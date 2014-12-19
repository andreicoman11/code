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
#define INFILE "aib.in" 
#define OUTFILE "aib.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, c[NMAX];

void add(int p, int v) {
	while(p<=n) {
		c[p] += v;
		p += (p & -p); // add last 1 digit
	}
}

int getsum(int p) {
	int s = 0, poz = 1;
	while(p) {
		s += c[p];
		p -= (p & -p); // subtract last 1 digit
	}
	return s;
}

int bin_search(int val) {
	int a = 1, b = n;
	while( a+1<b ) {
		int m = (a+b) >> 1;
		if( getsum(m)<val ) a = m+1;
		else b = m;
	}
	if( getsum(a)==val ) return a;
	if( getsum(b)==val ) return b;
	return -1;
}

int main() {
	fin >> n >> m;
	int op, poz, val, a, b;
    c[0] = 0;
	for(int i=1; i<=n; i++) {
		fin >> val;
		add(i, val);
	}

	for(int i=0; i<m; i++){
		fin >> op ;
		switch(op) {
			case 0:
				fin >> poz >> val;
				add(poz, val);
				break;
			case 1:
				fin >> a >> b;
				fout << getsum(b) - getsum(a-1) << "\n";
				break;
			default:
				fin >> val;
				fout << bin_search(val) << "\n";
		}
	}


	return 0;
}