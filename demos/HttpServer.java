/*
# 实现一个简单 Web 服务器
- HTTP Keep-Alive https://www.cnblogs.com/skynet/archive/2010/12/11/1903347.html
- TCP Keep-Alives https://tools.ietf.org/html/rfc1122#page-101
- 聊聊 TCP KeepAlive 机制 https://zhuanlan.zhihu.com/p/28894266
- 简单 Web 服务器 https://blog.csdn.net/u012734441/article/details/44801523
- 完整的 HTTP 请求 https://zhuanlan.zhihu.com/p/38240894
- https://hit-alibaba.github.io/interview/basic/network/HTTP.html#transfer-encoding
- https://hit-alibaba.github.io/interview/basic/network/HTTP.html#持久连接
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Connection_management_in_HTTP_1.x
- https://imququ.com/post/web-proxy.html

关于 URL 长度限制问题，IE 最长可以传 2083 字节，而 GET 最多只能到 2048 字符。但是 RFC 2616，Hypertext Transfer Protocol -- HTTP/1.1，并没有对 URL 长度做限制。

幂等（idempotent、idempotence）是一个数学与计算机学概念，常见于抽象代数中。
在编程中一个幂等操作的特点是其任意多次执行所产生的影响均与一次执行的影响相同。幂等函数，或幂等方法，是指可以使用相同参数重复执行，并能获得相同结果的函数。

假如在不考虑诸如错误或者过期等问题的情况下，若干次请求的副作用与单次请求相同或者根本没有副作用，那么这些请求方法就能够被视作“幂等”的。GET，HEAD，PUT 和 DELETE方法都有这样的幂等属性，同样由于根据协议，OPTIONS，TRACE 都不应有副作用，因此也理所当然也是幂等的。

HTTP 1.1 有多种连接方式：

- Short-lived Connections 短暂连接，请求一次就断开；
- Persistent Connections 持久连接，请求后保持连接，后续再通过此连接请求其它资源；
- HTTP Pipelining 通过持久连接发出连续的请求而不是等待回复后再发出请求；

## POST 数据

每个 POST 主要包含了 Content-Type 和消息主体编码方式两部分。

浏览器 form 表单如果不设置 enctype 编码属性，那么就会以 application/x-www-form-urlencoded 方式提交数据。而带文件的表单会以 multipart/form-data 方式 POST 数据，文件数据通过约定的 boundary 进行分割。

看一个请求示例：

    POST http://www.example.com HTTP/1.1
    Content-Type:multipart/form-data; boundary=----WebKitFormBoundaryrGKCBY7qhFd3TrwA

    ------WebKitFormBoundaryrGKCBY7qhFd3TrwA
    Content-Disposition: form-data; name="text"

    title
    ------WebKitFormBoundaryrGKCBY7qhFd3TrwA
    Content-Disposition: form-data; name="file"; filename="chrome.png"
    Content-Type: image/png

    PNG ... content of chrome.png ...
    ------WebKitFormBoundaryrGKCBY7qhFd3TrwA--


## HTTP Keep-Alive 

简单说就是保持当前的 TCP 连接，避免了重新建立连接。

KeepAlive 并不是 TCP 协议规范的一部分，但在几乎所有的 TCP/IP 协议栈（不管是Linux还是Windows）中，都实现了 KeepAlive 功能。

- KeepAlive 默认情况下是关闭的，可以被上层应用开启和关闭
- tcp_keepalive_time: KeepAlive 的空闲时长，或者说每次正常发送心跳的周期，默认值为 7200s（2小时）
- tcp_keepalive_intvl: KeepAlive 探测包的发送间隔，默认值为 75s
- tcp_keepalive_probes: 在 tcp_keepalive_time 之后，没有接收到对方确认，继续发送保活探测包次数，默认值为9（次）

HTTP 长连接不可能一直保持，例如 Keep-Alive: timeout=5, max=100，表示这个 TCP 通道可以保持 5 秒，max=100，表示这个长连接最多接收 100 次请求就断开。

HTTP 是一个无状态协议，这意味着每个请求都是独立的，Keep-Alive 没能改变这个结果。另外，Keep-Alive也不能保证客户端和服务器之间的连接一定是活跃的，在 HTTP1.1 版本中也如此。唯一能保证的就是当连接被关闭时你能得到一个通知，所以不应该让程序依赖于 Keep-Alive 的保持连接特性，否则会有意想不到的后果。

使用长连接之后，客户端、服务端怎么知道本次传输结束呢？两部分：1. 判断传输数据是否达到了Content-Length 指示的大小；2. 动态生成的文件没有 Content-Length ，它是分块传输（chunked），这时候就要根据 chunked 编码来判断，chunked 编码的数据在最后有一个空 chunked 块，表明本次传输数据结束。


## Transfer-Encoding 

用来标示 HTTP 报文传输格式的头部值。尽管这个取值理论上可以有很多，但是当前的 HTTP 规范里实际上只定义了一种传输取值——chunked。

如果一个HTTP消息（请求消息或应答消息）的Transfer-Encoding消息头的值为chunked，那么，消息体由数量未定的块组成，并以最后一个大小为0的块为结束。

每一个非空的块都以该块包含数据的字节数（字节数以十六进制表示）开始，跟随一个CRLF （回车及换行），然后是数据本身，最后块CRLF结束。在一些实现中，块大小和CRLF之间填充有白空格（0x20）。

最后一块是单行，由块大小（0），一些可选的填充白空格，以及CRLF。最后一块不再包含任何数据，但是可以发送可选的尾部，包括消息头字段。消息最后以CRLF结尾。

一个示例响应如下：

    HTTP/1.1 200 OK
    Content-Type: text/plain
    Transfer-Encoding: chunked

    25
    This is the data in the first chunk

    1A
    and this is the second one
    0


## HTTP 管线化 Pipelining

默认情况下 HTTP 协议中每个传输层连接只能承载一个 HTTP 请求和响应，浏览器会在收到上一个请求的响应之后，再发送下一个请求。在使用持久连接的情况下，某个连接上消息的传递类似于请求1 -> 响应1 -> 请求2 -> 响应2 -> 请求3 -> 响应3。

HTTP Pipelining 管线化是将多个 HTTP 请求整批提交的技术，在传送过程中不需等待服务端的回应。使用 HTTP Pipelining 技术之后，某个连接上的消息变成了类似这样请求1 -> 请求2 -> 请求3 -> 响应1 -> 响应2 -> 响应3。

管线化机制通过持久连接 persistent connection 完成，仅 HTTP/1.1 支持。只有 GET 和 HEAD 请求可以进行管线化，而 POST 则有所限制。

开启管线化很可能并不会带来大幅度的性能提升，而且很多服务器端和代理程序对管线化的支持并不好，因此现代浏览器如 Chrome 和 Firefox 默认并未开启管线化支持。

## Java Socket

线程执行 ServerSocket accept() 方法进入阻塞，一直等到有客户连接。当线程执行 Socket read() 或 readLine() 读取数据时，如果输入流中没有数据，线程也会阻塞，一直等到读入足够的数据才返回。

java.nio 包提供了支持非阻塞通信的类，ServerSocketChannel 替代 ServerSocket 支持阻塞通信与非阻塞通信。SocketChannel 替代 Socket 支持阻塞通信与非阻塞通信。


*/

