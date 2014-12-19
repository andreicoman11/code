#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "distincte2.in" 
#define OUTFILE "distincte2.out"
#define NMAX 1000010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m;
int v[NMAX];
int a[1000010];
int b[1000010][2];

int main()
{
	fin >> n >> m;
	for(int i=0; i<n; i++)
		fin >> a[i];

	for(int i=0; i<m; i++)
		fin >> b[i][0] >> b[i][1];

	for(int i=0; i<n; i++)
		if( v[a[i]]==0 ) {
			v[a[i]] = 1;
		}

	
	for(int i=1; i<NMAX; i++)
		v[i] += v[i-1];

	for(int i=0; i<m; i++) {
		fout << v[b[i][1]] - v[b[i][0]-1] << "\n";
	}

	return 0;
}