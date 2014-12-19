#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;

ifstream fin ("F.in");
//ofstream fout ("F.out");

int grad(int,int,int);

int main()
{
	string a, b;
	fin >> a >> b;
	while( a[0]!='0' && b[0]!='0' )
	{
		int m[100][100];
		int val = 0;
		for(int i=0; i<b.size(); i++)
		{
			if( b[i]==a[0] ) val = 1;
			m[0][i] = val;
		}

		for(int i=1; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
		{
			if( a[i]==b[j] )
			{
				if( j==0 )	m[i][j] = 1;
				else m[i][j] = 1 + m[i-1][j-1];
			}
			else
			{
				if( j==0 ) m[i][j] = m[i-1][j];
				else m[i][j] = max( m[i-1][j], m[i][j-1] );
			}
		}
		/*for(int i=0; i<a.size(); i++)
		{
			for(int j=0; j<b.size(); j++)
				cout << m[i][j] << " ";
			cout << "\n";
		}*/
		int k = m[ a.size()-1 ][ b.size()-1 ];
		//cout << k << "\n";

		if( a.size()<b.size() )
			cout << grad( a.size(), b.size(), k ) << "\n";
		else 
			cout << grad( b.size(), a.size(), k ) << "\n";

		fin >> a >> b;
	}

	return 0;
}

int grad(int l1,int l2,int k)
{
	if( (k >= l1/2+l1%2) && ( k>= l2/2+l2%2) )
		return 1;
	if( l1 >= l2/2+l2%2 )//|| 3*k>=( l1/2+l1%2+l2/2+l2%2) )
	{
		return 2;
	}
	else
	{
		l1 = l1 * 2;
		//k = min( k+l1*2, l2 );
		k = k + l1/2;
		if( l1<l2 )	return 1 + grad(l1, l2, k);
		else return 1 + grad( l2, l1, k);
	}
}