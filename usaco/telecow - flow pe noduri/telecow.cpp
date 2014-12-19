/*
ID: andreic4
PROG: telecow
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
#include <queue>
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
#define INFILE "telecow.in" 
#define OUTFILE "telecow.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);

bool g[200][200];
bool done[100];
int n, s, e, m;

int getflow()
{
  int tflow = 0;
  while(1)
  {
    bool v[100] = {0};
    int t[100] = {0};
    v[s] = 1;
    t[s] = -1;
    queue<int> q;
    q.push(s);
    bool isend = 0;
    while( !q.empty() && !isend )
    {
      int nod = q.front();
      q.pop();
      for(int i=0; i<n; i++)
        if( v[i]==0 && !done[i] && g[2*nod+1][2*i] && g[2*i][2*i+1] )
        {
          v[i] = 1;
          t[i] = nod;
          q.push(i);
          if( i==e ) isend = 1;
        }
      if( isend ) break;
    }

    if( isend==0 ) break;

    tflow++;
    int nod = e;
    while( t[nod]!=-1 )
    {
      g[2*nod][2*nod+1] = 0;
      g[ 2*t[nod]+1 ][2*nod] = 0;
      nod = t[nod];
    }
    g[2*e][2*e+1] = 1;
  }
  return tflow;
}

int main()
{
  memset(g, 0, sizeof(g));
  fin >> n >> m >> s >> e;
  s--;
  e--;
  for(int i=0; i<n; i++)
    g[2*i][2*i+1] = 1;

  for(int i=0; i<m; i++)
  {
    int a, b;
    fin >> a >> b;
    g[(a-1)*2+1][(b-1)*2] = g[(b-1)*2+1][(a-1)*2] = 1;
  }

  bool gaux[200][200];
  memset(done, 0, sizeof(done));
  memcpy(gaux, g, sizeof(gaux));

  int flow = getflow();
  fout << flow << endl;

  bool vis[100] = {0};
  for(int i=0; i<n; i++)
    if( i!=e && i!=s && g[2*i][2*i+1]==0 )
      vis[i] = 1;

  memcpy(g, gaux, sizeof(g));

  for(int i=0; i<n && flow>0; i++)
    if( vis[i] )
    {
      memcpy(g, gaux, sizeof(g));
      done[i] = 1;
      int newflow = getflow();
      //cout << i << " " << newflow << endl;
      if( newflow+1==flow )
      {
        flow--;
        fout << i+1;
        if( flow>0 ) fout << " ";
      }
      else
        done[i] = 0;
    }
  fout << endl;

	return 0;
}
