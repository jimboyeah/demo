// package com.example.servingwebcontent;


// ==========================================================
//  @RestController RESTfuls API
// ==========================================================

@Grab(group='com.fasterxml.jackson.core', module='jackson-annotations', version='2.9.9')
import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonIgnore;

public class Book
{
    public Integer id;
    public String name;
    public String author;

    @JsonFormat(pattern = "yyyy-MM-dd")
    public Date date = new Date();

    public Book()
    {
        // ...
    }
    public Book(Integer id, String name, String author)
    { 
        this.id = id;
        this.name = name;
        this.author = author;
        System.out.println("[X] Book: " + this);
    }
    // Groovy auto make utils getter/setter method for public member 
    // public Integer getId(){ return this.id; }
    // public void setId(Integer value){ this.id = value; }
    // public String getName(){ return this.name; }
    // public void setName(String value){ this.name = value; }
    // public String getAuthor(){ return this.author; }
    // public void setAuthor(String value){ this.author = value; }
    public String toString() { return "<BOOK>"; }
    public Date getDate(){ 
        System.out.println("[X] books getDate: " + date);
        return date; }
    public void setDate(Date value){ this.date = value; }
}

@RestController
public class HelloBookController 
{
    List<Book> books;

    public HelloBookController()
    {
        books = new ArrayList<>();
        Book b1 = new Book(1, "Spring in Action 5th", "Craig Walls");
        Book b2 = new Book(2, "Spring Boot in Action 1st", "Craig Walls");
        books.add(b1);
        books.add(b2);
    }

    // curl localhost:8080/rest
    @RequestMapping(path = "/rest", method = RequestMethod.GET)
    public String home() {
        "This is Spring Boot application"
    }

    // curl localhost:8080/books.json
    @RequestMapping(path = "/books.json", method = RequestMethod.GET)
    public List<Book> json(@RequestParam(name="id", defaultValue="-1") Integer id) {
        System.out.println("[X] books.json: " + id);
        if (id > -1){
            List<Book> sl = new ArrayList<Book>();
            sl.add(books[id]);
            return sl;
        }
        return books;
    }

    @GetMapping("/books")
    // public ModelAndView test(ModelAndView mv)
    public ModelAndView test()
    {
        System.out.println("[X] books test: " + books);
        ModelAndView mv = new ModelAndView();
        mv.addObject("books", books);
        mv.setViewName("book");
        return mv;
    }
}

// ==========================================================
//  @Controller Thymaleaf freemarker
// ==========================================================
@Grab("spring-boot-starter-web")
@Grab('spring-boot-starter-actuator')
// @Grab("spring-boot-starter-security")
@Grab('spring-boot-starter-freemarker')
@Grab('spring-boot-starter-thymeleaf')

import org.springframework.context.annotation.*;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.view.InternalResourceViewResolver;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.lang.*;

import freemarker.template.Configuration;

@Controller
// @EnableWebMvc
// @EnableWebSecurity
class ThisWillActuallyRun 
{
    // curl localhost:8080/sayhello
    @RequestMapping(value = "/sayhello", method = RequestMethod.GET)
    @ResponseBody
    String sayhello(@RequestParam(value="name", defaultValue="ABC") String name) 
    {
        System.out.println("[X] sayhello receive name: " + name);
        return String.format("中汉 Hello %s!", name);
    }

    // curl localhost:8080/hello.ftl
    @RequestMapping(value = "/hello.ftl", method = RequestMethod.GET)
    ModelAndView hello(@RequestParam(value="name", defaultValue="FreeMarker") String name) 
    {
        System.out.println("[X] sayhello receive name: " + name);
        ModelAndView mv = new ModelAndView();
        mv.setViewName("hello");
        mv.addObject("name", name);
        return mv;
    }

    // curl localhost:8080/greet?name=XY
    @RequestMapping("/greet")
    String home(Model model, @RequestParam String name) 
    {
        System.out.println("[X] home receive name: " + name);
        model.addAttribute("name", name)
        return "greeting"
    }

    // curl localhost:8080/hi?name=XY
    @GetMapping("/greeting")
    public String greeting(@RequestParam(name="name", required=false, defaultValue="World") String name, Model model)
    {
        model.addAttribute("name", name);
        System.out.println("[X] greeting receive name: " + name);
        // return "forward:index.html";
        return "greeting";
    }
}

// ==========================================================
//  @Configuration
// ==========================================================
@Configuration
public class ControllerConfig implements WebMvcConfigurer 
{
    @Override
    public void addViewControllers(ViewControllerRegistry registry) 
    {
        System.out.println("[X] addViewControllers: /index.view " + registry);
        registry.addViewController("/index.view").setViewName("index");
    }

    @Bean
    public InternalResourceViewResolver viewResolver() 
    {
        InternalResourceViewResolver viewResolver = new InternalResourceViewResolver();
        System.out.println("[X] viewResolver: " + InternalResourceViewResolver);
        // viewResolver.setPrefix("/WEB-INF/jsp/");
        // viewResolver.setSuffix(".jsp");
        // viewResolver.setPrefix("/templates/");
        // viewResolver.setSuffix(".html");
        return viewResolver;
    }
}

// @SpringBootApplication
// public class ExitCodeApplication 
// {
//     @Bean
//     public ExitCodeGenerator exitCodeGenerator() 
//     {
//         return {42};
//         // return () -> 42;
//     }

//     public static void main(String[] args) 
//     {
//         System.exit(SpringApplication.exit(SpringApplication.run(ExitCodeApplication.class, args)));
//     }
// }


