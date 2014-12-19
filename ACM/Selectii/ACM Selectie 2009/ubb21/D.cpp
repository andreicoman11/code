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

long long p = 0;

void back(int i, int sum, int v[], int n)
{
	if( sum==n )
	{
		long long prod = 1;
		for(int j=0; j<i; j++)
			if( v[j]==1 ) prod*=3;
			else prod*=2;
		p += prod;
	}
	else for(int j=1; j<=n; j++)
		if( sum+j<=n )
		{
			v[i] = j;
			back(i+1,sum+j,v,n);
		}
}

int main()
{
	int N;
	cin >> N;
	//N=1;
	while( N>=0 )
	{
		if( N%2==0 )
		{
			p = 0;
			int v[20];
			back(0,0,v,N/2);
			cout << p << endl;
		}
		else cout << "0\n";

		cin >> N;
	}

	return 0;
}
