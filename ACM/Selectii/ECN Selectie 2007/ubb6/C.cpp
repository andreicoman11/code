#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

ofstream fout ("C.out");
ifstream fin  ("chicago.in");
double v[100][100];

int main()
{
	int n,m;
	fin >> n;

	fout.setf(ios::fixed, ios::floatfield);
	fout.setf(ios::showpoint);
	fout.precision(6);

	while(n)
	{
		fin >> m;

		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			v[i][j] = 0;

		for(int i=0; i<m; i++)
		{
			int a,b,p;
			fin >> a >> b >> p;
			a--;b--;
			v[a][b] = v[b][a] = (double)p;
		}

		for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(  ( v[i][j] < (v[i][k]*v[k][j]/(double)100) ) )
				v[i][j] = v[i][k]*v[k][j]/(double)100;

		fout << v[0][n-1] << " percent\n";
		fin >> n;
	}

	return 0;
}
