/*
ID: andreic4
PROG: milk6
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
typedef vector<VVI> VVVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "milk6.in" 
#define OUTFILE "milk6.out"
#define MAX 1000
#define MAXE 2000001

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, edge[32][32] = {0}; // cost of edges
int ind[32][32] = {0};  // index of edges in given edge set
int orig[32][32] = {0}; // original path costs
int to_check[MAX][3] = {0}, checkno = 0;
VI trez(MAX);
int trezsz = MAX;
int put[MAX] = {0};
VVVI edges(32, VVI(32));

int augment()
{
  int v[32] = {0};
  int t[32] = {0};
  bool found = 0;
  queue<int> q;
  q.push(0);
  v[0] = 1;
  t[0] = -1;
  while( !q.empty() && !found )
  {
    int nod = q.front();
    q.pop();
    REP(i, n)
      if( v[i]==0 && edge[nod][i]>0 )
      {
        t[i] = nod;
        v[i] = 1;
        q.push(i);
        if( i==n-1 )
        {
          found = 1;
          break;
        }
      }
  }

  if( !found ) return 0;
  int minc = MAXE;
  int nod = n-1;
  while( t[nod]!=-1 )
  {
    minc = min(minc, edge[ t[nod] ][nod]);
    nod = t[nod];
  }

  nod = n-1;
  while( t[nod]!=-1 )
  {
    edge[nod][ t[nod] ] += minc;
    edge[ t[nod] ][nod] -= minc;
    if( edge[ t[nod] ][nod]==0 )
    { // might be in min cut
      to_check[checkno][0] = ind[ t[nod] ][nod];
      to_check[checkno][1] = t[nod];
      to_check[checkno][2] = nod;
      checkno++;
    }
    nod = t[nod];
  }
  return minc;
}

int getflow()
{
  int maxflow = 0;
  int minc = MAXE;
  while( minc!=0 )
  {
    minc = MAXE;
    int v[32] = {0};
    int t[32] = {0};
    bool found = 0;
    queue<int> q;
    q.push(0);
    v[0] = 1;
    t[0] = -1;
    while( !q.empty() && !found )
    {
      int nod = q.front();
      q.pop();
      REP(i, n)
        if( v[i]==0 && edge[nod][i]>0 )
        {
          t[i] = nod;
          v[i] = 1;
          q.push(i);
          if( i==n-1 )
          {
            found = 1;
            break;
          }
        }
    }

    if( !found ) break;

    int nod = n-1;
    while( t[nod]!=-1 )
    {
      minc = min(minc, edge[ t[nod] ][nod]);
      nod = t[nod];
    }

    nod = n-1;
    while( t[nod]!=-1 )
    {
      edge[nod][ t[nod] ] += minc;
      edge[ t[nod] ][nod] -= minc;
      nod = t[nod];
    }
    maxflow += minc;
  }
  return maxflow;
}

void mincut(int i, int flowrem, VI rez)
{
  if( flowrem==0 )
  {
    if( i<trezsz || (i==trezsz && rez<trez) )
    {
      trez = rez;
      trezsz = i;
    }
  }
  else
  {
    REP(j, checkno)
      if( put[ to_check[j][0] ]==0 )
      {
        memcpy(edge, orig, sizeof(edge));
        edge[ to_check[j][1] ][ to_check[j][2] ] = 0;
        if( flowrem - orig[ to_check[j][1] ][ to_check[j][2] ] == getflow() )
        {
          int aux = orig[ to_check[j][1] ][ to_check[j][2] ];
          put[ to_check[j][0] ] = 1;
          orig[ to_check[j][1] ][ to_check[j][2] ] = 0;
          rez[i] = to_check[j][0];

          mincut(i+1, flowrem - aux, rez);

          put[ to_check[j][0] ] = 0;
          orig[ to_check[j][1] ][ to_check[j][2] ] = aux;
        }
      }
  }
}

int main()
{
  int m, a, b;
  fin >> n >> m;
  REP(i, m)
  {
    fin >> a >> b;
    fin >> edge[a-1][b-1];
    if( edge[a-1][b-1] )
    {
      ind[a-1][b-1] = i+1;
      edges[a-1][b-1].pb(i+1);
    }
  }
  memcpy(orig, edge, sizeof(orig));

  int maxf = 0, minf;
  while( (minf = augment())>0 )
  {
    maxf += minf;
    //cout << minf << endl;
  }

  /*cout << maxf << endl;
  REP(i, checkno)
    cout << to_check[i][0] << " " << to_check[i][1] << " " << to_check[i][2] << "\n";*/

  VI rez(MAX);
  mincut(0, maxf, rez);

  fout << maxf << " " << trezsz << endl;
  REP(i, trezsz)
    fout << trez[i] << endl;;

	return 0;
}
