1.InputStream、OutputStream

处理字节流的抽象类

InputStream 是字节输入流的所有类的超类,一般我们使用它的子类,如FileInputStream等.

OutputStream是字节输出流的所有类的超类,一般我们使用它的子类,如FileOutputStream等.

 

2.InputStreamReader  OutputStreamWriter

处理字符流的抽象类

InputStreamReader 是字节流通向字符流的桥梁,它将字节流转换为字符流.

OutputStreamWriter是字符流通向字节流的桥梁，它将字符流转换为字节流.

 

3.BufferedReader BufferedWriter

BufferedReader 由Reader类扩展而来，提供通用的缓冲方式文本读取，readLine读取一个文本行，

从字符输入流中读取文本，缓冲各个字符，从而提供字符、数组和行的高效读取。

BufferedWriter  由Writer 类扩展而来，提供通用的缓冲方式文本写入， newLine使用平台自己的行分隔符，

将文本写入字符输出流，缓冲各个字符，从而提供单个字符、数组和字符串的高效写入。

 
// InputStream 和 String 之间的转化

针对一个 2MB 的文件的输入流，多次执行测试如下(单位是毫秒)：

| 时间 |   序号   |
|------|----------|
|   21 | 方法七   |
|   31 | 方法九   |
|   36 | 方法一   |
|   36 | 方法十二 |
|   40 | 方法六   |
|   66 | 方法三   |
|   87 | 方法二   |
|  101 | 方法四   |
|  107 | 方法八   |
|  111 | 方法十   |
|  178 | 方法五   |
|  236 | 方法十一 |

从上述结果来看，方法七和方法九更好一些，而方法五和方法十一会更差一些。


// 1、InputStream转化为String

// 方法一：
byte[] bytes = new byte[0];
bytes = new byte[inputStream.available()];
inputStream.read(bytes);
String str = new String(bytes);

// 方法二：
String result = new BufferedReader(new InputStreamReader(inputStream))
        .lines().collect(Collectors.joining(System.lineSeparator()));

// 方法三：
String result = new BufferedReader(new InputStreamReader(inputStream))
       .lines().parallel().collect(Collectors.joining(System.lineSeparator()));

// 方法四：
Scanner s = new Scanner(inputStream).useDelimiter("\\A");
String str = s.hasNext() ? s.next() : "";

// 方法五：
String resource = new Scanner(inputStream).useDelimiter("\\Z").next();
return resource;

// 方法六：
StringBuilder sb = new StringBuilder();
String line;

BufferedReader br = new BufferedReader(new InputStreamReader(inputStream));
while ((line = br.readLine()) != null) {
    sb.append(line);
}
String str = sb.toString();
return str;

// 方法七：
ByteArrayOutputStream result = new ByteArrayOutputStream();
byte[] buffer = new byte[1024];
int length;
while ((length = inputStream.read(buffer)) != -1) {
    result.write(buffer, 0, length);
}
String str = result.toString(StandardCharsets.UTF_8.name());
return str;

// 方法八：
BufferedInputStream bis = new BufferedInputStream(inputStream);
ByteArrayOutputStream buf = new ByteArrayOutputStream();
int result = bis.read();
while(result != -1) {
    buf.write((byte) result);
    result = bis.read();
}
String str = buf.toString();
return str;

// 1.2 Apache Common提供

// 方法九：
StringWriter writer = new StringWriter();
IOUtils.copy(inputStream, writer, StandardCharsets.UTF_8.name());
String str = writer.toString();

// 方法十：
String str = IOUtils.toString(inputStream, "utf-8");

// 1.3 Google Guava 提供

// 方法十一：
String str = CharStreams.toString(new InputStreamReader(inputStream, StandardCharsets.UTF_8));

// 方法十二：
String str = new String(ByteStreams.toByteArray(inputStream));

// 2、String转化为InputStream

InputStream is = new ByteArrayInputStream(str.getBytes());

// 2.2 Apache Common提供

InputStream targetStream = IOUtils.toInputStream(str, StandardCharsets.UTF_8.name());

// 2.3 Google Guava提供

InputStream targetStream = new ReaderInputStream(CharSource.wrap(str).openStream(), StandardCharsets.UTF_8.name());
