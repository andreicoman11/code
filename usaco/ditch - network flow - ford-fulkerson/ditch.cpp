/*
ID: andreic4
PROG: ditch
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
#define INFILE "ditch.in" 
#define OUTFILE "ditch.out"
#define INF 2147483647

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int dist[200][200];
int n, m;

void readF()
{
  memset( dist, 0, sizeof(dist));
  fin >> m >> n;
  REP(i, m)
  {
    int a, b, c;
    fin >> a >> b >> c;
    a--;
    b--;
    dist[a][b] += c;
  }
}

void printd()
{
  REP(i, n)
  {
    REP(j, n)
      cout << dist[i][j] << " ";
    cout << endl;
  }
}

int flow()
{
  int maxflow = 0;
  int prev[200];
  bool vis[200];
  /* Find flows until pathcap==0 */ 
  while( true )
  {
    memset(vis, 0, sizeof(vis));
    queue<int> nodes;
    nodes.push(0);
    prev[0] = -1;
    vis[0] = true;
    int node;
    bool sink = false;
    /* Find path from source to sink */ 
    while( !nodes.empty() && !sink )
    {
      node = nodes.front();
      nodes.pop();
      REP(i, n)
        if( dist[node][i]>0 && vis[i]==false )
        {
          nodes.push(i);
          prev[i] = node;
          vis[i] = true;
          if( i==n-1 ) sink = true;
        }
    }
    /* If no path to sink, we are done*/
    if( !sink ) break;

    /* Find capacity limit on path found */
    int pathcap = INF;
    node = n-1;
    while( prev[node]!=-1 )
    {
      pathcap = min(dist[ prev[node] ][node], pathcap);
      node = prev[node];
    }

    /* Update capacities along flow */
    maxflow += pathcap;
    node = n-1;
    while( prev[node]!=-1 )
    {
      dist[ prev[node] ][node] -= pathcap;
      dist[node][ prev[node] ] += pathcap;
      node = prev[node];
    }
  }
  return maxflow;
}

int main()
{
  readF();
  int maxflow = flow();
  
  fout << maxflow << endl;
	return 0;
}
