#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

#define INFILE "zidar.in"
#define OUTFILE "zidar.out"

const int MMAX = 64;
const int NMAX = 64;
const int XMAX = 64;

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int dp[MMAX][NMAX][XMAX], zid[MMAX][NMAX];

int main() {

   int m, n, X, t;
   fin >> m >> n >> X >> t;
   memset(dp, 0x0f, sizeof(dp));

   for(int i=0; i<m; i++)
   for(int j=0; j<n; j++)
      fin >> zid[i][j];

   int best = 0;
   for(int i=0; i<n; i++)
   {
      int cost = 0;
      for(int j=i; j<n && (j-i+1)<=X; j++) {
         cost += zid[0][j];
         for(int k=i; k<=j; k++) {
            dp[0][k][j-i+1] = min(cost, dp[0][k][j-i+1]);
            if(cost<=t ) best = max(best, j-i+1);
         }
      }
   }

   for(int l=1; l<m; l++)
   {
      for(int i=0; i<n; i++)
      {
         int cost = 0;
         for(int j=i; j<n; j++) {
            cost += zid[l][j];
            for(int x = j-i+1+l; x<=X; x++) {
               int minval = dp[0][0][60];
               for(int k=i; k<=j; k++)
                  minval = min(minval, cost + dp[l-1][k][x-(j-i+1)]);

               if( minval<=t ) {
                  if( best<x ) {
                     best = x;
                     //cout << best << "\t" << l << " " << i << " " << j << "\t\t" << minval << " " << cost << " " << x-(j-i+1) << '\n';
                  }
               }
               for(int k=i; k<=j; k++)
                  dp[l][k][x] = min(minval, dp[l][k][x]);
            }
         }
      }
   }

   fout << best;

   return 0;
}
