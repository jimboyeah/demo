/*
 * QUESTION:
    We know the prototype of strcpy following:
        char * strcpy(char * strDest,const char * strSrc);
    Now, please youself definition of strcpy without library function and tell the details of return type char *.
 */

#include <iostream>
#include <cstring>
#include <stddef.h> //C99，Annex B16 for NULL, ISO C Standard:  7.17  Common definitions

using namespace std;

char * strcpy(char *dest, const char *src);

int main()
{
    const char * greeting = "Hello world!";
    int len = strlen(greeting);

    char *ref1 = new char[len+1]();
    cout << "len is " << len << endl;
    cout << "ref1 is " << ref1 << endl;
    cout << "ref1 at " << &ref1 << endl;

    char *ref2 = strcpy(ref1, greeting);

    cout << "ref1 is " << ref1 << endl;
    cout << "ref1 at " << &ref1 << endl;
    cout << "ref2 is " << ref2 << endl;
    cout << "ref2 at " << &ref2 << endl;

    delete ref1;
    return 0;
}

// C-style function implementation - NULL is not C's keyword
char * strcpy(char *dest, const char *src)
{
    //cout << "do nothing" << endl; //WHY NO OUTPUT?
    if(dest==NULL || src==NULL){
        return dest; //do nothing, just return as-is
    }
    char * bak = dest;
    while( (*dest++ = *src++) != '\0');
    //while( *dest++ = *src++ != '\0'); //error evaluate
    return bak;
}

