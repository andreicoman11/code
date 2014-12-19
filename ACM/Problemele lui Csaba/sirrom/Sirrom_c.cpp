#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

int n;
char d[16][10001];
vector<vector<int> > kmp;
vector<vector<int> > c;

int comp(char* T, char* P)
{
	int lt = strlen(T);
	int pt = strlen(P);
	if( lt==1 || pt==1 ) return 0;
	P[pt-1] = '#';
	vector<int> pi(lt + pt, 0);
	
	int k = 0;
	for(int i=1; i<pt; i++)
	{
		while( k>0 && P[k]!=P[i] )
			k = pi[k-1];
		if( P[k]==P[i] ) k++;
		pi[i] = k;
	}
	
	k = 0;
	for(int i=1; i<lt; i++)
	{
		while( k>0 && P[k]!=T[i] )
			k = pi[k-1];
		if( P[k]==T[i] ) k++;
		pi[i+pt] = k;
	}
	
	return pi[pi.size()-1];
}

int calc(int node, int bits)
{
	if( c[node][bits]!=-1 ) return c[node][bits];
	else
	{
		int res = 0;
		for(int i=0; i<n; i++)
			if( i!=node && (bits & (1<<i)) )
				res = max( res, kmp[i][node] + calc(i, bits-(1<<node)) );
		c[node][bits] = res;
		return res;
	}
}

int main()
{
	FILE* fin;
	fopen_s( &fin , "sirrom.in", "r");
	fscanf(fin, "%d", &n);
	while(n!=-1)
	{
		int tsum = 0;
		for(int i=0; i<n; i++)
		{
			fscanf( fin , "%s", d[i]);
			tsum += strlen(d[i]);
		}
		
		kmp.clear();
		kmp.resize(n);
		//cout << "comp\n";
		for(int i=0; i<n; i++)
		{
			kmp[i].resize(n);
			for(int j=0; j<n; j++)
				if( i!=j ) kmp[i][j] = comp(d[i], d[j]);
		}
		/*fout << endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				fout << kmp[i][j] << " ";
			fout << endl;
		}
		fout << endl;*/
		c.clear();
		c.resize(n);
		int tcomsum = 0;
		
		for(int i=0; i<n; i++)
		{
			c[i].resize(1<<n,-1);
			c[i][1<<i]=0;
		}
		//cout << "calc\n";
		for(int i=0; i<n; i++)
			tcomsum = max( tcomsum, calc(i, (1<<n)-1));
		
		cout << tsum - tcomsum << endl;
		
		fscanf(fin, "%d", &n);
	}

	return 0;
}
