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
#include <queue>
#include <stack>
#include <list>
using namespace std;

#define PROBLEM ""
ifstream fin;
ofstream fout;

void solve() {
	
}

int main() {
	for(int i=1, tests; i<=10; i++) {
		ostringstream ins, outs;
		ins << PROBLEM << i << ".in";
		outs << PROBLEM << i << ".out";		
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