/*
    解说strcpy的实现代码：

    1.   char * strcpy(char * strDest,const char * strSrc)
    2.   {
    3.       if ((strDest==NULL)||(strSrc==NULL))    //[1]
    4.           throw "Invalid argument(s)";        //[2]
    5.       char * strDestCopy=strDest;             //[3]
    6.       while ((*strDest++=*strSrc++)!='\0');   //[4]
    7.       return strDestCopy;
    8.   }

    错误的做法：
    [1]
    (A)不检查指针的有效性，说明答题者不注重代码的健壮性。
    (B)检查指针的有效性时使用((!strDest)||(!strSrc))或(!(strDest&&strSrc))，
       说明答题者对C语言中类型的隐式转换没有深刻认识。在本例中char *转换为bool即是类型隐式转换，
       这种功能虽然灵活，但更多的是导致出错概率增大和维护成本升高。所以C++专门增加了bool、true、false
       三个关键字以提供更安全的条件表达式。
    (C)检查指针的有效性时使用((strDest==0)||(strSrc==0))，说明答题者不知道使用常量的好处。
       直接使用字面常量（如本例中的 0）会减少程序的可维护性。0虽然简单，但程序中可能出现很多处对指针的检查，
       万一出现笔误，编译器不能发现，生成的程序内含逻辑错误，很难排除。
       而使用 NULL代替0，如果出现拼写错误，编译器就会检查出来。

    [2]
    (A)return new string("Invalid argument(s)";，说明答题者根本不知道返回值的用途，
       并且他对内存泄漏也没有警惕心。从函数中返回函数体内分配的内存是十分危险的做法，
       他把释放内存的义务抛给不知情的调用者，绝大多数情况下，调用者不会释放内存，这导致内存泄漏。
    (B)return 0;，说明答题者没有掌握异常机制。调用者有可能忘记检查返回值，调用者还可能无法检查返回值（见后面的链式表达式）。
       妄想让返回值肩负返回正确值和异常值的双重功能，其结果往往是两种功能都失效。应该以抛出异常来代替返回值，
       这样可以减轻调用者的负担、使错误不会被忽略、增强程序的可维护性。

    [3]
    (A)忘记保存原始的strDest值，说明答题者逻辑思维不严密。

    [4]
    (A)循环写成while (*strDest++=*strSrc++);，同[1](B)。
    (B)循环写成while (*strSrc!='\0') *strDest++=*strSrc++;，说明答题者对边界条件的检查不力。
       循环体结束后，strDest字符串的末尾没有正确地加上'\0'。

    2.返回strDest的原始值使函数能够支持链式表达式，增加了函数的“附加值”。
    同样功能的函数，如果能合理地提高的可用性，自然就更加理想。
    链式表达式的形式如：
        int iLength=strlen(strcpy(strA,strB));
    又如：
        char * strA=strcpy(new char[10],strB);
    返回strSrc的原始值是错误的。
    其一，源字符串肯定是已知的，返回它没有意义。
    其二，不能支持形如第二例的表达式。
    其三，为了保护源字符串，形参用 const限定strSrc所指的内容，把const char *作为char *返回，类型不符，编译报错。

    上面内容是转自：http://bbs.chinaunix.net/viewthread.php?tid=25356


    争论http://www.cppblog.com/SINE/archive/2011/04/28/145180.html：
    # re: 【C/C++ string】之strcpy函数 2011-04-28 10:09 oo
    1 在这样的函数中，检查传入参数是否为NULL是没有意义的，除了NULL，其他的非法值的情况远比比NULL的情况更多。
    2 这里抛出一个异常是一个很怪的想法。
    4[A] see http://www.google.com/codesearch/p?hl=zh-CN#lIRf952n7hs/libc/strcpy.c&q=strcpy&sa=N&cd=1&ct=rc

    # re: 【C/C++ string】之strcpy函数 2011-04-28 10:19 溪流
    @oo
    NULL 检查还是有点意义的吧，这是唯一能检查的值，其他情况就让用户自生自灭吧，检查了 NULL 就表示告诉用户我尽力了。。。
    抛异常我也觉得不妥，这里没必要引入异常体系。

    # re: 【C/C++ string】之strcpy函数 2011-04-28 10:27 COS
    其实这里检查NULL就是为了说明编程者的思维是否严谨，如果是在实际应用的时候，
    我们大可避免NULL的出现，在调试程序的时候就可以解决它。
    至于异常抛出，那也是为了考察作者是否了解异常的使用，真正做的时候，也是不需要的。
    在<string.h>中定义的strcpy(...)这些都是没有的，因为程序本身就很小，
    如果我们还在那里把异常处理加进去的话，函数本身就不够精简。
    所以，设计者把这些异常处理留给我们使用库文件的人自己处理了。

    # re: 曾经出现频率最高的笔试题【C/C++ string】之strcpy函数 2011-04-28 11:22 陈昱(CY)
    先找到末尾，然后用memcpy，提高效率

    # re: 曾经出现频率最高的笔试题【C/C++ string】之strcpy函数 2011-04-28 12:10 陈昱(CY)
    .....不对，不用库函数，那要提高效率比较麻烦了，要自己实现memcpy......

    # re: 曾经出现频率最高的笔试题【C/C++ string】之strcpy函数 2011-04-28 18:27 Lo
    这里抛出异常是无厘头行为。又不是java 改成assert还说得过去。

    # re: 曾经出现频率最高的笔试题【C/C++ string】之strcpy函数 2011-04-28 21:28 COS
    @Lo这个是我转的别人的贴，其实我本人也认为没有必要抛出异常的。本身代码就短，还抛出异常，就显得累赘了。

    # re: 曾经出现频率最高的笔试题【C/C++ string】之strcpy函数 2011-04-29 14:56 pangzi
    如果两个指针的内存区域有重叠，直接飞掉。

    # re: 曾经出现频率最高的笔试题【C/C++ string】之strcpy函数 2011-04-30 22:35 天堂的隔壁
    git://android.git.kernel.org/platform/bionic.git›libc›string›strcpy.c

    char * strcpy(char *to, const char *from)
    {
        char *save = to;

        for (; (*to = *from) != '\0'; ++from, ++to);
        return(save);
    }

    看来Google的工程师是得不了多少分的了。
    1[A]这个不说了，本来就是有争议的，看各公司的习惯。
    1[B]strcpy本来是C标准库的一部分，扯到C++显然蛋了。
    1[C]提个问题，谁知道NULL在那里定义的？这里反而写0个人感觉是思维严密的表现，他会担心，这里的NULL的定义问题。
        当然了，如果能#include <stddef.h>就完美了。（C99，Annex B16）但起码比完全不思考的好。
        直接写NULL也是可以接受的，非上机笔试，潜规则是允许半伪代码。
    2[A]这个答案太有想象力了。
    2[B]这个颠覆语言了，更扯蛋了。
    3[A]难以想象一个正常的人，在return的时候找不到值了，会想不起来…
        (你可能出门的时候想不起带钥匙，却很难在开门的时候还想不起来。)
        不过既然是笔试，可能能从行距，有没有插入符号等看出来吧- -

 */

