/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/lang/Math.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/Random.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/security/SecureRandom.html

## ThreadLocalRandom

Java7 新增，给多线程并发生成随机数使用的。ThreadLocalRandom 比 Random 快，因为 Random 在生成随机数的时候使用了 CAS。

ThreadLocalRandom 通过静态方法实例化：

    ThreadLocalRandom.current().nextInt(5);

## SecureRandom

在需要频繁生成随机数，或者安全要求较高的时候，避免使用 Random 被预测的到产生的随机值。

内置 NativePRNG 和 SHA1PRNG 两种随机数算法，默认使用 NativePRNG，可以配置 -Djava.security 参数来修改调用的算法。如果是 /dev/[u]random 就是 NativePRNG，否则就是 SHA1PRNG。在 JVM 启动参数设置 -Djava.security=file:/dev/urandom。

当然还可以通过 getInstance 来初始化对象：

    SecureRandom secureRandom = new SecureRandom();
    SecureRandom secureRandom3 = SecureRandom.getInstance("SHA1PRNG");
    SecureRandom secureRandom2 = SecureRandom.getInstance("SHA1PRNG", "SUN");

另外，这个类生成随机数，首次调用性能比较差，如果条件允许最好服务启动后先调用一下 nextInt()。实际上 SHA1PRNG 的性能将近要比 NativePRNG 好一倍，synchronized 的代码少了一半，所以没有特别重的安全需要，尽量使用 SHA1PRNG 算法生成随机数。

*/

import java.util.concurrent.*;
import java.util.stream.*;
import java.util.*;
import java.security.*;

public class RandomDemo
{ 
    static public void main(String args[]) throws InterruptedException
    { 
        log("-----------------------Math.random()-----------------------");
        IntStream.range(1, 25).forEach(i -> {
            // 使用 Lambda 来创建线程
            Thread t1 = new Thread(() -> log( getThreadName() + " -> " + Math.random()), "Math.random()");
            t1.start();
        });

        log("---------------------ThreadLocalRandom---------------------");
        int rt = ThreadLocalRandom.current().nextInt(1, 3);
        log("sleep for a seconds " + rt);
        TimeUnit.SECONDS.sleep(rt);
        
        log("-----------------------Random.ints()-----------------------");
        IntStream limit = new Random().ints(20, 1, 1000).limit(10);        
        limit.parallel().map(e -> { log(e+""); return e; }).min();

        log("------------------------Random.next------------------------");
        Random random = new Random();
        System.out.println("random.nextInt() -> " + random.nextInt());
        System.out.println("random.nextDouble() -> " + random.nextDouble());

        log("-----------------------SecureRandom-----------------------");
        SecureRandom secureRandom = new SecureRandom();
        log("secureRandom.getAlgorithm() -> " + secureRandom.getAlgorithm());
        log("secureRandom.nextInt(10) -> " + secureRandom.nextInt(10));
        log("secureRandom.nextLong() -> " + secureRandom.nextLong());
        log("secureRandom.nextDouble() -> " + secureRandom.nextDouble());
        log("secureRandom.nextGaussian() -> " + secureRandom.nextGaussian());
        // void nextBytes​(byte[] bytes)
    }

    static public String getThreadName()
    {
        return Thread.currentThread().getName();
    }

    static public void log(String t)
    {
        System.out.println(t); 
    } 
}