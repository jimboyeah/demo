/*
 * init.c - C source for GNU CHESS for Windows
 *
 * Copyright (c) 1988,1989,1990 John Stanback
 * Copyright (c) 1992 Free Software Foundation
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
#include "gnuchess.h"
#include "ttable.h"
#ifdef HAVE_GETTIMEOFDAY
#include <sys/time.h>
#endif
extern SHORT CompColorExt,WhoseTurnExt,CompMoveExt;
extern SHORT notime;
extern SHORT selected;
extern DWORD CustCols[16];
SHORT WinSizeX,WinSizeY,WinPosX,WinPosY;
RECT wr;
SHORT maximized;
char lpStatic[]="STATIC";

char IniFile[]="gnuchess.ini";

char hexuint[]="%06X";
char shortfs[]="%hd";

char BrdSection[]="board";
char OptSection[]="options";
char skillsectn[]="skill";

char szboardsize[]="boardsize";
char szsquarebd[]="squarebd";
char szwinsizeX[]="winsizeX";
char szwinsizeY[]="winsizeY";
char szwinposX[]="winposX";
char szwinposY[]="winposY";
char szmaximized[]="maximized";
char szbkgrnd[]="background";
char szwhitesq[]="whitesquare";
char szblacksq[]="blacksquare";
char szwhitepc[]="whitepiece";
char szblackpc[]="blackpiece";
char sztext[]="text";
char szedge[]="edge";
char szcustcols[]="cc00";
char szbeep[]="beep";
char szcoords[]="coords";
char szstats[]="stats";
char szbook[]="book";
char szhash[]="hash";
char szhdepth[]="hashdepth";
char szmvlim[]="movelimit";
char szWA[]="WAwindow";
char szWB[]="WBwindow";
char szWX[]="WXwindow";
char szBA[]="BAwindow";
char szBB[]="BBwindow";
char szBX[]="BXwindow";
char szcontempt[]="contempt";
char szmaterial[]="material";
char szrcptr[]="recapture";
char szthreat[]="threat";
char szpvs[]="pvs";
char szne[]="neweval";
char szgamein[]="gamein";
char szXCmv0[]="XCmoves0";
char szXCmin0[]="XCminutes0";
char szXCmv1[]="XCmoves1";
char szXCmin1[]="XCminutes1";
char szXCmv2[]="XCmoves2";
char szXCmin2[]="XCminutes2";
char szXC[]="XC";
char szMRT[]="MaxResponseTime";
char szdither[]="dither";
char szeasy[]="easy";
char szmaxdepth[]="maxdepth";
char sznull[]="";
DWORD CCdefs[16]={CBLACK,BLUE,GREEN,CYAN,RED,PINK,YELLOW,PALEGRAY,DARKGRAY,
      DARKBLUE,DARKGREEN,DARKCYAN,DARKRED,DARKPINK,BROWN,CWHITE};

/* .... MOVE GENERATION VARIABLES AND INITIALIZATIONS .... */


SHORT distdata[64][64], taxidata[64][64];

#ifdef KILLT
/* put moves to the center first */
void
Initialize_killt (void)
{
  register UTSHORT f, t, s;
  register SHORT d;
  for (f = 0; f < 64; f++)
    for (t = 0; t < 64; t++)
      {
   d = taxidata[f][0x1b];
   if (taxidata[f][0x1c] < d)
     d = taxidata[f][0x1c];
   if (taxidata[f][0x23] < d)
     d = taxidata[f][0x23];
   if (taxidata[f][0x24] < d)
     d = taxidata[f][0x24];
   s = d;
   d = taxidata[t][0x1b];
   if (taxidata[t][0x1c] < d)
     d = taxidata[t][0x1c];
   if (taxidata[t][0x23] < d)
     d = taxidata[t][0x23];
   if (taxidata[t][0x24] < d)
     d = taxidata[t][0x24];
   s -= d;
   killt[(f << 8) | t] = s;
   killt[(f << 8) | t | 0x80] = s;
      }
}
#endif
void
Initialize_dist (void)
{
  register SHORT a, b, d, di;

  for (a = 0; a < 64; a++)
    for (b = 0; b < 64; b++)
      {
   d = abs (column (a) - column (b));
   di = abs (row (a) - row (b));
   taxidata[a][b] = d + di;
   distdata[a][b] = (d > di ? d : di);
      }
#ifdef KILLT
  Initialize_killt ();
#endif
}

const SHORT Stboard[64] =
{rook, knight, bishop, queen, king, bishop, knight, rook,
 pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn,
 rook, knight, bishop, queen, king, bishop, knight, rook};
