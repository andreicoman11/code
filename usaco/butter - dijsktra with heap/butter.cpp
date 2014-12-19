/*
ID: andreic4
PROG: butter
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
#include <utility>
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
#define INFILE "butter.in" 
#define OUTFILE "butter.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define MAXN 810

const int INF = 500000;
int cow[MAXN], edges[MAXN][MAXN], ecost[MAXN][MAXN], n, cows, cowdmin;

bool comp(pair<int,int> a, pair<int,int> b)
{
  return a.second > b.second;
}

void trypasture(int p)
{
  int cowd = 0, cowsleft = cows;
  int distop[MAXN]; memset(distop, INF, sizeof(distop));
  vector<pair<int,int> > v;

  distop[p] = 0;
  v.pb( pair<int,int>(p, 0) );
  make_heap(v.begin(), v.end(), comp);
  while( cowsleft && v.sz && cowd<cowdmin )
  {
    pop_heap(v.begin(),v.end(), comp);
    int n = v[ v.sz-1 ].first;
    int dist = v[ v.sz-1 ].second;
    v.pop_back();
    if( distop[n]==-1 ) continue;
    
    cowsleft -= cow[n];
    cowd += cow[n]*dist;
    distop[n] = -1;
    
    for(int i=1; i<=edges[n][0]; i++)
      if( distop[ edges[n][i] ] > dist + ecost[n][ edges[n][i] ] )
      {
        // found better path to edges[n][i] through n
        distop[ edges[n][i] ] = dist + ecost[n][ edges[n][i] ];
        v.pb( pair<int,int>(edges[n][i], dist + ecost[n][ edges[n][i] ]));
        if( v.sz )
          push_heap( v.begin(), v.end(), comp);
        else
          make_heap( v.begin(), v.end(), comp);
      }
  }
  cowdmin = cowdmin > cowd ? cowd : cowdmin;
}

int main()
{
  memset(edges, 0, sizeof(edges));
  memset(ecost, 0, sizeof(ecost));
  int m;
  fin >> cows >> n >> m;
  memset(cow, 0, sizeof(cow));
  REP(i, cows)
  {
    int x;
    fin >> x;
    cow[x-1]++;
  }
  REP(i, m)
  {
    int x, y, cost;
    fin >> x >> y >> cost; x--; y--;
    ecost[x][y] = ecost[y][x] = cost;
    edges[x][ ++edges[x][0] ] = y;
    edges[y][ ++edges[y][0] ] = x;
  }

  cowdmin = INF;
  for(int i=0; i<n; i++)
    trypasture(i);

  fout << cowdmin << endl;

	return 0;
}
