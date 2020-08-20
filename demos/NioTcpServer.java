/*
- [Java1.4 从 BIO 模型发展到 NIO 模型](https://www.cnblogs.com/kendoziyu/p/java-develop-from-bio-to-nio.html)
*/

import java.io.*;
import java.nio.*;
import java.net.*;
import java.util.*;
import java.nio.channels.*;

public class NioTcpServer 
{
    public static void main(String[] args) 
    {
        try {
            ServerSocketChannel channel = ServerSocketChannel.open();
            
            System.out.println("Default ServerSocketChannel isBlocking: " + channel.isBlocking());
            channel.configureBlocking(false); // Non-blocking I/O mode
            channel.bind(new InetSocketAddress(8081));

            Selector selector = Selector.open();
            channel.register(selector, SelectionKey.OP_ACCEPT);

            System.out.println("Test: curl localhost:8081");
            new Thread(new SelectorIO(selector), "Selector-IO").start();
            System.in.read(); // 阻塞主线程
        } catch (IOException ex) {
            System.out.println("TcpServer " + ex);
        }
    }
}

class SelectorIO implements Runnable 
{

    private Selector selector;

    public SelectorIO(Selector selector) 
    {
        this.selector = selector;
    }

    @Override
    public void run() 
    {
            while (true) {
        try {
                int count = selector.select();
                if (count == 0) continue;
                Iterator<SelectionKey> iterator = selector.selectedKeys().iterator();
                while (iterator.hasNext()) {
                    SelectionKey selectionKey = iterator.next();
                    if (selectionKey.isAcceptable()) {
                        handleAccept(selectionKey);
                    } else if (selectionKey.isReadable()) {
                        handleRead(selectionKey);
                    } else if (selectionKey.isWritable()) {
                        handleWrite(selectionKey);
                    }
                    // 坑，如果不移除，同一个事件会重复处理
                    iterator.remove();
                }
        } catch (Exception e) {
            System.out.println("SelectorIO run error." + e);
            e.printStackTrace();
        }
            }
    }

    private void handleWrite(SelectionKey selectionKey) throws IOException 
    {
        System.out.println("Writing...");
        SocketChannel socketChannel = (SocketChannel) selectionKey.channel();
        socketChannel.write(ByteBuffer.wrap("heartbeat\r\n".getBytes()));
        selectionKey.interestOps(SelectionKey.OP_READ);
    }

    private void handleRead(SelectionKey selectionKey) throws IOException 
    {
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        SocketChannel socketChannel = (SocketChannel) selectionKey.channel();
        buffer.clear();
        socketChannel.read(buffer);
        buffer.flip();
        byte[] data = new byte[buffer.remaining()];
        buffer.get(data);
        System.out.print("Reading ");
        System.out.println(new String(data));
        SelectionKey write = socketChannel.register(selector, SelectionKey.OP_WRITE);
        // SelectionKey write = selectionKey.interestOps(SelectionKey.OP_WRITE);
        System.out.println(write.equals(selectionKey));
    }

    private void handleAccept(SelectionKey selectionKey) throws IOException 
    {
        ServerSocketChannel server = (ServerSocketChannel) selectionKey.channel();
        SocketChannel socketChannel = server.accept();
        socketChannel.configureBlocking(false); // Non-Blocking I/O mode
        SelectionKey read = socketChannel.register(selectionKey.selector(), SelectionKey.OP_READ);
        System.out.println(read.equals(selectionKey));
    }
}