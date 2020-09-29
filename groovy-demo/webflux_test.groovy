import static org.mockito.Mockito.*;
import java.util.ArrayList;
import java.util.List;
import org.junit.Test;
import org.mockito.Mockito;
import org.springframework.http.MediaType;
import org.springframework.test.web.reactive.server.WebTestClient;
import reactor.core.publisher.Flux;
import tacos.Ingredient.Type;
import tacos.data.TacoRepository;
import tacos.web.api.DesignTacoController;
​
public class DesignTacoControllerTest {
    @Test
    public void shouldReturnRecentTacos() {
        Taco[] tacos = {
            testTaco(1L), testTaco(2L), testTaco(3L), testTaco(4L),
            testTaco(5L), testTaco(6L), testTaco(7L), testTaco(8L),
            testTaco(9L), testTaco(10L), testTaco(11L), testTaco(12L),
            testTaco(13L), testTaco(14L), testTaco(15L), testTaco(16L)
        };
        
        Flux<Taco> tacoFlux = Flux.just(tacos);
        TacoRepository tacoRepo = Mockito.mock(TacoRepository.class);
        
        when(tacoRepo.findAll()).thenReturn(tacoFlux);
        WebTestClient testClient = WebTestClient.bindToController(
            new DesignTacoController(tacoRepo)).build();
        
        testClient.get().uri("/design/recent")
            .exchange().expectStatus().isOk().expectBody()
            .jsonPath('$').isArray()
            .jsonPath('$').isNotEmpty()
            .jsonPath('$[0].id').isEqualTo(tacos[0].getId().toString())
            .jsonPath('$[0].name').isEqualTo("Taco 1")
            .jsonPath('$[1].id').isEqualTo(tacos[1].getId().toString())
            .jsonPath('$[1].name').isEqualTo("Taco 2")
            .jsonPath('$[11].id').isEqualTo(tacos[11].getId().toString())
            ...
            .jsonPath('$[11].name').isEqualTo("Taco 12")
            .jsonPath('$[12]').doesNotExist()
            .jsonPath('$[12]').doesNotExist();
    }
    
    ...

    @Test
    public void shouldSaveATaco() {
        TacoRepository tacoRepo = Mockito.mock(TacoRepository.class);
        Mono<Taco> unsavedTacoMono = Mono.just(testTaco(null));
        Taco savedTaco = testTaco(null);
        savedTaco.setId(1L);
        Mono<Taco> savedTacoMono = Mono.just(savedTaco);
        when(tacoRepo.save(any())).thenReturn(savedTacoMono);
        WebTestClient testClient = WebTestClient.bindToController(
            new DesignTacoController(tacoRepo)).build();
        
        testClient.post()
            .uri("/design")
            .contentType(MediaType.APPLICATION_JSON)
            .body(unsavedTacoMono, Taco.class)
            .exchange()
            .expectStatus().isCreated()
            .expectBody(Taco.class)
            .isEqualTo(savedTaco);
    }
}
/*
WebTestClient 可以做的不仅仅是针对 Controller 的 GET 请求进行测试。
它还可以用于测试任何类型的 HTTP 方法，包括 GET、POST、PUT、PATCH、DELETE 和 HEAD 请求。

表 11.1 WebTestClient 针对 Spring WebFlux 控制器测试任何类型的请求

| HTTP 方法 | WebTestClient 方法 |
|-----------|--------------------|
| GET       | .get()             |
| POST      | .post()            |
| PUT       | .put()             |
| PATCH     | .patch()           |
| DELETE    | .delete()          |
| HEAD      | .head()            |

到目前为止，编写的测试依赖于 Spring WebFlux 框架的模拟实现，因此不需要真正的服务器。但可能需要在 Netty 或 Tomcat 等服务器的上下文中测试 WebFlux Controller，并且可能需要使用 repository 或其他依赖项。也就是说，可能需要编写一个集成测试。

要编写 WebTestClient 集成测试，首先使用 @RunWith 和 @SpringBootTest 对测试类进行注解，就像其他任何 Spring Boot 集成测试一样：

    @RunWith(SpringRunner.class)
    @SpringBootTest(webEnvironment=WebEnvironment.RANDOM_PORT)
    public class DesignTacoControllerWebTest {
        @Autowired
        private WebTestClient testClient;
    }

通过将 webEnvironment 属性设置为 webEnvironment.RANDOM_PORT，将要求 Spring 启动正在运行的服务器来监听随机选择的端口。

WebTestClient 还将自动连接到测试类中。这不仅意味着将不再需要在测试方法中创建一个 URL，而且在发出请求时也不需要指定完整的 URL。这是因为 WebTestClient 将被装配成知道测试服务器在哪个端口上运行。现在可以将 shouldReturnRecentTacos() 重写为使用自动连线 WebTestClient 的集成测试：

    @Test
    public void shouldReturnRecentTacos() throws IOException {
        testClient.get().uri("/design/recent")
            .accept(MediaType.APPLICATION_JSON).exchange()
            .expectStatus().isOk()
            .expectBody()
            .jsonPath("$[?(@.id == 'TACO1')].name").isEqualTo("Carnivore")
            .jsonPath("$[?(@.id == 'TACO2')].name").isEqualTo("Bovine Bounty")
            .jsonPath("$[?(@.id == 'TACO3')].name").isEqualTo("Veg-Out");
    }

毫无疑问，你已经注意到这个新版本的 shouldReturnRecentTacos() 的代码要少得多。因为将使用自动注入的实例，因此不再需要创建 WebTestClient。而且没有必要模拟 TacoRepository，因为 Spring 将创建 DesignTacoController 的一个实例，并为它注入一个真正的 TacoRepository。在这个新版本的测试方法中，使用 JSONPath 表达式来验证从数据库提供的值。

在测试过程中，当需要使用 WebFlux Controller 公开的 API 时，WebTestClient 非常有用。但是，当应用程序本身使用其他 API 时呢？让我们把注意力转向 Spring 的响应式 web 的客户端，看看 WebClient 是如何提供 REST 客户端来处理诸如 Mono 和 Flux 之类的响应式类型的。

*/