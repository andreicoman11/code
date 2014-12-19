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
#define INFILE "meneaito.in" 
#define OUTFILE "meneaito.out"
#define NMAX 200010
#define MAXSEC 200000

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, x[NMAX][3], a[NMAX], b[NMAX];
bool vis[16*NMAX];

int comp(const void* a, const void* b)
{
	return ((int*)a)[0] - ((int*)b)[0];
}

int main()
{
	fin >> n;
	int cnt = 0;

	for(int i=2; i<n; i++)
		fin >> a[i];

	for(int i=2; i<n; i++)
		fin >> b[i];

	for(int i=2; i<n; i++)
	{
		int period = (b[i]-a[i])*2;
		if( a[i]<=i && i<=b[i] )
		{
			x[cnt][0] = period;
         if( period==0 )
         {
            fout << -1;
            return 0;
         }
			x[cnt][1] = i-a[i];
			x[cnt][2] = b[i]-a[i]+b[i]-i;
			if( x[cnt][2]==period ) x[cnt][2] = 0;
			cnt++;
		}
	}

	qsort(x, cnt, 3*sizeof(int), comp);

	for(int i=0; i<cnt; i++)
	{
		int per = x[i][0];
		int p1 = x[i][1];
		int p2 = x[i][2];
		if( !(vis[ per+per+p1+per+per+per ] && vis[ per+per+p1+per+per ] && vis[ per+p1+per+per ] && vis[ per+p1+per ] && vis[ per+p1 ] && vis[p1]) )
		{
			vis[p1] = vis[per+p1] = 1;
			for(int j=per+p1+per; j<=MAXSEC; j+=per )
				vis[j] = 1;
		}
		if( p1!=p2 && !(vis[ per+per+p2+per+per+per ] && vis[ per+per+p2+per+per ] && vis[ per+p2+per+per ] && vis[ per+p2+per ] && vis[ per+p2 ] && vis[p2]) )
		{
			vis[p2] = vis[per+p2] = 1;
			for(int j=per+p2+per; j<=MAXSEC; j+=per )
				vis[j] = 1;
		}
		
	}

	int min = -1;
	for(int i=0; min==-1 && i<=MAXSEC; i++)
		if( !vis[i] ) min = i;

	fout << min;

	return 0;
}