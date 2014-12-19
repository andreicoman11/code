#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "strmatch.in" 
#define OUTFILE "strmatch.out"
#define SMAX 2000005
#define SOLMAX 1005

ifstream fin(INFILE);
ofstream fout(OUTFILE);

char a[SMAX], b[SMAX];
int t[SMAX], sol[SOLMAX];

int main() {

   fin.getline(a, SMAX);
   fin.getline(b, SMAX);
   int res = 0;

   int k = 0, n = strlen(a), m = strlen(b);
   for(int j=1; j<n; j++) {
      while( k>0 && a[j]!=a[k] ) k = t[k-1];

      if( a[j]==a[k] ) k++;

      t[j] = k;
   }

   k = 0;
   for(int i=0; i<m; i++) {
      while( k>0 && b[i]!=a[k] ) k = t[k-1];

      if( b[i]==a[k] ) k++;
      if( k==n ) {
         if( res<1000 ) sol[res] = i-n+1;
         res++;
         k = t[k-1];
      }
   }

   fout << res << '\n';
   for(int i=0; i<min(res, 1000); i++)
      fout << sol[i] << " ";

   return 0;
}
