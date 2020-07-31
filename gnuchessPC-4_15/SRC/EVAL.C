/*
 * eval.c - C source for GNU CHESS
 *
 * Copyright (c) 1988,1989,1990 John Stanback
 * Copyright (c) 1992 Free Software Foundation
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
#include "ttable.h" /* uses hashbd, hashkey and eval cache */

/* Backward pawn bonus indexed by # of attackers on the square */
static const SHORT BACKWARD[16] =
{-6, -10, -15, -21, -28, -28, -28, -28, -28, -28, -28, -28, -28, -28, -28, -28};

/* Bishop mobility bonus indexed by # reachable squares */
static const SHORT BMBLTY[14] =
{-2, 0, 2, 4, 6, 8, 10, 12, 13, 14, 15, 16, 16, 16};

/* Rook mobility bonus indexed by # reachable squares */
static const SHORT RMBLTY[15] =
{0, 2, 4, 6, 8, 10, 11, 12, 13, 14, 14, 14, 14, 14, 14};

/* Positional values for a dying king */
static const SHORT DyingKing[64] =
{0, 8, 16, 24, 24, 16, 8, 0,
 8, 32, 40, 48, 48, 40, 32, 8,
 16, 40, 56, 64, 64, 56, 40, 16,
 24, 48, 64, 72, 72, 64, 48, 24,
 24, 48, 64, 72, 72, 64, 48, 24,
 16, 40, 56, 64, 64, 56, 40, 16,
 8, 32, 40, 48, 48, 40, 32, 8,
 0, 8, 16, 24, 24, 16, 8, 0};

/* Isolated pawn penalty by rank */
static const SHORT ISOLANI[8] =
/*{-18, -20, -22, -24, -24, -22, -20, -18};*/
{-8, -10, -12, -14, -14, -12, -10, -8};

/* table for King Bishop Knight endings */
static const SHORT KBNK[64] =
{620, 560, 500, 440, 380, 320, 260, 240,
 560, 520, 460, 400, 340, 280, 230, 260,
 500, 460, 320, 280, 260, 220, 280, 320,
 440, 400, 280, 200, 200, 260, 340, 380,
 380, 340, 260, 200, 200, 280, 400, 440,
 320, 280, 220, 260, 280, 320, 460, 500,
 260, 230, 280, 340, 400, 460, 520, 560,
 240, 260, 320, 380, 440, 500, 560, 620};

/* penalty for threats to king, indexed by number of such threats */
static const SHORT KTHRT[36] =
{0, -8, -20, -36, -52, -68, -80, -80, -80, -80, -80, -80,
 -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80,
 -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80, -80};

/* King positional bonus inopening stage */
static const SHORT KingOpening[64] =
{0, 0, -4, -10, -10, -4, 0, 0,
 -4, -4, -8, -12, -12, -8, -4, -4,
 -12, -16, -20, -20, -20, -20, -16, -12,
 -16, -20, -24, -24, -24, -24, -20, -16,
 -16, -20, -24, -24, -24, -24, -20, -16,
 -12, -16, -20, -20, -20, -20, -16, -12,
 -4, -4, -8, -12, -12, -8, -4, -4,
 0, 0, -4, -10, -10, -4, 0, 0};

/* King positional bonus in end stage */
static const SHORT KingEnding[64] =
{0, 6, 12, 18, 18, 12, 6, 0,
 6, 12, 18, 24, 24, 18, 12, 6,
 12, 18, 24, 30, 30, 24, 18, 12,
 18, 24, 30, 36, 36, 30, 24, 18,
 18, 24, 30, 36, 36, 30, 24, 18,
 12, 18, 24, 30, 30, 24, 18, 12,
 6, 12, 18, 24, 24, 18, 12, 6,
 0, 6, 12, 18, 18, 12, 6, 0};

/* Passed pawn positional bonus */
static const SHORT PassedPawn0[8] =
{0, 60, 80, 120, 200, 360, 600, 800};
static const SHORT PassedPawn1[8] =
{0, 30, 40, 60, 100, 180, 300, 800};
static const SHORT PassedPawn2[8] =
{0, 15, 25, 35, 50, 90, 140, 800};
static const SHORT PassedPawn3[8] =
{0, 5, 10, 15, 20, 30, 140, 800};

/* Knight positional bonus */
static const SHORT pknight[64] =
{0, 4, 8, 10, 10, 8, 4, 0,
 4, 8, 16, 20, 20, 16, 8, 4,
 8, 16, 24, 28, 28, 24, 16, 8,
 10, 20, 28, 32, 32, 28, 20, 10,
 10, 20, 28, 32, 32, 28, 20, 10,
 8, 16, 24, 28, 28, 24, 16, 8,
 4, 8, 16, 20, 20, 16, 8, 4,
 0, 4, 8, 10, 10, 8, 4, 0};

/* Bishop positional bonus */
static const SHORT pbishop[64] =
{14, 14, 14, 14, 14, 14, 14, 14,
 14, 22, 18, 18, 18, 18, 22, 14,
 14, 18, 22, 22, 22, 22, 18, 14,
 14, 18, 22, 22, 22, 22, 18, 14,
 14, 18, 22, 22, 22, 22, 18, 14,
 14, 18, 22, 22, 22, 22, 18, 14,
 14, 22, 18, 18, 18, 18, 22, 14,
 14, 14, 14, 14, 14, 14, 14, 14};

/* Pawn positional bonus */
static const SHORT PawnAdvance[64] =
{0, 0, 0, 0, 0, 0, 0, 0,
 4, 4, 4, 0, 0, 4, 4, 4,
 6, 8, 8, 10, 10, 8, 8, 6,
 6, 8, 12, 16, 16, 12, 8, 6,
 8, 12, 16, 24, 24, 16, 12, 8,
 12, 16, 24, 32, 32, 24, 16, 12,
 12, 16, 24, 32, 32, 24, 16, 12,
 0, 0, 0, 0, 0, 0, 0, 0};

static const SHORT CentralPawn[64] =
{ 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0} ;


#define AHOPEN (-270)

static SHORT kpkwv_ (SHORT, SHORT, SHORT, SHORT, SHORT, SHORT);
static SHORT kpkbv_ (SHORT, SHORT, SHORT, SHORT, SHORT, SHORT);
inline static int ScoreKBNK (SHORT, SHORT, SHORT);
inline static int ScoreK1PK (SHORT, SHORT, SHORT, SHORT, SHORT, SHORT);

SHORT PUTVAR = false;
SHORT Mwpawn[64], Mbpawn[64], Mknight[2][64], Mbishop[2][64];
static SHORT Mking[2][64], Kfield[2][64];
static SHORT c1, c2, *atk1, *atk2, *PC1, *PC2;
SHORT atak[2][64];
SHORT emtl[2];
static SHORT PawnBonus, BishopBonus, RookBonus;
static SHORT KNIGHTPOST, KNIGHTSTRONG, BISHOPSTRONG, KATAK;
static SHORT PEDRNK2B, PWEAKH, PADVNCM, PADVNCI, PAWNSHIELD, PDOUBLED, PBLOK;
static SHORT RHOPN, RHOPNX, KHOPN, KHOPNX, KSFTY;
static SHORT ATAKD, HUNGP, HUNGX, KCASTLD, KMOVD, XRAY, PINVAL;
SHORT pscore[2];
/************************* Evaluation cache code ****************************/
/* NOTE: The static evaluation cache "EETable" belongs to eval.c and cannot */
/*       be moved to ttable.c */

