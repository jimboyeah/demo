import java.util.Date;

public class PrintfTest { 
    public static void main(String[] args) { 

        int i = 254; 
        double d = 128.678; 
        String s = "System.out.rintf test: \n"; 

        System.out.printf("%s %c \n", s, 'X');      // %s   表示输出字符串。 
        System.out.printf("%f \n", d);      // %f   表示格式化输出浮点数。 
        System.out.printf("%9.2f \n", d);   // %9.2 指定 m.n 输出宽度，和小数点后的位数。 
        System.out.printf("%+9.2f \n", d);  // %+   前缀表示输出的数带正负号。 
        System.out.printf("%-9.4f \n", d);  // %-   前缀表示输出的数左对齐（默认为右对齐）。 
        System.out.printf("%+-9.3f \n", d); // %+-  前缀表示输出的数带正负号且左对齐。 
        System.out.printf("%d \n", i);      // %d   表示输出十进制整数。 
        System.out.printf("%o \n", i);      // %o   表示输出八进制整数。 
        System.out.printf("%x \n", i);      // %x   表示输出十六进制整数。 
        System.out.printf("%#x \n", i);     // %#x  表示输出带有十六进制标志的整数。 
        System.out.printf("字符串：%2$s，%1$d 对应十六进制数 %1$#x%n", i, s);   // 多个变量用 X$ 指定第几个变量。

        Date date = new Date();
        long dataL = date.getTime();
        // %t 格式化年月日
        // y/Y 表示输出日期的年份，2 位数或 4 位数
        // m 表示输出日期的月份
        // d 表示输出日期的日号
        // b/B 表示输出日期的月份的缩写或完整名
        System.out.printf("%1$ty-%1$tm-%1$td; %2$ty-%2$tm-%2$td%n", date, dataL);
        System.out.printf("现在是 %1$tB%n", date);

        // 日期组合
        // D 表示以 "%tm/%td/%ty"格式化日期
        // F 表示以"%tY-%tm-%td"格式化日期
        System.out.printf("%1$tD%n", date);
        System.out.printf("%1$tF%n", date);

        // 输出时分秒
        // H 表示输出时间的时（24进制）
        // I 表示输出时间的时（12进制），
        // M 表示输出时间的分
        // S 表示输出时间的秒
        // L 表示输出时间的秒中的毫秒
        // p 表示输出时间的上午或下午信息
        System.out.printf("%1$tH:%1$tM:%1$tS; %2$tI:%2$tM:%2$tS%n", date, dataL);
        System.out.printf("%1$tH:%1$tM:%1$tS %1$tL%n", date);
        System.out.printf("%1$tH:%1$tM:%1$tS %1$tL %1$tp%n", date);

        // 时间组合
        // R 表示以"%tH:%tM"格式化时间
        // T 表示以"%tH:%tM:%tS"格式化时间
        // r 表示以"%tI:%tM:%tS %Tp"格式化时间
        System.out.printf("%1$tR%n", date);
        System.out.printf("%1$tT%n", date);
        System.out.printf("%1$tr%n", date);
        System.out.printf("%1$tD %1tT.%1$tL%n", date);

        /*** 输出星期***/
        // a/A 表示得到星期几的简称或全称
        // c 输出时间日期的完整信息
        System.out.printf("%1$tF %1$tA%n", date);
        System.out.printf("%1$tF %1$ta%n", date);
        System.out.printf("%1$tc%n", date);
    } 
}