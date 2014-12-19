#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "loto2.in" 
#define OUTFILE "loto2.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {
   int res = 1999999973;
   int n;
   fin >> n;
   vector<int> v(n);
   int maxv = 0;
   for(int i=0; i<n; i++) {
      fin >> v[i];
      maxv = max(maxv, v[i]);
   }

   if( maxv>=res ) {
      res = maxv;
      bool ok = 0;
      while( !ok ) {
         res++;
         ok = 1;
         for(int i=0; ok && i<n; i++)
            if( res % v[i]==0 )
               ok = 0;
      }
   }

   fout << res;


   return 0;
}
