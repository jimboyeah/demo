/*
 * dialogs.c - C source for GNU CHESS
 *
 * Copyright (c) 1996 Conor McCarthy
 * Some code derived from from Chess 3.21 by Daryl Baker
 *
 * This file is part of GNU CHESS.
 *
 * GNU Chess is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * GNU Chess is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Chess; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "gnuchess.h"

char *lpszTitle;
tshort DlgInt1,DlgInt2,DlgInt3,DlgInt4,DlgInt5,DlgInt6;
long size;
extern HBRUSH hDlgBkgrnd;

BOOL CALLBACK ChangeWinDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   BOOL ok;
   switch ( Message )
    {
      case WM_INITDIALOG:
         SetWindowText (hDlg,CP[69]);
         SetDlgItemText (hDlg, IDC_APROMPT, CP[11]);
         SetDlgItemText (hDlg, IDC_BPROMPT, CP[12]);
         SetDlgItemText (hDlg, IDC_XPROMPT, CP[38]);
         SetDlgItemText (hDlg, IDC_WHITE, CP[40]);
         SetDlgItemText (hDlg, IDC_BLACK, CP[41]);
         SetDlgItemInt ( hDlg, IDC_WA, WAwindow, true);
         SetDlgItemInt ( hDlg, IDC_WB, WBwindow, true);
         SetDlgItemInt ( hDlg, IDC_WX, WXwindow, true);
         SetDlgItemInt ( hDlg, IDC_BA, BAwindow, true);
         SetDlgItemInt ( hDlg, IDC_BB, BBwindow, true);
         SetDlgItemInt ( hDlg, IDC_BX, BXwindow, true);
         return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         switch (LOWORD(wParam))
          {
            case IDOK:
               DlgInt1 = GetDlgItemInt (hDlg,IDC_WA,&ok,true);
               if (ok) DlgInt2 = GetDlgItemInt (hDlg,IDC_WB,&ok,true);
               if (ok) DlgInt3 = GetDlgItemInt (hDlg,IDC_WX,&ok,true);
               if (ok) DlgInt4 = GetDlgItemInt (hDlg,IDC_BA,&ok,true);
               if (ok) DlgInt5 = GetDlgItemInt (hDlg,IDC_BB,&ok,true);
               if (ok) DlgInt6 = GetDlgItemInt (hDlg,IDC_BX,&ok,true);
               if (ok) EndDialog ( hDlg, true);
               return true;

            case IDCANCEL:
               EndDialog ( hDlg, false);
               return true;
         }
    }
   return false;
}

BOOL CALLBACK HashDepthDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   BOOL ok;
   switch ( Message )
    {
      case WM_INITDIALOG:
         SetWindowText(hDlg,CP[63]);
         SetDlgItemText (hDlg, IDC_DPROMPT, CP[49]);
         SetDlgItemText (hDlg, IDC_MLPROMPT, CP[29]);
         SetDlgItemInt ( hDlg, IDC_DEPTH, HashDepth, true);
         SetDlgItemInt ( hDlg, IDC_MOVELIM, HashMoveLimit, true);
         return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         switch (LOWORD(wParam))
          {
            case IDOK:
               DlgInt1 = GetDlgItemInt (hDlg,IDC_DEPTH,&ok,true);
               if (ok) DlgInt2 = GetDlgItemInt (hDlg,IDC_MOVELIM,&ok,true);
               if (ok) EndDialog ( hDlg, true);
               return true;

            case IDCANCEL:
               EndDialog ( hDlg, false);
               return true;
         }
    }
   return false;
}

BOOL CALLBACK GetNumDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   BOOL ok;
   switch ( Message )
    {
      case WM_INITDIALOG:
         SetWindowText(hDlg,lpszTitle);
         SetDlgItemText (hDlg, IDC_PROMPT, CP[lParam]);
         SetDlgItemInt ( hDlg, IDC_NUM, DlgInt1, true);
         return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         switch (LOWORD(wParam))
          {
            case IDOK:
               DlgInt1 = GetDlgItemInt (hDlg, IDC_NUM, &ok, true);
               if (ok) EndDialog ( hDlg, true);
               return true;

            case IDCANCEL:
               EndDialog ( hDlg, false);
               return true;
         }
    }
   return false;
}

BOOL CALLBACK AboutDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   switch ( Message )
    {
      case WM_INITDIALOG:
         return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         if (LOWORD(wParam)==IDOK)
           {
             EndDialog ( hDlg, true);
             return true;
           }
    }
   return false;
}

BOOL CALLBACK TimeDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   BOOL ok;
   SHORT tXCmoves,tXCminutes,i;
   switch ( Message )
    {
      case WM_INITDIALOG:
         SetWindowText(hDlg,CP[65]);
         SetDlgItemInt (hDlg, IDC_MOVES1, XCmoves[0],false);
         SetDlgItemInt (hDlg, IDC_MINS1, XCminutes[0], false);
         SetDlgItemInt (hDlg, IDC_MOVES2, XCmoves[1],false);
         SetDlgItemInt (hDlg, IDC_MINS2, XCminutes[1], false);
         SetDlgItemInt (hDlg, IDC_MOVES3, XCmoves[2],false);
         SetDlgItemInt (hDlg, IDC_MINS3, XCminutes[2], false);
         SetDlgItemInt (hDlg, IDC_MAXRT, MaxResponseTime/100, false);
         for (i=0;i<3;i++)
          {
           SendDlgItemMessage(hDlg,IDC_MOVES1+i,CB_ADDSTRING,0,(long)"1");
           SendDlgItemMessage(hDlg,IDC_MOVES1+i,CB_ADDSTRING,0,(long)"10");
           SendDlgItemMessage(hDlg,IDC_MOVES1+i,CB_ADDSTRING,0,(long)"20");
           SendDlgItemMessage(hDlg,IDC_MOVES1+i,CB_ADDSTRING,0,(long)"40");
           SendDlgItemMessage(hDlg,IDC_MOVES1+i,CB_ADDSTRING,0,(long)"60");
           SendDlgItemMessage(hDlg,IDC_MINS1+i,CB_ADDSTRING,0,(long)"5");
           SendDlgItemMessage(hDlg,IDC_MINS1+i,CB_ADDSTRING,0,(long)"15");
           SendDlgItemMessage(hDlg,IDC_MINS1+i,CB_ADDSTRING,0,(long)"30");
           SendDlgItemMessage(hDlg,IDC_MINS1+i,CB_ADDSTRING,0,(long)"60");
           SendDlgItemMessage(hDlg,IDC_MINS1+i,CB_ADDSTRING,0,(long)"600");
          }
         if (!XCmoves[0] || !XCminutes[0])
          { EnableWindow(GetDlgItem(hDlg, IDC_MOVES2),false);
            EnableWindow(GetDlgItem(hDlg, IDC_MOVES3),false);
            EnableWindow(GetDlgItem(hDlg, IDC_MINS2),false);
            EnableWindow(GetDlgItem(hDlg, IDC_MINS3),false);
          }
         else
          { EnableWindow(GetDlgItem(hDlg, IDC_MAXRT),false);
            EnableWindow(GetDlgItem(hDlg, IDC_MRTEXT),false);
            EnableWindow(GetDlgItem(hDlg, IDC_MRSECS),!ok);
            if (!XCmoves[1] || !XCminutes[0])
             { EnableWindow(GetDlgItem(hDlg, IDC_MOVES3),false);
               EnableWindow(GetDlgItem(hDlg, IDC_MINS3),false);
             }
          }
         return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         if (HIWORD(wParam)==CBN_EDITCHANGE||HIWORD(wParam)==CBN_SELCHANGE)
           /*if these messages are processed here, the GetDlgItemInt
             function will retrieve the old value, not the new one*/
             PostMessage(hDlg,WM_USER+100,wParam,0);
         else switch (LOWORD(wParam))
          {
            case IDOK:
               for (i=0;i<3;i++)
                {
                 XCmoves[i]=GetDlgItemInt (hDlg, IDC_MOVES1+i, &ok, false);
                 XCminutes[i]=GetDlgItemInt (hDlg, IDC_MINS1+i, &ok, false);
                }
               XC=0;
               for (i=0;i<3;i++)
                {
                 if (XCmoves[i] && XCminutes[i])XC++;
                 else break;
                }
               if (!XC)
                {
                  MaxResponseTime=GetDlgItemInt (hDlg, IDC_MAXRT,
                                  &ok, false)*100;
                  if (!MaxResponseTime)
                     MaxResponseTime=600;
                  SetTimeControl();
                  EndDialog(hDlg,true);
                }
               else
                {
                  XCmore=0;
                  TimeControl.clock[white] = TimeControl.clock[black] = 0;
                  SetTimeControl();
                  EndDialog ( hDlg, true);
                }
               return true;

            case IDCANCEL:
               EndDialog ( hDlg, false);
               return true;
         }
      case WM_USER+100:
        switch(LOWORD(wParam))
          {
           case IDC_MOVES1:
           case IDC_MINS1:
             tXCmoves=GetDlgItemInt(hDlg,IDC_MOVES1,&ok,false);
             tXCminutes=GetDlgItemInt(hDlg,IDC_MINS1,&ok,false);
             if (!tXCmoves || !tXCminutes)ok=false;
             else ok=true;
             EnableWindow(GetDlgItem(hDlg, IDC_MAXRT),!ok);
             EnableWindow(GetDlgItem(hDlg, IDC_MRTEXT),!ok);
             EnableWindow(GetDlgItem(hDlg, IDC_MRSECS),!ok);
             EnableWindow(GetDlgItem(hDlg, IDC_MOVES2),ok);
             EnableWindow(GetDlgItem(hDlg, IDC_MINS2),ok);
             if (!ok)
              {
               EnableWindow(GetDlgItem(hDlg, IDC_MOVES3),false);
               EnableWindow(GetDlgItem(hDlg, IDC_MINS3),false);
               break;
              }
           case IDC_MOVES2:
           case IDC_MINS2:
             tXCmoves=GetDlgItemInt(hDlg,IDC_MOVES2,&ok,false);
             tXCminutes=GetDlgItemInt(hDlg,IDC_MINS2,&ok,false);
             if (!tXCmoves || !tXCminutes)ok=false;
             else ok=true;
             EnableWindow(GetDlgItem(hDlg, IDC_MOVES3),ok);
             EnableWindow(GetDlgItem(hDlg, IDC_MINS3),ok);
             break;
          }
        return true;
    }
   return false;
}

