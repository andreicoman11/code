#include <vector>
#include <fstream>
#include <queue>
using namespace std;

#define INFILE "distante.in" 
#define OUTFILE "distante.out"
#define pb push_back
#define piii pair<int,pair<int,int> >
#define NMAX 50010
#define inf 50000000


int n, d[NMAX];
bool verif[NMAX];
vector<piii > e;
ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {

   int cases;
   fin >> cases;
   for(;cases; cases--) {
      int m, start;
      fin >> n >> m >> start;
      for(int i=0; i<n; i++)
         fin >> d[i], verif[i] = 0;

      verif[start-1] = 1;
      for(; m; m--) {
         int a, b, c;
         fin >> a >> b >> c;
         a--; b--;
         if( d[a] + c == d[b] ) verif[b] = 1;
         if( d[b] + c == d[a] ) verif[a] = 1;
      }

      bool ok = 1;
      for(int i=0; i<n; i++)
         ok = ok & verif[i];

      fout << (ok ? "DA" : "NU");
      if( cases>1 )  fout << "\n";
   }
   return 0;
}
