import java.lang.reflect.*;

class Gum {
    private int weight = 0;
    static { System.out.println("Loading Gum"); }
    public Gum(){ }
    public Gum(int i){ weight = i; }
    public String greeting(){ return "Hi!"; }
}

public class LoadClassDemo {
    public static void print(Object obj) {
        System.out.println(obj);
    }
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        try {
            Class clz = Class.forName("Gum");

            // Class clazz = Gum.class;
            // Constructor[] cts = clz.getConstructors();
            // for ( Constructor c:cts ) {
            //    print("Contructor: "+c.getName​());
            // }
            // Constructor constructor = clz.getConstructor();
            // Object object = clz.newInstance(); 


            Constructor cons = clz.getConstructor(int.class);
            // cons.setAccessible(true);
            Object object = cons.newInstance(0);

            Method method = clz.getMethod("greeting");
            String msg = (String)method.invoke(object);
            print(msg);

            Field field = clz.getDeclaredField("weight");
            field.setAccessible(true);
            print("get private member:"+field.get(object));

            Class<?> class1 = Class.forName("Gum");
            String name = class1.getClassLoader().getClass().getName();
            print("class loader is " + name);

        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
