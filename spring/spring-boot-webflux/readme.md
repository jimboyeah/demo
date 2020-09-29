

## Reactor 响应式编程
- https://potoyang.gitbook.io/spring-in-action-v5/di-10-zhang-reactor-jie-shao/10.1-li-jie-xiang-ying-shi-bian-cheng
- Spring in Action - Part 3 Reactive Spring

响应式编程是对命令式编程进行替代的一个范例。这种替代的存在是因为响应式编程解决了命令式编程的限制。通过了解这些限制，可以更好地把握响应式模式的好处。

如果和许多开发者一样，都是从**命令式编程**起步的。很自然地，现在你所写的大多数代码都是命令式的。命令式编程是非常直观的，现在的学生在他们学校的 STEM 课程中很轻松地学习它，它很强大，以至于它构成了大部分的代码，驱动着最大的企业。

这个想法很简单：你写的代码就是一行接一行的指令，按照它们的顺序一次一条地出现。一个任务被执行，程序就需要等到它执行完了，才能执行下一个任务。每一步，数据都需要完全获取到了才能被处理，因此它需要作为一个整体来处理。

这样做还行吧...直到它不得行了。当正在执行的任务被阻塞了，特别是它是一个 IO 任务，例如将数据写入到数据库或从远程服务器获取数据，那么调用该任务的线程将无法做任何事情，直到任务完成。说穿了，阻塞的线程就是一种浪费。

大多数编程语言，包括 Java，支持并发编程。在 Java 中启动另一个线程并将其发送到执行某项工作的分支上是相当容易的，而调用线程则继续执行其他工作。尽管很容易创建线程，但这些线程可能最终会阻塞自己。在管理在多线程里面的并发是很具有挑战性的。更多的线程意味着更高的复杂度。

相反，**响应式编程**是函数式和声明式的。响应式编程涉及描述通过该数据流的 pipeline 或 stream，而不是描述的一组按顺序执行的步骤。响应式流处理数据时只要数据是可用的就进行处理，而不是需要将数据作为一个整体进行提供。事实上，输入数据可以是无穷的（例如，一个地点的实时温度数据的恒定流）。

应用于一个真实世界的类比就是，将命令式编程看做一个装水的气球，响应式编程看做花园里面的水管。两者都是在炎热的夏天让你的朋友惊喜并沉浸其中的方式。但是它们的执行风格是不同的：

一个水气球一次能携带的它的有效载荷，在撞击的那一刻浸湿了它预定的目标。然而，水球的容量是有限的，如果你想用水泡更多的人（或把同一个人淋得更湿），你唯一的选择就是增加水球的数量。

一根花园水龙带将其有效载荷作为一股水流从水龙头流向喷嘴。花园水龙头接的水带的容量可能是有限的，但在打水仗的过程中水是源源不断的。只要水从水龙头进入软管，就会一直通过软管然后从喷嘴喷出。同一个花园软管是很容易扩展的，你和朋友们可以玩得更尽兴。

命令式编程就类似打水仗中的水球，本质上没有什么问题，但是拿着类似响应式编程的水管的人在可扩展性和性能方面是有优势的。

Reactive Streams 是 2013 年底由 Netflix、Lightbend 和 Pivotal（Spring 背后的公司）的工程师发起的一项计划。响应式流旨在为无阻塞异步流处理提供一个标准。

我们已经谈到了响应式编程的异步特性；它使我们能够并行执行任务以获得更大的可伸缩性。Backpressure（译者注：如何形象的描述反应式编程中的背压(Backpressure)机制？ ）是一种手段，通过对用户愿意处理的数据量设定限制，数据消费者可以避免被生产速度过快的数据淹没。

Java Streams 与 Reactive Streams 对比：

- 在 Java 流和响应式流之间有很大的相似性。首先，它们的名字中都含有 Streams。它们也都为处理数据提供函数式接口。事实上，稍后当学到容器的时候，你会看到，其实它们有很多共同操作。
- 然而，Java 流通常是同步的，同时只能处理有限数据集。它们本质上是使用函数式进行集合迭代的一种手段。
- 响应式流支持任何大小的数据集，包括无限数据集的异步处理。它们使实时处理数据成为了可能。

响应式流的规范可以通过四个接口定义来概括：

- **Publisher** 为每一个 Subscription 的 Subscriber 生产数据。
- **Subscriber** 通过调用 onSubscribe() 函数接收消息，调用 request() 去请求数据。
- **Subscription** 对象将 Publisher 调用 onSubscribe() 发出的消息传输给 Subscriber。
- **Processor** 它连接了 Subscriber 和 Publisher。

