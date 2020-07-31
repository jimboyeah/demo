/*
 * search.c - C source for GNU CHESS
 *
 * Copyright (c) 1988,1989,1990 John Stanback
 * Copyright (c) 1992 Free Software Foundation
 * Modified by Conor McCarthy for the Windows environment
 *
 * This file is part of GNU CHESS.
 *
 * GNU Chess is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any later
 * version.
 *
 * GNU Chess is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * GNU Chess; see the file COPYING.  If not, write to the Free Software
 * Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include "gnuchess.h"
#include "ttable.h"
#include "ttable.c" /* inline doesn't work with separate compilation!! */
#ifdef NULLMOVE
#undef DEEPNULL
#endif
#if !defined OLDTIME && defined HAVE_GETTIMEOFDAY
double pow ();
#endif
SHORT background = 0;
static SHORT DepthBeyond;
UTSHORT PrVar[MAXDEPTH+1];
SHORT notime = true;
#ifdef IGNUAN
extern SHORT GNUANtop;
extern SHORT GNUANmv;
#endif
#if defined NULLMOVE || defined DEEPNULL
SHORT null;       /* Null-move already made or not */
SHORT no_null;
SHORT PVari;      /* Is this the PV */
#endif
#ifdef DEBUG40
extern int whichway;
#endif
#ifdef IGNUAN
extern GNUANadj();
#endif
#ifdef DEBUG
  int tracetmp;
  UTSHORT DBLINE[MAXDEPTH+1];
  struct leaf *dbptr;
#endif
SHORT zwndw;
SHORT start_stage;
SHORT terminal;
extern SHORT origbrd[64],origcol[64];
extern SHORT OrigGameCnt;
int repetition (void);

#define interval 15

#include "ataks.h"

/* ............    MOVE GENERATION & SEARCH ROUTINES    .............. */
inline
int
repetition ()

/*  Check for draw by threefold repetition.  */

{
  register SHORT i, c, cnt;
  register SHORT f, t;
  SHORT b[64];

  cnt = c = 0;
  /* try to avoid work */
  memset ((CHAR *) b, 0, sizeof (b));
  for (i = GameCnt; i > Game50; i--)
    {
      f = GameList[i].gmove >> 8;
      t = GameList[i].gmove & 0x3f;

      if (b[f]) c--;
      if (b[t]) c--;
      b[f] = (board[f] + (color[f] << 8))
        - (board[t] + (color[t] << 8)) + b[t];
      b[t] = (board[t] + (color[t] << 8)) - (no_piece + (neutral << 8));
      if (b[f]) c++;
      if (b[t]) c++;
      if (c == 0)
        if (((i ^ GameCnt) & 1))
     cnt++;
    }
  return (cnt);
}

int
pick (SHORT p1, SHORT p2)

/*
 * Find the best move in the tree between indexes p1 and p2. Swap the best
 * move into the p1 element.
 *
 */
{
  register struct leaf *p, *q, *r, *k;
  register s0;
  struct leaf temp;

  k = p = &Tree[p1];
  q = &Tree[p2];
  s0 = p->score;
  for (r = p + 1; r <= q; r++)
    if (r->score != 9999 && (r->score) > s0)
      {
   s0 = (r->score);
   p = r;
      }
  if (p != k)
    {
      temp = *p;
      *p = *k;
      *k = temp;
      return true;
    }
  return false;
}

void
SaveBoard (void)
{
  SHORT sq;
  for (sq=0;sq<64;sq++)
   {
    origbrd[sq]=board[sq];
    origcol[sq]=color[sq];
   }
  OrigGameCnt=GameCnt;
}

#ifdef DEBUG
UTSHORT trace[MAXDEPTH+1];
CHAR traceline[256];
UTSHORT tracelog[MAXDEPTH+1];
int tracen = 0;
int traceflag = 0;
int traceply = 0;
#endif
int bookflag = false;
int Jscore = 0;

static int TCcount, TCleft;
void
SelectMove (SHORT side, SHORT iop)


/*
 * Select a move by calling function search() at progressively deeper ply
 * until time is up or a mate or draw is reached. An alpha-beta window of
 * -Awindow to +Bwindow points is set around the score returned from the
 * previous iteration. If Sdepth != 0 then the program has correctly
 * predicted the opponents move and the search will start at a depth of
 * Sdepth+1 rather than a depth of 1.
 */