// package cn.demos;

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
 
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.*;

class Request {
    private InputStream input;
    
    private String uri;

    public String[] headers; 
    
    public Request(InputStream input){
        this.input = input;
    }
    
    public void parse() throws IOException
    {
        String req = readString(input);
        System.out.printf("Request[%d]: \n%s", req.length(), req);
        uri = parseUri(req);
    }
    
    public String parseUri(String requestString){
        int verb, puri;
        verb = requestString.indexOf(" ");
        if(verb != -1){
            puri = requestString.indexOf(" ", verb+1);
            if(puri>verb){
                return requestString.substring(verb+1, puri);
            }
        }
        return null;
    }
    
    public String getUri(){
        return this.uri;
    }

    public static String readString(InputStream inputStream) throws IOException
    {
        // byte[] bytes = new byte[0];
        // bytes = new byte[inputStream.available()]; // trap for Connection: Keep-Alive
        // inputStream.read(bytes);
        // String str = new String(bytes);
        // return str;


        // ByteArrayOutputStream buf = new ByteArrayOutputStream();
        // byte[] all = inputStream.readAllBytes(); // JDK 9
        // buf.writeBytes(all);
        // return buf.toString();

StringBuilder sb = new StringBuilder();
String line;

BufferedReader br = new BufferedReader(new InputStreamReader(inputStream));
while ((line = br.readLine()) != null) {
    sb.append(line);
    System.out.printf("%s<\n", line);
}
String str = sb.toString();
return str;

        // BufferedInputStream bis = new BufferedInputStream(inputStream);
        // ByteArrayOutputStream buf = new ByteArrayOutputStream();
        // int result = bis.read();
        // while(result != -1) {
        //     buf.write((byte) result);
        //     result = bis.read();
        // }
        // String str = buf.toString();
        // return str;
    }
}


