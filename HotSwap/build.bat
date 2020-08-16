javac -d bin -cp main\java\ -encoding utf-8 main\java\Hot.java
javac -d bin -cp main\java\ -encoding utf-8 main\java\HotSwapURLClassLoader.java
javac -d bin -cp main\java\ -encoding utf-8 main\java\MonitorHotSwap.java
javac -d bin -cp main\java\ -encoding utf-8 main\java\TestHotSwap.java
cd bin && jar -cvfm demo.jar ..\MANIFEST.MF *
rem java -jar demo.jar
rem java -Xbootclasspath/a:demo.jar;some2.jar; -jar demo.jar
cd ..
