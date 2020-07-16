/*
 * DEMO by Jimbowhy 2016/3/5 4:12:02
 * TEXT: http://blog.csdn.net/winsenjiansbomber/article/details/50806962
 * codepage list: control panel -> language option -> advanced
 */

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>

char TIP_GBK[5]   = {0xBA, 0xD3, 0xD4, 0xB4, 0x00}; //"河源";
char TIP_BIG[5]   = {0xAA, 0x65, 0xB7, 0xBD, 0x00};
char TIP_UNILE[5] = {0xB3, 0x6C, 0x90, 0x6E, 0x00};
char TIP_UNIBE[5] = {0x6C, 0xB3, 0x6E, 0x90, 0x00};
char TIP_UTF[7]   = {0xE6, 0xB2, 0xB3, 0xE6, 0xBA, 0x90, 0x00};
char *TIP_CHARSET = "Test charset for 中文字符集:\nGBK: %s, BIG5: %s, UNI-LE: %s, UNI-BE: %s, UTF-8: %s\n";

int main()
{

	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 932");printf("chcp 932\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 936");printf("chcp 936\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 949");printf("chcp 949\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 950");printf("chcp 950\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 1200");printf("chcp 1200\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 1201");printf("chcp 1201\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);
	getch();

	system("chcp 20936");printf("chcp 20936\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);

	system("chcp 65001");printf("chcp 65001\n");
	printf(TIP_CHARSET, TIP_GBK, TIP_BIG, TIP_UNILE, TIP_UNIBE, TIP_UTF);

	unsigned int c;
    char *locale;
    locale = setlocale(LC_ALL, "");
	printf("locale %s\n", locale);
	c = getwchar();
	printf("bye 0x%x", c);
	c = getwchar();
	printf("bye 0x%x", c);
	return 0;
}