{
  static SHORT i, tempb, tempc, tempsf, tempst, xside, rpt;
  static SHORT alpha, beta, score;
  static struct GameRec *g;
  SHORT InChkDummy;
  static SHORT start_score;
  static SHORT plyscore;
#ifdef DEBUG

  if (debuglevel & (512 | 1024))
    {
      CHAR b[32];
      SHORT c1, c2, r1, r2;
      tracen = 0;
      traceflag = false;
      traceply = 0;
      tracelog[0] = 0;
      while (true)
   {
     printf ("debug?");
     gets (b);
     if (b[0] == 'p')
       traceply = atoi (&b[1]);
     else if (b[0] == '\0')
       break;
     else
       {
         c1 = b[0] - 'a';
         r1 = b[1] - '1';
         c2 = b[2] - 'a';
         r2 = b[3] - '1';
         trace[++tracen] = (locn (r1, c1) << 8) | locn (r2, c2);
       }
     if (tracen == 0 && traceply > 0)
       traceflag = true;
   }

    }
#endif

  flag.timeout = false;
  flag.back = false;
  flag.musttimeout = false;
  flag.abort=false;
  INCscore = 0;
  xside = side ^ 1;
/* we need to test if recycle will still have an effect -- DanO*/
/*  recycle = (GameCnt % rehash) - rehash;  not used anymore */

  /* if background mode set to infinite */
  if (iop == 2)
    {
      ResponseTime = 9999999;
      background = true;
    }
  else
    {
      player = side;
      if (TCflag)
   {
     TCcount = 0;
     background = false;
     if (TimeControl.moves[side] < 1)
       TimeControl.moves[side] = 1;
     /* special case time per move specified */
     if (flag.onemove)
       {
         ResponseTime = TimeControl.clock[side] - 100;
         TCleft = 0;
       }
     else
       {
         /* calculate avg time per move remaining */

         ResponseTime = TimeControl.clock[side] / TimeControl.moves[side];
         ResponseTime = ResponseTime * 2 / 3;
         ResponseTime += TCadd / 2;
         TCleft = (int) ResponseTime / 5;
         if (TimeControl.moves[side] < 5)
      TCcount = MAXTCCOUNTX - 10;
       }
     if (ResponseTime < 101)
       {
         ResponseTime = 100;
         TCcount = MAXTCCOUNTX - 10;
       }
     else if (ResponseTime < 200)
       {
         TCcount = MAXTCCOUNTX - 10;
       }
   }
      else
   {
     ResponseTime = MaxResponseTime;
     TCleft = 0;
     ElapsedTime (1);
   }
      if (TCleft)
   {
     TCcount = ((int) ((TimeControl.clock[side] - ResponseTime)) / 2) / TCleft;
     if (TCcount > MAXTCCOUNTX)
       TCcount = 0;
     else
       TCcount = MAXTCCOUNTX - TCcount;
   }
      else
   TCcount = MAXTCCOUNTX;
    }

#ifdef QUIETBACKGROUND
  if (!background)
#endif /* QUIETBACKGROUND */
    ShowSidetoMove ();
  ExtraTime = 0;
  if (Sdepth > 0)
      goto inloop;
  else
      ElapsedTime (1);

  ExaminePosition ();
  stage= -1; /* Force init in UpdateWeights() */
  start_score= Tscore[0]= Tscore[1]= score=
    evaluate (side, 1, 1, 0, -9999, 9999, &terminal, &InChkDummy);
  start_stage= stage;
#ifdef HISTORY
  memset ((UCHAR *) history, 0, (unsigned long) sizeof (history));
#endif
  FROMsquare = TOsquare = -1;
  PV = 0;
  if (iop == 1)
    hint = 0;
  for (i = 0; i < MAXDEPTH; i++)
    PrVar[i] = killr0[i] = killr1[i] = killr2[i] = 0;
  /* set initial window for search */
  alpha = score - ((computer == black) ? BAwindow : WAwindow);
  beta = score + ((computer == black) ? BBwindow : WBwindow);
  rpt = 0;
  TrPnt[1] = 0;
  root = &Tree[0];
  VMoveList (side, 1);
  /* can I get a book move? */
#ifndef IGNUAN
  if (flag.regularstart && Book)
    {
      flag.timeout = bookflag = OpeningBook (&hint, side);
      if (TCflag && !flag.onemove && !background)
   ResponseTime += ResponseTime;
    }
#endif
#ifdef IGNUAN
  if (GNUANtop) GNUANadj();
#endif
  /* Are we in stalemate or mated? */
  if (TrPnt[2] == TrPnt[1])
    {
      flag.timeout = true;
      score = -9999;
    }
  if (TrPnt[2] - TrPnt[1] == 1)
      flag.timeout = true;
  if (flag.timeout)
      rpt = repetition ();
  for (i = TrPnt[1]; i < TrPnt[2]; i++) pick (i, TrPnt[2] - 1);
  /* zero stats for hash table */
  reminus = replus = 0;
  GenCnt = NodeCnt = ETnodes = EvalNodes = 0;
#if defined HASHSTATS
  ClearHashStats();
#endif
  plyscore = score;
  Jscore = 0;
  zwndw = 20;
  /********************* main loop ********************************/
  Sdepth = (MaxSearchDepth < (MINDEPTH - 1)) ? MaxSearchDepth : (MINDEPTH - 1);
#if defined NULLMOVE || defined DEEPNULL
  no_null= (emtl[xside] == 0 || emtl[side] == 0);
#endif
inloop:
  while (!flag.timeout)
    {
      /* go down a level at a time */
      Sdepth++;
      TCcount = 0;
#if defined NULLMOVE || defined DEEPNULL
      null = 0;
      PVari = 1;
#endif
      DepthBeyond = Sdepth + ((Sdepth == 1) ? FBEYOND : flag.threat ? SBEYOND: TBEYOND); 

#ifndef BAREBONES
#ifdef QUIETBACKGROUND
      if (!background)
#endif /* QUIETBACKGROUND */
   ShowDepth (0);
#endif
      root->score= Tscore[0]= Tscore[1]= start_score;
      /* search at this level returns score of PV */
      score = search (side, 1, Sdepth, 0, alpha, beta, PrVar, &rpt, QBLOCK, false);
      /* save PV as killer */
      for (i = 1; PrVar[i] != 0; i++) killr0[i] = PrVar[i];

      /* low search failure re-search with (-inf,score) limits  */
      if (score < alpha)
   {
#ifndef BAREBONES
     reminus++;
#ifdef QUIETBACKGROUND
     if (!background)
#endif /* QUIETBACKGROUND */
       ShowDepth ('-');
#endif

#if defined NULLMOVE || defined DEEPNULL
           null = 0;
           PVari = 1;
#endif
          Tscore[0]= Tscore[1]= start_score;
     score = search (side, 1, Sdepth, 0, -9999, 9999, PrVar, &rpt,QBLOCK,false);

          /* save PV as killer */
          for (i = 1; PrVar[i] != 0; i++) killr0[i] = PrVar[i];
   }
      /* high search failure re-search with (score, +inf) limits */
      else if (score > beta && score != 9998)
   {
#ifndef BAREBONES
     replus++;
#ifdef QUIETBACKGROUND
     if (!background)
#endif /* QUIETBACKGROUND */
       ShowDepth ('+');
#endif
#if defined NULLMOVE || defined DEEPNULL
           null = 0;
           PVari = 1;
#endif
          Tscore[0]= Tscore[1]= start_score;
     score = search (side, 1, Sdepth, 0, -9999, 9999, PrVar, &rpt,QBLOCK,false);

          /* save PV as killer */
          for (i = 1; PrVar[i] != 0; i++) killr0[i] = PrVar[i];
   }
      /**************** out of search ********************************************/
      if (flag.musttimeout || Sdepth >= MaxSearchDepth)
   flag.timeout = true;

      else if (TCflag && (Sdepth > (MINDEPTH - 1)) && (TCcount < MAXTCCOUNTR))
   {
     if (plyscore - score > ZDELTA)
       {
         TCcount++;
         ExtraTime += TCleft;
       }
   }
#ifdef notdef
      if (score > (Jscore - zwndw) && score > (Tree[1].score + 250))
   ExtraTime = 0;
#endif
      if (score > plyscore + 250)
   ExtraTime = 0;
      ElapsedTime (2);
      if (root->flags & exact || rpt > 1) flag.timeout = true;
#if defined OLDTIME || !defined HAVE_GETTIMEOFDAY
      else if (!(Sdepth < MINDEPTH) && TCflag && ((4 * et) > (2 * ResponseTime + ExtraTime)))
   flag.timeout = true;
#else
      else if (!(Sdepth < MINDEPTH) && TCflag && !flag.onemove &&
          ((int) ((double)1.93913099 * (pow ((double) et, (double)1.12446928l))) > (ResponseTime + ExtraTime)))
          { flag.timeout = true;}
#endif
      /************************ time control ***********************************/

      /* save PV as killer */
      for (i = 1; PrVar[i] != 0; i++) killr0[i] = PrVar[i];
      if (!flag.timeout) start_score= Tscore[0] = score;
      /* if done or nothing good to look at quit */
      if ((root->flags & exact) || (score < -9000)) flag.timeout = true;
      /* find the next best move put below root */
      if (!flag.timeout)
   {
     /* */
#if !defined NODYNALPHA
     Jscore = (plyscore + score) >> 1;
#endif
     zwndw = 20 + abs (Jscore / 12);
     plyscore = score;
     /* recompute search window */
     beta = score + ((computer == black) ? BBwindow : WBwindow);
#if !defined NODYNALPHA
     alpha = ((Jscore < score) ? Jscore : score) - ((computer == black) ? BAwindow : WAwindow) - zwndw;
#else
     alpha = score - ((computer == black) ? BAwindow : WAwindow);
#endif
   }
#ifndef BAREBONES
#ifdef QUIETBACKGROUND
      if (!background)
#endif /* QUIETBACKGROUND */
   ShowResults (score, PrVar, '.');
#ifdef DEBUG41
      debug41 (score, PrVar, '.');
#endif
#endif
    }
  /******************************* end of main loop ***********************************/
  /* background mode */
  if (iop == 2 || flag.abort)
    return;
    /* if no moves and not in check then draw */
  if ((score == -9999) && !(SqAtakd (PieceList[side][0], xside)))
    {
      root->flags |= draw;
      DRAW = CP[31];    /* No moves */
    }
  else if (GameCnt == MAXMOVES)
    {
      root->flags |= draw;
      DRAW = CP[28];    /* Max Moves */
    }
  /* not in book so set hint to guessed move for other side */
  if (!bookflag)
    hint = ((PrVar[1]) ? PrVar[2] : 0);

   algbr (root->f, root->t, (SHORT) root->flags);
  /* if not mate or draw make move and output it */
  if (((score != -9999) && (rpt <= 1)) || (root->flags & draw))
    {
      MakeMove (side, &Tree[0], &tempb, &tempc, &tempsf, &tempst);
#if !defined NOMATERIAL
      if (flag.material && !pmtl[black] && !pmtl[white] && (mtl[white] < (valueR + valueK)) && (mtl[black] < (valueR + valueK)))
   {
     root->flags |= draw;
     DRAW = CP[57];  /* No pieces */
   }
      else
#endif
      if (!PieceCnt[black] && !PieceCnt[white])
   {
     root->flags |= draw;
     DRAW = CP[32];  /* No pieces */
   }
    }
  else
    { root->score = score; /* When mate, ignore distinctions! * --SMC */
    }
  rpt = repetition ();
  g = &GameList[GameCnt];
  if (g->flags & capture && g->piece == king) { flag.mate = flag.illegal = true; }
  /* If Time Control get the elapsed time */
  if (TCflag) ElapsedTime (1);
  if (rpt > 1) root->flags |= (draw | exact);
  if (score == -9999 /*|| rpt > 1 */)
    mvstr[0][0] = mvstr[1][0] = mvstr[2][0] = mvstr[3][0] = mvstr[4][0] = '\0';
  /* if mate set flag */
  if ((score == -9999) || (score == 9998)) {flag.mate = true; }
  OutputMove (score);
  /* if mate clear hint */
  if (flag.mate) hint = 0;
  /* if pawn move or capture or castle or promote zero repitition array */
  if ((board[root->t] == pawn) || (root->flags & (capture | cstlmask | promote)))
    {
      Game50 = GameCnt;
      ZeroRPT ();
    }
  /* add move to game list */
#ifdef IGNUAN
  GNUANmv = g->gmove;
#endif
  g->score = score;
  g->nodes = NodeCnt;
  g->time = (et + 50) / 100;
  g->depth = Sdepth;
  /* update time comtrol info */
  if (TCflag)
    {
#if defined CHESSTOOL || defined XBOARD
      TimeControl.clock[side] -= (et + OperatorTime + 45);
      timecomp[compptr] = (et + OperatorTime + 45);
#else
      TimeControl.clock[side] -= (et + OperatorTime);
      timecomp[compptr] = (et + OperatorTime);
#endif
      if(notime)TimeControl.clock[side] += TCadd;
      notime = true;
      /* finished our required moves - setup the next set */
      --TimeControl.moves[side];
    }
  /* check for end conditions */
  if ((root->flags & draw) && rpt < 2)
#if !defined CLIENT
    flag.mate = true;
#else
    ;
#endif
  else if (GameCnt == MAXMOVES)
    {
      flag.mate = true;
    }
  /* out of move store, you loose */
  else
    /* switch to other side */
    player = xside;
  Sdepth = 0;
}


