/*
https://www.liaoxuefeng.com/wiki/1252599548343744/1306581033549858

使用 ReentrantLock 比直接使用 synchronized 更安全，可以替代 synchronized 进行线程同步。

但是，synchronized 可以配合 wait 和 notify 实现线程在条件不满足时等待，条件满足时唤醒。

用 ReentrantLock 我们怎么编写wait和notify的功能呢？答案是使用 Condition 对象来实现。

我们仍然以TaskQueue为例，把前面用synchronized实现的功能通过ReentrantLock和Condition来实现：

可见，使用Condition时，引用的Condition对象必须从Lock实例的newCondition()返回，这样才能获得一个绑定了Lock实例的Condition实例。

Condition提供的await()、signal()、signalAll()原理和synchronized锁对象的wait()、notify()、notifyAll()是一致的，并且其行为也是一样的：

await()会释放当前锁，进入等待状态；

signal()会唤醒某个等待线程；

signalAll()会唤醒所有等待线程；

唤醒线程从await()返回后需要重新获得锁。

此外，和tryLock()类似，await()可以在等待指定时间后，如果还没有被其他线程通过signal()或signalAll()唤醒，可以自己醒来：

if (condition.await(1, TimeUnit.SECOND)) {
    // 被其他线程唤醒
} else {
    // 指定时间内没有被其他线程唤醒
}
可见，使用Condition配合Lock，我们可以实现更灵活的线程同步。

小结
Condition可以替代wait和notify；

Condition对象必须从Lock对象获取。

*/

import java.util.concurrent.*;
import java.util.stream.*;


class Lock_condition {
    private final Lock lock = new ReentrantLock();
    private final Condition condition = lock.newCondition();
    private Queue<String> queue = new LinkedList<>();

    public static void main(String[] argv)
    {
        Lock_condition lc = new Lock_condition();

    }

    public void addTask(String s) {
        lock.lock();
        try {
            queue.add(s);
            condition.signalAll();
        } finally {
            lock.unlock();
        }
    }

    public String getTask() {
        lock.lock();
        try {
            while (queue.isEmpty()) {
                condition.await();
            }
            return queue.remove();
        } finally {
            lock.unlock();
        }
    }
}