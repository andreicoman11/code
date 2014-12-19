#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

#define INFILE "lca.in" 
#define OUTFILE "lca.out"
#define NMAX 100010
#define LOGMAX 20

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m, t[NMAX], l[NMAX*LOGMAX], rmq[NMAX*LOGMAX][LOGMAX], cnt, f[NMAX], lg[NMAX*LOGMAX];
vector<vector<int> > e;

void DFS() {
   stack<int> s;
   s.push(1);
   while( !s.empty() ) {
      int nod = s.top();
      rmq[cnt][0] = nod;
      f[nod] = cnt++;
      if( t[nod] < e[nod].size() ) {
         s.push(e[nod][ t[nod] ]);
         t[nod]++;
         rmq[cnt++][0] = nod;
      } else
         s.pop();
   }
}

int main() {
   fin >> n >> m;
   e.resize(n+1);
   for(int i=2; i<=n; i++) {
      fin >> t[i];
      e[t[i]].push_back(i);
      l[i] = l[t[i]] + 1;
      t[i] = 0;
   }
   cnt = 0;
   DFS();

   for(int j=1; (1<<j)<=cnt; j++)
   for(int i=0; i+(1<<j)<=cnt; i++)
      if( l[ rmq[i][j-1] ] < l[ rmq[i+(1<<(j-1)) ][j-1] ] )
         rmq[i][j] = rmq[i][j-1];
      else 
         rmq[i][j] = rmq[i+(1<<(j-1))][j-1];

   for(int i=2; i<=cnt; i++)
      lg[i] = lg[i>>1] + 1;

   int x, y, k;
   for(int i=0; i<m; i++)
   {
      fin >> x >> y;
      x = f[x];
      y = f[y];
      if( y<x ) swap(x,y);
      k = lg[ y - x + 1 ];
      if( l[ rmq[x][k] ] < l[ rmq[y-(1<<k)+1][k] ] )
         fout << rmq[x][k] << '\n';
      else 
         fout << rmq[y-(1<<k)+1][k] << '\n';
   }

   return 0;
}
