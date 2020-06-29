
# Makefile 自动化编译
- http://www.ruanyifeng.com/blog/2015/02/make.html
- https://www.gnu.org/software/make/manual/make.html
- http://erlang.org/doc/man/make.html#emakefile
- Programming Erlang 2nd - 10.3 Automating Compilation with Makefiles


Make 是最常用的构建工具，诞生于 1977 年，主要用于 C 语言的项目。但是实际上 ，任何只要某个文件有变化，就要重新构建的项目，都可以用 Make 构建。

Erlang 命令本身也实现了 Emakefile 的功能，执行编译 `erl -make` 相当执行 `make:all()`，编译后的字节文件会保存到 `ebin` 目录，执行时使用 `erl -pa ebin` 就可以自动加载字节码。erl -make 也兼容 GNU make。

Emakefile 规则定义语法：

    Modules.
    {Modules,Options}.    

其中 Modules 是原子类型，可以是以下：

- 一个模块名，如 file1，又或者在其它目录中 `../foo/file1`
- 一组模块，通过熊通配符号指定，如 `'file*'`
- 全通配，当前目录下的所有模块 `'*'`
- 由以上项目任意组合的列表，比如 `['file*','../foo/file3','File4']`

选项 Options 指定了编译选项，Emakefile 文件是从上到下读取的，如果多条匹配设置出现，开头的一条生效。如下 `'file1'` 模块的编译选项是 `[debug_info,{i,"../foo"}]`，它指定了编译输出调试信息，如以下 Emakefile 文件：

    {'src/*', [debug_info,
               {i, "src"},
               {i, "include"},
               {outdir, "ebin"}]}.

    {'file1',[debug_info,{i,"../foo"}]}.
    {'*',[debug_info]}.    


GNU 的 Make 工具可以替代手工的编译工作，通过 Makefile 脚本实现工程级别的编译工作自动化。

列如，以下一个 Makefile：

    .SUFFIXES: .erl .beam
     
    .erl.beam:
        erlc -W $<
    ERL = erl -boot start_clean 
     
    MODS = hello shop
    
    all: compile 
     
    compile: ${MODS:%=%.beam}
        @echo "make clean - clean up"
     
    clean:  
        rm -rf *.beam erl_crash.dump 

保存到源代码 hello.erl、shop.erl 同一文件夹下，执行 `erl -make`，编译成功就会出现源代码对应的 .beam。

在 Windows 系统使用 Gnu make 命令，需要 ComSpec 这个环境变量指向 cmd.exe，或者设置 `SHELL=cmd.exe` 否则 shell 会执行失败：

    process_begin: CreateProcess(NULL,gcc -c test.c, ...)failed. 
    make(e=2): 系统找不到指定的文件 
    make:*** [test.o] 错误2 

列如，Erlang 源代码中提供了 wxErlang 模块的示例，其编译脚本 otp_src_23.0\lib\wx\examples\demo\Makefile 是为 Linux 系统准备的，在 Windows 系统上使用需要修改一下；

    SHELL=cmd.exe

    ERL_TOP = ..\..\..\..
    TOPDIR   = ..\..
    SRC = .
    BIN = .
    ERLINC = $(TOPDIR)/include
    ERLC = erlc
    TESTMODS = \
        demo \
        demo_html_tagger \
        ...
        ex_graphicsContext

    TESTTARGETS = $(TESTMODS:%=%.beam)
    TESTSRC = $(TESTMODS:%=%.erl)

    # Targets
    $(TESTTARGETS):$(TESTSRC)
    opt debug:  $(TESTTARGETS)
        ERLC -o $(TOPDIR)/ebin  $(TESTSRC)
    clean:
        del $(TOPDIR)\ebin\*.beam
        del "$(TOPDIR)\ebin\erl_crash.dump"
    #   del $(TESTTARGETS:%="$(TOPDIR)/ebin/%")
    #   rm -f $(TESTTARGETS)
    #   rm -f *~ core erl_crash.dump

    # docs:

    run: opt
        erl -smp -detached -pa $(TOPDIR)\ebin -s demo

然后执行编译，运行测试：

    $ make
    $ erl -noshell -s demo start -s init stop

make 命令只是一个根据指定的 Shell 命令进行构建的工具，它的规则很简单：

- Target 规定要构建哪个文件，用什么命令；
- Dependence 它依赖哪些源文件；
- Update 当那些文件有变动时，如何重新构建它。

