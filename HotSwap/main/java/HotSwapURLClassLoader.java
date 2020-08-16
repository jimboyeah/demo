
import java.io.File;
import java.io.FileNotFoundException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.HashMap;
import java.util.Map;
 
/**
  * 重新加载更改过的.class文件，达到热替换的作用
  * @author banana
  */
public class HotSwapURLClassLoader extends URLClassLoader {
 
    //缓存加载class文件的最后最新修改时间
    public static Map<String,Long> cacheLastModifyTimeMap = new HashMap<String,Long>();
 
    //工程class类所在的路径
    public static String projectClassPath = "bin";
 
    //所有的测试的类都在同一个包下
    public static String packagePath = "/";
 
    private static HotSwapURLClassLoader hcl = new HotSwapURLClassLoader();
 
    public HotSwapURLClassLoader() {
        //设置 ClassLoader 加载的路径
        super(getMyURLs());
        System.out.println("new HotSwapURLClassLoader ...\n");
    }
 
    public static HotSwapURLClassLoader  getClassLoader(){
        return hcl;
    } 
 
    private static  URL[] getMyURLs(){
        URL url = null;
        try {
            url = new File(projectClassPath).toURI().toURL();
        } catch (MalformedURLException e) {
            e.printStackTrace();
        }
        return new URL[] { url };
    }
 
    /**
     * 重写loadClass，不采用双亲委托机制("java."开头的类还是会由系统默认ClassLoader加载)
     */
    @Override
    public Class<?> loadClass(String name, boolean resolve) throws ClassNotFoundException {
        Class clazz = null;
        //查看HotSwapURLClassLoader实例缓存下，是否已经加载过class
        //不同的HotSwapURLClassLoader实例是不共享缓存的
        clazz = findLoadedClass(name);
        if (clazz != null ) {
            if (resolve){
                resolveClass(clazz);
            }
            //如果class类被修改过，则重新加载
            if (isModify(name)) {
                hcl = new HotSwapURLClassLoader();
                clazz = customLoad(name, hcl);
            }
            return (clazz);
        }
 
        // 如果类的包名以 java 或者 sun 开始，则由交给系统默认加载器 AppClassLoader 加载
        if(name.startsWith("java.") || name.startsWith("sun.")){
            try {
                //得到系统默认的加载cl，即AppClassLoader
                ClassLoader system = ClassLoader.getSystemClassLoader();
                clazz = system.loadClass(name);
                if (clazz != null) {
                    if (resolve)
                        resolveClass(clazz);
                   return (clazz);
                }
            } catch (ClassNotFoundException e) {
                // Ignore
                e.printStackTrace();
            }
        }

       return customLoad(name,this);
    }

    public Class load(String name) throws Exception{
        return loadClass(name);
    }

    public Class customLoad(String name, ClassLoader cl) throws ClassNotFoundException {
        return customLoad(name, false, cl);
    }

    public Class customLoad(String name, boolean resolve, ClassLoader cl) throws ClassNotFoundException {
        // findClass() 调用的是 URLClassLoader 重载 ClassLoader 的 findClass()
        Class clazz = ((HotSwapURLClassLoader)cl).findClass(name);
        if (resolve) ((HotSwapURLClassLoader)cl).resolveClass(clazz);
        //缓存加载class文件的最后修改时间
        long lastModifyTime = getClassLastModifyTime(name);
        cacheLastModifyTimeMap.put(name, lastModifyTime);
        return clazz;
    }

    public Class<?> loadClass(String name) throws ClassNotFoundException {
        return loadClass(name,false);
    }

    @Override
    protected Class<?> findClass(String name) throws ClassNotFoundException {
        // TODO Auto-generated method stub
       System.out.println("findClass "+name);
       return super.findClass(name);
    }

    /**
     * @param name
     * @return .class文件最新的修改时间
     */
    private long getClassLastModifyTime(String name){
        String path = getClassCompletePath(name);
        File file = new File(path);
        System.out.println(file.getAbsolutePath());
        if(!file.exists()){
           throw new RuntimeException(new FileNotFoundException(name));
        }
        return file.lastModified();
    }

    private boolean isModify(String name){
       long lastmodify = getClassLastModifyTime(name);
       long previousModifyTime = cacheLastModifyTimeMap.get(name);
       if(lastmodify>previousModifyTime){
           return true;
      }
      return false;
    }
    
    private String getClassCompletePath(String name){
        String simpleName = name.substring(name.lastIndexOf(".")+1);
        // return simpleName+".class";
        return projectClassPath+packagePath+simpleName+".class";
    }    
}