int
search (SHORT side,
   register SHORT ply,
   register SHORT depth,
        SHORT ext,
   SHORT alpha,
   SHORT beta,
   UTSHORT *bstline,
   SHORT *rpt,
   SHORT quiescent,
   SHORT didnull)

/*
 * Perform an alpha-beta search to determine the score for the current board
 * position. If depth <= 0 only capturing moves, pawn promotions and
 * responses to check are generated and searched, otherwise all moves are
 * processed. The search depth is modified for check evasions, certain
 * re-captures and threats. Extensions may continue for up to 11 ply beyond
 * the nominal search depth.
 */


{
  register SHORT j, pnt;
  SHORT tempb, tempc, tempsf, tempst;
  SHORT xside, pbst, score, rcnt, InChk;
  UTSHORT mv, nxtline[MAXDEPTH+1];
  struct leaf *node, tmp;
  SHORT best = -12000;
  SHORT bestwidth = 0;
#if defined NULLMOVE || defined DEEPNULL
  SHORT PVsave;
  SHORT PVarisave;
  SHORT nmscore;
#endif
  SHORT extdb= 0;
  SHORT threat= 0;      /* tom@izf.tno.nl */
  SHORT threat2= 0;     /* tom@izf.tno.nl */
#ifdef DEBUG
  int xxxtmp;
#endif

  /* look every ZNODE nodes for a timeout */
#if defined NULLMOVE || defined DEEPNULL
  if (!null)
    {
#endif
      if (NodeCnt > ETnodes)
   {
     ElapsedTime (2);
     if (flag.back)
       {
         flag.back = false;
         flag.timeout = true;
         flag.musttimeout = false;
       }
     else if (TCflag || MaxResponseTime)
       {
         if ((et >= (ResponseTime + ExtraTime)) && Sdepth > MINDEPTH )
      {     /* try to extend to finish ply */
        if (!flag.onemove && (flag.back || (TCflag && TCcount < MAXTCCOUNTX)))
          {
            flag.back = false;
            flag.musttimeout = true;
            TCcount += 1;
            ExtraTime += TCleft;
          }
        else
          {
            flag.back = false;
            flag.timeout = true;
            flag.musttimeout = false;
          }
      }
       }
     else if (flag.back)
       {
         flag.back = false;
         flag.timeout = true;
         flag.musttimeout = false;
       }

   }
      else if (!TCflag && flag.musttimeout && Sdepth > MINDEPTH)
   {
     flag.timeout = true;
     flag.musttimeout = false;
   }
#if defined NULLMOVE || defined DEEPNULL
    }
#endif

  xside = side ^ 1;
  if (ply == 1) INCscore= 0;
  score = evaluate (side, ply, depth, ext, alpha, beta, &terminal, &InChk);
  if (ply > 1 && terminal == true)
    return (0);

  /* score > 9000 its a draw or mate */
  if (score > 9000) 
    { 
      bstline[ply] = 0; 
      *rpt = 0;
      return (score); 
    }
  if (ply >= MAXDEPTH-1) return (score);

  /*  No point searching deeper than the ply where a mate was found  */
  if (root->score + ply > 9998)  
      return (score);  

  /*
   * check for possible repetition if so call repetition - rpt is
   * repeat count
   */
  if ((GameCnt >= (Game50 + 3)) && ProbeRPThash(side,hashkey))
    {
      *rpt = repetition ();
      if (*rpt == 1) 
   score = -contempt;
      else if (*rpt > 1 && ply > 1) 
   {
          bstline[ply] = 0;
          return (-contempt);
        }
    }
  else
    *rpt = 0;


  /* Do we need to add depth because of special conditions */
  /* if in check or pawn threat or in capture sequence search deeper */
  /*************************************** depth extensions ***********************************/
 
#define DOTHREAT    (start_stage < THRSTAGE)
#define DOCHECK     (start_stage < 6 /*CHECKSTAGE*/)
#define INRANGE       (ply + depth < DepthBeyond - DEPTHMARGIN)
 
  Threat[ply]= 0;
  if (depth > 0)
    {
      /* Allow opponent a chance to check again */
      if (InChk) 
        {
          if (flag.threat)
            depth= (DOCHECK && INRANGE) ? depth+1: depth;
          else
            depth= (depth < 2) ? 2 : depth;
        }
      else if ((ply>1 && PawnThreat[ply - 1] && INRANGE) ||            
              (flag.rcptr && ply>2 && CptrFlag[ply - 1] && CptrFlag[ply - 2] && 
          ply<Sdepth+2 && CptrFlag[ply-1]==CptrFlag[ply-2]))
          ++depth;
    }
  else
    {
      int tripple_check = 0;
      if (score >= alpha &&
          (InChk || (ply>1 && PawnThreat[ply - 1] && ply<DepthBeyond-4)
          || (hung[side] > 1 && !ext && ply%2==0))) {
        threat2= 1;
        ext++;
        depth= 1;
      }
      else if (score <= alpha &&
               ((ply<Sdepth+4 && ply>4 &&
                ChkFlag[ply-2] && ChkFlag[ply-4] &&
                (ChkFlag[ply-2] != ChkFlag[ply-4] ||
                (flag.threat && DOTHREAT && QueenCheck[ply-2])))
          ||
                (flag.threat && ply<DepthBeyond-DEPTHMARGIN && ply>6
                && ChkFlag[ply-2] && ChkFlag[ply-4] && ChkFlag[ply-6]
                &&  (tripple_check=1)
                && ((ply < Sdepth+4 ?
                  (ChkFlag[ply-2] != ChkFlag[ply-4] || ChkFlag[ply-2] !=
ChkFlag [ply-6])
                  : (ChkFlag[ply-2] != ChkFlag[ply-4] &&
                     ChkFlag[ply-2] != ChkFlag[ply-6] &&
                     ChkFlag[ply-4] != ChkFlag[ply-6]))
                || (DOTHREAT && QueenCheck[ply-2]
                && QueenCheck[ply-4] && QueenCheck[ply-6]
                && QueenCheck[ply-2] != QueenCheck[ply-6]))
                ))) {
          if (tripple_check && DepthBeyond < Sdepth+13+DEPTHMARGIN)
            {
              extdb += 2;
              DepthBeyond += 2;
            }
          depth= 1;
          ext++;
          Threat[ply]= threat= 1;
        }

    }    
  ThreatSave[ply]= ((ply>1 && ThreatSave[ply-1]) || threat);
  /*******************************************************************************************/
  /* Make sure that width test at lower ply gets non random move
     count in case of pruning:  -- TomV
     This test also allows us to delay move generation till the
     null move is done.
   */
  if (ply>1) TrPnt[ply+1]= TrPnt[ply];

  /*
   * if more then DepthBeyond ply past goal depth or at goal depth and
   * score > beta quit - means we are out of the window
   * Changed such that capture are not unlimited.  Kong Sian
   */
#ifdef UNLIMITEDCAPS
  if (depth < 1 && score > beta) return (score);
  if (ply > DepthBeyond) depth = 0;
#else
  if (ply > DepthBeyond || (depth < 1 && score > beta)) { return (score); }
#endif

  /* Lets prune if its likely that we can get a cut.  Kong Sian*/
#ifdef PRUNE
  if ((depth == 1 || depth == 2) && !InChk && score > beta + 50*depth &&
   emtl[side] > valueQ && hung[side]==0)
     return (score);
#endif


/*
 * if below first ply and not at goal depth generate all moves else only
 * capture moves
 */

#if defined ttblsz
     if ( flag.hash && ply > 1 && *rpt == 0)
       {
      if (ProbeTTable (side, depth, ply, &alpha, &beta, &score) == true)
        {
            if (beta == -20000 || alpha > beta)
         {
             bstline[ply] = PV;
             bstline[ply + 1] = 0;
             if (score == -10000+ply) bstline[ply] = 0;
                            /*
                             * make sure the move is in the
                             * MoveList
                             */
#ifdef IGNUAN
                            if (ply == 1)
                              {   
                                  struct leaf tmp;
              register int spnt;
                                  for (spnt = TrPnt[ply]; spnt < TrPnt[ply + 1]; spnt++)
                                    {
                                        if (((Tree[spnt].f << 8) | Tree[spnt].t) == PV)
                                          {
                                              if (ply == 1 && Tree[spnt].score == DONTUSE) {bstline[1] = 0; break;}
                                              Tree[spnt].score = (beta == -20000) ? score : alpha;
                                              if (abs (score) > 9000) Tree[spnt].flags |= exact;
                                              if (spnt != TrPnt[ply])
                                                {
                                                    tmp = Tree[TrPnt[ply]];
                                                    Tree[TrPnt[ply]] = Tree[spnt];
                                                    Tree[spnt] = tmp;
                                                }
                                              if (beta == -20000) return (score);
                                              else return (alpha);
                                          }
                                    }
                              } else 
#endif
            {
            register int i = TrPnt[ply];
            Tree[i].t = PV & 0x3f;
            Tree[i].f = PV>>8;
            Tree[i].flags = 0;
            Tree[i].reply = 0;
            Tree[i].score = (beta == -20000) ? score : alpha; 
            TrPnt[ply+1] = i+1;
                                if (abs (score) > 9000) Tree[i].flags |= exact; 
            if (beta == -20000) return (score); 
                                    else return (alpha); 
               }

         }
        }
      /* ok try the transition file if its there */
      else if (hashfile && (depth > HashDepth) && (GameCnt < HashMoveLimit)
          && (ProbeFTable (side, depth, ply, &alpha, &beta, &score) == true))
        {
            if (beta == -20000 || alpha > beta)
         {
             bstline[ply] = PV;
             bstline[ply + 1] = 0;
             /*
              * make sure the move is in the
              * MoveList
              */
             if (ply == 1)
               {
              struct leaf tmp;
              register int spnt;
              for (spnt = TrPnt[ply]; spnt < TrPnt[ply + 1]; spnt++)
                {
               if (((Tree[spnt].f << 8) | Tree[spnt].t) == PV)
                 {
                           if (ply == 1 && Tree[spnt].score == DONTUSE) {bstline[1] = 0; break;}
                     Tree[spnt].score = (beta == -20000) ? score : alpha;
                     if (abs (score) > 9000) Tree[spnt].flags |= exact;
                     if (spnt != TrPnt[ply])
                  {
                      tmp = Tree[TrPnt[ply]];
                      Tree[TrPnt[ply]] = Tree[spnt];
                      Tree[spnt] = tmp;
                  }
                     PutInTTable (side, score, depth, ply, alpha, beta, PV);
                     if (beta == -20000) return (score);
                     else return (alpha);
                 }
                }
                } else {
                                register int i = TrPnt[ply];
                                Tree[i].t = PV & 0x3f;
                                Tree[i].f = PV>>8;
                                Tree[i].score = (beta == -20000) ? score : alpha;
            TrPnt[ply+1] = i+1;
                                if (abs (score) > 9000) Tree[i].flags |= exact;
                                if (beta == -20000) return (score);
                                    else return (alpha);
                              }
 

         }
        }
     }
#endif /* ttblsz */

  if ((depth > 0) || InChk || (background && ply < Sdepth + 2)) 
    {
      if (ply >1)
   MoveList (side, ply);
   quiescent = false;
    }
  else
    {
      CaptureList (side, ply);
      quiescent = true;
    }

  /* no moves return what we have */

  /*
   * normally a search will continue til past goal and no more capture
   * moves exist
   */
  /* unless it hits DepthBeyond */
  if (TrPnt[ply] == TrPnt[ply + 1]) 
    return (!InChk ? score : -10000+ply);


  /* if not at goal set best = -inf else current score */
  best = (depth > 0) ? -12000 : score;
#ifdef NULLMOVE

  PVarisave = PVari;
  if (!didnull &&    /* no previous null-move */
      !PVari &&         /* no null-move during the PV */
      (ply > 1) &&      /* not at ply 1 */
      (depth > 1) &&
      !InChk &&         /* no check */
      (emtl[side] > valueQ))
    /* enough material such that zugzwang is unlike but who knows which value
       is suitable? */
    {

      /* ok, we make a null move, i.e.  this means we have nothing to do
    but we have to keep the some arrays up to date otherwise gnuchess
    gets confused.  Maybe somebody knows exactly which informations are
    important and which not.

    Another idea is that we try the null-move first and generate the
    moves later.  This may save time but we have to take care that
    PV and other variables contain the right value so that the move
    ordering works right.
    */
      register struct GameRec *g;
      SHORT rdepth;

      nxtline[ply + 1] = 0;
      CptrFlag[ply] = 0;
      PawnThreat[ply] = 0;
      Tscore[ply] = score;
      PVsave = PV;
      PV = 0;
      null = 1;
      g = &GameList[++GameCnt];
      g->hashkey = hashkey;
      g->hashbd = hashbd;
      epsquare = -1;
      TOsquare = -1;
      g->Game50 = Game50;
      g->gmove = 0;
      g->flags = 0;
      g->piece = 0;
      g->color = neutral;
      rdepth = (depth-3 < 0 ? 0 : depth-3);
      nmscore = -search (xside, ply + 1, rdepth, ext, -beta, -beta+1, nxtline, &rcnt,false,1);
      null = 0;
      PV = PVsave;
      GameCnt--;
      if (nmscore > beta)
        {
     DepthBeyond -= extdb;
     return (nmscore);
   }
      if (depth <= 3 && score > beta && nmscore < -9000)
          depth++;
    }
#elif defined DEEPNULL

  /*
   * The deepnull algoritm is taken from the article by
   * Christian Donninger in ICCA journal Vol 16, No. 3.  TomV
   */
  PVarisave = PVari;
  if ((flag.deepnull ? !didnull : !null) &&  /* no previous null-move */
      !flag.nonull &&
      !no_null &&
      !PVari &&         /* no null-move during the PV */
      (ply > (flag.deepnull ? 1: 2)) &&      /* not at ply 1 */
      (score > alpha - 150 || !flag.deepnull) &&
      (ply <= Sdepth || flag.deepnull) &&
      (depth > (flag.deepnull ? (flag.verydeep ? 1: 2): 3)) &&
      !InChk &&         /* no check */
      /* enough material such that zugzwang is unlikely: */
      ! (emtl[xside] == 0 || emtl[side] <= valueB))
    {

      /* ok, we make a null move, i.e.  this means we have nothing to do
    but we have to keep the some arrays up to date otherwise gnuchess
    gets confused.

    Another idea is that we try the null-move first and generate the
    moves later.  This may save time but we have to take care that
    PV and other variables contain the right value so that the move
    ordering works right.
    */
      CptrFlag[ply] = 0;
      PawnThreat[ply] = 0;
      Tscore[ply] = score;
      PVsave = PV;
      PV = 0;
      epsquare = -1;
      TOsquare = -1;
      if (!null)
        null= ply;
      if (flag.deepnull) {
        nmscore = -search (xside, ply + 1, (depth >= 3 ? depth - 3: 0), ext, -beta, -alpha, nxtline, &rcnt,false,1);
        if (ply == null)
          null = 0;
        PV = PVsave;
   if (nmscore > beta) {
     DepthBeyond-= extdb;
     return nmscore;
        }
   if (nmscore > alpha)
     alpha= nmscore;
        if (depth <= 3 && ply < DepthBeyond-depth-4
            && score >= beta && nmscore < score - 350)
              depth++;
      } else {
        best = -search (xside, ply + 1, depth - 2, ext, -beta - 1, -beta, nxtline, &rcnt, false, 1);
        null = 0;
        PV = PVsave;
        if (best < alpha) best = -12000;
        else if (best > beta) {
      DepthBeyond-= extdb;
           return (best);
        }  else best = -12000;
      }
    }
#endif
  /* if best so far is better than alpha set alpha to best */
  if (best > alpha) alpha = best;
  /********************** main loop ************************************************************************/
  /* look at each move until no more or beta cutoff */
  for (pnt = pbst = TrPnt[ply]; pnt < TrPnt[ply + 1] && best <= beta && best != 9999-ply; pnt++)
    {
      if ((pnt&interval)==0)
       {
        flag.searching=true;
        CheckMessage();
        flag.searching=false;
       }
      NodeCnt++;
      /* find the most interesting looking of the remaining moves */
      if (ply > 1)
   pick (pnt, TrPnt[ply + 1] - 1);
#if defined NULLMOVE || defined DEEPNULL
      PVari = PVarisave && (pnt == pbst); /* Is this the PV? */
#endif

      node = &Tree[pnt];

      /* is this a forbidden move */
      if (ply == 1 && node->score == DONTUSE) { continue;}
#ifdef DEBUG
      if (debuglevel & (512 | 1024))
   {
     if (!tracen)
       traceflag = ((ply > traceply) ? false : true);
     else if (ply <= tracen && (ply == 1 || traceflag))
       {
         if (trace[ply] == (Tree[pnt].t | (Tree[pnt].f << 8)))
      traceflag = true;
         else
      traceflag = false;
       }
     tracelog[ply] = (Tree[pnt].t | (Tree[pnt].f << 8));
     tracelog[ply + 1] = 0;
   }
#endif
      nxtline[ply + 1] = 0;

#ifndef BAREBONES
      /* if at top level */
      if (ply == 1)
   {        /* at the top update search status */
     if (flag.post)
#ifdef QUIETBACKGROUND
       if (!background)
#endif /* QUIETBACKGROUND */
         ShowCurrentMove (pnt, node->f, node->t);
   }
#endif
#ifdef DEBUG
     xxxtmp = node->score;
     tracetmp = traceflag;
#endif
   if (!(node->flags & exact)) {
     /* make the move and go deeper */
     MakeMove (side, node, &tempb, &tempc, &tempsf, &tempst);
     CptrFlag[ply] = (node->flags & capture) ? TOsquare+1 : 0;
     PawnThreat[ply] = (node->flags & pwnthrt);
     Tscore[ply] = node->score;
     PV = node->reply;
     if (flag.pvs && depth > 0) {
            if (pbst == pnt) {
              node->score= -search (xside, ply + 1,
                                 depth > 0 ? depth - 1 : 0, ext,
                                 -beta, -alpha,
                                 nxtline, &rcnt, quiescent, 0);
            } else {
              node->score= -search(xside, ply + 1,
                              depth > 0 ? depth - 1 : 0, ext,
                              -alpha-1, -alpha,
                              nxtline, &rcnt, quiescent, 0);
              if (node->score >= best && alpha <= node->score
              && node->score <= beta)
                  node->score = -search (xside, ply + 1,
                                 depth > 0 ? depth - 1 : 0, ext,
                                 -beta, -node->score,
                                 nxtline, &rcnt, quiescent, 0);
            }
          } else

     node->score = -search (xside, ply + 1,
             (depth > 0) ? depth - 1 : 0, ext,
             -beta, -alpha,
             nxtline, &rcnt, quiescent, false);
     node->width = (ply % 2 == 1) ? (TrPnt[ply + 2] - TrPnt[ply + 1]) : 0;
     if (abs (node->score) > 9000) node->flags |= exact;
     else if (rcnt == 1) node->score /= 2;
          if (node->score == 9999-ply && !ChkFlag[ply]) 
       {
         node->flags |= draw;
              node->score = (-contempt);
       }
     if ((rcnt >= 2 || GameCnt - Game50 > 99 ))
       {
         node->flags |= (draw | exact);
         DRAW = CP[21]; /* Draw */
         node->score = -contempt;
       }
     node->reply = nxtline[ply + 1];
     /* reset to try next move */
     UnmakeMove (side, node, &tempb, &tempc, &tempsf, &tempst);
        }
      /* if best move so far */
      if (!flag.timeout && ((node->score > best) || ((node->score == best) && (node->width > bestwidth))))
   {
     /*
      * all things being equal pick the denser part of the
      * tree
      */
     bestwidth = node->width;

     /*
      * if not at goal depth and better than alpha and not
      * an exact score increment by depth
      */
     if (depth > 0 && node->score > alpha && !(node->flags & exact)) node->score += depth; 
     best = node->score;
     pbst = pnt;
     if (best > alpha) { alpha = best; }
     /* update best line */
     for (j = ply + 1; nxtline[j] > 0; j++) bstline[j] = nxtline[j]; 
     bstline[j] = 0;
     bstline[ply] = (node->f << 8) | node->t;
     /* if at the top */
     if (ply == 1)
       {
         /*
          * if its better than the root score make it
          * the root
          */
         if ((best > root->score) || ((best == root->score) && (bestwidth > root->width)) || pnt > 0)
      {
        tmp = Tree[pnt];
        for (j = pnt - 1; j >= 0; j--)
          Tree[j + 1] = Tree[j];
        Tree[0] = tmp;
        pbst = 0;
      }
#ifndef BAREBONES
#ifdef QUIETBACKGROUND
         if (!background)
#endif /* QUIETBACKGROUND */
      if (Sdepth > 2)
        if (best > beta)
          {
            ShowResults (best, bstline, '+');
#ifdef DEBUG41
            debug41 (best, bstline, '+');
#endif
          }
        else if (best < alpha)
          {
            ShowResults (best, bstline, '-');
#ifdef DEBUG41
            debug41 (best, bstline, '-');
#endif
          }
        else
          ShowResults (best, bstline, '&');
#ifdef DEBUG41
         debug41 (best, bstline, '&');
#endif
#endif
         ElapsedTime (2);
         TCcount++;
         if (!background && Sdepth > 2)
      {
        if (best < alpha)
          {
            TCcount = 0;
            ExtraTime += Sdepth * TCleft;
            if (ExtraTime > 12 * TCleft)
           ExtraTime = 12 * TCleft;
            if (best > 300)
           ExtraTime = 0;
            return (best);
          }
      }
       }
   }
      if (flag.timeout)
   {
          DepthBeyond-= extdb;
#if defined NULLMOVE || defined DEEPNULL
     PVari = PVarisave;
#endif
         if (best == -12000)
           return (Tscore[ply - 1]);
         else
           return (best);

   }
    }

  /**************************************************************/
 /*************** out of main loop *****************************/

  if (best == -10000+ply) bstline[ply] = 0;
  node = &Tree[pbst];
  mv = (node->f << 8) | node->t;
#if defined NULLMOVE || defined DEEPNULL
  PVari = PVarisave;
#endif

  /*
   * we have a move so put it in local table - if it's already there
   * done else if not there or needs to be updated also put it in
   * hashfile
   */
#if ttblsz
  if (flag.hash && !quiescent && *rpt == 0 && best == alpha)
    {
      if (PutInTTable (side, best, depth, ply, alpha, beta, mv)
     && hashfile && (depth > HashDepth) && (GameCnt < HashMoveLimit))
   {
     PutInFTable (side, best, depth, ply, alpha, beta, node->f, node->t);
   }
    }
#endif /* ttblsz */
  if (depth > 0)
    {
#ifdef HISTORY
      j = (node->f << 8) | node->t;
      if (side == black)
   j |= 0x4000;
      if (history[j] < HISTORYLIM)
   history[j] |= (unsigned short) 1 << depth;
#endif
      if (node->t != (SHORT) (GameList[GameCnt].gmove & 0xFF))
   if (best > beta && mv != killr1[ply])
     {
       killr2[ply] = killr1[ply];
       killr1[ply] = mv;
     }
      killr0[ply] = ((best > 9000) ? mv : 0);
    }
  DepthBeyond -= extdb;
  return (best);
}




