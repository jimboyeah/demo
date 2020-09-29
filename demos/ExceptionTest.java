
public class ExceptionTest
{
    public static void main(String[] args) throws Exception 
    {
        int i = 9;
        try{
            System.out.println("A");
            throw new Exception("after A");
        }catch(Exception ex){
            System.out.println("B");
            throw new Exception("after B");
        }finally{
            System.out.println("C");
        }
        // System.out.println("D"); // 错误: 无法访问的语句，因为 try throw ... 
    }
}
/*
A
B
C
Exception in thread "main" java.lang.Exception: after B
    at ExceptionTest.main(ExceptionTest.java:12)
*/
