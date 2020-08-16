/*
https://docs.oracle.com/javase/tutorial/java/javaOO/enum.html
java 枚举(enum) 全面解读 https://www.jianshu.com/p/0d69c36a723b
*/

public class EnumTest {
    Day day;
    
    public EnumTest(Day day) {
        this.day = day;
    }
    
    public void tellItLikeItIs() {
        switch (day) {
            case MONDAY:
                System.out.println("Mondays are bad.");
                break;
                    
            case FRIDAY:
                System.out.println("Fridays are better.");
                break;
                         
            case SATURDAY: case SUNDAY:
                System.out.println("Weekends are best.");
                break;
                        
            default:
                System.out.println("Midweek days are so-so.");
                break;
        }
    }
    
    public static void main(String[] args) {
        System.out.printf("Day.MONDAY.ordinal() -> %d\n", Day.MONDAY.ordinal());
        System.out.printf("Day.SATURDAY.ordinal() -> %d\n", Day.SATURDAY.ordinal());
        System.out.printf("Day.valueOf(\"MONDAY\") -> %s\n", Day.valueOf("MONDAY"));
        
        // foreach Day[]
        for (Day day:Day.values())
        {
            System.out.printf("foreach Day.values() -> %s\n", day);
        }

        EnumTest firstDay = new EnumTest(Day.MONDAY);
        firstDay.tellItLikeItIs();
        EnumTest thirdDay = new EnumTest(Day.WEDNESDAY);
        thirdDay.tellItLikeItIs();
        EnumTest fifthDay = new EnumTest(Day.FRIDAY);
        fifthDay.tellItLikeItIs();
        EnumTest sixthDay = new EnumTest(Day.SATURDAY);
        sixthDay.tellItLikeItIs();
        EnumTest seventhDay = new EnumTest(Day.SUNDAY);
        seventhDay.tellItLikeItIs();
    }
}

// jad -sjava Day.class
// public final class Day extends Enum
enum Day
{
    SUNDAY (100), 
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY;

    private int _value;
    Day(){}
    Day(int value)
    {
        _value = value;
    }
}
