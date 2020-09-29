/*
Groovy 脚本执行：
java -jar groovy-2.5.13.jar demo.groovy
java -jar C:\Users\OCEAN\.m2\repository\org\codehaus\groovy\groovy\2.5.13\groovy-2.5.13.jar demo.groovy
*/
package com.demos;

import java.lang.annotation.*;

class Example 
{
   static void main(String[] args) 
   {
      Student st = new Student();
      st.StudentID = 1;
      st.Marks1 = 10;
      st.DisplayMarks();

      Package pkg = Student.class.getPackage();
      System.out.println("Package: " + pkg);
   } 
} 

interface Marks 
{ 
   void DisplayMarks(); 
} 

class Student implements Marks 
{
   int StudentID
   int Marks1;
    
   void DisplayMarks() {
      println(Marks1);
   }
}

