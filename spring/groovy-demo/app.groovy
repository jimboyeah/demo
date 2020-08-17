package com.example.servingwebcontent;

@Controller
public class GreetingController 
{
    @GetMapping("/greeting")
    public String greeting(@RequestParam(name="name", required=false, defaultValue="World") String name, Model model) 
    {
        model.addAttribute("name", name);
        // templateResolver.setPrefix("/WEB-INF/templates/");
        templateResolver.setPrefix("/templates/");
        templateResolver.setSuffix(".html");
        return "greeting";
    }
}

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

@Component
public class MyBean implements CommandLineRunner 
{
    public void run(String... args) 
    {
        System.out.println(" Do something else ...");
    }
} 