const SHORT Stcolor[64] =
{white, white, white, white, white, white, white, white,
 white, white, white, white, white, white, white, white,
 neutral, neutral, neutral, neutral, neutral, neutral, neutral, neutral,
 neutral, neutral, neutral, neutral, neutral, neutral, neutral, neutral,
 neutral, neutral, neutral, neutral, neutral, neutral, neutral, neutral,
 neutral, neutral, neutral, neutral, neutral, neutral, neutral, neutral,
 black, black, black, black, black, black, black, black,
 black, black, black, black, black, black, black, black};
SHORT board[64], color[64];

/* given epsquare, from where can a pawn be taken? */
const SHORT epmove1[64] =
{0, 1, 2, 3, 4, 5, 6, 7,
 8, 9, 10, 11, 12, 13, 14, 15,
 16, 24, 25, 26, 27, 28, 29, 30,
 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39,
 40, 32, 33, 34, 35, 36, 37, 38,
 48, 49, 50, 51, 52, 53, 54, 55,
 56, 57, 58, 59, 60, 61, 62, 63};
const SHORT epmove2[64] =
{0, 1, 2, 3, 4, 5, 6, 7,
 8, 9, 10, 11, 12, 13, 14, 15,
 25, 26, 27, 28, 29, 30, 31, 23,
 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39,
 33, 34, 35, 36, 37, 38, 39, 47,
 48, 49, 50, 51, 52, 53, 54, 55,
 56, 57, 58, 59, 60, 61, 62, 63};


/*
 * nextpos[piece][from-square] , nextdir[piece][from-square] gives vector of
 * positions reachable from from-square in ppos with piece such that the
 * sequence ppos = nextpos[piece][from-square]; pdir =
 * nextdir[piece][from-square]; u = ppos[sq]; do { u = ppos[u]; if(color[u]
 * != neutral) u = pdir[u]; } while (sq != u); will generate the sequence of
 * all squares reachable from sq.
 *
 * If the path is blocked u = pdir[sq] will generate the continuation of the
 * sequence in other directions.
 */

UCHAR nextpos[8][64][64];
UCHAR nextdir[8][64][64];

/*
 * ptype is used to separate white and black pawns, like this; ptyp =
 * ptype[side][piece] piece can be used directly in nextpos/nextdir when
 * generating moves for pieces that are not black pawns.
 */
const SHORT ptype[2][8] =
{ { no_piece, pawn, knight, bishop, rook, queen, king, no_piece },
  { no_piece, bpawn, knight, bishop, rook, queen, king, no_piece } };

/* data used to generate nextpos/nextdir */
static const SHORT direc[8][8] =
{
   { 0, 0, 0, 0, 0, 0, 0, 0 },
   { 10, 9, 11, 0, 0, 0, 0, 0 },
   { 8, -8, 12, -12, 19, -19, 21, -21 },
   { 9, 11, -9, -11, 0, 0, 0, 0 },
   { 1, 10, -1, -10, 0, 0, 0, 0 },
   { 1, 10, -1, -10, 9, 11, -9, -11 },
   { 1, 10, -1, -10, 9, 11, -9, -11 },
   { -10, -9, -11, 0, 0, 0, 0, 0 } };
