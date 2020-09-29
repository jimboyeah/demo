/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/lang/annotation/Annotation.html
Annotations Basics https://docs.oracle.com/javase/tutorial/java/annotations/basics.html
Java Annotation https://www.runoob.com/w3cnote/java-annotation.html

Java 注解 Annotation 也可称标注，是 JDK5.0 引入的一种注释机制，是元数据编程 meta programming。

Annotation 是一个辅助接口，它在 Junit、Struts、Spring 等工具框架中被广泛使用。

Java 语言中的类、方法、变量、参数和包等都可以被标注。和 Javadoc 不同，Java 标注可以通过反射获取标注内容。在编译器生成类文件时，标注可以被嵌入到字节码中。Java 虚拟机可以保留标注内容，在运行时可以获取到标注内容。

实现注解 Annotation 接口时与普通类的不同点：

- 不能通过 new 关键字创建注解实例。
- 只能声明基本数据类型属性，如 String 或者 Class<?> 类型及其数组。
- 不允许声明方法和构造器。
- 旧版本 Java 相同的注解不能重复使用，Java 8 通过提供可重复注解 @Repeatable 放松了这种限制。

Java 内置注解定义共有 7 个，3 个在 java.lang 中，4 个在 java.lang.annotation 中。

作用在代码的注解是

|     Annotation    |                              说明                              |
|-------------------|----------------------------------------------------------------|
| @Override         | 检查该方法是否是重写了其父类的方法，如果没有重写则报编译错误。 |
| @Deprecated       | 标记过时方法。如果使用该方法，会报编译警告。                   |
| @SuppressWarnings | 指示编译器去忽略注解中声明的警告。                             |

作用在其他注解的注解，或者说元注解:

|  Annotation |                                       说明                                      |
|-------------|---------------------------------------------------------------------------------|
| @Retention  | 标识这个注解怎么保存，在代码中，还是编入 class 文件中，或在运行时通过反射访问。 |
| @Documented | 标记这些注解是否包含在用户文档中，能使该 Annotation 标签出现在 javadoc 中。     |
| @Target     | 标记这个注解应该是哪种 Java 成员。                                              |
| @Inherited  | 标记这个注解是继承于哪个注解类(默认 注解并没有继承于任何子类)                   |

基类被标注为 @Inherited，那么继承的子类也会继承基类的注解，@Inherited 使用注解具有继承性。假设，我们定义了一个注解 MyAnnotation，并且被标注为 @Inherited。现在，某个基类 Base 使用了 MyAnnotation，则这个类具有了 MyAnnotation 注解，它是可继承的。所以，子类继承了 Base，那么子类也就具有了 MyAnnotation 注解。

从 Java 7 开始，额外添加了 3 个注解:

|      Annotation      |                                   说明                                  |
|----------------------|-------------------------------------------------------------------------|
| @SafeVarargs         | Java 7 支持，忽略任何使用参数为泛型变量的方法或构造函数调用产生的警告。 |
| @Repeatable          | Java 8 支持，标识某注解可以在同一个声明上使用多次。                     |
| @FunctionalInterface | Java 8 支持，标识一个匿名函数或函数式接口。                             |


若某个方法被 @Deprecated 标注，则该方法不再被建议使用。如果有开发人员试图使用或重写被 @Deprecated 标示的方法，编译器会给相应的提示信息。

@Deprecated 的定义如下：

    @Documented
    @Retention(RetentionPolicy.RUNTIME)
    public @interface Deprecated {
    }

参数说明：

@interface 来修饰 Deprecated，意味着 Deprecated 实现了 java.lang.annotation.Annotation 接口；即 Deprecated 就是一个注解。 (02) @Documented -- 它的作用是说明该注解能出现在 javadoc 中。

注解保留策略 Retention Policy：

- RetentionPolicy.RUNTIME 编译器会将注解信息保留在 .class 文件中，并且能被虚拟机读取，因此可以通过反射机制获取。
- RetentionPolicy.CLASS   注解被编译器记录在 class 文件中，但是在运行时不存在，不需要虚拟机保留。
- RetentionPolicy.SOURCE  注解被编译器丢弃，即注解仅在源码中保留，class 文件中不存在。

@SuppressWarnings 常用的关键字的表格

