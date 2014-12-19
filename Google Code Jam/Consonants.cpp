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
#include <stack>
#include <queue>
using namespace std;

//ifstream fin (".in");
//ifstream fin ("A-small.in");
ifstream fin ("A-large.in");
ofstream fout (".out");

bool vow[256];

void solve() {
   string s;
   fin >> s;
   int n;
   fin >> n;
   long long sz = s.size();
   long long nr = sz * (sz+1LL) / 2LL;

   //cout << nr << endl;
   for(int i=0; i<(int)s.size(); i++) {
      long long less = min(n-1, (int)s.size() - i);
      nr -= less;
   }
   //cout << nr << endl;

   int first = 0;
   int ct = 0;
   for(int i=0; i<(int)s.size(); i++) {
      if( vow[s[i]] ) {
         ct = 0;
      } else {
         ct++;
         if(ct==n) {
            while(i<(int)s.size() && !vow[s[i]] )
               i++;

            if( i<(int)s.size() ) {
               first = i - (n-1);
               ct = 0;
            } else
               break;
         }
      }
      if( i-first+1>=n ) {
         //cout << first << " " << i << " " << i-n-first+2 << endl;
         nr -= i-n-first+2;
      }
   }
   //cout << nr << endl << endl;
   fout << nr << endl;
}

int main() {
   vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = 1;
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}