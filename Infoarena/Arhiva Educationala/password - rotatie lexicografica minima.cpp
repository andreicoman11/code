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
#define INFILE "password.in" 
#define OUTFILE "password.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

string s;
int n;

inline int val(int x)
{
	return( x>=n ? x-n : x);
}

int main()
{
	fin >> s;
	n = s.size();

	int min = 0, l = 0, p = 1;
	while( p<n )
	{
		while( l<n && s[val(min+l)]==s[val(p+l)] ) l++;
		if( l==n ) break;

		if( s[val(min+l)] < s[val(p+l)] ) {
			p = p + l + 1;
			l = 0;
		} else {
			min = max(p, min+l + 1);
			p = min+1;
			l = 0;
		}
		cout << min << " " << l << " " << p << "\n";
	}

	fout << min;


	return 0;
}