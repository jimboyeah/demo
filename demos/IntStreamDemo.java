/*
https://docs.oracle.com/javase/8/docs/api/java/util/stream/IntStream.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/stream/IntStream.html
*/

import java.util.stream.*;
import java.util.*;

public class IntStreamDemo 
{ 
    public IntStreamDemo() 
    { 
        log("Constructor"); 
    } 

    public static void main(String[] args) 
    {
        int[] nums = { 1, 2, 3, 4, 5, 6 };
        int sum2 = IntStream.of(nums).sum();
        System.out.println("累加结果为：" + sum2);

        int sum3 = IntStream.of(nums).parallel().sum();
        System.out.println("并发求和结果为：" + sum3);


        List<String> list = new ArrayList<>();

        Stream<String> stream = list.stream();
        Stream<String> stream1 = list.parallelStream();

        IntStream stream2 = Arrays.stream(new int[]{2, 3, 5});

        IntStream intStream = IntStream.of(1, 2, 3);

        // IntStream limit = new Random().ints().limit(10);        
        System.out.println("Using Random IntStream");
        IntStream limit = new Random().ints(20, 1, 1000).limit(10);        
        limit.parallel().map(e -> { log(e+""); return e; }).min();

        //IntStream.range() and IntStream.rangeClosed() examples
        System.out.println("Using IntStream.range() & IntStream.rangeClosed()");
        IntStream.range(1, 10).forEach(i -> System.out.print(i + " "));
        System.out.println();
        IntStream.rangeClosed(1, 10).forEach(i -> System.out.print(i + " "));
    }

    static public void log(String t)
    {
        System.out.println(t); 
    } 
}