#
#  Demo MySQL with C++ by Jimbowy 2016/3/4 15:42:27
#  GNU makefile demo
#

CC=g++
CFLAGS=-g
LFLAGS=-Wl,--enable-stdcall-fixup

ifdef REBUILD
endif

ifeq "$(BUILD)" "RELEASE"
LFLAGS:=-s $(LFLAGS)
CFLAGS:=
endif

#$(info $(LFLAGS))

INC:=-I"C:\Program Files (x86)\MySQL\MySQL Server 5.1\include"
LIB:=-L"C:\Program Files (x86)\MySQL\MySQL Server 5.1\lib\opt"
LIBS:=-lmysql

all: main.exe codepage.exe main.o
	@echo off

main.exe: main.o
	$(CC) $(LFLAGS) $(INC) $(LIB) -o main.exe $(LIBS) main.o

main.o:
	$(CC) -c $(CFLAGS) -o main.o $(INC) main.cpp

codepage.exe:codepage.cpp

clear:
	@del main.exe main.o codepage.exe codepage.o
