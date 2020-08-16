/*
ConcurrentModificationException详解 https://www.jianshu.com/p/c5b52927a61a
Java提高篇（三四）-----fail-fast机制 https://blog.csdn.net/chenssy/article/details/38151189
Java Synchronized 同步锁 http://blog.csdn.net/luoweifu/article/details/46613015

Synchronized 同步锁用法：

1. 修饰一个代码块，被修饰的代码块称为同步语句块，同步作用于这个代码块的对象；
2. 修饰一个方法，称为同步方法，其作用的范围是整个方法，同步作用于调用这个方法的对象；
3. 修改一个静态的方法，其作用的范围是整个静态方法，作用的对象是这个类的所有实例；
4. 修改一个类，其作用的范围是 synchronized 后面括号括起来的部分，作用于这个类的所有实例。

使用示范；

    public void method()
    {
       synchronized(this) {
          // todo
       }
    }

    public synchronized void method()
    {
       // todo
    }

    public synchronized static void method() {
       // todo
    }

    class ClassName {
       public void method() {
          synchronized(ClassName.class) {
             // todo
          }
       }
    }

synchronized 修饰一个方法为同步方法，但不能在构造器上使用。同步加锁的是对象，而不是代码。

- 修饰实例方法，相当于 synchronized(this);
- 修饰静态方法，相当于 synchronized(this.class);
- 修饰代码块的形式是 synchronized(Object)。

如果锁的是类对象 class，尽管 new 多个实例对象，但他们仍然是属于同一个类依然会被锁住，线程之间保证同步关系。

synchronized 是重量级锁，从系统层面实现上效率较低，。

- 偏向锁
- 轻量级锁

*/

import java.util.stream.*;
import java.util.Random;

public class Lock_synchronized 
{ 
    static public void main(String args[]) 
    { 
        IntStream.range(0, 10).forEach( i -> {
            Thread t1 = new Thread(new SyncThread());
            t1.start();
        });
        // 使用 Lambda 来创建线程
        // Thread t1 = new Thread(() -> log(" -> " + Math.random()), "Math.random()");
    } 
    
    static public void log(String t)
    {
        System.out.println(t); 
    } 
}

class SyncThread implements Runnable 
{
    // { System.out.println("Dynamic Code Block "); } 
    // static { System.out.println("Static Code Block "); } 

    private static int count = 0;

    public SyncThread() 
    {
        System.out.println("new SyncThread.");
        // count = 0; this fault
    }

    public synchronized static void increase() 
    {
        IntStream.range(0, 2).forEach( i -> {
            try {
                System.out.println(Thread.currentThread().getName() + " -> " + (count++));
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }); 
    }

    public synchronized void run() 
    {
        increase();
    }
}