# This is the Gnu makefile for the Record2 program found
# on p. 1312 of the book "Programming Windows Fifth Edition"
# by Charles Petzold.

# John Kopplin   www.computersciencelab.com

PROGRAM = Record2.exe


ifndef WINE
CC      = gcc
WRES    = windres
else
CC      = winegcc
WRES    = wrc
endif

ifdef DEBUG
ODIR    = Debug
CFLAGS  = -g -D_DEBUG -mno-cygwin
else
ODIR    = Release
CFLAGS  = -mno-cygwin
endif

SRCDIR  = .
LIBDIRS =
INCDIRS =
LIBS    = -mno-cygwin -mwindows -lcomctl32 -lcomdlg32 -lwinmm -ladvapi32 -lwinspool

SRCS = $(SRCDIR)/Record2.c \
       ../Record1/Record.rc

OBJS = $(ODIR)/Record2.o \
       $(ODIR)/Record.res

HDRS = ../Record1/Resource.h \
       ../Record1/afxres.h

ALLOBJS  = $(OBJS)
ALLBIN   = $(ODIR)/$(PROGRAM)




all: $(ODIR)/$(PROGRAM)

cleanobjs:
	rm -f $(ALLOBJS)

cleanbin:
	rm -f $(ALLBIN)

clean: cleanobjs cleanbin

cleanall: cleanobjs cleanbin

$(ODIR)/$(PROGRAM): $(OBJS) $(HDRS)
	$(CC) -o $(ODIR)/$(PROGRAM) $(OBJS) $(INCDIRS) $(LIBDIRS) $(LIBS)

$(ODIR)/%.res : %.rc $(HDRS) $(ODIR)
	$(WRES) --use-temp-file -O coff $< $@

$(ODIR)/%.o : %.cpp $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR)/%.o : %.c $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR):
	mkdir $@

# Petzold employs files from the Record1 project in this Record2 project.

$(ODIR)/%.o : ../Record1/%.c $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR)/%.res : ../Record1/%.rc $(HDRS) $(ODIR)
	$(WRES) --use-temp-file -O coff $< $@
