/*
Varargs

Variable number of arguments 是 Java 5 带来的新功能，使用省略号代替多参数（参数类型... 参数名）

*/

import java.util.*;

public class VarArgs { 
    public static void main(String[] args) 
    { 
        print("Pi:%f E:%f/n", Math.PI, Math.E); 
    } 

    private static void print(String format,  Object... args) 
    {
        Arrays.asList(args).forEach(o -> System.out.println(o));
        //J2SE 1.5 新增的 printf(String format, Object... args)
        System.out.printf(format,  args); 
    } 
} 