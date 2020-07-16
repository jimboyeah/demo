/*
 * DEMO by Jimbowhy 2016/3/5 4:12:02
 * TEXT: http://blog.csdn.net/winsenjiansbomber/article/details/50806962
 */

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <mysql.h> 

#define TIP_ERROR			"ERROR(%s:%d) #%d %s\n"
#define TIP_ERROR_CONNECT	"Connection error #%d!\n"
#define TIP_CONNECT_OK		"Demo by Jimbowhy. Mysql %s has connected!\n"
#define TIP_TEST			"MySQL database testing...\n"
#define TIP_DBINFO			"Charset=%s; collation=%s; dir=%s\n"
#define TIP_RSINFO			"%d data rows, %d field count\n"

#define SQL_TEST    "SELECT ID,post_title FROM wp_posts;\n"

#define USER		"root"
#define PASSWORD	"1im8o"
#define HOST		"localhost"
#define PORT		3306
#define DATABASE	"hyc_hr"

char TIP_GBK[5]   = {0xBA, 0xD3, 0xD4, 0xB4, 0x00}; //"ºÓÔ´";
char TIP_UTF[7]   = {0xE6, 0xB2, 0xB3, 0xE6, 0xBA, 0x90, 0x00};
char *TIP_CHARSET = "Test charset for GBK: %s, UTF-8: %s\n";

void query(MYSQL db, char *sql){

	printf(TIP_TEST);
	printf("SQL: %s", sql);

	MYSQL_RES *rs;
	MYSQL_ROW row;
	unsigned long *len;
	unsigned long fc, rc;

	if(0!=mysql_query(&db,sql)){
		printf("ERR %s\n", mysql_error(&db));
		return;
	}
	
	//rs = mysql_use_result(&db);
	rs = mysql_store_result(&db);

	if(NULL==rs){
		printf(TIP_ERROR,__FILE__, __LINE__, mysql_errno(&db),mysql_error(&db));
	}
	fc = mysql_field_count(&db);
	rc = mysql_num_rows(rs);
	printf(TIP_RSINFO, rc, fc);

	int c = 1;
	while ((row = mysql_fetch_row(rs)) != NULL && c>-1){
		len = mysql_fetch_lengths(rs);
		if(NULL==len){
			printf(TIP_ERROR,__FILE__, __LINE__, mysql_errno(&db),mysql_error(&db));
		}
		printf("%s\t%s\n", row[0],row[1]);
		c % 16 == 0 && getch() == 'x'? c=-1 : c++;
	}
	mysql_free_result(rs); /* NEVER forget this free */

}

class Base
{
	public:
		void say(){ printf("Hi! %d", this); }
};

int main()
{
	Base bb;
	bb.say();

	printf(TIP_CHARSET, TIP_GBK, TIP_UTF);
	MYSQL db;
	mysql_init(&db);
	MY_CHARSET_INFO dbi;
	if(mysql_real_connect(&db,HOST,USER,PASSWORD,DATABASE,PORT,NULL,0)){
		printf(TIP_CONNECT_OK, mysql_get_server_info(&db));

		mysql_get_character_set_info(&db, &dbi);
		printf(TIP_DBINFO, dbi.name, dbi.csname, dbi.dir);
		mysql_set_character_set(&db, "utf8");
		mysql_get_character_set_info(&db, &dbi);
		printf(TIP_DBINFO, dbi.name, dbi.csname, dbi.dir);

		query(db,SQL_TEST);
	}else{
		printf(TIP_ERROR_CONNECT, mysql_errno(&db));
		printf(TIP_ERROR,__FILE__, __LINE__, mysql_errno(&db),mysql_error(&db));
		//fprintf(stderr, "ERROR: %s\n", mysql_error(&db));
	}

	mysql_close(&db);

	return 0;
}