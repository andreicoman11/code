#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "ternar.in" 
#define OUTFILE "ternar.out"
#define NMAX 1250

int m[NMAX][NMAX], N, M;
bool v[NMAX][NMAX];

int main()
{
   FILE* fin  = fopen(INFILE, "r");
   FILE* fout = fopen(OUTFILE, "w+");
   fscanf(fin, "%d %d", &N, &M);
   for(int i=0; i<N; i++)
   for(int j=0; j<M; j++)
      fscanf(fin, "%d", &m[i][j]);

   int rez = 0;
   memset(v, 0, sizeof(v));
   for(int i=1; i<N-1; i++)
   for(int j=1; j<M-1; j++)
      if( m[i][j]==2 && !v[i][j] && m[i-1][j-1]==1 && m[i-1][j]==1 && m[i][j-1]==1 )
      {
         bool vx = 1, vy = 1;
         int x = i+1;
         while( x<N && m[x][j]==2 )
         {
            v[x][j] = 1;
            if( m[x][j-1]!=1 ) vx = 0;
            x++;
         }
         if( x==N || vx==0) continue;

         int y = j+1;
         while( y<M && m[i][y]==2 )
         {
            v[i][y] = 1;
            if( m[i-1][y]!=1 ) vy = 0;
            y++;
         }
         if( y==M || vy==0 ) continue;

         x--; y--;
         for(int ii=i; ii<=x; ii++)
            if( m[ii][y]!=2 || m[ii][y+1]!=1 ) vx = 0;
            else v[ii][y] = 1;

         for(int jj=j; jj<=y; jj++)
            if( m[x][jj]!=2 || m[x+1][jj]!=1 ) vy = 0;
            else v[x][jj] = 1;

         if( vx==0 || vy==0 ) continue;
         if( m[x+1][y+1]!=1 || m[x+1][j-1]!=1 || m[i-1][y+1]!=1 ) continue;

         for(int ii = i+1; ii<x; ii++)
         for(int jj = j+1; jj<y; jj++)
            if( m[ii][jj]!=2 ) vx=0;
            else v[ii][jj] = 1;
         if( vx==0 ) continue;
         rez = max(rez, (x-i+3)*(y-j+3));
      }

   fprintf(fout, "%d\n", rez);

	return 0;
}