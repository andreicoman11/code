#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define LL long long
#define INFILE "sumdiv2.in" 
#define OUTFILE "sumdiv2.out"
#define INTMAX 100010
#define BMAX 1000010

int n, allint[INTMAX][2], primes[1000], pno = 1;
LL v[BMAX], s[BMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  primes[0] = 2;
  for(int i=2; i<=1000; i++)
  {
    bool ok = 1;
    for(int j=0; j<pno && primes[j]*primes[j]<=i && ok; j++)
      if( i%primes[j]==0 ) ok = 0;
    if(ok)
      primes[pno++] = i;
  }

  cin >> n;
  int m = BMAX, M = 0;
  for(int i=0; i<n; i++)
  {
    cin >> allint[i][0] >> allint[i][1];
    m = min(m, allint[i][0]);
    M = max(M, allint[i][1]);
  }

  s[1] = 0;
  v[1] = 1;
  for(int i=2; i<=M; i++)
  {
    v[i] = 1 + i;
    for(int j=0; j<pno; j++)
      if( i%primes[j]==0 )
      {
        int pjpow = primes[j];
        int x = i / primes[j];
        while( x%primes[j]==0 )
        {
          pjpow *= primes[j];
          x /= primes[j];
        }
        v[i] = (primes[j]*pjpow - 1) / (primes[j] - 1) * v[x];
        break;
      }
    s[i] = v[i] + s[i-1];
  }
  
  for(int i=0; i<n; i++)
    cout << s[allint[i][1]] - s[allint[i][0]-1] << "\n";

	return 0;
}
