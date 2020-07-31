Readme file for GNU Chess 4.14 for Windows, June 16, 1997

GNU Chess is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Chess is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Chess; see the file COPYING.TXT.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

This is a port of GNU Chess to the Win32 environment. The program requires
Windows 3.1 or later and a 386 or higher processor. To run it under
Windows 3.1 requires the Win32s 32-bit extender, which is available free
from many FTP sites including ftp.microsoft.com in
Softlib/MSLFILES/PW1118.exe. Win32s is not required and should not be
installed on Windows 95 systems. If GNU Chess will not run in Windows 3.1,
it is probably because Win32s has not been successfully installed. A 32-bit
version which runs under Windows 3.1 without Win32s will probably be
available shortly.

In Windows 95, you can add a shortcut to the start menu by opening Windows
Explorer, clicking on gnuchess.exe, selecting Create Shortcut under the File
menu, and moving the shortcut into the Windows/Start Menu/Programs folder, or
a subfolder of it.

Change from version 4.13:

- Fixed a bug which prevented use of the book file.

Change from version 4.12:

- Fixed an error in gnuchess.lan which incorrectly referred to the bookfile
  as gnuchess.boo

Changes from version 4.11:

- The program is now compiled with Watcom C, with speed optimisations for
  Pentium processors. The file CW3215.DLL is no longer required.

- Fixed a bug in the loading of saved games which caused pieces to disappear
  after castling in the Review Game function. (This bug is in the original
  character mode version of GNU Chess, where its effect is much less likely
  to be noticed).

- Fixed a bug which caused the next move to go to the other player if an
  illegal move was selected in Force mode.

- The clocks stop when checkmate is reached. "Checkmate" is displayed instead
  of whose move it is.

- The hint is cleared after Undo (to prevent an illegal move being displayed).

- The filename for the List function can be chosen.

- The clocks are initialised when the game is run.

- The dialog backgrounds are now colored according to the Windows color
  scheme set in the Color control panel.

The package should contain the following files:

    GNUCHESS.EXE     Executable file
    GNUCHESS.DAT     Opening book file (not essential)
    GNUCHESS.HLP     Windows Help file
    GNUCHESS.LAN     File of string constants
    README.TXT       This file

  \DOC   
    ARTICLE.TXT      Article on GNU Chess by Stuart Cracraft
    ARTICLE2.TXT     "GNU Chess: Experiences learned with communal sharing"
                     by Stuart Cracraft
    COPYING.TXT      GNU general public license
    HEURIST.TXT      Description of GNU Chess's heuristics
    MOVE_GEN.TXT     Description of GNU Chess's move generation algorithm
    WINPORT.TXT      Notes on the windows port

  \SRC Source code (not essential - you can delete it if you don't want it)
    ATAKS.C
    ATAKS.H
    BOOK.C
    DIALOGS.C
    DSPCOM.C
    EVAL.C
    GENMOVES.C
    GNUCHESS.H
    GNUCHESS.HPJ  Help project file
    GNUCHESS.ICO
    GNUCHESS.RC
    GNUCHESS.RTF  Help source
    INIT.C
    MAIN.C
    SEARCH.C
    TTABLE.C
    TTABLE.H
    VERSION.H
    WINDSP.C
    Six bitmaps per piece (total 36), eg for the bishop:
    B40D.BMP   40x40 detail
    B40M.BMP   40x40 mask
    B60D.BMP   60x60 detail
    B60M.BMP   etc
    B80D.BMP
    B80M.BMP

Please report bugs or suggestions to:

        bug-gnu-chess@prep.ai.mit.edu.

Have a great GNUchess game!

The team:

        Conor McCarthy
        Stuart Cracraft
        John Stanback
