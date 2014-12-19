#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define LL long long
#define INFILE "euclid3.in" 
#define OUTFILE "euclid3.out"

LL gcd_e(LL a, LL b, LL& x, LL& y)
{
  if( b==0 )
  {
    x = 1;
    y = 0;
    return a;
  }

  LL x0, y0;
  LL d = gcd_e(b, a%b, x0, y0);
  x = y0;
  y = x0 - (a/b) * y0;
  return d;
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  int t;
  for(scanf("%d", &t); t; t--)
  {
    LL a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    LL x, y;
    LL d = gcd_e(a, b, x, y);

    if( c%d ) cout << "0 0\n";
    else cout << (c/d) * x << " " << (c/d) * y << "\n";
  }
	
	return 0;
}
