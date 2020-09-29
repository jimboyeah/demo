// ==========================================================
//  Spring Reactor & WebFlux
// ==========================================================

/*
https://projectreactor.io/docs/core/release/api/reactor/core/publisher/Mono.html
https://projectreactor.io/docs/core/release/api/reactor/core/publisher/Flux.html
https://projectreactor.io/docs/core/release/api/reactor/core/scheduler/Schedulers.html

Flux.just 静态方法创建一个 Flux，它发出所提供的元素，然后完成。

其它 Reactor 的创建方式参考：

    // Flux.create 静态方法以编程方式发射数据
    Flux.create((t) -> {
            t.next("create");
            t.next("create1");
            t.complete();
        }).subscribe(System.out::println);

    // Flux.generate 以编程方式创建一个的 Flux，通过 consumer 回调逐一生成信号
    // 注意 generate.next() 只能调用 1 次
    Flux.generate(t -> {
            t.next("generate");
            t.complete();
        }).subscribe(System.out::println);

    String[] fruits = new String[] {
        "Apple", "Orange", "Grape", "Banana", "Strawberry" };
    
    Flux<String> fruitFlux = Flux.fromArray(fruits);

    List<String> fruitList = new ArrayList<>();
    fruitList.add("Apple");
    fruitList.add("Orange");
    fruitList.add("Grape");
    fruitList.add("Banana");
    fruitList.add("Strawberry");
    Flux<String> fruitFlux = Flux.fromIterable(fruitList);

    Flux<Long> intervalFlux = Flux.interval(Duration.ofSeconds(1)).take(5);

    public void createAFlux_fromStream() {
        Stream<String> fruitStream =
            Stream.of("Apple", "Orange", "Grape", "Banana", "Strawberry");
        Flux<String> fruitFlux = Flux.fromStream(fruitStream);
        // ... verify steps
    }

其它过滤方法及辅助方法参考：

Flux，skip() 操作将创建一个新的 Flux，该 Flux 在从源 Flux 发出剩余项之前跳过指定数量的项。
对该流调用 skip(3) 将生成一个新的流，该流跳过前三个项，并且只发布最后两个项。

    Flux<String> skipFlux = Flux.just(
        "one", "two", "skip a few", "ninety nine", "one hundred")
        .skip(3);

    StepVerifier.create(skipFlux)
        .expectNext("ninety nine", "one hundred")
        .verifyComplete();

下面的测试方法使用 skip() 创建一个在发出任何值之前等待 4 秒的 Flux。由于该 Flux 是从项之间具有 1 秒延迟（使用 delayElements()）的 Flux 创建的，因此只会发出最后两个项：

    Flux<String> skipFlux = Flux.just(
        "one", "two", "skip a few", "ninety nine", "one hundred")
        .delayElements(Duration.ofSeconds(1))
        .skip(Duration.ofSeconds(4));

    StepVerifier.create(skipFlux)
        .expectNext("ninety nine", "one hundred")
        .verifyComplete();

skip() 跳过前几个项，take() 只发出前几个项：

    Flux<String> nationalParkFlux = Flux.just(
        "Yellowstone", "Yosemite", "Grand Canyon","Zion", "Grand Teton")
        .take(3);

    StepVerifier.create(nationalParkFlux)
        .expectNext("Yellowstone", "Yosemite", "Grand Canyon")
        .verifyComplete();

以下测试方法使用 take() 的替代形式在订阅后的前 3.5 秒内发出尽可能多的项：

    Flux<String> nationalParkFlux = Flux.just(
        "Yellowstone", "Yosemite", "Grand Canyon","Zion", "Grand Teton")
        .delayElements(Duration.ofSeconds(1))
        .take(Duration.ofMillis(3500));

    StepVerifier.create(nationalParkFlux)
        .expectNext("Yellowstone", "Yosemite", "Grand Canyon")
        .verifyComplete();
    
给定一个决定一个项是否通过 Flux 的 Predicate，filter() 操作允许你根据需要的任何条件有选择地发布。

    Flux<String> nationalParkFlux = Flux.just(
        "Yellowstone", "Yosemite", "Grand Canyon","Zion", "Grand Teton")
        .filter(np -> !np.contains(" "));
    
    StepVerifier.create(nationalParkFlux)
        .expectNext("Yellowstone", "Yosemite", "Zion")
        .verifyComplete();

也许你需要过滤的是你已经收到的任何项目。distinct() 操作产生一个只发布源 Flux 中尚未发布的项的 Flux。

    Flux<String> animalFlux = Flux.just(
        "dog", "cat", "bird", "dog", "bird", "anteater")
        .distinct();

    StepVerifier.create(animalFlux)
        .expectNext("dog", "cat", "bird", "anteater")
        .verifyComplete();

对于 Flux 或 Mono，最常用的操作之一是将已发布的项转换为其他形式或类型。Reactor 为此提供 map() 和 flatMap() 操作。

    Flux<Player> playerFlux = Flux
        .just("Michael Jordan", "Scottie Pippen", "Steve Kerr")
        .map(n -> {
            String[] split = n.split("\\s");
            return new Player(split[0], split[1]);
        });
    
    StepVerifier.create(playerFlux)
        .expectNext(new Player("Michael", "Jordan"))
        .expectNext(new Player("Scottie", "Pippen"))
        .expectNext(new Player("Steve", "Kerr"))
        .verifyComplete();

关于 map() 的重要理解是，映射是同步执行的，因为每个项都是由源 Flux 发布的。如果要异步执行映射，应考虑使用 flatMap() 操作。flatMap() 不是简单地将一个对象映射到另一个对象，而是将每个对象映射到一个新的 Mono 或 Flux。Mono 或 Flux 的结果被压成一个新的 Flux。当与subscribeOn() 一起使用时，flatMap() 可以释放 Reactor 类型的异步能力。

    Flux<Player> playerFlux = Flux
        .just("Michael Jordan", "Scottie Pippen", "Steve Kerr")
        .flatMap(n -> Mono.just(n).map(p -> {
            String[] split = p.split("\\s");
            return new Player(split[0], split[1]);
        })
        .subscribeOn(Schedulers.parallel())
        );
    
    List<Player> playerList = Arrays.asList(
        new Player("Michael", "Jordan"),
        new Player("Scottie", "Pippen"Pippen"),
        new Player("Steve", "Kerr"));
    
    StepVerifier.create(playerFlux)
        .expectNextMatches(p -> playerList.contains(p))
        .expectNextMatches(p -> playerList.contains(p))
        .expectNextMatches(p -> playerList.contains(p))
        .verifyComplete();

使用 flatMap() 和 subscribeOn() 的好处是，可以通过将工作分成多个并行线程来增加流的吞吐量。但由于这项工作是并行完成的，无法保证先完成哪项工作，因此无法知道产生的 Flux 中排放的项目的顺序。因此，StepVerifier 只能验证发出的每个项是否存在于 Player 对象的预期列表中，并且在 Flux 完成之前将有三个这样的项。

| Schedulers 方法 |                                               描述                                              |
|-----------------|-------------------------------------------------------------------------------------------------|
| .immediate()    | 在当前线程中执行订阅                                                                            |
| .single()       | 在单个可重用线程中执行订阅，对所有调用方重复使用同一线程                                        |
| .newSingle()    | 在每个调用专用线程中执行订阅                                                                    |
| .elastic()      | 在从无限弹性池中提取的工作进程中执行订阅，根据需要创建新的工作线程，默认释放空闲60 秒的工作线程 |
| .parallel()     | 在从固定大小的池中提取的工作进程中执行订阅，该池的大小取决于 CPU 核心的数量。                   |


在处理流经 Flux 的数据的过程中，你可能会发现将数据流分解成比特大小的块是有帮助的。buffer() 操作可以解决这个问题。

给定一个 String 值的 Flux，每个值都包含一个水果的名称，你可以创建一个新的 List 集合的 Flux，其中每个 List 的元素数不超过指定的数目：

    Flux<String> fruitFlux = Flux.just(
        "apple", "orange", "banana", "kiwi", "strawberry");
    
    Flux<List<String>> bufferedFlux = fruitFlux.buffer(3);
    
    StepVerifier
        .create(bufferedFlux)
        .expectNext(Arrays.asList("apple", "orange", "banana"))
        .expectNext(Arrays.asList("kiwi", "strawberry"))
        .verifyComplete();

在这种情况下，String 元素的 Flux 被缓冲到一个 List 集合的新 Flux 中，每个 List 集合包含的项不超过三个。因此，发出 5 个 String 的原始 Flux 将转换为发出两个List 集合的 Flux，一个包含 3 个水果，另一个包含 2 个水果。

将值从响应式 Flux 缓冲到非响应式 List 集合似乎适得其反。但是，当将 buffer() 与 flatMap() 结合使用时，它可以并行处理每个 List 集合：

    Flux.just("apple", "orange", "banana", "kiwi", "strawberry")
        .buffer(3)
        .flatMap(x -> 
             Flux.fromIterable(x)
                 .map(y -> y.toUpperCase())
                 .subscribeOn(Schedulers.parallel())
                 .log()
        ).subscribe();

在这个新示例中，仍然将 5 个 String 值的 Flux 缓冲到 List 集合的新 Flux 中，然后将 flatMap() 应用于 List 集合的 Flux。这将获取每个 List 缓冲区并从其元素创建一个新的 Flux，然后对其应用 map() 操作。因此，每个缓冲 List 在单独的线程中进一步并行处理。

为了证明它是有效的，我还包含了一个要应用于每个子 Flux 的 log() 操作。log() 操作只记录所有的 Reactor Streams 事件，这样你就可以看到真正发生了什么。

    02:16:21.234  INFO 5920 --- [     parallel-3] reactor.Flux.SubscribeOn.344    : onNext(APPLE)
    02:16:21.234  INFO 5920 --- [     parallel-3] reactor.Flux.SubscribeOn.344    : onNext(ORANGE)
    02:16:21.234  INFO 5920 --- [     parallel-4] reactor.Flux.SubscribeOn.345    : onNext(KIWI)
    02:16:21.234  INFO 5920 --- [     parallel-3] reactor.Flux.SubscribeOn.344    : onNext(BANANA)
    02:16:21.234  INFO 5920 --- [     parallel-4] reactor.Flux.SubscribeOn.345    : onNext(STRAWBERRY)
    02:16:21.234  INFO 5920 --- [     parallel-3] reactor.Flux.SubscribeOn.344    : onComplete()
    02:16:21.234  INFO 5920 --- [     parallel-4] reactor.Flux.SubscribeOn.345    : onComplete()

留意日志条目显示，第一个缓冲区（apple、orange 和 banana）中的水果在 parallel-3 线程中处理。同时，在第二个缓冲区（kiwi 和 strawberry）中的水果在 parallel-4 线程中进行处理。从每个缓冲区的日志条目交织在一起这一事实可以明显看出，这两个缓冲区是并行处理的。

如果出于某种原因，需要将 Flux 发出的所有内容收集到 List 中，则可以调用不带参数的 buffer()：

    Flux<List<List>> bufferedFlux = fruitFlux.buffer();

这将产生一个新的 Flux，该 Flux 会发出一个包含源 Flux 发布的所有项的 List。

使用 collectList() 操作也可以实现同样的功能，collectList() 生成一个发布 List 的 Mono，而不是生成一个发布 List 的 Flux。

    Flux<String> fruitFlux = Flux.just(
        "apple", "orange", "banana", "kiwi", "strawberry");
    Mono<List<String>> fruitListMono = fruitFlux.collectList();
    // ono<List<String>> fruitListMono = fruitFlux.collectMap(a -> a.charAt(0));

    StepVerifier
        .create(fruitListMono)
        .expectNext(Arrays.asList(
            "apple", "orange", "banana", "kiwi", "strawberry"))
        .verifyComplete();


有时你只需要知道 Mono 或 Flux 发布的条目是否符合某些条件，all() 和 any() 操作对反应式类型执行逻辑判断：

    Flux<String> animalFlux = Flux.just(
        "aardvark", "elephant", "koala", "eagle", "kangaroo");
    
    Mono<Boolean> hasAMono = animalFlux.all(a -> a.contains("a"));
    StepVerifier.create(hasAMono)
        .expectNext(true)
        .verifyComplete();

    Flux<String> animalFlux = Flux.just(
        "aardvark", "elephant", "koala", "eagle", "kangaroo");
    
    Mono<Boolean> hasAMono = animalFlux.any(a -> a.contains("t"));
    StepVerifier.create(hasAMono)
        .expectNext(true)
        .verifyComplete();

- all() 可以对 Flux 进行测试以确保所有消息在所有操作中都满足某些条件
- any() 可以对 Flux 进行测试以确保在任何操作中至少有一条消息满足某些条件

总结：

- 响应式编程包括创建数据流通过的管道。
- Reactor Stream 规范定义了四种类型：Publisher、Subscriber、Subscription 和 Transformer（Publisher 和 Subscriber 的组合）。
- Project Reactor 实现了 Reactive Steam，并将流定义抽象为两种主要类型，Flux 和 Mono，每种类型都提供数百个操作。
- Spring 5 利用 Reactor 创建响应式控制器、存储库、REST 客户端和其他响应式框架支持。

*/