static const SHORT max_steps[8] =
{0, 2, 1, 7, 7, 7, 1, 2};
static const SHORT nunmap[120] =
{
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, 0, 1, 2, 3, 4, 5, 6, 7, -1,
  -1, 8, 9, 10, 11, 12, 13, 14, 15, -1,
  -1, 16, 17, 18, 19, 20, 21, 22, 23, -1,
  -1, 24, 25, 26, 27, 28, 29, 30, 31, -1,
  -1, 32, 33, 34, 35, 36, 37, 38, 39, -1,
  -1, 40, 41, 42, 43, 44, 45, 46, 47, -1,
  -1, 48, 49, 50, 51, 52, 53, 54, 55, -1,
  -1, 56, 57, 58, 59, 60, 61, 62, 63, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int InitFlag = false;
void
Initialize_moves (void)

/*
 * This procedure pre-calculates all moves for every piece from every square.
 * This data is stored in nextpos/nextdir and used later in the move
 * generation routines.
 */

{
  SHORT ptyp, po, p0, d, di, s, delta;
  UCHAR *ppos, *pdir;
  SHORT dest[8][8];
  SHORT steps[8];
  SHORT sorted[8];

  for (ptyp = 0; ptyp < 8; ptyp++)
    for (po = 0; po < 64; po++)
      for (p0 = 0; p0 < 64; p0++)
   {
     nextpos[ptyp][po][p0] = (UCHAR) po;
     nextdir[ptyp][po][p0] = (UCHAR) po;
   }
  for (ptyp = 1; ptyp < 8; ptyp++)
    for (po = 21; po < 99; po++)
      if (nunmap[po] >= 0)
   {
     ppos = nextpos[ptyp][nunmap[po]];
     pdir = nextdir[ptyp][nunmap[po]];
     /* dest is a function of direction and steps */
     for (d = 0; d < 8; d++)
       {
         dest[d][0] = nunmap[po];
         delta = direc[ptyp][d];
         if (delta != 0)
      {
        p0 = po;
        for (s = 0; s < max_steps[ptyp]; s++)
          {
            p0 = p0 + delta;

            /*
             * break if (off board) or (pawns only move two
             * steps from home square)
             */
            if ((nunmap[p0] < 0) || (((ptyp == pawn) || (ptyp == bpawn))
                      && ((s > 0) && ((d > 0) || (Stboard[nunmap[po]] != pawn)))))
         break;
            else
         dest[d][s] = nunmap[p0];
          }
      }
         else
      s = 0;

         /*
          * sort dest in number of steps order currently no sort
          * is done due to compability with the move generation
          * order in old gnu chess
          */
         steps[d] = s;
         for (di = d; s > 0 && di > 0; di--)
      if (steps[sorted[di - 1]] == 0)  /* should be: < s */
        sorted[di] = sorted[di - 1];
      else
        break;
         sorted[di] = d;
       }

     /*
      * update nextpos/nextdir, pawns have two threads (capture
      * and no capture)
      */
     p0 = nunmap[po];
     if (ptyp == pawn || ptyp == bpawn)
       {
         for (s = 0; s < steps[0]; s++)
      {
        ppos[p0] = (UCHAR) dest[0][s];
        p0 = dest[0][s];
      }
         p0 = nunmap[po];
         for (d = 1; d < 3; d++)
      {
        pdir[p0] = (UCHAR) dest[d][0];
        p0 = dest[d][0];
      }
       }
     else
       {
         pdir[p0] = (UCHAR) dest[sorted[0]][0];
         for (d = 0; d < 8; d++)
      for (s = 0; s < steps[sorted[d]]; s++)
        {
          ppos[p0] = (UCHAR) dest[sorted[d]][s];
          p0 = dest[sorted[d]][s];
          if (d < 7)
            pdir[p0] = (UCHAR) dest[sorted[d + 1]][0];

          /*
           * else is already initialized
           */
        }
       }
   }
}

void
NewGame (void)

/*
 * Reset the board and other variables to start a new game.
 */

{
  SHORT l;
#ifdef HAVE_GETTIMEOFDAY
  struct timeval tv;
#endif
#ifdef CLIENT
  if(GameCnt >0)ListGame();
  fflush(stdout);
#endif
  compptr = oppptr = 0;
  stage = stage2 = -1;     /* the game is not yet started */
  notime = true;
  if (flag.reverse)InvalidateRect(hWnd,0,true);
flag.illegal=flag.mate=flag.quit=flag.bothsides=flag.onemove=false;
flag.force=flag.back=flag.musttimeout=flag.reverse=false;

#ifdef DEBUG
 flag.nott = flag.noft = flag.nocache = false;
#endif

  computer = black;
  opponent = white;
  GenCnt = NodeCnt = et0 = epsquare =  XCmore = 0;
  xwndw = BXwindow;
  if (!MaxSearchDepth)
    MaxSearchDepth = MAXDEPTH - 1;
  GameCnt = 0;
  Game50 = 1;
  hint = 0x0C14;
  selected=0;
  ZeroRPT ();
  Developed[white] = Developed[black] = false;
  castld[white] = castld[black] = false;
  PawnThreat[0] = CptrFlag[0] = false;
  Pscore[0] = Tscore[0] = 12000;
  for (l = 0; l < TREE; l++)
    Tree[l].f = Tree[l].t = 0;
  if (!InitFlag)
   InitHashCode((unsigned int)1);
  for (l = 0; l < 64; l++)
    {
      board[l] = Stboard[l];
      color[l] = Stcolor[l];
      Mvboard[l] = 0;
    }
  InitializeStats ();
#ifdef HAVE_GETTIMEOFDAY
  gettimeofday(&tv, NULL);
  time0 = tv.tv_sec*100+tv.tv_usec/10000;
#else
  time0 = GetTickCount();
#endif
  ElapsedTime (1);
  flag.regularstart = true;
  Book = flag.usebook ? BOOKFAIL : 0;
  TimeControl.clock[white] = TimeControl.clock[black] = 0;
  SetTimeControl();
  player^=1;
  UpdateClocks();
  player^=1;
  UpdateClocks();

  if (!InitFlag)
    {
      GetOpenings ();
#ifdef CACHE
   etab[0] = (struct etable *)malloc(ETABLE*sizeof(struct etable));
   etab[1] = (struct etable *)malloc(ETABLE*sizeof(struct etable));
   if(etab[0] == NULL || etab[1] == NULL){ ShowMessage(CP[70]);Exit(1);}
#endif
#if ttblsz
      Initialize_ttable();
#endif
      InitFlag = true;
    }
#if ttblsz
   ZeroTTable(0);
#endif /* ttblsz */
#ifdef CACHE
   memset ((CHAR *) etab[0], 0, ETABLE*sizeof(struct etable));
   memset ((CHAR *) etab[1], 0, ETABLE*sizeof(struct etable));
#endif
#ifdef NODITHER
  PCRASH = PCRASHS;
  PCENTER = PCENTERS;
#else
  PCRASH = PCRASHS + (dither?(rand() % PCRASHV):0);
  PCENTER = PCENTERS + (dither?(rand() % PCENTERV):0);
#endif
  ShowPlayers();
  SetWindowText(hComputerMove,"");
  return;
}

void
InitConst (CHAR *lang)
{
  FILE *constfile;
  CHAR s[512];
  CHAR sl[5];
  int len, entry;
  CHAR *p, *q;
flag.illegal=flag.mate=flag.quit=flag.bothsides=flag.onemove=flag.force=false;
flag.autolist=flag.back=flag.musttimeout=false;
flag.searching=flag.editing=flag.replay=false;

  constfile = fopen (LANGFILE, "r");
  if (!constfile)
    {
   constfile = fopen("\\gnuchess\\bin\\gnuchess.lan", "r");
    }
  if (!constfile)
    {
      ShowMessage("NO LANGFILE (file gnuchess.lan not found)");
      exit (1);
    }
  while (fgets (s, sizeof (s), constfile))
    {
      if (s[0] == '!') continue;
      len = strlen (s);
      for (q = &s[len]; q > &s[8]; q--) if (*q == '}') break;
      if (q == &s[8])
   {
     ShowMessage ("Error in gnuchess.lan");
     exit (1);
   }
      *q = '\0';
      if (s[3] != ':' || s[7] != ':' || s[8] != '{')
   {
     sprintf (msg,"Langfile format error %s", s);
     ShowMessage(msg);
     exit (1);
   }
      s[3] = s[7] = '\0';
      if (lang == NULL)
   {
     lang = sl;
     strcpy (sl, &s[4]);
   }
      if (strcmp (&s[4], lang))
   continue;
      entry = atoi (s);
      if (entry < 0 || entry >= CPSIZE)
   {
     ShowMessage ("Langfile number error");
     exit (1);
   }
      for (q = p = &s[9]; *p; p++)
   {
     if (*p != '\\')
       {
         *q++ = *p;
       }
     else if (*(p + 1) == 'n')
       {
         *q++ = '\n';
         p++;
       }
   }
      *q = '\0';
      if (entry < 0 || entry > 255)
   {
     sprintf (msg,"Langfile error %d", entry);
     ShowMessage (msg);
     exit (1);
   }
      CP[entry] = (CHAR *) malloc ((unsigned) strlen (&s[9]) + 1);
      if (CP[entry] == NULL)
   {
     ShowMessage ("Insufficient memory");
     exit (1);
   }
      strcpy (CP[entry], &s[9]);

    }
  fclose (constfile);
}

void GetMetrics(void)
{
   HDC hDC;
   HANDLE hOld,hSysFont;
   TEXTMETRIC tm;
   SIZE size;
   RECT rc;
   GetWindowRect(GetDesktopWindow(),&rc);
   hDC=GetDC(hWnd);
   hFont=CreateFont ( (rc.right-rc.left)/50, 0, 0, 0, FW_NORMAL, 0, 0, 0,
                ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, FIXED_PITCH | FF_SWISS, "Helv" );
   hSysFont=GetStockObject(SYSTEM_FONT);
   hOld=SelectObject(hDC,hFont);
   GetTextMetrics(hDC,&tm);
   LineSpace=tm.tmHeight;
   CharWidth=tm.tmAveCharWidth;
   SelectObject(hDC,hSysFont);
   GetTextMetrics(hDC,&tm);
   SLineSpace=tm.tmHeight;
   GetTextExtentPoint(hDC,CP[74],17,&size);
   CompColorExt=size.cx+25;
   GetTextExtentPoint(hDC,"It is White's move",18,&size);
   WhoseTurnExt=size.cx+25;
   GetTextExtentPoint(hDC,"My move is a7a8q",16,&size);
   CompMoveExt=size.cx+4;
   SelectObject(hDC,hOld);
   ReleaseDC(hWnd,hDC);
}


void InitScreen(void)
{
  SHORT x,y,marginF,marginB,lengthF,lengthB;

  if (squarebd)
  switch (boardsize)
   {
   case SMALL:
     sqwidthF=sqwidthB=sqdepth=bmsize=40;
     break;
   case MEDIUM:
     sqwidthF=sqwidthB=sqdepth=bmsize=60;
     break;
   case LARGE:
     sqwidthF=sqwidthB=sqdepth=bmsize=80;
   }
  else
  switch (boardsize)
   {
   case SMALL:
     sqwidthF=60;
     sqwidthB=42;
     sqdepth=40;
     bmsize=40;
     break;
   case MEDIUM:
     sqwidthF=90;
     sqwidthB=63;
     sqdepth=60;
     bmsize=60;
     break;
   case LARGE:
     sqwidthF=120;
     sqwidthB=84;
     sqdepth=80;
     bmsize=80;
   }
  deltaX=(sqwidthF-sqwidthB)*8;
  for (y=0;y<8;y++)
   {
     marginF=deltaX*y/16;
     marginB=deltaX*(y+1)/16;
     lengthF=sqwidthF*8-(marginF<<1);
     lengthB=sqwidthF*8-(marginB<<1);
     marginF+=LEFTMARGIN;
     marginB+=LEFTMARGIN;
     for (x=0;x<8;x++)
     {
      squares[x][y][0].x=marginF+lengthF*x/8;
      squares[x][y][0].y=(8-y)*sqdepth+BACKMARGIN;
      squares[x][y][1].x=marginF+lengthF*(x+1)/8;
      squares[x][y][1].y=(8-y)*sqdepth+BACKMARGIN;
      squares[x][y][2].x=marginB+lengthB*(x+1)/8;
      squares[x][y][2].y=(7-y)*sqdepth+BACKMARGIN;
      squares[x][y][3].x=marginB+lengthB*x/8;
      squares[x][y][3].y=(7-y)*sqdepth+BACKMARGIN;
      pieceloc[x+(y<<3)].x=lengthF/16-bmsize/2+squares[x][y][0].x;
      pieceloc[x+(y<<3)].y=squares[x][y][2].y;
     }
   }
  boardpg[0]=squares[0][0][0];
  boardpg[1]=squares[7][0][1];
  boardpg[2]=squares[7][7][2];
  boardpg[3]=squares[0][7][3];
}

void CreateStatics(void)
 {
  SHORT CompMoveXpos,YPos;
  YPos=BACKMARGIN+sqdepth*8+LineSpace+BRD_EDGE;
  hComputerColor = CreateWindow (lpStatic, NULL,
                   WS_CHILD | SS_LEFT | WS_VISIBLE,
                   LEFTMARGIN, YPos, CompColorExt, SLineSpace,
                   hWnd, (HMENU)0, hInst, NULL);

  hWhoseTurn = CreateWindow (lpStatic, NULL,
                   WS_CHILD | SS_LEFT | WS_VISIBLE,
                   LEFTMARGIN+CompColorExt, YPos, WhoseTurnExt, SLineSpace,
                   hWnd, (HMENU)1, hInst, NULL);

  hInCheck  = CreateWindow (lpStatic, NULL,
                   WS_CHILD | SS_LEFT | WS_VISIBLE,
                   LEFTMARGIN+CompColorExt+WhoseTurnExt,
                   YPos, 120, SLineSpace,
                   hWnd, (HMENU)2, hInst, NULL);

  hComputerMove = CreateWindow (lpStatic, NULL,
                   WS_CHILD | SS_CENTER | WS_VISIBLE,
                   CompMoveXpos=LEFTMARGIN+sqwidthB*8+deltaX/2+(20>>squarebd),
                   65,CompMoveExt, SLineSpace, hWnd, (HMENU)3, hInst, NULL);

  hClockBlack  =  CreateWindow ( lpStatic, NULL,
                   WS_CHILD | SS_CENTER | WS_VISIBLE,
                   CompMoveXpos+(CompMoveExt-60)/2, 30,
                   60, SLineSpace, hWnd, (HMENU)4, hInst, NULL);

  hClockWhite  =  CreateWindow ( lpStatic, NULL,
                   WS_CHILD | SS_CENTER | WS_VISIBLE,
                   CompMoveXpos+(CompMoveExt-60)/2, 120,
                   60, SLineSpace, hWnd, (HMENU)5, hInst, NULL);

  hBlack       = CreateWindow ( lpStatic, CP[41],
                   WS_CHILD | SS_CENTER | WS_VISIBLE,
                   CompMoveXpos+(CompMoveExt-60)/2, 10,
                   60, SLineSpace, hWnd, (HMENU)6, hInst, NULL);

  hWhite       = CreateWindow ( lpStatic, CP[40],
                   WS_CHILD | SS_CENTER | WS_VISIBLE,
                   CompMoveXpos+(CompMoveExt-60)/2, 100,
                   60, SLineSpace, hWnd, (HMENU)7, hInst, NULL);
  hDepth       = CreateWindow ( lpStatic, NULL,
                   WS_CHILD | SS_CENTER | WS_VISIBLE,
                   CompMoveXpos+(CompMoveExt-80)/2, 150,
                   80, SLineSpace, hWnd, (HMENU)1010, hInst, NULL);
}

void MoveStatics(void)
{
  SHORT CompMoveXpos;

  MoveWindow(hComputerColor,LEFTMARGIN, BACKMARGIN+sqdepth*8+20,
     CompColorExt, SLineSpace, false);
  MoveWindow(hWhoseTurn,LEFTMARGIN+CompColorExt, BACKMARGIN+sqdepth*8+20,
     WhoseTurnExt, SLineSpace, false);
  MoveWindow(hInCheck,LEFTMARGIN+CompColorExt+WhoseTurnExt,
     BACKMARGIN+sqdepth*8+20,120, SLineSpace, false);
  MoveWindow(hComputerMove,CompMoveXpos=LEFTMARGIN+sqwidthB*8+deltaX/2+
    (20>>squarebd), 65, CompMoveExt, SLineSpace, false);
  MoveWindow(hClockBlack,CompMoveXpos+(CompMoveExt-60)/2, 30,
     60, SLineSpace, false);
  MoveWindow(hClockWhite,CompMoveXpos+(CompMoveExt-60)/2, 120,
     60, SLineSpace, false);
  MoveWindow(hBlack,CompMoveXpos+(CompMoveExt-60)/2, 10,
     60, SLineSpace, false);
  MoveWindow(hWhite,CompMoveXpos+(CompMoveExt-60)/2, 100,
     60, SLineSpace, false);
  MoveWindow(hDepth,CompMoveXpos+(CompMoveExt-80)/2, 150,
     80, SLineSpace, false);
}

BOOL LoadSettings(void)
{
 SHORT i;

 boardsize=GetPrivateProfileInt(BrdSection,szboardsize,SMALL,IniFile);
 squarebd=GetPrivateProfileInt(BrdSection,szsquarebd,0,IniFile);
 WinPosX=GetPrivateProfileInt(BrdSection,szwinposX,0,IniFile);
 WinPosY=GetPrivateProfileInt(BrdSection,szwinposY,0,IniFile);
 WinSizeX=GetPrivateProfileInt(BrdSection,szwinsizeX,0,IniFile);
 WinSizeY=GetPrivateProfileInt(BrdSection,szwinsizeY,0,IniFile);
 GetPrivateProfileString(BrdSection,szbkgrnd,sznull,msg,sizeof(msg),IniFile);
 clrBackGround = msg[0] ? strtoul(msg,0,16) : BROWN;
 GetPrivateProfileString(BrdSection,szblacksq,sznull,msg,sizeof(msg),IniFile);
 clrBlackSquare = msg[0] ? strtoul(msg,0,16) : DARKGREEN;
 GetPrivateProfileString(BrdSection,szwhitesq,sznull,msg,sizeof(msg),IniFile);
 clrWhiteSquare = msg[0] ? strtoul(msg,0,16) : PALEGRAY;
 GetPrivateProfileString(BrdSection,szblackpc,sznull,msg,sizeof(msg),IniFile);
 clrBlackPiece = msg[0] ? strtoul(msg,0,16) : DARKRED;
 GetPrivateProfileString(BrdSection,szwhitepc,sznull,msg,sizeof(msg),IniFile);
 clrWhitePiece = msg[0] ? strtoul(msg,0,16) : CWHITE;
 GetPrivateProfileString(BrdSection,sztext,sznull,msg,sizeof(msg),IniFile);
 clrText = msg[0] ? strtoul(msg,0,16) : CBLACK;
 GetPrivateProfileString(BrdSection,szedge,sznull,msg,sizeof(msg),IniFile);
 clrEdge = msg[0] ? strtoul(msg,0,16) : CBLACK;
 for (i=0;i<16;i++)
  {
   szcustcols[2]=(char)i+'0';
   GetPrivateProfileString(BrdSection,szcustcols,sznull,msg,sizeof(msg),IniFile);
   if (msg[0]) CustCols[i]=strtoul(msg,0,16);
   else CustCols[i]=CCdefs[i];
  }
 flag.beep=GetPrivateProfileInt(OptSection,szbeep,1,IniFile);
 flag.coords=GetPrivateProfileInt(OptSection,szcoords,1,IniFile);
 flag.post=GetPrivateProfileInt(OptSection,szstats,0,IniFile);
 flag.usebook=GetPrivateProfileInt(OptSection,szbook,1,IniFile);
 flag.hash=GetPrivateProfileInt(OptSection,szhash,1,IniFile);
 HashDepth=GetPrivateProfileInt(OptSection,szhdepth,HASHDEPTH,IniFile);
 HashMoveLimit=GetPrivateProfileInt(OptSection,szmvlim,HASHMOVELIMIT,IniFile);
 WAwindow=GetPrivateProfileInt(OptSection,szWA,WAWNDW,IniFile);
 WBwindow=GetPrivateProfileInt(OptSection,szWB,WBWNDW,IniFile);
 WXwindow=GetPrivateProfileInt(OptSection,szWX,WXWNDW,IniFile);
 BAwindow=GetPrivateProfileInt(OptSection,szBA,BAWNDW,IniFile);
 BBwindow=GetPrivateProfileInt(OptSection,szBB,BBWNDW,IniFile);
 BXwindow=GetPrivateProfileInt(OptSection,szBX,BXWNDW,IniFile);
 contempt=GetPrivateProfileInt(OptSection,szcontempt,0,IniFile);
 flag.material=GetPrivateProfileInt(OptSection,szmaterial,1,IniFile);
 flag.rcptr=GetPrivateProfileInt(OptSection,szrcptr,1,IniFile);
 flag.threat=GetPrivateProfileInt(OptSection,szthreat,1,IniFile);
 flag.pvs=GetPrivateProfileInt(OptSection,szpvs,1,IniFile);
 flag.neweval=GetPrivateProfileInt(OptSection,szne,1,IniFile);
 flag.gamein=GetPrivateProfileInt(OptSection,szgamein,0,IniFile);
 XCmoves[0]=GetPrivateProfileInt(skillsectn,szXCmv0,0,IniFile);
 XCminutes[0]=GetPrivateProfileInt(skillsectn,szXCmin0,0,IniFile);
 XCmoves[1]=GetPrivateProfileInt(skillsectn,szXCmv1,0,IniFile);
 XCminutes[1]=GetPrivateProfileInt(skillsectn,szXCmin1,0,IniFile);
 XCmoves[2]=GetPrivateProfileInt(skillsectn,szXCmv2,0,IniFile);
 XCminutes[2]=GetPrivateProfileInt(skillsectn,szXCmin2,0,IniFile);
 XC=0;
 for (i=0;i<3;i++)
  {
   if (XCmoves[i] && XCminutes[i])XC++;
   else break;
  }
 GetPrivateProfileString(skillsectn,szMRT,"3000",msg,sizeof(msg),IniFile);
 MaxResponseTime=strtol(msg,0,10);
 dither=GetPrivateProfileInt(skillsectn,szdither,0,IniFile);
 flag.easy=GetPrivateProfileInt(skillsectn,szeasy,1,IniFile);
 MaxSearchDepth=GetPrivateProfileInt(skillsectn,szmaxdepth,MAXDEPTH,IniFile);
 return GetPrivateProfileInt(BrdSection,szmaximized,0,IniFile);
}

void SaveSettings(void)
{
 RECT rect;
 SHORT i;

 sprintf(msg,shortfs,boardsize);
 WritePrivateProfileString(BrdSection,szboardsize,msg,IniFile);
 sprintf(msg,shortfs,squarebd);
 WritePrivateProfileString(BrdSection,szsquarebd,msg,IniFile);
 if (wr.right)
  {
   sprintf(msg,shortfs,wr.left);
   WritePrivateProfileString(BrdSection,szwinposX,msg,IniFile);
   sprintf(msg,shortfs,wr.top);
   WritePrivateProfileString(BrdSection,szwinposY,msg,IniFile);
   sprintf(msg,shortfs,wr.right-wr.left);
   WritePrivateProfileString(BrdSection,szwinsizeX,msg,IniFile);
   sprintf(msg,shortfs,wr.bottom-wr.top);
   WritePrivateProfileString(BrdSection,szwinsizeY,msg,IniFile);
  }
 sprintf(msg,shortfs,maximized);
 WritePrivateProfileString(BrdSection,szmaximized,msg,IniFile);
 sprintf(msg,hexuint,clrBackGround);
 WritePrivateProfileString(BrdSection,szbkgrnd,msg,IniFile);
 sprintf(msg,hexuint,clrBlackSquare);
 WritePrivateProfileString(BrdSection,szblacksq,msg,IniFile);
 sprintf(msg,hexuint,clrWhiteSquare);
 WritePrivateProfileString(BrdSection,szwhitesq,msg,IniFile);
 sprintf(msg,hexuint,clrBlackPiece);
 WritePrivateProfileString(BrdSection,szblackpc,msg,IniFile);
 sprintf(msg,hexuint,clrWhitePiece);
 WritePrivateProfileString(BrdSection,szwhitepc,msg,IniFile);
 sprintf(msg,hexuint,clrText);
 WritePrivateProfileString(BrdSection,sztext,msg,IniFile);
 sprintf(msg,hexuint,clrEdge);
 WritePrivateProfileString(BrdSection,szedge,msg,IniFile);
 for (i=0;i<16;i++)
  {
   sprintf(msg,hexuint,CustCols[i]);
   sprintf(szcustcols+2,shortfs,i);
   WritePrivateProfileString(BrdSection,szcustcols,msg,IniFile);
  }
 sprintf(msg,shortfs,flag.beep);
 WritePrivateProfileString(OptSection,szbeep,msg,IniFile);
 sprintf(msg,shortfs,flag.coords);
 WritePrivateProfileString(OptSection,szcoords,msg,IniFile);
 sprintf(msg,shortfs,flag.post);
 WritePrivateProfileString(OptSection,szstats,msg,IniFile);
 sprintf(msg,shortfs,flag.usebook);
 WritePrivateProfileString(OptSection,szbook,msg,IniFile);
 sprintf(msg,shortfs,flag.hash);
 WritePrivateProfileString(OptSection,szhash,msg,IniFile);
 sprintf(msg,shortfs,HashDepth);
 WritePrivateProfileString(OptSection,szhdepth,msg,IniFile);
 sprintf(msg,shortfs,HashMoveLimit);
 WritePrivateProfileString(OptSection,szmvlim,msg,IniFile);
 sprintf(msg,shortfs,WAwindow);
 WritePrivateProfileString(OptSection,szWA,msg,IniFile);
 sprintf(msg,shortfs,WBwindow);
 WritePrivateProfileString(OptSection,szWB,msg,IniFile);
 sprintf(msg,shortfs,WXwindow);
 WritePrivateProfileString(OptSection,szWX,msg,IniFile);
 sprintf(msg,shortfs,BAwindow);
 WritePrivateProfileString(OptSection,szBA,msg,IniFile);
 sprintf(msg,shortfs,BBwindow);
 WritePrivateProfileString(OptSection,szBB,msg,IniFile);
 sprintf(msg,shortfs,BXwindow);
 WritePrivateProfileString(OptSection,szBX,msg,IniFile);
 sprintf(msg,shortfs,contempt);
 WritePrivateProfileString(OptSection,szcontempt,msg,IniFile);
 sprintf(msg,shortfs,flag.material);
 WritePrivateProfileString(OptSection,szmaterial,msg,IniFile);
 sprintf(msg,shortfs,flag.rcptr);
 WritePrivateProfileString(OptSection,szrcptr,msg,IniFile);
 sprintf(msg,shortfs,flag.threat);
 WritePrivateProfileString(OptSection,szthreat,msg,IniFile);
 sprintf(msg,shortfs,flag.pvs);
 WritePrivateProfileString(OptSection,szpvs,msg,IniFile);
 sprintf(msg,shortfs,flag.neweval);
 WritePrivateProfileString(OptSection,szne,msg,IniFile);
 sprintf(msg,shortfs,flag.gamein);
 WritePrivateProfileString(OptSection,szgamein,msg,IniFile);
 sprintf(msg,shortfs,XCmoves[0]);
 WritePrivateProfileString(skillsectn,szXCmv0,msg,IniFile);
 sprintf(msg,shortfs,XCminutes[0]);
 WritePrivateProfileString(skillsectn,szXCmin0,msg,IniFile);
 sprintf(msg,shortfs,XCmoves[1]);
 WritePrivateProfileString(skillsectn,szXCmv1,msg,IniFile);
 sprintf(msg,shortfs,XCminutes[1]);
 WritePrivateProfileString(skillsectn,szXCmin1,msg,IniFile);
 sprintf(msg,shortfs,XCmoves[2]);
 WritePrivateProfileString(skillsectn,szXCmv2,msg,IniFile);
 sprintf(msg,shortfs,XCminutes[2]);
 WritePrivateProfileString(skillsectn,szXCmin2,msg,IniFile);
 sprintf(msg,"%ld",MaxResponseTime);
 WritePrivateProfileString(skillsectn,szMRT,msg,IniFile);
 sprintf(msg,shortfs,dither);
 WritePrivateProfileString(skillsectn,szdither,msg,IniFile);
 sprintf(msg,shortfs,flag.easy);
 WritePrivateProfileString(skillsectn,szeasy,msg,IniFile);
 sprintf(msg,shortfs,MaxSearchDepth);
 WritePrivateProfileString(skillsectn,szmaxdepth,msg,IniFile);
}