响应式流通常使用弹珠图（Marble Diagram）进行绘制。弹珠图最简单的形式就是，在最上面画出数据流经 Flux 或是 Mono 的时间线，在中间画出操作，在最下面画出 Flux 或是 Mono 结果的时间线。当数据流通过原始的 Flux 后，它通过一些操作进行处理，通过数据流处理后产生一个新的 Flux。




## Spring 5 WebFlux
- [Spring 5 WebFlux](https://www.jianshu.com/p/40a0ebe321be)
- [了解 Spring 5.0 WebFlux 应用场景](https://www.cnblogs.com/quanxiaoha/p/10773773.html)
- [Spring 5 WebFlux 性能测试](https://blog.csdn.net/get_set/article/details/79492440)
- [Spring 5 webflux](https://www.zhihu.com/question/68164187)
- https://docs.spring.io/spring/docs/5.1.7.RELEASE/spring-framework-reference/web-reactive.html#webflux
- https://potoyang.gitbook.io/spring-in-action-v5/di-10-zhang-reactor-jie-shao/10.2-reactor/10.2.1-tu-jie-xiang-ying-shi-liu

Spring 5 的一大亮点是对响应式编程的支持，基于 Reactive Streams 的 Spring WebFlux 框架，构建异步的、非堵塞的、事件驱动的服务，在伸缩性方面表现非常好。

对比 Spring MVC 更有益我们去理解 WebFlux：

- Spring MVC 构建于 Servlet API 之上，使用的是同步阻塞式 I/O 模型，就是说，每一个请求对应一个线程去处理。
- Spring WebFlux 是一个异步非阻塞式的 Web 框架，它能够充分利用多核 CPU 的硬件资源去处理大量的并发请求。

明确一点就是 WebFlux 不是 Spring MVC 的替代方案！，虽然 WebFlux 也可以被运行在 Servlet 容器上（需是 Servlet 3.1+ 以上的容器），但是 WebFlux 主要还是应用在异步非阻塞编程模型，而 Spring MVC 是同步阻塞的，如果你目前在 Spring MVC 框架中大量使用非同步方案，那么，WebFlux 才是你想要的，否则，使用 Spring MVC 才是你的首选。

异步非阻塞并不会使程序运行得更快，WebFlux 并不能使接口的响应时间缩短，它仅仅能够提升吞吐量和伸缩性。

在微服务架构中，Spring MVC 和 WebFlux 可以混合使用，比如已经提到的，对于那些 IO 密集型服务(如网关)，我们就可以使用 WebFlux 来实现。

WebFlux 模块由三个新组件构成：

- Router Functions: 对标 @Controller，@RequestMapping 等标准的 Spring MVC 注解，提供一套函数式风格的 API，用于创建 Router，Handler 和 Filter。
- WebFlux: 核心组件，协调上下游各个组件提供响应式编程支持。
- Reactive Streams: 一种支持背压 Backpressure 的异步数据流处理标准，主流实现有 RxJava 和 Reactor，Spring WebFlux 默认集成的是 Reactor。

WebFlux 模块需要运行在实现了 Servlet 3.1+ 规范的容器之上，Servlet 3.1 规范中新增了对异步处理的支持，在新的 Servlet 规范中，Servlet 线程不需要一直阻塞等待直到业务处理完成，也就是说，Servlet 线程将不需要等待业务处理完成再进行结果输出，然后再结束 Servlet 线程，而是在接到新的请求之后，Servlet 线程可以将这个请求委托给另外一个线程（业务线程）来完成，Servlet 线程将委托完成之后变返回到容器中去接收新的请求，Servlet 3.1 规范特别适用于那种业务处理非常耗时的场景之下，可以减少服务器资源的占用，并且提高并发处理速度，而对于那些能快速响应的场景收益并不大。

Reactor 类似于 RxJava 2.0，同属于第四代响应式框架，下面主要介绍一下 Reactor 中的 Flux、Mono 两个关键概念。

如果去查看源代码的话，可以发现，Flux 和 Mono 都实现了 Reactor 的 Publisher 接口，从这里可以看出，Flux 和 Mono 属于事件发布者，类似与生产者，对消费者提供订阅接口，当有事件发生的时候，Flux 或者 Mono 会通过回调消费者的相应的方法来通知消费者相应的事件，这也就是所谓的相应式编程模型，生产者和消费者减耦，它们之间通过实现一个共同的方法组来实现相互联系（生产者通知事件是通过回调消费者的方法，而实现通知很多时候是通过代理）。

Flux 可以 emit 很多 item，并且这些 item 可以经过若干 Operators 然后才被 subscrib，下面是使用 Flux 的一个小例子：

    Flux.fromIterable(getSomeLongList())
        .mergeWith(Flux.interval(100))
        .doOnNext(serviceA::someObserver)
        .map(d -> d * 2)
        .take(3)
        .onErrorResumeWith(errorHandler::fallback)
        .doAfterTerminate(serviceM::incrementTerminate)
        .subscribe(System.out::println);


Mono 只能 emit 最多只能一个 item，下面是使用 Mono 的一个小例子：

    Mono.fromCallable(System::currentTimeMillis)
        .flatMap(time -> Mono.first(serviceA.findRecent(time), serviceB.findRecent(time)))
        .timeout(Duration.ofSeconds(3), errorHandler::fallback)
        .doOnSuccess(r -> serviceM.incrementSuccess())
        .subscribe(System.out::println);

简单体验 WebFlux

Spring 官方为了让我们更加快速/平滑到 WebFlux，之前 SpringMVC 那套都是支持的。也就是说：我们可以像使用 SpringMVC 一样使用着 WebFlux。

在 Spring Boot 项目中添加依赖：

    <!-- https://mvnrepository.com/artifact/org.projectreactor/reactor-core -->
    <dependency>
        <groupId>org.projectreactor</groupId>
        <artifactId>reactor-core</artifactId>
        <version>1.1.6.RELEASE</version>
    </dependency>

    // https://mvnrepository.com/artifact/org.projectreactor/reactor-core
    @Grapes(
        @Grab(group='org.projectreactor', module='reactor-core', version='1.1.6.RELEASE')
    )

Reactor 还提供了测试支持，把以下这个依赖添加到项目构建中：

    <dependency>
        <groupId>io.projectreactor</groupId>
        <artifactId>reactor-test</artifactId>
        <scope>test</scope>
    </dependency>

我假定你要向 Spring Boot 项目中添加这些依赖，它可以为你处理的依赖管理，所以没有必要指定依赖的 version 元素。但是如果你想在非 Spring Boot 项目中使用 Reactor，那么你需要在构建中设置 Reactor 的 BOM（物料清单）。下面的依赖管理条目增加了 Reactor 的 Bismuth-RELEASE 到构建中：

    <dependencyManagement>
        <dependencies>
            <dependency>
                <groupId>io.projectreactor</groupId>
                <artifactId>reactor-bom</artifactId>
                <version>Bismuth-RELEASE</version>
                <type>pom</type>
                <scope>import</scope>
            </dependency>
        </dependencies>
    </dependencyManagement>

现在，Reactor 在你的项目构建中了，可以使用 Mono 和 Flux 开始创建响应式管道了。

WebFlux 使用的响应式流并不是用 JDK9 平台，而是一个叫做 Reactor 响应式流库。所以，入门 WebFlux 其实更多是了解怎么使用 Reactor 的 API。

Reactor 是一个响应式流，它也有对应的发布者 Publisher，Reactor 的发布者用两个类来表示：

- Mono(返回0或1个元素)
- Flux(返回0-n个元素)

而订阅者则是 Spring 框架去完成，下面我们来看一个简单的例子：

    // 阻塞5秒钟
    private String createStr() {
        try {
            TimeUnit.SECONDS.sleep(5);
        } catch (InterruptedException e) {
        }
        return "some string";
    }

    // 普通的SpringMVC方法
    @GetMapping("/1")
    private String get1() {
        log.info("get1 start");
        String result = createStr();
        log.info("get1 end.");
        return result;
    }

    // WebFlux(返回的是Mono)
    @GetMapping("/2")
    private Mono<String> get2() {
        log.info("get2 start");
        Mono<String> result = Mono.fromSupplier(() -> createStr());
        log.info("get2 end.");
        return result;
    }

首先，值得说明的是，我们构建 WebFlux 环境启动时，应用服务器默认是 Netty。我们分别来访问一下 SpringMVC 的接口和 WebFlux 的接口，看一下有什么区别。

    get1 start 08/14/20 15:56:19.298
    get1 end. 08/14/20 15:56:24.300

    get2 start 08/14/20 15:57:50.242
    get2 end. 08/14/20 15:57:50.243

从调用者(浏览器)的角度而言，是感知不到有什么变化的，因为都是得等待 5s 才返回数据。但是，从服务端的日志我们可以看出，WebFlux 是直接返回 Mono 对象的，而不是像 SpringMVC 一直同步阻塞 5s，线程才返回。

