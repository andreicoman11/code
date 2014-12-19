#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

#define INFILE "2sat.in" 
#define OUTFILE "2sat.out"
#define NMAX 200002
#define inv(x) (x<n ? (x+n) : (x-n))
#define norm(x) (x<n ? x : (x-n))

vector<vector<int> > e, er;
int n, m, val[NMAX/2];
bool vis[NMAX], inst[NMAX], imp = 0;
stack<int> st;

void dfs1(int nod)
{
   vis[nod] = inst[nod] = 1;
   for(int i=0; i<e[nod].size(); i++)
      if( !vis[e[nod][i]] )
         dfs1(e[nod][i]);
   st.push(nod);
}

void dfs2(int nod)
{
   inst[nod] = 0;
   if( vis[nod] ) imp = 1;
   val[norm(nod)] = (nod<n ? 0 : 1);
   for(int i=0; i<er[nod].size(); i++)
      if( inst[er[nod][i]] ) dfs2(er[nod][i]);
   vis[nod] = vis[inv(nod)] = 1;
}

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   scanf("%d %d", &n, &m);
   e.resize(2*n);
   er.resize(2*n);
   for(int i=0; i<m; i++)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      if( a<0 ) a = n - a - 1; else a--;
      if( b<0 ) b = n - b - 1; else b--;
      e[inv(a)].push_back(b);
      e[inv(b)].push_back(a);
      er[a].push_back(inv(b));
      er[b].push_back(inv(a));
   }

   for(int i=0; i<2*n; i++)
      if( !vis[i] )
         dfs1(i);

   memset(vis, 0, sizeof(vis));
   while( !st.empty() )
   {
      int nod = st.top();
      st.pop();
      if( !vis[nod] )
         dfs2(nod);
   }

   if(imp) cout << "-1\n";
   else 
      for(int i=0; i<n; i++)
         cout << val[i] << " ";


   return 0;
}