int
castle (SHORT side, SHORT kf, SHORT kt, SHORT iop)

/* Make or Unmake a castling move. */

{
  register SHORT rf, rt, t0, xside;

  xside = side ^ 1;
  if (kt > kf)
    {
      rf = kf + 3;
      rt = kt - 1;
    }
  else
    {
      rf = kf - 4;
      rt = kt + 1;
    }
  if (iop == 0)
    {
      if (kf != kingP[side] ||
     board[kf] != king ||
     board[rf] != rook ||
     color[kf] != side ||
     color[rf] != side ||
     Mvboard[kf] != 0 ||
     Mvboard[rf] != 0 ||
     color[kt] != neutral ||
     color[rt] != neutral ||
     color[kt - 1] != neutral ||
     SqAtakd (kf, xside) ||
     SqAtakd (kt, xside) ||
     SqAtakd (rt, xside))
   return (false);
    }
  else
    {
      if (iop == 1)
   {
     castld[side] = true;
     Mvboard[kf]++;
     Mvboard[rf]++;
   }
      else
   {
     castld[side] = false;
     Mvboard[kf]--;
     Mvboard[rf]--;
     t0 = kt;
     kt = kf;
     kf = t0;
     t0 = rt;
     rt = rf;
     rf = t0;
   }
      board[kt] = king;
      color[rt] = color[kt] = side;
      Pindex[kt] = 0;
      board[kf] = no_piece;
      color[rf] = color[kf] = neutral;
      board[rt] = rook;
      Pindex[rt] = Pindex[rf];
      board[rf] = no_piece;
      PieceList[side][Pindex[kt]] = kt;
      PieceList[side][Pindex[rt]] = rt;
      UpdateHashbd (side, king, kf);
      UpdateHashbd (side, king, kt);
      UpdateHashbd (side, rook, rf);
      UpdateHashbd (side, rook, rt);
    }
  return (true);
}


