#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


ifstream fin  ("h.dat");
ofstream fout ("H.out");

int roads[1002][1002];
long long int sums[1002][1002];

int main()
{
	int N, n, m, k;
	fin >> N;
	int N2 = 1;
	while(N)
	{
		fin >> n >> m >> k;
		cout << k << "\n";

		for(int i=1; i<=n; i++)
		{
			memset( roads[i], 0, sizeof(roads[i]) );
			memset( sums[i], 0, sizeof(sums[i]) );
		}

		for(int i=0; i<k; i++)
		{
			int a,b;
			fin >> a >> b;
			roads[a][b] = 1;
		}

		for(int i=n; i; i--)
		for(int j=1; j<=m; j++)
		{
			sums[i][j] = roads[i][j] + max( sums[i][j-1], sums[i+1][j]);
		}

		unsigned long long int nr = 0;

		for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if( roads[i][j] )
				nr += sums[i+1][j-1];

		/*for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
				cout << sums[i][j] << " ";
			cout << "\n";
		}*/

		fout << "Test case " << N2 << ": " << nr << "\n";

		N--;
		N2++;
	}

	return 0;
}
