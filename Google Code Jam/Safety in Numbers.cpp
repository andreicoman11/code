#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <list>
using namespace std;

//ifstream fin ("A-small.in");
//ofstream fout ("A-small.out");
ifstream fin ("A-large.in");
ofstream fout ("A-large.out");

void solve() {
   int n, S=0;
   fin >> n;
   vector<int> s(n);
   vector<double> v(n);
   bool set[256];
   memset(set, 0, sizeof(set));

   for(int i=0; i<n; i++){
      fin >> s[i];
      S += s[i];
   }

   int sh = n, go = 1, S2 = 2*S;
   while(go) {
      go = 0;
      double val = double (S2) / double(sh);
      for(int i=0; i<n; i++)
         if( set[i]==0 && double(s[i]) > val ) {
            sh--;
            go = 1;
            v[i] = 0.0;
            set[i] = 1;
            S2 -= s[i];
         }
   }

   for(int i=0; i<n; i++) {
      if( set[i]==0 ) {
         v[i] = (S2 / double(sh) - double(s[i])) / double(S) * 100.0;
      }
      fout << fixed << setprecision(6) << v[i] << " ";
   }
   fout << "\n";
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