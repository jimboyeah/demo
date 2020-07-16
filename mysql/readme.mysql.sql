--------------------------------------------------------------------------------
MySQL Examples
================================================================================

使用php 5.3.3连接使用旧版密码模式的mysql 5.2.14时会有：
mysqlnd cannot connect to MySQL 4.1+ using the old insecure authentication. 
Please use an administration tool to reset your password with the command
SET PASSWORD = PASSWORD('your_existing_password'). 
This will store a new, and more secure, hash value in mysql.user. 
If this user is used in other scripts executed by PHP 5.2 or earlier 
you might need to remove the old-passwords flag from your my.cnf file in 
path/to/the/file/where/connection/script/is/written/

解决方法如下：
SET old_passwords = 0;
UPDATE mysql.user SET Password = PASSWORD('testpass') WHERE User = 'testuser' limit 1;
SELECT LENGTH(Password) FROM mysql.user WHERE User = 'testuser';
FLUSH PRIVILEGES;



安装MySql后，开启CMD输入以下命令进行登录，输入quit退出
mysql -hHost_addr -uUser -p

实例安装与使用
mysqld-nt --install mysqld1
mysqld-nt --remove mysqld1
还可以使用Windows系统的sc命令安装实例
sc create MySQL binPath= "patch\to\bin\mysqld --defaults-file=path\to\my.ini" start= demand



TO SET A PASSWORD FOR THE MySQL root USER !
To do so, start the server, then issue the following commands:

/usr/bin/mysqladmin -u root password 'new-password'
/usr/bin/mysqladmin -u root -h domain.host password 'new-password'

Alternatively you can run:
/usr/bin/mysql_secure_installation

which will also give you the option of removing the test
databases and anonymous user created by default.  This is
strongly recommended for production servers.



查询版本号和当前日期，不分大小写，任意组合，亦可以分行输入：
SELECT VERSION(),CURRENT_DATE;
sElect  VeRsion(),CuRrEnt_DaTE; --二者等效

激活数据库及已激活数据库信息
USE mysql;
SELECT DataBase();

使用information_schema.SCHEMATA表查询数据库列表
SELECT SCHEMA_NAME,DEFAULT_CHARACTER_SET_NAME,DEFAULT_COLLATION_NAME FROM information_schema.SCHEMATA;

当前所有数据库列表
SHOW DATABASES;

当前数据库表列举
SHOW TABLES;
SHOW TABLES LIKE '%post%';
SHOW TABLES FROM mydb;

查询当前用户账户信息
SELECT USER();

查询数据表描述
DESCRIBE people;

创建用户账户信息，完成后要分配权限以生效
INSERT INTO mysql.user(Host,User,Password,ssl_cipher,x509_issuer,x509_subject)
  VALUES("Jimbo","admin",password("123456"),'','','');
  或使用CREATE USER
  CREATE USER 'user'[@'host']
  [IDENTIFIED BY [PASSWORD] 'password'] [, ...]

取得最后插入的记录ID和MS SQL 的SCOPE_IDENTITY()一样
SELECT LAST_INSERT_ID();

使用预定关键字创建用户账户
  CREATE USER root IDENTIFIED BY '12345';

创建用户账户并分配数据访问权限
  CREATE USER 'newuser'@'%' IDENTIFIED BY '12345';
  CREATE DATABASE new_db;
  GRANT SELECT,UPDATE,INSERT,DELETE,CREATE,DROP,ALTER ON new_db.* TO 'new_user'@'%';
  FLUSH PRIVILEGES;

  CREATE USER '2011_grant_01'@'%' IDENTIFIED BY '2011_grant_01';
  CREATE DATABASE 2011_grant_01;
  GRANT CREATE,SELECT,UPDATE,INSERT,DELETE ON 2011_grant_01.* TO '2011_grant_01'@'%';
  FLUSH PRIVILEGES;

  要将数据库的所有权限请使用：
  GRANT ALL [PRIVILEGES] ON 2011_grant_01.* TO '2011_grant_01'@'%';

  //some problems
  CREATE USER `new_user`@`%` IDENTIFIED BY `12345`; --trouble from _ which will make new_user to be another user what is keyword!
  GRANT ALL PRIVILEGES ON new_db.* TO 'new_user'@'%' IDENTIFIED BY '12345' WITH GRANT OPTION; --trouble from ALL
 
  SHOW GRANTS FOR '2011_grant_01'@'%';

