#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

//ifstream fin ("A-small-practice.in");
//ofstream fout ("A-small.out");
ifstream fin ("A-large-practice.in");
ofstream fout ("A-large.out");

int N, N2 = 1;

int d[10], c[26];

int main()
{
	fin >> N;
	while( N2<=N )
	{
		string t;
		fin >> t;
		long long int rez = 0;
		if( t.size()==1 ) rez = 1;
		else
		{
			int no[64];
			memset(d, -1, sizeof(d));
			memset(c, -1, sizeof(c));
			memset(no, 0, sizeof(no));
			int cul = 1;
			int base = 0;
			for(int i=0; i<t.size(); i++)
			{
				if( isdigit(t[i]) )
				{
					int a = t[i] - int('0');
					if( d[a]!=-1 ) no[i] = d[a];
					else
					{
						d[a] = no[i] = cul;
						if( cul==1 ) cul = 0;
						else if( cul==0 ) cul = 2;
						else cul++;
						base++;
					}
				}
				else
				{
					int a = t[i] - int('a');
					if( c[a]!=-1 ) no[i] = c[a];
					else
					{
						c[a] = no[i] = cul;
						if( cul==1 ) cul = 0;
						else if( cul==0 ) cul = 2;
						else cul++;
						base++;
					}
				}
				//cout << t[i] << " " << no[i] << endl;system("pause");
			}
			if( base==1 ) base = 2;
			long long pow = 1;
			for(int i=t.size()-1; i>=0; i--)
			{
				rez += pow * no[i];
				pow *= base;
			}
		}
			

		fout << "Case #" << N2 << ": " << rez << "\n";
		//cout << t << " " << rez << endl;system("pause");
		N2++;
	}

	return 0;
}
