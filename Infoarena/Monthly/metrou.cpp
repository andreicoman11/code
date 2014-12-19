#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "metrou.in" 
#define OUTFILE "metrou.out"
#define NMAX 2048

ifstream fin(INFILE);
ofstream fout(OUTFILE);

LL n, x[NMAX], a[NMAX][2], d[NMAX][2];

int main() {
   fin >> n;
   for(int i=0; i<n; i++)
      fin >> x[i];
   x[n] = 300000;

   for(int i=0; i<n; i++)
      fin >> a[i][0];

   for(int i=0; i<n; i++)
      fin >> a[i][1];

   //fout << 0 << " " << d[0][0] << " " << d[0][1] << "\n";
   for(int i=0; i<n; i++)
   for(int j=0; j<2; j++)
   {
      LL cost2 = 0, costct = 0;
      LL ppl = 0;
      int p = i;
      LL ax = 0;
      d[i][j] = -1;

      for(int k = i-1; k>=0; k--)
      {
         while( p>k+1 && (x[i+1]-x[p])<=(x[p]-x[k]) && (i+1<n) )
         {
            costct += a[p][1-j] * (x[i+1] - x[p]);
            ppl -= a[p][1-j];
            ax -= a[p][1-j] * x[p];
            p--;
         }

         if( (x[i+1]-x[k+1])<=(x[k+1]-x[k]) && (i+1<n) )
         {
            // k+1 == p
            costct += a[k+1][1-j] * (x[i+1] - x[k+1]);
            p--;
            cost2 = 0;
         }
         else
         {
            ax += a[k+1][1-j] * x[k+1];
            ppl += a[k+1][1-j];
            cost2 = ax - x[k] * ppl;
         }

         //fout << "cost new: " << i << " " << k << "\t" << p << " " << ax << " " << ppl << "\t" << costct << " " << cost2 << "\n";
         if( d[i][j]==-1 || (d[i][j] > d[k][1-j] + cost2 + costct) )
	         d[i][j] = d[k][1-j] + cost2 + costct;

      }
      // only i+1 is open
      if( i+1<n ) {
	      LL dij = costct + ppl * x[i+1] - ax + (x[i+1]-x[0]) * a[0][1-j];
         if( d[i][j]==-1 || d[i][j]>dij )
	         d[i][j] = dij;
      }
   }

   fout << min( d[n-1][0], d[n-1][1]);

   return 0;
}
