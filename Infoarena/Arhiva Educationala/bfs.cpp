#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INFILE "bfs.in" 
#define OUTFILE "bfs.out"
#define NMAX 100000

vector<vector<int> > g(NMAX);
int lvl[NMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  s--;
  memset(lvl, 0, sizeof(lvl));

  for(int i=0; i<m; i++)
  {
    int o, in;
    scanf("%d %d", &o, &in);
    g[o-1].push_back(in-1);
  }

  queue<int> q;
  q.push(s);
  lvl[s] = 1;
  while( !q.empty() )
  {
    int nod = q.front();
    q.pop();
    for(int i=0; i<g[nod].size(); i++)
      if( lvl[g[nod][i]]==0 )
      {
        lvl[g[nod][i]] = lvl[nod]+1;
        q.push(g[nod][i]);
      }
  }

  printf("%d", lvl[0]-1);
  for(int i=1; i<n; i++)
    printf(" %d", lvl[i]-1);

	return 0;
}
