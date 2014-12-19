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
//ifstream fin ("B-small.in");
ifstream fin ("B-large.in");
ofstream fout (".out");

vector<long long> v;
long long e, e_all, r;
int n;

void solve() {
   v.clear();
   fin >> e >> r >> n;
   if( r>e ) r = e;
   e_all = e;
   v.resize(n);
   for(int i=0; i<n; i++)
      fin >> v[i];

   vector<int> next(n, -1);
   stack<int> s;
   for(int i=n-1; i>=0; i--) {
      if( s.empty() ) s.push(i);
      else if( v[s.top()] > v[i] ) {
         next[i] = s.top();
         s.push(i);
      } else {
         while( !s.empty() && v[s.top()]<=v[i] ) 
            s.pop();
         if( !s.empty() )
            next[i] = s.top();
         s.push(i);
      }
   }

   //for(int i=0; i<n; i++)
   //   cout << next[i] << " ";cout << endl;

   long long res = 0;
   for(int i=0; i<n; i++)
      if( next[i]==-1 || r*(long long)(next[i]-i)>=e_all ) {
         res += e * v[i];
         e = r;
      } else {
         long long e_left = e_all - r*(long long)(next[i]-i);
         if( e >= e_left ) {
            e_left = e - e_left;
            res += e_left * v[i];
            e = e - e_left + r;
         } else e += r;
      }
   fout << res << std::endl;
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