// ==========================================================
//  Uploader
// ==========================================================
// import org.springframework.ui.Model;
// import org.springframework.web.bind.annotation.GetMapping;
// import org.springframework.web.bind.annotation.PostMapping;
// import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MaxUploadSizeExceededException;
import org.apache.tomcat.util.http.fileupload.impl.FileSizeLimitExceededException;
import org.springframework.web.multipart.MultipartFile;
 
// import javax.servlet.http.HttpServletRequest;
// import java.io.File;
// import java.io.IOException;
import java.text.SimpleDateFormat;
// import java.util.Date;
// import java.util.UUID;
 
@RestController
@CrossOrigin
public class FileUploadController {
 
    SimpleDateFormat dtFormat = new SimpleDateFormat("yyyy/MM/dd/");
 
    @GetMapping("/upload")
    public ModelAndView upload(HttpServletRequest req, ModelAndView mv) 
    {
        mv.addObject("name", "Uploader");
        mv.setViewName("upload");
        return mv;
    }

    @PostMapping("/upload")
    public String upload(MultipartFile uploadFile, HttpServletRequest req) 
    {
        String realPath = req.getSession().getServletContext().getRealPath("/uploadFile/");
 
        // Ex. /uploadFile/2019/06/06/32091e5f-c9e9-4506-9567-43e724f1fe37.png
        String format = dtFormat.format(new Date());
        File folder = new File(realPath + format);
        if (!folder.isDirectory()) {
            folder.mkdirs();
        }

        String oldName = uploadFile.getOriginalFilename();
        String newName = UUID.randomUUID().toString()+oldName.substring(oldName.lastIndexOf("."), oldName.length());
        System.out.println("Upload file to " + realPath + newName);
        try {
            uploadFile.transferTo(new File(folder, newName));
            String filePath = req.getScheme()+"://"+req.getServerName()+":"+req.getServerPort()+"/uploadFile/"+format+newName;
            return filePath;
        } catch (MaxUploadSizeExceededException ex) {
            System.out.println("文件大小超限 " + ex.getMessage());
        } catch (StringIndexOutOfBoundsException ex) {
            System.out.println("客户端文件缺件 " + ex.getMessage());
        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (Exception ex) {
            System.out.printf("Upload Exception %s:", ex, ex.getMessage());
        }
        return "上传失败!";
    }
}


// ==========================================================
//  @Configration @Bean @Autowired
// ==========================================================
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
 
@Configuration
public class MyConfigration 
{
    @Bean
    public String hello() 
    {
        return "Welcome to Spring...";
    }
}

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
 
@RestController
public class HelloAutowiredController 
{
    @Autowired
    String hello;
 
    // curl localhost:8080/autowired
    @GetMapping("/autowired")
    public String autowired() {
        System.out.println("[X] @Autowired hello: " + hello);
        return hello;
    }
}


// ==========================================================
// Spring CommandLineRunner / ApplicationRunner
// ==========================================================
@Component
// @ConfigurationProperties(prefix = "spring.banner.image")
// @PropertySource("classpath:book.properties")
public class MyBean implements CommandLineRunner 
{
    // Using @Value Spring Annotation with Groovy avoid GString
    @Value('${spring.banner.image.location}')
    // @Value("${location}") // for java
    String banner

    public void run(String... args) 
    {
        System.out.println("[X] Spring banner: " + banner);
    }
}

// ==========================================================
// Spring HandlerInterceptor
// ==========================================================
@Component
public class TestInterceptor implements HandlerInterceptor 
{
    public TestInterceptor()
    {
        System.out.println("[X] TestInterceptor...");
    }

    @Override
    public void afterCompletion(HttpServletRequest request,
            HttpServletResponse response, Object handler, Exception ex)
            throws Exception 
    {
        System.out.println("[X] HandlerInterceptor -> afterCompletion after view render...");
    }

    @Override
    public void postHandle(HttpServletRequest request,
            HttpServletResponse response, Object handler,
            ModelAndView modelAndView) throws Exception 
    {
        System.out.println("[X] HandlerInterceptor -> postHandle after view resolve...");
    }

    @Override
    public boolean preHandle(HttpServletRequest request,
            HttpServletResponse response, Object handler) throws Exception 
    {
        System.out.println("[X] HandlerInterceptor -> preHandle before view resolve...");
        return true;
    }
}

@Configuration
public class WebMvcConfig implements WebMvcConfigurer {
    @Override
    public void addInterceptors(InterceptorRegistry registry) 
    {
        registry
            .addInterceptor(new TestInterceptor())
            .addPathPatterns("/**") // 配置拦截路径（所有路径都拦截）
            .excludePathPatterns("/hello2"); // 配置排除的路径
    }
}

// ==========================================================
// Spring Events
// ==========================================================
import org.springframework.context.ApplicationEvent;
import org.springframework.context.ApplicationListener;
import org.springframework.context.event.ContextStartedEvent;
import org.springframework.context.event.ContextStoppedEvent;

@Component
public class HelloListener<ApplicationEvent> implements ApplicationListener 
{
    @Override
    void onApplicationEvent(ApplicationEvent e) 
    {
        if (e instanceof ContextStartedEvent){
            System.out.println("[X] Spring Started!");
        }else if (e instanceof ContextStoppedEvent){
            System.out.println("[X] Spring Stopped!");
        }else{
            System.out.println("[X] Spring Event:"+e.getClass().toString());
        }
    }
}
