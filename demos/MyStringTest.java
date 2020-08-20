import java.lang.*;
import java.lang.reflect.*;

public class MyStringTest
{
    public static void main(String[] argv) throws Exception
    {
        LoaderDemo ld = new LoaderDemo();
        System.out.println(LoaderDemo.MyClassLoader.class);
        LoaderDemo.MyClassLoader ml = ld.new MyClassLoader();

        // java.lang.SecurityException: Prohibited package name: java.lang
        // Class<?> clz = Class.forName("java.lang.MyString");

        System.out.println("prent ClassLoader: " + ml.getParent());
        Class<?> clz = ml.loadClass("java.lang.MyString");
        Constructor constructor = clz.getConstructor(int.class);

        System.out.println(clz);
        Object object = constructor.newInstance(0);
        System.out.println(object);
        // MyString ms = new MyString();
        // System.out.println(ms.name);
    }
}
