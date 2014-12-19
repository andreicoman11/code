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

unsigned long long lu, ld, mu, md, ru, rd;

void go(string t)
{
  if( t.sz==0 )
    return;
  if( t[0]=='L' )
  {
    ru = mu;
    rd = md;
  }
  else
  {
    lu = mu;
    ld = md;
  }
  mu = lu + ru;
  md = ld + rd;
  go( t.substr(1) );
}

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    string m;
    cin >> m;

    lu = 0;
    ld = 1;
    mu = md = 1;
    ru = 1;
    rd = 0;
    go(m);
	
    cout << mu << "/" << md << endl;
	}
	
	return 0;
}