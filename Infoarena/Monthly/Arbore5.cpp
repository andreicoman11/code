#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <map>
using namespace std;

#define INFILE "arbore5.in" 
#define OUTFILE "arbore5.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

struct nod{
	int tata;
	list<int> fii;
};

bool comp[NMAX];
int n, m, nr[NMAX], res;
nod v[NMAX];

void verif(int x) {
	comp[x] = 1;
	for(list<int>::iterator it=v[x].fii.begin(); it!=v[x].fii.end(); it++) {
		if( v[x].tata!=*it ) v[ *it ].tata = x;
		if( !comp[ *it ] ) verif( *it );
		if( v[x].tata!=*it )  nr[x] += nr[ *it ];
	}
	if( nr[x]%2==0 && x!=1 ) res++;
}

int main()
{
	fin >> n >> m;

	for(int i=0; i<n-1; i++) {
		int a, b;
		fin >> a >> b;
		v[a].fii.push_back(b);
		v[b].fii.push_back(a);
	}

	for(int i=0; i<m; i++) {
		int a, b;
		fin >> a >> b;
		nr[a]++;
		nr[b]++;
	}

	res = 0;
	verif(1);

	fout << res << "\n";

	return 0;
}