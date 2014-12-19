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

#define INFILE "scmax.in" 
#define OUTFILE "scmax.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int a[NMAX], t[NMAX], m[NMAX];

int get_pos(int l, int r, int val)
{
	while( l<r )
	{
		int pos = (l+r) / 2;
		if( a[m[pos]]<val && val<=a[m[pos+1]] ) return pos;
		else if( val<=a[m[pos]] ) r = pos-1;
		else l = pos+1;
	}
	return l;
}

void print_scmax(int i)
{
	if( t[i]!=-1 ) print_scmax(t[i]);
	fout << a[i] << " ";
}

int main()
{
	int n;
	fin >> n;
	for(int i=0; i<n; i++)
		fin >> a[i];

	t[0] = -1;
	m[0] = 0;
	int nr = 0;

	for(int i=1; i<n; i++)
	{
		if( a[i] <= a[m[0]] ) {
			m[0] = i;
			t[i] = -1;
		} else {
			int pos = get_pos(0, nr, a[i]);

			m[pos+1] = i;
			t[i] = m[pos];
			nr = max(nr, pos+1);
		}
	}
	
	fout << nr+1 << '\n';
	print_scmax(m[nr]);

	return 0;
}