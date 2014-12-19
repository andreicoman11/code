/*
ID: andreic4
PROG: game1
LANG: C++
*/
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
#include <queue>
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
#define INFILE "game1.in" 
#define OUTFILE "game1.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define MAXN 100

int d[MAXN][MAXN], a[MAXN], s[MAXN][MAXN], n;

#define max(x,y) ((x>y)?x:y)

int main()
{
  fin >> n;
  REP(i, n)
  {
    fin >> a[i];
    d[i][0] = a[i];
    s[i][0] = a[i];
  }

  for(int j=1; j<n; j++)
  for(int i=0; i+j<n; i++)
    s[i][j] = s[i][j-1] + s[i+j][0];

  for(int j=1; j<n; j++)
  for(int i=0; i+j<n; i++)  
    d[i][j] = max(a[i] + s[i+1][j-1] - d[i+1][j-1],
                  a[i+j] + s[i][j-1] - d[i][j-1]);

  /*for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      cout << s[i][j] << " " ;
    cout << endl;
  }cout << endl;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      cout << d[i][j] << " " ;
    cout << endl;
  }*/

  fout << d[0][n-1] << " " << s[0][n-1] - d[0][n-1] << endl;

	return 0;
}