void
EnPassant (SHORT xside, SHORT f, SHORT t, SHORT iop)

/*
 * Make or unmake an en passant move.
 */

{
  register SHORT l;

  l = t + ((t > f) ? -8 : 8);
  if (iop == 1)
    {
      board[l] = no_piece;
      color[l] = neutral;
    }
  else
    {
      board[l] = pawn;
      color[l] = xside;
    }
  InitializeStats ();
}


void
UpdatePieceList (SHORT side, SHORT sq, SHORT iop,short piece)

/*
 * Update the PieceList and Pindex arrays when a piece is captured or when a
 * capture is unmade.
 */

{
  register SHORT i;

  if (iop == 1) 
    {
      i = Pindex[sq];
      if (i < PieceCnt[side]) 
        {
        PieceList[side][i] = PieceList[side][PieceCnt[side]];
        Pindex[PieceList[side][i]] = i;
        }
      PieceCnt[ side ]--;    
    }
  else
    { 
      if (piece != king)
        {
           PieceCnt[side]++;
           PieceList[side][PieceCnt[side]] = sq;
           Pindex[sq] = PieceCnt[side];
        } 
      else 
   {
     PieceCnt[side]++;
           for (i = PieceCnt[side]; i > 0; i--)
             {
              PieceList[side][i] = PieceList[side][i - 1];
              Pindex[PieceList[side][i]] = i;
             } 
     PieceList[side][0] = sq;
     Pindex[sq] = 0;
        }
    }
}

