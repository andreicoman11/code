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
using namespace std;

ifstream fin ("E.in");
//ofstream fout ("E.out");

long long int a,p;

int main()
{
	fin >> p >> a;
	while( p && a)
	{
		bool prime = true;
		if( p%2==0 ) prime = false;
		for(long long int j=3; j*j<=p && prime; j+=2)
			if( p%j==0 )
				prime = false;
		if( prime )
			cout << "no\n";
		else
		{
			vector<int> bits;
			long long int p2 = p;
			while( p2 )
			{
				bits.push_back(p2%2);
				p2 /= 2;
			}
			/*for(int i=0; i<bits.size(); i++)
				cout << bits[i] << " ";
			cout << "\n";*/
			long long int ap = 1;
			long long int ai = a;		
			//cout << "p=" << p << " a=" << a << endl;
			for(long long int i=0; i<bits.size(); i++)
			{
				if( bits[i] )
				{
					 ap = (ap*ai)%p;				 
				}
				ai = (ai*ai)%p;
				//cout << i << " " << ap << " " << ai << "\n";
			}
			if( ap%p==a ) cout << "yes\n";
			else cout << "no\n";
		}

		fin >> p >> a;
	}

	return 0;
}