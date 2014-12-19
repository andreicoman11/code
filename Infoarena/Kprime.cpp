#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin ("kprime.in");
ofstream fout ("kprime.out");
bool prime[1001];
int no[100001];
unsigned long long int pos = 0;

int main()
{
	memset(prime, 0, sizeof(prime));
	prime[2] = prime[3] = 1;
	for(int i=5; i<1000; i+=2)
	{
		bool ok = true;
		for(int j=3; j*j<=i && ok; j+=2)
			if( i%j==0 ) ok = false;
		if( ok ) prime[i] = 1;
	}
	int prevp = -1;
	int firstp = -1, lastp = -1, nextp;
	int kk = 0;
	int n,k;
	fin >> n >> k;
	for(int i=0; i<n; i++)
		fin >> no[i];
	int c = 0;

	//find firstp
	while( c<n && prime[no[c]]==0 ) c++;
	firstp = c;
	// find lastp
	while( c<n && kk<k )
	{
			if( prime[no[c]] ) kk++;
			c++;
	}
	lastp = c-1;
	if( kk<k ) 
	{
		fout << 0 << endl;
	}
	// find nextp
	while( c<n && prime[no[c]]==0 ) c++;
		nextp = c;
	//cout << prevp << " " << firstp << " " << lastp << " " << nextp << endl;
	//system("pause");

	while( lastp<n )
	{
		pos += (firstp-prevp)*(nextp-lastp);
		//cout << pos << endl;
		prevp = firstp;
		firstp++;
		while( prime[no[firstp]]==0 ) firstp++;
		lastp = nextp;
		nextp++;
		while( nextp<n && prime[no[nextp]]==0 ) nextp++;
		//cout << prevp << " " << firstp << " " << lastp << " " << nextp << endl;
		//system("pause");
	}
	fout << pos << endl;
return 0;
}
