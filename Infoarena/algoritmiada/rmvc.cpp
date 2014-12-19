#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <bitset>
#include <map>
using namespace std;

#define INFILE "rmvc.in" 
#define OUTFILE "rmvc.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int NMAX = 95;
const int MMAX = 325;
int n, m, edges, res;
bitset<NMAX> btres;
vector<vector<int> > e;
map<pair<int,int>, int> emap;
bool _emap[NMAX][NMAX];

void back(int i, bitset<NMAX> bt, bitset<MMAX> ebt) {
   if( (int)ebt.count()>=edges ) {
      if( (int)bt.count()<res ) {
         res = bt.count(), btres = bt;
      }

   } else if( i>=n || bt.count()>=18 ) return;

   else if( e[i].size()==0 || bt[i]==1 ) {
         back(i+1, bt, ebt);
         return ;
      }

   else {
      bitset<MMAX> ebt2 = ebt;
      for(auto it=e[i].begin(); it!=e[i].end(); it++)
         ebt2[ emap[make_pair(i, *it)] ] = 1;
        
      bt[i] = 1;
      back(i+1, bt, ebt2);

      bt[i] = 0;
      for(auto it=e[i].begin(); it!=e[i].end(); it++)
         if( bt[*it] == 0 ) {
            bt[*it] = 1;
            for(auto it2=e[*it].begin(); it2!=e[*it].end(); it2++) 
               ebt[ emap[make_pair(*it, *it2)] ] = 1;
         }
      back(i+1, bt, ebt);
   }
}

int main() {
   fin >> n >> m;
   while(m--) {
      int a, b;
      fin >> a >> b;
      a--;
      b--;
      _emap[a][b] = _emap[b][a] = 1;
      emap[make_pair(a,b)] = emap[make_pair(b,a)] = m;
   }

   e.resize(n);
   for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
         if( _emap[i][j] )
            e[i].push_back(j);
   edges = emap.size() / 2;

   res = n;
   bitset<NMAX> bt;
   bitset<MMAX> ebt;
   back(0, bt, ebt);
   fout << res << '\n';
   for(int i=0; i<n; i++)
      if( btres[i]==1 ) fout << i+1 << " " ;

   return 0;
}
