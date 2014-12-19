/*
ID: andreic4
PROG: milk4
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXQ 20005
#define MAXP 105
#define INF  0x7fffffff

void    findMinPails ();
void    backtrack ();
int     betterSequence (int a, int b);
int     compare (const void *a, const void *b);

int     nQuart, nPail;
int     pails[MAXP];
int     minPails[MAXQ];
int     lastPail[MAXQ];
int     nLast[MAXQ];
int     finalSet[MAXP], nFinal;

int 
main ()
{
    FILE   *fin = fopen ("milk4.in", "r");
    fscanf (fin, "%d %d", &nQuart, &nPail);

    for (int i = 0; i < nPail; i++)
 fscanf (fin, "%d", &(pails[i]));
    fclose (fin);

    qsort (pails, nPail, sizeof (pails[0]), compare);

    findMinPails ();
    backtrack ();

    FILE   *fout = fopen ("milk4.out", "w");
    fprintf (fout, "%d", nFinal);

    for (int i = 0; i < nFinal; i++)
 fprintf (fout, " %d", finalSet[i]);
    fprintf (fout, "\n");
    fclose (fin);

    return 0;
}

void 
findMinPails ()
{
    //Indicate that nothing is possible yet
    for (int i = 0; i <= nQuart; i++) {
 lastPail[i] = -1;
 minPails[i] = INF;
 nLast[i] = -1;
    }

    minPails[0] = 0;

    for (int i = 0; i < nPail; i++) {
 int     tempMP[MAXQ], tempLP[MAXQ], tempNL[MAXQ];

 for (int j = 0; j <= nQuart; j++) {
     tempMP[j] = minPails[j];
     tempLP[j] = lastPail[j];
     tempNL[j] = nLast[j];
 }

 for (int j = pails[i]; j <= nQuart; j++) {
     int     prev = j - pails[i];

     if (tempMP[prev] < INF) { /* meaning it's reachable */
//case 1: try using more of this pail
      if (tempLP[prev] == pails[i]) {
      tempLP[j] = pails[i];
      tempMP[j] = tempMP[prev];
      tempNL[j] = tempNL[prev] + 1;
  }

//case 2: try using just one of this pail
      // because we have to
      if (tempLP[prev] != pails[i]) {
      tempLP[j] = pails[i];
      tempMP[j] = tempMP[prev] + 1;
      tempNL[j] = 1;
  }

//case 3: try using just one of this pail
     /* because it's better */
      if (minPails[prev] < INF &&
      (minPails[prev] + 1 < tempMP[j] ||
   (minPails[prev] + 1 == tempMP[j] &&
       betterSequence (prev,
    j - tempNL[j] * pails[i])
   ))) {
      tempLP[j] = pails[i];
      tempMP[j] = minPails[prev] + 1;
      tempNL[j] = 1;
  }
     }
 }

 for (int j = pails[i]; j <= nQuart; j++)
     if (tempMP[j] <= minPails[j]) {
  minPails[j] = tempMP[j];
  lastPail[j] = tempLP[j];
  nLast[j] = tempNL[j];
     }
    }
}

void 
backtrack ()
{
    int     curr = nQuart;
    nFinal = minPails[nQuart];

    for (int j = 0; j < nFinal; j++) {
 finalSet[j] = lastPail[curr];
 curr -= lastPail[curr] * nLast[curr];
    }
}

int 
betterSequence (int a, int b)
//See if the sequence arriving at "a" is better than that arriving at "b"
// Assume the two sequences have equal lengths
{
    while (a && b) {
 if (lastPail[a] < lastPail[b])
     return 1;
 if (lastPail[a] > lastPail[b])
     return 0;

 a -= nLast[a] * lastPail[a];
 b -= nLast[b] * lastPail[b];
    }

    if (a)
 return 0;
    return 1;
}

int 
compare (const void *a, const void *b) //Sort in descending order
{
    return *(int *) b - *(int *) a;
}