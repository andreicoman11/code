#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "lgput.in" 
#define OUTFILE "lgput.out"
#define MOD 1999999973

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  unsigned long long int n, p, np = 1;
  scanf("%lld %lld", &n, &p);

  for(unsigned long long int i=1; i<=p; i<<=1, n = (n*n)%MOD)
	  if( i&p )
      np = (np * n) % MOD;

  cout << np << "\n";
	return 0;
}
