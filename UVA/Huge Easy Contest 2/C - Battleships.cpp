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
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE ".in"
//ifstream cin(INFILE);

int main()
{
  char f[128][128];
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n;
    cin >> n;
    memset(f, 0, sizeof(f));
    REP(i, n)
    REP(j, n)
      cin >> f[i][j];

    int s = 0;
    REP(i, n)
    REP(j, n)
      if( f[i][j]!='.' )
      {
        bool hasx = (f[i][j]=='x' ? 1 : 0);
        f[i][j] = '.';

        if( j<n-1 && f[i][j+1]!='.' )
        {
          int j2 = j+1;
          while( j2<n && f[i][j2]!='.' )
          {
            if( f[i][j2]=='x' ) hasx = 1;
            f[i][j2] = '.';
            j2++;
          }
        }
        if( i<n-1 && f[i+1][j]!='.' )
        {
          int i2 = i+1;
          while( i2<n && f[i2][j]!='.' )
          {
            if( f[i2][j]=='x' ) hasx = 1;
            f[i2][j] = '.';
            i2++;
          }
        }
        s += (int)hasx;
        /*REP(i, n)
        {
          REP(j, n)
            cout << f[i][j];
          cout << endl;
        }cout << endl;*/
      }
	
		cout << "Case " << r << ": " << s << endl;
	}
	
	return 0;
}