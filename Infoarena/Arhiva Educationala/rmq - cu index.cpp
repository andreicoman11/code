#include <vector>
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

int n, m, v[NMAX], rmq[NMAX][LOGMAX], lg[NMAX];

int main() {
   fin >> n >> m;
   for(int i=0; i<n; i++) {
      fin >> v[i];
      rmq[i][0] = i;
   }

   for(int j=1; (1<<j)<=n; j++)
   for(int i=0; i+(1<<j)<=n; i++)
      if( v[ rmq[i][j-1] ] < v[ rmq[i+(1<<(j-1))][j-1] ] )
         rmq[i][j] = rmq[i][j-1];
      else
         rmq[i][j] = rmq[i+(1<<(j-1))][j-1];         

   for(int i=2; i<=n; i++)
      lg[i] = lg[i>>1] + 1;

   for(int i=0; i<m; i++) {
      int x, y;
      fin >> x >> y;
      x--; y--;
      int k = lg[y-x+1];

      fout << min(v[rmq[x][k]], v[rmq[y-(1<<k)+1][k]]) << '\n';
   }
   
   return 0;
}