打印权限
  SHOW GRANTS FOR 'new_user'@'%';
收回权限
  REVOKE ALL ON *.* FROM 'new_user'@'%';
  REVOKE SELECT,INSERT,UPDATE,DELETE,CREATE ON 2011_grant_01.* FROM '2011_grant_01'@'%';

分配全部权限或分配部分权限，并刷新
  --GRANT SELECT ON databasename.* TO ‘username’@'%’ IDENTIFIED BY ‘password’ WITH grant option;
  GRANT ALL PRIVILEGES ON people.* TO admin@jimbo IDENTIFIED BY '1234';
  GRANT SELECT,UPDATE on phplampDB.* TO admin@jimbo IDENTIFIED BY '1234';
  FLUSH PRIVILEGES;
  权限分配按等级可以分为
  1. Global level 
    GRANT ALL ON *.* TO 'someuser'@'somehost';
    GRANT SELECT, INSERT ON *.* TO 'someuser'@'somehost';

  2. Database level 
    GRANT ALL ON mydb.* TO 'someuser'@'somehost';
    GRANT SELECT, INSERT ON mydb.* TO 'someuser'@'somehost';

  3. Table level 
    GRANT ALL ON mydb.mytbl TO 'someuser'@'somehost';
    GRANT SELECT, INSERT ON mydb.mytbl TO 'someuser'@'somehost';

  4.Column level 
    GRANT SELECT (col1), INSERT (col1,col2) ON mydb.mytbl TO 'someuser'@'somehost';

  5.Routine level 
    GRANT CREATE ROUTINE ON mydb.* TO 'someuser'@'somehost';
    GRANT EXECUTE ON PROCEDURE mydb.myproc TO 'someuser'@'somehost';


设置用户远程登录(主机字段设置为%)
UPDATE mysql.user SET host='%' WHERE user='root';

删除用户
  USE mysql;
  DELETE FROM user WHERE User="admin" and Host="jimbo";
  FLUSH PRIVILEGES;
  或：
  DROP USER 'new_user'@'%';

修改用户密码
SET PASSWORD FOR 'root'@'%.localhost' = PASSWORD('12345@abc');
UPDATE mysql.user SET password=password('新密码') WHERE User="admin" and Host="jimbo";
FLUSH PRIVILEGES;

误删管理帐户还原处理
在my.ini文件中启用 skip-grant-tables 选项来登录，这样可以省略验证过程。
  [mysqld]
  skip-grant-tables
并执行下SQL语句之一:
  insert into mysql.user set Host='%',User='root',Password=Password('12345'),select_priv='y', insert_priv='y',update_priv='y', Alter_priv='y',delete_priv='y',create_priv='y',drop_priv='y',reload_priv='y',shutdown_priv='y',Process_priv='y',file_priv='y',grant_priv='y',References_priv='y',index_priv='y',create_user_priv='y',show_db_priv='y',super_priv='y',create_tmp_table_priv='y',Lock_tables_priv='y',execute_priv='y',repl_slave_priv='y',repl_client_priv='y',create_view_priv='y',show_view_priv='y',create_routine_priv='y',alter_routine_priv='y',x509_issuer='',x509_subject='',ssl_cipher='';
  INSERT INTO mysql.user VALUES ('%','root',password('12345'),'Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','N','N','','','','',0,0,0,0);
最后设置grant option权限
  GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '12345' WITH GRANT OPTION;

