#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

#define INFILE "ubuntzei.in" 
#define OUTFILE "ubuntzei.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int NMAX = 2005;
const int INF = 0x3f3f3f3f;

vector<pair<int,int> > e[NMAX];
vector<int> k;
vector<int> dmin[NMAX];
int n, cmin[1<<15][15];
bool vis[NMAX];

void dijkstra(int s) {
   dmin[s].resize(n);
   for(int i=0; i<n; i++)
      dmin[s][i] = INF;

   priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
   memset(vis, 0, sizeof(vis));
   q.push(make_pair(0, s));

   int left = n;
   while(left) {
      int nod = q.top().second;
      int cost = q.top().first;
      q.pop();
      if( vis[nod] ) continue;
      left--;
      vis[nod] = 1;
      dmin[s][nod] = cost;
      for(vector<pair<int,int> >::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
         if( vis[it->first]==0 ) {
            q.push(make_pair(cost+it->second, it->first));
         }
   }
}

int main() {
   int m, ksz;
   fin >> n >> m;
   fin >> ksz;
   k.resize(ksz);
   for(int i=0; i<ksz; i++) {
      fin >> k[i];
      k[i]--;
   }


   for(int i=0; i<m; i++) {
      int a, b, c;
      fin >> a >> b >> c;
      e[a-1].push_back(make_pair(b-1, c));
      e[b-1].push_back(make_pair(a-1, c));
   }

   memset(cmin, 0x3f3f3f3f, sizeof(cmin));
   cmin[0][0] = 0;
   dijkstra(0);
   if( ksz==0 ) {
      fout << dmin[0][n-1];
      return 0;
   }

   for(int i=0; i<ksz; i++) {
      dijkstra(k[i]);
      cmin[1<<i][i] = dmin[0][k[i]];
   }

   for(int v=1; v<(1<<ksz); v++) 
      for(int j=0; j<ksz; j++) // vizitate orasele din v, ultimul fiind j
         if( (v & (1<<j)) ) {
            for(int i=0; i<ksz; i++)
               if( (v & (1<<i)) == 0 ) {  // continua la orasul i nevizitat
                  cmin[v | (1<<i)][i] = min(cmin[v | (1<<i)][i], cmin[v][j] + dmin[k[j]][k[i]]);
               }
         }

   int best = INF;
   for(int i=0; i<ksz; i++)
      best = min(best, cmin[(1<<ksz) - 1][i] + dmin[k[i]][n-1]);
   fout << best << '\n';

   return 0;
}
