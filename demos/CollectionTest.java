/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/Collection.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/ArrayList.html

Collection 接口

是 List、Set 和 Queue 接口的父接口，通常情况下不被直接使用。Collection 接口定义了一些通用的方法，通过这些方法可以实现对集合的基本操作。定义的方法既可用于操作 Set 集合，也可用于操作 List 和 Queue 集合。


*/

import java.util.*;

public class CollectionTest {
    public static void main(String[] args)
    {
        ArrayList<String> list = new ArrayList<>();
        System.out.printf("%s capacity %d \n", list.getClass().getSimpleName(), list.size());

        list.add("1st");
        list.add("2nd");
        list.add("3rd");
        list.addAll(list); // duplicate
        System.out.printf("%s capacity changed to %d \n", list.getClass().getSimpleName(), list.size());

        System.out.println("list items:");
        Iterator it = list.iterator();
        Boolean arrow = false;
        while (it.hasNext())
        {
            System.out.print( (arrow? " -> ":"") + it.next());
            arrow = true;
        }
        System.out.println();

        System.out.println("foreach list:");
        arrow = false;
        for (String str:list)
        {
            System.out.print( (arrow? " -> ":"") + str);
            arrow = true;
        }
        System.out.println();
        list.clear();

        // boolean removeAll(Collection c)      补集，剔除 c 集合中存在的元素
        // boolean retainAll(Collection c)      差集，剔除 c 集合中不存在的元素
        // boolean containsAll(Collection c)    判断 c 是否是子集
    }
}
