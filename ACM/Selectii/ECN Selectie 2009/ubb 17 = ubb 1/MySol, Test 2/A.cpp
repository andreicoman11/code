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

ifstream fin("A.dat");

int main()
{
	int s;
	while(fin >> s)
	{
		int N;
		bool c[100005];
		int nr[100005];
		memset( c, false, sizeof(c));
		c[0] = 1;
		fin >> N;
		for(int i=0; i<N; i++)
		{
			int d, n;
			fin >> n >> d;
			if(n && s)
			{
				memset( nr, 0, sizeof(nr));
				/*for(int j=0; j<=s-d; j++)
					if( c[j] && nr[j]==0 )
						for(int k=1; k<=n && j+d*k<=s; k++)
						{
							c[j+d*k]=1;
							nr[j+d*k]=1;
						}*/
				for(int j=d; j<=s; j++)
					if( c[j]==false && c[j-d] && nr[j-d]<n )
					{
						c[j] = 1;
						nr[j] = nr[j-d]+1;
					}
				/*cout << d << " of " << n << " times\n";
				for(int j=0; j<=s; j++)
					if( c[j] ) cout << j << " " << nr[j] << "   ";
				system("pause");*/
			}
		}
		while(c[s]==false)
			s--;
		cout << s << endl;
	}
	return 0;
}