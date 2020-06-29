public class Hello
{
	public static void main(String[] args)
	{
		System.out.println("8 + 5 = " + Hello.add(8, 5));
	}
	
	static
	{
		System.loadLibrary("../bin/libhello");
	}
	
	public static native int add(int a, int b);
}