#ifdef CACHE
struct etable *etab[2];

inline void
PutInEETable (SHORT side,int score)

/*
 * Store the current eval position in the static cache
 */

{
    register struct etable *ptbl;
#ifdef DEBUG
    if (flag.nocache) return;
#endif
    ptbl = &((etab[side])[hashkey % (ETABLE)]);
    ptbl->ehashbd = hashbd;
    ptbl->escore[white] = pscore[white];
    ptbl->escore[black] = pscore[black];
    ptbl->hung[white] = hung[white];
    ptbl->hung[black] = hung[black];
    ptbl->score = score;
    memcpy (ptbl->sscore, svalue, sizeof (svalue));
#if defined HASHSTATS 
    EADD++;
#endif
    return;
}

inline int
CheckEETable (SHORT side)

/* Check the static cache for an entry  */
{
    register struct etable *ptbl;
#ifdef DEBUG
    if (flag.nocache) return false;
#endif
    ptbl = &((etab[side])[hashkey % (ETABLE)]);
    if (hashbd == ptbl->ehashbd) return true;
    return false;
}

inline int
ProbeEETable (SHORT side, SHORT *score)

/* Get an evaluation from the static cache */
{
    register struct etable *ptbl;
#ifdef DEBUG
    if (flag.nocache) return false;
#endif
    ptbl = &((etab[side])[hashkey % (ETABLE)]);
    if (hashbd == ptbl->ehashbd)
      {
	  pscore[white] = ptbl->escore[white];
	  pscore[black] = ptbl->escore[black];
	  memcpy (svalue, ptbl->sscore, sizeof (svalue));
	  *score = ptbl->score;
          hung[white] = ptbl->hung[white];
          hung[black] = ptbl->hung[black];
#if defined HASHSTATS
	  EGET++;
#endif
	  return true;
      }
    return false;

}
#else /* Define null stubs for the above procedures */
#define PutInEETable(side, score)
#define ProbeEETable(side, score) (false)
#define CheckEETable(side) (false)
#endif /* CACHE */

/* ............    POSITIONAL EVALUATION ROUTINES    ............ */

/*
 * Inputs are:
 * pmtl[side] - value of pawns
 * mtl[side]  - value of all material
 * emtl[side] - vaule of all material - value of pawns - value of king
 * hung[side] - count of hung pieces
 * Tscore[ply] - search tree score for ply
 * ply
 * Pscore[ply] - positional score for ply ply
 * INCscore    - bonus score or penalty for certain positions
 * slk - single lone king flag
 * Sdepth - search goal depth
 * ChkFlag[ply]- checking piece at level ply or 0 if no check
 * PC1[column] - # of my pawns in this column
 * PC2[column] - # of opponents pawns in column
 * PieceCnt[side] - just what it says
 */

inline
int
ScoreKPK (SHORT side,
	  SHORT winner,
	  SHORT loser,
	  SHORT king1,
	  register SHORT king2,
	  register SHORT sq)

/*
 * Score King and Pawns versus King endings.
 */

{
    register SHORT s, r;

    s = ((PieceCnt[winner] == 1) ? 50 : 120);
    if (winner == white)
      {
	  r = row (sq) - ((side == loser) ? 1 : 0);
	  if (row (king2) >= r && distance (sq, king2) < 8 - r)
	      s += 10 * row (sq);
	  else
	      s = 500 + 50 * row (sq);
	  if (row (sq) < 6)
	      sq += 16;
	  else if (row (sq) == 6)
	      sq += 8;
      }
    else
      {
	  r = row (sq) + ((side == loser) ? 1 : 0);
	  if (row (king2) <= r && distance (sq, king2) < r + 1)
	      s += 10 * (7 - row (sq));
	  else
	      s = 500 + 50 * (7 - row (sq));
	  if (row (sq) > 1)
	      sq -= 16;
	  else if (row (sq) == 1)
	      sq -= 8;
      }
    s += 8 * (taxicab (king2, sq) - taxicab (king1, sq));
    return (s);
}

inline
SHORT
ScoreLoneKing (SHORT side)
/*
 * Static evaluation when loser has only a king and winner has no pawns or no
 * pieces.
 */

{
  register SHORT winner, loser, king1, king2, s, i;

  if (mtl[white] == valueK && mtl[black] == valueK)
    return 0;
  UpdateWeights ();
  winner = ((mtl[white] > mtl[black]) ? white : black);
  loser = winner ^ 1;
  king1 = PieceList[winner][0];
  king2 = PieceList[loser][0];

  s = 0;

  if (pmtl[winner] == 0)
    {
      if (emtl[winner] == valueB + valueN)
	s = ScoreKBNK (winner, king1, king2);
      else if (emtl[winner] == valueN + valueN)
	s = 0;
      else if (emtl[winner] < valueR)
        s = 0;
      else
	s = 500 + emtl[winner] - DyingKing[king2] - 10 * distance (king1, king2);
    }
  else
    {
      if (pmtl[winner] == valueP)
	s = ScoreK1PK (side, winner, loser, king1, king2, PieceList[winner][1]);
      else
	for (i = 1; i <= PieceCnt[winner]; i++)
	  s += ScoreKPK (side, winner, loser, king1, king2, PieceList[winner][i]);
    }
  return ((side == winner) ? s : -s);
}

inline
int
ScoreKBNK (SHORT winner, SHORT king1, SHORT king2)
/*
 * Score King+Bishop+Knight versus King endings.  Works fine now.
 */

{
    register SHORT s, Bsq, Nsq, KBNKsq = 0;

    if (board[PieceList[winner][1]] == bishop)
      {
        Bsq = PieceList[winner][1];
        Nsq = PieceList[winner][2];
      }
    else
      {
        Bsq = PieceList[winner][2];
        Nsq = PieceList[winner][1];
      }

    KBNKsq = (((row (Bsq) % 2) == (column (Bsq) % 2)) ? 0 : 7);

    s = emtl[winner] - 300;
    s += ((KBNKsq == 0) ? KBNK[king2] : KBNK[locn (row (king2), 7 - column (king2))]);
    s -= (8*taxicab(king1,king2) + 2*distance(Nsq,king2) + distance(Bsq,king2));
    s += KingEnding[king1];
    return (s);

}

SHORT dist_ (SHORT f1, SHORT r1, SHORT f2, SHORT r2)
{
  return distdata [ f1-9+8*r1 ][ f2-9+8*r2 ];
}

inline 
int  
ScoreK1PK (SHORT side,
           SHORT winner,
           SHORT loser,
           SHORT king1,
           register SHORT king2,
           register SHORT sq)

     /*
      *  We call Don Beal's routine with the necessary parameters and determine
      *  win/draw/loss.  Then we compute the real evaluation which is +-500 for
      *  a win/loss and 10 for a draw, plus some points to lead the computer to
      *  a decisive winning/drawing line.
      */

