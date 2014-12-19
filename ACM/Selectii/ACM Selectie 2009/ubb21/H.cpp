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


int main()
{
	int N;
	cin >> N;
	while( N-- )
	{
		vector<int> x,y;
		int n;
		cin >> n;
		x.resize(n);
		y.resize(n);
		int maxx = -100, minx = 100, maxy = -100, miny = 100;
		for(int i=0; i<n; i++)
		{
			cin >> x[i];
			if( x[i]>maxx ) maxx = x[i];
			if( x[i]<minx ) minx = x[i];
		}
		cin >> n;
		for(int i=0; i<n; i++)
		{
			cin >> y[i];
			if( y[i]>maxy ) maxy = y[i];
			if( y[i]<miny ) miny = y[i];
		}

		int no = 0;
		for(int xx = minx+1; xx<maxx; xx++)
		for(int yy = miny+1; yy<maxy; yy++)
		{
			bool s, nn, e, w;
			s = nn = e = w = 0;
			for(int i=0; i<n; i++)
			{
				if( x[i]==xx && y[i]>yy ) nn=1;
				if( x[i]==xx && y[i]<yy ) s=1;
				if( y[i]==yy && x[i]>xx ) e=1;
				if( y[i]==yy && x[i]<xx ) w=1;
			}
			if( nn&&s&&w&&e ) no++;
		}

		cout << no << endl;
	}

	return 0;
}
