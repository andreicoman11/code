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
#define INFILE "sr.in" 
#define OUTFILE "sr.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	string a, b;
	fin >> a >> b;
	for(int ib=0, ia=0; ib<b.sz; ib++) {
		while( a[ia]!=b[ib] ) ia++;
		ia++;
		fout << ia << " ";
	}

	return 0;
}