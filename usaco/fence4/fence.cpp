/*
ID: andreic4
PROG: fence4
LANG: C++
*/
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
#define SQR(A) ((A)*(A))
 
/* maximum number of points */
#define MAXN 201
 
/* number of points */
int npos;
 
/* the points, where pos[npos] == pos[0] */
double pos[MAXN][2];
 
/* observer's location */
double obsx, obsy;
 
/* cansee[x] = can we see the segment (x,x+1)? */
int cansee[MAXN];
 
int side(double sx, double sy, double ex, double ey, int p)
 { /* determine the side that the points lie on */
  double dx, dy;
  double px, py;
  double t;
 
  dx = ex - sx;
  dy = ey - sy;
 
  px = pos[p][0] - sx;
  py = pos[p][1] - sy;
 
  /* take cross-product */
  t = dx * py - dy * px;
 
  if (t > 0.00001) return 0; /* "left" side */
  if (t < -0.00001) return 1; /* "right" side */
  return 2; /* on the line */
 }
 
int first_inter(double sx, double sy, double ex, double ey)
 { /* what is the first segment intersected by the ray s->e */
  int lv; /* loop variable */
  int t1, t2;
  int s1, s2;
  double ax, ay, bx, by;
  double t;
  double coeff, cnst;
  double i, j;
  double x, y;
  double mlbrush, mrbrush; /* when is the earliest brush on a side? */
 
  /* min = distance to nearest intersection point */
  /* mloc = edge where this occurs */
  double min = 1e10; /* ~= infinity */
  int mloc = npos; /* unused location */
 
  mlbrush = mrbrush = 1e10; /* infinity */
 
  for (lv = 0; lv < npos; lv++)
   { /* for each segment, determine length along */
    ax = pos[lv][0];
    ay = pos[lv][1];
    bx = pos[lv+1][0];
    by = pos[lv+1][1];
 
    /* take cross product */
    t = (ex - sx) * (ay - by) - (ey - sy) * (ax - bx);
    if (t > -0.00001 && t < 0.00001) /* parallel */
      continue; /* not considered visible */
 
    /* not parallel */
    /* we are now solving the following equations:
     (ex - sx) j + sx = (bx - ax) i + ax
     (ey - sy) j + sy = (by - ay) i + ay
    */
 
    /* solves for alpha by multiple first by (by - ay) and
       the second by (bx - ax) and subtracting equations */
    cnst = (ax - sx)*(by - ay) - (ay - sy)*(bx - ax);
    coeff = (ex - sx) * (by - ay) - (ey - sy) * (bx - ax);
    if (coeff > -0.00001 && coeff < .00001)
     { /* degenerate, one of bx - ax and by - ay is about zero */
      if (bx - ax > -.00001 && bx - ax < 0.00001)
       { /* bx - ax == 0, can solve first eqn directly */
        cnst = ax - sx;
        coeff = ex - sx;
       } else { /* by - ay == 0, can solve second eqn directly */
        cnst = ay - sy;
        coeff = ey - sy;
       }
     }
    j = cnst / coeff;
 
    /* if intersection occurs before starting point, no intersection */
    if (j < -.00001) continue;
 
    /* determine beta */
    cnst = sx + (ex - sx) * j - ax;
    coeff = bx - ax;
    if (coeff > -0.00001 && coeff < .00001)
     { /* handle degeneracy */
      cnst = sy + (ey - sy) * j - ay;
      coeff = by - ay;
     }
    i = cnst / coeff;
 
    /* if the interesection occurs with i < 0 | i > 1, the
       intersection is not within the confines of the segment */
    if (i < -.00001 || i > 1.00001) continue;
 
    /* calculate intersection point */
    x = ax + (bx - ax) * i;
    y = ay + (by - ay) * i;
 
    /* determine distance along line that intersection occurs */
    t = (x - sx) * (ex - sx) + (y - sy) * (ey - sy);
 
    /* make sure it's in bounds, and better than what we have */
    if (t < -0.00001 || t > min) continue;
 
    /* if it occurs at an end point */
    if (i < .00001 || i > 0.99999) 
     {
      /* find the endpoints that are incident to the intersected endpoint */
      if (i < .00001)
       {
        t1 = lv-1;
        if (t1 < 0) t1 += npos;
        t2 = lv+1;
       } else {
        t1 = lv;
        t2 = lv+2;
        if (t2 >= npos) t2 -= npos;
       }
 
      /* if they lie on the same side of the line, then ray 'brushes'
         endpoint, which is not considered to an intersection */
 
      s1 = side(sx,sy,ex,ey,t1);
      s2 = side(sx,sy,ex,ey,t2);
      if (s1 == s2) {
	if (s1 == 0 && t < mlbrush) mlbrush = t;
	if (s1 == 1 && t < mrbrush) mrbrush = t;
        continue;
      }
     }
    /* found a better edge! */
    min = t;
    mloc = lv;
   }
/* if it brushes on both sides, it cannot be seen */
  if (min > mlbrush && min > mrbrush) return npos;
  return mloc;
 }
 
