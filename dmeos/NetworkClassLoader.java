import java.lang.reflect.*;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.net.URL;
import java.net.HttpURLConnection;

/*
 * Test: 
 * php -S localhost:8080 -t ..\..\dmeos
 */
class NetworkClassLoader extends ClassLoader {

    private String rootUrl;

    public static void main(String argv[]) throws ClassNotFoundException, InstantiationException, 
    IllegalAccessException, NoSuchMethodException, InvocationTargetException
    {
        NetworkClassLoader ncl = new NetworkClassLoader("http://localhost:8080/");  
        String basicClassName = "Gum";
        Class<?> clz = ncl.loadClass(basicClassName);

        Constructor cons = clz.getConstructor(int.class);
        cons.setAccessible(true);
        System.out.printf("cons. %s \n", cons);
        Object oo = cons.newInstance(0);

        System.out.println(oo);
    }

    public NetworkClassLoader(String rootUrl) {
        this.rootUrl = rootUrl;
    }

    @Override
    protected Class<?> findClass(String name) throws ClassNotFoundException {
        byte[] classData = getClassData(name);
        if (classData == null) {
            throw new ClassNotFoundException();
        } else {
            return defineClass(name, classData, 0, classData.length);
        }
    }

    private byte[] getClassData(String className) {
        String path = rootUrl + className.replace('.', '/') + ".class";
        System.out.printf("URL: %s \n", path);
        try {
            URL url = new URL(path);
        // HttpURLConnection con = (HttpURLConnection)url.openConnection();
        // System.out.println(con.getResponseCode​() +" "+ con.getContentType());
        // InputStream in = url.openStream();
        // BufferedReader buffer = new BufferedReader(new InputStreamReader(in));
        // StringBuffer bs = new StringBuffer();
        // String line  = null;
        // while((line=buffer.readLine())!=null){
        //     bs.append(line);
        // }
        // System.out.println("getClassData:"+bs.length()+":"+bs.substring(0));
        // return bs.toString().getBytes();
            InputStream ins = url.openStream();
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            int bufferSize = 4096;
            byte[] buffer = new byte[bufferSize];
            int len = 0;
            while ((len = ins.read(buffer)) != -1) {
                baos.write(buffer, 0, len);
            }
            System.out.println("getClassData:"+len+":");
            return baos.toByteArray();
        } catch (Exception e) {
            System.out.println("getClassData exception:");
            e.printStackTrace();
        }
        System.out.println("getClassData null:");
        return null;
    }

    @Override
    public Class<?> loadClass(String name, boolean resolve) throws ClassNotFoundException {
        Class c = findLoadedClass(name);
        if( name.startsWith("java.") ){
            ClassLoader system = ClassLoader.getSystemClassLoader();
            c = system.loadClass(name);
        }
        if( null==c ) c = findClass(name);
        if( null!=c && resolve ) resolveClass(c);
        return c;
    }

}