创建数据库及删除
CREATE DATABASE pubs;
ALTER DATABASE pubs CHARACTER SET 'utf8';
CREATE DATABASE pubs CHARACTER SET 'utf8';
DROP DATABASE pubs;

创建表格及删除
USE pubs;
CREATE TABLE people (id int NOT NULL, name varchar(24));
INSERT people VALUE(0, 'Jimbo');
DROP TABLE people;

修改表格，加唯一标识
ALTER TABLE people ADD UNIQUE(id);

设置连接时的字符集
SET NAMES 'charset_name'
SET CHARACTER SET charset_name


打开skip-grant-tables选项后
要使用mysqladmin flush-privileges password '***'命令形式来更新密码表。
This doesn't work, Performing what is suggested results in:

mysqladmin: unable to change password; error: 'Can't find any matching row in the user
table'

This is due to anonymous connection. However after that statement is ran, grant checking
is turned on due to the flush privs and the statement will succeed if ran twice,.

字符串转数值排序
select user_id,meta_value from wp_usermeta where meta_key='points' order by CONVERT(meta_value,DECIMAL) desc INTO OUTFILE 'c:\\www\\database\\toppoints.txt';

随机排序
SELECT * FROM tbl_name ORDER BY RAND();


联合查询
SELECT user_id,meta_value,user_login,display_name 
  FROM wp_usermeta AS um left join wp_users as u 
  on um.user_id=u.ID 
  WHERE meta_key='points' 
  ORDER BY um.meta_value DESC 
  LIMIT 9,10;

GROUP BY与COUNT统计，分组与分组函数应用
  SELECT *, COUNT(*) AS post_count FROM wp_posts 
  WHERE post_status='publish' AND post_type='post' GROUP BY post_author;
  SUM函数可以用来求字段值总和，与COUNT求总记录数含义不同。注意MySQL中*, COUNT(*)顺序不可以逆转。
  如果要判断分组后的状态条件请用HAVING从句，如post_author出现超过2次(含2次):
  SELECT *, COUNT(*) AS post_count FROM wp_posts 
  WHERE post_status='publish' AND post_type='post' GROUP BY post_author;
  HAVING COUNT(*)>2;

  使用COUNT(*)后，返回结果只有一个总计记录，
  SELECT *,COUNT(*) as amonunting FROM wp_usermeta WHERE meta_key='register_state' and meta_value like CONCAT('%(',1096,')%')  ;
  可以通过GROUP BY来强制时行记录分组，并返回各组记录：
  SELECT *,COUNT(*) as amonunting FROM wp_usermeta WHERE meta_key='register_state' and meta_value like CONCAT('%(',1096,')%')  group by meta_value;
  注意分组函数只能用于原有字段的操作，而不能用于分组函数生成的新字段，如COUNT(*) as amonunting，就不可以使用MAX(amounting)。
  要使用分组函数生成的字段，请在HAVING子句后添加：
  SELECT *,COUNT(*) as amonunting FROM wp_usermeta WHERE meta_key='register_state' and meta_value like CONCAT('%(',1096,')%')  group by meta_value having amonunting>8;
  
  为了统计上面返回记录数，要另嵌套SELECT语句：
  SELECT count(*) FROM
  (SELECT COUNT(*) as amonunting 
    FROM wp_usermeta WHERE meta_key='register_state' and meta_value like CONCAT('%(',1096,')%')
    GROUP BY meta_value HAVING amonunting>8
  );
  如果就这样执行，MySQL就不爽了，临时表没有名字是处理不了的：
  [Err] 1248 - Every derived table must have its own alias
  要给它加上临时表名：
  SELECT count(*) FROM
  (SELECT COUNT(*) as amonunting 
    FROM wp_usermeta WHERE meta_key='register_state' and meta_value like CONCAT('%(',1096,')%')
    GROUP BY meta_value HAVING amonunting>8
  ) AS temp_table;


  考虑下面这个复杂嵌套语句：如何将ID传参一样设置到1096这个位置呢？
  SELECT ID, meta_value
  FROM wp_usermeta wum LEFT JOIN wp_user wu ON wu.id=wum.user_id 
  WHERE date_format(user_registered,@fm)<date_format(@dt,@fm) AND meta_key='register_state' AND
    (
    SELECT count(*) FROM
    (SELECT COUNT(*) as amonunting 
      FROM wp_usermeta WHERE meta_key='register_state' and meta_value like CONCAT('%(',1096,')%')
      GROUP BY meta_value HAVING amonunting>8
    ) AS temp_table
    );
  
  可以考虑使用临时处理：
  set @fm = '%Y%m%d %H:%i:%s';
  set @dt = '2011-07-21 00:00:00';

  SELECT ID, meta_value, count(*) as C FROM
  (
  SELECT ID, meta_value
  FROM wp_usermeta wum LEFT JOIN wp_users wu ON wu.id=wum.user_id 
  WHERE date_format(user_registered,@fm)<date_format(@dt,@fm) AND meta_key='register_state' AND meta_value NOT LIKE '%point_for:()%'
  ) as T1 GROUP BY meta_value;


