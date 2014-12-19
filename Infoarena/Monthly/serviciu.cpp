#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "serviciu.in" 
#define OUTFILE "serviciu.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {
   int n;
   fin >> n;
   int distmax = 1;
   for(int i=0; i<n; i++) {
      int h, o;
      fin >> h >> o;
      if( h<o ) swap(h, o);
      distmax = max(distmax, min( (h-o), (o-h+2*n) ) );
   }

   fout << distmax;

   return 0;
}
