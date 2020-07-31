/*
 * windsp.c - Windows interface for CHESS
 *
 * Copyright (c) 1996 Conor McCarthy
 * Contains code from uxdsp.c (Copyright (c) 1988,1989,1990 John Stanback
 *                             Copyright (c) 1992 Free Software Foundation)
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
#include "ataks.h"
#include <ctype.h>
#include <signal.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

#define ESC 0x1B

extern SHORT pscore[2];

#define TAB (46)
#define VIR_C(s)  ((flag.reverse) ? 7-column(s) : column(s))
#define VIR_R(s)  ((flag.reverse) ? 7-row(s) : row(s))

UTSHORT MV[MAXDEPTH+1];
int MSCORE;
CHAR *DRAW;

POINT boardpg[4];
POINT squares[8][8][4];
POINT pieceloc[64];
struct bitmaps pieces[7];
SHORT origbrd[64],origcol[64];
extern char szBtnBar[];
SHORT button;
extern SHORT selected,selectX,selectY;
extern char lpStatic[];
HWND hBtnWnd;

DWORD clrBackGround;
DWORD clrBlackSquare;
DWORD clrWhiteSquare;
DWORD clrBlackPiece;
DWORD clrWhitePiece;
DWORD clrText;
DWORD clrEdge;

SHORT sqwidthF;
SHORT sqwidthB;
SHORT sqdepth;
SHORT boardsize=SMALL;
SHORT deltaX,bmsize;

void DrawButton(HDC,SHORT,BOOL,BOOL);

void
EditBoard (void)

{
  UTSHORT sq,f,t;
  HDC hDC;
  HMENU hMainMenu,hEditMenu;

  button=0;
  flag.editing=true;
  hBtnWnd = CreateWindow(szBtnBar,"",WS_OVERLAPPED|WS_SYSMENU,
               100,0,bmsize*10+49+GetSystemMetrics(SM_CXBORDER)*2,
               bmsize+4+GetSystemMetrics(SM_CYCAPTION)
                 +GetSystemMetrics(SM_CYBORDER),
               hWnd,NULL,hInst,NULL);
  ShowWindow(hBtnWnd,SW_SHOWNORMAL);
  hEditMenu=LoadMenu(hInst,"EDIT");
  hMainMenu=GetMenu(hWnd);
  SetMenu(hWnd,hEditMenu);
  flag.regularstart = true;
  Book = BOOKFAIL;
  do
  {
   while (!command)CheckMessage();
   if (command==1)
    {
     if (flag.quit)Exit(0);
     command=0;
     if (strlen(move)==2)
      {
       t=(UTSHORT)(move[0]-'a'+(move[1]-'1')*8);
       if (t>63) {ShowMessage(CP[71]); continue; }
       if (!button)
        {
         board[t]=no_piece;
         color[t]=neutral;
         hDC=GetDC(hWnd);
         DrawPiece(t,hDC);
         ReleaseDC(hWnd,hDC);
         continue;
        }
       else move[0]=0;
      }
     else t = (UTSHORT)(move[2]-'a'+(move[3]-'1')*8);
     if (board[t]==king)
      {
       ShowMessage(CP[72]);
       command=0;
       continue;
      }
     if (button && !move[0])
      /* A button is down on the button bar
         and the left mouse button was pressed*/
      {
       board[t]=button>queen?button-5:button;
       color[t]=button>queen?black:white;
       hDC=GetDC(hWnd);
       DrawPiece(t,hDC);
       ReleaseDC(hWnd,hDC);
      }
     else
      {
       f=(UTSHORT)(move[0]-'a'+(move[1]-'1')*8);
       if (f==t)  /*from and to are equal - clear the square*/
        {
         board[f]=no_piece;
         color[f]=neutral;
        }
       else    /*make the move*/
        {
         board[t]=board[f];
         color[t]=color[f];
         board[f]=no_piece;
         color[f]=neutral;
        }
       UpdateDisplay(f,t,0,0,0);
      }
    }
  }
  while (command!=IDM_DONE);
  for (sq = 0; sq < 64; sq++)
    Mvboard[sq] = ((board[sq] != Stboard[sq]) ? 10 : 0);
  GameCnt = 0;
  Game50 = 1;
  ZeroRPT ();
  Sdepth = 0;
  InitializeStats ();
  SetMenu(hWnd,hMainMenu);
  DestroyMenu(hEditMenu);
  DestroyWindow(hBtnWnd);
  button=command=0;
  flag.editing=false;
}

