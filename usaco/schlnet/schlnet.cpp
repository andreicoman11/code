/*
ID: andreic4
PROG: schlnet
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
#define INFILE "schlnet.in" 
#define OUTFILE "schlnet.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

bool g[100][100];
int n;

bool hastop[100];
bool istop[100];
bool verif[100];
bool reach[100];

void fillfrom(int i)
{
  hastop[i] = 1;
  istop[i] = 0;
  verif[i] = 1;
  for(int j=0; j<n; j++)
    if( g[i][j] && !verif[j] )
      fillfrom(j);
}

int gettops()
{
  memset(hastop, 0, sizeof(hastop));
  memset(istop, 0, sizeof(istop));
  while(1)
  {
    int i=0;
    for(; i<n; i++)
      if( !hastop[i] )
        break;

    if( i==n ) break;

    memset(verif, 0, sizeof(verif));
    fillfrom(i);
    istop[i] = 1;
  }

  int tops = 0;
  REP(i, n)
    if( istop[i] ) 
      tops++;

  return tops;
}

void reverseG()
{
  REP(i, n)
    FOR(j, i+1, n)
  {
    bool b = g[i][j];
    g[i][j] = g[j][i];
    g[j][i] = b;
  }
}
void fillreach(int i)
{
  reach[i] = 1;
  REP(j, n)
    if( g[i][j] && !reach[j] )
      fillreach(j);
}


bool isfullycon()
{
  REP(i, n)
  {
    // check if we can reach all nodes from i
    memset(reach, 0, sizeof(reach));
    fillreach(i);

    REP(j, n)
      if( !reach[j] )
        return 0;

  }
  return 1;
}

int main()
{
  memset(g, 0, sizeof(g));
  fin >> n;
  REP(i, n)
  {
    int e;
    fin >> e;
    while( e )
    {
      g[i][e-1] = 1;
      fin >> e;
    }
  }

  int tops = gettops();
  fout << tops << endl;

  // reverse graph, in order to find the 'leafs' of the graph 
  reverseG();
  int bottoms = gettops();

  if( isfullycon() )
    fout << "0\n";
  else
    fout << max(tops, bottoms) << endl;

	return 0;
}
