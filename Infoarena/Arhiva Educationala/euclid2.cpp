#include <cstdio>
using namespace std;

#define INFILE "euclid2.in" 
#define OUTFILE "euclid2.out"


long long int gcd(long long int a, long long int b)
{
  return (b==0 ? a : gcd(b, a%b));
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  long long int a, b;
  int t;
  scanf("%d", &t);
  while( t-- )
  {
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", gcd(a, b));
  }

	
	return 0;
}