BOOL CALLBACK StatDlgProc ( HWND hDlg, UINT Message,
                               WPARAM wParam, LPARAM lParam)
{

   switch (Message)
    {
      case WM_INITDIALOG:
         return (true);

#ifdef WIN32
      case WM_CTLCOLORBTN:
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_BTN:
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         if (LOWORD(wParam)==IDOK)
          {
destroy:
            DestroyWindow(hDlg);
            flag.post=false;
            return true;
          }
         break;

      case WM_SYSCOMMAND:
         if ((wParam & 0xFFF0) == SC_CLOSE) goto destroy;
         break;
    }

    return (false);              /* Didn't process a message    */
}

BOOL CALLBACK TypeMoveDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   switch (Message)
    {
     case WM_INITDIALOG:
       SetWindowText(hDlg,szAppName);
       SetDlgItemText(hDlg, IDC_PROMPT, CP[42]);
       SendMessage ( GetDlgItem(hDlg, IDC_NUM), EM_LIMITTEXT, 5, 0);
       return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

     case WM_COMMAND:
       switch (LOWORD(wParam))
         {
          case IDOK:
            if (GetDlgItemText ( hDlg, IDC_NUM, move, 6))
             {
               EndDialog (hDlg, true);
               break;
             }
          case IDCANCEL:
            EndDialog (hDlg, false);
            break;

          default: return false;
         }
       return true;
    }
   return false;
}

