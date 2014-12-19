#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

#define pb push_back
#define sz size()
#define INFILE "graf2.in" 
#define OUTFILE "graf2.out"
#define NMAX 1024

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, idx, compidxctr, res;
vector<int> v[NMAX], cv[NMAX], topv;
int lowidx[NMAX], compidx[NMAX];
vector<vector<int> > comp;
stack<int> st;
bitset<NMAX> dr[NMAX];
bool inst[NMAX];

void tarjan(int x)
{
	int xidx = ++idx;
	lowidx[x] = idx;
	st.push(x);
	inst[x] = 1;

	for(int i=0; i<v[x].sz; i++) {
		if( lowidx[ v[x][i] ]==0 ) {
			tarjan( v[x][i] );
			lowidx[x] = min(lowidx[x], lowidx[v[x][i]]);

		} else if(inst[ v[x][i] ] )
			lowidx[x] = min(lowidx[x], lowidx[v[x][i]]);
	}

	if( lowidx[x]==xidx ) 
	{
		vector<int> ct;
		int w;
		do{
			w = st.top();
			inst[w] = 0;
			compidx[w] = compidxctr;
			st.pop();
			ct.push_back(w);

		} while( w!=x );
		++compidxctr;
		comp.push_back(ct);
		res += (ct.sz == 1 ? 0 : ct.sz);
	}
}

void topsort() 
{
	vector<int> nin( compidxctr );
	queue<int> n0;
	for(int i=0; i<compidxctr; i++)
	{
		for(int j=0; j<compidxctr; j++)
			if( dr[j][i] ) nin[i]++;
		if( nin[i]==0 ) n0.push(i);
	}

	while( !n0.empty() )
	{
		int nod = n0.front();
		n0.pop();
		topv.pb(nod);
		for(int i=0; i<compidxctr; i++)
			if( dr[nod][i] ) {
				nin[i]--;
				if( nin[i]==0 ) n0.push(i);
			}
	}

}

int main()
{
	fin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		fin >> a >> b;
		v[a-1].pb(b-1);
	}

	for(int i=0; i<n; i++)
		if( lowidx[i]==0 )
			tarjan(i);
			
	// compute new graph with supernodes, no cycles
	for(int i=0; i<comp.sz; i++)
	{
		for(int j=0; j<comp[i].sz; j++) {
			int compnod = comp[i][j];
			for(int k=0; k<v[compnod].sz; k++)
				dr[i][ compidx[v[compnod][k]] ] = 1;
		}
		dr[i][i] = 0;
	}

	topsort();
	bitset<NMAX> e2[NMAX];
	for(int i = compidxctr-1; i>=0; i--)
	{
		for(int j=0; j<compidxctr; j++)
			if( dr[topv[i]][j] && e2[topv[i]][j]==0 ) 
			{
				res++;
				e2[topv[i]][j] = 1;
			}
		for(int j=0; j<compidxctr; j++)
			if( dr[j][topv[i]] )
			{
				e2[j] = e2[j] | e2[topv[i]];
			}
	}
	fout << res;

	return 0;
}