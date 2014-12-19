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

vector<int> x, y;


int main()
{
	int N;
	cin >> N;
	while( N-- )
	{
		int n, k;
		cin >> n;
		x.clear();
		x.resize(n);
		y.clear();
		y.resize(n);
		for(int i=0; i<n; i++)
			cin >> x[i];
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> y[i];
		cin >> k;
		//cout << k << " " << n << endl;
		double min_dist = 10000;
		for(double i=-50; i<=50; i+=0.5)
		for(double j=-50; j<=50; j+=0.5)
		{
			vector<double> dist(x.size());
			for(int l=0; l<x.size(); l++)
				dist[l] = abs(i-x[l]) + abs(j-y[l]);
			sort(dist.begin(), dist.end());
			if( dist[k-1]<min_dist ) min_dist = dist[k-1];
		}
		printf("%.1f\n", min_dist);
		//cout << min_dist << endl;
	}

	return 0;
}
