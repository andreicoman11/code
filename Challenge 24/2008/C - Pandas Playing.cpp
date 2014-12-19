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

#define PROBLEM "C"

ifstream fin;
ofstream fout;

int n, art_points, root;
vector<vector<int> > e;
vector<int> lowp, depth;

void DFS(int n, int t, int dep)
{
	depth[n] = lowp[n] = dep;
	for(vector<int>::iterator it=e[n].begin(); it!=e[n].end(); it++)
		if( *it!=t && depth[*it]==-1 ) {
			DFS(*it, n, dep+1);
			lowp[n] = min(lowp[n], lowp[*it]);
			if( depth[n]<=lowp[*it] )
				if( root!=n || (root==n && e[root].size()>2 || 
					(e[root].size()==2 && lowp[e[root][0]]!=lowp[e[root][1]]) ))
					art_points++;
				
		} else if( *it!=t )
			lowp[n] = min(lowp[n], depth[*it]);
}

bool exists() {
	fin >> n;
	if( n%2 ) {
		std::cout << "n impar: " << n << endl;
		//return 0;
	}
	e.clear();
	e.resize(n);
	for(int i=0; i<n; i++) {
		int m;
		fin >> m;
		e[i].resize(m);
		for(int j=0; j<m; j++) {
			fin >> e[i][j];
			e[i][j]--;
		}
	}

	// BFS
	vector<bool> searched(n);
	for(int i=0; i<n; i++)
	if( !searched[i] )
	{
		searched[i] = 1;
		vector<int> pos;
		vector<bool > vis(n);
		queue<pair<int, int> > q;
		q.push(make_pair(i,0));
		vis[i] = 1;
		int lvlmax = 0;
		while( !q.empty() ) {
			int nod = q.front().first, lvl = q.front().second;
			q.pop();
			lvlmax = max(lvl, lvlmax);
			if(lvl==n/2)
				pos.push_back(nod);
			else if(lvl>n/2) return 0;
			for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
				if( !vis[*it] ) {
					vis[*it] = 1;
					q.push(make_pair(*it, lvl+1));
				}
		}

		if( lvlmax<n/2-1 ) {
			vis.clear();
			vis.resize(n);
			q.push(make_pair(i,0));
			vis[i] = 1;
			while( !q.empty() ) {
				int nod = q.front().first, lvl = q.front().second;
				q.pop();
				searched[nod] = 1;
				if( lvl+lvlmax+1 < n/2 )
					for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
						if( !vis[*it] ) {
							vis[*it] = 1;
							q.push(make_pair(*it, lvl+1));
						}
			}

		} else if( pos.size() ) {
			art_points = 0;
			root = i;
			lowp.clear();
			lowp.resize(n);
			depth.clear();
			depth.resize(n);
			depth.assign(n, -1);
			// find articulation points
			DFS(i, -1, 0);
			if( !art_points ) return 1;
			//else return 0;
		}
	}
	return 0;
}

void solve() {
	fout << (exists() ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
}

int main() {
	for(int i=1, tests; i<=10; i++) {
		ostringstream ins, outs;
		ins << PROBLEM << i << ".in";		outs << PROBLEM << i << ".out";		
		fin.open(ins.str());
		fout.open(outs.str());

		fin >> tests;
		while( tests-- ) {
			solve();
		}

		fin.close();
		fout.close();
	}

	return 0;
}