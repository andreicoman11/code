#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

#define INFILE "alianta.in" 
#define OUTFILE "alianta.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, n1, n2, maxn;
vector<vector<int> > e;
int best[1<<18];

void search_first(int i, int clans, int vis, int mask) {
   if( i>=n1 ) {
      int mask2 = ((1<<n2)-1) ^ mask;
      best[mask2] = max(best[mask2], clans);

   } else {
      search_first(i+1, clans, vis, mask);

      if( vis & (1<<i) ) return;
      for(auto it=e[i].begin(); it!=e[i].end(); it++)
         if( *it<n1 )   vis |= (1 << (*it));
         else           mask |= (1 << (*it - n1));
      
      search_first(i+1, clans+1, vis, mask);
   }
}

void search(int i, int clans, int mask, int vis) {
   if( i>=n ) {
      //cout << maxn << " " << clans << " " << best[mask] << " " << mask << endl;
      maxn = max(maxn, clans + best[mask]);

   } else {
      search(i+1, clans, mask, vis);

      if( vis & (1<<(i-n1)) ) return;
      for(auto it=e[i].begin(); it!=e[i].end(); it++)
         if( *it>=n1 )  vis |= (1 << (*it - n1));
      
      search(i+1, clans+1, (mask | (1<<(i-n1))), vis);
   }
}

void solve() {
   memset(best, 0, sizeof(best));
   n1 = (n+1) / 2;
   n2 = n - n1;
   
   search_first(0, 0, 0, 0);
   for(int i = (1<<n2)-1; i; i--) {
      for(int j=0; j<n2; j++)
         if( (i & (1<<j))==0 )
            best[i] = max(best[i], best[i + (1<<j)]);
   }
   
   maxn = 1;
   search(n1, 0, 0, 0);
}

int main() {
   int t;
   fin >> t;
   while(t--) {
      int m;
      fin >> n >> m;
      e.clear();
      e.resize(n);
      for(int i=0; i<m; i++) {
         int a, b;
         fin >> a >> b;
         e[a-1].push_back(b-1);
         e[b-1].push_back(a-1);
      }
      
      solve();
      fout << maxn << '\n';
   }

   return 0;
}
