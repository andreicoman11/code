/*
ID: andreic4
PROG: tour
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
#define INFILE "tour.in" 
#define OUTFILE "tour.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

map<string, int> cities;
bool g[100][100];
int a[100][100];
int n;

void printa()
{
  REP(i, n)
  {
    REP(j, n)
      fout << a[i][j] << " " ;
    fout << endl;
  }system("pause");
}

int main()
{
  int edges;
  fin >> n >> edges;
  string city1, city2;
  REP(i, n)
  {
    fin >> city1;
    cities[city1] = i;
  }
  memset(g, 0, sizeof(g));
  REP(i, edges)
  {
    fin >> city1 >> city2;
    int c1, c2;
    c1 = cities[city1];
    c2 = cities[city2];
    g[c1][c2] = g[c2][c1] = 1;
  }

  memset(a, 0, sizeof(a));
  a[0][0] = 1;
  FOR(i, 0, n)
    if( g[0][i] )
    {
      a[0][i] = a[i][0] = 2;
    }

  FOR(i, 0, n)
  FOR(j, i+1, n)
    if( g[0][i] && g[0][j] )
    {
      a[i][j] = a[j][i] = 3;
    }

  FOR(i, 0, n)
  FOR(j, i+1, n)
    if( a[i][j] )
    {
      int k = max(i, j);
      /*if( k==n-1 )
      {
        if( i!=k && g[i][k] )   a[k][k] = a[i][k];
        if( j!=k && g[j][k] )   a[k][k] = a[j][k];
      }*/
      for(k=k+1;k<n-1;k++)
      {
        if( g[j][k] )
          a[i][k] = a[k][i] = max( a[i][k], a[i][j]+1);
        if( g[i][k] )
          a[k][j] = a[j][k] = max( a[k][j], a[i][j]+1);
      }
      if( g[i][n-1] && g[j][n-1] )
        a[n-1][n-1] = max(a[n-1][n-1], a[i][j]+1);
      //cout << "Upgrade " << i << " " << j << " from " << a[i][j] << endl;
      //printa();
    }

  //printa();
  a[n-1][n-1] = max(1, a[n-1][n-1]);
  fout << a[n-1][n-1] << endl;  

	return 0;
}
