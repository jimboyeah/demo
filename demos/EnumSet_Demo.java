// Java program to demonstrate range() method
import java.util.*;
 
// Creating an enum of CARS type
enum CARS {
    RANGE_ROVER,
    MUSTANG,
    CAMARO,
    AUDI,
    BMW
}
;
 
public class EnumSet_Demo {
 
    public static void main(String[] args)
    {
 
        // Creating an EnumSet
        EnumSet<CARS> e_set;
 
        // Input the values using range()
        e_set = EnumSet.range(CARS.RANGE_ROVER, CARS.CAMARO);
 
        // Displaying the new set
        System.out.println("The enum set is: " + e_set);
    }
}