LRESULT WINAPI BtnWndProc(HWND hBtnWnd, UINT message, WPARAM wParam,
                        LPARAM lParam)
{
 HDC hDC;
 HPEN hOldPen;
 HRGN hRgn;
 PAINTSTRUCT ps;
 SHORT i;

 switch (message)
  {
   case WM_PAINT:
     hDC=BeginPaint(hBtnWnd,&ps);
     for (i=pawn;i<=queen+5;i++) DrawButton(hDC,i,i==button? true:false,false);
     hOldPen=SelectObject(hDC,GetStockObject(BLACK_PEN));
     for (i=bmsize+4;i<(bmsize+5)*10;i+=bmsize+5)
      {
       MoveToEx(hDC,i,0,0);
       LineTo(hDC,i,bmsize+4);
      }
     SelectObject(hDC,hOldPen);
     EndPaint(hBtnWnd,&ps);
     return 0;

   case WM_KEYDOWN:
     if (wParam>='0' && wParam<='9')
      {
       wParam-='0';
       if (!wParam) wParam=10;
       lParam=--wParam*(bmsize+5)+pawn;  /*   -   */
      }                                  /*    |  */
     else break;                         /*    |  */
   case WM_LBUTTONDOWN:                  /*    |  */
     if (selected)                       /*  <-   */
      {
       selected=0;
       hRgn=CreatePolygonRgn(&squares[selectX][selectY][0],
              4, ALTERNATE);
       hDC=GetDC(hWnd);
       InvertRgn(hDC,hRgn);  /*restore square to normal*/
       ReleaseDC(hWnd,hDC);
       DeleteObject(hRgn);
      }
     i=LOWORD(lParam)/(bmsize+5)+pawn;
     hDC=GetDC(hBtnWnd);
     if (button) DrawButton(hDC,button,false,true);
     if (i!=button)
      {DrawButton(hDC,i,true,true);
       button=i;
      }
     else button=0;
     ReleaseDC(hBtnWnd,hDC);
     return 0;
  }
 return DefWindowProc(hBtnWnd,message,wParam,lParam);
}

void DrawButton(HDC hDC,SHORT bn,BOOL down,BOOL changed)
{
 HPEN hDkPen,hOldPen;
 HDC hMemDC;
 HBITMAP hBmpOld;
 SHORT x,piece;
 COLORREF color;

 if (bn>queen) {color=clrBlackPiece; piece=bn-5;}
 else {color=clrWhitePiece; piece=bn;}
 x=(bn-pawn)*(bmsize+5);
 hOldPen=SelectObject(hDC,GetStockObject(NULL_PEN));
 if (changed)
  {
   SelectObject(hDC,GetStockObject(LTGRAY_BRUSH));
   Rectangle(hDC,x,0,x+bmsize+5,bmsize+5);
  }
 hDkPen=CreatePen(PS_SOLID,1,RGB(128,128,128));
 if (!down)SelectObject(hDC,GetStockObject(WHITE_PEN));
 else SelectObject(hDC,hDkPen);
 MoveToEx(hDC,x,bmsize+3,0); /*MoveTo not implemented in Win32*/
 LineTo(hDC,x,0);
 LineTo(hDC,x+bmsize+4,0);
 MoveToEx(hDC,x+1,bmsize+2+down,0);
 LineTo(hDC,x+1,1);
 LineTo(hDC,x+bmsize+3+down,1);
 if (!down)
  {
   SelectObject(hDC,hDkPen);
   MoveToEx(hDC,x,bmsize+3,0);
   LineTo(hDC,x+bmsize+3,bmsize+3);
   LineTo(hDC,x+bmsize+3,0);
   MoveToEx(hDC,x+1,bmsize+2,0);
   LineTo(hDC,x+bmsize+2,bmsize+2);
   LineTo(hDC,x+bmsize+2,1);
  }
 SelectObject(hDC,hOldPen);
 DeleteObject(hDkPen);
 hMemDC = CreateCompatibleDC(hDC);
 SetTextColor(hDC,CBLACK);
 SetBkColor(hDC,CWHITE);
 hBmpOld=SelectObject(hMemDC, pieces[piece].mask);
 BitBlt(hDC, (bn-pawn)*(bmsize+5)+down, 2+down, bmsize, bmsize,
        hMemDC, 0, 0, SRCAND);
 SelectObject(hMemDC, pieces[piece].detail);
 SetBkColor(hDC,color);
 BitBlt(hDC, (bn-pawn)*(bmsize+5)+down, 2+down, bmsize, bmsize,
        hMemDC, 0, 0, SRCPAINT);
 SelectObject(hMemDC,hBmpOld);
 DeleteDC(hMemDC);
}

