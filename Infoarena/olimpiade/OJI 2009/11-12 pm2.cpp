#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define LL long long
#define sortAll(x) sort(x.begin(), x.end())
#define INFILE "pm2.in" 
#define OUTFILE "pm2.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n;
vector<vector<int> > g1, g2;
vector<int> deg1, deg2, t1, t2, tmp;

int main() {
	fin >> n;
	g1.resize(n);
	g2.resize(n);
	deg1.resize(n);
	deg2.resize(n);
	t1.resize(n);
	t2.resize(n);
	tmp.resize(n);
	for(int i=0; i<n; i++) 
		fin >> tmp[i];

	for(int i=0; i<n; i++) {
		int sz;
		fin >> sz;
		g2[i].resize(sz);
		deg1[i] = sz;
		for(int j=0; j<sz; j++) {
			fin >> g2[i][j];
			g2[i][j]--;
			g1[ g2[i][j] ].push_back(i);
			deg2[ g2[i][j] ]++;
		}
	}

	queue<int> q;
	for(int i=0; i<n; i++) {
		t1[i] = 0;
		if(deg1[i]==0)
			q.push(i);
	}

	int tmin = 0;
	while( !q.empty() ) {
		int nod = q.front();
		q.pop();
		tmin = max(tmin, t1[nod] + tmp[nod]);
		for(vector<int>::iterator it=g1[nod].begin(); it!=g1[nod].end(); it++) {
			t1[*it] = max(t1[*it], t1[nod] + tmp[nod]);
			deg1[*it]--;
			if( deg1[*it]==0 ) {
				q.push(*it);
			}
		}
	}

	for(int i=0; i<n; i++) {
		t2[i] = tmin - tmp[i];
		if(deg2[i]==0)
			q.push(i);
	}

	while( !q.empty() ) {
		int nod = q.front();
		q.pop();
		for(vector<int>::iterator it=g2[nod].begin(); it!=g2[nod].end(); it++) {
			t2[*it] = min(t2[*it], t2[nod] - tmp[*it]);
			deg2[*it]--;
			if( deg2[*it]==0 ) {
				q.push(*it);
			}
		}
	}

	fout << tmin << '\n';
	for(int i=0; i<n; i++)
		fout << t1[i] << ' ' << t2[i] << '\n';

	return 0;
}