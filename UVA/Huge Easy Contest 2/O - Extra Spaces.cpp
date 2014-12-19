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

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    cout << "Case " << r << ":\n";
    int n;
    cin >> n;
    char buf[512];
    cin.getline(buf, 512);
    REP(i, n)
    {
      cin.getline(buf, 512);
      bool sp = 0;
      for(int j=0; j<(int)strlen(buf); j++)
        if( buf[j]!=' ' )
        {
          cout << buf[j];
          sp = 0;
        }
        else
        {
          if( !sp ) cout << ' ';
          sp = 1;
        }
      cout << endl;
    }
	
		if( r<runs ) cout << endl;
	}
	
	return 0;
}