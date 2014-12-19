#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "curatenie.in" 
#define OUTFILE "curatenie.out"
#define NMAX 500010
ifstream fin(INFILE);
ofstream fout(OUTFILE);

int arb[NMAX][2], pos[NMAX], n, v[NMAX];

int go(int a, int b, int x, int y)
{
   if( a>=n || a>b || x>=n || x>y ) return 0;

   arb[ v[x] ][0] = go( a, pos[v[x]]-1, x+1, x+pos[v[x]]-a);
   arb[ v[x] ][1] = go( pos[v[x]]+1, b, x+pos[v[x]]-a+1, y);

   return v[x];
}

int main() {
   fin >> n;
   for(int i=0; i<n; i++)
   {
      int x;
      fin >> x;
      pos[x] = i;
   }

   for(int i=0; i<n; i++)
      fin >> v[i];

   go(0, n-1, 0, n-1);

   for(int i=1; i<=n; i++)
   {
      fout << arb[i][0] << " " << arb[i][1] << "\n";
   }

   return 0;
}
