#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

ofstream fout ("D.out");
ifstream fin  ("d.txt");
int m[2][10000];

int main()
{
	string a, b;
	while( fin >> a )
	{
		fin >> b;
		//cout << a << " " << b << "\n";
		for(unsigned int i=0, val=0; i<b.size(); i++)
		{
			if( b[i]==a[0] ) val = 1;
			m[0][i] = val;
			//cout << m[0][i] << " ";
			//if( i+1==b.size() ) cout << "\n";
		}

		for(unsigned int ii=1; ii<a.size(); ii++)
		for(unsigned int j=0; j<b.size(); j++)
		{
			int i = ii%2;
			int i2 = (ii+1)%2;
			if( a[ii]==b[j] )
			{				
				//cout << "if ";
				if( j==0 ) m[i][j]=1;
				else
				{
					m[i][j] = max( m[i][j-1], m[i2][j-1]+1);
				}				
			}
			else
			{
				if( j==0 ) m[i][j] = m[i2][j];
				else m[i][j] = max( m[i][j-1], m[i2][j]);
			}
			//cout << "i=" << i << "i2=" << i2 << " " << ii << " " << j << "\t" << m[i][j] << "\t" << m[i][j-1] << " " << m[i2][j-1] << "\n";
			//cout << m[i][j] << " ";// << m[i2][j] << "\n" << "\n" ;
			//if( j== b.size()-1 ) cout << "\n";
		}
		/*for(unsigned int i=0; i<a.size(); i++)
		{
			for(unsigned int j=0; j<b.size(); j++)
				cout << m[i][j] << " ";
			cout << endl;
		}*/

		fout << m[(a.size()-1)%2][b.size()-1] << "\n";
	}

	return 0;
}
