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
long long int v[900], v2[900];
long long int res, aux;

int main()
{
	fin >> N;
	while( N2<=N )
	{
		int n;
		fin >> n;
		memset( v, 0, sizeof(v));
		for(int i=0, j; i<n; i++)
		{
			fin >> v[i];
			j = i;
			while( i && v[i]<v[i-1] )
			{
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
				i--;
			}
			i = j;
		}

		memset( v2, 0, sizeof(v2));
		for(int i=0, j; i<n; i++)
		{
			fin >> v2[i];
			j = i;
			while( i && v2[i]<v2[i-1] )
			{
				aux = v2[i];
				v2[i] = v2[i-1];
				v2[i-1] = aux;
				i--;
			}
			i = j;
		}
		
		res = 0;
		for(int i=0; i<n; i++)
		{
			res += v[i] * v2[n-i-1];
		}

		fout << "Case #" << N2 << ": ";
		fout << res;
		if( N2!=N) fout << "\n";
		N2++;
	}

	return 0;
}
