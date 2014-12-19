#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "cal.in" 
#define OUTFILE "cal.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {

   int sx, sy, n, nr = 0;
   LL s;
   fin >> sx >> sy >> s >> n;
   
   for(int i=0; i<n; i++) {
      LL fx, fy;
      fin >> fx >> fy;
      LL dif = abs(fx-sx) + abs(fy-sy);
      if( dif==s ) nr++;
   }

   fout << nr << "\n";

   return 0;
}
