package com.demos.controller;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import java.util.Date;
import java.util.Map;

@RestController
public class HelloWorldController {

    // 从 application.yml 中读取配置，如取不到默认值为 Hello JSP
    @Value("${application.hello:Hello JSP}")
    private String hello = "Hello";

    @RequestMapping("/hello")
    public String hello() {
        return "Hello World";
    }

    // @RequestMapping("/")
    // public String index() {
    //     return "Hello Spring Boot 2.0!";
    // }

    /**
     * 响应 JSP 页面 page1
     * 页面位置按 prefix 配置的 webapp 子目录下查找 index.jsp
     */
    @RequestMapping("/page1")
    public ModelAndView page1(){
        System.out.println(hello);
        ModelAndView mav = new ModelAndView("index");
        mav.addObject("content", hello);
        return mav;
    }

    /**
     * 响应 JSP 页面 page1（可以直接使用 Model 封装内容，直接返回页面字符串）
     * 页面位置按 prefix 配置的 webapp 子目录下查找 index.jsp
     */
    @RequestMapping("/page2")
    public String page2(Model model){
        model.addAttribute("content", hello + "（第二种）");
        return "index2";
    }
}