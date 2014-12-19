#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "dmin2.in" 
#define OUTFILE "dmin2.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);
int n, m, cnt = 0, x, y;

int main() {
   fin >> n >> m;
   /*for(int i=0; cnt<n-2 && i<m; i++)
   {
      fin >> x >> y;
      if(x==1 || x==n || y==1 || y==n) cnt++;
   }*/
   
   cnt = 2;
   LL res = n-2-cnt;
   m -= cnt;
   res += (LL)(n-3) * (n-2) / 2 - m;
   fout << res;

   return 0;
}
