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
#include <iomanip>
using namespace std;

ifstream fin ("D.in");
//ofstream fout ("D.out");

int d;

int main()
{
	int c[400], a[400];
	fin >> d;
	while(d)
	{
		double p;
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));
		fin >> p;
		int i = 0;
		c[0] = 100000;
		a[0] = (int)( (double)c[0]/p*0.97 );
		//cout << i << " " << c[i] << " " << a[i] << "\n";
		for(i=1; i<d; i++)
		{
			fin >> p;
			int ci = max( c[i-1], (int)( (double)a[i-1]*p*0.97 ) );
			int ai = max( a[i-1], (int)( (((double)c[i-1])/p)*0.97 ) );
			c[i] = ci;
			a[i] = ai;
			//cout << i << " " << c[i] << " " << a[i] << " " << "\n";
		}

		double rez = c[d-1];
		rez /= 100;
		cout.setf(ios::fixed);
		cout << setprecision(2) << rez << "\n";

		fin >> d;
	}

	return 0;
}