#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

#define LL long long
#define INFILE "mvc.in" 
#define OUTFILE "mvc.out"
#define NMAX 100010

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int INF = 0x3f3f3f3f;
int n, c[NMAX], t[NMAX], a, b, dp[NMAX][2], mincost;
vector<vector<int> > e;
vector<int> v;
bool vis[NMAX];


void bfs() {
   queue<int> q;
   vis[0] = 1;
   q.push(0);
   a = -1;

   while( !q.empty() ) {
      int nod = q.front();
      v.push_back(nod);
      q.pop();

      for(auto it=e[nod].begin(); it!=e[nod].end(); it++)
         if( vis[*it] && *it!=t[nod] ) {
            a = *it;
            b = nod;

         } else if( *it!=t[nod] ) {
            vis[*it] = 1;
            t[*it] = nod;
            q.push(*it);
         }
   }
}

void get_cost(int x) {
   memset(dp, 0, sizeof(dp));
   for(int i=n-1; i>=0; i--) {
      int nod = v[i];
      int cost_sel = c[nod], cost_not_sel = 0;
      for(auto it=e[nod].begin(); it!=e[nod].end(); it++) 
         if( *it!=t[nod] ) {
            cost_not_sel += dp[*it][1];
            cost_sel += min(dp[*it][1], dp[*it][0]);
         }
      dp[nod][0] = cost_not_sel;
      dp[nod][1] = cost_sel;
      if( x==nod ) dp[nod][0] = INF;
   }
   cout << x << " " << dp[0][0] << " " << dp[0][1] << endl;
   mincost = min(mincost, min(dp[0][0], dp[0][1]));
}

int main() {
   fin >> n;
   for(int i=0; i<n; i++)
      fin >> c[i];
   e.resize(n);
   
   for(int i=0; i<n; i++) {
      fin >> a >> b;
      e[a-1].push_back(b-1);
      e[b-1].push_back(a-1);
   }

   bfs();
   for(auto it=e[a].begin(); it!=e[a].end(); it++)
      if( *it==b ) {
         e[a].erase(it);
         break;
      }
   for(auto it=e[b].begin(); it!=e[b].end(); it++)
      if( *it==a ) {
         e[b].erase(it);
         break;
      }
   
   cout << a << " " << b << endl;
   mincost = INF;
   get_cost(a);
   get_cost(b);
   fout << mincost << '\n';

   return 0;
}
