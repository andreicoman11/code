#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

//ifstream fin (".in");
ifstream fin ("D-small.in");
//ifstream fin ("-large.in");
ofstream fout (".out");

bool vis[1<<20];
int t[1<<20], n, k;
vector<multiset<int> > ch;
map<int,int> keys, keyneeded;

void printch(int v) {
   if( t[v] ) printch(t[v]);
   int nr = v - t[v];
   int val = 0;
   while(nr) {
      val++;
      nr /= 2;
   }
   fout << val << " ";
}

void dfs(int v) {
   if( v==((1<<n)-1) ) {
      vis[v] = 1;
      return ;
   }
   if( vis[(1<<n)-1] ) return ;
   if( vis[v] ) return ;

   vis[v] = 1;
   for(int i=0; i<n; i++)
      if( vis[ v | (1<<i)]==0 && keys[keyneeded[i]]>0 ) {
         keys[keyneeded[i]]--;
         for(multiset<int>::iterator it=ch[i].begin(); it!=ch[i].end(); it++) 
            keys[*it]++;

         t[v|(1<<i)] = v;
         dfs(v|(1<<i));

         keys[keyneeded[i]]++;
         for(multiset<int>::iterator it=ch[i].begin(); it!=ch[i].end(); it++) 
            keys[*it]--;
      }
   return ;
}

void solve() {
   memset(vis, 0, sizeof(vis));
   memset(t, 0, sizeof(t));
   ch.clear();
   keys.clear();

   fin >> k >> n;

   for(int i=0; i<k; i++) {
      int _key;
      fin >> _key;
      keys[_key-1]++;
   }

   ch.resize(n);
   for(int i=0; i<n; i++) {
      int kt, _keyneeded;
      fin >> _keyneeded >> kt;
      keyneeded[i] = _keyneeded - 1;
      for(int j=0; j<kt; j++) {
         int _key;
         fin >> _key;
         ch[i].insert(_key-1);
      }
   }

   dfs(0);
   if( vis[ (1<<n)-1 ] ) {
      printch( (1<<n)-1 );
      fout << endl;
   }
   else
      fout << "IMPOSSIBLE" << endl;
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}