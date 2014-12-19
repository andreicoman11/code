#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

#define LL long long
#define INFILE "classictask.in" 
#define OUTFILE "classictask.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

LL a, b, c, powa, powa2, suma;

void add()
{
   // a = a * powa
   powa2 = powa;
   suma = a;
   a = 0;
   while( powa2 )
   {
      if( powa2 & 1LL )
         a = (a + suma) % c;
      powa2 >>= 1LL;
      suma = (suma + suma) % c;
   }
}

void gopowa()
{
   // powa = powa*powa
   powa2 = powa;
   suma = powa;
   powa = 0;
   while( powa2 )
   {
      if( powa2 & 1LL )
         powa = (powa + suma) % c;
      powa2 >>= 1LL;
      suma = (suma + suma) % c;
   }
}

int main() {
   fin >> a >> b >> c;

   a %= c;

   powa = a;
   a = 1;

   while(b)
   {
      //cout << a << " " << powa << "\n";
      if( b & 1LL ) 
         add();
      b >>= 1LL;
      gopowa();
   }
      

   fout << a;

   return 0;
}
