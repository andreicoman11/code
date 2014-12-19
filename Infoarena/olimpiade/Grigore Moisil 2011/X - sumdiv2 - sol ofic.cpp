#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
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

  cin >> n;
  int m = BMAX, M = 0;
  for(int i=0; i<n; i++)
  {
    cin >> allint[i][0] >> allint[i][1];
    m = min(m, allint[i][0]);
    M = max(M, allint[i][1]);
  }

  memset(v, 0, sizeof(v));
  v[1] = 1;
  s[1] = 0;
  for(int i=2; i<=M; i++)
  {
    for(int j=i*2; j<=M; j+=i)
      v[j] += i;
    v[i] += 1 + i;
    s[i] = s[i-1] + v[i];
  }
  
  for(int i=0; i<n; i++)
    cout << s[allint[i][1]] - s[allint[i][0]-1] << "\n";

	return 0;
}
