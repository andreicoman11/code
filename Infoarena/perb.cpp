#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define INFILE "perb.in" 
#define OUTFILE "perb.out"
#define MAX 602

int c[MAX][MAX], n, v[MAX/2][4];
char s[MAX];

int main()
{
   int m;
   ifstream fin(INFILE);
   ofstream fout(OUTFILE);
   fin >> n >> m >> s;

   for(int i=0; i<n; i++)
      if( s[i]=='A' ) s[i] = 0;
      else if( s[i]=='C' ) s[i] = 1;
      else if( s[i]=='G' ) s[i] = 2;
      else if( s[i]=='T' ) s[i] = 3;

   memset(c, 0x3f, sizeof(c));

   for(int i=0; i<n-1; i++)
   for(int p=1; i+2*p<=n && p<=n/2; p++)
   {
      for(int j=i, k=0; j<i+p; j++, k++)
      {
         v[k][0] = v[k][1] = v[k][2] = v[k][3] = 0;
         v[k][s[j]]++;
      }

      for(int j=i+p, ps=2; j+p<=n; j+=p, ps++)
      {
         int changes = 0;
         for(int k=0; k<p; k++)
         {
            v[k][s[j+k]]++;
            changes += ps - max(max(v[k][0], v[k][1]), max(v[k][2], v[k][3]));
         }
 
         c[i][j+p-1] = min(c[i][j+p-1], changes);
      }
   }

   for(int i=0; i<m; i++)
   {
      int x, y;
      fin >> x >> y;
      if( x>y ) swap(x, y);
      if( x==y ) fout << "0\n";
      else fout << c[x-1][y-1] << "\n";
   }

   fin.close();
   fout.close();
	
   return 0;
}
