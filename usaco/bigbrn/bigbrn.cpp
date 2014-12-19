/*
ID: andreic4
PROG: bigbrn
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
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "bigbrn.in" 
#define OUTFILE "bigbrn.out"
#define MAX 1024
ifstream fin (INFILE);
ofstream fout (OUTFILE);

bool a[MAX][MAX];
int d[MAX][MAX];
int n, trees;

int main()
{
  memset(a, 0, sizeof(a));
  fin >> n >> trees;
  int tx, ty;
  REP(i,trees)
  {
    fin >> tx >> ty;
    a[tx-1][ty-1] = 1;
  }

  int smax = 0;
  memset(d, 0, sizeof(d));
  FOR(i, 0, n)
  {
    d[i][0] = 1;
    d[0][i] = 1;
  }

  FOR(i,1,n)
  FOR(j,1,n)
  {
    if( a[i][j]==0 && a[i][j-1]==0 && a[i-1][j]==0 && a[i-1][j-1]==0 )
    {
      d[i][j] = 1 + min(d[i-1][j-1], min(d[i][j-1], d[i-1][j]));
    }
    else d[i][j] = 1;
    if( d[i][j]>smax ) smax = d[i][j];
  }

  fout << smax << endl;


	return 0;
}