void
ShowPlayers (void)
{
  SetWindowText ( hComputerColor, (computer == black) ? CP[73] : CP[74]);
}

void
ShowDepth (CHAR ch)
{
  sprintf (msg,CP[19], Sdepth, ch); /*Depth= %d%c*/
  SetWindowText(hDepth,msg);
}

void
ShowScore (SHORT score)
{
  sprintf (msg, "%d", (int)score);
  SetDlgItemText(hStats,IDC_SCORE,msg);
}

void
ShowMessage (CHAR *s)
{
  MessageBox(hWnd,s,szAppName,MB_OK);
}

void
ShowCurrentMove (SHORT pnt, SHORT f, SHORT t)
{
  sprintf (msg,"(%2d) %4s", pnt, mvstr[0]);
  SetDlgItemText(hStats,IDC_POS,msg);
}

void
ShowSidetoMove (void)
{
 if(!flag.mate)
  {
   sprintf (msg,CP[75],ColorStr[player]);
   SetWindowText ( hWhoseTurn, msg);
  }
 else SetWindowText ( hWhoseTurn, "Checkmate");
 if (SqAtakd (PieceList[player][0], player^1))
  {
   sprintf(msg,CP[76],ColorStr[player]);
   SetWindowText ( hInCheck, msg);
  }
 else
  {
   SetWindowText ( hInCheck, "");
  }
}

void
ShowNodeCnt (long int NodeCnt)
{
 sprintf (msg,"%ld", NodeCnt);
 SetDlgItemText(hStats,IDC_NODE,msg);
 sprintf(msg,"%ld", (et>=100) ? NodeCnt / (et / 100) : 0);
 SetDlgItemText(hStats,IDC_NODESEC,msg);
}

void
ShowResults (SHORT score, UTSHORT *bstline, CHAR ch)
{
  UCHAR d, ply;

  if (flag.post)
    {
      SHORT len=0;
      ShowDepth (ch);
      ShowScore (score);
      d = 7;
      for (ply = 1; bstline[ply] > 0; ply++)
   {
     algbr ((SHORT) bstline[ply] >> 8, (SHORT) bstline[ply] & 0xFF, false);
     len+=sprintf (msg+len,"%s ", mvstr[0]);
   }
      msg[len]='\0';
      SetDlgItemText(hStats,IDC_BESTLINE,msg);
    }
}

