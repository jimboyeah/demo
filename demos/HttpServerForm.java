
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;
// import org.apache.commons.io.IOUtils;

import java.io.*;
import java.io.IOException;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.InetSocketAddress;
import java.net.URLDecoder;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

// http://localhost:8001/test
// curl -d "a=abc" http://localhost:8001/test?a=b
public class HttpServerForm {

    public static void main(String[] arg) throws Exception {
        HttpServer server = HttpServer.create(new InetSocketAddress(8001), 0);
        server.createContext("/test", new TestHandler());
        server.start();
    }

    static class TestHandler implements HttpHandler{
        @Override
        public void handle(HttpExchange exchange) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try{
                        String response = "hello world";

                        String queryString =  exchange.getRequestURI().getQuery();
                        Map<String,String> queryStringInfo = formData2Dic(queryString);
                        System.out.println(queryStringInfo);

                        // String postString = IOUtils.toString(exchange.getRequestBody());
                        String postString = readString(exchange.getRequestBody());
                        Map<String,String> postInfo = formData2Dic(postString);
                        System.out.println(postInfo);

                        exchange.sendResponseHeaders(200,0);
                        OutputStream os = exchange.getResponseBody();
                        os.write(response.getBytes());
                        os.close();
                    }catch (IOException ie) {
                        ie.printStackTrace();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }

    public static Map<String,String> formData2Dic(String formData ) {
        Map<String,String> result = new HashMap<>();
        if(formData== null || formData.trim().length() == 0) {
            return result;
        }
        final String[] items = formData.split("&");
        Arrays.stream(items).forEach(item ->{
            final String[] keyAndVal = item.split("=");
            if( keyAndVal.length == 2) {
                try{
                    final String key = URLDecoder.decode( keyAndVal[0],"utf8");
                    final String val = URLDecoder.decode( keyAndVal[1],"utf8");
                    result.put(key,val);
                }catch (UnsupportedEncodingException e) {}
            }
        });
        return result;
    }

    public static String readString(InputStream inputStream) throws IOException
    {
        // byte[] bytes = new byte[0];
        // bytes = new byte[inputStream.available()];
        // inputStream.read(bytes);
        // String str = new String(bytes);
        // return str;


        BufferedInputStream bis = new BufferedInputStream(inputStream);
        ByteArrayOutputStream buf = new ByteArrayOutputStream();
        int result = bis.read();
        while(result != -1) {
            buf.write((byte) result);
            result = bis.read();
        }
        String str = buf.toString();
        return str;
    }
}