{
#ifdef WAY4PL64
  SHORT s;
#endif 
  SHORT win, sqc, sqr, k1c, k1r, k2c, k2r;
  const int drawn = 10, won = 500;

#ifdef WAY4PL64
#ifdef CACHE
  if (ProbeEETable(side,&s)) return s;
#endif 
#endif
  sqc = column (sq) + 1;
  sqr = row (sq) + 1;
  k1c = column (king1) + 1;
  k1r = row (king1) + 1;
  k2c = column (king2) + 1;
  k2r = row (king2) + 1;
  if (winner == black)
    {  
      sqr = 9 - sqr;
      k1r = 9 - k1r;
      k2r = 9 - k2r;
    }  
  if (sqc > 4)
    {
      sqc = 9 - sqc;
      k1c = 9 - k1c;
      k2c = 9 - k2c;
    }  
       
  if (side == winner)
    win = kpkwv_ (sqc, sqr, k1c, k1r, k2c, k2r);
  else 
    win = kpkbv_ (sqc, sqr, k1c, k1r, k2c, k2r);
     
#ifdef WAY4PL64
  if (!win)  s = drawn + 5 * distance (sq, king2) - 5*distance(king1,king2);
  else       s = won + 50 * (sqr - 2) + 10*distance(sq,king2);
#else
  if (!win)
    return drawn + 5 * distance (sq, king2);
  else
    return won + 50 * (sqr - 2);
#endif

#ifdef WAY4PL64
#ifdef CACHE
  if (PUTVAR) PutInEETable (side, s);
#endif

  return s;
#endif
}


static SHORT 
kpkwv_ (SHORT pf, SHORT pr, SHORT wf, SHORT wr, SHORT bf, SHORT br)
{

  /*
   *  Don Beal's routine, which was originally in Fortran.  See AICC 2
   */

  static SHORT wbdd, mbpf, nbpf, blpu;
  static SHORT brpu, mwpf, wlpu, wrpu, blpuu, brpuu, wlpuu, wrpuu, md,
    bq, blpuuu, brpuuu, bsd, tbf, sgf, bpp, sdr, sgr, wsd, wsg, ppr, wpp;

  ppr = ((pr == 2) ? 3 : pr);
  if (pf == 1)
    { 
      if (bf == 3)
    	{ 
	  if (pr == 7 && wf == 1 && wr == 8 && br > 6) return (0);
          if (pr == 6 && wf < 4 && wr == 6 && br == 8) return (1);
        }
      if (bf == 1 && br > pr) return (0);
      if (pr == 7 && bf > 2) return (1);
      if (bf <= 3 && br - ppr > 1) return (0);
      if (wf == 1 && bf == 3 && wr - pr == 1 && br - pr == 1) return(0);
    }
  bq = dist_ (bf, br, pf, 8);
  if (bq > 8 - ppr) return (1);
  mbpf = bf - pf;
  if (mbpf < 0) mbpf = -mbpf;
  bpp = dist_ (bf, br, pf, ppr);
  wpp = dist_ (wf, wr, pf, ppr);
  if (bpp - wpp < -1 && br - pr != mbpf) return (0);
  if (pf == 1 && pr <= 3 && wf <= 2 && wr == 8 && bf == 4 && br >= 7) return (1);
  if (!(pf != 2 || pr != 6 || bf != 1 || br != 8))
    { 
      if (wf <= 3 && wr == 6) return (0);
      if (wf == 4 && wr == 8) return (0);
    }
  if (pr == 7)
    { 
      if (wr < 8 && wpp == 2 && bq == 0) return (1);
      if (wr == 6 && wf == pf && bq == 0) return (1);
      if (wr >= 6 && wpp <= 2 && bq != 0) return (1);
    }
  blpuu = dist_ (bf, br, pf - 1, pr + 2);
  wbdd = dist_ (wf, wr, bf, br - 2);
  brpuu = dist_ (bf, br, pf + 1, pr + 2);
  if (pr == 6)
    { 
      if (dist_ (bf, br, pf + 1, pr) > 1 &&
          brpuu > dist_ (wf, wr, pf + 1, pr)) return (1);
      if (pf != 1)
    	{ 
	  if (blpuu > dist_ (wf, wr, pf - 1, pr)) return (1);
      	  if (br == 8 && mbpf == 1 && wbdd == 1) return (1);
      	  if (br > 6 && nbpf == 2 && dist_ (wf, wr, bf, 5) <= 1) return (1);
        }
      else
          if (wf == 1 && wr == 8 && bf == 2 && br == 6) return (0);
    }
  mwpf = wf - pf;
  if (mwpf < 0) mwpf = -mwpf;
  if (pr >= 5 && mwpf == 2 && wr == pr && bf == wf && br - pr == 2) return (1);
  brpu = dist_ (bf, br, pf + 1, pr + 1);
  wrpu = dist_ (wf, wr, pf + 1, pr + 1);
  blpu = dist_ (bf, br, pf - 1, pr + 1);
  wlpu = dist_ (wf, wr, pf - 1, pr + 1);
  if (!(pf == 1 || pr != 5))
    { 
      if (mwpf <= 1 && wr - pr == 1) return (1);
      if (wrpu == 1 && brpu > 1) return (1);
      if (wr >= 4 && bf == wf && br - pr >= 2 && mbpf == 3) return (1);
      if (wlpu == 1 && blpu > 1) return (1);
    }
  if (pr == 2 && br == 3 && mbpf > 1 && dist_ (wf, wr, bf, br + 2) <= 1) return (1);
  if (wr - pr == 2 && br == pr && mbpf == 1 && mwpf > 1 &&
      (wf - pf) * (bf - pf) > 0) return (0);
  if (pf == 1 && wf == 1 && wr == br && bf > 3) return (1);
  sgf = pf - 1;
  if (wf >= pf) { sgf = pf + 1; }
  sgr = wr - (mwpf - 1);
  if (mwpf == 0 && wr > br) sgr = wr - 1;
  wsg = dist_ (wf, wr, sgf, sgr);
  if (wr - pr - mwpf > 0 && wr - br >= -1 && bpp - (wsg + (sgr - ppr))
      >= -1 && dist_ (bf, br, sgf, sgr) > wsg) return (1);
  md = mbpf - mwpf;
  if (!(pf != 1 || bf <= 3))
    { 
      sdr = br + (bf - 3);
      if (sdr > 8) sdr = 8;
      if (wr > br + 1) sdr = br;
      if (sdr > ppr)
        { 
	  wsd = dist_ (wf, wr, 3, sdr);
          bsd = dist_ (bf, br, 3, sdr);
          if (bsd - wsd < -1) return (0);
          if (bsd <= wsd && md <= 0) return (0);
    	}
    }
  brpuuu = dist_ (bf, br, pf + 1, pr + 3);
  if (brpu > wrpu && brpuuu > wrpu && pr - wr != pf - wf) return (1);
  if (brpuuu == 0 && wrpu == 1) return (1);
  blpuuu = dist_ (bf, br, pf - 1, pr + 3);
  if (pf != 1)
    { 
      if (blpu > wlpu && blpuuu > wlpu && pr - wr != wf - pf) return (1);
      if (blpuuu == 0 && wlpu == 1) return (1);
    }
  wrpuu = dist_ (wf, wr, pf + 1, pr + 2);
  if (brpuu > wrpuu) return(1);
  wlpuu = dist_ (wf, wr, pf - 1, pr + 2);
  if (pf > 1 && blpuu > wlpuu) return (1);
  if (br == pr)
    { 
      if (mwpf <= 2 && wr - pr == -1 && mbpf != 2) return (1);
      if (dist_ (wf, wr, bf - 1, br + 2) <= 1 && bf - pf > 1) return (1);
      if (dist_ (wf, wr, bf + 1, br + 2) <= 1 && bf - pf < -1) return (1);
    }
  if (pf != 1)
    { 
      if (br == pr && mbpf > 1 && dist_ (wf, wr, pf, pr - 1) <= 1) return (1);
      if (br - pr >= 3 && wbdd == 1) return (1);
      if (wr - pr >= 2 && wr < br && md >= 0) return (1);
      if (mwpf <= 2 && wr - pr >= 3 && bf != pf && wr - br <= 1) return (1);
      if (wr >= pr && br - pr >= 5 && mbpf >= 3 && md >= -1 && ppr == 3) return (1);
      if (md >= -1 && pr == 2 && br == 8) return (1);
    }
  tbf = bf - 1;
  if (pf > bf) tbf = bf + 1;
  if (mbpf > 1 && br == ppr && dist_ (wf, wr, tbf, wr + 2) <= 1) return (1);
  if (br == pr && bf - pf == -2 && dist_ (wf, wr, pf + 2, pr - 1) <= 1) return (1);
  if (pf > 2 && br == pr && bf - pf == 2 &&
      dist_ (wf, wr, pf - 2, pr - 1) <= 1) return(1);
  return (0);
}				/* kpkwv_ */