void
OutputMove (SHORT score)
{
  UpdateDisplay (root->f, root->t, 0, (SHORT) root->flags, 0);
  if(flag.illegal){MessageBox(hWnd,CP[58],"",MB_OK);return;}
  if(mvstr[0][0])
   {
    sprintf (msg,CP[30], mvstr[0]); /*My move is %s*/
    SetWindowText ( hComputerMove, msg);
   }

  if (flag.beep)
    MessageBeep(0);

  if (root->flags & draw)
    MessageBox (hWnd,CP[21],"",MB_OK);
  else if (root->score == -9999)
    MessageBox (hWnd,CP[33],"",MB_OK);
  else if (root->score == 9998)
    MessageBox (hWnd,CP[15],"",MB_OK);
#ifdef VERYBUGGY
  else if (root->score < -9000)
    MessageBox (hWnd,CP[34],"",MB_OK);
  else if (root->score > 9000)
    MessageBox (hWnd,CP[16],"",MB_OK);
#endif /*VERYBUGGY*/
  if (flag.post)
    {
      register SHORT h, l, t;

      h = TREE;
      l = 0;
      t = TREE >> 1;
      while (l != t)
   {
     if (Tree[t].f || Tree[t].t)
       l = t;
     else
       h = t;
     t = (l + h) >> 1;
   }

      ShowNodeCnt (NodeCnt);
      sprintf (msg,"%d", (int)t);   /*Max Tree=*/
      SetDlgItemText(hStats,IDC_TREE,msg);
    }
  ShowSidetoMove ();
}

void
UpdateClocks (void)
{
  SHORT m, s;

  m = (SHORT) (et / 6000);
  s = (SHORT) (et - 6000 * (long) m) / 100;
  if (TCflag)
    {
      m = (SHORT) ((TimeControl.clock[player] - et) / 6000);
      s = (SHORT) ((TimeControl.clock[player] - et - 6000 * (long) m) / 100);
    }
  if (m < 0)
    m = 0;
  if (s < 0)
    s = 0;
  sprintf (msg,"%d:%02d", m, s);
  (player == white)? SetWindowText (hClockWhite, msg):
                     SetWindowText (hClockBlack, msg);
  if (flag.post && (!flag.easy || player==computer))
    ShowNodeCnt (NodeCnt);
}

void
DrawPiece (SHORT sq,HDC hDC)
{
 HBRUSH hBrush_lt,hBrush_dk,hOldBrush;
 HPEN hOldPen;
 HDC hMemDC;
 HBITMAP hBMPold;
 SHORT sqloc,*brdptr,*colptr;

 if (flag.searching || flag.replay) {brdptr=&origbrd; colptr=&origcol;}
 else {brdptr=&board; colptr=&color;}
 if (flag.reverse)sqloc=63-sq;
   else sqloc=sq;
 hBrush_lt = CreateSolidBrush ( clrWhiteSquare );
 hBrush_dk = CreateSolidBrush ( clrBlackSquare );
 hOldBrush = SelectObject ( hDC, hBrush_lt);
 hOldPen   = SelectObject ( hDC, GetStockObject (BLACK_PEN) );
 if (((sq+sq/8)&1)==0) SelectObject(hDC,hBrush_dk);
    else SelectObject(hDC,hBrush_lt);
 Polygon(hDC,&squares[sqloc%8][sqloc/8][0],4);
 SelectObject(hDC,hOldBrush);
 SelectObject(hDC,hOldPen);
 DeleteObject(hBrush_lt);
 DeleteObject(hBrush_dk);
 if (*(brdptr+sq)!=no_piece)
  {hMemDC = CreateCompatibleDC(hDC);
   hBMPold = SelectObject(hMemDC, pieces[*(brdptr+sq)].mask);
   SetBkColor(hDC,CWHITE);
   SetTextColor(hDC,CBLACK);
   BitBlt(hDC, pieceloc[sqloc].x, pieceloc[sqloc].y, bmsize, bmsize,
          hMemDC, 0, 0, SRCAND);
   SelectObject(hMemDC, pieces[*(brdptr+sq)].detail);
   if (*(colptr+sq)==black)SetBkColor(hDC,clrBlackPiece);
      else SetBkColor(hDC,clrWhitePiece);
   BitBlt(hDC, pieceloc[sqloc].x, pieceloc[sqloc].y, bmsize, bmsize,
          hMemDC, 0, 0, SRCPAINT);
   SelectObject(hMemDC, hBMPold);
   DeleteDC(hMemDC);
  }
}

void
ShowPostnValue (SHORT sq)

