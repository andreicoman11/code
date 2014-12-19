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
#define INFILE "disjoint.in" 
#define OUTFILE "disjoint.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int parent[NMAX], rang[NMAX];

int getroot(int x)
{
	int y;
	for(y=x; y!=parent[y]; y = parent[y]);

	for(int i=x; i!=y;) {
		i = parent[i];
		parent[x] = y;
		x = i;
	}
	
	return y;

}
void unite(int a, int b)
{
   int x = getroot(a);
   int y = getroot(b);
	if( x==y )
		return;

	if( rang[x] > rang[y] )
		parent[y] = x;
	else if( rang[x] < rang[y] )
		parent[x] = y;
   else {
      parent[y] = x;
      rang[x]++;
   }
}

int main()
{
	int n, m;
	fin >> n >> m;

	for(int i=1; i<=n; i++)
		parent[i] = i;

	while( m-- )
	{
		int op, a, b;
		fin >> op >> a >> b;
		if( op==1 ) {
			unite(a, b);

		} else {
			if( getroot(a) == getroot(b) )
				fout << "DA\n";
			else
				fout << "NU\n";

		}
	}

	return 0;
}