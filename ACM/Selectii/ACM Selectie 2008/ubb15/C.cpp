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

ifstream fin ("C.in");
//ofstream fout ("C.out");

int main()
{
	int n,m,i,a;
	fin >> n >> m;
	int d[100000];
	int k[100000];
	while( n && m)
	{
		int maxsize = 1;
		memset(d, 0, sizeof(d));
		memset(k, 0, sizeof(k));
		for(i=0; i<n; i++)
		{
			fin >> a;
			d[a]++;
			if( a>maxsize ) maxsize = a;
		}
		for(i=0; i<m; i++)
		{
			fin >> a;
			k[a]++;
			if( a>maxsize ) maxsize = a;
		}
		int gold = 0;
		int dragons = 0;
		for(i=0; i<=maxsize; i++)
		{
			dragons += d[i];
			if( k[i] && dragons>0 )
			{
				if( k[i]<=dragons )
				{
					gold += k[i]*i;
					dragons -= k[i];
				}
				else
				{
					gold += dragons*i;
					dragons = 0;
				}
			}
		}
		if( dragons>0 )
			cout << "Loowater is doomed!\n";
		else 
			cout << gold << "\n";

		fin >> n >> m;
	}

	return 0;
}