/*
 * must have called ExaminePosition() first
 */

{
/*  SHORT score;

  gotoXY (4 + 5 * VIR_C (sq), 5 + 2 * (7 - VIR_R (sq)));
  score = ScorePosition (color[sq]);
  if (color[sq] != neutral)
    {sprintf (msg,"%3d ", svalue[sq]);
     printz(msg);}
  else
    printz ("   ");  */
}

void
ShowPostnValues (void)
{
/*  SHORT sq, score;

  ExaminePosition ();
  for (sq = 0; sq < 64; sq++)
    ShowPostnValue (sq);
  score = ScorePosition (opponent);
  gotoXY (TAB, 5);
  sprintf (msg,CP[35], score, mtl[computer], pscore[computer], mtl[opponent],pscore[opponent]);
  printz(msg);

  ClrEoln (); */
}

void
UpdateDisplay (SHORT f, SHORT t, SHORT redraw, SHORT isspec,HDC hDC)
{
  SHORT i, sq;
  int x, y;
  HBRUSH hOldBrush, hBrush_lt, hBrush_dk;
  HPEN hOldPen;
  BOOL DCsupplied=true;

  if (!hDC) {hDC=GetDC(hWnd); DCsupplied=false;}
  if (redraw)
    {
   hBrush_lt = CreateSolidBrush ( clrWhiteSquare );
   hBrush_dk = CreateSolidBrush ( clrBlackSquare );

   hOldBrush = SelectObject ( hDC, hBrush_lt);
   hOldPen   = SelectObject ( hDC, GetStockObject (BLACK_PEN) );

   Polygon(hDC,&boardpg,4);
   SelectObject(hDC,hBrush_dk);
   for (y=0;y<8;y++)
      for (x=y&1;x<8;x+=2)Polygon(hDC,&squares[x][y][0],4);
   SelectObject(hDC,hOldBrush);
   if (flag.searching || flag.replay)
    {
     for (sq=0;sq<64;sq++)
     if (origbrd[sq]!=no_piece)DrawPiece(sq,hDC);
    }
   else
    {
     for (sq=0;sq<64;sq++)
     if (board[sq]!=no_piece)DrawPiece(sq,hDC);
    }
   DeleteObject(hBrush_lt);
   DeleteObject(hBrush_dk);
   SelectObject(hDC,hFont);
   SetBkMode(hDC,TRANSPARENT);
   SetTextColor(hDC,clrText);
   if (flag.coords)
   for (i=0;i<8;i++)
    {
     y=sqdepth*i+(sqdepth-LineSpace)/2;
     x=LEFTMARGIN+deltaX/2-deltaX/2*y/(sqdepth*8)-CharWidth-8;
     TextOut(hDC,x,y+BACKMARGIN,flag.reverse?CP[60]+i :
             "87654321"+i,1);
     TextOut(hDC,LEFTMARGIN+i*sqwidthF+(sqwidthF-CharWidth)/2,BACKMARGIN+
         sqdepth*8+BRD_EDGE,flag.reverse?"hgfedcba"+i:CP[59]+i,1);
    }
   hBrush_dk=CreateSolidBrush(clrEdge);
   SelectObject(hDC,hBrush_dk);
   if(!squarebd)
     Rectangle(hDC,boardpg[0].x,boardpg[0].y,
         boardpg[1].x+1,boardpg[1].y+BRD_EDGE);
   SelectObject(hDC,hOldBrush);
   SelectObject(hDC,hOldPen);
   DeleteObject(hBrush_dk);
    }
  else
    {
      DrawPiece (f,hDC);
      DrawPiece (t,hDC);
      if (isspec & cstlmask)
   if (t > f)
     {
       DrawPiece (f + 3,hDC);
       DrawPiece (t - 1,hDC);
     }
   else
     {
       DrawPiece (f - 4,hDC);
       DrawPiece (t + 1,hDC);
     }
      else if (isspec & epmask)
   {
     DrawPiece (t - 8,hDC);
     DrawPiece (t + 8,hDC);
   }
    }
  if (!DCsupplied)ReleaseDC(hWnd,hDC);
}

