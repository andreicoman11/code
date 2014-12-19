#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define INFILE "muzica.in" 
#define OUTFILE "muzica.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m;
LL a, b, f;
LL c, d, e;
LL ones = (1<<16) - 1;

LL v[65535];

int gethash(LL x)
{
   return (x*2654435761LL) & ones;
}

void addhash(LL aux)
{
   int haux = gethash(aux);
   while( haux<65535 && v[haux] ) haux++;
   if( haux==65535 ) haux = 0;
   while( haux<65535 && v[haux] ) haux++;
   v[haux] = aux;
}

bool find(LL f)
{
   int haux = gethash(f);
   while( haux<65535 && v[haux]!=f && v[haux] ) haux++;
   if( haux==65535 ) haux = 0;
   while( haux<65535 && v[haux]!=f && v[haux] ) haux++;
   if( v[haux]==f ) {
      v[haux] = 2000000000LL;
      return 1;
   }
   return 0;
}


int main() {
   fin >> n >> m;
   fin >> a >> b >> c >> d >> e;
   c = c%e;
   d = d%e;
   LL res = 0, aux;
   for(int i=0; i<n; i++)
   {
      fin >> aux;
      if( aux==a )         res++;
      else if( aux==b )    res++;
      else if( aux<e )     addhash(aux);
   }
   
   for(int i=2; i<m; i++)
   {
      f = (c*b + d*a) % e;
      a = b;
      b = f;
      if( find(f) )
         res++;
   }

   fout << res;

   return 0;
}
