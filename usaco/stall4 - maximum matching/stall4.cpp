/*
ID: andreic4
PROG: stall4
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
#include <queue>
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
#define INFILE "stall4.in" 
#define OUTFILE "stall4.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m;
int sink, source;
/* d[i][j] = edge from i to j */
/* 0-source, 1-n cows, n+1-n+m stalls, n+m+1 stall */
bool d[402][402];
bool vis[402];
int prev[402];

void readstall()
{
  fin >> n >> m;
  source = 0;
  sink = n + m + 1;
  REP(i, n)
  {
    // edge from source to cow
    d[source][i+1] = 1;
    int nr;
    fin >> nr;
    REP(j, nr)
    {
      int x;
      fin >> x;
      d[i+1][x+n] = 1;
    }
  }
  FOR(i,n+1,n+m+1)
    d[i][sink] = 1;
}

int augment()
{
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(0);
  vis[0] = true;
  prev[0] = -1;
  bool issink = false;
  while( !q.empty() && !issink )
  {
    int node = q.front();
    q.pop();
    REP(i, sink+1)
      if( d[node][i] && !vis[i] )
      {
        q.push(i);
        vis[i] = 1;
        prev[i] = node;
        if( i==sink) issink = true;
      }
  }

  if( issink==false ) return 0;

  int node = sink;
  while( prev[node]!=-1 )
  {
    d[ prev[node] ][node] = 0;
    d[node][ prev[node] ] = 1;
    node = prev[node];
  }
  return 1;
}

int main()
{
  readstall();
  int totalflow = 0;
  int maxflow;
  while( (maxflow = augment()) )
  {
    totalflow += maxflow;
    //cout << maxflow << endl;
  }
  //cout << totalflow << endl;
  fout << totalflow << endl;
  
	return 0;
}