extern CHAR *InPtr;
void
skip ()
{
  while (*InPtr != ' ' && *InPtr!=0)
    InPtr++;
  while (*InPtr == ' ')
    InPtr++;
}
void
skipb ()
{
  while (*InPtr == ' ')
    InPtr++;
}

void
GiveHint (void)
{
  CHAR s[40];
  if (hint)
    {
      algbr ((SHORT) (hint >> 8), (SHORT) (hint & 0xFF), false);
      strcpy (s, CP[50]);  /*try*/
      strcat (s, mvstr[0]);
      ShowMessage (s);
    }
  else
    ShowMessage (CP[56]);
}

void Replay(void)
{
 SHORT i,f,t;
 HWND hReplay;
 HMENU hMenu,hMainMenu;
 char message[36];

 flag.replay=true;
 ShowWindow(hComputerColor,SW_HIDE);
 ShowWindow(hWhoseTurn,SW_HIDE);
 ShowWindow(hInCheck,SW_HIDE);
 hReplay = CreateWindow (lpStatic, "",
                   WS_CHILD | SS_LEFT | WS_VISIBLE,
                   LEFTMARGIN, BACKMARGIN+sqdepth*8+20,
                   600, SLineSpace,
                   hWnd, (HMENU)0, hInst, NULL);
 hMenu = CreateMenu ();
 AppendMenu ( hMenu, MF_STRING, IDM_PREV,"&Previous");
 AppendMenu ( hMenu, MF_STRING, IDM_NEXT,"&Next");
 AppendMenu ( hMenu, MF_STRING, IDM_DONE,"&End");
 hMainMenu = GetMenu ( hWnd);
 SetMenu ( hWnd, hMenu);
 EnableMenuItem(hMenu,IDM_PREV,MF_BYCOMMAND|MF_GRAYED);
 for (i = 0; i < 64; i++)
    {
      origbrd[i] = Stboard[i];
      origcol[i] = Stcolor[i];
    }
 UpdateDisplay(0,0,1,0,0);
 i=1;
 while(1)
  {
   DrawMenuBar(hWnd);
   sprintf(message,CP[77],i);
   SetWindowText(hReplay,message);
   while (!command)CheckMessage();
   if (command==IDM_DONE) break;
   if (flag.quit)Exit(0);
   if(command==IDM_NEXT)
    {
     f=GameList[i].gmove>>8;
     t=GameList[i].gmove&255;
     if (GameList[i].flags & cstlmask)
      {
       if (t>f)
        {
         origbrd[t-1]=origbrd[t+1];
         origcol[t-1]=origcol[t+1];
         origbrd[t+1]=no_piece;
         origcol[t+1]=neutral;
        }
       else
        {
         origbrd[t+1]=origbrd[t-2];
         origcol[t+1]=origcol[t-2];
         origbrd[t-2]=no_piece;
         origcol[t-2]=neutral;
        }
      }
     if (GameList[i].flags & promote)
       origbrd[f]=GameList[i].flags & pmask;
     if (GameList[i].flags & epmask)
      {
       SHORT l;
       l = t + ((t > f) ? -8 : 8);
       board[l] = no_piece;
       color[l] = neutral;
      }
     origbrd[t]=origbrd[f];
     origcol[t]=origcol[f];
     origbrd[f]=no_piece;
     origcol[f]=neutral;
     UpdateDisplay(f,t,0,GameList[i].flags,0);
     i++;
     if(i>GameCnt)EnableMenuItem(hMenu,IDM_NEXT,MF_BYCOMMAND|MF_GRAYED);
     if(i==2)EnableMenuItem(hMenu,IDM_PREV,MF_BYCOMMAND|MF_ENABLED);
    }
   else if(command==IDM_PREV)
    {
     i--;
     f=GameList[i].gmove>>8;
     t=GameList[i].gmove&255;
     if (GameList[i].flags & cstlmask)
      {
       if (t>f)
        {
         origbrd[t+1]=origbrd[t-1];
         origcol[t+1]=origcol[t-1];
         origbrd[t-1]=no_piece;
         origcol[t-1]=neutral;
        }
       else
        {
         origbrd[t-2]=origbrd[t+1];
         origcol[t-2]=origcol[t+1];
         origbrd[t+1]=no_piece;
         origcol[t+1]=neutral;
        }
      }
     if (GameList[i].flags & promote)
       origbrd[t]=pawn;
     if (GameList[i].flags & epmask)
      {
       SHORT l;
       l = t + ((t > f) ? -8 : 8);
       board[l] = pawn;
       color[l] = !GameList[i].color;
      }
     origbrd[f]=origbrd[t];
     origcol[f]=origcol[t];
     if(GameList[i].flags & capture)
      {
       origbrd[t]=GameList[i].piece;
       origcol[t]=GameList[i].color;
      }
     else
      {
       origbrd[t]=no_piece;
       origcol[t]=neutral;
      }
     UpdateDisplay(f,t,0,GameList[i].flags,0);
     if(i==GameCnt)EnableMenuItem(hMenu,IDM_NEXT,MF_BYCOMMAND|MF_ENABLED);
     if(i==1)EnableMenuItem(hMenu,IDM_PREV,MF_BYCOMMAND|MF_GRAYED);
    }
   command=0;
  }
 SetWindowText(hReplay,CP[78]);
 command=0;
 SetMenu(hWnd,hMainMenu);
 DestroyMenu(hMenu);
 flag.replay=false;
 UpdateDisplay(0,0,1,0,0);
 DestroyWindow(hReplay);
 ShowWindow(hComputerColor,SW_SHOWNORMAL);
 ShowWindow(hWhoseTurn,SW_SHOWNORMAL);
 ShowWindow(hInCheck,SW_SHOWNORMAL);
}

