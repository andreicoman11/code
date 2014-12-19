#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

#define INFILE "mxl.in" 
#define OUTFILE "mxl.out"

int n;
long long int m[42][42];
bool b[42][42];
vector<vector<string> > vs;

void verif(int x, int y)
{
   long long int res = 0;
   int len = vs[x][y].size();
   for(int i = 0 + (vs[x][y][0]=='='); i<len; i++)
   {
      int a = int(vs[x][y][i++]) - int('0');
      if( i>=len ) { res+= a; break;}
      if( isdigit(vs[x][y][i]) ) a = a*10 + int(vs[x][y][i++]) - int('0');
      
      if( i>=len || vs[x][y][i]=='+' ) res += a;
      else
      {
         int q = vs[x][y][++i] - int('0');
         if( i+1<len && isdigit(vs[x][y][++i]) ) q = q*10 + int(vs[x][y][i++]) - int('0');
         a--; q--;
         if( b[a][q]==1 )
            verif(a, q);
         res += m[a][q];
      }
   }
   m[x][y] = res;
   b[x][y] = 0;
}

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);
   memset(m, 0, sizeof(m));
   memset(b, 0, sizeof(b));
   int k;
   cin >> n >> k;
   char buf[280];
   vs.resize(n);
   for(int i=0; i<n; i++)
      vs[i].resize(n);

   for(int i=0; i<k; i++)
   {
      int x, y, c = 0;
      cin >> x >> y;
      cin.getline(buf, 280, '\n');
      while( buf[c]==' ' ) c++;

      b[x-1][y-1] = 1;
      vs[x-1][y-1] = buf;
      if(c) vs[x-1][y-1] = vs[x-1][y-1].substr(c);
   }

   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
      {
         if( b[i][j]==1 )
            verif(i, j);
         cout << m[i][j] << " ";
      }
      cout << "\n";
   }

   return 0;
}
