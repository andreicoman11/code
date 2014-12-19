#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "iostream"
using namespace std;

#define LL long long
#define INFILE "impartiri.in" 
#define OUTFILE "impartiri.out"
#define NMAX 3010
#define MOD 2113

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m, k;
int dpn[NMAX], dpm[NMAX], dp[NMAX];

int main() 
{
   fin >> n >> m >> k;
   int nm = max(n, m);
   
   dpn[0] = dpm[0] = 0;
   for(int v=1; v<=nm; v++)
   {
      dp[0] = 1;
      dp[1] = 1;
      for(int i=2; i<=nm; i++) {
         dp[i] = (dp[i-1]*2 - (i>=v+1 ? dp[i-v-1] : 0) + MOD) % MOD;
         //cout << dp[i] << " ";
      }
      //cout << endl;
      dpn[v] = dp[n];
      dpm[v] = dp[m];
   }

   int res = 0;
   for(int v=1; v<=min(k,n); v++)
   {
      int res2 = (dpn[v] - dpn[v-1] + MOD) % MOD;
      res = (res + res2 * dpm[ min(k/v, m) ]) % MOD;
      //cout << dpn[v] - dpn[v-1] << " " << min(k/v, m) << " " << (dpn[v] - dpn[v-1]) * dpm[ min(k/v, m) ] << "\n";
   }
   fout << res << endl;

   return 0;
}
