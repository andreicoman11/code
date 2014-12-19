#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

#define LL long long
#define INFILE "facebook.in" 
#define OUTFILE "facebook.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

map<int, int> m;

int main() {
   int n, k;
   fin >> n >> k;
   for(int i=0; i<n; i++)
   {
      int x;
      fin >> x;
      int cnt = m[x] + 1;
      if( cnt>=k ) {
         fout << i+1-k;
         return 0;
      }
      m[x] = cnt;
   }
   fout << "-1";

   return 0;
}
