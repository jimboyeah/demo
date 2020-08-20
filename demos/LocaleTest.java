import java.util.Locale;
import java.util.Date;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import java.text.DateFormat;

public class LocaleTest {
 
  public static void main(String[] args) {
    testDiffDateLocales();
    testAllLocales();
  }
 
  private static void testDiffDateLocales() {
    // date: 2020-09-19 14:22:30
    Date date = new Date(120, 8, 19, 14, 22, 30);
 
    Locale localeCN = Locale.SIMPLIFIED_CHINESE;
    Locale localeUS = new Locale("en", "US");
 
    String cn = DateFormat.getDateInstance(DateFormat.MEDIUM, localeCN).format(date);
    String us = DateFormat.getDateInstance(DateFormat.MEDIUM, localeUS).format(date);
 
    System.out.printf("Locale.SIMPLIFIED_CHINESE: %s\nLocal.US: %s\n", cn, us);
  }
 
  private static void testAllLocales() {
    Locale[] ls = Locale.getAvailableLocales();
 
    System.out.print("All Locales: \n");
    for (Locale locale:ls) {
      System.out.printf("(%s), ", locale);
    }
    System.out.println();
  }
}