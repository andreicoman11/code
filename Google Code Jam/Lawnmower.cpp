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
//ifstream fin ("B-small.in");
ifstream fin ("B-large.in");
ofstream fout (".out");

void solve() {
   int lawn[105][105], n, m;
   fin >> n >> m;
   for(int i=0; i<n; i++)
   for(int j=0; j<m; j++)
      fin >> lawn[i][j];

   int row[105], col[105];
   for(int i=0; i<n; i++) {
      int lmax = 0;
      for(int j=0; j<m; j++)
         lmax = max(lmax, lawn[i][j]);
      row[i] = lmax;
   }

   for(int j=0; j<m; j++) {
      int lmax = 0;
      for(int i=0; i<n; i++)
         lmax = max(lmax, lawn[i][j]);
      col[j] = lmax;
   }

   bool ok = 1;
   for(int i=0; i<n; i++)
   for(int j=0; j<m; j++)
      if( lawn[i][j]!= min(row[i], col[j])) ok = 0;

   if( ok ) fout << "YES" << endl;
   else     fout << "NO" << endl;
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