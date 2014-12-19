#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "ciur.in" 
#define OUTFILE "ciur.out"
#define NMAX 2000010

bool v[NMAX];

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);
   int n, primes = 1;
   cin >> n;

   memset(v, 0, sizeof(v));
   for(int i=3; i<=n; i+=2)
      if( !v[i] )
      {
         v[i] = 1;
         primes++;
         if( i<=n/i )
         for(int j = i*i; j<=n; j+=i)
            v[j] = 1;
      }
   cout << primes;

   return 0;
}
