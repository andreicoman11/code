#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "pitagora2.in" 
#define OUTFILE "pitagora2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

LL n;
vector<int> d;

int main()
{
	fin >> n;
	for(int i=1; i*i<=n; i++)
		if( n%i==0 ) {
			d.pb(i);
			if( i*i!=n ) d.pb(n/i);
		}
	sort(d.begin(), d.end());

	LL p = 0, q = -1;
	for(int i=0; i<d.sz; i++)
	for(int j=i; j<d.sz && d[i]*d[j]<n; j++)
		if( d[i]*d[j]>p && (n/d[i]*n/d[j])%2==(d[i]*d[j])%2) {
			p = d[i]*d[j];
			q = n/d[i] * n/d[j];
		}
	if( q==-1 ) fout << "-1\n";
	else fout << (q-p) / 2;

	return 0;
}