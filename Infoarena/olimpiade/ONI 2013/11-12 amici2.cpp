#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

#define INFILE "amici2.in" 
#define OUTFILE "amici2.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

static const int NMAX = 21010;
bool vis[NMAX];
vector< vector<int> > e;

int main() {
   int n, m;
   int t;
   fin >> t;
   while(t--) {
      fin >> n >> m;
      e.clear();
      e.resize(n);
      for(int i=0; i<m; i++) {
         int a, b;
         fin >> a >> b;
         a--, b--;
         e[a].push_back(b);
         e[b].push_back(a);
      }

      queue<pair<int, int> > q;
      memset(vis, 0, sizeof(vis));
      q.push(make_pair(0,0));
      vis[0] = 1;
      int maxlvl = 0;
      while( !q.empty() ) {
         int nod = q.front().first;
         int lvl = q.front().second;
         q.pop();
         maxlvl = max(maxlvl, lvl);
         for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
            if( !vis[*it] ) {
               vis[*it] = 1;
               q.push(make_pair(*it, lvl+1));
            }
      }

      int zile = 0;
      while(maxlvl) {
         zile++;
         maxlvl >>= 1;
      }
      fout << zile << '\n';
   }

   return 0;
}
