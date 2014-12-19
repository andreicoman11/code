#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
using namespace std;

#define INFILE "ciclueuler.in" 
#define OUTFILE "ciclueuler.out"
#define NMAX 100005

vector<int> edges[NMAX];
int degree[NMAX], n, m;
bool vis[NMAX];
stack<int> ciclu, stiva;

void readg() 
{
  cin >> n >> m;
  for(int i=0, a, b; i<m; i++) 
  {
    scanf("%d %d", &a, &b);
    a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
    degree[a]++;
    degree[b]++;
  }
}

void dfs(int v)
{
  vis[v] = 1;
  for(int i=0; i<edges[v].size(); i++)
    if( !vis[edges[v][i]] )
    {
      dfs(edges[v][i]);
    }
}

bool hasEuler() 
{
  dfs(0);
  for(int i=0; i<n; i++)
    if( !vis[i] || degree[i]&1 )
      return false;
  return true;
}

void del_edge(int a, int b)
{
  for(vector<int>::iterator it=edges[a].begin(); it!=edges[a].end(); it++)
    if( (*it)==b ) {
       edges[a].erase(it);
      break;
    }
  
  for(vector<int>::iterator it=edges[b].begin(); it!=edges[b].end(); it++)
    if( (*it)==a ) {
       edges[b].erase(it);
      break;
    }
    
  degree[a]--;
  degree[b]--;
}

void euler(int v)
{
  while( degree[v]!=0 )
  {
    int vn = edges[v][0];
    del_edge(v, vn);
    stiva.push(v);
    v = vn;
  }
}

int main()
{
  freopen(INFILE, "r", stdin);
  ofstream fout(OUTFILE);
  memset(vis, 0, sizeof(vis));

  readg();
  if( hasEuler() )
  {
    memset(vis, 0, sizeof(vis));
    int v = 0;
    do{
      euler(v);
      v = stiva.top();
      stiva.pop();
      ciclu.push(v);
    } while( !stiva.empty() );

    while( !ciclu.empty() )
    {
      fout << ciclu.top()+1 << " ";
      ciclu.pop();
    }
  }
  else
  {
    fout << "-1\n";
  }

	return 0;
}