package com.demos.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import reactor.core.publisher.Mono;
import reactor.core.publisher.Flux;
import reactor.core.scheduler.Schedulers;

import java.util.concurrent.*;
import java.time.*;

@Grab("reactor-core")
@Grab("spring-boot-starter-web")
// @Grab(group='org.projectreactor', module='reactor-core', version='1.1.6.RELEASE')

// curl localhost:8080
@RestController
public class HelloController {

    private void log(String msg)
    {
        // Groovy
        System.out.printf('%s %2$tD %1tT.%2$tL%n', msg, new Date());
        // Java
        // System.out.printf("%s %2$tD %1tT.%2$tL%n", msg, new Date());
    }

    // 阻塞 1 秒钟
    private String createStr() {
        try {
            TimeUnit.SECONDS.sleep(1);
        } catch (InterruptedException e) {
        }
        // return Groovy Map
        // String msg = '从客户端看不出效果，因为都是阻塞后才能返回到客户端，但是服务器端就不一样了，WebFlux 是异步非阻塞的。'
        // return "中汉 Hello %s!";

        String msg = "中汉"
        return [
            msg: msg,
            GBK2GBK: new String(msg.getBytes("GBK"), "GBK"),
            GBK2UTF8: new String(msg.getBytes("GBK"), "UTF-8"),
            GBK2UTF82: new String(new String(msg.getBytes("GBK"), "UTF-8").getBytes("GBK"), "UTF-8"),
            GBK2UTF82A: new String(new String(msg.getBytes("UTF-8"), "GBK").getBytes("UTF-8"), "GBK"),
            UTF82GBK: new String(msg.getBytes("UTF-8"), "GBK")
        ];
    }

