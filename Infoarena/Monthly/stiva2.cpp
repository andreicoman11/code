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
#define INFILE "stiva2.in" 
#define OUTFILE "stiva2.out"
#define NMAX 1024
#define MOD 9973

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, k, a[NMAX], b[NMAX][NMAX];
int res, v[128];

bool verif()
{
	int last = 0, sum = v[0];
	for(int i=1; i<n; i++)
	{
		sum += v[i];
		if( sum==0 ) {
			if( last+k<i ) return 0;
			last = i+1;
		}
	}
	return 1;
}

void back(int i, int f, int g)
{
	if( i>=n )
	{
		if( verif() ) {
			res = (res + 1) % MOD;
			/*for(int j=0; j<n; j++)
				cout << v[j] << " ";
			cout << endl;*/
		}
	}
	else {
		v[i] = -1;
		if( f<n/2 ) back(i+1, f+1, g);
		v[i] = 1;
		if( g<n/2 ) back(i+1, f, g+1);
	}
}

int main()
{
	fin >> n >> k;
	//for(n=2; n<=100; n+=2)
	//for(k=2; k<=100; k++)
	//{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		b[0][0] = 1;
		b[1][1] = 2;
		for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++) 
			if( b[i][j] )
			{
				if( j+1<=(k+1)/2 ) b[i+1][j+1] = (b[i+1][j+1] + b[i][j]) % MOD;
				if( j )		b[i+1][j-1] = (b[i+1][j-1] + b[i][j]) % MOD;
			}

		a[0] = 1;
		for(int i=2; i<=n; i+=2)
		{
			for(int p=2; p<=k+1 && i>=p; p+=2)
				a[i] = (a[i] + a[i-p] * b[p][0]) % MOD;
		}

		//res = 0;
		//back(0, 0, 0);
		//if( res!=a[n] )	cout << n << " " << k << "\t" << res << " " << a[n] << endl;
		//cout << endl;
	//}
	fout << a[n];


	return 0;
}