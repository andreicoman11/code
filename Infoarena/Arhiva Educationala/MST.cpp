#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "apm.in" 
#define OUTFILE "apm.out"
#define NMAX 200010
#define pii pair<int,int>
#define piii pair<int, pii>

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m;
vector<pii > e[NMAX];
vector<piii > mst;
bool vis[NMAX];

int prim(int x, int y, int c)
{
	priority_queue<piii, vector<piii>, greater<piii> > q;
	vis[x] = vis[y] = 1;
	
	for(vector<pii >::iterator it=e[x].begin(); it!=e[x].end(); it++)
		if( vis[it->first]==0 )
			q.push(make_pair(it->second, make_pair(x, it->first)));
	
	for(vector<pii >::iterator it=e[y].begin(); it!=e[y].end(); it++)
		if( vis[it->first]==0 )
			q.push(make_pair(it->second, make_pair(y, it->first)));

	int put = 2, mst_cost = c;
	mst.pb( make_pair(c, make_pair(x, y)));
	while( put<n ){
		piii nod = q.top();
		q.pop();
		if( vis[nod.second.second] ) continue;
		put++;
		vis[nod.second.second] = 1;
		mst_cost += nod.first;
		mst.pb(nod);

		for(vector<pii >::iterator it=e[nod.second.second].begin(); it!=e[nod.second.second].end(); it++)
			if( vis[it->first]==0 )
				q.push(make_pair(it->second, make_pair(nod.second.second, it->first)));
	}
	return mst_cost;
}

int main()
{
	fin >> n >> m;
	int ea, eb, ec = 1010;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		fin >> a >> b >> c;
		e[a-1].pb(make_pair(b-1, c));
		e[b-1].pb(make_pair(a-1, c));
		if( c<ec ) {
			ec = c;
			ea = a-1;
			eb = b-1;
		}
	}

	int mst_cost = prim(ea, eb, ec);

	fout << mst_cost << "\n";
	fout << mst.sz << "\n";
	for(vector<piii >::iterator it=mst.begin(); it!=mst.end(); it++)
		fout << it->second.first+1 << " " << it->second.second+1 << "\n";

	return 0;
}