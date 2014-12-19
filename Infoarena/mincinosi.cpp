#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

#define LL long long
#define INFILE "mincinosi.in" 
#define OUTFILE "mincinosi.out"

int n;
int m[1000001], nr[1000001];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  memset(m, 0, sizeof(m));

  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> nr[i];
    m[nr[i]]++;
  }

  int maxf = 0, ans;
  for(int i=0; i<=n; i++)
  {
    if( m[i] && i==n-m[i] )
    {
      if( maxf < m[i] )
      {
        maxf = m[i];
        ans = i;
      }
    }
  }

  cout << maxf << endl;
  for(int i=0; i<n; i++)
    if( nr[i]==ans ) cout << i+1 << "\n";

	return 0;
}
