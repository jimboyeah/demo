/*
Groovy 脚本执行：
java -jar groovy-2.5.13.jar demo.groovy
java -jar C:\Users\OCEAN\.m2\repository\org\codehaus\groovy\groovy\2.5.13\groovy-2.5.13.jar demo.groovy
*/

def msg = '中汉 hello demo.groovy!'
System.out.println(msg);
System.out.println msg;

println("msg: ${msg}")
println "msg: ${msg}"

println new String(msg.getBytes("GBK"), "GBK")

def m2 = new String(msg.getBytes("UTF-8"), "GBK")
// 涓�姹� hello demo.groovy!
println m2
// 娑擃厽鐪? hello demo.groovy!
println new String(m2.getBytes("UTF-8"), "GBK")
