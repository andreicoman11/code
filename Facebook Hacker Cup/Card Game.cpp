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

ifstream fin ("card_game.txt");
ofstream fout (".out");

#define MOD 1000000007
#define NMAX 10005

int comb[NMAX][NMAX];

void compute_comb() {
   comb[1][0] = comb[1][1] = 1;
   for(int i=2; i<=10000; i++) {
      comb[i][0] = comb[i][i] = 1;
      for(int j=1; j<i; j++)
         comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
   }
}

void solve() {
   int n, k;
   fin >> n >> k;
   vector<long long> a(n);

   for(int i=0; i<n; i++)
      fin >> a[i];
   sort(a.begin(), a.end());
   
   long long sum = 0;
   for(int i=k-1; i<n; i++)
      sum = (sum + (a[i] * comb[i][k-1])%MOD ) % MOD;
   fout << sum << '\n';
}

int main() {
   compute_comb();
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}