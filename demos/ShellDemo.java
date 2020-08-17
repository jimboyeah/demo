import java.util.stream.*;
import java.util.function.*;
import java.util.concurrent.*;
import java.io.*;

public class ShellDemo
{ 
    public static boolean isWindows = System.getProperty("os.name").toLowerCase().startsWith("windows");

    static public void main(String args[]) throws IOException, InterruptedException
    { 
        // RuntimeExecTest();
        ProcessBuilderTest();
    } 
    static public void log(String t){
        System.out.println(t); 
    } 

    static void RuntimeExecTest() throws IOException, InterruptedException
    {
        String homeDirectory = System.getProperty("user.home");
        Process process;
        if (isWindows) {
            process = Runtime.getRuntime()
             .exec(String.format("cmd.exe /c dir %s", homeDirectory));
        } else {
            process = Runtime.getRuntime()
             .exec(String.format("sh -c ls %s", homeDirectory));
        }
        StreamGobbler streamGobbler = 
         new StreamGobbler(process.getInputStream(), ShellDemo::log);
        Executors.newSingleThreadExecutor().submit(streamGobbler);
        int exitCode = process.waitFor();
        assert exitCode == 0;
    }

    // ProcessBuilder 执行比 Runtime 方法更可取，因为能够定制一些细节。
    // - builder.directory() 改变正在运行 Shell 命令的工作目录
    // - builder.environment() 方法设置自定义键值对作为环境变量
    // - builder.inheritio() 方法将它们都继承到当前 JVM 进程的流中
    // - 重定向输入和输出流值自定义流

    static void ProcessBuilderTest() throws IOException, InterruptedException
    {
        ProcessBuilder builder = new ProcessBuilder();
        if (isWindows) {
            builder.command("cmd.exe", "/c", "start");
        } else {
            builder.command("sh", "-c", "ls");
        }
        builder.directory(new File(System.getProperty("user.dir")));
        Process process = builder.start();
        
        StreamGobbler streamGobbler = new StreamGobbler(process.getInputStream(), System.out::println);
        Executors.newSingleThreadExecutor().submit(streamGobbler);
        int exitCode = process.waitFor();
        assert exitCode == 0;
    }

    private static class StreamGobbler implements Runnable {
        private InputStream inputStream;
        private Consumer<String> consumer;

        public StreamGobbler(InputStream inputStream, Consumer<String> consumer) {
            this.inputStream = inputStream;
            this.consumer = consumer;
        }

        @Override
        public void run() {
            new BufferedReader(new InputStreamReader(inputStream)).lines().forEach(consumer);
        }
    }
}

