/*

*/

import java.util.concurrent.atomic.*;

public class circler extends Thread 
{
    public static void main(String[] args) 
    {
        A a = new A();
        B b = new B(a);
        a.setB(b);
        System.out.println(a.getB());
    }
}

class A 
{
    private B b;

    public B getB() {
        return b;
    }

    public void setB(B b) {
        this.b = b;
    }
}

class B 
{
    private A a;

    public B(A a) {
        this.a = a;
    }
    
    public A getA() {
        return a;
    }
}