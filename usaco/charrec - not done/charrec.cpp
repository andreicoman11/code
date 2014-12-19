/*
ID: andreic4
PROG: charrec
LANG: C++
*/
#include <stdio.h>

FILE *e = fopen ("font.in", "r");
FILE *f = fopen ("charrec.in", "r");
FILE *g = fopen ("charrec.out", "w");
long const limax = 30;//max for no. of characters in a row and no. of ideal images in font.in
long const nmax = 1210;//max for no. of lines in charrec.in
long nlit, nlin, nsol;
char lit[limax][limax][limax], lin[nmax][limax];
/*
  lit[i] stores the (i-1)-th ideal character image from "font.in"
  lin[i] stores the (i+2)-th line from "charrec.in"
*/

char sol[nmax];
long x[nmax], pred[nmax], car[nmax];
/*
  x[i] stores the minimum number of total corruptions so far ( that is the minimum number of
  characaters changed from lines lin[0], lin[1], ...lin[i-1], to obtain a sequence (s)
  of ideal character images )
  lit[ car[i] ] is the last ideal image in (s)
  (i-pred[i]) can be 19, 20 or 21 == the number of lines of the corrupted image of car[i]
*/

long dist[limax][limax][nmax];
/*
  dist[i][j][k] remembers the number of differences (corruptions) between lit[i][j] and lin[k]
  so we won't waste precious time recalculating it again and again using difv()
*/

void citeste (); //reads data and intializes variables
long difv (char a[limax], char b[limax]); //counts the differences between a and b
void ident();//computes x[], pred[] and car[]
void recon(long k); //constructs sol[], based on the three above
void scrie();//writes sol[]

int main () {
    citeste ();
    ident ();
    recon (nlin);
    scrie ();
    fclose (e);
    fclose (f);
    fclose (g);
    return 0;
}

void citeste () {
    long i, j, k;
    char aux;
    fscanf (e, "%d", &nlit);
    fscanf (e, "%c", &aux);
    nlit = nlit / 20;
    for(i = 0; i < nlit; i++) {
        for (j = 0; j < 20; j++) {
            for (k = 0; k < 20; k++)
  fscanf (e, "%c", &lit[i][j][k]);
            fscanf (e, "%c", &aux);
        }
    }
    
    fscanf (f, "%d", &nlin);
    fscanf (f, "%c", &aux);
    for(i = 0; i < nlin; i++) {
        for (j = 0; j < 20; j++)
     fscanf (f, "%c", &lin[i][j]);
        fscanf (f, "%c", &aux);
    }
    for (i = 0; i <= nlin; i++)
        x[i] = pred[i] = car[i] = -1;
    x[0] = 0;
    for (i = 0; i < nlit; i++)
        for (j = 0; j < 20; j++)
            for (k = 0; k < nlin; k++)
                dist[i][j][k] = -1;
}

long difv (char a[limax], char b[limax]) {
    long i, ndif=0;
    for (i = 0; i < 20; i++)
 if (a[i] != b[i])
     ndif++;
    return ndif;
}

void ident() {
    long i, j, k, t, pret;
    for(i=0; i<=nlin; i++) {
 if(x[i]!=-1) {
            for(j=0; j<nlit; j++) {
  //a line is misssing
         if(nlin >= i+19) {
               pret = 0;
               for (t = 0; t < 19; t++) {
              if(dist[j][t+1][i+t]==-1)
       dist[j][t+1][i+t] = difv(lit[j][t+1], lin[i+t]);
              pret+=dist[j][t+1][i+t];
               }
               if ((x[i+19]==-1 || pret+x[i] < x[i+19]) && pret<=114) {
              x[i+19] = x[i]+pret;
              pred[i+19] = i;
              car[i+19] = j;
               }
               for (k = 1; k < 20; k++) {
              if (dist[j][k-1][i+k-1] == -1)
       dist[j][k-1][i+k-1] = difv(lit[j][k-1], lin[i+k-1]);
   if (dist[j][k][i+k-1] == -1)
       dist[j][k][i+k-1] = difv(lit[j][k], lin[i+k-1]);
              pret += dist[j][k-1][i+k-1]-dist[j][k][i+k-1];
              if((x[i+19]==-1 || pret+x[i] < x[i+19]) && pret<=114) {
                    x[i+19] = x[i]+pret;
                    pred[i+19] = i;
                    car[i+19] = j;
              }
               }
         }
         // no line missing or duplicated
         if(nlin >= i+20) {
               pret=0;
               for (k = 0; k < 20; k++) {
              if (dist[j][k][i+k]==-1)
       dist[j][k][i+k] = difv(lit[j][k], lin[i+k]);
              pret += dist[j][k][i+k];
               }
               if ((x[i+20]==-1 || pret+x[i] < x[i+20]) && pret<=120) {
              x[i+20] = x[i]+pret;
              pred[i+20] = i;
              car[i+20] = j;
               }
         }
         //a line is duplicated
         if (nlin >= i+21) {
               pret = 0;
               for (t = 0; t < 20; t++) {
              if(dist[j][t][i+t+1]==-1)
       dist[j][t][i+t+1] = difv(lit[j][t], lin[i+t+1]);
              pret += dist[j][t][i+t+1];
               }
               if ((x[i+21]==-1 || pret+x[i] < x[i+21]) && pret<=120) {
              x[i+21] = x[i]+pret;
              pred[i+21] = i;
              car[i+21] = j;
               }
               for (k = 1; k < 21; k++) {
              if (dist[j][k-1][i+k-1]==-1)
       dist[j][k-1][i+k-1] = difv(lit[j][k-1], lin[i+k-1]);
              if(dist[j][k-1][i+k]==-1)
       dist[j][k-1][i+k] = difv(lit[j][k-1], lin[i+k]);
              pret += dist[j][k-1][i+k-1]-dist[j][k-1][i+k];
              if((x[i+21]==-1 || pret+x[i] < x[i+21]) && pret<=120) {
                    x[i+21] = x[i]+pret;
                    pred[i+21] = i;
                    car[i+21] = j;
              }
               }
         }
         }
        }
    }
}

void recon(long k) {
    long t;
    if (pred[k] != -1) {
        recon (pred[k]);
        t = car[k];
        if (t==0)
       t = -64;
        t += 96;
        nsol++;
        sol[nsol] = char(t);
    }
}

void scrie() {
    long i;
    for (i = 1; i <= nsol; i++)
 fprintf (g, "%c", sol[i]);
    fprintf (g, "\n");
}