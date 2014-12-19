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
#define sortAll(x) sort(x.begin(), x.end())
#define INFILE "linterv.in" 
#define OUTFILE "linterv.out"
#define NMAX 5010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int v[NMAX][2];

int comp(const void* a, const void* b)
{
	return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
	int T;
	fin >> T;
	while(T--)
	{
		int n;
		fin >> n;
		for(int i=0; i<n; i++)
		fin >> v[i][0] >> v[i][1];

		qsort(v, n, 2*sizeof(int), comp);

		int sum = 0, b = v[0][0], e = v[0][1];
		for(int i=1; i<n; i++)
			if( e>=v[i][0] )
				e = max(e, v[i][1]);
			else {
				sum += e-b;
				b = v[i][0];
				e = v[i][1];
			}
		sum += e-b;
		fout << sum << "\n";
	}

	return 0;
}