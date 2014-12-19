#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

ofstream fout ("H.out");
ifstream fin  ("H.in");
int n, m[1000][1000];


int main()
{
	fin >> n;
	while(n)
	{
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fin >> m[i][j];

		int ok = 1;
		for(int x=0; ok && x<n-1; x++)
		for(int y=0; ok && y<n-1; y++)
		{
			int a = x+1;
			int b = y+1;
			while( ok && a<n && b<n )
			{
				if( m[x][y] + m[a][b] != m[x][b] + m[a][y] )
					ok = 0;
				a++;
				b++;
			}
		}
		if( ok ) fout << "homogeneous\n";
		else fout << "not homogeneous\n";
		fin >> n;
	}

	return 0;
}
