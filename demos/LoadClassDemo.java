import java.lang.reflect.*;
import java.util.*;

class Gum {
    private int weight = 0;
    static { System.out.println("Loading Gum..."); }
    public Gum(){ }
    public Gum(int i){ weight = i; }
    public String greeting(){ return "Hi!"; }
    public String typeloader()
    { 
        System.out.println("ClassLoader for Gum: " + getClass().getClassLoader());
        return getClass().getClassLoader()+"";
    }
}

public class LoadClassDemo {
    public static void print(Object obj) {
        System.out.println(obj);
    }
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        try {

            print("--------------sun.boot.class.path--------------");
            // BoostrapClassLoader
            String booProperty = System.getProperty("sun.boot.class.path");
            String[] forBoo = booProperty.split(";");
            Arrays.asList(forBoo).forEach(s -> System.out.println(s));


            print("-----------------java.ext.dirs-----------------");
            // ExtClassLoader for jre/lib/*.jar
            String extProperty = System.getProperty("java.ext.dirs");
            String[] forExt = extProperty.split(";");
            Arrays.asList(forExt).forEach(s -> System.out.println(s));

            print("----------------java.class.path----------------");
            // AppClassLoader for classpath
            String appProperty = System.getProperty("java.class.path");
            String[] forApp = appProperty.split(";");
            Arrays.asList(forApp).forEach(s -> System.out.println(s));


            Class clz = Class.forName("Gum");
            // ClassLoader.loadClass("Gum");

            // Class clazz = Gum.class;
            // Constructor[] cts = clz.getConstructors();
            // for ( Constructor c:cts ) {
            //    print("Contructor: "+c.getName​());
            // }
            // Constructor constructor = clz.getConstructor();
            // Object object = clz.newInstance(); 


            Constructor cons = clz.getConstructor(int.class);
            // cons.setAccessible(true);
            Object object = cons.newInstance(90);

            Method method = clz.getMethod("greeting");
            String msg = (String)method.invoke(object);
            print(msg);

            Field field = clz.getDeclaredField("weight");
            field.setAccessible(true);
            print("get private member:"+field.get(object));

            // return null for Bootstrap class loader
            Class<?> class1 = Class.forName("Gum");
            // ClassLoader cl = class1.getClassLoader();
            // ClassLoader cl = new Gum().getClass().getClassLoader();
            ClassLoader cl = Gum.class.getClassLoader();

            if (cl==null){
                print("class loader is bootstrap class loader.");
            }else{
                String name = cl.getClass().getName();
                print("class loader is " + name);
                print("1st parent loader is " + cl.getParent());
                print("2nd parent loader is " + cl.getParent().getParent());
            }

        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
