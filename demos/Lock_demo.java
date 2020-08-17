/*
https://www.cnblogs.com/linkworld/p/7458559.html

Lock 接口的出现替代了同步代码块或者同步函数，将同步的隐式锁操作变成显式锁操作，同时更为灵活，可以在一个锁上加上多个监视器。

Lock 接口中的方法:
- lock(): 获取锁
- unlock(): 释放锁, 这个动作是必须要完成的, 所以通常需要定义在 finally 代码块中
- tryLock​(long time, TimeUnit unit) 尝试等待指定时间，超时就进入中断退出
- newCondition() 返回条件监视器

Condition 接口的出现替代了 Object 类中的 wait()、notify()、notifyAll() 方法，将这些
监视器方法单独进行了封装，变成 Condition 监视器对象，可以与任意锁进行组合。

常用方法:

- await(): 让线程处于冻结状态
- signal(): 唤醒一个等待线程
- signalAll(): 唤醒所有等待线程

格式:
Condition c1 = lock.newCondition(); // 新建一个监视器对象


*/
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.stream.IntStream;

public class Lock_demo {

    private static Lock lock = new ReentrantLock();
    // private static Lock lock = new ReentrantLock(true);
    
    public static void main(String[] args) {
        IntStream.range(0, 5).forEach( i ->{
            // 匿名类
            new Thread() {
                public void run() {
                    String thread = Thread.currentThread().getName();
                    System.out.println(thread + " running...");
                    log(thread);
                };
            }.start();
        });
    }

    static public void log(String t) {
        for ( int i=0; i<2; i++) {
            lock.lock();
            try {
                System.out.println(t);
                Thread.sleep(100);
            }catch(Exception e){
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }
}
