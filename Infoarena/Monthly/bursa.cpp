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
#define INFILE "bursa.in" 
#define OUTFILE "bursa.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

LL n, p[NMAX];
LL s;

int main()
{
	fin >> n >> s;
	for(int i=0; i<n; i++)
		fin >> p[i];

	LL smax = s, sleft = s, actmax = 0;
	for(int i=0; i<n; i++)
	{
		while( i+1<n && p[i]>=p[i+1]) i++;
		
		actmax = smax / p[i];
		sleft = smax - actmax * p[i];

		while( i+1<n && p[i]<=p[i+1]) i++;
		smax = sleft + actmax * p[i];
	}

	fout << smax - s;

	return 0;
}