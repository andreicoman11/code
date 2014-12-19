#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("F.dat");

int n, m;
int diag[26];
long long rez1, rez2, rez;

void backpar(int diag_curenta, int nebuni_pusi, int k);
void backimpar(int diag_curenta, int nebuni_pusi, int k);

int main()
{
	int k;
	fin >> n >> m >> k;
	while( (n+m+k) != -3 )
	{
		if( n>m )
		{
			int aux = n;
			n = m;
			m = aux;
		}
		memset(diag, 0, sizeof(diag));
		if( k>m+n-2 )
			cout << "0\n";
		else
		{
			rez1 = 0;
			rez2 = 0;
			backpar(1, 0, k);
			backimpar(1, 0, k);
			rez = rez1 + rez2;
			//cout << k << " " << rez1 << "\t" << k << " " << rez2 << " " << rez << endl;
			for(int i=1; i<k; i++)
			{
				rez1 = 0;
				rez2 = 0;
				backimpar(1, 0, k-i);
				backpar(1, 0, i);
				rez += rez1*rez2;
				cout << k-i << " " << rez1 << "\t" << i << " " << rez2 << " " << rez << endl;
			}
			cout << rez << endl;
		}

		fin >> n >> m >> k;
	}
	return 0;
}

void backpar(int d, int k2, int k)
{
	if( d%2 ) d++;
	//cout << k2 << " " << d << endl;
	//system("pause");
	
	if( k2==k ) rez2++;
	else if( d<m+n && k2<k )
	{
		if( m+n-1+k2*2-d >= k ) backpar(d+1, k2, k);
		if( d<=n ) // perete stanga
		{
			for(int i=1; i<=d; i++)
				if( diag[n-d+2*i]==0 )
				{
					diag[n-d+2*i] = 1;
					//cout << n-d+i << " " << i << " " << k2 << " " << d << endl;
					backpar(d+1, k2+1,k);
					diag[n-d+2*i] = 0;
				}
		}
		else if( n<d && d<=m ) // diag maxime
		{
			int j = d-n+1;
			for(int i=0; i<n; i++)
				if( diag[j+1+i*2]==0 )
				{
					diag[j+1+i*2] = 1;
					//cout << i+1 << " " << j+i << " " << k2 << " " << d << endl;
					backpar(d+1, k2+1, k);
					diag[j+1+i*2] = 0;
				}

		}
		else if( d>m ) // diag descresc
		{
			int j = d-n+1;
			for(int i=0; j+i<=m; i++)
				if( diag[j+1+i*2]==0 )
				{
					diag[j+1+i*2] = 1;
					//cout << i+1 << " " << j+i << " " << k2 << " " << d << endl;
					backpar(d+1, k2+1, k);
					diag[j+1+i*2] = 0;
				}
		}
	}
} 

void backimpar(int d, int k2, int k)
{
	if( d%2==0 ) d++;
	//cout << k2 << " " << d << endl;
	//system("pause");
	
	if( k2==k ) rez1++;
	else if( d<m+n && k2<k )
	{
		if( m+n+k2*2-d >= k ) backimpar(d+1, k2, k);
		if( d<=n ) // perete stanga
		{
			for(int i=1; i<=d; i++)
				if( diag[n-d+2*i]==0 )
				{
					diag[n-d+2*i] = 1;
					//cout << n-d+i << " " << i << " " << k2 << " " << d << endl;
					backimpar(d+1, k2+1, k);
					diag[n-d+2*i] = 0;
				}
		}
		else if( n<d && d<=m ) // diag maxime
		{
			int j = d-n+1;
			for(int i=0; i<n; i++)
				if( diag[j+1+i*2]==0 )
				{
					diag[j+1+i*2] = 1;
					//cout << i+1 << " " << j+i << " " << k2 << " " << d << endl;
					backimpar(d+1, k2+1, k);
					diag[j+1+i*2] = 0;
				}

		}
		else if( d>m ) // diag descresc
		{
			int j = d-n+1;
			for(int i=0; j+i<=m; i++)
				if( diag[j+1+i*2]==0 )
				{
					diag[j+1+i*2] = 1;
					//cout << i+1 << " " << j+i << " " << k2 << " " << d << endl;
					backimpar(d+1, k2+1, k);
					diag[j+1+i*2] = 0;
				}
		}
	}
} 