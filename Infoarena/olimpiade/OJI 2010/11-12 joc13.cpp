#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "joc13.in" 
#define OUTFILE "joc13.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int NMAX = 5005;
const int INF = -5000000;
int n, K, val[NMAX][2], d[NMAX][2][11];

int main() {
   fin >> n >> K;

   for(int j=0; j<2; j++)
   for(int i=0; i<n; i++)
      fin >> val[i][j];

   memset(d, INF, sizeof(d));
   for(int k=1; k<=1; k++) {
      d[0][0][k] = val[0][0];
      d[0][1][k] = val[0][1] + val[0][0];
   }

   for(int i=1; i<n; i++) {
      for(int j=0; j<2; j++) {
         int dmax = INF;
         int s = val[i][j];
         for(int k = 1; k<K && i-k>=0; k++) {
            d[i][j][1+k] = max(d[i][j][1+k], s + d[i-k][j][1]);
            dmax = max(dmax, d[i][j][1+k]);
            s += val[i-k][j];
         }
         d[i][1-j][1] = max(d[i][1-j][1], val[i][1-j] + dmax);
      }
   }

   int res = INF;
   for(int k=1; k<=K; k++)
      res = max(res, d[n-1][1][k]);
   fout << res ;
   return 0;
}
