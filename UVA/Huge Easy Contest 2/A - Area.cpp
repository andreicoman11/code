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

unsigned long long map[101][101];

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n, m;
    unsigned long long k;
    cin >> n >> m >> k;
    n++;
    m++;
    memset(map, 0, sizeof(map));
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
      cin >> map[i][j];
      map[i][j] += map[i][j-1];
    }

    FOR(j, 1, m)
    FOR(i, 1, n)
    {
      map[i][j] += map[i-1][j];
    }

    int maxsize = 0;
    unsigned long long mincost = k;
    bool found = 0;

    FOR(i, 1, n)
    FOR(j, 1, m)
    FOR(x, i, n)
    FOR(y, j, m)
      if( ((x-i+1)*(y-j+1)>maxsize && map[x][y]-map[x][j-1]-map[i-1][y]+map[i-1][j-1] <= k) || 
          ( (x-i+1)*(y-j+1)==maxsize && map[x][y]-map[x][j-1]-map[i-1][y]+map[i-1][j-1] < mincost ) )
      {
        maxsize = (x-i+1)*(y-j+1);
        mincost = map[x][y]-map[x][j-1]-map[i-1][y]+map[i-1][j-1];
        found = 1;
      }
	
    if( !found )
      cout << "Case #" << r << ": 0 0\n";
    else
      cout << "Case #" << r << ": " << maxsize << " " << mincost << endl;
	}
	
	return 0;
}