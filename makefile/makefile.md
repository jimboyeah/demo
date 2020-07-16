#Make自动化编译工具-编译静态库与动态库

- MD Document:2/28/2016 2:23:09 AM by Jiimbowhy
- CSDN PuBLiSh:http://blog.csdn.net/winsenjiansbomber/article/details/50758180


在软件开发过程中，编译程序有时会成为一种额外繁重的工作，对于一些大项目工程而言更是如此。所以像Visual Studio等等IDE都是集成了自动化编译工具的，NMAKE 命令就是MS平台下的自动化编译工具。还有其它平台使用如 Ant、Automake、CMake等等，而GNU社区也有自己的自动化编译工具，它就是 GNU make。很早之前深谙自动化编译的重要，只是一直没有机会写一篇相关的文章，这次真的是巧遇了，@亦楠 同学在《headfirst》实验中遇到自动化编译问题，正好可以切题。

自动化编译工具的基本思想就是通过设置一系列依赖关系或规则，通过依赖关系的最低层目标来执行编译链接命令，或其它任意的命令都可以。一个大工程中，可以定义各个分立的项目，需要时可能通过 make 来执行独立分部的编译，而不需要将整个工程重新编译。个别文件被更新时，make 也可以检测到有哪些相应的依赖目标需要重新编译或链接。


##一些常识

执行 make 命令时，它会自动读取 makefile 文件的内容，如果想用其它规则定义文件，可以通过 -f、--file、--makefile 等选项来指定。如果没有指定规则文件，则它会按依次尝试读取这几个规则文件 GNUmakefile, makefile, Makefile，所以只要目录下只要有其中任意一个就可以。

执行 make 命令时，很经常的情况是指定目标的，目标 Goals 就是指当次执行命令想要达到的什么样的期待，或者说期望命令做到什么工作，编译发行程序或者编译调试版程序，这些都是目标。默认情况下，make 的目标 Goals 是第一条规则定义的目标 target。注意 goals 和 target 的在用法的区别，它们没有本质区别，仅仅是在用法上不同。如果在运行命令时指定了目标，如 make release，那么 release 就会保存在 MAKECMDGOALS 变量，当然规则文件要先有这个定义才会成功执行。

在编写规则文件的时候，也许会想调试看看，对于不同的目标 make 会产生什么样动作或命令，那么就可以在执行 make 命令时指定选项 --just-print，它用来打印 make 读取规则文件后产生的动作命令，而不是执行它们。


##目标与规则定义


