set lib=lib/commons-logging-1.2.jar;lib\spring-aop.jar;lib\spring-aspects.jar;lib\spring-beans.jar;lib\spring-context-indexer.jar;lib\spring-context-support.jar;lib\spring-context.jar;lib\spring-core.jar;lib\spring-expression.jar;lib\spring-instrument.jar;lib\spring-jdbc.jar;lib\spring-orm.jar;lib\spring-test.jar;lib\spring-tx.jar;lib\spring-web.jar;lib\spring-webflux.jar;lib\spring-webmvc.jar;lib\spring-websocket.jar

if [%1]==[run] goto run

javac -d . src\com\coding\HelloBean.java
javac -d . -cp %lib% src\com\coding\HelloBean.java
javac -d . -cp %lib% src\com\coding\HelloListener.java

:run

java -cp . -Xbootclasspath/a:%lib% com.coding.SpringDemo
