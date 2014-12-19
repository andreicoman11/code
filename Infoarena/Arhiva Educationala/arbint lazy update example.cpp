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
#include <stack>
#include <queue>
#include <tuple>
using namespace std;

//ifstream fin (".in");
//ifstream fin ("C-small.in");
ifstream fin ("C-large.in");
ofstream fout (".out");

const int NMAX = 16000008;
set<long long> edge;
map<long long,int> edge_idx;
multimap<int, tuple<int, long long, long long> > attacks;
int smax = 2000000000;
int wall[NMAX], lazy[NMAX], x, y;
int wallmin = 0, wallmax;

int getmin(int idx, int a, int b) {
   if( y<a || x>b ) return smax;

   if( lazy[idx]!=0 ) {
      wall[idx] = max(wall[idx], lazy[idx]);
      if( a!=b ) {
         lazy[2*idx] = max(lazy[2*idx], lazy[idx]);
         lazy[2*idx+1] = max(lazy[2*idx+1], lazy[idx]);
      }
      lazy[idx] = 0;
   }

   if( x<=a && b<=y ) return wall[idx];
   if( a==b ) return wall[idx];
   int mid = (a+b) / 2;

   int res = smax;
   /*if( x<=mid && a<=y )*/   res = min(res, getmin(idx*2, a, mid));
   /*if( x<=b && mid+1<=y )*/ res = min(res, getmin(idx*2+1, mid+1, b));
   return res;
}

bool is_suc(tuple<int,long long,long long> attack) {
   int s;
   long long w, e;
   tie(s,w,e) = attack;
   w *= 2LL;
   e *= 2LL;
   x = edge_idx[*edge.find(w)];
   y = edge_idx[*edge.find(e)];
   int smin = getmin(1, wallmin, wallmax);
   
   //cout << s << " " << w << " " << e << "\t" << smin << endl;
   return s > smin;
}

void add(int idx, int a, int b, int val) {
   if( lazy[idx]!=0 ) {
      wall[idx] = max(wall[idx], lazy[idx]);
      if( a!=b ) {
         lazy[2*idx] = max(lazy[2*idx], lazy[idx]);
         lazy[2*idx+1] = max(lazy[2*idx+1], lazy[idx]);
      }
      lazy[idx] = 0;
   }

   if( y<a || x>b ) return;

   if( x<=a && b<=y ) {
      wall[idx] = max(wall[idx], val);
      lazy[idx] = wall[idx];
      return;
   }
   if( a==b ) {
      wall[idx] = max(wall[idx], val);
      lazy[idx] = wall[idx];
      return ;
   }
   int mid = (a+b) / 2;

   /*if( x<=mid && a<=y ) */add(idx*2, a, mid, val);
   /*if( x<=b && mid+1<=y )*/ add(idx*2+1, mid+1, b, val);
   wall[idx] = min(wall[idx*2], wall[idx*2+1]);
}

void repair_wall(tuple<int,long long,long long> attack) {
   int s;
   long long w, e;
   tie(s,w,e) = attack;
   int smin = smax;
   w *= 2LL;
   e *= 2LL;
   auto it = edge.find(w);
   x = edge_idx[*edge.find(w)];
   y = edge_idx[*edge.find(e)];
   add(1, wallmin, wallmax, s);
}

void solve() {
   attacks.clear();
   edge.clear();
   edge_idx.clear();
   memset(wall, 0, sizeof(wall));
   memset(lazy, 0, sizeof(lazy));
   int N;
   fin >> N;
   for(int i=0; i<N; i++) {
      int n, d, s, dd, ds;
      long long w, e, dpos;
      fin >> d >> n >> w >> e >> s >> dd >> dpos >> ds;
      for(;n; n--) {
         attacks.insert(make_pair(d, make_tuple(s, w, e)));
         edge.insert(w*2-1);
         edge.insert(w*2);
         edge.insert(e*2);
         edge.insert(e*2+1);
         d += dd;
         s += ds;
         w += dpos;
         e += dpos;
      }
   }

   int idx = 0;
   for(auto it=edge.begin(); it!=edge.end(); it++)
      edge_idx[*it] = idx++;
   wallmax = edge.size();
   cout << edge.size() << endl;
   
   int suc_attacks = 0;
   for(int day=0; day<=676060; day++) {
      auto init_it = attacks.find(day);
      // find successful attacks
      for(auto it = init_it; it!=attacks.end() && it->first==day; it++) {
         //cout << it->first << " " << get<0>(it->second) << " " << get<1>(it->second)-1000001 << " " << get<2>(it->second)-1000001 << "   \t";
         suc_attacks += is_suc(it->second);
         //cout << suc_attacks << endl;
      }

      // repair walls
      for(auto it = init_it; it!=attacks.end() && it->first==day; it++) {
         repair_wall(it->second);
      }
   }
   
   fout << suc_attacks << endl;
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      cout << N2 << endl;
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}