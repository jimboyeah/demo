/*
https://zhuanlan.zhihu.com/p/68089617

类加载的双亲委托机制

一个 class 文件发送请求加载,会先找到自定义的类加载器,当然这里没画出来
APPClassLoader 得到加载器请求后，向上委托交给 ExtClassLoader，再委托 BoostrapClassLoader，这是向上委托方向
最终到达 BoostrapClassLoader 会先在缓存中找，没有就尝试在自己能加载的路径去加载，找不到就交给 ExtClassLoader，一直到用户自定义的 ClassLoader，这就是向下查找方向

前面说的类的唯一性由类和类加载器共同决定, 这样保证了确保了类的唯一性
弄清楚这些,我们可以开始验证自定义的类加载器是否可以加载我们自定义的这个 java.lang.System 类了

自定义类加载器
新建一个 MyClassLoader 继承 ClassLoader 并重写 loadclass 方法，读入字节码，使用 defineClass 返回类定义。

java -cp demos LoaderDemo

*/

import java.io.InputStream;
import java.util.*;
import java.io.*;

public class LoaderDemo {

    public static void main(String[] args) throws ClassNotFoundException
    {
        System.out.println("--------------sun.boot.class.path--------------");
        // BoostrapClassLoader
        String booProperty = System.getProperty("sun.boot.class.path");
        String[] forBoo = booProperty.split(";");
        Arrays.asList(forBoo).forEach(s -> System.out.println(s));


        System.out.println("-----------------java.ext.dirs-----------------");
        // ExtClassLoader for jre/lib/*.jar
        String extProperty = System.getProperty("java.ext.dirs");
        String[] forExt = extProperty.split(";");
        Arrays.asList(forExt).forEach(s -> System.out.println(s));

        System.out.println("----------------java.class.path----------------");
        // AppClassLoader for classpath
        String appProperty = System.getProperty("java.class.path");
        String[] forApp = appProperty.split(";");
        Arrays.asList(forApp).forEach(s -> System.out.println(s));

        LoaderDemo ld = new LoaderDemo();
        MyClassLoader ml = ld.new MyClassLoader();
        System.out.println("prent ClassLoader: " + ml.getParent());
        Class cl = ml.loadClass("Gum");
        System.out.println("Class loaded: " + cl);
    }

    /**
     * @Description 自定义ClassLoader
     * @Author apdoer
     * @Date 2019/5/28 15:27
     * @Version 1.0
     */
    public class MyClassLoader extends ClassLoader
    {
        public MyClassLoader(){
            super(null);
        }

        protected Class<?> findClass(String name) throws ClassNotFoundException {
            throw new ClassNotFoundException(name);
        }

        @Override
        public Class<?> loadClass(String name) throws ClassNotFoundException {
            try {
                String className = null;
                if (name != null && !"".equals(name)){
                    if (name.startsWith("java.lang") && !name.startsWith("java.lang.MyString")){
                        return super.loadClass(name);
                        // className = new StringBuilder("/").append(name.replace('.','/')).append(".class").toString();
                    }else {
                        className = new StringBuffer(name.replace('.', File.separatorChar)).append(".class").toString();
                        // className = new StringBuffer(name.substring(name.lastIndexOf('.')+1)).append(".class").toString();
                    }
                    System.out.println("MyClassLoder loadClass: " + className + " -> " + name);
                    InputStream is = getClass().getResourceAsStream(className);
                    System.out.println(is + " " + is.available());
                    if (is == null) return super.loadClass(name);
                    byte[] bytes = new byte[is.available()];
                    is.read(bytes);
                    return defineClass(name, bytes, 0, bytes.length);
                }
            }catch (Exception e){
                e.printStackTrace();
                throw new ClassNotFoundException();
            }
            return super.loadClass(name);
        }
    }
}