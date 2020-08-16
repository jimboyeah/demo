/*
file:///C:/download/programming/jdk-14.0.2_doc-all/api/java.base/java/util/List.html#method.summary
*/
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
 
public class ForEachList
{
    public static void main(String[] args)
    {

        System.out.println("---------For-Each-------------");
        
        int[][] arr2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}} ;
        for(int[] row : arr2)
        {
            System.out.print("row: ");
            for(int element : row)
            {
                System.out.print(element+" ");
            }
            System.out.println();
        }
        
        List<String> list = new ArrayList<String>();
        
        list.add("Linux");
        list.add("Git");
        list.add("Github");
        list.add("Github");
        list.add("Google");
        list.sort( (it, that) -> -it.compareTo(that) );
        // list.sort( (it, that) -> {return -it.compareTo(that); } );
        
        System.out.println("---------- for -----------");
        for(int i = 0; i < list.size(); i++)
        {
            System.out.println(list.get(i));
        }
        
        System.out.println("---------- iterator -----------");
        for(Iterator<String> iter = list.iterator(); iter.hasNext();)
        {
            System.out.println(iter.next());
        }
        
        System.out.println("---------- For-Each -----------");
        for(String str: list)
        {
            System.out.println(str);
        }
    }
}