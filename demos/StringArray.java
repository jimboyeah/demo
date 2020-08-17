/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/Arrays.html
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/lang/String.html#method.summary
*/
import java.util.*;

public class StringArray
{
    public static void main(String[]args)
    {
        String[] strArray={"1","2","3"};
        strArray[1]="a";
        Arrays.sort(strArray);
        // == 操作符总是比较内存中两个对象的引用。
        // stra.equals(strb);
        // stra.compareTo(strb);

        for(String str:strArray)
        {
            System.out.println(str);
        }
        System.out.println(String.join(",", "one", "more..."));
        System.out.println(String.join(",", strArray));


        System.out.println("");
        String str2 = new String("Pistachio.Raspberry.Sugarcane");

        System.out.println("split by .:" );
        System.out.println(String.join(" ", str2.split("\\.")));
 
        System.out.println("");
        System.out.println("split by R|S:" );
        for (String retval: str2.split("R|S")){
            System.out.println(retval);
        }

    }
}
