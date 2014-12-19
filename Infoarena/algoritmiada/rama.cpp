#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "rama.in" 
#define OUTFILE "rama.out"
#define NMAX 702

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m, c[NMAX][NMAX], r[NMAX][NMAX];
vector<string> v;

int main() {
   fin >> n >> m;
   v.resize(n);
   for(int i=0; i<n; i++)
      fin >> v[i];

   int maxa = 0;
   for(int i=0; i<n; i++) {
      if( v[i][0]=='1' ) r[i][0] = 1;
      maxa = max(maxa, r[i][0]);
      for(int j=1; j<m; j++) {
         if( v[i][j]=='1' ) r[i][j] = r[i][j-1] + 1;
         else r[i][j] = 0;
         maxa = max(maxa, r[i][j]);
      }
   }

   for(int j=0; j<m; j++) {
      if( v[0][j]=='1' ) c[0][j] = 1;
      maxa = max(maxa, c[0][j]);
      for(int i=1; i<n; i++) {
         if( v[i][j]=='1' ) c[i][j] = c[i-1][j] + 1;
         else c[i][j] = 0;
         maxa = max(maxa, c[i][j]);
      }
   }

   for(int i=1; i<n; i++)
   for(int j=1; j<m; j++)
      if( r[i][j]>1 && c[i][j]>1 && r[i][j]*c[i][j]>maxa) {
         
         int rval = 1, pcmax = i;
         for(int pr = j - r[i][j] + 1; pr<j; pr++)
            if( c[i][pr] > rval ) {
               for(int pc = max(i - c[i][j] + 1, i - c[i][pr] + 1); pc<pcmax; pc++)
                  if( r[pc][j] >= j-pr+1 ) {
                     maxa = max(maxa, (i-pc+1) * (j-pr+1));
                     rval = c[i][pr];
                     pcmax = i-pc+1;
                  }
            }
      }

   fout << maxa << '\n';
   return 0;
}