规则就是 make 在执行时具体实施命令的约束条件，如果规则定义有问题，就很可能触发错误 No rule to make target `xxx'，定义一条规则的语法结构如下：

	target … : prerequisites …
	        recipe
	        …

target 指一个目标，可以是抽象的目标 Phony Targets 如执行清理的目标 clean，也可以是具体目标如一个可执行程序 abc.exe，就是一个目标名称，在整个依赖关系中充当关系节点，具有承上启下的作用。冒号:右边是依赖条件 prerequisites，也就是说要实现 target 目标，首先需要有 prerequisites 指定的一系列条件，这些条件可以是一些文件，或都是其它目标。然后跟着的 recipe 就是实现这个目标要做工作，可以在里编写调用编译链接程序的语句，从而实现目标的编译。注意 recipe 前面的TAB缩进，如果不想使用TAB缩进，可以修改 .RECIPEPREFIX 变量，否则会收到 missing separator/ multiple target patterns. 之类的报告。

make 执行时需要一个 makefile 文件来定义目标的依赖关系，make 会分析其关系结构，通常第条规则就是作为。先来看一个简单的 makefile 文件内容结构：

	objects = main.o display.o \
	          insert.o
	
	edit : $(objects)
	        cc -o edit $(objects)
	main.o : main.c defs.h
	        cc -c main.c
	command.o : command.c defs.h command.h
	        cc -c command.c
	display.o : display.c defs.h buffer.h
	        cc -c display.c
	insert.o : insert.c defs.h buffer.h
	        cc -c insert.c
	clean :
	        rm edit $(objects)

开头一行的反斜杠是用来换行的，如果一行写的内容太长就可以用它来截断。文件开关定义了目标 objects，它含有一系列的目标文件，这些目标文件又是其它几个目标的依赖文件。可以看到 edit 是一个最终可执行目标程序，它依赖所有目标文件，它需要执行的编译命令就是 cc，还有指定的参数。其它几个目标，注意是指冒号左边的 target 目标，都依赖了不同的文件，它们执行时就会生成 edit 目标依赖的文件即扩展名为 .o 的目标文件。除 clean 这个目标是用于清理临时文件的，所以没有依赖。

make 定义了几个默认的目标，有前面提到的 clean，还有 all，表示需要编译整个工程；有 install，只执行库文件、可执行文件等的拷贝动作；还有 unstall，执行反安装的动作，check 执行检查等等，有这些定义，就可以执行 make install 来安装程序了。


##编译链接常识

GNU make有不同的移植版本，当前我在用的就是 MinGW 移植版本，它的命令文件是 mingw32-make。在执行它时，它会按规则定义去调用相关的命令，如编译程序，链接程序。在此之前有必要了解一下编译链接命令的基本用法，编译链接命令不一定是分离的两个程序，它们可以是同一样命令。以GCC编译器为例，它有几个和编译链接相关的命令，ld是链接程序，ar 是库管理程序，用来生成库文；gcc 这个编译命令默认编译C语言代码，需要编译C++时，需要通过 -l 来引用C++标准库等等，如 -lstdc++，而g++编译命令则默认编译C++。在编译阶段则通过 -I 参数来引用头文件目录。下面的一组命令中有用来编译链接示例程序，其中　-ｃ　选项表示只编译不链接，输出文件名使用默认值，即和输入文件同名。GCC编译的文件一般都会比VC编译器的大，但是通过加入 -s 去符号优化，通过 strip 工具执行符号清理还是可以为输出文件减肥的，即相当于编译 release 版，不带 -s 相当于编译 debug 版本：

	g++ print.c -c
	g++ lib.c -c
	g++ print.o lib.o main.c

和输出文件大小优化相关的链接选项、还有动态静态链接的选项有如下这些，可以参考 [GCC Command Options][4]。也可以使用 -S 链接选项来清除调试部分的符号，注意，因为 g++ 使用 -S 来生成汇编代码。因此需要通过这种方式 -Wl,-S 来传递给链接程序：

	-s, --strip-all        Remove all symbol table and relocation information from the executable. 
	-S, --strip-debug      Strip debugging symbols
	--strip-discarded      Strip symbols in discarded sections
	--no-strip-discarded   Do not strip symbols in discarded sections

	-Bdynamic, -dy, -call_shared		Link against shared libraries
	-Bstatic, -dn, -non_shared, -static	Do not link against shared libraries


GNU工具中还有一个　ar　命令即归档命令 archive，用它来制作库文件.a。早期在Linux系统上ar程序单纯用来打包多个目标文件 .o 到 .a，类似做tar做的事情，并不处理目标文件里的符号表。而在链接时，Linker程序则需要 .a 文件提供一个完整的符号引用表，否则就会出现符号引用未定义等错误。当时就写了单独提供 ranlib 命令来生成符号链接。新版 ar 命令已经将 ranlib 的功能集成，通过 s 选项就可以生成符号索引。所以如果需要编译链接库，则可以执行以下编译链接命令，需要动态库时，可以给g++设置 -shared 选项，-Wl选项也可以用来给链接程序传递参数。例如，下面两组命令就是使用静态链接 libsp.a 和动态链接 libsp.so 的两种编译方式示范：

	g++ -shared -o libsp.so print.o lib.o
	g++ -o d.exe main.c libsp.so

	ar -crs libsp.a print.o lib.o
	g++ -o s.exe main.c libsp.a


##一个实用的例子

现在来做一个模拟真实情况的编译任务，工程含有 5 个文件，用途如下：

	main.c	主程序入口
	lib.h	库文件头
	lib.c	库文件，含 sum 函数
	print.h	
	print.c	库文件，含 print 函数，和 lib.c 一起打包为库文件 libsp.a

代码如下：

	// main.c                      +----------+    +------------+    +----------+
	#include <iostream>            |   lib.h  |--->|   main.c   |<---|  print.h |
	                               +----+-----+    +-----+------+    +----+-----+
	#include "lib.h"                    V                A                V
	#include "print.h"             +----+-----+          |           +----+-----+
	                               |   lib.c  |          |           |  print.c |
	using namespace std;           +----+-----+          |           +----+-----+
	                                    |          +-----+------+         |
	int main(void)                      +--------->+ libsp.a/so +<--------+
	{                                              +------------+
		print("1+2+3=");
		cout << sum(1,2,3) << endl;
	}                                              // lib.c
                                                   #include "lib.h"

	// lib.h                                       int sum(int a, int b, int c)
	#ifndef lib_header                             {
	#define lib_header                             	return a+b+c;
									                }
	int sum(int a, int b, int c);

	#endif //lib_header                            // print.c
                                                   #include <iostream>
                                                   #include "print.h"
	// print.h
	#ifndef print_header                           using namespace std;
	#define print_header
	                                               void print(char *msg)
	void print(char *);                            {
	                                               	cout << msg;
	#endif //print_header                          }


makefile 内容如下，注意变量CC，make有时会通过CC变量来执行编译器，定义这个变量防止出现 CreateProcess(NULL) 错误：

	#
	#  GNU makefile demo by Jimbowhy @ 2016/2/28 1:57:22
	#

	CC=g++
	var := $(MAKE) command executed
	
	all : main libsp.a libsp.so print.o lib.o main.o
		@echo off
	
	main : main.c lib.o print.o
		g++ -o main.exe print.o lib.o main.c
		@echo 4 $?
	
	libsp.a: print.o lib.o
		ar -crs libsp.a print.o lib.o
	
	libsp.so: print.o lib.o
		g++ -shared -o libsp.so print.o lib.o
	
	static: libsp.a main.c
		g++ -o static.exe main.c libsp.a
	
	dynamic: libsp.so main.c
		g++ -o dynamic.exe main.c libsp.so
	
	lib  : lib.c lib.h
		g++ lib.c -c
	
	print: print.c print.h 
		g++ print.c -c
	
	check: anythine.c any.d
		@echo 1 $@
		@echo 2 $%
		@echo 3 $<
		@echo 4 $?
		@echo 5 $^
		@echo 6 $+
		@echo 7 $|
		@echo 8 $*
		@echo $(var)
	
	anythine.c any.d:
		
	clean:
		del *.o
		del *.a
		del *.so


执行编译工作时只需要两条命令就可以编译静态链接和动态链接两个版本，警告信息直接无视，代码中使用的是C-Style的字符串：

	C:\c\src\makefile>mingw32-make dynamic
	g++ -shared -o libsp.so print.o lib.o
	g++ -o dynamic.exe main.c libsp.so
	main.c: In function 'int main()':
	main.c:11:16: warning: deprecated conversion from string constant to 'char*' [-W
	write-strings]
	
	C:\c\src\makefile>mingw32-make static
	ar -crs libsp.a print.o lib.o
	g++ -o static.exe main.c libsp.a
	main.c: In function 'int main()':
	main.c:11:16: warning: deprecated conversion from string constant to 'char*' [-W
	write-strings]


##库文件的引用问题

使用库文件进行编译，是一个可以节省编译工作的方法，无论是 Win32 平台还是 Linux 平台，都支持库链接技术，只是实现的方法上有差异。在 Win32 平台上编译生成的文件格式为 PE(Portable Executable) 或者 COFF(Common Object File Format)，而Linux平台下编译得到的文件是ELF(Executable & Linking Format)。GNU 有一个 dlltool 工具用来转换 Win32 平台的 DLL 动态库。程序可以将一些不需要变动的代码编译为库，动态库或静态库，如C语言的标准库等等。由于库文件的存在，就需要一种定位目标代码的技术。如例子中的库函数 sum，在编译到库文件后，libsp.a 或 libsp.so，它是以二进制代码的形式存储的，通过符号表来保存函数名与对应地址的关系。开发程序时需要调用这个函数，其实就是引用这个函数的内存地址，链接程序会在链接时重定位它以使程序执行正确。

只有正确的引用地址，链接程序才能将指定的二进制代码数据和程序进行链接，这个过程也就是链接程序的存在意义。ld 链接程序通过 -l 来引用库文件，通过 -L 来引用库文件目录。当引用不正确时，通常就会出现 undefined reference to *** 错误了。怎样保证引用的正确性呢？首先，确定库路径正确，保证链接程序可以找到库文件；其次，确保没有同名的库文件，在混乱的引用中这可能会引起莫名的问题，存在同名引用时，可以调整引用库的的顺序解决；在正确的库文件上还找不到符号定义时，那么就是库文件的部件了，可能是版本不对，也可能是编译系统使用了缓存。

链接程序在查找库文件时，首先从命令行上加载指定的位置查找，然后查找标准库目录。再从库文件查找符号引用信息，及符号定义。使用 -l 引用库文件与直接使用库文件名来引用的差别就，使用 -l 选项时，链接链接程序会自动添加库引用的全名 lib*.a ，引用库时，只需要填写*部分。

关于使用库文件的编译方式，使用以下两条命令测试，第三条是作为对比的正常编译链接命令：

	g++ -Os -s -o static.exe -L. -llibsp.a main.c 
	g++ -Os -s -o static.exe -L. -lsp main.c 
	g++ -Os -s -o static.exe main.c libsp.a

第一条命令输出内容：

	g++ -Os -s -o static.exe -L . -llibsp.a main.c
	c:/mingw471/mingw32/bin/ld.exe: cannot find -llibsp.a

第二条命令输出内容：

	g++ -Os -s -o static.exe -L . -lsp main.c
	C:\Users\ADMINI~1\AppData\Local\Temp\cc7JfvNP.o:main.c:(.text.startup+0x1e): und
	efined reference to `print(char*)'
	C:\Users\ADMINI~1\AppData\Local\Temp\cc7JfvNP.o:main.c:(.text.startup+0x3a): und
	efined reference to `sum(int, int, int)'

比较两条输出，第一条是因为库文件引用参数设置错误导致链接程序无法定位库文件，而第二条则已经可以读取库文件了，但是却无法找到符号定义，所以问题的根本就符号定位。为了说明指令中引用库的优先顺序，下面有一条命令与前面的正常编译链接命令相似的形式。它的差别只是在一点，即库文件的位置提前到了代码文件的前面，而给出的错误信息是和上面第二条命令输出内容完全一致的，即库文件是找到了，就是找不到符号定义。

	g++ -Os -s -o static.exe libsp.a main.c 

综合起来，就可以得到正确的命令执行方式，使用库编译时，正确的命令形式应该是这样的：

	g++ -Os -s -o static.exe -L. main.c -lsp

GNU 提供了一组工具来查询elf，有 nm/ar/readelf 等等。而 objdump 则是功能较齐全的一个，它就可以用来查看目标文件的各种信息，如 -a 选项用来查看库文件包含的目标文件，-r 选项查询重定位符号信息，-d 选项用来反汇编各符号的代码，-t 选项用来查询符号定义表，-h 选项来查看目标文件各个分区信息。如下面输出了库文件的重定位与符号表内容，注意原代码的函数名已经被改动了，可以称作函数签名，C++实现函数重载功能就是通过这样的签名实现的。这种函数名改动是按一定的规则进行的，不影响链接程序将其对应上原代码的符号：

	>objdump -rtj .text libsp.a
	In archive libsp.a:
	
	print.o:     file format pe-i386
	
	SYMBOL TABLE:
	[  3](sec  1)(fl 0x00)(ty  20)(scl   2) (nx 1) 0x00000000 __Z5printPc
	AUX tagndx 0 ttlsiz 0x0 lnnos 0 next 0
	...
	AUX scnlen 0x76 nreloc 8 nlnno 0
	
	RELOCATION RECORDS FOR [.text]:
	OFFSET   TYPE              VALUE
	00000010 dir32             __ZSt4cout
	...
	00000054 DISP32            _atexit
	
	lib.o:     file format pe-i386
	
	SYMBOL TABLE:
	[  2](sec  1)(fl 0x00)(ty  20)(scl   2) (nx 1) 0x00000000 __Z3sumiii
	AUX tagndx 0 ttlsiz 0x0 lnnos 0 next 0
	[  4](sec  1)(fl 0x00)(ty   0)(scl   3) (nx 1) 0x00000000 .text
	AUX scnlen 0x12 nreloc 0 nlnno 0

因为各平台的共享库实现方式不同，在开发无平台依赖的库时就会变得很难搞。而GNU提供了 libtool 这个工具就是为了解决这个问题开发的，可以用它来实现可移植的共享库编译。它的全名就是 The GNU Portable Library Tool。其中还含有一个工具 libltdl API，它隐藏了各平台的实现细节，打包后提供一组通用API，用来在程序中动态加载库文件并执行库函数。目前的版本为 2.4，支持以下这些系统的动态链接库技术：

	dlopen (POSIX compliant systems, GNU/Linux, etc.)
	shl_load (HP-UX)
	LoadLibrary (Win16 and Win32)
	load_add_on (BeOS)
	NSAddImage or NSLinkModule (Darwin and Mac OS X)
	GNU DLD (emulates dynamic linking for static libraries)
	libtool’s dlpreopen (see Dlpreopening)

为了使用这个工具，需要下载 [GNU Libtool/libltdl][6] 包。我用的是 TDM-GCC 平台，因此需要 MinGW 的移植版本。下载好开发包后，直接放到 GCC 的目录就可以用了。

对于Linux系统的 DLFCN API，MinGW 却没有提供实现，即使有一个 dlfcn-win32，作者 Ramiro Polla 也是通过包装 LoadLibrary(), GetProcAddress()等函数实现的。有了这些动态加载共享库的工具后，就可以通过代码来加载来定位库函数，而不必通过链接程序的处理了。

如前面提到，函数编译后名字改变了，在C语言中，函数签名的方式还比较简单，有规律可言。因此，DLFCN API 提供的几个方法 dlopen, dlsym 和 dlclose 就可以实现共享库的动态加载。

写到这里，咬了口苹果，心里突然好担心咬的是毒苹果。因为的给小贵宾吃了几块苹果，它今天就一直胃，还吐了好多像苹果汁一样的粘液，味道还好重！

但在C++中，情况却不同了，因为引入了函数重载，所以函数的签名方法真是各家修各家路，花样百出，函数经编译后基本上它妈都不认得了，这种情况就是 Name Mangling。所以，在C++环境上，DLFCN 难再动态加载共享库了，当然有个解决办法就 extern "C"。


##编译Win32平台DLL

为了编译DLL，需要按Win32平台的要求为共享库设置导入表，还发将函数定义为导出函数，这样程序加载DLL后才可以调用到导出的方法。在前面的例子的基础上，修改 lib.h 和 lib.c，分别添加上以正内容：

	//lib.h
	#ifdef BUILD_DLL  
	#define EXPORT __declspec(dllexport) 
	#else  
	#define EXPORT __declspec(dllimport) 
	#endif
	
	EXTERN "C" EXPORT bool CheckForMDAC(int a,int b );

	//lib.c
	EXPORT int add(int a,int b )
	{
		return a+b;
	}

Win32平台的 DLL 和 so 共享库一样，都是动态链接库，所以编译时也要使用 -shared 选项，不同的是 DLL 需要一个命名导入库，也就是链接符号和对应地址构成符号表文件，和静态库一样以 .lib 为扩展名。但是它们是两种完全不同的文件，导入库只包含符号对应地址的数据表，而静态库是包含编译后的二进制代码的。在编译程序时，就需要引用库文件，导入库或静态库，使用静态库时，链接后得到的程序就可以脱离DLL独立运行。而使用导入库链接时只在程序中包含装入动态库 DLL 时所需的信息，所以程序运行时需要查找并装入对应的DLL文件。对VC编译工具而言，如果指定了下面任意一项，则 LINK 链接程序就会在指定 /IMPLIB 选项的条件下生成命名导入库：

- 源代码中的 __declspec(dllexport) 关键字
- .def 文件中的 EXPORTS 语句
- LINK 命令中的 /EXPORT:entryname[,@ordinal[,NONAME]][,DATA]
- \#pragma comment(linker,"/EXPORT:function=_function@2")

为编译上面的修改后的代码，需要使用编译器的符号定义选项 -D 来定义 BUILD_DLL 这个符号，还需要根据不的库文件类设置输出文件的扩展名。修改 makefile 文件，在开头添加选项定义：

	OLIB=-o libsp.so
	ifeq "$(MAKECMDGOALS)" "libsp.dll"
	CFLAGS=-DBUILD_DLL
	OLIB:=-o libsp.lib
	endif

然后，以 libsp.dll 为目标，编译规则，包括现有规则的修改：

	libsp.dll: libsp.so
		g++ -Os -s -shared -Wl,--out-implib,libsp.lib -o libsp.dll print.o lib.o
	
	libsp.so: print.o lib.o
		g++ -Os -s -shared $(OLIB) print.o lib.o
	
	lib  : lib.c lib.h
		g++ -c $(CFLAGS) lib.c


这样修改后，通过命令 make libsp.dll 就可以编译链接 DLL 库文件了。使用VC编译工具引用库文件时，可以通过命令行引用，但是对于VC编译工具通常做法是通过代码中添加伪指令来实现：

	#pragma comment(lib, "libsp.lib")
	#pragma comment(linker, "<linker options>")
	#pragma comment(linker,"/NODEFAULTLIB:libc.lib")


##其它功能

执行命令行求值 --eval，可能通过它来定义变量，可以多次使用，命令行可以直接使用变量的定义：

	make --eval=var=$(var)
	make var=YES 

make 支持变量的定义和使用，语法格式如下：

	name1 := $(lastword $(MAKEFILE_LIST))
	
变量 name1 通过赋值运算符 := 得到其它任意内容，这里是将其它变量的值传给 name1。MAKEFILE_LIST是make内部定义的变量，指当前 make 解析过的 makefile 列表，所以 make 是支持嵌套调用的，命令如下：

	@$(MAKE) -f Makefile $@

make 也支持引用其它文件：

	include foo *.mk $(bar)
	include filenames…

字符串处理指令：

	$(subst from,to,text)
	$(strip string)
	$(findstring find,text)

目录与文件处理：

	$(dir names…)
	$(notdir names…)
	$(suffix names…)
	$(basename names…)
	$(addsuffix suffix,names…)
	$(addprefix prefix,names…)
	$(realpath names…)
	$(abspath names…)
	$(file op filename,text)

输出错误、警告、提示信息：

	$(error text…)
	ifdef ERROR1
	$(error error is $(ERROR1))
	endif

	$(warning text…)
	$(info text…)

执行shell命令，通过shell命令可以与操作系统交互：

	$(shell echo *.c)

通过检测 .FEATURES 变量，可以确定 make 是否集成 GUN Guile 脚本语言。

如果系统支持回去动态目标文件，则可以通过 load 指令来加载，加载时 make 通常会执行 mk_funcs_gmk_setup，或指定的初始化函数 init_mk_func。加载成功后，文件就会添加到变量 .LOADED：

	load ../mk_funcs.so
	load ../mk_funcs.so(init_mk_func)

条件判断指令：

	$(if condition,then-part[,else-part])
	ifdef variable
	ifndef variable
	ifeq (a,b)
	ifeq "a" "b"
	ifeq 'a' 'b'
	ifneq (a,b)
	ifneq "a" "b"
	ifneq 'a' 'b'
	else
	endif

定义变量时可以用 =、:=、::= 来赋值，优先等级一个比一个高，而使用 override 是优先级最高的。如果变量还没有赋值的情况下，?= 可以用来为变量执行一次赋值，+= 则可以用来连接变量中的字符串，还可以用 define/endef/undefine 来定义变量。以下两组变量语句具有相同功能：
	
	variable := value
	variable += more
	
	variable := value
	variable := $(variable) more

	override variable = value

以下是一些常用的内置变量，如果要使用$符号为字符串就要使用转义形式，即$$表示这是一个字符串而不变量引用：

	AR	Archive-maintaining program; default ‘ar’.
	AS	Program for compiling assembly files; default ‘as’.
	CC	Program for compiling C programs; default ‘cc’.
	CXX	Program for compiling C++ programs; default ‘g++’.
	CPP	Program for running the C preprocessor, default ‘$(CC) -E’.

	$@	The file name of the target.
	$%	The target member name, when the target is an archive member.
	$<	The name of the first prerequisite.
	$?	The names of all the prerequisites that are newer than the target.
	$^	The names of all the prerequisites, with spaces between them.
	$+	This is like ‘$^’, but prerequisites listed more than once are duplicated in the order they were listed in the makefile.
	$*	The stem with which an implicit rule matches.

	$(@D)
	$(@F)	The directory part and the file-within-directory part of $@.
	
	$(*D)
	$(*F)	The directory part and the file-within-directory part of $*.
	
	$(%D)
	$(%F)	The directory part and the file-within-directory part of $%.
	
	$(<D)
	$(<F)	The directory part and the file-within-directory part of $<.
	
	$(^D)
	$(^F)	The directory part and the file-within-directory part of $^.
	
	$(+D)
	$(+F)	The directory part and the file-within-directory part of $+.
	
	$(?D)
	$(?F)	The directory part and the file-within-directory part of $?.

	MAKE_VERSION	The version number of the GNU make program.
	MAKE_HOST		A string representing the host.	
	MAKELEVEL	The number of levels of recursion (sub-makes).	
	MAKEFLAGS	The flags given to make.
	CURDIR		Set to the pathname of the current working directory 

库文件打包，make 的库文件的规则可以按以下格式定义，ranlib为符号链接更新命令：

	libfoo.a: foolib(hack.o kludge.o …) …
		ranlib libfoo.a

	foolib(x.o) : x.o
	        ar cr foolib x.o

	foolib(y.o) : y.o
	        ar cr foolib y.o

需要注意的是 make 可以通过 -j 参数来执行多编程编译，这种情况下出现多个线程同时读写，库文件可能会有多线程问题。

详细内容请参考官方文档。

最后，点评一下@亦楠 同学的实验代码，代码真没怎么看，因为注解写真是太凌乱了，鸟巢一样，代码都在其中淹没。建议，如果真需要写这么多注解，那有一个好办法，就是将注解集中到一块，对代码进行分析或点评。因为有行号嘛，不怕找不到点评对应那句代码。那有第一个办法就有第二个，第二个办法就是写总结，当文章写，一来可以锻炼写作技术，培养解决问题的思路，三来可以加强记忆，可谓以一举多得。


##参考资源
- [Make Wiki][1]
- [GCC Command Options][4]
- [make: *** No rule to make target `main.c', needed by `main'.  Stop.][2]
- [示例代码及脚本下载][3]
- [GNU Libtool][6]
- [GNU libtool for MinGW][8]
- Linkers & Loaders by John R.Levine
- [How To Write Shared Libraries by Ulrich Drepper][7]
- [Program library HOWTO - David A. Wheeler][5]
- [C++ dlopen mini HOWTO][9]

[1]: http://directory.fsf.org/wiki/Make "Make Wiki"
[2]: http://ask.csdn.net/questions/239273
[3]: http://download.csdn.net/detail/winsenjiansbomber/9446391 "Download makefile.zip"
[4]: https://gcc.gnu.org/onlinedocs/gcc-4.7.1/gcc/Invoking-GCC.html "GCC Command Options"
[5]: http://tldp.org/HOWTO/Program-Library-HOWTO/index.html "Program library HOWTO - David A. Wheeler"
[6]: http://www.gnu.org/software/libtool/libtool.html "GNU Libtool"
[7]: https://www.akkadia.org/drepper/dsohowto.pdf "How To Write Shared Libraries by Ulrich Drepper"
[8]: https://sourceforge.net/projects/mingw/files/MinGW/Extension/libtool/ "GNU libtool for MinGW"
[9]: http://www.faqs.org/docs/Linux-mini/C++-dlopen.html "C++ dlopen mini HOWTO"