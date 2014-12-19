#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define PB push_back
#define SZ size()
#define SORT(x) sort(ALL(x))
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "D-small-attempt0.in" 
#define OUTFILE "D-small.out"
#define INFILE2 "D-large.in" 
#define OUTFILE2 "D-large.out"

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

ifstream fin (INFILE);

int p[64][3], n;

double minarea(int i, int j)
{
	double x = p[i][0] + p[j][0];
	x /= 2;
	double y = p[i][1] + p[j][1];
	y /= 2;
	double rez = p[i][2] + p[j][2];
	rez += sqrt( (x-p[i][0])*(x-p[i][0]) + (y-p[i][1])*(y-p[i][1]) );
	rez += sqrt( (x-p[j][0])*(x-p[j][0]) + (y-p[j][1])*(y-p[j][1]) );
	return rez/2;
}

int main()
{
	FILE* fout;
	fopen_s(&fout, OUTFILE, "w");
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
		int n;
		fin >> n;

		for(int i=0; i<n; i++)
			fin >> p[i][0] >> p[i][1] >> p[i][2];
		
		double rez = 0.0;
		if( n==1 ) rez = (double)p[0][2];
		else if( n==2 )
		{
			rez = max( p[0][2], p[1][2]);
		}
		else
		{
			rez = minarea(0, 1);
			for(int k=0; k<2; k++)
			for(int l=k+1; l<3; l++)
			{
				double min = minarea(k, l);
				if( min<rez ) rez = min;
			}
			if( p[1][2]>rez ) rez = p[1][2];
			if( p[2][2]>rez ) rez = p[2][2];
			if( p[0][2]>rez ) rez = p[0][2];
			
		}
	
		fprintf( fout, "Case #%d: %.6f\n", r, rez);
	}
	
	return 0;
}