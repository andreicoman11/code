#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)

char b[101][101];
int d[101][101];
long long MOD = 1000007;

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n;
    memset(b, 0, sizeof(b));
    memset(d, 0, sizeof(d));
    cin >> n;
    cin.getline(b[0], 100);

    REP(i, n)
    REP(j, n)
      cin >> b[i][j];

    for(int i=0; i<n; i++)
      if( b[n-1][i]=='W' )
      {
        d[n-1][i] = 1;
        b[n-1][i] = '.';
      }

    for(int i=n-2; i>=0; i--)
    for(int j=0; j<n; j++)
      if( b[i][j]=='.' )
      {
        if( j-1>=0 )
        {
          if( b[i+1][j-1]=='.' )
            d[i][j] = ((long long)d[i][j] + (long long)d[i+1][j-1]) % MOD;
          else if( b[i+1][j-1]=='B' && j-2>=0 && i+2<n && b[i+2][j-2]=='.' )
            d[i][j] = ((long long)d[i][j] + (long long)d[i+2][j-2]) % MOD;
        }
        
        if( j+1<n )
        {
          if( b[i+1][j+1]=='.' )
            d[i][j] = ((long long)d[i][j] + (long long)d[i+1][j+1]) % MOD;
          else if( b[i+1][j+1]=='B' && j+2<n && i+2<n && b[i+2][j+2]=='.' )
            d[i][j] = ((long long)d[i][j] + (long long)d[i+2][j+2]) % MOD;
        }
      }
      else if( b[i][j]=='W' )
      {
        d[i][j] = 1;
        b[i][j] = '.';
      }

    long long s = 0;
    REP(i, n)
      s = (s+(long long)d[0][i]) % MOD;
	
		cout << "Case " << r << ": " << s << endl;
	}
	
	return 0;
}