BOOL CALLBACK PromoteDlgProc ( HWND hDlg, UINT Message,
                               WPARAM wParam, LPARAM lParam)
{

   switch (Message)
    {
      case WM_INITDIALOG:
         SetWindowText(hDlg,CP[66]);
         DlgInt1 = 5;
         CheckRadioButton ( hDlg, 101, 104, 104);
         return true;

#ifdef WIN32
      case WM_CTLCOLORBTN:
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_BTN:
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         switch (LOWORD(wParam))
          {
            case IDOK:
               EndDialog ( hDlg, DlgInt1);
               return true;

            case 101:
            case 102:
            case 103:
            case 104:
               DlgInt1 = wParam-99;
               CheckRadioButton ( hDlg, 101, 104, LOWORD(wParam));
               return true;
         }
    }
   return (false);               /* Didn't process a message    */
}

BOOL CALLBACK CreateHashDlgProc (HWND hDlg, UINT Message,
                                  WPARAM wParam, LPARAM lParam)
{
   char szsize[7];
   switch ( Message )
    {
      case WM_INITDIALOG:
         SetWindowText(hDlg,CP[67]);
         SetDlgItemText (hDlg, IDC_PROMPT, CP[68]);
         SendDlgItemMessage(hDlg,IDC_HFSIZE,EM_LIMITTEXT,6,0);
         return true;

#ifdef WIN32
      case WM_CTLCOLORSTATIC:
        SetBkMode((HDC)wParam,TRANSPARENT);
      case WM_CTLCOLORDLG:
        return hDlgBkgrnd;
#else
      case WM_CTLCOLOR:
        switch(HIWORD(lParam))
         {
          case CTLCOLOR_STATIC:
           SetBkMode((HDC)wParam,TRANSPARENT);
          case CTLCOLOR_DLG:
           return hDlgBkgrnd;
         }
      return true;
#endif

      case WM_COMMAND:
         switch (LOWORD(wParam))
          {
            case IDOK:
               GetDlgItemText (hDlg,IDC_HFSIZE,szsize,7);
               size = strtol (szsize,0,10);
               EndDialog ( hDlg, true);
               return true;

            case IDCANCEL:
               EndDialog ( hDlg, false);
               return true;
         }
    }
   return false;
}
