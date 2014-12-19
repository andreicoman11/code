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

#define LL long long
#define sortAll(x) sort(x.begin(), x.end())
#define INFILE "timp.in" 
#define OUTFILE "timp.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main() {
	int n, k;
	fin >> n >> k;
	int clep[3];
	clep[0] = k;
	clep[1] = n-k;

	stack<int> moves;
	while(clep[0]!=0 && clep[1]!=0) {
		int minclep = min(clep[0], clep[1]);
		clep[2] = 2 * minclep;
		clep[0] -= minclep;
		clep[1] -= minclep;
		if( clep[0]==0 )	{
			moves.push(1);
			clep[0] = clep[1];
			clep[1] = clep[2];
		}
		else {
			moves.push(0); 
			clep[1] = clep[0];
			clep[0] = clep[2];
		}
	}

	fout << moves.size() << '\n';
	while( !moves.empty() ) {
		fout << moves.top() << '\n';
		/*if( moves.top()==1 ) {
			int initclep = clep[0];
			clep[0] = clep[1] + initclep/2;
			clep[1] = initclep/2;
			clep[2] = 0;
		} else {
			int initclep = clep[1];
			clep[1] = clep[0] + initclep/2;
			clep[0] = initclep/2;
			clep[2] = 0;
		}*/
		//cout << clep[0] << " " << clep[1] << " " << clep[2] << '\n';
		moves.pop();
	}

	return 0;
}