    // 普通的 Spring MVC 方法
    @GetMapping("/1")
    private String get1() {
        log("get1 start");
        String result = createStr();
        log("get1 end.");
        return result;
    }

    // WebFlux 方法(返回的是 Mono)
    @GetMapping("/2")
    // @RequestMapping(value = "/2", produces = "text/html;charset=utf-8")
    // @ResponseBody
    private Mono<String> get2() {
        log("get2 start");
        Mono<String> result = Mono.fromSupplier({createStr()});
        // Mono<String> result = Mono.fromSupplier(() -> createStr());
        log("get2 end.");
        return result;
    }

    // @GetMapping("/helloWebFlux")
    // @GetMapping(value={"/", "/helloWebFlux"}) // Java
    @GetMapping(value=["/", "/helloWebFlux"]) // Groovy
    public Mono<String> helloWebFlux() {
        String html = String.join("\n"
                , "<html>"
                , "     <body>"
                , "         <p>Hello, WebFlux</p>"
                , "         <a href=\"/1\">SpringMVC</a> |"
                , "         <a href=\"/2\">WebFlux</a> |"
                , "         <a href=\"/createAFlux_just\">createAFlux_just</a> |"
                , "         <a href=\"/mergeFluxes\">mergeFluxes</a> |"
                , "         <a href=\"/zipFluxes\">zipFluxes</a> |"
                , "         <a href=\"/firstFlux\">firstFlux</a> |"
                , "         <a href=\"/bufferedFlux\">bufferedFlux</a> |"
                , "         <a href=\"/bufferedFlatMap\">bufferedFlatMap</a> |"
                , "         <p>" + new Date() + "</p>"
                , "     </body>"
                , "</html>");
        return Mono.just(html);
    }

