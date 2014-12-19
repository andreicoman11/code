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

long long d[1024];

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
	  int n,m,k;
    cin >> n >> m >> k;
    long long lavg = 0;
    REP(i, n)
    {
      cin >> d[i];
      lavg += d[i];
    }
    
    long double avg = (long double)lavg / (long double)n;
    long long c = d[0], dr = d[m];
    long double difc = abs((long double)c - avg);
    long double difdr = abs((long double)dr - avg);

    FOR(i, 1, m)
      if( abs((long double)d[i] - avg)<difc || (abs((long double)d[i] - avg)==difc && d[i]<c))
      {
        difc = abs((long double)d[i] - avg);
        c = d[i];
      }

    FOR(i, m+1, m+k)
      if( abs((long double)d[i] - avg)<difdr || (abs((long double)d[i] - avg)==difdr && d[i]<dr))
      {
        difdr = abs((long double)d[i] - avg);
        dr = d[i];
      }

		cout << "Case #" << r << ": " << c << " " << dr << endl;
	}
	
	return 0;
}