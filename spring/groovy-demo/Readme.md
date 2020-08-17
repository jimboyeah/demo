
## Spring Boot CLI Starting
- Spring Initializr - https://start.spring.io/
- Groovy 语言快速入门 - https://www.jianshu.com/p/e8dec95c4326
- [Why is Spring Boot? --Spring Boot 四大神器](https://gtwlover.gitee.io/2017/12/02/Spring%20Boot/)
- [Spring Boot Documentation](https://docs.spring.io/spring-boot/docs/2.2.2.RELEASE/reference/htmlsingle)
- [Spring Boot CLI](https://docs.spring.io/spring-boot/docs/current/reference/html/spring-boot-cli.html)
- [Spring Boot CLI](https://www.breakyizhan.com/springboot/3454.html)
- [Spring Boot Groovy CLI](http://zetcode.com/springboot/groovycli/)
- [FreeMarker 模板语言](http://freemarker.foofun.cn/dgui_template_overallstructure.html)
- [What is Apache FreeMarker™?](https://freemarker.apache.org/)
- [Tutorial: Thymeleaf + Spring](https://www.thymeleaf.org/doc/tutorials/2.1/thymeleafspring.html)
- [Spring Boot FreeMarker tutorial](http://zetcode.com/springboot/freemarker/)
- [Introducing Spring Boot](https://docs.spring.io/spring-boot/docs/current/reference/html/getting-started.html#getting-started-installing-the-cli)

Spring 四大神器：

- 起步依赖 spring-boot-starter-xx
- 服务监控 Spring Boot Actuator
- 自动配置 Spring Boot Auto Configuration
- 命令行工具 Spring Boot CLI，借此你只需写代码就能完成完整的应用程序，无需传统项目构建。

在 pom.xml 中配置 Actuator 启用服务监控：

    <!-- tag::actuator[] -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-actuator</artifactId>
    </dependency>
    <!-- end::actuator[] -->

运行程序后，可以使用 curl 测试它暴露的以下几个访问入口：

    curl localhost:8080/errors
    curl localhost:8080/actuator
    curl localhost:8080/actuator/health
    curl localhost:8080/actuator/info


官方文档提供了基于 Groovy 实现的 Spring Boot CLI 工具是快速快速执行原型程序，您可以用它来快速构建 Spring 原型应用，并通过命令行的方式将其运行起来，或打包输出 jar。

Spring Boot Groovy 应用开发中，CLI 工具做了许多魔术操作来简化工程配置：

- 自动下载 jar 依赖；
- 自动配置 Spring 应用程序；
- 自动创建 Spring 应用程序入口；
- 默认的 import 语言；

标准的 Groovy 包含一个 @Grab 注解，它允许你声明对第三方库的依赖。这项有用的技术允许 Groovy 以类似 Maven 或 Gradle 工程相同的方式管理下载 jars 依赖，而不需要使用构建工具。

Spring Boot 进一步延伸了该技术，它会基于你的代码尝试推导你 grab 哪个库。

例如，由于 WebApplication 代码上使用了 @RestController 注解，Tomcat 和 Spring MVC 两个依赖模块将被获取 grabbed。

下面列表 grab hints 标注：

|                       items                        |             Grabs             |
|----------------------------------------------------|-------------------------------|
| JdbcTemplate,NamedParameterJdbcTemplate,DataSource | JDBC应用                      |
| @EnableJms                                         | JMS应用                       |
| @EnableCaching                                     | 缓存抽象                      |
| @Test                                              | JUnit                         |
| @EnableRabbit                                      | RabbitMQ                      |
| @EnableReactor                                     | 项目重构                      |
| extends Specification                              | Spock test                    |
| @EnableBatchProcessing                             | Spring Batch                  |
| @MessageEndpoint,@EnableIntegrationPatterns        | Spring 集成                   |
| @EnableDeviceResolver                              | Spring Mobile                 |
| @Controller,@RestController,@EnableWebMvc          | Spring MVC + 内嵌 Tomcat      |
| @EnableWebSecurity                                 | Spring Security               |
| @EnableTransactionManagement                       | Spring Transaction Management |


注 想要理解自定义是如何生效的，可以查看Spring Boot CLI源码中的CompilerAutoConfiguration子类。


首先，安装 Spring Boot CLI：

    $ wget http://repo.spring.io/release/org/springframework/boot/spring-boot-cli/1.5.7.RELEASE/spring-boot-cli-1.5.7.RELEASE-bin.zip
    $ unzip spring-boot-cli-1.5.7.RELEASE-bin.zip 
    $ cd spring-1.5.7.RELEASE/
    $ ls
    bin  INSTALL.txt  legal  lib  LICENCE.txt  shell-completion
    $ export PATH=$PATH:~/bin/spring-1.5.7.RELEASE/bin/

这里使用 FreeMarker 模板语言来快速建立一个原型工程，按以下目录结构组织：

    $ tree
    .
    ├── app.groovy
    ├── static
    │   └── index.html
    └── templates
        └── hello.ftl

例如以下 app.groovy 示范动态脚本运行的 Controller，注意 @Grab 引入依赖模块：
    
    @Controller
    @Grab('spring-boot-starter-freemarker')
    class ThisWillActuallyRun {

        @RequestMapping("/")
        String home(@RequestParam(value="name", defaultValue="ABC") String name) 
        {
            System.out.println("Name is " + name);
            return String.format("Hello %s!", name);
        }

        @RequestMapping("/greet")
        String home(Model model, @RequestParam String name) 
        {
            model.addAttribute("myname", name)
            return "hello"
        }
    }

将控制器用 **@RestController** 标注，即可以实现 RESTfuls API。

模板文件 hello.ftl 参考：

    <!DOCTYPE html>
    <html>
        <head>
            <title>Home page</title>
            <meta charset="UTF-8">
        </head>
        <body>
            <p>Hello ${myname}, today is a beautiful day!</p>
        </body>
    </html>

首页 index.html 可以省略，它只是一个 HTML 表单，用来向 greet 提交数据，使用以下 curl 命令就可以实现：

    curl -d "name=HI" -X POST http://localhost:8080/greet

可以运行 Spring Boot CLI 命令，它会安装 Groovy 解析器：

    $ spring run app.groovy
    $ spring run --watch app.groovy

可以到 Maven 的本地仓库中找到 Groovy 编译器：

    .m2\repository\org\codehaus\groovy\groovy

然后测试：

    curl http://localhost:8080
    curl http://localhost:8080?name=xyz

将 Groovy 脚本打包生成应用程序，输出为一个可执行的 jar 文件：

    $ spring jar my-app.jar *.groovy

你可以使用 -- 将命令行参数和 spring 命令参数区分开来：

    $ spring run app.groovy -- --server.port=9000

Groovy 是一种基于 Java 平台的面向对象语言，有以下特点:

- 同时支持静态和动态类型。
- 支持运算符重载。
- 本地语法列表和关联数组。
- 对正则表达式的本地支持。
- 各种标记语言，如 XML 和 HTML 原生支持。
- Groovy 对于 Java 开发人员来说很简单，因为 Java 和 Groovy 的语法非常相似。
- 您可以使用现有的 Java 库。
- Groovy 扩展了 java.lang.Object。

可以在 Maven 项目中集成 Groovy 或 freemarker 支持，按以下修改 pom.xml 的依赖配置：

    <!-- https://mvnrepository.com/artifact/org.codehaus.groovy/groovy-all -->
    <dependency>
        <groupId>org.codehaus.groovy</groupId>
        <artifactId>groovy-all</artifactId>
        <version>2.5.13</version>
        <type>pom</type>
    </dependency>

    <!-- https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-freemarker -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-freemarker</artifactId>
        <version>2.3.3.RELEASE</version>
    </dependency>


通过 CLI 来使用 start.spring.io 服务创建一个新的项目：

    $ spring init --dependencies=web,data-jpa my-project
    Using service at https://start.spring.io
    Project extracted to '/Users/developer/example/my-project'

使用 spring init --list 列表所有项目模板能力、依赖和参数设置：

    Project types (* denotes the default)
    +-----------------+------------------------------------------+-----------------------------+
    | Id              | Description                              | Tags                        |
    +-----------------+------------------------------------------+-----------------------------+
    | gradle-build    | Generate a Gradle build file.            | build:gradle,format:build   |
    | gradle-project  | Generate a Gradle based project archive. | build:gradle,format:project |
    | maven-build     | Generate a Maven pom.xml.                | build:maven,format:build    |
    | maven-project * | Generate a Maven based project archive.  | build:maven,format:project  |
    +-----------------+------------------------------------------+-----------------------------+


    Parameters
    +-------------+------------------------------------------+------------------------------+
    | Id          | Description                              | Default value                |
    +-------------+------------------------------------------+------------------------------+
    | artifactId  | project coordinates (infer archive name) | demo                         |
    | bootVersion | spring boot version                      | 2.3.3.RELEASE                |
    | description | project description                      | Demo project for Spring Boot |
    | groupId     | project coordinates                      | com.example                  |
    | javaVersion | language level                           | 11                           |
    | language    | programming language                     | java                         |
    | name        | project name (infer application name)    | demo                         |
    | packageName | root package                             | com.example.demo             |
    | packaging   | project packaging                        | jar                          |
    | type        | project type                             | maven-project                |
    | version     | project version                          | 0.0.1-SNAPSHOT               |
    +-------------+------------------------------------------+------------------------------+


使用 Maven 做项目管理工具，一些基本的操作，编译，构建，单元测试，安装，网站生成和基于 Maven 部署项目命令参考：

    mvn package        来构建项目 使用Maven清理项目
    mvn clean          来清理项目 使用Maven运行单元测试
    mvn test           来执行单元测试 将项目安装到Maven本地资源库
    mvn install        打包和部署项目到本地资源库 生成基于Maven的项目文档站点
    mvn site           来为您的项目生成信息文档站点 使用“mvn site-deploy”部署站点（WebDAV例子）
    mvn site-deploy    通过WebDAV部署自动生成的文档站点到服务器 部署基于Maven的war文件到Tomcat
    mvn tomcat:deploy  以 WAR 文件部署到 Tomcat

打包后，直接运行 **java -jar demo.jar** 就可以启动你的应用了！

或者在 Maven 工程目录下运行开始服务器：

    mvn clean package r-boot:run

总结起来，Spring Boot 的三种启动方式：

- 用 IDE 运行 Application 类的 main 方法
- 在 Spring Boot 工程目录下运行 **mvn spring-boot:run**
- 运行 **mvn install** 或打包命令生成的 jar 包

        mvn install
        cd target
        java -jar demo.jar

在 pom.xml 中配置生成 jar 或 war 包：

    <packaging>jar</packaging>  

    <packaging>war</packaging>

对比 JAR、WAR、EAR 包：

|      |              Java Archive file               |            Web Archive file            |   Enterprise Archive file   |
|------|----------------------------------------------|----------------------------------------|-----------------------------|
| 内容 | 类文件、properties、普通库、资源、辅助文件等 | Servlet、JSP、JSTL、JAR、HTML/XML资源  | 包含JAR、WAR，还包括EJB组件 |
| 部署 | application-client.xml                       | web.xml                                | application.xml             |
| 容器 | 应用服务器（application servers）            | 小型服务程序容器（servlet containers） | EJB容器（EJB containers）   |
| 级别 | 小                                           | 中                                     | 大                          |

默认服务是 8080 端口，如果端口被占用，可以修改 resources\application.properties 中设置：

    #设置端口号
    server.port=8999

当然，更先进的开发还是热加载 Live Reload 或者叫 Hot Swap 热交换，在开发服务器运行时，实时监视文件的修改，在开发工具的修改保存动作后，内容就在浏览器中更新。

在开发阶段每次修改代码都要手动去重新启动程序，热加载或热部署能简单粗暴帮我们去掉这一繁琐的动作，提高开发效率。

Spring Boot 内建提供了支持热加载的功能，这个机制是通过 spring-dev-tools 来实现的。

在 pom.xml 中添加 devtools 插件引用：

    <!--添加依赖-->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-devtools</artifactId>
        <!-- optional=true 依赖不会传递 -->
        <optional>true</optional>
    </dependency>

在 eclipse project 中添加 spring-boot-maven-plugin，idea 中不需要添加此配置。

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <!-- fork 如果没有该标志，热部署 devtools 不生效 -->
                    <fork>true</fork>
                </configuration>
            </plugin>
        </plugins>
    </build>


于热部署是监听 Class 文件的变化，它自身不会主动去编译 Java 文件，所以我们得在 Java 文件改动时，自动编译成 Class 文件，然后热部署工具创造的新的类加载器才会加载改变后的 Class 文件。

所以，如果你使用 IDEA 开发工具的话，记得要把自动编译打开。

    File --> Settings --> Compiler --> Build Project automatically

在配置文件 application.yml 设置热部署：

    spring:
      devtools:
        restart:
          #设置开启热部署
          enabled: true