void
DoDebug (void)
{
  SHORT c, p, sq, tp, tc, tsq, score;
  CHAR s[40];

  ExaminePosition ();
  ShowMessage (CP[22]);
  scanz ("%s", s);
  c = neutral;
  if (s[0] == CP[7][0] || s[0] == CP[7][1])  /* w W*/
    c = white;
  if (s[0] == CP[7][2] || s[0] == CP[7][3])  /*b B*/
    c = black;
  for (p = king; p > no_piece; p--)
    if ((s[1] == pxx[p]) || (s[1] == qxx[p]))
      break;
  for (sq = 0; sq < 64; sq++)
    {
      tp = board[sq];
      tc = color[sq];
      board[sq] = p;
      color[sq] = c;
      tsq = PieceList[c][1];
      PieceList[c][1] = sq;
      ShowPostnValue (sq);
      PieceList[c][1] = tsq;
      board[sq] = tp;
      color[sq] = tc;
    }
  score = ScorePosition (opponent);
  printz (CP[35], score, mtl[computer], pscore[computer], mtl[opponent],pscore[opponent]);

}
void
DoTable (SHORT table[64])
{
  SHORT  sq;
  ExaminePosition ();
  for (sq=0;sq<64;sq++){
  sprintf (msg,"%3d ", table[sq]);
  printz(msg);

}
}
/*SHORT LdisplayLine;
void Ldisplay1(){LdisplayLine=4; ClrScreen();UpdateDisplay (0, 0, 1, 0, 0); }

void Ldisplay2(){
  refresh ();
  getchar ();
  ClrScreen ();
  UpdateDisplay (0, 0, 1, 0, 0);
}

void Ldisplay(char *m, char *h, SHORT count)
{
   gotoXY(50,LdisplayLine);
   LdisplayLine++;
   sprintf(msg,"%s\t%s\t%d\n",m,h,count);
   printz(msg);
}
Ldisplay3()
{ClrScreen();refresh();LdisplayLine=4;}
void Ldisplay4(char *line)
{
        gotoXY(10,LdisplayLine);
        LdisplayLine++;
        sprintf(msg,"%s",line);
        printz(msg);
   refresh();
}  */
