package com.demos.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import reactor.core.publisher.Mono;

import java.util.concurrent.*;
import java.util.*;

@RestController
public class HelloController {

    private void log(String msg)
    {
        System.out.printf("%s %2$tD %1tT.%2$tL%n", msg, new Date());
    }

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
        log("get1 start");
        String result = createStr();
        log("get1 end.");
        return result;
    }

    // WebFlux(返回的是Mono)
    @GetMapping("/2")
    private Mono<String> get2() {
        log("get2 start");
        Mono<String> result = Mono.fromSupplier(() -> createStr());
        log("get2 end.");
        return result;
    }

    // @GetMapping("/hello")
    @GetMapping({"/", "/hello"})
    // @GetMapping(value={"/", "/hello"})
    public Mono<String> hello() {
        String html = String.join("\n"
                , "<html>"
                , "     <body>"
                , "         <p>Hello, WebFlux</p>"
                , "         <a href=\"/1\">SpringMVC</a>"
                , "         <a href=\"/2\">WebFlux</a>"
                , "     </body>"
                , "</html>");

        return Mono.just(html);
    }
}
