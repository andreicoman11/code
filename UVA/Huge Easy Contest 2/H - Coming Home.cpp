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

int gett()
{
  string c;
  cin >> c;
  int h = c[0]*10 + c[1];
  int m = c[3]*10 + c[4];
  return h*60 + m;
}

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int k;
    cin >> k;
    int now = gett();
    
    int mint = gett();
    if( mint<now ) mint += 24*60;
    int q;
    cin >> q;
    mint += q;

    for(int i=2; i<=k; i++)
    {
      int t = gett();
      if( t<now ) t += 24*60;
      cin >> q;
      t += q;
      mint = min(t, mint);
    }
	
		cout << "Case " << r << ": " << mint - now << endl;
	}
	
	return 0;
}