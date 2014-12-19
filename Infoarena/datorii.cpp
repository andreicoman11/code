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
#define INFILE "datorii.in" 
#define OUTFILE "datorii.out"
#define NMAX 15010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, c[NMAX];

void add(int p, int v)
{
	int poz = 1;
	while(p<=n)
	{
		c[p] += v;
		while( (poz&p) == 0 ) poz <<= 1;
		p += poz;
	}
}

int getsum(int p)
{
	int poz = 1, sum = 0;
	while(p)
	{
		sum += c[p];
		while( (poz&p)==0 ) poz <<= 1;
		p -= poz;
	}
	return sum;
}

int main()
{
	int m, a, b, c;
	fin >> n >> m;
	for(int i=1; i<=n; i++) 
	{	
		fin >> a;
		add(i, a);
	}
	while(m--)
	{
		fin >> a >> b >> c;
		if( a==0 )
			add(b, -c);
		else
			fout << getsum(c) - getsum(b-1) << "\n";
	}

	return 0;
}