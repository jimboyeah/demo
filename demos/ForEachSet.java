/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/HashSet.html#method.summary
Java集合--Set(基础) https://www.jianshu.com/p/b48c47a42916

- HashSet 基于 HashMap 实现，不允许有重复元素的集合。
- HashSet 允许有 null 值。
- HashSet 无序的，即不会记录插入的顺序，LinkedHashSet 元素插入有序，TreeSet 元素排序。
- HashSet 不是线程安全的，并发读写需要自行处理。


public interface Set<E> extends Collection<E> {

    A:添加功能
    boolean add(E e);
    boolean addAll(Collection<? extends E> c);

    B:删除功能
    boolean remove(Object o);
    boolean removeAll(Collection<?> c);
    void clear();

    C:长度功能
    int size();

    D:判断功能
    boolean isEmpty();
    boolean contains(Object o);
    boolean containsAll(Collection<?> c);
    boolean retainAll(Collection<?> c); 

    E:获取Set集合的迭代器：
    Iterator<E> iterator();

    F:把集合转换成数组
    Object[] toArray();
    <T> T[] toArray(T[] a);
    
    //判断元素是否重复，为子类提高重写方法
    boolean equals(Object o);
    int hashCode();
}

TreeSet 元素可以实现 implements Comparable<T> 以进行排序，或者在实例化 TreeSet 时指定一个比较器。

        TreeSet<Demo> treeSet = new TreeSet<Demo>(new SimpleComparator());

        public class SimpleComparator implements Comparator<Demo> {

            public int compare(Demo demo1, Demo demo2) {
                return demo1.length() - demo2.length();
            }
        }

*/

import java.util.Iterator;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.TreeSet;
import java.util.SortedSet;
 
public class ForEachSet
{
    public static void main(String[] args)
    {
        Set<String> items = new HashSet<>();
        shuffleFill(items);
        // items.sort()

        printA(items);
        printB(items);

        //  LinkedHashSet 保持元素插入元素时顺序。
        Set<String> linked = new LinkedHashSet<>();
        shuffleFill(linked);
        printB(linked);

        treeSetTest();
    }

    public static void treeSetTest()
    {
        System.out.println("\n----------TreeSet Test----------");
        TreeSet<String> treeSet = new TreeSet<String>();
        System.out.println("TreeSet capacity "+treeSet.size());
        shuffleFill(treeSet);

        // 迭代器遍历：降序
        // Iterator<String> iteratorDesc = treeSet.descendingIterator();
        printB(treeSet);
        

        // 获取指定元素前的子集
        System.out.println("treeSet.headSet() of Haw -> " + treeSet.headSet("Haw"));
        System.out.println("treeSet.headSet() of Banana -> " + treeSet.headSet("Banana"));
        // subSet() 含头不含尾
        System.out.println("subSet [Haw, Longan] -> " + treeSet.subSet("Haw", "Longan"));
        System.out.println("subSet [Banana, Haw] -> " + treeSet.subSet("Banana", "Haw"));
        // IllegalArgumentException
        // System.out.println("subSet [Haw, Banana] -> " + treeSet.subSet("Haw", "Banana"));

        // NavigableSet 接口方法
        System.out.println("TreeSet first() -> " + treeSet.first());

        boolean isEmpty = treeSet.isEmpty();
        System.out.println("treeSet.isEmpty() -> " + isEmpty);
        boolean hasBanana = treeSet.contains("Banana");
        System.out.println("treeSet contains Banana -> " + hasBanana);

        // remove() 集合中不存在的元素返回 false
        boolean removeBanana = treeSet.remove("Banana");
        System.out.println("treeSet remove Banana -> " + removeBanana);
        
       // 删除并返回第一个元素：如果set集合不存在元素，则返回null
        System.out.println("treeSet.pollFirst() -> " + treeSet.pollFirst());
        
        //删除并返回最后一个元素：如果set集合不存在元素，则返回null
        System.out.println("treeSet.pollLast() -> " + treeSet.pollLast());

        treeSet.clear();//清空集合:
    }

    public static void printA(Set<String> items)
    {
        System.out.println("\n\n------------while------------");
        System.out.printf("%s Capacity %d \n", items.getClass().getSimpleName(), items.size());

        Iterator<String> ito = items.iterator();
        while (ito.hasNext())
        {
            String it = ito.next();
            System.out.printf("%-12s", it==null? "NULL":it);
        }
        System.out.println();
    }

    public static void printB(Set<String> items)
    {
        System.out.println("\n\n------------foreach------------");
        System.out.printf("%s Capacity %d \n", items.getClass().getSimpleName(), items.size());
        for (String it:items)
        {
            System.out.printf("%-12s", it==null? "NULL":it);
        }
        System.out.println();
    }

    public static void shuffleFill(Set<String> items)
    {
        try { // Exception for TreeSet
            items.add(null); // ok
            items.add(null); // no duplicate
        } catch(Exception ex){}

        items.add("Berry");
        items.add("Date");
        items.add("Sorosis");
        items.add("Pitaya");
        items.add("Rambutan");
        items.add("Guava");
        items.add("Pineapple");
        items.add("Sapodilla");
        items.add("Pomelo");
        items.add("Tangor");
        items.add("Pistachio");
        items.add("Raspberry");
        items.add("Sugarcane");
        items.add("Persimmon");
        items.add("Lichee");
        items.add("Strawberry");
        items.add("Loquat");
        items.add("Apple");
        items.add("Pomegranate");
        items.add("Haw");
        items.add("Longan");
        items.add("Carambola");
        items.add("Quarenden");
        items.add("Filbert");
    }
}
