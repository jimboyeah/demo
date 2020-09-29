// spring test app.groovy TestApp.groovy
import org.junit.Test

import org.junit.*;
import reactor.test.*;
import reactor.core.publisher.*;

import java.util.concurrent.*;
import java.util.*;
import java.time.*;

@Grab("reactor-core")
@Grab("reactor-test")
@Grab('junit')

@Grab('junit')

class TestApp {
   @Test
   void welcomeTest() {
      assertEquals("Hello ABC", new ThisWillActuallyRun().home())
   }

    @Test
    public void createAFlux_just() {
        Flux<String> fruitFlux = Flux
            .just("Apple", "Orange", "Grape", "Banana", "Strawberry");
        fruitFlux.subscribe{
            f -> System.out.println("Here's some fruit: " + f);
        }
    }

    @Test
    public void mergeFluxes() {
        Flux<String> characterFlux = Flux
            .just("Garfield", "Kojak", "Barbossa")
            .delayElements(Duration.ofMillis(500));
        
        Flux<String> foodFlux = Flux
            .just("Lasagna", "Lollipops", "Apples")
            .delaySubscription(Duration.ofMillis(250))
            .delayElements(Duration.ofMillis(500));
        
        Flux<String> mergedFlux = characterFlux.mergeWith(foodFlux);
        
        StepVerifier.create(mergedFlux)
            .expectNext("Garfield")
            .expectNext("Lasagna")
            .expectNext("Kojak")
            .expectNext("Lollipops")
            .expectNext("Barbossa")
            .expectNext("Apples")
            .verifyComplete();
    }
}