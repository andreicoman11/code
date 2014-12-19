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

ifstream fin ("B.in");
ofstream fout ("B.out");
#define NMAX 1024 

bool u[NMAX];
int n, lvls, s[NMAX][2];

int comp(const void* a, const void* b) {
   return ((int*)a)[1] - ((int*)b)[1];
}

void solve() {
   memset(u, 0, sizeof(u));
   fin >> n;
   lvls = n;
   for(int i=0; i<n; i++) {
      fin >> s[i][0] >> s[i][1];
   }

   qsort(s, n, 2*sizeof(int), comp);

   int p1=0, p2=0, x=0;
   while( p2<n ) {

      if( s[p2][1]<=x ) {
         if( u[p2] ) x++;
         else        x+=2;
         u[p2] = 1;
         p2++;

      } else {
         p1 = n-1;
         while( p1>=0 && (u[p1]==1 || s[p1][0]>x)) p1--;

         if( p1>=0 && u[p1]==0 && s[p1][0]<=x ) {
            lvls++;
            u[p1] = 1;
            x++;
         
         } else {
            fout << "Too Bad\n";
            return ;
         }
      }
   }
   fout << lvls << endl;
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      cout << N2-1 << endl;
      solve();
   }

	return 0;
}