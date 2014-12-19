#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
using namespace std;

#define INFILE "biconex.in" 
#define OUTFILE "biconex.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

vector<vector<int> > e, bic_comp;
vector<int> depth, lowp;
stack<pair<int,int> > st;

void bicComp(int x, int y) {
	vector<int> comp;
	int a, b;
	do {
		a = st.top().first, b = st.top().second;
		st.pop();
		comp.push_back(b);
	} while( a!=x && b!= y);
	comp.push_back(x);
	bic_comp.push_back(comp);
}

void DFS(int n, int t, int dep) {
	depth[n] = lowp[n] = dep;
	for(vector<int>::iterator it = e[n].begin(); it!=e[n].end(); it++) 
		if( *it!=t && depth[*it]==-1 ) {
			st.push(make_pair(n, *it));
			DFS(*it, n, dep+1);
			lowp[n] = min(lowp[n], lowp[*it]);
			if( depth[n]<=lowp[*it] ) {
				bicComp(n, *it);
			}
		}
		else
			lowp[n] = min(lowp[n], depth[*it]);
}

int main() {
	int n, m, a, b;
	fin >> n >> m;
	e.resize(n);
	depth.resize(n);
	for(int i=0; i<n; i++)
		depth[i] = -1;
	lowp.resize(n);

	for(int i=0; i<m; i++) {
		fin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	DFS(0, -1, 0);

	fout << bic_comp.size() << '\n';
	for(int i=0; i< bic_comp.size(); i++) {
		for(int j=0; j<bic_comp[i].size(); j++)
			fout << bic_comp[i][j]+1 << " ";
		fout << '\n';
	}

	return 0;
}