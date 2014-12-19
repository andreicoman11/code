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
#define INFILE "bile.in" 
#define OUTFILE "bile.out"
#define NMAX 256

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int p[NMAX*NMAX], rang[NMAX*NMAX], v[NMAX*NMAX][2], res[NMAX*NMAX], s[NMAX*NMAX];
bool u[NMAX][NMAX];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int getroot(int x)
{
	int y = x;
	for(; y!=p[y]; y = p[y]);

	for(int i=x; i!=y; )
	{
		i = p[i];
		p[x] = y;
		x = i;
	}
	return y;
}

int unite(int x, int y)
{
   int a = getroot(x);
   int b = getroot(y);
   if( a==b ) return s[a];

	if( rang[a]>rang[b] ) 
	{
		p[b] = a;
		s[a] += s[b];
		return s[a];
	}
	else if( rang[b]>rang[a] )
	{
		p[a] = b;
		s[b] += s[a];
		return s[b];

	} 
   else 
   {
      rang[a] ++;
      p[b] = a;
		s[a] += s[b];
		return s[a];
   }
}

int main()
{
	int n;
	fin >> n;
	for(int t=0; t<n*n; t++)
	{
		fin >> v[t][0] >> v[t][1];
      v[t][0]--;
      v[t][1]--;
		p[t] = t;
		rang[t] = 1;
		s[t] = 1;
	}

	int cmax = 0;
	for(int i=n*n-1; i>=0; i--)
	{
		res[i] = cmax;
		u[ v[i][0] ][ v[i][1] ] = 1;
		for(int j=0; j<4; j++)
		{
			int x = v[i][0] + dx[j];
			int y = v[i][1] + dy[j];
			if( x>=0 && y>=0 && x<n && y<n && u[x][y] ) {
				int sum = unite(p[x*n+y], p[v[i][0]*n+v[i][1]]);
				cmax = max(sum, cmax);
			}
		}
		cmax = max(cmax, s[ v[i][0]*n + v[i][1] ]);
	}

	for(int i=0; i<n*n; i++)
		fout << res[i] << "\n";

	return 0;
}