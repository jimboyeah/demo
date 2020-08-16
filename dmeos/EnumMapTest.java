/*
https://docs.oracle.com/javase/tutorial/java/javaOO/enum.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/EnumMap.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/EnumSet.html
Java enum 详解 http://c.biancheng.net/view/1100.html

为了更好地支持枚举类型，java.util 中添加了两个新类：EnumMap 和 EnumSet。使用它们可以更高效地操作枚举类型。

EnumMap 是专门为枚举类型量身定做的 Map 实现。虽然使用其他的 Map（如 HashMap）实现也能完成枚举类型实例到值的映射，但是使用 EnumMap 会更加高效。

HashMap 只能接收同一枚举类型的实例作为键值，并且由于枚举类型实例的数量相对固定并且有限，所以 EnumMap 使用数组来存放与枚举类型对应的值，使得 EnumMap 的效率非常高。

*/

import java.util.*;

public class EnumMapTest {
    
    public static void main(String[] args) {
        DataBaseInfo();
        System.out.printf("MYSQL -> %s\n", getURL(DataBaseType.MYSQL));
        for (DataBaseType db:DataBaseType.values())
        {
            System.out.printf("%s -> %s\n", db, getURL(db));
        }

        // Set<Map.Entry<K,​V>>
        for (Map.Entry<DataBaseType, String> entry : dbUrls.entrySet()) {
            System.out.println(entry.getKey() + " --> " + entry.getValue());
        }
    }

    enum DataBaseType {
        MYSQL, ORACLE, DB2, SQLSERVER
    }

    private static EnumMap<DataBaseType, String> dbUrls = new EnumMap<DataBaseType, String>(DataBaseType.class);

    public static void DataBaseInfo() {
        dbUrls.put(DataBaseType.DB2,"jdbc:db2://localhost:5000/sample");
        dbUrls.put(DataBaseType.MYSQL,"jdbc:mysql://localhost/mydb");
        dbUrls.put(DataBaseType.ORACLE,"jdbc:oracle:thin:@localhost:1521:sample");
        dbUrls.put(DataBaseType.SQLSERVER,"jdbc:microsoft:sqlserver://sql:1433;Database=mydb");
    }

    public static String getURL(DataBaseType type) {
        return dbUrls.get(type);
    }
}

