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
#include <iomanip>
using namespace std;

//ifstream fin (".in");
//ifstream fin ("B-small.in");
ifstream fin ("B-large.in");
ofstream fout (".out");

vector<int> pyr;
double one = 1.0, zero = 0.0;
vector<vector<double> > comb;

void solve() {
   int n, x, y;
   fin >> n >> x >> y;
   x = abs(x);
   y = abs(y);
   int lat = 0;
   while( n >= pyr[lat] ) {
      n -= pyr[lat];
      lat++;
   }
   lat++;

   if( x+y<2*(lat-1) )     fout << one << endl;
   else if( x+y>2*(lat-1) ) fout << zero << endl;
   else if( x==0 || n==0 )         fout << zero << endl;
   else {
      // x+y == 2*(lat-1)
      lat = 2*(lat-1);

      if( n>lat ) {
         int s = n - lat;
         n -= 2*s;
         lat -= s;
         x -= s;
         if( x<=0 ) {
            fout << one << endl;
            return ;
         }
      }

      x = lat - x + 1;
      if( x>n ) {
         fout << zero << endl;
         return;
      }
      double res = 1.0;
      for(int i=0; i<x; i++)
         res -= comb[n][i];
      fout << res << endl;
   }
}

int main() {
   comb.resize(1500);
   comb[0].push_back(1.0);
   comb[1].push_back(0.5);
   comb[1].push_back(0.5);

   for(int i=2; i<=1416; i++)
   {
      comb[i].push_back(comb[i-1][0] * 0.5);
      for(int j=1; j<i; j++)
         comb[i].push_back((comb[i-1][j-1] + comb[i-1][j]) * 0.5);
      comb[i].push_back(comb[i-1][i-1] * 0.5);
   }

   pyr.push_back(1);
   int x = 1;
   for(int i=2; x<=1000000; i++) {
      pyr.push_back(4 * i - 3 );
      x += 4 * i - 3;
   }

   int N, N2 = 1;
	fin >> N;
   fout << fixed << setprecision(6);
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}