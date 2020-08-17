/*
https://www.liaoxuefeng.com/wiki/1252599548343744/1306581182447650

使用 Future 获得异步执行结果时，要么调用阻塞方法 get()，要么轮询看 isDone() 是否为 true，这两种方法都不是很好，因为主线程也会被迫等待。

    ExecutorService executor = Executors.newFixedThreadPool(4); 
    Callable<String> task = new Task();
    Future<String> future = executor.submit(task);
    // 从Future获取异步执行返回的结果，可能阻塞:
    String result = future.get();

可以通过 cancel() 方法取消 Feture 的执行。

Java 8 引入 CompletableFuture 改进 Future，可以传入回调对象，当异步任务完成或者发生异常时，自动调用回调对象的回调方法。

CompletableFuture 优点：

- 异步任务结束时，会自动回调某个对象的方法；
- 异步任务出错时，会自动回调某个对象的方法；
- 主线程设置好回调后，不再关心异步任务的执行。

除了异步回调机制，CompletableFuture 更强大的功能是串行、并行执行多个 CompletableFuture。

*/

import java.util.concurrent.CompletableFuture;

public class CompletableFuture_TEST 
{
    public static void main(String[] args) throws Exception 
    {
        CompletableFuture<Double> cf = CompletableFuture.supplyAsync(CompletableFuture_TEST::fetchPrice);

        cf.thenAccept((result) -> {
            System.out.println("price: " + result);
        });

        cf.exceptionally((e) -> {
            e.printStackTrace();
            return null;
        });

        // 串行任务，使用 lambda 语法简化
        CompletableFuture<String> cff = cf.thenApplyAsync((price) -> {
            return "Price: " + price;
        });
        cff.thenAccept((result) -> {
            System.out.println("cff return: " + result);
        });

        // 用 anyOf 并行为一个新的 CompletableFuture:
        CompletableFuture<Object> cfp = CompletableFuture.anyOf(cf, cff);
        cfp.thenAccept( ret -> System.out.println("Parallel return " + ret));


        // 主线程等待 CompletableFuture 返回，否则默认使用的线程池会立刻关闭:
        Thread.sleep(200);
    }

    static Double fetchPrice() {
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
        }
        if (Math.random() < 0.3) {
            throw new RuntimeException("FETCH PRICE FAILED!");
        }
        return 5 + Math.random() * 20;
    }
}

