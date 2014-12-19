#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "cautbin.in" 
#define OUTFILE "cautbin.out"
#define NMAX 100050

unsigned int n, m, v[NMAX];

int binary_search(unsigned int val)
{
  unsigned int i, step;
  for(step=1; step<n; step<<=1);
  for(i=0; step; step>>=1)
    if( i+step<n && v[i+step]<=val )
      i |= step;
  return i;
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  scanf("%d", &n);
  for(unsigned int i=0; i<n; i++)
    scanf("%d", &v[i]);

  unsigned int t, x, bs;
  scanf("%d", &m);
  for(unsigned int i=0; i<m; i++)
  {
    scanf("%d %d", &t, &x);
    switch(t) {
      case 0:
        bs = binary_search(x);
        printf("%d\n", (v[bs] == x ? (1+bs) : -1 ));
        break;
      case 1:
        printf("%d\n", 1+binary_search(x));
        break;
      default:
        bs = binary_search(x-1);
        if( v[bs]<x ) bs++;
        printf("%d\n", bs+1);
    }
  }


	
	return 0;
}