void
MakeMove (SHORT side,
     struct leaf *node,
     SHORT *tempb,   /* color of to square */
     SHORT *tempc,   /* piece at to square */
     SHORT *tempsf,  /* static value of piece on from */
     SHORT *tempst)  /* static value of piece on to */

/*
 * Update Arrays board[], color[], and Pindex[] to reflect the new board
 * position obtained after making the move pointed to by node. Also update
 * miscellaneous stuff that changes when a move is made.
 */

{
  register SHORT f, t, xside, ct, cf;
  register struct GameRec *g;

  xside = side ^ 1;
  g = &GameList[++GameCnt];
  g->hashkey = hashkey;
  g->hashbd = hashbd;
  g->epssq = epsquare;
  f = node->f;
  t = node->t;
  epsquare = -1;
  /* FROMsquare = f;*/
  TOsquare = t;
  INCscore = 0;
  g->Game50 = Game50;
  g->gmove = (f << 8) | t;
  g->flags = node->flags;
  if (node->flags & cstlmask)
    {
      g->piece = no_piece;
      g->color = side;
      (void) castle (side, f, t, 1);
      Game50 = GameCnt;
    }
  else
    {
      if (!(node->flags & capture) && (board[f] != pawn))
   { IncrementRPThash(side,hashkey); }
      else
   Game50 = GameCnt;
      *tempsf = svalue[f];
      *tempst = svalue[t];
      g->piece = *tempb = board[t];
      g->color = *tempc = color[t];
      if (*tempc != neutral)
   {
     UpdatePieceList (*tempc, t, 1,*tempb);
     /* if capture decrement pawn count */
     if (*tempb == pawn)
       {
         --PawnCnt[*tempc][column (t)];
       }
     if (board[f] == pawn)
       {
         cf = column (f);
         ct = column (t);
         /* move count from from to to */
         --PawnCnt[side][cf];
         ++PawnCnt[side][ct];

         /*
          * calculate increment for pawn structure
          * changes
          */
         /* doubled or more - */
         if (PawnCnt[side][ct] > (1 + PawnCnt[side][cf]))
      INCscore -= 15;
         /* went to empty column + */
         else if (PawnCnt[side][ct] < 1 + PawnCnt[side][cf])
      INCscore += 15;

         /*
          * went to outside col or empty col on one
          * side ????????
          */
         else if (ct == 0 || ct == 7 || PawnCnt[side][ct + ct - cf] == 0)
      INCscore -= 15;
       }
     mtl[xside] -= value[*tempb];
     if (*tempb == pawn)
       pmtl[xside] -= valueP;
     UpdateHashbd (xside, *tempb, t);
     INCscore += *tempst;
     Mvboard[t]++;
   }
      color[t] = color[f];
      board[t] = board[f];
      svalue[t] = svalue[f];
      Pindex[t] = Pindex[f];
      PieceList[side][Pindex[t]] = t;
      color[f] = neutral;
      board[f] = no_piece;
      if (board[t] == pawn)
   if (t - f == 16)
     epsquare = f + 8;
   else if (f - t == 16)
     epsquare = f - 8;
      if (node->flags & promote)
   {
     board[t] = node->flags & pmask;
     --PawnCnt[side][column (t)];
     mtl[side] += value[board[t]] - valueP;
     pmtl[side] -= valueP;
     UpdateHashbd (side, pawn, f);
     UpdateHashbd (side, board[t], f);
     INCscore -= *tempsf;
   }
      if (node->flags & epmask)
   EnPassant (xside, f, t, 1);
      else
       {
        UpdateHashbd (side, board[t], f);
        UpdateHashbd (side, board[t], t);
       }
      Mvboard[f]++;
    }
  if (flag.animate && (flag.bothsides || player==computer))
   {
     UpdateDisplay(node->f,node->t,0,node->flags,0);
     flag.searching=true;
     CheckMessage();
     flag.searching=false;
   }
}

