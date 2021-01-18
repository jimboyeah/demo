// mcppv2_paramarray3.cs
// compile with: csc /r:mcppv2_paramarray2.dll ..\dotnet-clr\src\mcppv2_paramarray3.cs
// a C# program

using System;

public class X {
    static void Main(string[] args)
    {
        // Visual C# will generate a String array to match the
        // ParamArray attribute
        String plugin = args.Length > 0? args[0]:"demo";
        if (!plugin.EndsWith(".exe")) plugin += ".exe";
        Console.WriteLine("Test:{0}\n", plugin);
        C myc = new C();
        myc.f("hello", "there", "world");
   }
}