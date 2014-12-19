#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std;

ifstream fin ("C-large-practice.in");
ofstream fout ("C-large-practice.out");
#define LL long long
#define LMAX 1000000000

int d[2046], l[2048];

void solve() {
	int n;
	fin >> n;
	vector<vector<int> > e(n);
	for(int i=0; i<n-1; i++) {
		fin >> d[i];
		d[i]--;
		e[d[i]].push_back(i);
		l[i] = -1;
	}

	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<d[i]; j++)
			if( d[j]>d[i] ) {
				fout << "Impossible\n";
				return;
			}
	}

	l[0] = l[n-1] = LMAX;
	
	int k = 0, k2;
	stack<int> s;
	while( k<n-1 ) {
		k2 = d[k];
		l[k2] = LMAX;

		for(int i=k+1; i<k2; i++)
			if( d[i]==k2 ) {
				l[i] = LMAX-1;
				s.push(i);
				}
		k = k2;
	}

	while( !s.empty() ) {
		int j = s.top();
		s.pop();
		if( e[j].size()==0 ) 
			continue;
		int j0 = e[j][0];
		LL a1 = d[j] - j;
		LL a2 = j - j0;
		LL x1 = l[d[j]] - l[j];
		int x2 = ceil(double(x1 * a2) / (double)a1);
		l[j0] = l[j] - x2;
		s.push(j0);

		for(int i=1; i<e[j].size(); i++) {
			j0 = e[j][i-1];
			double step = double(l[j] - l[j0]) / double(j - j0);
			a2 = e[j][i] - j0;
			x2 = int(floor(step * a2));
			l[e[j][i]] = l[j0] + x2;
			if( (a2 * (l[j] - l[j0])) % (j - j0) == 0 )
				l[e[j][i]]--;
			s.push(e[j][i]);
		}
	}

	for(int i=0; i<n-1; i++) {
		double step = double(l[d[i]] - l[i]) / double(d[i]-i);
		double len = l[i];
		for(int j=i+1; j<d[i]; j++) {
			len += step;
			if( int(floor(len))<l[j] ) {
				cout << "error:" << i << " " << j << " " << d[i] << " "<< d[j] << "\t" << (LL)len << " " << l[j] << " " << l[d[i]] << " " << l[d[j]]<< endl;
			}
		}
	}

	for(int i=0; i<n; i++)
		fout << l[i] << " ";
	fout << "\n";
}

int main() {
	int N, N2 = 1;
	fin >> N;
	while( N2<=N )
	{
		fout << "Case #" << N2++ << ": ";
		solve();
	}

	return 0;
}
