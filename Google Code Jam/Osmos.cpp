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

void solve() {
   int n;
   long long a;
   fin >> a >> n;
   vector<long long> v(n);
   for(int i=0; i<n; i++)
      fin >> v[i];
   sort(v.begin(), v.end());
   reverse(v.begin(), v.end());

   while( v.size() && a>v[v.size()-1] ) {
      a += v[v.size()-1];
      v.resize(v.size()-1);
   }

   if( v.size()==0 ) fout << '0' << endl;
   else if( a==1 ) fout << v.size() << endl;
   else {
      long long a_init = a;
      int res = n;
      for(int rem = 0; rem<=v.size(); rem++) {
         a = a_init;
         int need = rem;
         for(int j=v.size()-1; j>=rem; j--) {
            while( a<=v[j] ) {
               need++;
               a += a-1;
            }
            a += v[j];
         }
         res = min(res, need);
      }
      fout << res << endl;
   }

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