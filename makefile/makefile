#
#  GNU makefile demo by Jimbowhy @ 2016/2/28 1:57:22
#

CC=g++
OLIB=-o libsp.so
ifeq "$(MAKECMDGOALS)" "libsp.dll"
CFLAGS=-DBUILD_DLL
OLIB:=-o libsp.lib
endif

#$(info $(OLIB))
#$(info $(MAKECMDGOALS))
#$(info $(CFLAGS))

all  : loader main static dynamic libsp.dll libsp.a libsp.so print.o lib.o main.o
	@echo off

loader: 
	g++ -Os -s -o loader.exe loader.c

main : main.c lib.o print.o
	g++ -Os -s -o main.exe print.o lib.o main.c
	@echo 4 $?

libsp.a: print.o lib.o
	ar -crs libsp.a print.o lib.o

libsp.so: print.o lib.o
	g++ -Os -s -shared $(OLIB) print.o lib.o

libsp.dll: libsp.so
	g++ -Os -s -shared -Wl,--out-implib,libsp.lib -o libsp.dll print.o lib.o

static: libsp.a main.c
	g++ -Os -s -o static.exe main.c -L . -lsp

dynamic: libsp.so main.c
	g++ -Os -s -o dynamic.exe main.c -L. -lsp

lib  : lib.c lib.h
	g++ -c $(CFLAGS) lib.c

print: print.c print.h 
	g++ -c print.c

check: anything.c any.d
	@echo 1 $@
	@echo 2 $%
	@echo 3 $<
	@echo 4 $?
	@echo 5 $^
	@echo 6 $+
	@echo 7 $|
	@echo 8 $*
	@echo $(var)

anything.c any.d:
	
clean:
	del *.o
	del *.a
	del *.so
	del *.exe