static SHORT 
kpkbv_ (SHORT pf, SHORT pr, SHORT wf, SHORT wr, SHORT bf, SHORT br)
{
  static SHORT incf[8] =
    {0, 1, 1, 1, 0, -1, -1, -1};
  static SHORT incr[8] =
    {1, 1, 0, -1, -1, -1, 0, 1};

  static SHORT i, nm, nbf, nbr;

  nm = 0;
  for (i = 0; i < 8; ++i)
    {
      nbf = bf + incf[i];
      if (nbf < 1 || nbf > 8) continue;
      nbr = br + incr[i];
      if (nbr < 1 || nbr > 8) continue;
      if (dist_ (nbf, nbr, wf, wr) < 2) continue;
      if (nbf == pf && nbr == pr) return (0);
      if (nbr == pr + 1 && (nbf == pf - 1 || nbf == pf + 1)) continue;
      ++nm;
      if (kpkwv_ (pf, pr, wf, wr, nbf, nbr) == 0) return(0);
    }
  if (nm > 0) return(-1);
  return(0);
}				/* kpkbv_ */

int
evaluate (register SHORT side,
	  register SHORT ply,
	  register SHORT depth,
          register SHORT ext,
	  register SHORT alpha,
	  register SHORT beta,
	  SHORT *terminal,
	  SHORT *InChk)	/* output Check flag */

/*
 * Compute an estimate of the score by adding the positional score from the
 * previous ply to the material difference. If this score falls inside a
 * window which is 180 points wider than the alpha-beta window (or within a
 * 50 point window during quiescence search) call ScorePosition() to
 * determine a score, otherwise return the estimated score. If one side has
 * only a king and the other either has no pawns or no pieces then the
 * function ScoreLoneKing() is called.
 */

{
    register SHORT xside, slk;
    SHORT s;

    xside = side ^ 1;
    s = -Pscore[ply - 1] + mtl[side] - mtl[xside] - INCscore;
    *terminal = false;
    hung[white] = hung[black] = 0;
    slk = ((mtl[white] == valueK && (pmtl[black] == 0 || emtl[black] == 0)) ||
	  (mtl[black] == valueK && (pmtl[white] == 0 || emtl[white] == 0)));

    /* should we use the estimate or score the position */
    if ( !slk && (ply == 1 || 
#ifdef PRUNE
		  depth == 1 || depth == 2 ||
#endif
#ifdef CACHE
    	(CheckEETable (side)) ||
#endif
        (flag.neweval ? ((
        (ply==Sdepth || (!ext && depth == 0 && s>=alpha-30 && s<=beta+30)) ||
        (ext && s >= alpha - 25 && s <= beta + 25)) )
        :
        ((Sdepth ==  ply) ||
        (ply > Sdepth && (s >= (alpha - 30) && s <= (beta + 30)) )) )
        ))
      {
	/* score the position */
	ataks (side, atak[side]);
	ataks (xside, atak[xside]);
	if (Anyatak (side, PieceList[xside][0]))
	    return (10001 - ply);
	ChkFlag[ply - 1] = *InChk = 
	    (Anyatak (xside, PieceList[side][0])) ? Pindex[TOsquare]+1 : 0;
#ifndef BAREBONES 
	EvalNodes++;
#endif
	if (ply>4) PUTVAR = true;
	s = ScorePosition (side);
	PUTVAR = false;
      }
    else
      {
	/* use the estimate but look at check and slk */
        if (SqAtakd (PieceList[xside][0], side)) return (10001 - ply);
	*InChk = SqAtakd (PieceList[side][0], xside);
        ChkFlag[ply - 1] = (*InChk ? Pindex[TOsquare] + 1 : 0);
#ifdef DEBUG 
        if (debuglevel & 4096)
            printf("%lx %lx %d %d\n",hashbd,hashkey,ply,s);
#endif
	if (slk)
	  {
	    if (ply>4) PUTVAR=true;
	    s = ScoreLoneKing (side);
	    PUTVAR=false;
	    *terminal = (s == 0 ? true : false);
	  }
      }

    Pscore[ply] = s - mtl[side] + mtl[xside];
    QueenCheck[ply - 1] =       /* tom@izf.tno.nl */
          ((*InChk) && board[TOsquare] == queen) ? TOsquare : 0;
#ifdef DEBUG 
    if (debuglevel & 4096)
	printf("%lx %lx %d %d\n",hashbd,hashkey,ply,s);
#endif
    return (s);
}

inline
int
BRscan (register SHORT sq, SHORT *mob)

/*
 * Find Bishop and Rook mobility, XRAY attacks, and pins. Increment the
 * hung[] array if a pin is found.
 */
{
    register UCHAR *ppos, *pdir;
    register SHORT s, mobx;
    register SHORT u, pin;
    SHORT piece, *Kf;
    mobx = s = 0;
    Kf = Kfield[c1];
    piece = board[sq];
    ppos = nextpos[piece][sq];
    pdir = nextdir[piece][sq];
    u = ppos[sq];
    pin = -1;			/* start new direction */
    do
      {
	  s += Kf[u];
	  if (color[u] == neutral)
	    {
		mobx++;
		if (ppos[u] == pdir[u])
		    pin = -1;	/* oops new direction */
		u = ppos[u];
	    }
	  else if (pin < 0)
	    {
		if (board[u] == pawn || board[u] == king)
		    u = pdir[u];
		else
		  {
		      if (ppos[u] != pdir[u])
			  pin = u;	/* not on the edge and on to find a pin */
		      u = ppos[u];
		  }
	    }
	  else
	    {
		if (color[u] == c2 && (board[u] > piece || atk2[u] == 0))
		  {
		      if (color[pin] == c2)
			{
			    s += PINVAL;
			    if (atk2[pin] == 0 || atk1[pin] > control[board[pin]] + 1)
				++hung[c2];
			}
		      else
			  s += XRAY;
		  }
		pin = -1;	/* new direction */
		u = pdir[u];
	    }
      }
    while (u != sq);
    *mob = mobx;
    return s;
}