void
UnmakeMove (SHORT side,
       struct leaf *node,
       SHORT *tempb, /* -> piece */
       SHORT *tempc, /* -> side */
       SHORT *tempsf,
       SHORT *tempst)

/*
 * Take back a move.
 */

{
  register SHORT f, t, xside;

  xside = side ^ 1;
  f = node->f;
  t = node->t;
  Game50 = GameList[GameCnt].Game50;
  if (node->flags & cstlmask)
    (void) castle (side, f, t, 2);
  else
    {
      color[f] = color[t];
      board[f] = board[t];
      svalue[f] = *tempsf;
      Pindex[f] = Pindex[t];
      PieceList[side][Pindex[f]] = f;
      color[t] = *tempc;
      board[t] = *tempb;
      svalue[t] = *tempst;
      if (node->flags & promote)
   {
     board[f] = pawn;
     ++PawnCnt[side][column (t)];
     mtl[side] += valueP - value[node->flags & pmask];
     pmtl[side] += valueP;
     UpdateHashbd (side, (SHORT) node->flags & pmask, t);
     UpdateHashbd (side, pawn, t);
   }
      if (*tempc != neutral)
   {
     UpdatePieceList (*tempc, t, 2,*tempb);
     if (*tempb == pawn)
       {
         ++PawnCnt[*tempc][column (t)];
       }
     if (board[f] == pawn)
       {
         --PawnCnt[side][column (t)];
         ++PawnCnt[side][column (f)];
       }
     mtl[xside] += value[*tempb];
     if (*tempb == pawn)
       pmtl[xside] += valueP;
     UpdateHashbd (xside, *tempb, t);
     Mvboard[t]--;
   }
      if (node->flags & epmask)
   {
     EnPassant (xside, f, t, 2);
   }
      else
       {
        UpdateHashbd (side, board[f], f);
        UpdateHashbd (side, board[f], t);
       }
      Mvboard[f]--;
      if (!(node->flags & capture) && (board[f] != pawn))
   { DecrementRPThash(side,hashkey); }
    }
  epsquare = GameList[GameCnt--].epssq;
  if (flag.animate) UpdateDisplay(node->f,node->t,0,node->flags,0);
}


