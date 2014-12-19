/*
ID: andreic4
PROG: rectbarn
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
#define INFILE "rectbarn.in" 
#define OUTFILE "rectbarn.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define MAXN 3001

int n, m;
bool b[MAXN][MAXN];

int max(int a, int b)
{
  return a > b ? a : b;
}

void printm(int mat[][MAXN])
{
  REP(i, n)
  {
    REP(j, m)
      cout << mat[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

int main()
{
  memset(b, 0, sizeof(b));
  int p;
  fin >> n >> m >> p;
  REP(i, p)
  {
    int x, y;
    fin >> x >> y;
    b[x-1][y-1] = 1;
  }

  int maxarea = 0, t=0;
  int l[2][MAXN], r[2][MAXN], top[MAXN];
  memset(top, -1, sizeof(top));

  REP(i, n)
  {
    int lastb = -1;
    REP(j, m)
      if( b[i][j] ) 
      {
        lastb = j;
        l[t][j] = j+1;
      }
      else l[t][j] = j-lastb;

    lastb = m;
    for(int j=m-1; j>=0; j--)
      if( b[i][j] )
      {
        lastb = j;
        r[t][j] = m-j;
      }
      else r[t][j] = lastb-j;

    REP(j, m)
      if( !b[i][j] )
      {
        if( i )
        {
          l[t][j] = min(l[t][j], l[1-t][j]);
          r[t][j] = min(r[t][j], r[1-t][j]);
        }
        int area = (i-top[j]) * (l[t][j]+r[t][j]-1);
        maxarea = max(area, maxarea);
      }
      else top[j] = i;
    t = 1-t;
  }

  fout << maxarea << endl;

	return 0;
}