inline
SHORT
KingScan (register SHORT sq)

/*
 * Assign penalties if king can be threatened by checks, if squares near the
 * king are controlled by the enemy (especially the queen), or if there are
 * no pawns near the king. 
	The following must be true: 
		board[sq] == king 
		c1 == color[sq] 
		c2 == otherside[c1]
 */

#define ScoreThreat \
	if (color[u] != c2)\
  	if (atk1[u] == 0 || (atk2[u] & 0xFF) > 1) ++cnt;\
  	else s -= 3

{
    register SHORT cnt;
    register UCHAR *ppos, *pdir;
    register SHORT s;
    register SHORT u;
    SHORT ok;

    s = 0;
    cnt = 0;
    if (HasBishop[c2] || HasQueen[c2])
      {
	  ppos = nextpos[bishop][sq];
	  pdir = nextdir[bishop][sq];
	  u = ppos[sq];
	  do
	    {
		if (atk2[u] & ctlBQ)
		    ScoreThreat;
		u = ((color[u] == neutral) ? ppos[u] : pdir[u]);
	    }
	  while (u != sq);
      }
    if (HasRook[c2] || HasQueen[c2])
      {
	  ppos = nextpos[rook][sq];
	  pdir = nextdir[rook][sq];
	  u = ppos[sq];
	  do
	    {
		if (atk2[u] & ctlRQ)
		    ScoreThreat;
		u = ((color[u] == neutral) ? ppos[u] : pdir[u]);
	    }
	  while (u != sq);
      }
    if (HasKnight[c2])
      {
	  pdir = nextdir[knight][sq];
	  u = pdir[sq];
	  do
	    {
		if (atk2[u] & ctlNN)
		    ScoreThreat;
		u = pdir[u];
	    }
	  while (u != sq);
      }
    s += (KSFTY * KTHRT[cnt]) / 16;

    cnt = 0;
    ok = false;
    pdir = nextpos[king][sq];
    u = pdir[sq];
    do
      {
	  if (board[u] == pawn)
	      ok = true;
	  if (atk2[u] > atk1[u])
	    {
		++cnt;
		if (atk2[u] & ctlQ)
		    if (atk2[u] > ctlQ + 1 && atk1[u] < ctlQ)
			s -= 4 * KSFTY;
	    }
	  u = pdir[u];
      }
    while (u != sq);
    if (!ok)
	s -= KSFTY;
    if (cnt > 1)
	s -= (KSFTY);
    return (s);
}


inline
int
trapped (register SHORT sq)

/*
 * See if the attacked piece has unattacked squares to move to. The following
 * must be true: c1 == color[sq] c2 == otherside[c1]
 */

{
    register SHORT u;
    register UCHAR *ppos, *pdir;
    register SHORT piece;

    piece = board[sq];
    ppos = nextpos[ptype[c1][piece]][sq];
    pdir = nextdir[ptype[c1][piece]][sq];
    if (piece == pawn)
      {
	  u = ppos[sq];		/* follow no captures thread */
	  if (color[u] == neutral)
	    {
		if (atk1[u] >= atk2[u])
		    return (false);
		if (atk2[u] < ctlP)
		  {
		      u = ppos[u];
		      if (color[u] == neutral && atk1[u] >= atk2[u])
			  return (false);
		  }
	    }
	  u = pdir[sq];		/* follow captures thread */
	  if (color[u] == c2)
	      return (false);
	  u = pdir[u];
	  if (color[u] == c2)
	      return (false);
      }
    else
      {
	  u = ppos[sq];
	  do
	    {
		if (color[u] != c1)
		    if (atk2[u] == 0 || board[u] >= piece)
			return (false);
		u = ((color[u] == neutral) ? ppos[u] : pdir[u]);
	    }
	  while (u != sq);
      }
    return (true);
}

static inline int
PawnValue (register SHORT sq, SHORT side)
/*
 * Calculate the positional value for a pawn on 'sq'.
 */

{
    register SHORT fyle, rank;
    register SHORT j, s, a1, a2, in_square, r, e;

    a1 = (atk1[sq] & 0x4FFF);
    a2 = (atk2[sq] & 0x4FFF);
    rank = row (sq);
    fyle = column (sq);
    s = 0;

     /* Central pawns, double pawns and isolanis */
    if (CentralPawn[sq])
        s += PCENTER * 2;
    if ((fyle == 0 || PC1[fyle - 1] == 0) && (fyle == 7 || PC1[fyle + 1] == 0))
      {
 	s += ISOLANI[fyle];
	if (PC2[fyle] == 0)
 	    s += PWEAKH;
      }
    if (PC1[fyle] > 1)
        s += PDOUBLED;

    if (c1 == white)
      {
	  s += Mwpawn[sq];
	  if ((sq == 11 || sq == 12) && color[sq + 8] != neutral) 
	      s += PEDRNK2B;
	  if (a1 < ctlP && atk1[sq + 8] < ctlP && atk2[sq + 8] & ctlP)
	    {
		s += BACKWARD[a2 & 0xFF] * 2;
		if (PC2[fyle] == 0) s += PWEAKH;
		if (color[sq + 8] != neutral) s += PBLOK;
	    }
	  if (c1 == computer && rank != 7 && color[sq+8] == black && board[sq+8] == pawn) s -= PCRASH;
	  if (PC2[fyle] == 0)
	    {
		r = rank - ((side == black)?1:0);
		in_square = (row (bking) >= r && distance (sq, bking) < 8 - r);
		e = (a2 == 0 || side == white)? 0:1;
		for (j = sq + 8; j < 64; j += 8)
		    if (atk2[j] >= ctlP) { e = 2; break; }
		    else if (atk2[j] > 0 || color[j] != neutral) e = 1;

		if (e == 2) s += (stage * PassedPawn3[rank]) / 10;
		else if (in_square /*|| e == 1*/) s += (stage * PassedPawn2[rank]) / 10;
		else if (emtl[black] > 0) s += (stage * PassedPawn1[rank]) / 10;
		else s += PassedPawn0[rank];
	    }
      }
    else if (c1 == black)
      {
	  s += Mbpawn[sq];
	  if ((sq == 51 || sq == 52) && color[sq - 8] != neutral)
	      s += PEDRNK2B;

	  if (a1 < ctlP && atk1[sq - 8] < ctlP && atk2[sq - 8] & ctlP)
	    {
		s += BACKWARD[a2 & 0xFF] * 2;
		if (PC2[fyle] == 0) s += PWEAKH;
		if (color[sq - 8] != neutral) s += PBLOK;
	    }
	  if (c1 == computer && rank != 0 && color[sq-8] == white && board[sq-8] == pawn) s -= PCRASH;
	  if (PC2[fyle] == 0)
	    {
		r = rank + ((side == white)?1:0);
		in_square = (row (wking) <= r && distance (sq, wking) < r + 1);
		e = (a2 == 0 || side == black)?0:1;
		for (j = sq - 8; j >= 0; j -= 8)
		    if (atk2[j] >= ctlP) { e = 2; break; }
		    else if (atk2[j] > 0 || color[j] != neutral) e = 1;

		if (e == 2) s += (stage * PassedPawn3[7 - rank]) / 10;
		else if (in_square /*|| e == 1*/) s += (stage * PassedPawn2[7 - rank]) / 10;
		else if (emtl[white] > 0) s += (stage * PassedPawn1[7 - rank]) / 10;
		else s += PassedPawn0[7 - rank];
	    }
      }
    if ((rank > 2 && rank < 5) && (fyle > 2 && fyle < 5)) s += PCENTER;
#ifdef notdef
    if (a2 > 0)
      {
	  if (a1 == 0 || a2 > ctlP + 1)
	    {
		s += HUNGP;
		if (trapped (sq)) hung[c1] += 2;
		hung[c1]++;
	    }
	  else if (a2 > a1) s += ATAKD;
      }
#endif
    return (s);
}

