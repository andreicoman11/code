#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define LL long long
#define INFILE "ubercool.in" 
#define OUTFILE "ubercool.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

LL powa(LL a, int b)
{
   LL apow = a;
   a = 1;
   while(b)
   {
      if( b & 1 ) a *= apow;
      b >>= 1;
      apow *= apow;
   }
   return a;
}

bool isprim(LL a)
{
   if( a%2==0 )
   {
      if( a==2 ) return 1;
      return 0;
   }

   for(LL i=3; i*i<=a; i++)
      if( a%i==0 ) return 0;
   return 1;
}

int main() {
   int t;
   fin >> t;
   while(t--)
   {
      LL x;
      fin >> x;
      if( x<2 ) {
         fout << "NU\n";
         continue;
      }

      bool found = 0;
      for(int b = 2; ! found && b<=60; b++)
      {
         LL a = pow(x, 1.0 / (long double)b);

         if( powa(a, b)==x && isprim(a) )
            found = 1;
         a++;
         if( powa(a, b)==x && isprim(a)  )
            found = 1;
      }

      if( found ) fout << "DA\n";
      else fout << "NU\n";
   }

   return 0;
}
