/*
ID: andreic4
PROG: race3
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
#include <queue>
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
#define INFILE "race3.in" 
#define OUTFILE "race3.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n;
int edge[51][101];
//int mat[51][51];
int v[51];

bool BFS(int nnod)
{
  memset(v, 0, sizeof(v));
  v[nnod] = 1;
  v[0] = 1;
  queue<int> q;
  q.push(0);
  while( !q.empty() )
  {
    int nod = q.front();
    q.pop();
    for(int i=0; edge[nod][i]>=0; i++)
      if( v[edge[nod][i]]==0 )
      {
        if( edge[nod][i]==n )
          return false;
        v[edge[nod][i]] = 1;
        q.push(edge[nod][i]);
      }
  }
  return true;
}

bool BFS2(int nnod)
{
  // check all nodes that can be reached from start,
  // without nnod
  BFS(nnod);

  // now see if using edges from nnod,
  // we can get to already checked nodes
  v[nnod] = 2;
  queue<int> q;
  q.push(nnod);
  while( !q.empty() )
  {
    int nod = q.front();
    q.pop();
    for(int i=0; edge[nod][i]>=0; i++)
      if( v[edge[nod][i]]==1 )
        return false;
      else if( v[edge[nod][i]]==0 )
      {
        v[edge[nod][i]] = 2;
        q.push(edge[nod][i]);
      }
  }
  return true;

}

void printedges();

int main()
{
  int e = 0;
  fin >> e;
  //memset(mat, 0, sizeof(mat));
  memset(edge, 0, sizeof(edge));
  while( e!=-1 )
  {
    int m;
    for(m=0; e!=-2; m++)
    {
      edge[n][m] = e;
      //mat[n][e] = mat[e][n] = 1;
      fin >> e;
    }
    
    if( e==-2 )
    {
      edge[n][m] = -1;
      n++;
      fin >> e;
    }
  }
  n--;

  //printedges();

  VI ans;
  FOR(i, 1, n)
    if( BFS(i) ) ans.pb(i);

  fout << ans.sz;
  REP(i, ans.sz)
    fout << " " << ans[i];
  fout << endl;

  // create undirected graph in edges, from mat
  /*REP(i, n)
  {
    int m = 0;
    REP(j, n+1)
      if( mat[i][j] )
        edge[i][m++] = j;
    edge[i][m] = -2;
  }*/

  //printedges();

  VI ans2;
  REP(i, (int)ans.sz)
    if( BFS2(ans[i]) )
      ans2.pb(ans[i]);

  fout << ans2.sz;
  REP(i, (int)ans2.sz)
    fout << " " << ans2[i];
  fout << endl;

	return 0;
}

void printedges()
{
  cout << n << endl;
  REP(i, n)
    if( i<4 || i>47 )
  {
    cout << i << ": ";
    for(int j=0; edge[i][j]>=0; j++)
      cout << edge[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}