int check_intersect(int f1, int f2) 
 { /* do (f1,f1+1) and (f2,f2+1) intersect? */
  double sx, sy;
  double ex, ey;
 
  sx = pos[f1][0];
  sy = pos[f1][1];
  ex = pos[f1+1][0];
  ey = pos[f1+1][1];
 
  if (side(sx, sy, ex, ey, f2) == side(sx, sy, ex, ey, f2+1))
  /* are the f2 and f2+1 on the same side of (f1,f1+1)? */
    return 0; /* if so, the segments don't intersect */
 
  sx = pos[f2][0];
  sy = pos[f2][1];
  ex = pos[f2+1][0];
  ey = pos[f2+1][1];
 
  if (side(sx, sy, ex, ey, f1) == side(sx, sy, ex, ey, f1+1))
  /* are f1 & f1+1 on the same side of (f2,f2+1) */
    return 0; /* if so, the segments don't intersect */
 
  /* the endpoints of each segment are on opposite sides of
     the other segment.  Therefore, they intersect */
  return 1; 
 }
 
int main(int argc, char **argv)
 {
  FILE *fout, *fin;
  int lv, lv2;
  int cnt;
  int t;
  double dx, dy;
 
  if ((fin = fopen("fence4.in", "r")) == NULL)
   {
    perror ("fopen fin");
    exit(1);
   }
  if ((fout = fopen("fence4.out", "w")) == NULL)
   {
    perror ("fopen fout");
    exit(1);
   }
 
  fscanf (fin, "%d", &npos);
  fscanf (fin, "%lf %lf", &obsx, &obsy);
  for (lv = 0; lv < npos; lv++)
    fscanf (fin, "%lf %lf", &pos[lv][0], &pos[lv][1]);
  pos[npos][0] = pos[0][0];
  pos[npos][1] = pos[0][1];
 
/* for each pair of segments that don't share a vertex */
  for (lv = 0; lv < npos; lv++)
    for (lv2 = lv+2; lv2 < npos; lv2++)
      if (check_intersect(lv, lv2))
       { /* if they intersect */
 
        /* and don't share a vertex */
        if (lv == 0 && lv2 == npos-1) continue; 
 
        /* then the fence is invalid */
        fprintf (fout, "NOFENCE\n"); 
        return 0;
       }
 
  for (lv = 0; lv < npos; lv++)
   {
    /* check endpoint */
    cansee[first_inter(obsx, obsy, pos[lv][0], pos[lv][1])] = 1;
 
    /* check midpoint of segment (lv, lv+1) */
    cansee[first_inter(obsx, obsy, 
               (pos[lv][0] + pos[lv+1][0])*0.5, 
               (pos[lv][1] + pos[lv+1][1])*0.5)] = 1;
   }
 
  /* count number of visible segments */
  cnt = 0;
  for (lv = 0; lv < npos; lv++)
    if (cansee[lv]) cnt++;
 
  fprintf (fout, "%i\n", cnt);
 
  /* list visible segments */
  for (lv = 0; lv < npos-2; lv++)
    if (cansee[lv])
     {
      fprintf (fout, "%.0f %.0f %.0f %.0f\n", pos[lv][0], pos[lv][1], 
            pos[lv+1][0], pos[lv+1][1]);
     }
  /* because of the way the ordering is defined, these two must be
     checked separately */
  if (cansee[npos-1])
   {
    fprintf (fout, "%.0f %.0f %.0f %.0f\n", pos[0][0], pos[0][1], 
          pos[npos-1][0], pos[npos-1][1]);
   }
  if (cansee[npos-2])
   {
      fprintf (fout, "%.0f %.0f %.0f %.0f\n", pos[npos-2][0], pos[npos-2][1], 
            pos[npos-2+1][0], pos[npos-2+1][1]);
   }
 
  return 0;
 }