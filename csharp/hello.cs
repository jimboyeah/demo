using System;
using System.Runtime.InteropServices;

public class Hello {
    public static void Main(string[] args) {
            Console.WriteLine("8 + 5 = {0}", Hello.Add(8, 5));
    }
    [DllImport("libhello.dll", 
        CallingConvention = CallingConvention.StdCall, // Cdecl
        EntryPoint = "Add"
        // ExactSpelling = true
    )] 
    extern public static int Add(int a, int b);
}