import java.lang.*;

public class GcCounterTest 
{
    private Object instance;
    
    // 占据 20M 内存
    public GcCounterTest() {
        byte[] m = new byte[20 * 1024 *1024];
    }

    public void finalize(){
        System.out.println("Destructor...");
    }
    
    public static void main(String[] args) {
        GcCounterTest c1 = new GcCounterTest();
        GcCounterTest c2 = new GcCounterTest();
        
        c1.instance = c2;
        c2.instance = c1;
        // 断掉引用
        c1 = null;
        c2 = null;
        
        // 假设在这行发生 GC，对象内存是否能被回收？
        System.gc();
    }
}