构建规则都写在 Makefile 文件里面，这个文件由一系列规则 rules 构成：

    <target> : <prerequisites> 
    [tab]  <commands>

- 第一行冒号前面的部分，叫做`目标` Target，多目标用空格隔开，冒号后面的部分叫做`前置条件` prerequisites。
- 第二行必须由一个 tab 键起首，后面跟着`命令` commands。
- 目标是必需的，不可省略，前置条件和命令都是可选的，但是两者之中必须至少存在一个。
- 每条规则就明确两件事：构建目标的前置条件是什么，以及如何构建。

目标通常是文件名，指明 Make 命令所要构建的对象，除了文件名，目标还可以是某个操作的名字，这称为`伪目标` phony target。

在定义目标时，如果当前目录中，正好有一个文件同名，比如，目标叫做 `clean`，Make 执行时发现 clean 文件已经存在，而且是最新的状态，就认为没有必要重新构建了，就不会执行指定的命令。为了避免这种情况，可以明确声明 clean 是伪目标，写法如下：

    .PHONY: clean
    clean:
            rm *.o temp

声明 clean 是伪目标之后，make 就不会去检查是否存在一个叫做 clean 的文件，而是每次运行都执行对应的命令。像 `.PHONY` 这样的内置目标名还有不少，伪目标以句点开头跟大写字母，可以查看手册。

前置条件通常是一组文件名，之间用空格分隔。它指定了目标是否重新构建的判断标准： 只要有一个`前置文件`不存在，或者有过更新，前置文件的 last-modification 时间戳比`目标`的时间戳新，目标就需要重新构建。

命令 commands 表示如何更新目标文件，由一行或多行的 Shell 命令组成。它是构建目标的具体指令，它的运行结果通常就是生成目标文件。

Make 有`隐含规则` implict rule，比如：

    foo : foo.o bar.o
            cc -o foo foo.o bar.o $(CFLAGS) $(LDFLAGS)

上面的规则中，没有定义 foo.o 目标，make 会自动使用隐含规则，选检查 foo.o 文件是不存在，然后检查目录下对应的源代码，比如 foo.c 文件就会执行 C 编译器，如果是 foo.p 文件则执行 Pascal 编译器，如此。

隐含规则和隐含变量是配套的，C compiler，对应的隐含变量就是 cc 命令，可以直接调用，$(CC)、$(CFLAGS)、$(CPPFLAGS) 等。


Make 的一些编程能力：

