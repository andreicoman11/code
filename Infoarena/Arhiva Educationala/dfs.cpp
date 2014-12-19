#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INFILE "dfs.in" 
#define OUTFILE "dfs.out"
#define NMAX 100000

vector<vector<int> > g(NMAX);
int lvl[NMAX];

void dfs(int nod)
{
  for(int j=0; j<g[nod].size(); j++)
    if( lvl[g[nod][j]]==0 )
    {
      lvl[g[nod][j]] = lvl[nod];
      dfs( g[nod][j] );
    }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  memset(lvl, 0, sizeof(lvl));
  int n, m;
  scanf("%d %d", &n, &m);
  memset(lvl, 0, sizeof(lvl));

  for(int i=0; i<m; i++)
  {
    int o, in;
    scanf("%d %d", &o, &in);
    g[o-1].push_back(in-1);
    g[in-1].push_back(o-1);
  }

  int cul = 1;
  for(int i=0; i<n; i++)
    if( lvl[i]==0 ) 
    {
      lvl[i] = cul++;
      dfs(i);
    }

  printf("%d\n", cul-1);
  

	return 0;
}
