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
#define INFILE "diagonale.in" 
#define OUTFILE "diagonale.out"
#define NMAX 1024
ifstream fin (INFILE);
ofstream fout (OUTFILE);

long long n, a[NMAX][NMAX], dp[2*NMAX], ds[2*NMAX];

int main()
{
	fin >> n;
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		fin >> a[i][j];

	long long dmax = a[0][0];
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++){
		int ddif = i - j;
		int dsum = i + j;
		dp[1000 + ddif] += a[i][j];
		ds[dsum] += a[i][j];
	}

   for(int i=1000-n+1; i<=1000+n-1; i++)
      dmax = max(dmax, dp[i]);

   for(int i=0; i<=2*n-2; i++)
      dmax = max(dmax, ds[i]);

	fout << dmax;
	
	return 0;
}