#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "dreptunghiuri.in" 
#define OUTFILE "dreptunghiuri.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int gcd(const int a, const int b)
{
   if( a<b ) return gcd(b, a);
   return (b==0 ? a : gcd(b, a%b));
}

int main() {
   long long n, m;
   fin >> n >> m;
   if( m==1 || n==1 ) {
      fout << '0';
      return 0;
   }

   if( n>m ) swap(n, m);
   
   m--; n--;
   long long res = m * (m+1) * n * (n+1) / 4;

   int xa, xb, y;
   for(int b=1; b<m; b++)
   for(int a=1; a<n; a++)
   {
      int d = gcd(a,b);
      int _xa = b/d;
      int _xb = a/d;
      int _y = _xb+b;
      xa = _xa;
      xb = _xb;
      y = _y;
      while( a+xa<=n && xb<=m && y<=m )
      {
         if( a+xa<=n && xb<=m && y<=m )
            res += (n-xa-a+1) * (m-y+1);
         
         xa += _xa;
         xb += _xb;
         y = b + xb;
      }
   }

   fout << res;

   return 0;
}
