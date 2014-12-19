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

ifstream fin("D.dat");
//ofstream fout("D.out");

int main()
{
	int N;
	unsigned long long s = 1;
	while(fin >> N)
	{
		s = 0;
		while(N--)
		{
			unsigned long long aux;
			fin >> aux;
			s += aux;
		}
		//cout << s << "\t";;
		unsigned long long l = 1, r = 1000000000;
		unsigned long long f = 0;
		while( r-l>1 )
		{
			unsigned long long a = (r+l)/2;
			if( a*a==s )
			{
				f = a;
				break;
			}
			else if( a*a>s )
			{
				r = a;
			}
			else
			{
				l = a;
			}
			//cout << l << " " << r << endl;
		}
		if(s==1 )
			cout << "1\n";
		else if( f )
			cout << f << endl;
		else 
			cout << "No solution\n";
	}
	return 0;
}