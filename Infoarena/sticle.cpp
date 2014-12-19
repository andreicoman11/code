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

#define INFILE "sticle.in" 
#define OUTFILE "sticle.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int T;
	fin >> T;
	int v[32];
	v[0] = 1;
	for(int i=1; i<32; i++)
		v[i] = v[i-1] * 2;
	while( T-- )
	{
		int n;
		fin >> n;
		for(int i=0; i<32; i++)
			if( n<=v[i] ) {
				fout << i << "\n";
				break;
			}
	}

	return 0;
}