void
InitializeStats (void)

/*
 * Scan thru the board seeing what's on each square. If a piece is found,
 * update the variables PieceCnt, PawnCnt, Pindex and PieceList. Also
 * determine the material for each side and set the hashkey and hashbd
 * variables to represent the current board position. Array
 * PieceList[side][indx] contains the location of all the pieces of either
 * side. Array Pindex[sq] contains the indx into PieceList for a given
 * square.
 */

{
  register SHORT i, sq;

  epsquare = -1;
  for (i = 0; i < 8; i++)
    {
      PawnCnt[white][i] = PawnCnt[black][i] = 0;
    }
  mtl[white] = mtl[black] = pmtl[white] = pmtl[black] = 0;
  PieceCnt[white] = PieceCnt[black] = 0;
  hashbd = hashkey = 0;
  for (sq = 0; sq < 64; sq++)
    if (color[sq] != neutral)
      {
   mtl[color[sq]] += value[board[sq]];
   if (board[sq] == pawn)
     {
       pmtl[color[sq]] += valueP;
       ++PawnCnt[color[sq]][column (sq)];
     }
   Pindex[sq] = ((board[sq] == king) ? 0 : ++PieceCnt[color[sq]]);

   PieceList[color[sq]][Pindex[sq]] = sq;
   UpdateHashbd(color[sq], board[sq], sq);
      }
}
