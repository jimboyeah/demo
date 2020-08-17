/*
https://javatutorial.net/java-volatile-example
*/

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.stream.IntStream;

public class Lock_volatile {

    public static void main(String[] args)
    {
        IntStream.range(1000, 1009).forEach( i ->{
            // 匿名类
            new Thread() {
                public void run() {
                    String thread = Thread.currentThread().getName();
                    try{
                        Thread.sleep(100);
                    } catch(Exception ex){}
                    log("Thread #" + i + " " + Singleton.getInstance().toString());
                };
            }.start();
        });
    }

    static public void log(String msg) {
        System.out.println(msg);
    }
}

class Singleton {
    // private static Singleton _instance;
    private static volatile Singleton _instance; // volatile variable
    public static Singleton getInstance() {
        if (_instance == null) {
            synchronized (Singleton.class) {
                if (_instance == null) _instance = new Singleton();
            }
        }
        return _instance;
    }
}