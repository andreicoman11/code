#include <vector>
#include <fstream>
#include <queue>
using namespace std;

#define INFILE "dijkstra.in" 
#define OUTFILE "dijkstra.out"
#define pb push_back
#define pii pair<int,int>
#define NMAX 50010
#define inf 50000000

vector< vector< pii > > e(NMAX);
int n, m, dist[NMAX];
priority_queue<pii, vector<pii >, greater<pii > > q;

void dijkstra(int start) {
   for(int i=0; i<n; i++)
      dist[i] = inf;

   q.push(make_pair(0, start));
   while( !q.empty() )
   {
      pii nod = q.top(); 
      q.pop();
      // first = cost, second = vecin
      if( dist[nod.second]<inf ) continue;

      dist[nod.second] = nod.first;
      for(vector<pii >::iterator it=e[nod.second].begin(); it!=e[nod.second].end(); it++)
         if( dist[ it->second ]==inf )
            q.push(make_pair(it->first + nod.first, it->second));
   }
}

int main() {
   ifstream fin(INFILE);
   ofstream fout(OUTFILE);

   fin >> n >> m;
   for(int i=0; i<m; i++) {
      int a, b, c;
      fin >> a >> b >> c;
      e[a-1].pb(make_pair(c, b-1));
   }

   dijkstra(0);
   for(int i=1; i<n; i++)
      fout << (dist[i]==inf ? 0 : dist[i]) << " ";

   return 0;
}