- deprecation  -- 使用了不赞成使用的类或方法时的警告，如 @SuppressWarnings(value={"deprecation"})
- unchecked    -- 执行了未检查的转换时的警告，例如当使用集合时没有用泛型 (Generics) 来指定集合保存的类型。
- fallthrough  -- 当 Switch 程序块直接通往下一种情况而没有 Break 时的警告。
- path         -- 在类路径、源文件路径等中有不存在的路径时的警告。
- serial       -- 当在可序列化的类上缺少 serialVersionUID 定义时的警告。
- finally      -- 任何 finally 子句不能正常完成时的警告。
- all          -- 关于以上所有情况的警告。

@Target 作用是指定标注适用的对象类型，如 @Target({TYPE, FIELD, METHOD})：

- TYPE 意味着，它能标注"类、接口（包括注释类型）或枚举声明"。
- FIELD 意味着，它能标注"字段声明"。
- METHOD 意味着，它能标注"方法"。
- PARAMETER 意味着，它能标注"参数"。
- CONSTRUCTOR 意味着，它能标注"构造方法"。
- LOCAL_VARIABLE 意味着，它能标注"局部变量"。


*/

import java.lang.annotation.Annotation;
import java.lang.annotation.Target;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.Repeatable;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Inherited;
import java.lang.reflect.Method;
import java.util.*;

/**
 * Annotation 示例
 * @MyAnnotation
 * @MyAnnotation(value={"a", "b", "..."})
 * 不带参数使用 @MyAnnotation 意味着对应的 MyAnnotation 标注的 value 值是默认值 "unknown"
 */
@Retention(RetentionPolicy.RUNTIME)
@Repeatable(value=MyRepeater.class)
@interface MyAnnotation {
    String[] value() default "unknown";
    String date() default "'2020/08/16'";
    String dt = "2020/08/16";
}

@Target(ElementType.TYPE)
@Retention(RetentionPolicy.RUNTIME)
@interface MyRepeater{
    MyAnnotation[] value();
}

/**
 * Person 类使用 MyAnnotation 注解。
 */
@MyAnnotation("Ann for a class")
@MyAnnotation("More ann for a class")
@SuppressWarnings({"a", "b", "c", "..."})
class Person {
   
    @MyAnnotation
    @Deprecated
    public void empty(){
        System.out.println("\nempty");
    }
   
    @MyAnnotation(value={"girl","boy"}, date="2020/08/16")
    public void somebody(String name, int age){
        System.out.println("\nsomebody: "+name+", "+age);
    }

    @SuppressWarnings(value={"deprecation"})
    public static void doSomething(){
        // Date​(int year, int month, int date) Deprecated.
        Date date = new Date(113, 8, 26);
        System.out.println(date);
    }
}

public class AnnotationsDemo {

    public static void main(String[] args) throws Exception {
       
        Person person = new Person();
        person.doSomething(); // deprecation or @SuppressWarnings
        // person.empty(); // deprecation

        // Class cp = Person.class;
        Class<Person> cp = Person.class;
        Method mSomebody = cp.getMethod("somebody", new Class[]{String.class, int.class});
        mSomebody.invoke(person, new Object[]{"lily", 18});

        Annotation[] ans = cp.getDeclaredAnnotations();
        // Annotation[] ans = cp.getAnnotations();
        Arrays.asList(ans).forEach(an -> System.out.println(an));

        iteratorAnnotations(mSomebody);
       
        Method mEmpty = cp.getMethod("empty", new Class[]{});
        mEmpty.invoke(person, new Object[]{});        
        iteratorAnnotations(mEmpty);
    }
   
    public static void iteratorAnnotations(Method method) {

        System.out.println("-----------------MyAnnotation---------------------");
        if(method.isAnnotationPresent(MyAnnotation.class)){
            MyAnnotation myAnnotation = method.getAnnotation(MyAnnotation.class);
            String[] values = myAnnotation.value();
            for (String str:values)
            {
                System.out.printf(str+", ");
            }
            System.out.println(myAnnotation.dt);
            System.out.println();
        }
       
        System.out.println("-----------------Annotations---------------------");
        Annotation[] annotations = method.getAnnotations();
        for(Annotation annotation : annotations){
            System.out.println(annotation);
        }
    }
}