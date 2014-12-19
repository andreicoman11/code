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

ifstream fin("E.dat");
//ofstream fout("E.out");

int main()
{
	int N;
	int d[10005];
	while(!fin.eof())
	{
		fin >> N;
		memset( d, 0, sizeof(d));
		for(int i=0; i<N; i++)
		{
			int p, t;
			fin >> p >> t;
			for(int j=t; j>0 && p>0; j--)
				if( d[j]<p )
				{
					int aux = d[j];
					d[j] = p;
					p = aux;
				}
		}

		long long s = 0;
		for(int i=0; i<10005; i++)
			s += d[i];
		cout << s << endl;
	}
	
	return 0;
}