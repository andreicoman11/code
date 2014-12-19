/*
ID: andreic4
PROG: concom
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
#define INFILE "concom.in" 
#define OUTFILE "concom.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define MAXN 100

const int MAXC = 101;
bool isc[MAXN];
int c[MAXN][MAXN][2], n;

void checkc(int comp)
{
  int ctrl[MAXN]; memset(ctrl, 0, sizeof(ctrl));
  bool vis[MAXN]; memset(vis, 0, sizeof(vis));
  int ccur = comp;
  while( ccur >= 0 )
  {
    vis[ccur] = 1;
    for(int i=1; i<=c[ccur][0][0]; i++)
      ctrl[ c[ccur][i][0] ] = (ctrl[ c[ccur][i][0] ] + c[ccur][i][1]) % MAXC;

    ccur = -1;
    for(int i=0; i<100; i++)
      if( ctrl[i]>50 && !vis[i] )
      {
        ccur = i;
        break;
      }
  }

  for(int i=0; i<100; i++)
    if( ctrl[i]>50 && i!=comp )
      fout << comp+1 << " " << i+1 << endl;
}

int main()
{
  memset(isc, 0, sizeof(isc));
  memset(c, 0, sizeof(c));
  fin >> n;
  REP(i, n)
  {
    int c1, c2, ca;
    fin >> c1 >> c2 >> ca; c1--; c2--;
    c[c1][ ++c[c1][0][0] ][0] = c2;
    c[c1][ c[c1][0][0] ][1] = ca;
    isc[c1] = 1;
  }

  REP(i, 100)
    if( isc[i] ) 
      checkc(i);

	return 0;
}
