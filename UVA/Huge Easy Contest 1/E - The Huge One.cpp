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
  string w = " - Wonderful.\n";
  string sw = " - Simple.\n";
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    bool isw = 1;
    char buf[1024];
    scanf("%s", buf);

    int nr[1001];
    int n = strlen(buf);
    for(int i=0; i<n; i++)
    {
      nr[i] = int(buf[i]) - int('0');
    }

    int s;
    cin >> s;
    while( s-- )
    {
      int div;
      cin >> div;
      int r = 0;
      for(int i=0; i<n; i++)
        r = (nr[i] + r*10)%div;
      if( r ) isw = 0;
    }
	
    printf("%s", buf);
		if( isw ) cout << w;
    else    cout << sw;
	}
	
	return 0;
}