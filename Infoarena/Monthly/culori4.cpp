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
#define INFILE "culori4.in" 
#define OUTFILE "culori4.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, a[32][2], b[32][2], na=0, nb=0;
int m[16][16];
LL res = 0;

void check()
{
	LL p = 1;
	for(int i=0; i<nb; i++)
	{
		int pi = 0;
		for(int j=1; j<=5; j++)
		{
			int x = b[i][0];
			int y = b[i][1];
			if( m[x-1][y]!=j && m[x+1][y]!=j && m[x][y-1]!=j && m[x][y+1]!=j )
				pi++;
		}
		p *= pi;
	}
	res += p;
}

void back(int i)
{
	if( i>=na )
		check();
	else
		for(int j=1; j<=5; j++)
		{
			int x = a[i][0];
			int y = a[i][1];
			if( m[x-1][y]!=j && m[x+1][y]!=j && m[x][y-1]!=j && m[x][y+1]!=j )
			{
				m[x][y] = j;
				back(i+1);
			}
		}
}

int main()
{
	fin >> n;
   memset(m, 0, sizeof(m));
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	{
		char caux;
		fin >> caux;
		
		if( caux=='?' )
		{
			m[i][j] = 0;
			if( (i+j)%2==0 ) {
				a[na][0] = i;
				a[na][1] = j;
				na++;
			} else {
				b[nb][0] = i;
				b[nb][1] = j;
				nb++;
			}
		} else m[i][j] = int(caux) - int('0');
	}

	if( na>nb )
	{
		int aux[32][2];
		memcpy(aux, a, sizeof(a));
		memcpy(a, b, sizeof(b));
		memcpy(b, aux, sizeof(aux));
		int naux = na;
		na = nb;
		nb = naux;
	}

   bool ok = 1;   
	for(int i=1; ok && i<=n; i++)
	for(int j=1; ok && j<=n; j++)
      if( m[i][j] && (m[i][j]==m[i-1][j] || m[i][j]==m[i+1][j] ||
         m[i][j]==m[i][j-1] || m[i][j]==m[i][j+1]) )
         ok = 0;

	back(0);

   if( na==0 && nb==0 ) res = 1;
   if( !ok ) res = 0;
	fout << res;

	return 0;
}