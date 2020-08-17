/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/concurrent/atomic/AtomicInteger.html#method.summary

内部 compareAndSet 方法使用 Unsafe 调用 native 原生方法 CAS（CompareAndSet）递增数值。

    public final boolean compareAndSet(int expect, int update) {
        return unsafe.compareAndSwapInt(this, valueOffset, expect, update);
    }

CAS 利用 CPU 调用底层指令实现，单一处理器，进行简单的读写操作时，能保证自身读取的原子性，多处理器或复杂的内存操作时，CAS 采用总线加锁或缓存加锁方式保证原子性。

在多核心 CPU 中使用总线加锁，如 i=0 初始化，多处理器多线程环境下进行 i++ 操作下，处理器核心 A 和 B 同时读取 i 值到各自缓存，分别进行递增，回写值 i=1 相同。处理器提供 LOCK# 信号，进行总线加锁后，处理器 A 读取 i 值并递增，处理器 B 被阻塞不能读取 i 值。

总线加锁，在 LOCK# 信号下，其他线程无法操作内存，性能较差，缓存加锁能较好处理该问题。

缓存加锁，处理器核心 A 和 B 同时读取 i 值到缓存，处理器 A 提前完成递增，数据立即回写到主内存，并让处理器 B 缓存该数据失效，处理器 B 需重新读取 i 值。

*/

import java.util.concurrent.atomic.*;

public class AtomicDemo extends Thread 
{
    private static final AtomicInteger TEST_INT = new AtomicInteger();

    @Override
    public void run() {
        if (TEST_INT.intValue()<100) TEST_INT.incrementAndGet();
    }

    public static void main(String[] args) {
        for (int i = 0; i < 1000; i++) {
            AtomicDemo demo = new AtomicDemo();
            demo.start();
            // demo.join();
        }
        
        System.out.println("最终结果："+TEST_INT);
    }
}
