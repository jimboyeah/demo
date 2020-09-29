package com.demos;

import com.demos.RequestDispatcher;
import com.demos.Router;
import com.demos.HttpServer;

public class App 
{
    public static void main(String[] args) 
    {
        var router = new Router((ctx, req) -> {
            ctx.html("Hello, World");
        })
        .handler("/hello.json", (ctx, req) -> {
            ctx.json(new String[] { "Hello", "World" });
        })
        .handler("/hello", (ctx, req) -> {
            var res = new HashMap<String, Object>();
            res.put("req", req);
            ctx.render("playground.ftl", res);
        })
        .handler("/world", (ctx, req) -> {
            ctx.redirect("/hello");
        })
        .handler("/error", (ctx, req) -> {
            ctx.abort(500, "wtf");
        })
        .resource("/pub", "/static")
        .child("/user", () -> {
            return new Router((ctx, req) -> {
                ctx.html("Hello, World");
            })
            .handler("/hello.json", (ctx, req) -> {
                ctx.json(new String[] { "Hello", "World" });
            })
            .filter((ctx, req, before) -> {
                if (before) {
                    System.out.printf("before %s\n", req.path());
                } else {
                    System.out.printf("after %s\n", req.path());
                }
                return true;
            });
        });

        var rd = new KidsRequestDispatcher("/kids", router);
        rd.templateRoot("/tpl");
        rd.exception(500, (ctx, e) -> {
            ctx.html("what the fuck it is", 500);
        })
        .exception((ctx, e) -> {
            ctx.html("mother fucker!", e.getStatus().code());
        });

        var server = new HttpServer("localhost", 8080, 2, 16, rd);
        server.start();
        
        Runtime.getRuntime().addShutdownHook(new Thread() {

            public void run() {
                server.stop();
            }

        });
    }

}

// http://localhost:8080/kids
// http://localhost:8080/kids/hello
// http://localhost:8080/kids/hello.json
// http://localhost:8080/kids/world
// http://localhost:8080/kids/error
// http://localhost:8080/kids/pub/bootstrap.min.css
// http://localhost:8080/kids/user
// http://localhost:8080/kids/user/hello