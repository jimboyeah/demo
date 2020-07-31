/*
 * dspcom.c - C source for GNU CHESS
 *
 * Copyright (c) 1988,1989,1990 John Stanback
 * Copyright (c) 1992 Free Software Foundation
 * Modified by Conor McCarthy for the Windows environment
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
#include "ataks.h"
#include "ttable.h" /* calls ZeroTTable(), probably belongs in main.c*/
#ifdef HAVE_GETTIMEOFDAY
#include <sys/time.h>
#endif
CHAR mvstr[5][7];
#if defined(Think_C) && defined(Window_Events)
#include "doevents.h"
#endif
extern SHORT Mwpawn[64], Mbpawn[64], Mknight[2][64], Mbishop[2][64];
extern CHAR *version, *patchlevel;
extern void LOpeningBook();
#ifdef ECO
extern void EOpeningBook();
SHORT ecomove;
#endif
CHAR *InPtr;
extern SHORT ok;
char filter[]="Chess files (*.chs)\0*.chs\0All files (*.*)\0*.*\0";
int Znodes;
SHORT origplayer,forcing;
void SaveSettings(void);
extern BOOL CALLBACK (*lpfnDlgProc)(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CompileBookDlgProc (HWND, UINT, WPARAM, LPARAM);

#include <ctype.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

void Replay(void);

void
algbr (SHORT f, SHORT t, SHORT flag)

/*
 * Generate move strings in different formats.
 */

{
  int m3p;

  if (f != t)
    {
      /* algebraic notation */
      mvstr[0][0] = cxx[column (f)];
      mvstr[0][1] = rxx[row (f)];
      mvstr[0][2] = cxx[column (t)];
      mvstr[0][3] = rxx[row (t)];
      mvstr[4][0] = mvstr[0][4] = mvstr[3][0] = '\0';
      if (((mvstr[1][0] = pxx[board[f]]) == CP[2][1]) || (flag & promote))
   {
     if (mvstr[0][0] == mvstr[0][2])   /* pawn did not eat */
       {
         mvstr[2][0] = mvstr[1][0] = mvstr[0][2];  /* to column */
         mvstr[2][1] = mvstr[1][1] = mvstr[0][3];  /* to row */
         m3p = 2;
       }
     else
       /* pawn ate */
       {
         mvstr[2][0] = mvstr[1][0] = mvstr[0][0];  /* column */
         mvstr[2][1] = mvstr[1][1] = mvstr[0][2];  /* to column */
         mvstr[2][2] = mvstr[0][3];
         m3p = 3;    /* to row */
       }
     if (flag & promote)
       {
         mvstr[0][4] = mvstr[1][2] = mvstr[2][m3p] = qxx[flag & pmask];
         mvstr[0][5] = mvstr[1][3] = mvstr[2][m3p + 1] = mvstr[3][0] = '\0';
#ifdef CHESSTOOL 
         mvstr[3][0] = mvstr[0][0]; /* Allow e7e8 for chesstool */
         mvstr[3][1] = mvstr[0][1];
         mvstr[3][2] = mvstr[0][2];
         mvstr[3][3] = mvstr[0][3];
         mvstr[3][4] = '\0';
#endif
       } else mvstr[2][m3p] = mvstr[1][2] = '\0';
   }
      else
   /* not a pawn */
   {
     mvstr[2][0] = mvstr[1][0];
     mvstr[2][1] = mvstr[0][1];
     mvstr[2][2] = mvstr[1][1] = mvstr[0][2];   /* to column */
     mvstr[2][3] = mvstr[1][2] = mvstr[0][3];   /* to row */
     mvstr[2][4] = mvstr[1][3] = '\0';
     strcpy (mvstr[3], mvstr[2]);
          mvstr[3][1] = mvstr[0][0];
     mvstr[4][0] = mvstr[1][0]; strcpy(&mvstr[4][1],mvstr[0]);
     if (flag & cstlmask)
       {
         if (t > f)
      {
        strcpy (mvstr[1], mvstr[0]);
        strcpy (mvstr[0], CP[3]);
        strcpy (mvstr[2], CP[5]);
      }
         else
      {
        strcpy (mvstr[1], mvstr[0]);
        strcpy (mvstr[0], CP[4]);
        strcpy (mvstr[2], CP[6]);
      }
       }
   }
    }
  else
    mvstr[0][0] = mvstr[1][0] = mvstr[2][0] = mvstr[3][0] = mvstr[4][0] = '\0';
}


int
VerifyMove (CHAR *s, SHORT iop, UTSHORT *mv)

/*
 * Compare the string 's' to the list of legal moves available for the
 * opponent. If a match is found, make the move on the board.
 */

{
  static SHORT pnt, tempb, tempc, tempsf, tempst, cnt;
  static struct leaf xnode;
  struct leaf *node;
  *mv = 0;

  if (iop == 2)
    {
      UnmakeMove (opponent, &xnode, &tempb, &tempc, &tempsf, &tempst);
      return (false);
    }
  cnt = 0;
  VMoveList (opponent, 2);
  pnt = TrPnt[2];
  while (pnt < TrPnt[3])
    {
      node = &Tree[pnt++];
      algbr (node->f, node->t, (SHORT) node->flags);
      if (strcmp (s, mvstr[0]) == 0 || strcmp (s, mvstr[1]) == 0 ||
     strcmp (s, mvstr[2]) == 0 || strcmp (s, mvstr[3]) == 0
      || strcmp (s, mvstr[4]) == 0)
   {
     cnt++;
     xnode = *node;
   }
    }
  if (cnt == 1)
    {
      MakeMove (opponent, &xnode, &tempb, &tempc, &tempsf, &tempst);
      if (SqAtakd (PieceList[opponent][0], computer))
   {
     UnmakeMove (opponent, &xnode, &tempb, &tempc, &tempsf, &tempst);
#ifdef DEBUG8
  if (1)
    {   
      FILE *D;
      int r, c, l;
      extern UTSHORT PrVar[];
      D = fopen ("DEBUG", "a+");
      pnt = TrPnt[2];
      fprintf (D, "resp = %ld\n", ResponseTime);
      fprintf (D, "iop = %d\n", iop);
      fprintf (D, "matches = %d\n", cnt);
      algbr (hint >> 8, hint & 0xff, (SHORT) 0);
      fprintf (D, "hint %s\n", mvstr[0]);
      fprintf (D, "inout move is %s\n", s);
      for (r = 1; PrVar[r]; r++)
        {
          algbr (PrVar[r] >> 8, PrVar[r] & 0xff, (SHORT) 0);
          fprintf (D, " %s", mvstr[0]);
        }
      fprintf (D, "\n");
      fprintf (D, "legal move are \n");
      while (pnt < TrPnt[3])
        {
          node = &Tree[pnt++];
          algbr (node->f, node->t, (SHORT) node->flags);
          fprintf (D, "%s %s %s %s %s\n", mvstr[0], mvstr[1], mvstr[2], mvstr[3],mvstr[4]);
        } 
      fprintf (D, "\n current board is\n");
      for (r = 7; r >= 0; r--)
        {
          for (c = 0; c <= 7; c++)
            {
              l = locn (r, c);
              if (color[l] == neutral)
                fprintf (D, " -");
              else if (color[l] == white)
                fprintf (D, " %c", qxx[board[l]]);
              else
                fprintf (D, " %c", pxx[board[l]]);
            }
          fprintf (D, "\n");
        }
      fprintf (D, "\n");
      fclose (D);
    }  
#endif 

/* Illegal move in check */
     ShowMessage (CP[27]);

     return (false);
   }
      else
   {
     if (iop == 1)
       return (true);
     UpdateDisplay (xnode.f, xnode.t, 0, (SHORT) xnode.flags, 0);
     if ((board[xnode.t] == pawn)
         || (xnode.flags & capture)
         || (xnode.flags & cstlmask))
       {
         Game50 = GameCnt;
         ZeroRPT ();
       }
     GameList[GameCnt].depth = GameList[GameCnt].score = 0;
     GameList[GameCnt].nodes = 0;
     ElapsedTime (1);
     GameList[GameCnt].time = (SHORT) (et+50)/100;
     if (TCflag)
       {
         TimeControl.clock[opponent] -= (et-TCadd);
         timeopp[oppptr] = et;
         --TimeControl.moves[opponent];
       }
     *mv = (xnode.f << 8) | xnode.t;
     algbr (xnode.f, xnode.t, false);
     return (true);
   }
    }
#ifdef DEBUG8
  if (1)
    {
      FILE *D;
      int r, c, l;
      extern UTSHORT PrVar[];
      D = fopen ("DEBUG", "a+");
      pnt = TrPnt[2];
      fprintf (D, "resp = %ld\n", ResponseTime);
      fprintf (D, "iop = %d\n", iop);
      fprintf (D, "matches = %d\n", cnt);
      algbr (hint >> 8, hint & 0xff, (SHORT) 0);
      fprintf (D, "hint %s\n", mvstr[0]);
      fprintf (D, "inout move is %s\n", s);
      for (r = 1; PrVar[r]; r++)
   {
     algbr (PrVar[r] >> 8, PrVar[r] & 0xff, (SHORT) 0);
     fprintf (D, " %s", mvstr[0]);
   }
      fprintf (D, "\n");
      fprintf (D, "legal move are \n");
      while (pnt < TrPnt[3])
   {
     node = &Tree[pnt++];
     algbr (node->f, node->t, (SHORT) node->flags);
     fprintf (D, "%s %s %s %s %s\n", mvstr[0], mvstr[1], mvstr[2], mvstr[3],mvstr[4]);
   }
      fprintf (D, "\n current board is\n");
      for (r = 7; r >= 0; r--)
   {
     for (c = 0; c <= 7; c++)
       {
         l = locn (r, c);
         if (color[l] == neutral)
      fprintf (D, " -");
         else if (color[l] == white)
      fprintf (D, " %c", qxx[board[l]]);
         else
      fprintf (D, " %c", pxx[board[l]]);
       }
     fprintf (D, "\n");
   }
      fprintf (D, "\n");
      fclose (D);
    }
#endif
/* Illegal move */
  ShowMessage (CP[26]);
  if (cnt > 1)
    ShowMessage (CP[10]);
  return (false);
}

int
parser (CHAR *f, int side)
{
  int c1, r1, c2, r2;

  if (f[4] == 'o')
    if (side == black)
      return 0x3C3A;
    else
      return 0x0402;
  else if (f[0] == 'o')
    if (side == black)
      return 0x3C3E;
    else
      return 0x0406;
  else
    {
      c1 = f[0] - 'a';
      r1 = f[1] - '1';
      c2 = f[2] - 'a';
      r2 = f[3] - '1';
      return (locn (r1, c1) << 8) | locn (r2, c2);
    }
  /*NOTREACHED*/
}

SHORT
GetGame (void)
{
  FILE *fd;
  CHAR fname[256], *p;
  int c, i, j;
  int eps = -1;
  int side;
  SHORT sq;
  OPENFILENAME ofn;
  fname[0]='\0';
  memset(&ofn,0,sizeof(ofn));
  ofn.hwndOwner=hWnd;
  ofn.lpstrFilter=filter;
  ofn.nFilterIndex=1;
  ofn.lpstrFile=fname;
  ofn.nMaxFile=256;
  ofn.lpstrTitle="Open Game";
#ifdef WIN32
  ofn.Flags=OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_EXPLORER;
#else
  ofn.Flags=OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
#endif
  ofn.lStructSize=sizeof(ofn);
  if (!GetOpenFileName(&ofn))return false;
  if (fname[0] == '\0')
    strcpy (fname, CP[44]);   /* chess.000 */
  if ((fd = fopen (fname, "r")) != NULL)
    {
      NewGame ();
      fgets (fname, 256, fd);
      computer = opponent = white;
      InPtr = fname;
      skip ();
      if (*InPtr == 'c')
   computer = black;
      else
   opponent = black;
      skip ();
      skip ();
      skip ();
      Game50 = atoi (InPtr);
      skip();
      skip();
      eps = atoi(InPtr);
      fgets (fname, 256, fd);
      InPtr = &fname[14];
      castld[white] = ((*InPtr == CP[53][0]) ? true : false);
      skip ();
      skip ();
      castld[black] = ((*InPtr == CP[53][0]) ? true : false);
      fgets (fname, 256, fd);
      InPtr = &fname[11];
      skipb ();
      TCflag = atoi (InPtr);
      skip ();
      InPtr += 14;
      skipb ();
      OperatorTime = atoi (InPtr);
      fgets (fname, 256, fd);
      InPtr = &fname[11];
      skipb ();
      TimeControl.clock[white] = atol (InPtr);
      skip ();
      skip ();
      TimeControl.moves[white] = atoi (InPtr);
      fgets (fname, 256, fd);
      InPtr = &fname[11];
      skipb ();
      TimeControl.clock[black] = atol (InPtr);
      skip ();
      skip ();
      TimeControl.moves[black] = atoi (InPtr);
      fgets (fname, 256, fd);
      for (i = 7; i > -1; i--)
   {
     fgets (fname, 256, fd);
     p = &fname[2];
     InPtr = &fname[11];
     skipb ();
     for (j = 0; j < 8; j++)
       {
         sq = i * 8 + j;
         if (*p == '.')
      {
        board[sq] = no_piece;
        color[sq] = neutral;
      }
         else
      {
        for (c = 0; c < 8; c++)
          {
            if (*p == pxx[c])
         {
           board[sq] = c;
           color[sq] = black;
         }
          }
        for (c = 0; c < 8; c++)
          {
            if (*p == qxx[c])
         {
           board[sq] = c;
           color[sq] = white;
         }
          }
      }
         p++;
         Mvboard[sq] = atoi (InPtr);
         skip ();
       }
   }
      GameCnt = 0;
      flag.regularstart = true;
      Book = BOOKFAIL;
      fgets (fname, 256, fd);
      fgets (fname, 256, fd);
      fgets (fname, 256, fd);
      side = black;
      while (fgets (fname, 256, fd))
   {
     struct GameRec *g;

     ++GameCnt;
     InPtr = fname;
     skipb ();
     g = &GameList[GameCnt];
     side = side ^ 1;
     g->gmove = parser (InPtr, side);
     skip ();
     g->score = atoi (InPtr);
     skip ();
     g->depth = atoi (InPtr);
     skip ();
     g->nodes = atol (InPtr);
     skip ();
     g->time = atol (InPtr);
     skip ();
     g->flags = c = atoi (InPtr);
     skip ();
#ifdef HAVE_STRTOUL
     g->hashkey = strtoul (InPtr, (CHAR **) NULL, 16);
     skip ();
     g->hashbd = strtoul (InPtr, (CHAR **) NULL, 16);
#else
     g->hashkey = strtol (InPtr, (CHAR **) NULL, 16);
     skip ();
     g->hashbd = strtol (InPtr, (CHAR **) NULL, 16);
#endif
     skip ();
     g->epssq = atoi(InPtr);
     g->piece = no_piece;
     g->color = neutral;
     if (c & (capture | cstlmask))
       {
         if (c & capture)
      {
        skip ();
        for (c = 0; c < 8; c++)
          if (pxx[c] == *InPtr)
            break;
        g->piece = c;
      }
         skip ();
         g->color = ((*InPtr == CP[41][0]) ? black : white);
       }
   }
/*      if (TimeControl.clock[white] > 0)
   TCflag = true; */
      if (TCflag == false && !MaxResponseTime)
         MaxResponseTime = 3000;
      fclose (fd);
      ZeroRPT ();
      InitializeStats ();
      epsquare = eps;
      UpdateDisplay (0, 0, 1, 0, 0);
      ShowPlayers();
      Sdepth = 0;
      hint = 0;
      return true;
    }
   else
    {
     ShowMessage("Could not open file");
     return false;
    }
}

void
SaveGame (void)
{
  FILE *fd;
  CHAR fname[256];
  SHORT sq, i, c, f, t;
  CHAR p;
  OPENFILENAME ofn;

  fname[0]='\0';
  memset(&ofn,0,sizeof(ofn));
  ofn.hwndOwner=hWnd;
  ofn.lpstrFilter=filter;
  ofn.nFilterIndex=1;
  ofn.lpstrFile=fname;
  ofn.nMaxFile=256;
  ofn.lpstrTitle="Save Game";
#ifdef WIN32
  ofn.Flags=OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_EXPLORER;
#else
  ofn.Flags=OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
#endif
  ofn.lStructSize=sizeof(ofn);
  ofn.lpstrDefExt="chs";
  if (!GetSaveFileName(&ofn))return;
  if (fname[0] == '\0')
/* chess.000 */
    strcpy (fname, CP[44]);
  if ((fd = fopen (fname, "w")) != NULL)
    {
      CHAR *b, *w;

      b = w = CP[24];
      if (computer == black)
   b = CP[45];
      if (computer == white)
   w = CP[45];
      fprintf (fd, CP[13], b, w, Game50,epsquare);
      fprintf (fd, CP[14], castld[white] ? CP[53] : CP[54], castld[black] ? CP[53] : CP[54]);
      fprintf (fd, CP[37], TCflag, OperatorTime);
      fprintf (fd, CP[39],
          TimeControl.clock[white], TimeControl.moves[white],
          TimeControl.clock[black], TimeControl.moves[black]);
      for (i = 7; i > -1; i--)
   {
     fprintf (fd, "%1d ", i + 1);
     for (c = 0; c < 8; c++)
       {
         sq = i * 8 + c;
         switch (color[sq])
      {
      case black:
        p = pxx[board[sq]];
        break;
      case white:
        p = qxx[board[sq]];
        break;
      default:
        p = '.';
      }
         fprintf (fd, "%c", p);
       }
     for (f = i * 8; f < i * 8 + 8; f++)
       fprintf (fd, " %d", Mvboard[f]);
     fprintf (fd, "\n");
   }
      fprintf (fd, "  %s\n", cxx);
      fprintf (fd, CP[43]);
      for (i = 1; i <= GameCnt; i++)
   {
     struct GameRec *g = &GameList[i];

     f = g->gmove >> 8;
     t = (g->gmove & 0xFF);
     algbr (f, t, g->flags);
     fprintf (fd, "%s %5d %5d %7ld %6ld %5d  %#08lx %#08lx %d %c   %s\n",
         mvstr[0], g->score, g->depth,
         g->nodes, g->time, g->flags, g->hashkey, g->hashbd,g->epssq,
      pxx[g->piece], (((int)(g->color) == 2) ? (CHAR *)"     " : ColorStr[g->color]));
   }
      fclose (fd);
/* Game saved */
      ShowMessage (CP[23]);
    }
  else
    /*ShowMessage ("Could not open file");*/
    ShowMessage (CP[17]);
}

void
ListGame (void)
{
  FILE *fd;
  SHORT i, f, t;
  CHAR fname[256];
  OPENFILENAME ofn;

  fname[0]='\0';
  memset(&ofn,0,sizeof(ofn));
  ofn.hwndOwner=hWnd;
  ofn.lpstrFilter="List files (*.lst)\0*.lst\0";
  ofn.nFilterIndex=1;
  ofn.lpstrFile=fname;
  ofn.nMaxFile=256;
  ofn.lpstrTitle="List Game In...";
#ifdef WIN32
  ofn.Flags=OFN_HIDEREADONLY|OFN_EXPLORER;
#else
  ofn.Flags=OFN_HIDEREADONLY;
#endif
  ofn.lStructSize=sizeof(ofn);
  if (!GetSaveFileName(&ofn))return;
  fd = fopen (fname, "w");
  if (!fd)
    {
      sprintf (msg,CP[55], fname);
      ShowMessage(msg);
      return;
    }
  /*fprintf (fd, "gnuchess game %d\n", u);*/
  fprintf (fd, CP[48], patchlevel);
  fprintf (fd, CP[8]);
  fprintf (fd, CP[9]);
  for (i = 1; i <= GameCnt; i++)
    {
      f = GameList[i].gmove >> 8;
      t = (GameList[i].gmove & 0xFF);
      algbr (f, t, GameList[i].flags);
      if(GameList[i].flags & book)
          fprintf (fd, "%6s  %5d    Book%7ld %5ld", mvstr[0],
          GameList[i].score, 
          GameList[i].nodes, GameList[i].time);
      else
          fprintf (fd, "%6s  %5d     %2d %7ld %5ld", mvstr[0],
          GameList[i].score, GameList[i].depth,
          GameList[i].nodes, GameList[i].time);
      if ((i % 2) == 0)
   {
#ifdef DEBUG40
   if(computer == black){
     int p;
   for(p=0;GameList[i-1].d1[p] && p < 7;p++){
      algbr((GameList[i-1].d1[p]>>8) & 0xff,GameList[i-1].d1[p] & 0xff,0);
           fprintf(fd," %s",mvstr[0]);
   }
   fprintf(fd,"\n");
   } else {
   int p;
   for(p=0;GameList[i].d1[p] && p < 7;p++){
      algbr(GameList[i].d1[p]>>8 & 0xff,GameList[i].d1[p] & 0xff,0);
           fprintf(fd," %s",mvstr[0]);
   }
   fprintf(fd,"\n");
   }
#else
   fprintf(fd,"\n");
#endif
    }
   }
  fprintf (fd, "\n\n");
  if (GameList[GameCnt].flags & draw)
    {
      fprintf (fd, CP[20], DRAW);
    }
  else if (GameList[GameCnt].score == -9999)
    {
      fprintf (fd, "%s\n", ColorStr[player ]);
    }
  else if (GameList[GameCnt].score == 9998)
    {
      fprintf (fd, "%s\n", ColorStr[player ^ 1]);
    }
  fclose (fd);
}

void
Undo (void)

/*
 * Undo the most recent half-move.
 */

{
  SHORT f, t;
  f = GameList[GameCnt].gmove >> 8;
  t = GameList[GameCnt].gmove & 0xFF;
  if (board[t] == king && distance (t, f) > 1)
    (void) castle (GameList[GameCnt].color, f, t, 2);
  else
    {
      /* Check for promotion: */
      if (GameList[GameCnt].flags & promote)
   {
     board[t] = pawn;
   }
      board[f] = board[t];
      color[f] = color[t];
      board[t] = GameList[GameCnt].piece;
      color[t] = GameList[GameCnt].color;
      if (color[t] != neutral)
   Mvboard[t]--;
      Mvboard[f]--;
    }
  if (GameList[GameCnt].flags & epmask)
    EnPassant (otherside[color[f]], f, t, 2);
  else
    InitializeStats ();
  epsquare = GameList[GameCnt].epssq;
  if (TCflag && (TCmoves>1))
    ++TimeControl.moves[color[f]];
  hashkey = GameList[GameCnt].hashkey;
  hashbd = GameList[GameCnt].hashbd;
  GameCnt--;
  flag.mate = false;
  hint = 0;
  Sdepth = 0;
  origplayer ^= 1;
  ShowSidetoMove ();
/*
  if (flag.regularstart)
*/
  if (flag.usebook) Book = BOOKFAIL;
}

SHORT
 TestSpeed (void (*f) (SHORT side, SHORT ply))
{
  unsigned i;
  long cnt, rate=0, t1, t2;

  t1 = GetTickCount();
  for (i = 0; i < 5000; i++)
    {
      f (opponent, 2);
    }
  t2 = GetTickCount();
  cnt = 5000L * (TrPnt[3] - TrPnt[2]);
  if (t2!=t1)rate = cnt*1000/(t2-t1);
  sprintf(msg,"Nodes= %u, Nodes/Sec= %u", cnt, rate);
  MessageBox(0,msg,"",0);
  return(TrPnt[3] - TrPnt[2]);
}

void
 TestPSpeed (SHORT (*f) (SHORT side), unsigned j)
{
  SHORT i;
  long cnt, rate, t1, t2;
#ifdef HAVE_GETTIMEOFDAY
struct timeval tv;
#endif

#ifdef HAVE_GETTIMEOFDAY
  gettimeofday(&tv,NULL);
  t1 = (tv.tv_sec*100+(tv.tv_usec/10000));
#else
  t1 = time (0);
#endif
  for (i = 0; i < j; i++)
    {
      (void) f (opponent);
    }
#ifdef HAVE_GETTIMEOFDAY
  gettimeofday(&tv,NULL);
  t2 = (tv.tv_sec*100+(tv.tv_usec/10000));
#else
  t2 = time (0);
#endif
  cnt = j;
  if (t2 - t1)
    et = (t2 - t1);
  else
    et = 1;
  rate = (et) ? ((cnt*100) / et) : 0;
  /*printz ("Nodes= %ld Nodes/sec= %ld\n", cnt, rate);*/
  ShowNodeCnt (cnt);
}

void
InputCommand (void)

/*
 * Process the users command. If easy mode is OFF (the computer is thinking
 * on opponents time) and the program is out of book, then make the 'hint'
 * move on the board and call SelectMove() to find a response. The user
 * terminates the search by entering ^C (quit siqnal) before entering a
 * command. If the opponent does not make the hint move, then set Sdepth to
 * zero.
 */

{
#ifdef QUIETBACKGROUND
  SHORT have_shown_prompt = false;
#endif
  SHORT tmp;
  UTSHORT mv;
  CHAR s[80], sx[80];
  CHAR *p, *q;

#if defined CHESSTOOL
  SHORT normal = false;
#endif

  ok = flag.quit = flag.bothsides = false;
  if (command>0 && !(command & 0x8000))origplayer=computer;
  else origplayer=opponent;
  command&=0x7FFF;
  ElapsedTime(1);
  player = opponent;
/* if transposition table is filling start it over */
 ZeroTTable(1); /* clear ageing table entries */
/* if we have a move for our opponent, and we are thinking on his time, and not in force mode */
  if (hint > 0 && !flag.easy && !flag.force && !command)
/* if the hint is a promotion don't do anything, we don't know what to promote to. */
    if ((board[hint >> 8] != pawn) || ((row (hint & 0x3f) != 0) && (row (hint & 0x3f) != 7)))
      {
   ft = time0;
/* create the hint move as string so we can do it */
   algbr ((SHORT) hint >> 8, (SHORT) hint & 0x3f, false);
   strcpy (s, mvstr[0]);
   tmp = epsquare;
#ifdef DEBUG12
#include "debug12.h"
#endif
   SaveBoard();
/* do the hint move */
   if (VerifyMove (s, 1, &mv))
     {
#ifdef QUIETBACKGROUND
       ShowSidetoMove ();
       have_shown_prompt = true;
#endif /* QUIETBACKGROUND */
/* would love to put null move in here */
/* after we make the hint move make a 2 ply search with both plys our moves */
/* think on opponents time */
       SelectMove (computer, 2);
/* undo the hint and carry on */
       VerifyMove (s, 2, &mv);
     }
   epsquare = tmp;
   time0 = ft;
      }
  while (!(ok || flag.quit))
    {
#if defined CHESSTOOL
      normal = false;
#endif
      player = opponent;
#ifdef QUIETBACKGROUND
      if (!have_shown_prompt)
   {
#endif /* QUIETBACKGROUND */
     ShowSidetoMove ();
#ifdef QUIETBACKGROUND
   }
      have_shown_prompt = false;
#endif /* QUIETBACKGROUND */
      while (!command)
       {
         CheckMessage();
         ElapsedTime(0);
       }
      if (flag.quit)Exit(0);
      strcpy(sx,move);
      sscanf (sx, "%s", s);
      if (command>100)
      {
       short cmnd;
       cmnd=command;
       command=0;
       switch (cmnd)
       {
        case IDM_NEW:
          origplayer=white;
          NewGame();
          UpdateDisplay(0,0,1,0,0);
          break;
        case IDM_GET:
          if (!GetGame())
           {
            player=origplayer;
            if (player==computer)ok=true;
           }
          else origplayer=opponent;
          break;
        case IDM_SAVE:
          SaveGame();
          break;
        case IDM_LIST:
          ListGame();
          player=origplayer;
          if (player==computer)ok=true;
          break;
        case IDM_QUIT:
          flag.quit=true;
          break;
        case IDM_EDIT:
          EditBoard();
          origplayer=opponent;
          hint=0;
          break;
        case IDM_REVIEW:
          Replay();
          player=origplayer;
          if (player==computer)ok=true;
          break;
        case IDM_REMOVE:
          Undo();
        case IDM_UNDO:
          Undo();
          player=origplayer;
          if (player==computer) ok = true;
          UpdateDisplay (0, 0, 1, 0, 0);
          break;
        case IDM_FORCE:
          flag.force = !flag.force;
          flag.bothsides = false;
          if (!flag.force && forcing)
           {
            Sdepth=0;
            ok=true;
            computer^=1;
            opponent^=1;
           }
          else
           {
            if (origplayer==opponent) forcing=0;
            else
             {
              forcing=1;
              computer^=1;
              opponent^=1;
             }
           }
          break;
        case IDM_COMPILE:
          lpfnDlgProc = MakeProcInstance ( CompileBookDlgProc, hInst);
          DialogBox ( hInst, MAKEINTRESOURCE(COMPILEBOOK), hWnd,
                lpfnDlgProc);
          FreeProcInstance ( lpfnDlgProc);
          break;
        case IDM_BOTH:
         flag.bothsides = true;
         if (flag.force && forcing)
          {
           computer^=1;
           opponent^=1;
          }
         flag.force=false;
         Sdepth = 0;
         ElapsedTime (1);
         SaveBoard();
         SelectMove (opponent, 1);
         ok = true;
         break;

        case IDM_SWITCHDM:
          player=origplayer=computer;
        case IDM_SWITCH:
          computer = computer ^ 1;
          opponent = opponent ^ 1;
          xwndw = (computer == white) ? WXwindow : BXwindow;
          goto changeside;
        case IDM_WHITE:
        case IDM_BLACK:
         {
          SHORT color=(cmnd-IDM_BLACK)^1;
          if (computer==color^(flag.force && forcing))continue;
          if (flag.force && forcing)
           {
            computer = color^1;
            opponent = color;
           }
          else
           {
            computer = color;
            opponent = color^1;
           }
          xwndw = computer==white ? WXwindow : BXwindow;
         }
changeside:
          if (!flag.force)
           {
            Sdepth = 0;
            player=origplayer;
            if (player==computer) ok=true;
            ShowPlayers ();
           }
          else
           {
            computer^=forcing;
            ShowPlayers();
            computer^=forcing;
            computer^=1;
            opponent^=1;
            forcing^=1;
           }
          if (computer^(flag.force & forcing)==flag.reverse)
           {
            flag.reverse=!(computer^(flag.force & forcing));
            InvalidateRect(hWnd,0,true);
            UpdateWindow(hWnd);
           }
          hint=0;
          break;
        case IDM_WTM:
        case IDM_BTM:
          player = origplayer = (cmnd==IDM_WTM)? white : black;
          if (player==computer)ok = true;
          if (flag.force)
           {
            computer = opponent;
            opponent = computer ^ 1;
            forcing ^= 1;
           }
          InitializeStats(); /*May crash or make illegal move without this.*/
       }
      }
   else
   {
/* It must be a move */
/* preprocess move;
   remove x or +
   change promotion from h1=Q to h1q
*/
   p=s; q=sx;
   while (*p != '\0'){
   if(*p == 'x' || *p == '+') p++;
   else if(*p == '='){ p++; *q = tolower(*p); p++; q++;}
      else {*q++ = *p++; }
   }
   *q = '\0';

   ok = VerifyMove (sx, 0, &mv);
   command=0;
   if (flag.force && ok)
    {
      hint=0;
      computer = opponent;
      opponent = computer ^ 1;
      forcing ^= 1;
    }
   }
    }

  /* guess is correct ?*/
  Sdepth = (hint == mv) ? Sdepth-1 : 0;
  if (Tree[0].score > 9000) Sdepth = 0;

}

#ifdef HAVE_GETTIMEOFDAY
void
ElapsedTime (SHORT iop)


/*
 * Determine the time that has passed since the search was started. If the
 * elapsed time exceeds the target (ResponseTime+ExtraTime) then set timeout
 * to true which will terminate the search. iop = 0 calculate et bump ETnodes
 * iop = 1 calculate et set timeout if time exceeded, calculate et
 */

{ long old_et;
  struct timeval tv;

  old_et=et;
  gettimeofday(&tv,NULL);
  et = (tv.tv_sec*100+(tv.tv_usec/10000)) - time0;
  ETnodes = NodeCnt + Znodes;
  if (et < 0)
    et = 0;
  if (iop == 1)
    {
      if (et > ResponseTime + ExtraTime && Sdepth > MINDEPTH)
   flag.timeout = true;
      ETnodes = NodeCnt + Znodes;
      gettimeofday(&tv,NULL);
      time0 = tv.tv_sec*100+tv.tv_usec/10000;
    }
#if !defined NONDSP
#ifdef QUIETBACKGROUND
  if (!background)
#endif /* QUIETBACKGROUND */
    if(et/100>old_et/100 && !flag.mate)UpdateClocks ();
#endif
#if defined(Think_C) && defined(Window_Events)
        check_events();
#endif

}
#else
void
ElapsedTime (SHORT iop)

/*
 * Determine the time that has passed since the search was started. If the
 * elapsed time exceeds the target (ResponseTime+ExtraTime) then set timeout
 * to true which will terminate the search. iop = 0 calculate et bump ETnodes
 * iop = 1 calculate et set timeout if time exceeded, calculate et
 */
{ long old_et;

  old_et=et;
  et = (GetTickCount() - time0)/10;
  ETnodes = NodeCnt + Znodes;
  if (et < 0)
    et = -et;
  if (iop == 1)
    {
      if (et > ResponseTime + ExtraTime && Sdepth > MINDEPTH)
   flag.timeout = true;
      ETnodes = NodeCnt + Znodes;
      time0 = GetTickCount();
    }
#ifdef QUIETBACKGROUND
  if (!background)
#endif /* QUIETBACKGROUND */
    if (et/100>old_et/100 && !flag.mate)UpdateClocks ();
#if defined(Think_C) && defined(Window_Events)
        check_events();
#endif
}
#endif


static SHORT Nmoves[] = NMOVEINIT;
void
SetTimeControl (void)
{
     flag.gamein = TCflag = false;
      TimeControl.moves[white] = TimeControl.moves[black] = 0;
if (XC){
                  if (XCmore < XC)
                    {
                      TCmoves = XCmoves[XCmore];
                      TCminutes = XCminutes[XCmore];
                      TCseconds = XCseconds[XCmore];
            TCadd = XCadd[XCmore];
                      XCmore++;
                    }
      if((TCminutes+TCseconds) == 0){TCflag = false;} else {
      TCflag = true;
      if(TCmoves == 0)
   {int i; i = (TCminutes*60+TCseconds + 40 * (TCadd/100))/60; 
      if(i > NMOVELIMIT) i = NMOVELIMIT; 
      TCmoves = Nmoves[i]; flag.gamein = true;}
   else flag.gamein = false;
      TimeControl.moves[white] = TimeControl.moves[black] = TCmoves;
      TimeControl.clock[white] += 6000L * TCminutes + TCseconds * 100;
      TimeControl.clock[black] += 6000L * TCminutes + TCseconds * 100;
    }
  }
  flag.onemove = (TCmoves == 1);
  et = 0;
  ElapsedTime (1);
}