通过结果集来建表
  create table T2 select * from T1;
　和SQL Server不同：select * into T2 from T1;
  这里T2不是一个存在的表。

使用SELECT INTO OUTFILE导出查询结果到文件(注意正斜杠表达,并且导出的数据在服务器端的哦)
  SELECT host, user from user INTO OUTFILE 'c:/www/data.txt';
  SELECT host, user from user INTO OUTFILE 'c:\\www\\data.txt';

  select user_id,meta_value from wp_usermeta where meta_key='register_state'  order by meta_value  INTO OUTFILE 'c:\\www\\database\\tricky.txt';
  select user_id,user_login,meta_value from wp_usermeta wum left join wp_users wu on user_id=id where meta_key='points' order by CONVERT(meta_value,DECIMAL) desc INTO OUTFILE 'c:\\www\\database\\toppoints.txt';
  select * from wp_users order by ID desc INTO OUTFILE 'c:\\www\\database\\users.txt';
  select id,user_login,user_email,user_registered from wp_users order by ID desc INTO OUTFILE 'c:\\www\\database\\users.txt';
  
  select umeta_id, meta_value from wp_usermeta where meta_key='register_state' into outfile 'C:\\Users\\acer\\Documents\\Navicat\\MySQL\\servers\\localhost_3306\\deepsleep\\user_meta.sql';

利用OUTFILE导出批量删除表的SQL语句
  use information_schema;
  select concat('DROP TABLE IF EXISTS ',table_name,';') 
  from TABLES 
  where table_schema='2011_grant_01' into outfile 'c:/table.txt';
  当然每次只drop一个表，太蜗牛了，一次可以drop a,b,c多个表
  甚至DROP TABLE IF EXISTS a,b,c都可以;

使用mysqlhotcopy脚本命令备份数据库(通过拷贝*.frm, *.MYD, and *.MYI备份)
mysqlhotcopy db_name /path/to/some/dir

使用mysqldump命令备份数据库或表到文件
mysqldump -u root -p mysql user > user_table.sql
--('Jimbo','admin','*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9'......),

mysqldump --single-transaction --all-databases > backup_sunday_1_PM.sql

mysqldump支持的文件格式：
  --xml Produce XML output  
  --tab=path Produce tab-separated data files  
  --result-file=file Direct output to a given file  