- Make 支持命令换行，在换行符前加反斜杠 `\` 转义，$$ 表示转义 $ 符号。
- 井号 # 在 Makefile 中表示其后面的内容是注释。
- 支持 `*`、`?`、`[...]`  通配符用来指定一组符合条件的文件名。
- 支持匹配符，`%`，如 `%.o: %.c` 为当前目录下源码文件定义相应的目标。
- 支持变量，如 `v1 = Hi!` 定义了 v1 变量，`${v1}` 或 `$(v1)` 使用变量，例如 `@echo $(v1)`，或者 `v2 = $(v1)`。
- 支持 shell 命令，如 `contents := $(shell cat foo)`。
- 变量高级引用，`$(var:a=b)` 或者 `${var:a=b}`，例如以下 bar 变量最后的值是 `a.c b.c l.a c.c`：

        foo := a.o b.o l.a c.o
        bar := $(foo:.o=.c)

- 内置变量，如`$(CC)` 指向当前使用的编译器，`$(MAKE)` 指向当前使用的 Make 工具。
- 自动变量：

    - `$@` 指代当前 Make 命令当前构建的那个目标。
    - `$<` 指代第一个前置条件。
    - `$?` 指代比目标更新的所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，其中 p2 的时间戳比 t 新，$? 就指代 p2。
    - `$^` 指代所有前置条件，之间以空格分隔。
    - `$*` 指代匹配符 % 匹配的部分， 比如 % 匹配 f1.txt 中的 f1，$* 就表示 f1。
    - `$(@D)` 和 `$(@F)` 分别指向 $@ 自动变量的目录名和文件名部分。
    - `$(<D)` 和 `$(<F)` 分别指向 $< 自动变量的目录名和文件名部分。

- 支持 if-else 条件判断结构：

        ifeq ($(CC),gcc)
            libs=$(libs_for_gcc)
        else
            libs=$(normal_libs)
        endif

- 支持循环结构：

        LIST = one two three

        all:
            for i in $(LIST); do \
                echo $$i; \
            done

        # 等同于

        all:
            for i in one two three; do \
                echo $i; \
            done

- 支持使用函数：

        $(function arguments)
        # 或者
        ${function arguments}

Makefile 提供了许多内置函数，可供调用。下面是几个常用的内置函数。

Text Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(subst from,to,text) | $(subst ee,EE,feet on the street) |
| $(lastword names…)    | $(lastword foo bar) |
| $(patsubst pattern,replacement,text)  | $(patsubst %.c,%.o,x.c.c bar.c) |
| $(strip string)   | $(strip a b c ) |
| $(findstring find,in) | $(findstring a,a b c) |
| $(filter pattern…,text)   | $(filter %.c %.s,$(sources)) |
| $(sort list)  | $(sort foo bar lose) |
| $(word n,text)    | $(word 2, foo bar baz) |
| $(wordlist s,e,text)  | $(wordlist 2, 3, foo bar baz) |

File Name Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(dir names…) | $(dir src/foo.c hacks)    |
| $(notdir names…)  | $(notdir src/foo.c hacks) |
| $(suffix names…)  | $(suffix src/foo.c src-1.0/bar.c hacks)   |
| $(basename names…)    | $(basename src/foo.c src-1.0/bar hacks)   |
| $(addsuffix suffix,names…)    | $(addsuffix .c,foo bar)   |
| $(addprefix prefix,names…)    | $(addprefix src/,foo bar) |
| $(join list1,list2)   | $(join a b,.c .o) |
| $(wildcard pattern)   |   |
| $(realpath names…)    |   |
| $(abspath names…) |   |

Conditional Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(if condition,then-part[,else-part]) |   |
| $(or condition1[,condition2[,condition3…]])   |   |
| $(and condition1[,condition2[,condition3…]])  |   |
|   |   |
|   |   |

Make Control Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(error text…)    | $(error error is $(ERROR1))   |
| $(info text…) |   |
| $(warning text…)  |   |

其它函数 

| 函数        | 格式        | 作用    |
| :-------  | :-------  | :-------  |
| Foreach Function  | $(foreach var,list,text)  | Repeat some text with controlled variation. |
| File Function     | $(file op filename[,text])    | Write text to a file. |
| Call Function     | $(call variable,param,param,…)    | Expand a user-defined function. |
| Value Function    | $(value variable) | Return the un-expanded value of a variable. |
| Eval Function     | $(eval $(call PROGRAM_template,$(prog))   | Evaluate the arguments as makefile syntax. |
| Origin Function   | $(origin variable)    | Find where a variable got its value. |
| Flavor Function   | $(flavor variable)    | Find out the flavor of a variable. |
| Shell Function    | $(shell echo *.c) | Substitute the output of a shell command. |
| Guile Function    |   | Use GNU Guile embedded scripting language. |


脚本模板 Makefile.template：

    # leave these lines alone
    .SUFFIXES: .erl .beam .yrl

    .erl.beam:
        erlc -W $<

    .yrl.erl:
        erlc -W $<

    ERL = erl -boot start_clean

    # Here's a list of the erlang modules you want compiling
    # If the modules don't fit onto one line add a \ character
    # to the end of the line and continue on the next line
    # Edit the lines below
    
    MODS = module1 module2 \
        module3 ... special1 \
        ...
        moduleN
    
    # The first target in any makefile is the default target.
    # If you just type "make" then "make all" is assumed (because
    # "all" is the first target in this makefile)

    all: compile

    compile: ${MODS:%=%.beam} subdirs

    ## special compilation requirements are added here

    special1.beam: special1.erl
        ${ERL} -Dflag1 -W0 special1.erl

    ## run an application from the makefile

    application1: compile
        ${ERL} -pa Dir1 -s application1 start Arg1 Arg2

    # the subdirs target compiles any code in sub-directories

    subdirs:
        cd dir1; $(MAKE)
        cd dir2; $(MAKE)
        ...

    # remove all the code

    clean:
        rm -rf *.beam erl_crash.dump
        cd dir1; $(MAKE) clean
        cd dir2; $(MAKE) clean

最重要的是：

    MODS = module1 module2 module3 ... special1 ...

它定义了需要编译的目标模块，然后使用 `${MODS:%=%.beam}` 转换成 beam 扩展名，执行 make 可以指定编译的目标：

    make [Target]

就会将模块编译生成脚本定义目标文件。

