#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "citylog.in" 
#define OUTFILE "citylog.out"
#define NMAX 100001

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int t[NMAX][6];
int n, m;
int cur = 0, op, a, b, x, y;
int v[6] = {1, 10, 100, 1000, 10000, 100000};

int get_cifre(int p) {
   if( p==0 ) return 1;
   int res = 0;
   while(p) {
      res++;
      p/=10;
   }
   return res;
}

int main() {
   fin >> n >> m;
   
   while(m--) {
      fin >> op >> a >> b;
      x = a ^ cur;
      y = b ^ cur;
      if( op==0 ) {
         t[x][0] = y;
         int pos = 0;
         bool go = 1;

         while(go) {
            int nod = x;
            for(int i=0; nod && i<10; i++) {
               nod = t[nod][pos];
            }
            t[x][++pos] = nod;
            if( !nod ) go = 0;
            if( pos>5 ) go = 0;
         }
      }
      else {
         while( x!=0 && y) {
            int pos = get_cifre(y) - 1;
            if( pos>5 ) pos = 5;
            x = t[x][pos];
            y -= v[pos];
         }
         fout << x << '\n';
         cur = x;
      }
   }

   return 0;
}