/**
 * HTTP Response = Status-Line
 *      *(( general-header | response-header | entity-header ) CRLF) 
 *      CRLF
 *      [message-body]
 *      Status-Line=Http-Version SP Status-Code SP Reason-Phrase CRLF
 *
 */
class Response {
    private static final int BUFFER_SIZE=1024;
    Request request;
    OutputStream output;
    
    public Response(OutputStream output){
        this.output = output;
    }
    
    public void setRequest(Request request){
        this.request = request;
    }
    
    public void sendStaticResource()throws IOException{
        byte[] bytes = new byte[BUFFER_SIZE];
        FileInputStream fis = null;
        try {
            File file = new File(HttpServer.WEB_ROOT, request.getUri());
            if (!file.isFile() || !file.exists()) throw new FileNotFoundException(HttpServer.WEB_ROOT + request.getUri());
            output.write(("HTTP/1.1 200 OK\r\n" + 
                            "Connection: Close\r\n" +
                            "\r\nOK").getBytes());

            fis = new FileInputStream(file);
            int ch = fis.read(bytes, 0, BUFFER_SIZE);
            while(ch != -1){
                output.write(bytes, 0, BUFFER_SIZE);
                ch = fis.read(bytes, 0, BUFFER_SIZE);
            }
        } catch (Exception e) {
            System.out.printf("sendStaticResource: %s \n", e.toString());
            e.printStackTrace();
            //file not found
            String errorMessage = "HTTP/1.1 404 File Not Found\r\n"+
                "Content-Type:text/html\r\n"+
                "Content-Length:23\r\n"+
                "\r\n"+
                "<h1>File Not Found</h1>";
            output.write(errorMessage.getBytes());
        }finally{
            if(fis != null){
                fis.close();
            }
        }
    }
}

public class HttpServer {
    /**
     * WEB_ROOT is the directory where our html and other files reside.
     * For this package,WEB_ROOT is the "webroot" directory under the
     * working directory.
     * the working directory is the location in the file system
     * from where the java command was invoke.
     */
    public static final String WEB_ROOT = System.getProperty("user.dir");
        //+File.separator+"webroot";
    
    private static final String SHUTDOWN="/SHUTDOWN";
    
    private boolean shutdown=false;
    
    public static void main(String[] args) {
        HttpServer server = new HttpServer();
        System.out.println("Web root: " + WEB_ROOT);
        start("http://localhost:8080");
        server.await();
    }

    public static void start(String url)
    {
        System.out.println(url);
        Boolean isWin = System.getProperty("os.name").toLowerCase().startsWith("windows");
        ProcessBuilder builder = new ProcessBuilder();
        // if (isWin) {
        //     builder.command("cmd.exe", "/c", "start", url);
        // } else {
        //     builder.command("sh", "-c", "open", url);
        // }
        // builder.directory(new File(System.getProperty("user.dir")));
        try{
            Process process = builder.start();
        }catch(Exception ex){}
    }
    
    public void await(){
        ServerSocket serverSocket=null;
        int port=8080;
        try {
            serverSocket = new ServerSocket(port, 1, InetAddress.getByName("127.0.0.1"));
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
        while(!shutdown){
            Socket socket = null;
            InputStream input = null;
            OutputStream output = null;
            try {
                socket = serverSocket.accept();
                input = socket.getInputStream();
                output = socket.getOutputStream();
                System.out.printf("new client req[%d]...\n", input.available());
                if (input.available()==0) continue; // What is this request?
                // create Request object and parse
                Request request = new Request(input);
                request.parse();
                if (request.getUri()==SHUTDOWN) 
                {
                    shutdown = true;
                    // serverSocket.close();
                }

                // create Response object
                Response response = new Response(output);
                response.setRequest(request);
                response.sendStaticResource();
                output.flush();
                socket.close();
                System.out.println("response client...");
            } catch (Exception e) {
                e.printStackTrace();
                continue;
            }
        }
    }
}
