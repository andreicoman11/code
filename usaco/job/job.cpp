/*
ID: andreic4
PROG: job
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "job.in" 
#define OUTFILE "job.out"
#define INF 2000000000

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m1, m2;
int maxtime;

int a[2][30];
int b[2][30];
VI c1, c2;

void readf()
{
  fin >> n >> m1 >> m2;
  c1.resize(n,0);
  c2.resize(n,0);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  REP(i, m1)
    fin >> a[1][i];
  REP(i, m2)
    fin >> b[1][i];
}

VI addjobs(int c[2][30], int m)
{
  VI costs(n,0);
  REP(i, n)
  {
    int mint = INF, minj = -1;
    REP(j, m)
      if( max(c[0][j], costs[i]) + c[1][j] < mint )
      {
        mint = max(c[0][j], costs[i]) + c[1][j];
        minj = j;
      }
    c[0][minj] = mint;
    costs[i] = mint;
    maxtime = max(maxtime, mint + c1[n-i-1]);
  }
  return costs;
}

int main()
{
  readf();
  c1 = addjobs(a, m1);
  fout << maxtime << " ";
  maxtime = 0;
  c2 = addjobs(b, m2);
  fout << maxtime << endl;

	return 0;
}
