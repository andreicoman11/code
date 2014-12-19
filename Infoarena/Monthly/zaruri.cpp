#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "zaruri.in" 
#define OUTFILE "zaruri.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int n;
	fin >> n;
	double v[32];
	v[0] = 3.5;
	for(int i=1; i<n; i++)
	{
		double s = 6., best = 5., c = 1.;
		while( best>v[i-1] ) {
			s += best;
			best -= 1.0;
			c += 1.0;
		}
		v[i] = (s + (6. - c) * v[i-1]) / 6.0;
	}
	fout << setprecision(8) << v[n-1];

	return 0;
}