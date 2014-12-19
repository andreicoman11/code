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

//ifstream fin (".in");
//ifstream fin ("A-small.in");
ifstream fin ("A-large.in");
ofstream fout (".out");

bool get_rings(long long r, long long x, long long t) {
   // 2LL * r * x + x + 2LL * (x-1LL) * x;
   t -= x;
   if( t<0LL ) return 0;
   t -= r * x;
   if( t<0LL ) return 0;
   t -= r * x;
   if( t<0LL ) return 0;
   t -= (x-1LL) * x;
   if( t<0LL ) return 0;
   t -= (x-1LL) * x;
   if( t<0LL ) return 0;
   return 1;
}

void solve() {
   long long r, t;
   fin >> r >> t;

   long long b = 1LL;
   while( get_rings(r, b, t) ) {
      b = b * 10LL;
   }
   long long a = 1LL;
   while( a+1<b ) {
      long long mid = (a+b) / 2LL;
      if( get_rings(r, mid, t) ) a = mid;
      else b = mid;
   }

   if( get_rings(r, b, t) ) fout << b << std::endl;
   else  fout << a << std::endl;
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}