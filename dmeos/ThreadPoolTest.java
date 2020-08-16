/*
Java JUC 包 https://www.cnblogs.com/linkworld/p/7819270.html

线程池提供了一个线程队列，队列中保存着所有等待状态的线程。避免了创建与销毁线程的额外开销，提高了响应速度。

线程池的体系结构

- java.util.concurrent.Executor: 负责线程的使用和调度的根接口;
- ExecutorService: 子接口,线程池的主要接口;
- ThreadPoolExecutor: 线程池的实现类;
- ScheduledExecutorService: 子接口,负责线程的调度;
- ScheduledThreadPoolExecutor: 继承了线程池的实现类,实现了负责线程调度的子接口;

工具类: Executors
- ExecutorService newFixedThreadPool(): 创建固定大小的线程池;
- ExecutorService newCachedThreadPool(): 缓存线程池,线程池中线程的数量不固定,可以根据需求自动更改数量;
- ExecutorService newSingleThreadExecutor(): 创建单个线程池, 线程池中只有一个线程;
- ScheduledExecutorService newScheduledThreadPool(): 创建固定大小的线程,可以延时或定时的执行任务;

线程的生命周期是个不可循环的过程，一个线程对象结束了不能再次 start，否则 java.lang.IllegalThreadStateException 异常。

*/

import java.util.concurrent.*;
import java.util.stream.*;

public class ThreadPoolTest
{
    public static void main(String[] args)
    {
        // ThreadTest();
        PoolTest();
    }

    public static void ThreadTest()
    {
        IntStream.range(100, 110).forEach(i -> {
            Thread thread = new Thread(new ThreadDemo(), "T"+i);
            thread.start();
        });
    }

    public static void PoolTest()
    {
        // 1. 创建线程池
        ExecutorService pool = Executors.newFixedThreadPool(9);

        // 2. 为线程池中线程分配任务
        //    submit(Callable<T> task)
        //    submit(Runnable task)

        ThreadDemo tpd = new ThreadDemo();
        for(int i=0; i<10; i++)
        {
            pool.submit(tpd);
        }

        // 3. 关闭线程池
        pool.shutdown();
    }
}

class ThreadDemo implements Runnable{

    private int i=100;

    public void run()
    {
        while(i <= 120){
            System.out.println(i++ + " " + Thread.currentThread().getName());
            try{
            Thread.sleep(10);
            }catch(Exception ex){ ex.printStackTrace(); }
        }
    }
}
