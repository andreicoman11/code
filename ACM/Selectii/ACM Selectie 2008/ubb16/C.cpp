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

ifstream fin ("C.in");
//ofstream fout ("C.out");

int N;

int main()
{
	string e1, e2;
	fin >> e1;
	while( e1[0]!='E' )
	{
		double h, t, d;
		h = t = d = -200;
		if( e1[0]=='T' ) fin >> t;
		if( e1[0]=='H' ) fin >> h;
		if( e1[0]=='D' ) fin >> d;

		fin >> e2;
		if( e2[0]=='T' ) fin >> t;
		if( e2[0]=='H' ) fin >> h;
		if( e2[0]=='D' ) fin >> d;
		
		if( d!=-200 )
		{
			double e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(d+273.16))));
			double A = (0.5555)*(e - 10.0);
			if( h==-200 )
				h = t + A;
			else
				t = h - A;
		}
		else
		{
			//d = ((double)1) / (-1)*(((log(((h-t)/0.5555 + 10.0)/6.11))/5417.7530 - 1/273.16)) - 273.16;
			double A = (h-t)/0.5555 + 10.0;
			A = log(A/6.11);
			A = A/5417.7530;
			A = 1/273.16 - A;
			d = ((double)1)/A - 273.16;
		}
		cout.setf(ios::fixed);
		cout << setprecision(1) << "T " << t << " D " << d << " H " << h << "\n";

		fin >> e1;
	}

	return 0;
}

