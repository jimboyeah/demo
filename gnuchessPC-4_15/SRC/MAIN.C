/*
 * main.c - C source for GNU CHESS for Windows
 *
 * Copyright (c) 1988,1989,1990 John Stanback
 * Copyright (c) 1992-1995 Free Software Foundation
 * Modified by Conor McCarthy for the Windows environment
 * Additions for the Windows version Copyright (c) 1996 Conor McCarthy
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
#ifdef WIN386
 #define INCLUDE_COMMDLG_H
#endif
#include "gnuchess.h"
#ifndef WIN386
 #include <commdlg.h>
#endif
#include "version.h"
#include "ttable.h"
#include <dos.h>
#include <signal.h>
#if defined Think_C && defined Window_Events
#include <console.h>
#endif
CHAR *ColorStr[2];
CHAR *CP[CPSIZE];

UTSHORT ETABLE = DEFETABLE;
CHAR savefile[128] = "";
CHAR listfile[128] = "";
#ifdef HISTORY
UTSHORT history[32768];
#endif
tshort svalue[64];
struct leaf Tree[TREE], *root;
SHORT TrPnt[MAXDEPTH+1];
SHORT PieceList[2][64], PawnCnt[2][8];
SHORT castld[2], Mvboard[64];
struct flags flag;
SHORT opponent, computer, dither;
tshort  WAwindow, WBwindow, WXwindow, BAwindow, BBwindow, BXwindow;
SHORT  INCscore;
long ResponseTime, ExtraTime, MaxResponseTime, et, et0, time0, ft;
unsigned long GenCnt, NodeCnt, ETnodes, EvalNodes;
long replus, reminus;
tshort HashDepth = HASHDEPTH, HashMoveLimit = HASHMOVELIMIT;
SHORT player;
struct GameRec GameList[MAXMOVES + MAXDEPTH];
SHORT Sdepth, Game50, MaxSearchDepth;
SHORT GameCnt = 0;
SHORT epsquare;
tshort  contempt, xwndw;
int Book;
struct TimeControlRec TimeControl;
int TCadd = 0;
SHORT TCflag, TCmoves, TCminutes, TCseconds, OperatorTime;
SHORT XCmoves[3], XCminutes[3], XCseconds[3],XCadd[3], XC, XCmore;
const SHORT otherside[3] =
{black, white, neutral};
SHORT hint;
SHORT TOflag;     /* force search re-init if we backup search */

SHORT mtl[2], pmtl[2], hung[2];
SHORT Pindex[64];
SHORT PieceCnt[2];
SHORT FROMsquare, TOsquare;
SHORT HasKnight[2], HasBishop[2], HasRook[2], HasQueen[2];
SHORT ChkFlag[MAXDEPTH], CptrFlag[MAXDEPTH], PawnThreat[MAXDEPTH];
SHORT QueenCheck[MAXDEPTH]; /* tom@izf.tno.nl */
SHORT NMoves[MAXDEPTH]; /* tom@izf.tno.nl */
SHORT Threat[MAXDEPTH]; /* tom@izf.tno.nl */
SHORT ThreatSave[MAXDEPTH]; /* tom@izf.tno.nl */
SHORT Pscore[MAXDEPTH], Tscore[MAXDEPTH];
const SHORT qrook[3] =
{0, 56, 0};
const SHORT krook[3] =
{7, 63, 0};
const SHORT kingP[3] =
{4, 60, 0};
const SHORT rank7[3] =
{6, 1, 0};
const SHORT sweep[8] =
{false, false, false, true, true, true, false, false};
UTSHORT killr0[MAXDEPTH+1], killr1[MAXDEPTH+1], killr2[MAXDEPTH+1];
UTSHORT PV, SwagHt, Swag0, Swag1, Swag2, Swag4, sidebit;
#ifdef KILLT
tshort killt[0x4000];
#endif
const SHORT value[7] =
{0, valueP, valueN, valueB, valueR, valueQ, valueK};
const SHORT control[7] =
{0, ctlP, ctlN, ctlB, ctlR, ctlQ, ctlK};
SHORT stage, stage2, Developed[2];
unsigned int starttime;
SHORT PCRASH, PCENTER;

char szAppName[]="GNU Chess";
char szChess[]="CHESS";
char szHelpFile[]="gnuchess.hlp";
char move[6];
SHORT command=0;
SHORT LineSpace,SLineSpace,CharWidth,CompColorExt,WhoseTurnExt,
     CompMoveExt,squarebd;