    // 使用 Flux 简单地 emit 多个数据
    @GetMapping("/createAFlux_just")
    public Flux<String> createAFlux_just()
    {
        Flux<String> fruitFlux = Flux
            .just("Apple", "Orange", "Grape", "Banana", "Strawberry");
        fruitFlux.subscribe{
            f -> System.out.println("Here's some fruit: " + f);
        }
        return fruitFlux;
    }

    // 合并这两个 Flux 对象后，新的合并后的 Flux 被创建。
    // delayElements() 操作用来将数据发送速度减慢，0.5 秒发一个数据。
    // delaySubscription() 操作应用于延迟发送数据，因此 foodFlux 将会在 characterFlux 之后执行。
    @GetMapping("/mergeFluxes")
    public Flux<String> mergeFluxes()
    {
        Flux<String> characterFlux = Flux
            .just("Garfield", "Kojak", "Barbossa")
            .delayElements(Duration.ofMillis(500));
        
        Flux<String> foodFlux = Flux
            .just("Lasagna", "Lollipops", "Apples")
            .delaySubscription(Duration.ofMillis(250))
            .delayElements(Duration.ofMillis(500));
        
        Flux<String> mergedFlux = characterFlux.mergeWith(foodFlux);
        mergedFlux.subscribe{
            f -> System.out.println("mergedFlux:" + f);
        }
        return mergedFlux;
    }

