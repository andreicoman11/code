#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define LL long long
#define INFILE "cifre3.in" 
#define OUTFILE "cifre3.out"

int main() {
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   int a, n, rez;
   cin >> a >> n;
   rez = (n>1 ? 1 : 0);
   for(int i2=0; i2<=3*n; i2++)
   for(int i3=0; i3<=2*n; i3++)
   for(int i5=0; i5<=n; i5++)
   for(int i7=0; i7<=n; i7++)
   {
      int m = i5 + i7 + i3/2 + i2/3;
      if( i3%2 ) m++;
      if( i2%3 ) m++;
      if( i2%3==1 && i3%2==1 ) m--;
      if(m<=n) {
         rez++;
      }
   }

   cout << rez << "\n";
   return 0;
}