机器间复制数据库
  1. The easiest (although not the fastest) way：
  shell> mysqladmin -h 'other_hostname' create db_name
  shell> mysqldump --opt db_name | mysql -h 'other_hostname' db_name
  
  2. From a remote machine over a slow network: 
  shell> mysqladmin create db_name
  shell> mysqldump -h 'other_hostname' --opt --compress db_name | mysql db_name

  3. Dump database and gzip it: 
  shell> mysqldump --quick db_name | gzip > db_name.gz
  Transfer it to the target machine: 
  shell> mysqladmin create db_name
  shell> gunzip < db_name.gz | mysql db_name

  mysqldump -uroot -p12345 -q media_dream --result-file="C:\MySQL Datafiles\midea_dream.sql"

  4. Use mysqlimport and mysqldump:
  shell> mkdir DUMPDIR
  shell> mysqldump --tab=DUMPDIR db_name
  Then transfer data to the target machine: 
  shell> mysqladmin create db_name           # create database
  shell> cat DUMPDIR/xxx.sql | mysql db_name   # create tables in database
  shell> mysqlimport db_name DUMPDIR/xxx.txt   # load data into tables



利用SQL脚本还原数据库，如果每条INSERT语句只插入一个记录，不是很高效哦！
mysql < backup.sql
mysql -uroot -p12345 mydatabase < backup.sql
或在mysql命令中输入：
mysql> backup.sql


使用mysqladmin重设用户密码(输入原有密码即可完成设置)
mysqladmin -u root -p flush-privileges password "newpassword" 

使用LOAD DATA INFILE导入文件记录，对应SELECT INTO OUTFILE导出文件，
记录以tab分隔，而记录内容中的tab或\以\转义，
  LOAD DATA INFILE 'c:/data.txt' INTO TABLE T1;

读入文件
  select load_file("PATH_TO_FILE"); 

设置主键或取消(联合主键和唯一主键)
  alter table T1 ADD PRIMARY KEY(host, user),UNIQUE KEY `uk_option_name` (`option_name`);
  alter table T1 DROP PRIMARY KEY(host, user);

使用limit关键字来分页
  select * from T1 limit 10,20 ;

查询记录，使用limit代替top
SELECT * FROM people LIMIT 1,2; --选出1号记录后的2个记录(即第一条为0号，后跟的两条记录)

统计某字段相同的记录
SELECT id, count(id) as c  FROM `cms_information` group by id having c>1 ;

多表操作，同步删除无对应外键的记录(wordpress)
delete from `wp_postmeta` where not exists 
	(select * from `wp_posts` where `wp_postmeta`.`post_id`=`wp_posts`.`id`);

mysql 日期比较，注意两日期表达格式要一致，这是因为要做字符串运算
  SET @fm = '%Y%m%d %H:%i:%s';
  SET @dt = '2011-07-08 00:00:00';
  SELECT date_format(@dt, @fm);
  SELECT COUNT(*) AS USER_COUNT FROM wp_users WHERE date_format(user_registered,@fm)>date_format(@dt,@fm);

  select * from tb where c> date_format(@dt,@fm);
  select * from tb where c> date_format(curdate()-1,@fm);
  select * from tb where c> date('2007-07-07') and c< date('2007-07-09')

正则提取字符串