HWND hWnd;
HFONT hFont;
char msg[200];
SHORT selected;
SHORT selectX,selectY;
HANDLE hInst;
HBRUSH hBrushBackGround,hDlgBkgrnd;
HWND hComputerColor,hWhoseTurn,hInCheck,hComputerMove,hClockBlack,
     hClockWhite,hBlack,hWhite,hDepth,hStats;
HACCEL hAccel;
SHORT ok;
DWORD CustCols[16];
CHOOSECOLOR cc;
extern char *lpszTitle;
extern tshort DlgInt1,DlgInt2,DlgInt3,DlgInt4,DlgInt5,DlgInt6;
extern long size;
extern int Znodes;
char szBtnBar[]="btnbar";
extern SHORT button;
extern SHORT WinSizeX,WinSizeY,WinPosX,WinPosY;
extern HWND hBtnWnd;
extern SHORT origbrd[64],origcol[64];
SHORT OrigGameCnt;
extern RECT wr;
extern SHORT maximized,forcing;
BOOL CALLBACK (*lpfnDlgProc)(HWND, unsigned, WORD, LONG);


LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM) ;
LRESULT WINAPI BtnWndProc(HWND, UINT, WPARAM, LPARAM) ;
void SizeWindow(int);
BOOL GetColor(DWORD);
void LoadDefaultColors(void);
BOOL LoadSettings(void);
void SaveSettings(void);
BOOL CALLBACK ChangeWinDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK HashDepthDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK GetNumDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK TimeDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK StatDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK TypeMoveDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PromoteDlgProc (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CreateHashDlgProc (HWND, UINT, WPARAM, LPARAM);

int timeopp[MINGAMEIN], timecomp[MINGAMEIN];
int compptr, oppptr;
inline void
TimeCalc ()
{
/* adjust number of moves remaining in gamein games */
  int increment = 0;
  int topsum = 0;
  int tcompsum = 0;
  int me,him;
  int i;
/* dont do anything til you have enough numbers */
  if (GameCnt < (MINGAMEIN * 2)) return;
/* calculate average time in sec for last MINGAMEIN moves */
  for (i = 0; i < MINGAMEIN; i++)
    {
      tcompsum += timecomp[i];
      topsum += timeopp[i];
    }
  topsum /= (100 * MINGAMEIN);
  tcompsum /= (100 * MINGAMEIN);
/* if I have less time than opponent add another move */
   me = TimeControl.clock[computer]/100; 
   him = TimeControl.clock[opponent]/100;
   if(me < him) increment += 2;
/* if I am > 60 sec behind increment or if I am less and in last 2 min */
   if((him - me) > 60 || (me<him && me < 120))increment++;
/* if I am losing more time with each move add another */
  if ( ((me - him) > 60) && tcompsum < topsum) increment--;
  if ( tcompsum > topsum) increment +=2;
/* if I am doing really well use more time per move */
  else if (me > him && tcompsum < topsum) increment = -1;
  if (me > (him+60) ) increment = -1;
  TimeControl.moves[computer] += increment;
/* but dont let moves go below MINMOVES */
  if (TimeControl.moves[computer] < MINMOVES )TimeControl.moves[computer] = MINMOVES;
}

int PASCAL WinMain (HANDLE hInstance, HANDLE
hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
  WNDCLASS   wndClass;

  if (LoadSettings()) nCmdShow = SW_SHOWMAXIMIZED;
  hBrushBackGround=CreateSolidBrush(clrBackGround);
  hDlgBkgrnd=CreateSolidBrush(GetSysColor(COLOR_BTNFACE));

  wndClass.style        =0;
  wndClass.lpfnWndProc  =WndProc;
  wndClass.cbClsExtra   =0;
  wndClass.cbWndExtra   =0;
  wndClass.hInstance    =hInstance;
  wndClass.hIcon        =LoadIcon(hInstance,szChess);
  wndClass.hCursor      =LoadCursor(NULL,IDC_ARROW);
  wndClass.hbrBackground=0;
  wndClass.lpszMenuName =szChess;
  wndClass.lpszClassName=szAppName;
  if (!RegisterClass(&wndClass))return FALSE;
  wndClass.style=0;
  wndClass.lpfnWndProc=BtnWndProc;
  wndClass.hbrBackground=GetStockObject(LTGRAY_BRUSH);
  wndClass.lpszMenuName=0;
  wndClass.lpszClassName=szBtnBar;
  if (!RegisterClass(&wndClass))return false;

  hInst=hInstance;
  InitConst (0);
  GetMetrics();
  InitScreen();
  hAccel=LoadAccelerators(hInstance,szChess);
  hWnd = CreateWindow(szAppName,szAppName,WS_OVERLAPPEDWINDOW,
             WinPosX,WinPosY,WinSizeX,WinSizeY,NULL,NULL,hInstance,NULL);
  if (!WinSizeX || !WinSizeY) SizeWindow(1);
  ShowWindow(hWnd, nCmdShow);
  CheckMenuItem ( GetMenu(hWnd), boardsize/12+IDM_SMALL, MF_CHECKED);
  CreateStatics();
  {
    long t;        /*rough speed test to calculate Znodes*/
    SHORT i;
    t=GetTickCount();
    while(GetTickCount()-t<250) {Znodes++; for(i=0;i<5000;i++);}
  }
  gsrand (starttime = ((unsigned int) time ((long *) 0)));  /* init urand */
#ifdef ttblsz
  ttblsize = ttblsz;
  rehash = -1;
#endif /* ttblsz */
  ColorStr[0] = CP[40];
  ColorStr[1] = CP[41];
  TCflag = false;

 {
  SHORT i;
  for ( i=pawn; i<=king; i++ )
   {
     pieces[i].detail = LoadBitmap (hInst, MAKEINTRESOURCE(i+boardsize));
     pieces[i].mask = LoadBitmap (hInst, MAKEINTRESOURCE(i+boardsize+6));
   }
 }

  Initialize_dist ();
  Initialize_moves ();
  NewGame ();

  if (flag.post) /*if post is set in the ini file*/
   {
    flag.post=false;
    SendMessage(hWnd,WM_COMMAND,IDM_POST,0L);
   }

  OpenHashFile(); /* Open persistent transposition table */
  while (!(flag.quit))
    {
      oppptr = (oppptr + 1) % MINGAMEIN;
      if (flag.bothsides && !flag.mate && !flag.quit)
       {
        SaveBoard();
        SelectMove (opponent, 1);
        if (flag.abort || command) {command|=0x8000; InputCommand(); }
       }
      else
    InputCommand ();
      if (opponent == black)
   if (flag.gamein || TCadd)
     {
       TimeCalc ();
     }
   else if (TimeControl.moves[opponent] == 0 && TCflag)
     {
       SetTimeControl ();
     }

      compptr = (compptr + 1) % MINGAMEIN;
      if (!(flag.quit || flag.mate || flag.force))
   {
     SaveBoard();
     SelectMove (computer, 1);
     if (computer == black)
       if (flag.gamein)
         {
      TimeCalc ();
         }
       else if (TimeControl.moves[computer] == 0 && TCflag)
         {
      SetTimeControl ();
         }
   }
    }
        CloseHashFile();

  Exit(0);
  return 0;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT Message,
                       WPARAM wParam, LPARAM lParam)
{
  HDC hDC;
  PAINTSTRUCT ps;

  switch(Message)
  { case WM_PAINT:
      hDC=BeginPaint(hWnd,&ps);
      UpdateDisplay(0,0,1,0,hDC);
      if (selected)
       {
         HRGN hRgn;

         hRgn=CreatePolygonRgn(&squares[selectX][selectY][0],
                 4, ALTERNATE);
         InvertRgn(hDC,hRgn);
         DeleteObject(hRgn);
       }
      EndPaint(hWnd,&ps);
      return 0;

    case WM_KEYDOWN:
      switch (wParam)
       {
        case VK_CANCEL:
          flag.timeout=true;
          break;
        case 13:
          if (flag.replay) command=1;
          break;
        case VK_F2:
          if (player==opponent || flag.editing || flag.force)
           {
            lpfnDlgProc = MakeProcInstance ( TypeMoveDlgProc, hInst);
            if (DialogBox ( hInst, MAKEINTRESOURCE(NUMDLG), hWnd,
                lpfnDlgProc))
              {
               command=1;
               if (flag.bothsides && !flag.editing)
                {
                 flag.bothsides=false;
                 flag.abort=flag.timeout=true;
                }
              }
            FreeProcInstance ( lpfnDlgProc);
           }
          else ShowMessage(CP[62]);
          break;
        default: if (flag.editing && wParam>='0' && wParam<='9')
          {
            wParam-='0';
            if (!wParam)wParam=10;
            PostMessage(hBtnWnd,WM_LBUTTONDOWN,0,--wParam*(bmsize+5)+pawn);
          }
         else return 1;
       }
      return 0;

#ifdef WIN32
    case WM_CTLCOLORSTATIC:
      SetTextColor((HDC)wParam,clrText);
      SetBkMode((HDC)wParam,TRANSPARENT);
      return hBrushBackGround;
#else
    case WM_CTLCOLOR:
      switch(HIWORD(lParam))
        {
         case CTLCOLOR_STATIC:
           SetTextColor((HDC)wParam,clrText);
           SetBkMode((HDC)wParam,TRANSPARENT);
           return hBrushBackGround;
        }
    return 0;
#endif

    case WM_LBUTTONDOWN:
     if (player==opponent || flag.force)
     {
      UINT xsq,ysq,width,margin;
      SHORT x,y;
      HRGN hRgn;

      if (flag.replay) {command=1;return 0;}
      x=LOWORD(lParam);
      y=HIWORD(lParam);
      if (y<BACKMARGIN || y>BACKMARGIN+sqdepth*8)return 0;/*is y o the board?*/
      width=sqwidthB*8+deltaX*(y-BACKMARGIN)/(sqdepth*8);
      margin=((sqwidthF*8-width)>>1)+LEFTMARGIN;
      if (x<margin || x>=width+margin) return 0;  /*is x on the board?*/
      xsq=8*(x-margin)/width;
      ysq=7-(y-BACKMARGIN)/sqdepth;
      if (!selected && !button)
       {
        selected=1;
        selectX=xsq;
        selectY=ysq;
        hRgn=CreatePolygonRgn(&squares[xsq][ysq][0],4, ALTERNATE);
        hDC=GetDC(hWnd);
        InvertRgn(hDC,hRgn);
        ReleaseDC(hWnd,hDC);
        DeleteObject(hRgn);
       }
      else
       {
        if (!button) /*no squares are highlighted if a button is down*/
         {
          hRgn=CreatePolygonRgn(&squares[selectX][selectY][0],
                 4, ALTERNATE);
          hDC=GetDC(hWnd);
          InvertRgn(hDC,hRgn);  /*restore square to normal*/
          ReleaseDC(hWnd,hDC);
          DeleteObject(hRgn);
         }
        selected=0;
        if (xsq==selectX && ysq==selectY && !flag.editing)return 0;
        if (flag.reverse)
         {
           selectX = 7-selectX;
           xsq = 7-xsq;
           selectY = 7-selectY;
           ysq = 7-ysq;
         }
        move[0]=(char)selectX+'a';
        move[2]=(char)xsq+'a';
        move[1]='1'+(char)selectY;
        move[3]='1'+(char)ysq;
        move[4]=0;
        if (!flag.editing
            && ((ysq==0 && selectY==1)||(ysq==7 && selectY==6))
            && abs(selectX-xsq)<=1
            && (player==white ? ysq>selectY : ysq<selectY) )
         {
           SHORT *brdptr,*colptr;
           if (flag.searching) {brdptr=&origbrd; colptr=&origcol;}
           else {brdptr=&board; colptr=&color;}
           if (*(brdptr+selectX+selectY*8)==pawn
            && *(colptr+selectX+selectY*8)==player
            && ( abs(selectX-xsq)==0 ? *(brdptr+xsq+ysq*8)==no_piece
                                     : *(colptr+xsq+ysq*8)==!player ) )
            {
             lpfnDlgProc = MakeProcInstance(PromoteDlgProc, hInst);
             move[4] = CP[1][DialogBox(hInst, MAKEINTRESOURCE(PROMOTE),
                hWnd, lpfnDlgProc)];  /*promotion*/
             FreeProcInstance(lpfnDlgProc);
             move[5]=0;
            }
         }
        if (button) move[0]=0; /*editing - allow delete with right button
                                 while a piece button is down*/
        if (!flag.editing)
         {
           if ((!flag.easy || flag.bothsides) && player==opponent)
              flag.timeout = true;
           if (flag.bothsides) {flag.abort=true; flag.bothsides = false; }
         }
        command=1;
       }
     }
     return 0;

    case WM_RBUTTONDOWN:
      if (flag.replay) {command=1; return 0;}
      if (flag.editing)
      {
       SHORT x,y;
       UINT width,margin;
       x=LOWORD(lParam);
       y=HIWORD(lParam);
       if (y<BACKMARGIN || y>BACKMARGIN+sqdepth*8)return 0;
       width=sqwidthB*8+deltaX*(y-BACKMARGIN)/(sqdepth*8);
       margin=((sqwidthF*8-width)>>1)+LEFTMARGIN;
       if (x<margin || x>=width+margin) return 0;
       if (flag.reverse)
        {
         move[0]='h'-8*(x-margin)/width;
         move[1]='1'+(y-BACKMARGIN)/sqdepth;
        }
       else
        {
         move[0]='a'+8*(x-margin)/width;
         move[1]='8'-(y-BACKMARGIN)/sqdepth;
        }
       move[2]=move[0];
       move[3]=move[1];
       move[4]=0;
       command=1;
      }
      return 0;

    case WM_ERASEBKGND:
      {
         RECT rect;
         UnrealizeObject ( hBrushBackGround);
         GetClientRect ( hWnd, &rect);
         FillRect ( (HDC)wParam, &rect, hBrushBackGround);
         return 1;
      }

    case WM_COMMAND:
      switch (LOWORD(wParam))
       {
        case IDM_QUIT:
          flag.quit=true;
          GetWindowRect(hWnd,&wr);
          maximized=IsZoomed(hWnd);
          if (IsIconic(hWnd)) wr.right = 0;
          WinHelp(hWnd,szHelpFile,HELP_QUIT,0L);
        case IDM_GET:
        case IDM_NEW:
        case IDM_LIST:
        case IDM_EDIT:
        case IDM_REVIEW:
        case IDM_REMOVE:
        case IDM_UNDO:
        case IDM_FORCE:
        case IDM_SWITCH:
        case IDM_SWITCHDM:
        case IDM_WHITE:
        case IDM_BLACK:
        case IDM_COMPILE:
          flag.timeout=flag.abort=true;
          flag.bothsides=false;
          command=LOWORD(wParam);
          break;
        case IDM_SAVE:
          flag.timeout=true;
          flag.bothsides=false;
          command=LOWORD(wParam);
          break;

        case IDM_BOTH:
          if (!flag.searching)
           {
            command=LOWORD(wParam);
            break;
           }
          if (flag.bothsides)
           {
            flag.bothsides=false;
            if (player==opponent)   /*computer is making opponents move*/
               flag.abort=flag.timeout=true; /*so abort it*/
           }
          else
           if (player==opponent) /*computer is thinking on opponent's time*/
            {
              flag.timeout=true;
              command=LOWORD(wParam);
            }
           else flag.bothsides=true;
          break;
        case IDM_WTM:
        case IDM_BTM:
          if (player==(LOWORD(wParam)==IDM_WTM)? white : black) break;
          flag.timeout=flag.abort=true;
          flag.bothsides=false;
          command=LOWORD(wParam);
          break;

        case IDM_BEEP:
          flag.beep=!flag.beep;
          break;
        case IDM_COORD:
          flag.coords=!flag.coords;
          InvalidateRect(hWnd,0,true);
          break;
        case IDM_POST:
          if ( flag.post )
           {
            SendMessage ( hStats, WM_COMMAND, IDOK, 0 );
            flag.post = false;
           }
          else
           {
            lpfnDlgProc = MakeProcInstance(StatDlgProc, hInst);
            hStats = CreateDialog (hInst, MAKEINTRESOURCE(STATS),
                hWnd, lpfnDlgProc);
            flag.post = true;
           }
          break;
        case IDM_ANIMATE:
          flag.animate=!flag.animate;
          if (!flag.animate)
           {
            UpdateDisplay(0,0,1,0,0);
            Znodes<<=4;
           }
          else Znodes>>=4;
          break;
        case IDM_HASH:
          flag.hash=!flag.hash;
          break;
        case IDM_BOOK:
          flag.usebook=!flag.usebook;
          Book = flag.usebook ? BOOKFAIL : 0;
          break;
        case IDM_HDEPTH:
          lpfnDlgProc = MakeProcInstance ( HashDepthDlgProc, hInst);
          if (DialogBox ( hInst, MAKEINTRESOURCE(HASHDEPTHDLG), hWnd,
                lpfnDlgProc))
           {
            HashDepth=DlgInt1;
            HashMoveLimit=DlgInt2;
           }
          FreeProcInstance ( lpfnDlgProc);
          break;
        case IDM_HFILE:
          lpfnDlgProc = MakeProcInstance ( CreateHashDlgProc, hInst);
          if (DialogBox ( hInst, MAKEINTRESOURCE(CREATEHASH), hWnd,
                lpfnDlgProc))
           {
            if (size < 24)
                size = (1 << size);
            if (size>0) CreateHashFile(size);
           }
          FreeProcInstance ( lpfnDlgProc);
          break;
        case IDM_WIN:
          lpfnDlgProc = MakeProcInstance ( ChangeWinDlgProc, hInst);
          if (DialogBox ( hInst, MAKEINTRESOURCE(CHANGEWINDOW), hWnd,
                lpfnDlgProc))
          {
            WAwindow=DlgInt1;
            WBwindow=DlgInt2;
            WXwindow=DlgInt3;
            BAwindow=DlgInt4;
            BBwindow=DlgInt5;
            BXwindow=DlgInt6;
            xwndw = (computer == white) ? WXwindow : BXwindow;
          }
          FreeProcInstance ( lpfnDlgProc);
          break;
        case IDM_CONTEMP:
          lpszTitle=CP[64];
          DlgInt1=contempt;
          lpfnDlgProc = MakeProcInstance ( GetNumDlgProc, hInst);
          if (DialogBoxParam ( hInst, MAKEINTRESOURCE(NUMDLG), hWnd,
                lpfnDlgProc,46L)) contempt=DlgInt1;
          FreeProcInstance ( lpfnDlgProc);
          break;
        case IDM_MATERIAL:
          flag.material=!flag.material;
          break;
        case IDM_RCPTR:
          flag.rcptr=!flag.rcptr;
          break;
        case IDM_THREAT:
          flag.threat=!flag.threat;
          break;
        case IDM_PVS:
          flag.pvs=!flag.pvs;
          break;
        case IDM_NEWEVAL:
          flag.neweval=!flag.neweval;
          break;
        case IDM_GAMEIN:
          flag.gamein=!flag.gamein;
          break;

        case IDM_TIME:
          lpfnDlgProc = MakeProcInstance ( TimeDlgProc, hInst);
          DialogBox ( hInst, MAKEINTRESOURCE(TIME), hWnd, lpfnDlgProc);
          FreeProcInstance ( lpfnDlgProc);
          break;
        case IDM_RANDOM:
          dither = (dither)?0:DITHER;
          break;
        case IDM_EASY:
          flag.easy = !flag.easy;
          if (flag.easy && flag.searching && player==opponent)
              flag.timeout=true;
          break;
        case IDM_DEPTH:
          lpszTitle=CP[61];
          DlgInt1=MaxSearchDepth;
          lpfnDlgProc = MakeProcInstance ( GetNumDlgProc, hInst);
          if (DialogBoxParam ( hInst, MAKEINTRESOURCE(NUMDLG), hWnd,
                   lpfnDlgProc,47L)) MaxSearchDepth=DlgInt1;
          FreeProcInstance ( lpfnDlgProc);
          TCflag = !(MaxSearchDepth > 0);
          break;

        case IDM_REVERSE:
          flag.reverse=!flag.reverse;
          if(selected) {selectX=7-selectX; selectY=7-selectY;}
          InvalidateRect(hWnd,0,true);
          break;

        case IDM_BACKGROUND:
          if (GetColor(clrBackGround))
           {
            clrBackGround=cc.rgbResult;
            InvalidateRect(hWnd,0,true);
            DeleteObject (hBrushBackGround);
            hBrushBackGround = CreateSolidBrush ( clrBackGround );
           }
          break;
        case IDM_BLACKSQUARE:
          if (GetColor(clrBlackSquare))
           {
            clrBlackSquare=cc.rgbResult;
            UpdateDisplay(0, 0, 1, 0, 0);
           }
          break;
        case IDM_WHITESQUARE:
          if (GetColor(clrWhiteSquare))
           {
            clrWhiteSquare=cc.rgbResult;
            UpdateDisplay(0, 0, 1, 0, 0);
           }
          break;
        case IDM_BLACKPIECE:
          if (GetColor(clrBlackPiece))
           {
            clrBlackPiece=cc.rgbResult;
            UpdateDisplay(0, 0, 1, 0, 0);
           }
          break;
        case IDM_WHITEPIECE:
          if (GetColor(clrWhitePiece))
           {
            clrWhitePiece=cc.rgbResult;
            UpdateDisplay(0, 0, 1, 0, 0);
           }
          break;
        case IDM_TEXT:
          if (GetColor(clrText))
           {
            clrText=cc.rgbResult;
            InvalidateRect (hWnd, NULL, TRUE);
           }
          break;
        case IDM_EDGE:
          if (GetColor(clrEdge))
           {
            clrEdge=cc.rgbResult;
            UpdateDisplay(0, 0, 1, 0, 0);
           }
          break;
        case IDM_DEFAULT:
          LoadDefaultColors();
          DeleteObject(hBrushBackGround);
          hBrushBackGround=CreateSolidBrush(clrBackGround);
          InvalidateRect(hWnd,0,true);
          break;

        case IDM_SMALL:
        case IDM_MEDIUM:
        case IDM_LARGE:
         {
          SHORT i;

          CheckMenuItem ( GetMenu(hWnd), boardsize/12+IDM_SMALL,
                     MF_UNCHECKED);
          boardsize=(LOWORD(wParam)-IDM_SMALL)*12;
          CheckMenuItem ( GetMenu(hWnd), LOWORD(wParam), MF_CHECKED);
          for (i=pawn;i<=king;i++)
          { DeleteObject(pieces[i].detail);
            DeleteObject(pieces[i].mask);
            pieces[i].detail = LoadBitmap (hInst, MAKEINTRESOURCE(i+boardsize));
            pieces[i].mask = LoadBitmap (hInst, MAKEINTRESOURCE(i+boardsize+6));
          }
          InitScreen();
          MoveStatics();
          SizeWindow(0);
          InvalidateRect(hWnd,0,TRUE);
          break;
         }
        case IDM_3D:
          squarebd=0;
          goto changebd;
        case IDM_SQUARE:
          squarebd=1;
changebd:
          InitScreen();
          MoveStatics();
          SizeWindow(0);
          InvalidateRect(hWnd,0,TRUE);
          break;
        case IDM_HINT:
          GiveHint();
          break;

        case IDM_INDEX:
          if (!WinHelp(hWnd,szHelpFile,HELP_CONTENTS,0L))
             ShowMessage("Could not open gnuchess.hlp");
          break;
        case IDM_HELP:
          if (!WinHelp(hWnd,"winhelp.hlp",HELP_HELPONHELP,0L))
             ShowMessage("Could not open winhelp.hlp");
          break;
        case IDM_ABOUT:
          lpfnDlgProc = MakeProcInstance ( AboutDlgProc, hInst);
          DialogBox (hInst,MAKEINTRESOURCE(ABOUT),hWnd,lpfnDlgProc);
          FreeProcInstance ( lpfnDlgProc);
          break;

        case IDM_CLEAR:     /*editing*/
          {
           short i;
           for (i=0;i<64;i++){board[i]=no_piece;color[i]=neutral;}
          }
          board[4]=board[60]=king;
          color[4]=white;
          color[60]=black;
          selected=0;
          UpdateDisplay(0,0,1,0,0);
          break;
        case IDM_RESTORE:     /*editing*/
          {
           short i;
           for (i=0;i<64;i++)
            {
             board[i]=Stboard[i];
             color[i]=Stcolor[i];
            }
           selected=0;
           UpdateDisplay(0,0,1,0,0);
           break;
          }
        case IDM_PREV:        /*replay*/
        case IDM_NEXT:
        case IDM_DONE:        /*editing*/
          command=LOWORD(wParam);
       }
      return 0;

    case WM_INITMENUPOPUP:
      if (!flag.editing) switch (lParam)
      {
       case 0:       /*Game menu*/
            EnableMenuItem ( (HMENU)wParam, IDM_SAVE,
                             (GameCnt>0 ? MF_ENABLED : MF_GRAYED) );
            EnableMenuItem ( (HMENU)wParam, IDM_LIST,
                             (GameCnt>0 ? MF_ENABLED : MF_GRAYED) );
            break;
       case 1:       /*Edit Menu */
            EnableMenuItem ( (HMENU)wParam, IDM_REVIEW,
                             (GameCnt>0 ? MF_ENABLED : MF_GRAYED) );
            EnableMenuItem ( (HMENU)wParam, IDM_UNDO,
                             (GameCnt>0 ? MF_ENABLED : MF_GRAYED) );
            EnableMenuItem ( (HMENU)wParam, IDM_REMOVE,
                          ((flag.searching ? OrigGameCnt : GameCnt)>1
                           ? MF_ENABLED : MF_GRAYED) );
            break;
       case 2:  /* Options Menu */
            CheckMenuItem ( (HMENU)wParam, IDM_HASH,
                     flag.hash?MF_CHECKED:MF_UNCHECKED);
            EnableMenuItem ( (HMENU)wParam, IDM_HASH,
                     (hashfile ? MF_ENABLED : MF_GRAYED) );
            CheckMenuItem ( (HMENU)wParam, IDM_COORD,
                     flag.coords?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_BEEP,
                     flag.beep?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_BOOK,
                     flag.usebook?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_POST,
                     flag.post?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_ANIMATE,
                     flag.animate?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_MATERIAL,
                     flag.material?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_RCPTR,
                     flag.rcptr?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_THREAT,
                     flag.threat?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_PVS,
                     flag.pvs?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_NEWEVAL,
                     flag.neweval?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_GAMEIN,
                     flag.gamein?MF_CHECKED:MF_UNCHECKED);
            break;
       case 3:   /*skill menu*/
            CheckMenuItem ( (HMENU)wParam, IDM_RANDOM,
                     dither?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_EASY,
                     flag.easy?MF_CHECKED:MF_UNCHECKED);
            break;
       case 4:   /*Side menu*/
          {
            int color=flag.bothsides ? 2
                      : computer^(flag.force & forcing);
            CheckMenuItem ( (HMENU)wParam, IDM_REVERSE,
                     flag.reverse?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_BLACK,
                 (color==black)?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_WHITE,
                 (color==white)?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_BOTH,
                     flag.bothsides?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_WTM,
                     player==white?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_BTM,
                     player==black?MF_CHECKED:MF_UNCHECKED);
            CheckMenuItem ( (HMENU)wParam, IDM_FORCE,
                   flag.force == false ? MF_UNCHECKED : MF_CHECKED);
          }
       case 5: /*Board menu */
         CheckMenuItem ( (HMENU)wParam, IDM_SQUARE,
                    squarebd?MF_CHECKED:MF_UNCHECKED);
         CheckMenuItem ( (HMENU)wParam, IDM_3D,
                    squarebd?MF_UNCHECKED:MF_CHECKED);
      }
      return 0;

    case WM_SYSCOLORCHANGE:
      DeleteObject(hDlgBkgrnd);
      hDlgBkgrnd=CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
      return 0;

    case WM_DESTROY:
      flag.quit=true;
      flag.timeout=flag.abort=true;
      flag.bothsides=false;
      command=IDM_QUIT;
      GetWindowRect(hWnd,&wr);
      maximized=IsZoomed(hWnd);
      if (IsIconic(hWnd)) wr.right = 0;
      WinHelp(hWnd,szHelpFile,HELP_QUIT,0L);
      return 0;
  }
  return DefWindowProc(hWnd,Message,wParam,lParam);
}

void SizeWindow(int move)
  {
    RECT wr;
    WinSizeX=LEFTMARGIN+sqwidthB*8+deltaX/2+20+CompMoveExt
          +GetSystemMetrics(SM_CXFRAME)*2;
    WinSizeY=BACKMARGIN+sqdepth*8+BRD_EDGE+LineSpace+SLineSpace+5
          +GetSystemMetrics(SM_CYCAPTION)+GetSystemMetrics(SM_CYFRAME)*2
          +GetSystemMetrics(SM_CYMENU);
    GetWindowRect(GetDesktopWindow(),&wr);
    if (wr.right-wr.left > WinSizeX) WinPosX = (wr.right-WinSizeX)/2;
    else { WinPosX=0; WinSizeX=wr.right-wr.left; }
    if (wr.bottom-wr.top > WinSizeY) WinPosY = (wr.bottom-WinSizeY)/2;
    else { WinPosY=0; WinSizeY=wr.bottom-wr.top; }
    if (!move)
     {
      GetWindowRect(hWnd,&wr);
      WinPosX=wr.left;
      WinPosY=wr.top;
     }
    MoveWindow(hWnd, WinPosX, WinPosY, WinSizeX, WinSizeY, TRUE);
  }

void CheckMessage(void)
 {
  MSG msg;

  if ( PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
    if ( !TranslateAccelerator (hWnd, hAccel, &msg) )
     {    TranslateMessage(&msg);
       DispatchMessage(&msg); }
 }

BOOL GetColor(DWORD current)
{
  cc.lStructSize=sizeof(cc);
  cc.hwndOwner=hWnd;
  cc.rgbResult=current;
  cc.lpCustColors=&CustCols;
  cc.Flags=CC_FULLOPEN|CC_RGBINIT;
  return ChooseColor(&cc);
}

void LoadDefaultColors()
 {
  clrBackGround  = BROWN;
  clrBlackSquare = DARKGREEN;
  clrWhiteSquare = PALEGRAY;
  clrBlackPiece  = DARKRED;
  clrWhitePiece  = CWHITE;
  clrText        = CBLACK;
  clrEdge        = CBLACK;
 }

void
Exit (int code)
{
  SHORT bm;

  for (bm=pawn;bm<=king;bm++)
   {
    DeleteObject(pieces[bm].mask);
    DeleteObject(pieces[bm].detail);
   }
  DeleteObject(hBrushBackGround);
  DeleteObject(hFont);
  if (!code) SaveSettings();
  exit (code);
}

