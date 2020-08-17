/*
https://zhuanlan.zhihu.com/p/68089617

线程上下文类加载器
和类加载器不同，这个线程上下文类加载器只是一个概念，是一个成员变量。

特点

- 线程上下文类加载器是一个成员变量，可以通过相应的方法来设置和获取
- 每个线程都有一个线程类加载器，默认是 AppClassLoader
- 子线程默认使用父线程的 ClassLoader 除非子线程通过 setContextClassLoader 来设置

Thread 的源码：

    public class Thread implements Runnable {

        private ClassLoader contextClassLoader;
        
            public void setContextClassLoader(ClassLoader cl) {
            SecurityManager sm = System.getSecurityManager();
            if (sm != null) {
                sm.checkPermission(new RuntimePermission("setContextClassLoader"));
            }
            contextClassLoader = cl;
        }
        
        @CallerSensitive
        public ClassLoader getContextClassLoader() {
            if (contextClassLoader == null) return null;
            SecurityManager sm = System.getSecurityManager();
            if (sm != null) {
                ClassLoader.checkClassLoaderPermission(contextClassLoader, Reflection.getCallerClass());
            }
            return contextClassLoader;
        }

        public void run()
        {

        }
    }

这个 sun.reflect.CallerSensitive 注解是为了堵住漏洞用的。曾经有黑客通过构造双重反射来提升权限，原理是当时反射只检查固定深度的调用者的类，看它有没有特权，例如固定看两层的调用者（getCallerClass(2)）。

如果我的类本来没足够权限群访问某些信息，那我就可以通过双重反射去达到目的：反射相关的类是有很高权限的，而在 我->反射1->反射2 这样的调用链上，反射2检查权限时看到的是反射1的类，这就被欺骗了，导致安全漏洞。使用CallerSensitive后，getCallerClass不再用固定深度去寻找actual caller（“我”），而是把所有跟反射相关的接口方法都标注上CallerSensitive，搜索时凡看到该注解都直接跳过，这样就有效解决了前面举例的问题

*/

public class LoadContextTest {

    public static void main(String[] args) {

        Thread thread = new Thread(()->{});
        System.out.println(thread.getContextClassLoader());
        thread.setContextClassLoader(LoadContextTest.class.getClassLoader().getParent());
        System.out.println(thread.getContextClassLoader());

        Thread t2 = new Thread(()->{});
        Thread.currentThread().setContextClassLoader(LoadContextTest.class.getClassLoader().getParent());
        t2.setContextClassLoader(LoadContextTest.class.getClassLoader().getParent());
        System.out.println(t2.getContextClassLoader());
    }
}