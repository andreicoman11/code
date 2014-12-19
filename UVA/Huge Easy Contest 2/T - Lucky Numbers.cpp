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
    long long n;
    cin >> n;
    long long i = (int)sqrt((long double)n);
    if( i*i==n ) i--;

		cout << "Case " << r << ":";
    while( i>0 )
    {
      if( n%i==0 ) cout << " " << n-i*i;
      i--;
    }
    cout << endl;
	
	}
	
	return 0;
}