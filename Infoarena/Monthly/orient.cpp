#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "orient.in" 
#define OUTFILE "orient.out"
#define NMAX 1024
#define pii pair<int,int>
#define inf 1000000000
ifstream fin (INFILE);
ofstream fout (OUTFILE);

vector<vector<pair<int,int> > > e;
int n, mincycle = inf, dist[NMAX];

int get_cost(
priority_queue<pii, vector<pii >, greater<pii > > q, int target) {
   while( !q.empty() ) {
      pii x = q.top();
      q.pop();
      if( dist[ x.second ]<inf ) continue;
      // ..->x.second = x.first
      dist[x.second] = x.first;
      if( x.second==target ) return x.first;

      for(vector<pii >::iterator it = e[x.second].begin(); it!=e[x.second].end(); it++)
         if( dist[ it->second ]==inf )
            q.push(make_pair( x.first + it->first, it->second));
   }

   return dist[target];
}

int main() {
   int m;
	fin >> n >> m;
   e.resize(n);
	for(; m; m--)
	{
		int a, b, c;
		fin >> a >> b >> c;
		a--; b--;
      // a->b==0, b->a==c
		e[a].pb( make_pair(0, b));
      e[b].pb( make_pair(c, a));
	}

   for(int i=0; i<n; i++)
   for(vector<pii >::iterator it = e[i].begin(); it!=e[i].end(); it++) {
      // i->j, find j->i
      int x = it->second;
      priority_queue<pii, vector<pii >, greater<pii > > q;
      for(vector<pii >::iterator it2 = e[x].begin(); it2!=e[x].end(); it2++)
         if( it2->second!=i )
            q.push(*it2);

      for(int p=0; p<n; p++)
         dist[p] = inf;
      dist[x] = 0;

      mincycle = min(mincycle, it->first + get_cost(q, i));
   }
      
	fout << mincycle;
	return 0;
}
