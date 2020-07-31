# This is the Gnu makefile for the Emf9 program found
# on p. 1160 of the book "Programming Windows Fifth Edition"
# by Charles Petzold.

# John Kopplin   www.computersciencelab.com

PROGRAM = Emf9.exe


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

SRCS = $(SRCDIR)/Emf9.c \
       ../Emf8/Emf.c \
       ../Emf8/Emf.rc

OBJS = $(ODIR)/Emf9.o \
       $(ODIR)/Emf.o \
       $(ODIR)/Emf.res

HDRS = ../Emf8/Resource.h \
       ../Emf8/afxres.h

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

# Petzold employs files from the Emf8 project in this Emf9 project.

$(ODIR)/%.o : ../Emf8/%.c $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR)/%.res : ../Emf8/%.rc $(HDRS) $(ODIR)
	$(WRES) --use-temp-file -O coff $< $@