存储过程示例１ 信息维度与联合查询
联合查询与存储过程，首先注意联合查询的两种语法风格：
  SELECT * FROM t1 
    LEFT JOIN (t2, t3, t4) 
    ON (t2.a=t1.a AND t3.b=t1.b AND t4.c=t1.c)
  
  或者：
  SELECT * FROM a JOIN b 
    LEFT JOIN c ON (c.key=a.key) 
    LEFT JOIN d ON (d.key=a.key)
  WHERE b.key=d.key;

  //开始存储过程
  DROP PROCEDURE IF EXISTS viewBookerMeta;
  DELIMITER //
  CREATE PROCEDURE viewBookerMeta()
  BEGIN
    SELECT post_id, post_date, meta_value FROM wp_postmeta AS a 
        LEFT JOIN (
          wp_term_relationships AS b, 
          wp_term_taxonomy AS c, 
          wp_terms AS d,
          wp_posts AS e
        )
        ON (
          e.ID=a.post_id AND a.post_id=b.object_id AND b.term_taxonomy_id=c.term_taxonomy_id AND c.term_id=d.term_id
        )
    WHERE a.meta_key='表单数据' AND c.taxonomy='category' AND e.post_status='publish' AND (d.name='团购报名' OR d.name='团购预订');
  END;
  //
  DELIMITER ;
  CALL viewBookerMeta();

  输出如：
  Query OK, 0 rows affected

  Query OK, 0 rows affected

  +---------+---------------------+---------------------------------------------------------------------+
  | post_id | post_date           | meta_value                                                          |
  +---------+---------------------+---------------------------------------------------------------------+
  |     861 | 2011-12-01 09:31:33 | 一汽丰田#卡罗拉#2001/1#请填写真实姓名#请填写购车人手机#广州#天河区#|
  |     862 | 2011-12-01 09:32:23 | 广汽本田#雅阁#2001/1#请填写真实姓名#请填写购车人手机#广州#天河区#|
  |     900 | 2011-12-06 06:33:21 | 一汽丰田#卡罗拉#2001/2#叶坚#13399887654#广州#天河区#温馨的爱车！|
  |     932 | 2011-12-07 02:10:05 | 一汽丰田#卡罗拉##叶坚#13610347569#广州##广州客户服务测试|
  |     937 | 2011-12-07 10:51:58 | 上海通用别克#君威##叶坚#13610347569#广州#天河区#     |
  +---------+---------------------+---------------------------------------------------------------------+
  5 rows in set

  Query OK, 0 rows affected

  从输出内容中可以看到，meta_value其实就像和对象绑定的属性数据，只是这里“对象”是wp_posts一维表中的一个记录！
  信息维度的研究和Wordpress的taxonomy分类学密切相关，这里面的联系可以让一个数据系统灵活，也可以让一个数据系统刻板！
  就目前面对的数据结构而言，我的想法是通过函数来分割meta_value来开成二维表以全其具有排序功能，或者通过切割字符串，使用特定区域前置来实现单区或排序，这里mysql就有一个非常合用的函数：
    mysql> SELECT SUBSTRING_INDEX('www.mysql.com', '.', 2);
        -> 'www.mysql'
    mysql> SELECT SUBSTRING_INDEX('www.mysql.com', '.', -2);
        -> 'mysql.com'
  例如要取出"卡罗拉"这个区的数据：
    mysql> SELECT SUBSTRING_INDEX(SUBSTRING_INDEX('一汽丰田#卡罗拉#2001/1#请填写真实姓名#请填写购车人手机#广州#天河区#','#',2),'#',-1) as model;

  组合前面的SQL语句就成这样了：
    SELECT post_id,
      SUBSTRING_INDEX(meta_value,'#',1) as field_brand, 
      SUBSTRING_INDEX(SUBSTRING_INDEX(meta_value,'#',2),'#',-1) as field_model, 
      SUBSTRING_INDEX(SUBSTRING_INDEX(meta_value,'#',3),'#',-1) as field_date, 
      SUBSTRING_INDEX(SUBSTRING_INDEX(meta_value,'#',4),'#',-1) as field_name, 
      SUBSTRING_INDEX(SUBSTRING_INDEX(meta_value,'#',5),'#',-1) as field_tel, 
      SUBSTRING_INDEX(SUBSTRING_INDEX(meta_value,'#',6),'#',-1) as field_city, 
      SUBSTRING_INDEX(SUBSTRING_INDEX(meta_value,'#',7),'#',-1) as field_area 
    FROM wp_postmeta AS a 
    WHERE a.meta_key='表单数据' ORDER BY field_date;

  出来数据也整整齐齐：
  +---------+--------------+-------------+------------+----------------+------------------+------------+------------+
  | post_id | field_brand  | field_model | field_date | field_name     | field_tel        | field_city | field_area |
  +---------+--------------+-------------+------------+----------------+------------------+------------+------------+
  |     937 | 上海通用别克| 君威      |            | 叶坚         | 13610347569      | 广州     | 天河区  |
  |     861 | 一汽丰田  | 卡罗拉   | 2001/1     | 请填写真实姓名| 请填写购车人手机| 广州     | 天河区  |
  |     862 | 广汽本田 | 雅阁      | 2001/1     | 请填写真实姓名| 请填写购车人手机| 广州     | 天河区  |
  |     900 | 一汽丰田 | 卡罗拉   | 2001/2     | 叶坚         | 13399887654      | 广州     | 天河区  |
  |     902 | 一汽丰田 | 卡罗拉   | 2001/2     | 叶坚         | 13399887654      | 广州     | 天河区  |
  |     845 | 东风本田 | CR-V        | 2002/4     | KF             | 13610347569      | 广州     | 天河区  |
  |     915 | 广汽本田 | 雅阁      | 2007/8     | 叶坚         | 13610347569      | 广州     | 天河区  |
  +---------+--------------+-------------+------------+----------------+------------------+------------+------------+
  7 rows in set

  分隔符内容更新
  set @old='<>';
  set @new='#';
  update wp_postmeta set meta_value=REPLACE(meta_value,@old,@new) where meta_value like concat('%',@old,'%');

  直接导出CSV：
  SELECT CONCAT(post_id,',',post_date,',',Replace(Replace(meta_value,',','，'),'#',',')) AS fields
  FROM wp_postmeta AS a LEFT JOIN wp_posts AS b ON a.post_id=b.ID
  WHERE a.meta_key='表单数据' AND b.post_status='publish' AND b.post_type='post' AND b.post_date>date('2011-12-5') AND b.post_date<date('2011-12-11') ORDER BY fields;
  
  日期可以这样子吗?： AND b.post_date BETWEEN date('2011-12-5') AND date('2011-12-9')
  SELECT CONCAT(post_id,',',post_date,',',Replace(Replace(meta_value,',','，'),'#',',')) AS fields
  FROM wp_postmeta AS a LEFT JOIN wp_posts AS b ON a.post_id=b.ID
  WHERE a.meta_key='表单数据' AND b.post_status='publish' AND b.post_type='post' AND b.post_date BETWEEN date('2011-12-5') AND date('2011-12-9') ORDER BY fields;
  OK，两个都可以实现，处理日期时要注意日期使用的格式一致时，字串的比较才是有意义的！
  