inline
int
KnightValue (register SHORT sq, register SHORT side)

/*
 * Calculate the positional value for a knight on 'sq'.
 */

{
    register SHORT s, a2, a1;

    s = Mknight[c1][sq];
    a2 = (atk2[sq] & 0x4FFF);
    if (a2 > 0)
      {
	  a1 = (atk1[sq] & 0x4FFF);
	  if (a1 == 0 || a2 > ctlBN + 1)
	    {
		s += HUNGP;
		if (trapped (sq))
		    hung[c1] += 2;
		hung[c1]++;
	    }
	  else if (a2 >= ctlBN || a1 < ctlP)
	      s += ATAKD;
      }
    return (s);
}

inline
int
BishopValue (register SHORT sq, register SHORT side)

/*
 * Calculate the positional value for a bishop on 'sq'.
 */

{
    register SHORT s;
    register SHORT a2, a1;
    SHORT mob;

    s = Mbishop[c1][sq];
    s += BRscan (sq, &mob);
    s += BMBLTY[mob] * 2; 
    a2 = (atk2[sq] & 0x4FFF);
    if (a2 > 0)
      {
	  a1 = (atk1[sq] & 0x4FFF);
	  if (a1 == 0 || a2 > ctlBN + 1)
	    {
		s += HUNGP;
		if (trapped (sq))
		    hung[c1] += 2;
		hung[c1]++;
	    }
	  else if (a2 >= ctlBN || a1 < ctlP)
	      s += ATAKD;
      }
    return (s);
}

inline
int
RookValue (register SHORT sq, register SHORT side)

/*
 * Calculate the positional value for a rook on 'sq'.
 */

{
    register SHORT s;
    register SHORT fyle, a2, a1;
    SHORT mob;

    s = RookBonus;
    s += BRscan (sq, &mob);
    s += RMBLTY[mob]; 
    fyle = column (sq);
    if (PC1[fyle] == 0)
	{ s += RHOPN;
    		if (PC2[fyle] == 0)
			s += RHOPNX;
        }
    if (pmtl[c2] > 100 && row (sq) == rank7[c1])
	s += 25;
    s += 14 - taxicab (sq, EnemyKing);
    a2 = (atk2[sq] & 0x4FFF);
    if (a2 > 0)
      {
	  a1 = (atk1[sq] & 0x4FFF);
	  if (a1 == 0 || a2 > ctlR + 1)
	    {
		s += HUNGP;
		if (trapped (sq))
		    hung[c1] += 2;
		hung[c1]++;
	    }
	  else if (a2 >= ctlR || a1 < ctlP)
	      s += ATAKD;
      }
    return (s);
}

inline
int
QueenValue (register SHORT sq, register SHORT side)

/*
 * Calculate the positional value for a queen on 'sq'.
 */

{
    register SHORT s, a2, a1;

    s = ((distance (sq, EnemyKing) < 3) ? 12 : 0);
    if (stage > 2)
	s += 14 - taxicab (sq, EnemyKing);
    a2 = (atk2[sq] & 0x4FFF);
    if (a2 > 0)
      {
	  a1 = (atk1[sq] & 0x4FFF);
	  if (a1 == 0 || a2 > ctlQ + 1)
	    {
		s += HUNGP;
		if (trapped (sq))
		    hung[c1] += 2;
		hung[c1]++;
	    }
	  else if (a2 >= ctlQ || a1 < ctlP)
	      s += ATAKD;
      }
    return (s);
}

inline
int
KingValue (register SHORT sq, register SHORT side)

/*
 * Calculate the positional value for a king on 'sq'.
 */

{
    register SHORT s;
    register SHORT fyle;
    SHORT a2, a1;
    s = (emtl[c2] > KINGPOSLIMIT) ? Mking[c1][sq] : Mking[c1][sq] / 2;
    if (KSFTY > 0)
/*	if (Developed[c2] || stage > 0) */
	    s += KingScan (sq);
    if (castld[c1])
	s += KCASTLD;
    else if (Mvboard[kingP[c1]])
	s += KMOVD;

    fyle = column (sq);
    if (PC1[fyle] == 0)
	s += KHOPN;
    if (PC2[fyle] == 0)
	s += KHOPNX;
    switch (fyle)
      {
      case 5:
	  if (PC1[7] == 0)
	      s += KHOPN;
	  if (PC2[7] == 0)
	      s += KHOPNX;
	  /* Fall through */
      case 6:
      case 4:
      case 0:

	  if (PC1[fyle + 1] == 0)
	      s += KHOPN;
	  if (PC2[fyle + 1] == 0)
	      s += KHOPNX;
	  break;
      case 2:
	  if (PC1[0] == 0)
	      s += KHOPN;
	  if (PC2[0] == 0)
	      s += KHOPNX;
	  /* Fall through */
      case 1:
      case 3:
      case 7:
	  if (PC1[fyle - 1] == 0)
	      s += KHOPN;
	  if (PC2[fyle - 1] == 0)
	      s += KHOPNX;
	  break;
      default:
	  /* Impossible! */
	  break;
      }
    /*  Some extra code for Ng5 problem */
    if (computer==c1 && fyle >= 6 && HasQueen[c2] && PC1[7]==0)
      s += AHOPEN;
    if (computer==c1 && fyle <= 1 && HasQueen[c2] && PC1[0]==0)
      s += AHOPEN;

    a2 = (atk2[sq] & 0x4FFF);
    if (a2 > 0)
      {
	  a1 = (atk1[sq] & 0x4FFF);
	  if (a1 == 0 || a2 > ctlK + 1)
	    {
		s += HUNGP;
		++hung[c1];
	    }
	  else
	      s += ATAKD;
      }
    return (s);
}


static int (*PieceValue[7]) (SHORT, SHORT) =
{NULL, PawnValue, KnightValue, BishopValue, RookValue, QueenValue, KingValue};

