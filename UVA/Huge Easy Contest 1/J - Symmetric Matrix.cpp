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
    int m[100][100];
    char c[100][100];
    int n;
    char caux;
    cin >> caux >> caux >> n;
    bool sym = 1;
    REP(i, n)
    REP(j, n)
    {
      long long aux;
      cin >> aux;
      m[i][j] = (int)(aux>>2);
      c[i][j] = aux & 3;
      if( aux<0 ) sym = 0;
    }

    REP(i, n)
    REP(j, n)
      if( m[i][j]!=m[n-i-1][n-j-1] || c[i][j]!=c[n-i-1][n-j-1] ) sym = 0;
	  
		cout << "Test #" << r << ": ";
    if( sym ) cout << "Symmetric.\n";
    else      cout << "Non-symmetric.\n";
	}
	
	return 0;
}