#include <vector>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

#define INFILE "maxflow.in" 
#define OUTFILE "maxflow.out"
#define NMAX 1001
#define INF 0x3f3f3f3f

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n;
vector<int> e[NMAX];
int cap[NMAX][NMAX], pre[NMAX];
bool vis[NMAX];

int bfs() {
   // bfs from start to destination
   memset(vis, 0, sizeof(vis));
   vis[1] = 1;
   pre[1] = -1;
   queue<int> q;
   q.push(1);
   while( !q.empty() ) {
      int nod = q.front();
      q.pop();

      // pass all neighbours, add them to queue if not destination
      for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++) 
         // neighbour not visited and there is still capacity on edge
         if( !vis[*it] && cap[nod][*it] ) {
            vis[*it] = 1;
            pre[*it] = nod;
            if( *it!=n ) q.push(*it);
         }
   }
   // return if it is still possible to reach the destination
   return vis[n];
}

int main() {
   int m, a, b, c;
   fin >> n >> m;
   while(m--) {
      fin >> a >> b >> c;
      e[a].push_back(b);
      e[b].push_back(a);
      cap[a][b] = c;
   }

   int maxflow = 0;
   while( bfs() ) {
      // traverse all nodes that can lead to destination
      for(vector<int>::iterator it=e[n].begin(); it!=e[n].end(); it++)
         if( vis[*it] && cap[*it][n] ) {
            int flow = INF;
            pre[n] = *it;
            for(int nod = n; flow && nod!=1; nod = pre[nod])
               flow = min(flow, cap[pre[nod]][nod]);

            if(!flow) continue;
            maxflow += flow;
            for(int nod = n; nod!=1; nod = pre[nod]) {
               cap[pre[nod]][nod] -= flow;
               cap[nod][pre[nod]] += flow;
            }
         }
   }
   fout << maxflow;
   return 0;
}
