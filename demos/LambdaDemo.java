/*
https://docs.oracle.com/javase/8/docs/api/java/util/function/package-summary.html
https://docs.oracle.com/javase/tutorial/java/javaOO/lambdaexpressions.html
*/
import java.util.concurrent.*;
import java.util.function.*;

public class LambdaDemo 
{ 
    public static void main(String args[])
    {
        // 方法引用写法
        Consumer<String> consumer = System.out::println;
        consumer.accept("abc");

        // 普通的Lambda写法
        consumer = s -> System.out.println(s);
        consumer.accept("xyz");

        int sleep = ThreadLocalRandom.current().nextInt(1, 6);

        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try{
                    TimeUnit.SECONDS.sleep(sleep);
                }catch(InterruptedException ex){
                    // ...
                }
                System.out.println("Runnable...");
            }
        });

        // 使用 Lambda 来创建线程
        Thread t2 = new Thread(() -> System.out.println("Lambda running..."));
        t1.start();
        t2.start();
    }
}