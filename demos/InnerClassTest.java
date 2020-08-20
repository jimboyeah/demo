/*
The Java™ Tutorials /tutorial/java/javaOO/innerclasses.html

嵌套类 Nested Classes 的形式：

- Inner Class 内部类
- Local Classes 局部类
- Anonymous Classes 匿名类


    class OuterClass {
        ...
        class NestedClass {
            ...
        }
    }

    public class LocalClassExample {
        ...  
        public static void validatePhoneNumber(
            class LocalClass {
            ...  
            }
        }
    }

    public class Button {
        public void click(){
            //匿名内部类，实现的是ActionListener接口
            new ActionListener(){
                public void onAction(){
                    System.out.println("click action...");
                }
            }.onAction();
        }
        //匿名内部类必须继承或实现一个已有的接口
        public interface ActionListener{
            public void onAction();
        }

        public static void main(String[] args) {
            Button button=new Button();
            button.click();
        }
    }

可以使用匿名内部类或静态内部类。


内部类是一个编译时概念，编译后外部类及其内部类会生成两个独立的 class 文件 OuterClass.class 和 OuterClass$InnerClass.class。

内部类可以直接访问外部类的 private 元素，但是外部类不可以直接访问内部类的元素

如果要创建一个内部类对象，必须利用 outerClass.new 来创建：

    OuterClass outerClass = new OuterClass();
    OuterClass.InnerClass innerClass = outerClass.new InnerClass();

即演示代码中的 this.new 演示的使用方式。

*/
public class InnerClassTest {

    public static void main(String s[]) 
    {
        DataStructure.main(s);
    }
}

class DataStructure {

    public static void main(String s[]) 
    {
        // Fill the array with integer values and print out only
        // values of even indices
        DataStructure ds = new DataStructure();
        ds.printEven();
    }

    // Create an array
    private final static int SIZE = 15;
    private int[] arrayOfInts = new int[SIZE];
    
    public DataStructure() 
    {
        // fill the array with ascending integer values
        for (int i = 0; i < SIZE; i++) {
            arrayOfInts[i] = i;
        }
    }
    
    public void printEven() 
    {
        // Print out values of even indices of the array
        DataStructureIterator iterator = this.new EvenIterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
        System.out.println();
    }
    
    interface DataStructureIterator extends java.util.Iterator<Integer> { } 

    // Inner class implements the DataStructureIterator interface,
    // which extends the Iterator<Integer> interface
    
    private class EvenIterator implements DataStructureIterator 
    {
        // Start stepping through the array from the beginning
        private int nextIndex = 0;
        
        public boolean hasNext() 
        {
            // Check if the current element is the last in the array
            return (nextIndex <= SIZE - 1);
        }        
        
        public Integer next() 
        {
            // Record a value of an even index of the array
            Integer retValue = Integer.valueOf(arrayOfInts[nextIndex]);
            
            // Get the next even element
            nextIndex += 2;
            return retValue;
        }
    }
}