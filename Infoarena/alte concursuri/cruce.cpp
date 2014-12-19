#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "cruce.in" 
#define OUTFILE "cruce.out"
#define NMAX 128
ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m;
char c[NMAX][NMAX];

int main() {
   fin >> n >> m;

   for(int i=0; i<n; i++)
   for(int j=0; j<m; j++)
      fin >> c[i][j];

   int res = 0;
   for(int x=1; x<n-1; x++)
   for(int y=1; y<m-1; y++)
   {
      int h=0, v=0;
      for(int k=1; x-k>=0 && x+k<n; k++)
         if( c[x-k][y]==c[x+k][y] ) h++;
         else break;

      for(int k=1; y-k>=0 && y+k<m; k++)
         if( c[x][y-k]==c[x][y+k] ) v++;
         else break;
      res += h*v;
   }
   fout << res;

   return 0;
}
