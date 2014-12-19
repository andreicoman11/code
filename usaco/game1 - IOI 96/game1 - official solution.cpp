/*
ID: andreic4
PROG: game1
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#define MAXBOARD 110
 
int board[MAXBOARD];
 
/*
 * best and total are indexed so that (e.g.) best[i, l] refers
 * to the board of length l starting at place i.
 */
int total[MAXBOARD][MAXBOARD];
int best[MAXBOARD][MAXBOARD];
 
int
max(int a, int b)
{
    return a > b ? a : b;
}
 
void
main(void)
{
    FILE *fin, *fout;
    int j, l, n;
 
    fin = fopen("game1.in", "r");
    fout = fopen("game1.out", "w");
    assert(fin != NULL && fout != NULL);
 
    fscanf(fin, "%d", &n);
    for(j=0; j<n; j++)
        fscanf(fin, "%d", &board[j]);
 
    /* calculate subboard totals */
    for(j=0; j<n; j++)
        total[j][0] = 0;
 
    for(l=1; l<=n; l++)
    for(j=0; j+l<=n; j++)
        total[j][l] = board[j] + total[j+1][l-1];
 
    /* calc best for boards of size one */
    for(j=0; j+1<=n; j++)
        best[j][1] = board[j];
 
    /* calc best for bigger boards */
    for(l=2; l<=n; l++)
      for(j=0; j+l<=n; j++)
        best[j][l] = max(board[j]     + total[j+1][l-1] - best[j+1][l-1],
                         board[j+l-1] + total[j  ][l-1] - best[j  ][l-1]);
 
 
    fprintf(fout, "%d %d\n", best[0][n], total[0][n]-best[0][n]);
 
    exit(0);
}
