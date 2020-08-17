package com.example.servingwebcontent;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class GreetingController {

    @GetMapping("/greeting")
    public String greeting(@RequestParam(name="name", required=false, defaultValue="World") String name, Model model) {
        model.addAttribute("name", name);
        // templateResolver.setPrefix("/WEB-INF/templates/");
        templateResolver.setPrefix("/templates/");
        templateResolver.setSuffix(".html");
        return "greeting";
    }

}

@RestController
class ThisWillActuallyRun {

    @RequestMapping("/")
    String home(@RequestParam(value="name", defaultValue="ABC") String name) {
        System.out.println("Name is " + name);
        return String.format("Hello %s!", name);
    }

}

@Component
public class MyBean implements CommandLineRunner {

    public void run(String... args) {
        System.out.println(" Do something else ...");
    }

} 