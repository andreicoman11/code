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

const int root = 0;
vector<vector<int> > e, bic_comp;
vector<int> depth, lowp, art_points;
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
				if( n!=root || (n==root && 
					(e[root].size()>2 || (e[root].size()==2 && lowp[e[root][0]]!=lowp[e[root][1]] ))))
					art_points.push_back(n);
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

	DFS(root, -1, 0);

	fout << bic_comp.size() << '\n';
	for(int i=0; i< bic_comp.size(); i++) {
		for(int j=0; j<bic_comp[i].size(); j++)
			fout << bic_comp[i][j]+1 << " ";
		fout << '\n';
	}

	sort(art_points.begin(), art_points.end());
	art_points.erase(unique(art_points.begin(), art_points.end()), art_points.end());
	fout << art_points.size() << '\n';
	for(int i=0; i<art_points.size(); i++)
		fout << art_points[i]+1 << ' ';

	return 0;
}