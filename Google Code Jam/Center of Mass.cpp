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

//ifstream fin ("B-small-practice.in");
ifstream fin ("B-large-practice.in");
//ofstream fout ("B-large.out");

int N, N2 = 1;


int main()
{
	FILE* fout;
	//fopen_s( &fout, "B-small.out", "w");
	fopen_s( &fout, "B-large.out", "w");
	fin >> N;
	while( N2<=N )
	{
		int n;
		fin >> n;
		long double x, y, z, a, b, c;
		x = y = z = a = b = c = 0.0;
		for(int i=0; i<n; i++)
		{
			long double xx, yy, zz;
			fin >> xx >> yy >> zz;
			x += xx/n;
			y += yy/n;
			z += zz/n;
			fin >> xx >> yy >> zz;
			a += xx/n;
			b += yy/n;
			c += zz/n;
		}
		bool move = 1;
		if( a*a+b*b+c*c<0.0000001 ) move = 0;
		
		long double t = - (a*x+b*y+c*z);
		t /= (a*a+b*b+c*c);

		fprintf( fout, "Case #%d: ", N2);
		
		if( move==0 || t<0 )
		{
			fprintf(fout, "%.8f %.8f\n", sqrt(x*x+y*y+z*z), 0);
		}
		else
		{
			long double dis = 0;
			dis += (x+t*a)*(x+t*a);
			dis += (y+t*b)*(y+t*b);
			dis += (z+t*c)*(z+t*c);
			fprintf(fout, "%.8f %.8f\n", sqrt( dis ), t);
		}
		N2++;
	}

	return 0;
}
