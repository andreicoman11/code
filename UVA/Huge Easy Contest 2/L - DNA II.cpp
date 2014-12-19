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

int getn(char c)
{
  switch(c){
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    default:
      return 3;
  }
}

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    string adn;
    cin >> adn;

    long long s = 0;
    long long p = 1;
    for(int i=(int)adn.sz-1; i>=0; i--,p*=4)
      s += p*getn(adn[i]);
	
    cout << "Case " << r << ": (" << adn.sz << ":" << s << ")\n";
	}
	
	return 0;
}