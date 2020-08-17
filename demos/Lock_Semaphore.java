/* 
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/concurrent/Semaphore.html
Semaphore 里面居然有这么一个大坑！
https://www.cnblogs.com/thisiswhy/p/13419807.html
https://docs.oracle.com/javase/7/docs/api/java/util/concurrent/Semaphore.html
https://docs.oracle.com/javase/8/docs/api/index.html?java/lang/Thread.html

信号量 Semaphores 机制是一种卓有成效的进程同步工具，由荷兰学者 Dijkstra 提出。

信号量的值仅能由 PV 操作来改变。

- P 操作（wait）申请一个单位资源，然后进程进入。
- V 操作（signal）释放一个单位资源，然后进程出来。

Semaphore 信号量维护一定数量的特权，当特权有余量，线程通过 acquire 方法可以获取到代码执行特权，用完后使用 release 方法归还这。

Semaphore 可以用于流量控制，特别是对并发数有限制的场景。如数据库同时只允许有 20 个线程访问，就可以使用信号量来实现。

当特权使用完后，线程再执行 acquire 就会进入同步阻塞，等待其它线程归还特权后，再继续获取特权执行同步代码。

    Semaphore​(int permits) 
    Semaphore​(int permits, boolean fair)   

构造函数可以指定是是使用公平锁，默认是 nonfair fairness。

死锁的四个必要条件：

- 互斥条件：一个资源每次只能被一个进程使用
- 请求与保持条件：进程已经保持了至少一个资源，但又提出了新的资源请求
- 不可剥夺条件:进程所获得的资源在未使用完毕之前，不能被其他进程强行夺走，即只能由获得该资源的进程自己来释放。
- 循环等待条件: 若干进程间形成首尾相接循环等待资源的关系。

Output:
    现有 3 个空车位
    二师兄 来停车，车位 2/3 
    大师兄 来停车，车位 1/3 
    师傅 来停车，车位 1/3 
    师傅 停车后，车位 1/0 
    大师兄 被劝走，因为保安不喜欢它 
    二师兄 停车后，车位 2/1 
    师傅 要开车走了，车位 1/0 
    师傅 把车开走后，车位 1/1二师兄 要开车走了，车位 2/0 
    二师兄 把车开走后，车位 2/3
*/

import java.util.concurrent.*;
import java.lang.*;

public class Lock_Semaphore
{ 
    static public void main(String args[]) { 
        // ReentrantLock rel = new ReentrantLock();
        Semaphore sph = new Semaphore(3, true);
        log("现有 3 个空车位");
        Thread t1 = new Thread(new Parking(1, "布加迪", sph), "大师兄");
        Thread t2 = new Thread(new Parking(2, "法拉利", sph), "二师兄");
        Thread t3 = new Thread(new Parking(1, "白龙马", sph), "师傅");
        t1.start();
        t2.start();
        t3.start();
        t1.interrupt();
    } 
    static public void log(String t){
        System.out.println(t); 
    }
}

class Parking implements Runnable
{
    private int space;
    private String car;
    private Semaphore semaphore;

    public Parking(int n, String car, Semaphore sph)
    {
        this.car = car;
        this.space = n;
        this.semaphore = sph;
    }

    @Override
    public void run()
    {
        String user = Thread.currentThread().getName();
        try{
            System.out.printf("%s 来停车，车位 %d/%d \n", user, space, semaphore.availablePermits());
            semaphore.acquire(space); // decrease permits
            System.out.printf("%s 停车后，车位 %d/%d \n", user, space, semaphore.availablePermits());
        }catch(InterruptedException ex){
            System.out.printf("%s 被劝走，因为保安不喜欢它 \n", user);
            return; // avoid semaphore.release(space);
        }

        try {
            int parkTime = ThreadLocalRandom.current().nextInt(1, 6);
            TimeUnit.SECONDS.sleep(parkTime);
            System.out.printf("%s 要开车走了，车位 %d/%d \n", user, space, semaphore.availablePermits());
        }catch(Exception ex){
            ex.printStackTrace();
        }finally{
            semaphore.release(space); // increase permits
            System.out.printf("%s 把车开走后，车位 %d/%d \n", user, space, semaphore.availablePermits());
        }
    }
}

