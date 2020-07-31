// mcppv2_paramarray3.cs
// compile with: csc /r:mcppv2_paramarray2.dll mcppv2_paramarray3.cs
// a C# program

public class X {
   public static void Main() {
      // Visual C# will generate a String array to match the
      // ParamArray attribute
      C myc = new C();
      myc.f("hello", "there", "world");
   }
}