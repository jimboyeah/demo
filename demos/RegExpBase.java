/*
 * Demo Java programme
 * Coompile: javac Base.java
 *    Usage: java -classpath . run
 *    javac Base.java && java -classpath . run
 */

import java.util.*;
import java.util.regex.*;

class RegExpBase
{
    Integer i = 1;
    Integer j,k,l;
    Integer in = new Integer(2);
    Integer [] ia;
    Integer [] ib = {1};
    Integer [] array = {3,6};
    Integer [][] d2 = {{2,8},{3,6}};
    Integer [][] dt = new Integer[][]{{2,8},{3,6}};
    Integer [] dd = new Integer[2];
    //Integer [] dc = new Integer[]; Error

    public void say(Integer i){
        System.out.println(array[1]);
        System.out.println(in);
    }
    public static void main(String[] args){
        RegEx.test();
    }
}

class RegEx
{
    public static void test(){
        String url = "www.forth.com/starting-forth/sf5/sf5.html";
        System.out.println(slice("(/)",url).length);
        System.out.println(exec("(/[^/]+)", url).length);
        System.out.println(exec("(w+.+/[^/]+)", url).length);
        System.out.println(exec("(w+\\.\\w+\\.com)", url).length);
    }
    public static String[] slice(String rule, String txt){
        Pattern p = Pattern.compile(rule);
        String[] slice = p.split(txt);
        System.out.println("Regex slice of "+txt);
        for(int i=0; i<slice.length; i++){
            System.out.println("\t"+slice[i]);
        }
        return slice;
    }
    public static String[] exec(String rule, String txt){
        Pattern p = Pattern.compile(rule);
        Matcher m = p.matcher(txt);
        boolean bl = m.lookingAt();
        boolean bm = m.matches();
        boolean bf = m.find();
        m.reset();
        int c = m.groupCount();
        System.out.println("matches(), find(), lookingAt():" + bm+", "+bf+", "+bl);
        List<String> rs = new ArrayList<String>();
        while(m.find()) { 
            rs.add( m.group() );
            System.out.println("matcher find: "+m.group()); 
        }
        return rs.toArray(new String[0]);
    }
}
