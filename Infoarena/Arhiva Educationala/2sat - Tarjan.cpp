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

int n, m, idx[NMAX], lowidx[NMAX], idxcnt = 0;
vector<vector<int> > e, C;
bool vis[NMAX], inst[NMAX], val[NMAX/2];
stack<int> st;


void scc(int nod)
{
   idx[nod] = lowidx[nod] = idxcnt++;
   vis[nod] = inst[nod] = 1;
   st.push(nod);

   for(int i=0; i<e[nod].size(); i++)
      if( !vis[e[nod][i]] )
      {
         scc(e[nod][i]);
         lowidx[nod] = min(lowidx[nod], lowidx[e[nod][i]]);
      } else if( inst[e[nod][i]] )
         lowidx[nod] = min(lowidx[nod], lowidx[e[nod][i]]);

   if( lowidx[nod]==idx[nod] )
   {
      int cnod;
      vector<int> comp;
      do {
         cnod = st.top();
         st.pop();
         comp.push_back(cnod);
         inst[cnod] = 0;

      } while( cnod!=nod );
      C.push_back(comp);
   }
}

bool doisat()
{
   memset(vis, 0, sizeof(vis));
   for(int i=C.size()-1; i>=0; i--)
   if( !vis[C[i][0]] )
   {
      int x;
      for(int j=0; j<C[i].size(); j++)
         if( vis[C[i][j]] ) return 0;
         else
         {
            x = C[i][j];
            val[norm(x)] = (x<n ? 0 : 1);
            vis[x] = vis[inv(x)] = 1;
         }
   }
   return 1;
}

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   scanf("%d %d", &n, &m);
   e.resize(2*n);
   for(int i=0; i<m; i++)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      if( a<0 ) a = n - a - 1; else a--;
      if( b<0 ) b = n - b - 1; else b--;
      e[inv(a)].push_back(b);
      e[inv(b)].push_back(a);
   }

   for(int i=0; i<2*n; i++)
      if( !vis[i] )
         scc(i);

   if( !doisat() )
      printf("-1\n");
   else 
      for(int i=0; i<n; i++)
         printf("%d ", val[i]);

   return 0;
}