SHORT
ScorePosition (register SHORT side)

/*
 * Perform normal static evaluation of board position. A score is generated
 * for each piece and these are summed to get a score for each side.
 */

{
    register SHORT score;
    register SHORT sq, i, xside;
    SHORT s;

    xside = side ^ 1;
    hung[white] = hung[black] = pscore[white] = pscore[black] = 0;
/* initialize Hasxxx */
    HasKnight[white] = HasKnight[black] = 0;
    HasBishop[white] = HasBishop[black] = 0;
    HasRook[white] = HasRook[black] = 0;
    HasQueen[white] = HasQueen[black] = 0;
    for (s = white; s <= black; s++)
	for (i = PieceCnt[s]; i >= 0; i--)
	    switch (board[PieceList[s][i]])
	      {
	      case knight:
		  ++HasKnight[s];
		  break;
	      case bishop:
		  ++HasBishop[s];
		  break;
	      case rook:
		  ++HasRook[s];
		  break;
	      case queen:
		  ++HasQueen[s];
		  break;
	      }
#ifdef CACHE
    if (!(hashkey+hashbd) || !ProbeEETable (side, &s))
      {
#endif
          UpdateWeights ();
	  for (c1 = white; c1 <= black; c1++)
	    {
		c2 = c1 ^ 1;
		/* atk1 is array of atacks on squares by my side */
		atk1 = atak[c1];
		/* atk2 is array of atacks on squares by other side */
		atk2 = atak[c2];
		/* same for PC1 and PC2 */
		PC1 = PawnCnt[c1];
		PC2 = PawnCnt[c2];
		for (i = PieceCnt[c1]; i >= 0; i--)
		  {
		      sq = PieceList[c1][i];
		      s = (*PieceValue[board[sq]]) (sq, side);	
/*		      switch (board[sq])
			{
			case pawn:
			    s = PawnValue (sq, side);
			    break;
			case knight:
			    s = KnightValue (sq);
			    break;
			case bishop:
			    s = BishopValue (sq);
			    break;
			case rook:
			    s = RookValue (sq);
			    break;
			case queen:
			    s = QueenValue (sq);
			    break;
			case king:
			    s = KingValue (sq);
			    break;
			default:
			    s = 0;
			    break;
			} */
		      pscore[c1] += s;
		      svalue[sq] = s;
		  }
	    }
    if (hung[side] > 1)
	pscore[side] += HUNGX;
    if (hung[xside] > 1)
	pscore[xside] += HUNGX;
    if (hung[computer] > 1)
	pscore[computer] += 8 * HUNGX; 

/*  Bonus for double bishops  */
    if (HasBishop[side] == 2)
	pscore[side] += 10 + 2 * stage;
    if (HasBishop[xside] == 2)
	pscore[xside] += 10 + 2 * stage;

    score = mtl[side] - mtl[xside] + pscore[side] - pscore[xside] + 10;
#ifndef NODITHER
    if (dither)
      {
	  if (flag.hash)
	      gsrand (starttime + (unsigned int) hashbd);
	  score += urand () % dither;
      }
#endif
    if (score > 0 && pmtl[side] == 0)
	if (emtl[side] < valueR)
	    score = 0;
	else if (score < valueR)
	    score /= 2;
    if (score < 0 && pmtl[xside] == 0)
	if (emtl[xside] < valueR)
	    score = 0;
	else if (-score < valueR)
	    score /= 2;

    if (mtl[xside] == valueK && emtl[side] > valueB)
	score += 200;
    if (mtl[side] == valueK && emtl[xside] > valueB)
	score -= 200;
#ifdef CACHE
    if(PUTVAR)PutInEETable(side,score);
#endif
    return (score);
#ifdef CACHE
}
else {
return s;
}
#endif
}
static inline void
BlendBoard (const SHORT a[64], const SHORT b[64], SHORT c[64])
{
    register int sq, s;
    s = 10 - stage;
    for (sq = 0; sq < 64; sq++)
	c[sq] = ((a[sq] * s) + (b[sq] * stage)) / 10;
}


void
ExaminePosition (void)

/*
 * This is done one time before the search is started. Set up arrays Mwpawn,
 * Mbpawn, Mknight, Mbishop, Mking which are used in the SqValue() function
 * to determine the positional value of each piece.
 */