    // 给静态方法 zip() 的 Function 接口简单地把两个值连接成一句话，由压缩后的 Flux 进行数据发送。
    @GetMapping("/zipFluxes")
    public Flux<Tuple2<String, String>> zipFluxes()
    {
        Flux<String> characterFlux = Flux.just("Garfield", "Kojak", "Barbossa");
        Flux<String> foodFlux = Flux.just("Lasagna", "Lollipops", "Apples");
        
        Flux<Tuple2<String, String>> zippedFlux = Flux.zip(characterFlux, foodFlux);
        zippedFlux.subscribe{
            f -> System.out.println("zipFluxex:" + f);
        }
        return zippedFlux;
    }

    // Flux.first() 选择第一个响应式类型进行发布
    // 在 fast Flux 已经开始发布后 100ms，slow Flux 才开始发布数据，
    // 这样导致新创建的 Flux 将完全忽略 slow Flux，而只发布 fast flux 中的数据。
    @GetMapping("/firstFlux")
    public Flux<String> firstFlux()
    {
        Flux<String> slowFlux = Flux.just("tortoise", "snail", "sloth")
            .delaySubscription(Duration.ofMillis(100));
        Flux<String> fastFlux = Flux.just("hare", "cheetah", "squirrel");
        
        Flux<String> firstFlux = Flux.first(slowFlux, fastFlux);
        firstFlux.subscribe{
            f -> System.out.println("firstFlux:" + f);
        }
        return firstFlux;
    }

    // 使用缓存
    @GetMapping("/bufferedFlux")
    public Flux<List<String>> bufferedFlux()
    {
        Flux<String> fruitFlux = Flux.just(
            "apple", "orange", "banana", "kiwi", "strawberry");
        
        Flux<List<String>> bufferedFlux = fruitFlux.buffer(3).log();

        return bufferedFlux;
    }

    @GetMapping("/bufferedFlatMap")
    public Flux<String> bufferedFlatMap()
    {
        Flux<String> bufferedFlux = 
        Flux.just("apple", "orange", "banana", "kiwi", "strawberry")
            .buffer(3)
            // .delayElements(Duration.ofMillis(50))
            .flatMap({x -> 
                 Flux.fromIterable(x)
                     .map({y -> y.toUpperCase()})
                     .subscribeOn(Schedulers.parallel())
                     .log()
            });

        return bufferedFlux;
    }

}
