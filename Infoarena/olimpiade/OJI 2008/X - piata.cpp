#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "piata.in" 
#define OUTFILE "piata.out"
#define NMAX 40010
LL n, s=0, it, jt, im, jm;

int f[NMAX];

int fsum(int x)
{
  int rez = 0;
  while(x)
  {
    rez += x%10;
    x /= 10;
  }
  return rez;
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n;
  for(int i=1; i<=n; i++)
    f[i] = fsum(i);
  cin >> it >> jt >> im >> jm;

  LL v2 = ( jm>=it ? (jm-it+1) : (jm+n-it+1));
  LL v1 = ( jt>=im ? (jt-im+1) : (jt+n-im+1));

  LL m = min(im-it+1, jm-jt+1);

  for(LL i=1; i<m; i++)
  {
    s += i*(f[v1]+f[v2]);
    v1 = (v1==n ? 1 : v1+1);
    v2 = (v2==1 ? n : v2-1);
  }

  while( v1!=v2 )
  {
    s += m * f[v1];
    v1 = ( v1==n ? 1 : v1+1);
  }
  s += m * f[v2];

  cout << s << "\n";

	return 0;
}
