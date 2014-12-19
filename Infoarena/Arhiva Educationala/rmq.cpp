#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "rmq.in" 
#define OUTFILE "rmq.out"
#define NMAX 100010
#define LOGMAX 20

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m, rmq[NMAX][LOGMAX], lg[NMAX];

int main() {
   fin >> n >> m;

   for(int i=0; i<n; i++)
      fin >> rmq[i][0];

   for(int i=2; i<=n; i++)
      lg[i] = lg[i>>1] + 1;

   for(int j=1; (1<<j)<=n; j++) 
   for(int i=0; i+(1<<j)<=n; i++)
         rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);

   int a, b, k;
   for(int i=0; i<m; i++)
   {
      fin >> a >> b;
      a--;
      b--;
      k = lg[b-a+1];
      fout << min(rmq[a][k], rmq[b-(1<<k)+1][k]) << '\n';
   }
   return 0;
}
