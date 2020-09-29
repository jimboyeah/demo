/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/HashMap.html#method.summary
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/concurrent/ConcurrentHashMap.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/Hashtable.html
ConcurrentModificationException详解 https://www.jianshu.com/p/c5b52927a61a
Hashtable 的实现原理 https://wiki.jikexueyuan.com/project/java-collection/hashtable.html

Map 和 Set 是两类不同的数据结构，HashMap 储存键值对，HashSet 仅仅存储对象的集合且无重复，但是 HashSet 基于 Map 实现。

HashMap、Hashtable 几乎等价，两者都实现了 Map 接口，几点差别：

- HashMap 非 synchronized，即非线程安全，可以接受 null 键或值；
- Hashtable 是 synchronized，线程安全的；
- Hashtable 可以直接使用对象的 hashCode；

对于 HashMap 同步机制可通过 Collections 的一个静态方法得到解决，或者使用并发包中实现的并发版 ConcurrentHashMap：

    public static Map Collections.synchronizedMap(Map m)

    java.util.concurrent.ConcurrentHashMap<K,​V>


TreeMap 对象会对元素进行排列次序。

HashMap 容器不保证元素顺序，根据需要该容器可能会对元素重新哈希，元素的顺序也会被重新打散。因此不同时间迭代同一个 HashMap 的顺序可能会不同。 

HashMap 采用的是冲突链表方式，根据对冲突的处理方式不同，哈希表有两种实现方式，一种开放地址方式（Open addressing），另一种是冲突链表方式（Separate chaining with linked lists）。

Hashtable 和 ConcurrentHashMap 相比，同步性能不及，但安全性更好，。ConcurrentHashMap 仅仅根据同步级别对 map 的一部分进行上锁，所以或以获取更佳的性能。

Hashtable 线程安全很好理解，因为它每个方法中都加入了 Synchronize 同步锁。

*/

import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.*;
import java.util.stream.*;
import java.util.concurrent.*;

public class HashTableTest
{
    private static Map<String, String> map = new HashMap<>();
    private static Map<String, String> table = new Hashtable<>();

    public static void main(String[] args) throws Exception
    {
        log("--------------------HashMap is NTS - None-Thread Safe------------------");
        // 使用 Lambda 来创建 9 个线程
        IntStream.range(1, 10).forEach(i -> {
            Thread t1 = new Thread(() -> {
                shuffleFill(map, i);
                log( getThreadName() + " -> map size: " + map.keySet().size());
                log( map.keySet().toString() );
                }, "HashMap random test #" + i);
            t1.start();
        });

        TimeUnit.MILLISECONDS.sleep(1000);

        log("----------------------HashTable is TS - thread safe--------------------");
        // 使用 Lambda 来创建 9 个线程
        IntStream.range(1, 10).forEach(i -> {
            Thread t1 = new Thread(() -> {
                shuffleFill(table, i);
                log( getThreadName() + " -> table size: " + table.keySet().size());
                log( table.keySet().toString() );
                }, "HashTable random test #" + i);
            t1.start();
        });
    }

    static public String getThreadName()
    {
        return Thread.currentThread().getName();
    }

    static public void log(String msg)
    {
        System.out.println(msg);
    }

    public static void shuffleFill(Map<String, String> map, int index)
    {
        Map<String, String> items = new HashMap<>();
        items.put("Berry", "浆果");
        items.put("Berry", "浆果");
        items.put("Date", "枣子");
        items.put("Sorosis", "桑果");
        items.put("Pitaya", "火龙果");
        items.put("Rambutan", "红毛丹");
        items.put("Guava", "石榴");
        items.put("Pineapple", "凤梨");
        items.put("Sapodilla", "人参果");
        items.put("Pomelo", "柚子");
        items.put("Tangor", "广柑");
        items.put("Pistachio", "开心果");
        items.put("Raspberry", "覆盆子");
        items.put("Sugarcane", "甘蔗");
        items.put("Persimmon", "柿子");
        items.put("Lichee", "荔枝");
        items.put("Strawberry", "草莓");
        items.put("Loquat", "枇杷");
        items.put("Apple", "苹果");
        items.put("Pomegranate", "石榴");
        items.put("Haw", "山楂");
        items.put("Longan", "龙眼");
        items.put("Carambola", "杨桃");
        items.put("Quarenden", "大红苹果");
        items.put("Filbert", "榛子");

        if (index>items.size() - 1) index = items.size() - 1;
        String key = items.keySet().toArray()[index].toString();
        map.put(key, items.get(key));
        // log("fill with " + key);
        // System.out.println(String.join(",", items.keySet()));
    }
}