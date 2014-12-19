#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

ifstream fin (".in");
//ifstream fin ("C-small.in");
//ifstream fin ("C-large-1.in");
//ifstream fin ("C-large-2.in");
ofstream fout (".out");

set<long long> sgood;
map<long long, long long> good;

bool is_pal(long long x) {
   ostringstream os;
   os << x;
   string s = os.str();
   for(int i=0; i<s.size()/2; i++)
      if( s[i]!=s[s.size()-1-i] )
         return 0;
   return 1;
}

void find() {
   int cnt = 1;
   good[0] = 0;
   sgood.insert(0);
   for(int i=1; i<4; i++)
      if( is_pal(i*i) ) {
         good[i*i] = cnt++;
         sgood.insert(i*i);
      }
   for(int i=1; i<10000; i++) {
      long long c = i;
      long long b = i;
      while(c) {
         b = b*10 + c%10;
         c /= 10;
      }
      b = b*b;
      if( is_pal(b) ) {
         good[b] = cnt++;
         sgood.insert(b);
      }
   }
   for(map<long long, long long>::iterator it=good.begin(); it!=good.end(); it++)
      cout << it->second << " " << it->first << endl;
}

void solve() {
   long long a, b;
   fin >> a >> b;
   long long posa = *(sgood.lower_bound(a));
   long long posb = *(sgood.lower_bound(b));
   long long res = good[posb] - good[posa];
   if( posa!=a && posb==b ) res++;
   //if( posa==a && posb!=b ) res--;
   if( posa==a && posb==b ) res++;
   fout << res << endl;
}

int main() {
   find();
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}