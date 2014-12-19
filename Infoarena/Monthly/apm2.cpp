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
#include <vector>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "apm2.in" 
#define OUTFILE "apm2.out"
#define NMAX 10010
#define pii pair<int,int>
#define piii pair<int, pii >

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, q;
bool vis[NMAX];
priority_queue<piii, vector<piii >, greater<piii > > q1;
vector<vector<pii > > e;
vector<vector<pii > > apm;

void prim(int x, int y, int c)
{
	apm[x].push_back(make_pair(y, c));
	apm[y].push_back(make_pair(x, c));
	vis[x] = vis[y] = 1;

	for(vector<pii >::iterator it=e[x].begin(); it!=e[x].end(); it++)
		q1.push(make_pair(it->second, make_pair(x, it->first)));

	for(vector<pii >::iterator it=e[y].begin(); it!=e[y].end(); it++)
		q1.push(make_pair(it->second, make_pair(y, it->first)));

	int put = 2;
	piii nod;
	while(put<n) {
		nod = q1.top();
		q1.pop();
		if( vis[nod.second.second] ) continue;
		put++;
		apm[ nod.second.first ].push_back(make_pair(nod.second.second, nod.first));
		apm[ nod.second.second ].push_back(make_pair(nod.second.first, nod.first));
		vis[ nod.second.second ] = 1;
		
		for(vector<pii >::iterator it=e[nod.second.second].begin(); it!=e[nod.second.second].end(); it++)
			if( !vis[it->first] )
				q1.push(make_pair(it->second, make_pair(nod.second.second, it->first)));
	}
}

int getMaxCostOnMST(int x, int y)
{
	memset(vis, 0, sizeof(vis));
	queue<pii > q2;
	q2.push(make_pair(x, 0) );
	pii nod;
	while( !q2.empty() )
	{
		nod = q2.front();
		q2.pop();
		vis[nod.first] = 1;
		for(vector<pii >::iterator it=apm[nod.first].begin(); it!=apm[nod.first].end(); it++) {
			if( it->first==y ) 
				return max(nod.second, it->second);
			if( vis[it->first]==0 )		
				q2.push(make_pair(it->first, max(nod.second, it->second)));
		}
	}
	return -1; // this shouldn't happen
}

int main()
{
	int ea, eb, emin = NMAX;

	fin >> n >> m >> q;
	e.resize(n);
	apm.resize(n);
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		fin >> a >> b >> c;
		a--;
		b--;
		e[a].push_back(make_pair(b,c));
		e[b].push_back(make_pair(a,c));
		if( emin>c ) {
			emin = c;
			ea = a;
			eb = b;
		}
	}

	prim(ea, eb, emin);
	e.clear();

	for(; q; q--)
	{
		int a, b;
		fin >> a >> b;
		int cost = getMaxCostOnMST(a-1, b-1);
		fout << cost - 1 << "\n";
	}

	return 0;
}