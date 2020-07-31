# This is the Gnu makefile for the PopPad program found
# on p. 633 of the book "Programming Windows Fifth Edition"
# by Charles Petzold.

# John Kopplin   www.computersciencelab.com

PROGRAM = PopPad.exe


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

# Gnu make's pattern rules are extraordinarily sensitive to the
# case of the filenames.  For an unknown reason, the MS-DOS names
# of the PopPad.rc file is POPPAD.RC even though this file appears
# as Poppad.rc when viewed with Windows Explorer.  You not only need
# to use this capitalization when defining the OBJS macro but you
# must also provide a pattern rule for .RC (as opposed to .rc) files.

SRCS = $(SRCDIR)/PopPad.c \
       $(SRCDIR)/PopFile.c \
       $(SRCDIR)/PopFind.c \
       $(SRCDIR)/PopFont.c \
       $(SRCDIR)/PopPrnt.c \
       $(SRCDIR)/POPPAD.rc

OBJS = $(ODIR)/PopPad.o \
       $(ODIR)/PopFile.o \
       $(ODIR)/PopFind.o \
       $(ODIR)/PopFont.o \
       $(ODIR)/PopPrnt.o \
       $(ODIR)/POPPAD.res

HDRS = $(SRCDIR)/Resource.h \
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

$(ODIR)/%.res : %.RC $(HDRS) $(ODIR)
	$(WRES) --use-temp-file -O coff $< $@

$(ODIR)/%.res : %.rc $(HDRS) $(ODIR)
	$(WRES) --use-temp-file -O coff $< $@

$(ODIR)/%.o : %.cpp $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR)/%.o : %.c $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR):
	mkdir $@
