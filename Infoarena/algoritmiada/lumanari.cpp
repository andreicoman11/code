#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#define INFILE "lumanari.in" 
#define OUTFILE "lumanari.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

long long sum = 0LL;

bool verif(int x, vector<int> v) {
   long long midsum = (long long)x * (x+1) / 2LL;
   if( midsum>sum ) return 0;
   long long rest = 0;
   for(int i=v.size()-1; i>=0; i--) {
      if( v[i]>=x ) {
         rest -= (v[i]-x);
         rest = max(0LL, rest);
      } else {
         rest += x - v[i];
      }
      if(x) x--;
   }
   return rest<=0LL;
}

int main() {
   int m;
   fin >> m;
   vector<int> v(m);
   for(int i=0; i<m; i++) {
      fin >> v[i];
      if( v[i]>m ) v[i] = m;
      sum += v[i];
      if( v[i]==0 ) {
         i--;
         m--;
         v.resize(m);
      }
   }
   sort(v.begin(), v.end());
   
   if( v.size()==0 ) {
      fout << "0\n";
      return 0;
   }

   int a = 1, b = m;
   while( a+1<b ) {
      int mid = (a+b) / 2;
      if( verif(mid, v) ) a = mid;
      else b = mid;
   }

   int res = a;
   if( verif(b, v) ) res = b;
   fout << res << '\n';

   return 0;
}
