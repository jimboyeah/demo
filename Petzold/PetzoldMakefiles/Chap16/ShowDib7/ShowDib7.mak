# This is the Gnu makefile for the ShowDib7 program found
# on p. 902 of the book "Programming Windows Fifth Edition"
# by Charles Petzold.

# John Kopplin   www.computersciencelab.com

PROGRAM = ShowDib7.exe


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

SRCS = $(SRCDIR)/ShowDib7.c \
       ../ShowDib3/PackeDib.c \
       $(SRCDIR)/ShowDib7.rc

OBJS = $(ODIR)/ShowDib7.o \
       $(ODIR)/PackeDib.o \
       $(ODIR)/ShowDib7.res

HDRS = ../ShowDib3/PackeDib.h \
       $(SRCDIR)/Resource.h \
       $(SRCDIR)/afxres.h

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

# Petzold employs files from the ShowDib3 project for this ShowDib7 project.

$(ODIR)/%.o : ../ShowDib3/%.c $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<
