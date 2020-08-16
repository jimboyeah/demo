/*
NoClassDefFoundError 错误是因为在运行时类加载器在 classpath 下找不到需要加载的类，
所以我们需要把对应的类加载到 classpath 中，或者检查为什么类在 classpath 中是不可用的，

这个发生可能的原因如下：

- 对应的 Class 在 Java 的 classpath 中不可用
- 你可能用 jar 命令运行你的程序，但类并没有在 jar 文件的 manifest 文件中的 classpath 属性中定义
- 可能程序的启动脚本覆盖了原来的 classpath 环境变量
- 因为 NoClassDefFoundError是 java.lang.LinkageError 的一个子类，所以可能由于程序依赖的原生的类库不可用而导致
- 检查日志文件中是否有 java.lang.ExceptionInInitializerError 这样的错误，NoClassDefFoundError 有可能是由于静态初始化失败导致的
- 如果你工作在J2EE的环境，有多个不同的类加载器，也可能导致 NoClassDefFoundErro

ClassNotFoundException 找不到指定的 class。
常见的场景就是：

- 调用 class 的 forName 方法时
- ClassLoader 中的 findSystemClass() 方法找不到指定的类
- ClassLoader 中的 loadClass() 方法找不到指定的类
- ClassLoader 中的 resolveClass() 方法找不到指定的类


*/
import java.lang.reflect.*;

public class MonitorHotSwap implements Runnable {
    private String className = "Hot";
    private Class hotClazz = null;
    private HotSwapURLClassLoader hotSwapCL = null;
 
    @Override
    public void run() {
        try {
            while (true) {
                initLoad();
                Thread.sleep(1000);
                if(hotClazz == null) continue;
                Object hot = hotClazz.newInstance();
                Method m = hotClazz.getMethod("hot");
                m.invoke(hot);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 如果 Hot 类被修改了，那么会重新加载，hotClass也会返回新的
    public void initLoad() throws Exception {
        hotSwapCL = HotSwapURLClassLoader.getClassLoader();
        try{
            hotClazz = hotSwapCL.loadClass(className);
        }catch(Exception ex){ // NoClassDefFoundError
            ex.printStackTrace();
            // System.out.println("Ex: " + ex.getMessage());
        }
    }
}