存储过程示例2 postmeta键列表
  #先清除旧存储过程，否则定义无效
  DROP PROCEDURE IF EXISTS viewPostMetaKey;
  DELIMITER //
  CREATE PROCEDURE carcar.viewPostMetaKey()
  BEGIN
    SELECT DISTINCTROW meta_key FROM wp_postmeta 
    WHERE meta_key='表单数据';
  END;
  //
  DELIMITER ;
  CALL viewPostMetaKey();

存储过程示例3 postmeta键列表与导出参数
  #先清除旧存储过程，否则定义无效
  DROP PROCEDURE IF EXISTS viewFormCount;
  DELIMITER //
  CREATE PROCEDURE carcar.viewFormCount(OUT _count INT)
  BEGIN
    SELECT count(meta_key) INTO _count FROM wp_postmeta 
    WHERE meta_key='表单数据';
  END;
  //
  DELIMITER ;
  CALL viewFormCount(@count);
  SELECT @count;

  输出内容如：
  Query OK, 0 rows affected

  Query OK, 0 rows affected

  Query OK, 0 rows affected

  +--------+
  | @count |
  +--------+
  |     18 |
  +--------+
  1 row in set


mysql中的存储过程和存储函数总称为存储事务，
A stored routine is either a procedure or a function. Stored routines are created with CREATE PROCEDURE and CREATE FUNCTION statements.

