#include <vector>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

#define LL long long
#define INFILE "prodiv.in" 
#define OUTFILE "prodiv.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

LL gcd(LL x, LL y) {
   return( y==0 ? x : gcd(y, x%y));
}

int main() {
   LL a=1LL, b=1LL, n;
   fin >> n;

   LL count = 1;
   int c2=0;
   while( n%2LL==0 ) {
      c2++;
      n /= 2LL;
      if( c2%2==0 ) a*=2LL, b*=2LL;
   }

   if( c2%2==1 ) {
      b *= 2LL;
      count *= 2;
   }
   //cout << n << " " << "\t"  << c2 << " " << a << " " << b << " " << count << endl;;

   for(LL i=3; n>1; i+=2)
      if( n%i==0 ) {
         //cout << n << " " << i << "\t";
         c2 = 0;
         while( n%i==0 ) {
            c2++;
            n /= i;
            if( c2%2==0 ) a*=i, b*=i;
         }
         
         if( c2%2==1 ) {
            b *= i;
            count*=2;
         }
         //cout << c2 << " " << a << " " << b << " " << count << endl;
      }

   fout << a << " " << b << "\n" << count;
   return 0;
}
