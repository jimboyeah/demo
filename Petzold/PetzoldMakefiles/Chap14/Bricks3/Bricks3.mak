# This is the Gnu makefile for the Bricks3 program found
# on p. 675 of the book "Programming Windows Fifth Edition"
# by Charles Petzold.

# John Kopplin   www.computersciencelab.com

PROGRAM = Bricks3.exe


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

# Petzold has mistakenly spelled the BRICKS3.C filename using all
# capital letters (curiously, Windows won't show you this but
# you can observe it from the DOS prompt).  The Gnu gcc compiler
# believes the .C filename suffix indicates a C++ file and this
# results in the compilation error "undefined reference to
# _gxx_personality_v0".  Fortunately we can solve this problem
# by adding "-x c" to the gcc command line to specify that we
# want the file treated as a C language file.

# The BRICKS3.RC resource filename is similarly spelled using
# only capital letters but the Gnu resource compiler (windres.exe)
# can tolerate this as long as you supply an .RC -> .res pattern rule.

SRCS = $(SRCDIR)/BRICKS3.c \
       $(SRCDIR)/BRICKS3.RC

# Gnu make's pattern rules are extraordinarily sensitive to the
# case of the filenames.  For an unknown reason, the MS-DOS names
# of the Bricks3.c and Bricks3.rc files are BRICKS3.C and BRICKS3.RC
# even though these filenames appear as Bricks3.c and Bricks3.rc
# when viewed with Windows Explorer.  You not only need to use this
# capitalization when defining the OBJS macro but you must also
# provide a pattern rule for .C and .RC (as opposed to .c and .rc)
# files.

OBJS = $(ODIR)/BRICKS3.o \
       $(ODIR)/BRICKS3.res

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

$(ODIR)/%.o : %.c $(HDRS) $(ODIR)
	$(CC) -x c $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR)/%.o : %.c $(HDRS) $(ODIR)
	$(CC) $(CFLAGS) -c $(INCDIRS) -o $@ $<

$(ODIR):
	mkdir $@
