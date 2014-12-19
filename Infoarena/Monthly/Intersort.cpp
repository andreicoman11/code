#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "intersort.in" 
#define OUTFILE "intersort.out"
#define NMAX 100010

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, perm[NMAX];
bool set[NMAX];

int main() {
   fin >> n;
   for(int i=0; i<n; i++) {
      fin >> perm[i];
      perm[i]--;
   }

   int s = 0;
   for(int i=0; i<n; i++)
      if( i!=perm[i] && set[i]==0 )
      {
         set[i] = 1;
         s+=2;
         int j = perm[i];
         while( j!=i )
         {
            set[j] = 1;
            j = perm[j];
            s++;
         }
      }

   if( perm[1]!=1 && perm[perm[1]]==1 && perm[1]!=0 ) s--;

   fout << s - 2*(perm[0]!=0);

   return 0;
}
