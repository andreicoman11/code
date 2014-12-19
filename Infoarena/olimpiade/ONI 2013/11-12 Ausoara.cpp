#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

#define INFILE "ausoara.in" 
#define OUTFILE "ausoara.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);
const static int NMAX = 101;

int n;
vector<int> v[NMAX], pos, res;

int main() {
	fin >> n;
	pos.resize(n);
	for(int i=0; i<n; i++) {
		int m;
		fin >> m;
		v[i].resize(m);
		for(int j=0; j<m; j++)
			fin >> v[i][j];
		pos[i] = 0;
	}

	for(int i=0; i<v[0].size(); i++) {
		bool ok = 1;
		for(int j=1; ok && j<n; j++) {
			int k = pos[j];
			for(;k<v[j].size() && v[j][k] < v[0][i]; k++);
			if( k==v[j].size() || v[j][k]>v[0][i] ) {
				ok = 0;
				pos[j] = k;
				break;
			}
			if( v[j][k]==v[0][i] ) pos[j] = k+1;
		}
		if( ok ) {
			res.push_back(v[0][i]);
		}
	}

	fout << res.size();
	for(int i=0; i<res.size(); i++)
		fout << " " << res[i];

	return 0;
}