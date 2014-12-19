#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

#define INFILE "pagina.in" 
#define OUTFILE "pagina.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {
   int n;
   fin >> n;
   vector<long long> v(n);
   set<long long> sums;
   long long sum = 0;
   for(int i=0; i<n; i++) {
      fin >> v[i];
      sum += v[i];
      sums.insert(sums.end(), sum);
   }

   long long row = 0;
   for(int i=0; i<n; i++) {
      row += v[i];
      if( sum % row==0 ) {
         bool ok = 1;
         for(long long j=2; ok && j*row<sum; j++)
            if( sums.find(j*row)==sums.end() )
               ok = 0;
         if(ok)
            break;
      }
   }
   fout << row;

   return 0;
}