{
    register SHORT i, sq;
    register SHORT fyle;
    SHORT wpadv, bpadv, wstrong, bstrong, z, side, pp, j, k, val, Pd, rank;
    static SHORT PawnStorm = false;
/* update ataks arrays */
    ataks (white, atak[white]);
    ataks (black, atak[black]);
/*	*/
    UpdateWeights ();
/* initialize Hasxxx */
    HasKnight[white] = HasKnight[black] = 0;
    HasBishop[white] = HasBishop[black] = 0;
    HasRook[white] = HasRook[black] = 0;
    HasQueen[white] = HasQueen[black] = 0;
    for (side = white; side <= black; side++)
	for (i = PieceCnt[side]; i >= 0; i--)
	    switch (board[PieceList[side][i]])
	      {
	      case knight:
		  ++HasKnight[side];
		  break;
	      case bishop:
		  ++HasBishop[side];
		  break;
	      case rook:
		  ++HasRook[side];
		  break;
	      case queen:
		  ++HasQueen[side];
		  break;
	      }
/* Developed if has moved knights and bishops */
    if (!Developed[white])
	Developed[white] = (board[1] != knight && board[2] != bishop &&
			    board[5] != bishop && board[6] != knight);
    if (!Developed[black])
	Developed[black] = (board[57] != knight && board[58] != bishop &&
			    board[61] != bishop && board[62] != knight);
/* Pawn Storm */
/*    if (!PawnStorm && stage < 5)*/
    PawnStorm = (stage < 5) &&
	           ((column (wking) < 3 && column (bking) > 4) ||
		     (column (wking) > 4 && column (bking) < 3));
/* setup base tables */
    memcpy (Mknight[white],pknight,sizeof(pknight));
    memcpy (Mknight[black],pknight,sizeof(pknight));
    memcpy(Mbishop[white],pbishop,sizeof(pbishop));
    memcpy(Mbishop[black],pbishop,sizeof(pbishop));

/* linear interpolate on stage	*/
/* Mking = (KingOpening * (10 - stage) + KingEnding * srage) /10  */
    BlendBoard (KingOpening, KingEnding, Mking[white]);
    BlendBoard (KingOpening, KingEnding, Mking[black]);

    for (sq = 0; sq < 64; sq++)
      {
	  fyle = column (sq);
	  rank = row (sq);
	  wstrong = bstrong = true;
/* does a black pawn attack to squares in this col from sq to end */
	  for (i = sq; i < 64; i += 8)
	      if (Patak (black, i)) { wstrong = false; break; }
/* does a white pawn attack to squares in this col from sq to end */
	  for (i = sq; i >= 0; i -= 8)
	      if (Patak (white, i)) { bstrong = false; break; }
/* 	*/
	  wpadv = bpadv = PADVNCM;
	  if ((fyle == 0 || PawnCnt[white][fyle - 1] == 0) && (fyle == 7 || PawnCnt[white][fyle + 1] == 0)) wpadv = PADVNCI;
	  if ((fyle == 0 || PawnCnt[black][fyle - 1] == 0) && (fyle == 7 || PawnCnt[black][fyle + 1] == 0)) bpadv = PADVNCI;
	  Mwpawn[sq] = (wpadv * PawnAdvance[sq]) / 10;
	  Mbpawn[sq] = (bpadv * PawnAdvance[63 - sq]) / 10;
	  Mwpawn[sq] += PawnBonus;
	  Mbpawn[sq] += PawnBonus;
/* 	*/
	  if (Mvboard[kingP[white]])
	    {
		if ((fyle < 3 || fyle > 4) && distance (sq, wking) < 3)
		    Mwpawn[sq] += PAWNSHIELD;
	    }
	  else if (rank < 3 && (fyle < 2 || fyle > 5))
	      Mwpawn[sq] += PAWNSHIELD / 2;
/* 	*/
	  if (Mvboard[kingP[black]])
	    {
		if ((fyle < 3 || fyle > 4) && distance (sq, bking) < 3)
		    Mbpawn[sq] += PAWNSHIELD;
	    }
	  else if (rank > 4 && (fyle < 2 || fyle > 5))
	      Mbpawn[sq] += PAWNSHIELD / 2;
/* 	*/
	  if (PawnStorm)
	    {
		if ((column (wking) < 4 && fyle > 4) || (column (wking) > 3 && fyle < 3))
		    Mwpawn[sq] += 4 * rank;
		if ((column (bking) < 4 && fyle > 4) || (column (bking) > 3 && fyle < 3))
		    Mbpawn[sq] -= (4 * rank - 28);
	    }
/* 	*/
	  Mknight[white][sq] += 5 - distance (sq, bking);
	  Mknight[white][sq] += 5 - distance (sq, wking);
	  Mknight[black][sq] += 5 - distance (sq, wking);
	  Mknight[black][sq] += 5 - distance (sq, bking);
/* 	*/
	  Mbishop[white][sq] += BishopBonus;
	  Mbishop[black][sq] += BishopBonus;
/* 	*/
	  for (i = PieceCnt[black]; i >= 0; i--)
	      if (distance (sq, PieceList[black][i]) < 3)
		  Mknight[white][sq] += KNIGHTPOST;
	  for (i = PieceCnt[white]; i >= 0; i--)
	      if (distance (sq, PieceList[white][i]) < 3)
		  Mknight[black][sq] += KNIGHTPOST;
/* 	*/
	  if (wstrong)
	      Mknight[white][sq] += KNIGHTSTRONG;
	  if (bstrong)
	      Mknight[black][sq] += KNIGHTSTRONG;
	  if (wstrong)
	      Mbishop[white][sq] += BISHOPSTRONG;
	  if (bstrong)
	      Mbishop[black][sq] += BISHOPSTRONG;
/* 	*/
#ifdef notdef
	  if (HasBishop[white] == 2)
	      Mbishop[white][sq] += 8;
	  if (HasBishop[black] == 2)
	      Mbishop[black][sq] += 8;
	  if (HasKnight[white] == 2)
	      Mknight[white][sq] += 5;
	  if (HasKnight[black] == 2)
	      Mknight[black][sq] += 5;
#endif
/* 	*/

	  Kfield[white][sq] = Kfield[black][sq] = 0;
	  if (distance (sq, wking) == 1)
	      Kfield[black][sq] = KATAK;
	  if (distance (sq, bking) == 1)
	      Kfield[white][sq] = KATAK;
/* 	*/
	  Pd = 0;
	  for (k = 0; k <= PieceCnt[white]; k++)
	    {
		i = PieceList[white][k];
		if (board[i] == pawn)
		  {
		      pp = true;
		      for (j = i + 8; j < 64; j += 8)
			  if (Patak (black, j) || board[j] == pawn)
			    {
				pp = false;
				break;
			    }
		      z = (pp ? i + ((row (i) == 6) ? 8 : 16) : i);
		      Pd += ((pp) ? 5 * taxicab (sq, z) : taxicab (sq, z));
		  }
	    }
/* 	*/
	  for (k = 0; k <= PieceCnt[black]; k++)
	    {
		i = PieceList[black][k];
		if (board[i] == pawn)
		  {
		      pp = true;
		      for (j = i - 8; j >= 0; j -= 8)
			  if (Patak (white, j) || board[j] == pawn)
			    {
				pp = false;
				break;
			    }
		      z = (pp ? i - ((row (i) == 1) ? 8 : 16) : i);
		      Pd += ((pp) ? 5 * taxicab (sq, z) : taxicab (sq, z));
		  }
	    }
/* 	*/
	  if (Pd != 0)
	    {
		val = (Pd * stage2) / 4;
		Mking[white][sq] -= val;
		Mking[black][sq] -= val;
	    }
      }
}

void
UpdateWeights (void)

/*
 * If material balance has changed, determine the values for the positional
 * evaluation terms.
 */

{
    register SHORT s1, tmtl;

    emtl[white] = mtl[white] - pmtl[white] - valueK;
    emtl[black] = mtl[black] - pmtl[black] - valueK;
    tmtl = emtl[white] + emtl[black];
    s1 = ((tmtl > 6600) ? 0 : ((tmtl < 1400) ? 10 : (6600 - tmtl) / 520));
    if (s1 != stage)
      {
	stage = s1;
	stage2 = ((tmtl > 3600) ? 0 : ((tmtl < 1400) ? 10 : (3600 - tmtl) / 220));
	PEDRNK2B = -15;		/* centre pawn on 2nd rank & blocked */
	PBLOK = -4;		/* blocked backward pawn */
	PDOUBLED = -14;		/* doubled pawn */
	PWEAKH = -12;		/* weak pawn on half open file */
	PAWNSHIELD = 10-stage;	/* pawn near friendly king */
	PADVNCM = 12;		/* advanced pawn multiplier */
	PADVNCI = 7;		/* muliplier for isolated pawn */
	PawnBonus = stage;

	KNIGHTPOST = (stage + 2) / 3;	/* knight near enemy pieces */
	KNIGHTSTRONG = (stage + 6) / 2;	/* occupies pawn hole */

	BISHOPSTRONG = (stage + 6) / 2;	/* occupies pawn hole */
	BishopBonus = BBONUS * stage;

	RHOPN = 10;		/* rook on half open file */
	RHOPNX = 4;
	RookBonus = RBONUS * stage;

	XRAY = 8;		/* Xray attack on piece */
	PINVAL = 16;		/* Pin */

	KHOPN = (2 * stage - 20);	/* king on half open file */
	KHOPNX = KHOPN / 2;
	KCASTLD = 10 - stage;
	KMOVD = -40 / (stage + 1);	/* king moved before castling */
	KATAK = (10 - stage);		/* B,R attacks near enemy king */
	KSFTY = ((stage < 8) ? (KINGSAFETY - 4 * stage) : 0);

	ATAKD = -8;		/* defender > attacker */
	HUNGP = -12;		/* each hung piece */
	HUNGX = -18;		/* extra for >1 hung piece */
      }
}

