#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "interzis.in" 
#define OUTFILE "interzis.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int NMAX = 15005;
const int LMAX = 1005;
const int MOD = 101267;
int n, l, t[LMAX];
string L;
vector<int> dp[2];

int main() {
   fin >> n >> l;
   fin >> L;

   int k = 0;
   for(int i=1; i<l; i++) {
      while( k && L[i]!=L[k] ) k = t[k-1];

      if( L[i]==L[k] ) k++;

      t[i] = k;
   }
   
   int row = 0;
   dp[0].resize(l+1);
   dp[1].resize(l+1);
   dp[row][0] = 1;
   for(int i=0; i<n; i++) {
      row = 1 - row;
      dp[row].clear();
      dp[row].resize(l+1);
      for(int j=0; j<min(i+1,l); j++) {
         dp[row][j+1] = (dp[1-row][j] + dp[row][j+1]) % MOD;
         char c = 'b' - L[j] + 'a';
         int k = j;
         while( k && L[k]!=c ) k = t[k-1];
         if( L[k]==c ) k++;

         dp[row][k] = (dp[1-row][j] + dp[row][k]) % MOD;
      }
   }

   int res = 0;
   for(int j=0; j<l; j++)
      res = (res + dp[row][j]) % MOD;
   fout << res;


   return 0;
}