手册中的——传出参数完整示例：
  mysql> delimiter //

  mysql> CREATE PROCEDURE simpleproc (OUT param1 INT)
      -> BEGIN
      ->   SELECT COUNT(*) INTO param1 FROM t;
      -> END;
      -> //
  Query OK, 0 rows affected (0.00 sec)

  mysql> delimiter ;

  mysql> CALL simpleproc(@a);
  Query OK, 0 rows affected (0.00 sec)

  mysql> SELECT @a;
  +------+
  | @a   |
  +------+
  | 3    |
  +------+
  1 row in set (0.00 sec)


  基本语法
  create procedure sp_name()
  begin
    ......
  end
  
  区块定义可以起别名，如：
  lable:begin
  ...........
  end lable;
  可以用leave lable;跳出区块，执行区块以后的代码

  调用存储过程 call sp_name()
  注意：存储过程名称后面必须加括号，哪怕该存储过程没有参数传递!

  删除存储过程
  drop procedure sp_name//
  注意不能在一个存储过程中删除另一个存储过程，只能调用另一个存储过程!

  条件语句
  if 条件 then
    statement
  else
    statement
  end if;

  while循环语句
  [label:] WHILE expression DO
    statements
  END WHILE [label] ;

  loop循环
  [label:] LOOP
    statements
  END LOOP [label];

  repeat until循环
  [label:] REPEAT
    statements
    UNTIL expression
  END REPEAT [label] ;

  常用命令
  1.show procedure status
  显示数据库中所有存储的存储过程基本信息，包括所属数据库，存储过程名称，创建时间等
  2.show create procedure sp_name
  显示某一个存储过程的详细信息


多表并联查询
SELECT * FROM CMS_Information AS a LEFT JOIN CMS_Category as b on a.PARENTID=b.ID
   WHERE a.parentid IN (select id from CMS_Category WHERE parentid=10002) 
  AND a.status=1 ORDER BY a.ordernum DESC, a.id DESC 
等价：
SELECT * FROM CMS_Information WHERE parentid IN (select id from CMS_Category WHERE parentid=10002) 
  AND status=1 ORDER BY ordernum DESC, id DESC 



临时表与记录复制
  1、复制表结构及数据到新表
  CREATE TABLE T1 SELECT * FROM T2
  这种方法会将oldtable中所有的内容都拷贝过来，当然我们可以用delete from newtable;来删除。
  不过这种方法的一个最不好的地方就是T1中没有了T2的primary key、Extra（auto_increment）等属性。需要自己用alter添加，而且容易搞错。


  2、只复制表结构到T1
  CREATE TABLE T1 SELECT * FROM T2 WHERE 1=2
  CREATE TABLE T1 LIKE T2


  3、复制T2的数据到T1(假设两个表结构一样)
  INSERT INTO T1 SELECT * FROM T2


  4、复制T2的数据到T1(假设两个表结构不一样)
  INSERT INTO T1(字段1,字段2,.......) SELECT 字段1,字段2,...... FROM T2


  5、可以将T1结构复制到T2
  SELECT * INTO T2 FROM T1 WHERE 1=2


  6、可以将T1内容全部复制到T2
  SELECT * INTO T2 FROM T1


  7、show create table T2;
  这样会将T2的创建命令列出。我们只需要将该命令拷贝出来，更改table的名字，就可以建立一个完全一样的表


  8、mysqldump
  用mysqldump将表dump出来，改名字后再导回去或者直接在命令行中运行 

  复制完全相同的记录(条件是表结构中没有自增auto_increment,和uniq(PRIMARY KEY)字段）
  INSERT INTO t SELECT * FROM t WHERE c=1;
  发生主键冲突时用： ON DUPLICATE KEY UPDATE c=c+1;

  调用存储过程进行复制
  DROP PROCEDURE IF EXISTS `copy_from`;

  CREATE DEFINER = `root`@`%` PROCEDURE `copy_from`(IN `origin` int,IN `target` int)
  BEGIN
    #Routine body goes here...
    DROP TABLE IF EXISTS `copy_tmp`;
    CREATE TABLE copy_tmp SELECT * FROM cms_information WHERE PARENTID=origin;
    UPDATE copy_tmp set parentid=target;
    INSERT INTO cms_information SELECT * FROM copy_tmp ON DUPLICATE KEY UPDATE cms_information.id=cms_information.id+5;
  END;


