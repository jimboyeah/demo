public class StringTest 
{
    public static void main(String[] args) throws Exception
    {
        String msg = "Hello 汉字!";
        byte[] bytes = msg.getBytes("ISO-8859-1");
        char[] chars = msg.toCharArray();
        System.out.println("String: "+msg.length() + " " + msg);
        System.out.printf("  bytes: %d %s \n", bytes.length, bytes);
        for (byte v:bytes ) {
            System.out.printf("  ->: %s\n", v);
        }
        System.out.printf("  chars: %d %s \n", chars.length, chars);
        for (char v:chars ) {
            System.out.printf("  ->: %s\n", v);
        }

        // String s="cfcd208495d565ef66e7dff9f98764da";
        // ByteArray b = new ByteArray(s.getBytes());
        // CharArray c = new CharArray(s.toCharArray());

        // long stringBytes = MemoryUtil.deepMemoryUsageOf(s);
        // long byteArrayBytes = MemoryUtil.deepMemoryUsageOf(b);
        // long charArrayBytes = MemoryUtil.deepMemoryUsageOf(c);

        // System.out.println("stringBytes:"+stringBytes);
        // System.out.println("byteArrayBytes:"+byteArrayBytes);
        // System.out.println("charArrayBytes:"+charArrayBytes);
    }
}