#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "siret.in" 
#define OUTFILE "siret.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, s[310], perm[310], dp[310], t[310];
bool e[310][310];

int main()
{
	fin >> n >> m;
	memset(e, 0, sizeof(e));
	memset(s, 0, sizeof(s));
	memset(dp, 0, sizeof(dp));
	memset(t, 0, sizeof(t));
	for(int i=0; i<m; i++) {
		int a, b;
		fin >> a >> b;
		a--, b--;
		if( a<b ) swap(a, b);
		e[a][b] = 1;
		s[b]++;
	}
	queue<int> q;
	for(int i=0; i<n; i++)
		if( s[i]==0 )
			q.push(i);

	int cnt = 0;
	while( !q.empty() )
	{
		int nod = q.front();
		perm[cnt++] = nod;
		q.pop();
		for(int i=0; i<n; i++)
			if( e[nod][i] )
			{
				e[nod][i] = 0;
				s[i]--;
				if( s[i]==0 ) q.push(i), t[i] = -1;
			}
	}

	dp[0] = 1;
	int rez = 1, rezi = 0;
	for(int i=1; i<n; i++)
	{
		int maxi = 1, ii = -1;
		for(int j=0; j<i; j++)
			if( perm[j] > perm[i] && maxi<dp[j]+1)
				maxi = dp[j]+1, ii = j;
		dp[i] = maxi;
		t[i] = ii;
		if( maxi>rez )
			rez = maxi, rezi = i;
	}
	fout << rez << endl;
	while( rezi>=0 )
	{
		fout << perm[rezi]+1 << " ";
		rezi = t[rezi];
	}
	return 0;
}