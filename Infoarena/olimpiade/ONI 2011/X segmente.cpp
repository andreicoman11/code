#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define NMAX 1001
#define INF 0x3f3f3f3f
#define INFILE "segmente.in" 
#define OUTFILE "segmente.out"

struct seg{
   int x1, y1, x2, y2;
};

int n, no, nv;
int m[NMAX][NMAX];
seg so[NMAX], sv[NMAX], s;

int getdist(seg o, seg v)
{
   if( o.x1<=v.x1 && o.x2>=v.x1 && v.y1<=o.y1 && v.y2>=o.y1 )
      return 0;

   if( o.x1<=v.x1 && o.x2>=v.x1 )
      return min(abs(v.y1-o.y1), abs(v.y2-o.y1));

   if( o.x1<=v.x1 && o.x2>=v.x1 )
      return min(abs(o.x1-v.x1), abs(o.x2-v.x1));

   return max(min(abs(v.y1-o.y1), abs(v.y2-o.y1)),min(abs(o.x1-v.x1), abs(o.x2-v.x1)));
}

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   cin >> n;
   no = nv = 0;
   for(int i=0; i<n; i++)
   {
      cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;
      if( s.x1!=s.x2 )  so[no++] = s;
      else              sv[nv++] = s;
   }

   for(int i=0; i<no; i++)
   for(int j=0; j<nv; j++)
   {
      m[i][j] = getdist( so[i], sv[j]);
   }

   int mind = INF;
   if( no<nv )
   {
      for(int i1=0; i1<no; i1++)
      for(int i2=i1+1; i2<no; i2++)
      {
         int min1 = INF, min2 = INF;
         for(int j=0; j<nv; j++)
         {
            int d = max( m[i1][j], m[i2][j]);
            if( d<min1 ) min2 = min1, min1 = d;
            else if( d<min2 ) min2 = d;
         }
         mind = min(mind, min2);
      }
   }
   else
   {
      for(int i1=0; i1<nv; i1++)
      for(int i2=i1+1; i2<nv; i2++)
      {
         int min1 = INF, min2 = INF;
         for(int j=0; j<no; j++)
         {
            int d = max( m[j][i1], m[j][i2]);
            if( d<min1 ) min2 = min1, min1 = d;
            else if( d<min2 ) min2 = d;
         }
         mind = min(mind, min2);
      }
   }

   cout << mind << "\n";

	return 0;
}
