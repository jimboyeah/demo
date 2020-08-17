public class DemoStatic 
{ 
    public static DemoStatic a = new DemoStatic();
    public static DemoStatic z = new DemoStatic(); 
    { log("Dynamic Code Block "); } 
    static { log("Static Code Block "); } 

    public DemoStatic() 
    { 
        log("Constructor"); 
    } 

    static public void main(String args[]) 
    { 
        // new DemoStatic(); 
        String a = "/abc/def/ghi"; 
        String[] b = a.split("/"); 
        log("长度:"+b.length); 
        log("[0]:"+b[0]); 
        log("[1]:"+b[1]); 
        log(DemoStatic.a.toString());
    } 
    
    static public void log(String t)
    {
        System.out.println(t); 
    } 
}