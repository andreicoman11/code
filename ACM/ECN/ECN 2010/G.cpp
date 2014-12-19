#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "g.in" 
#define OUTFILE "g.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int N;
	fin >> N;
	while(N--)
	{
		string f;
		fin >> f;
		int n, m;
		fin >> n >> m;
		int max = 0, maxi = 0, maxj = 0;
		REP(i, m)
		{
			int v[256] = {0};
			REP(j, n)
			{
				char c = f[j*m+i];
				//cout << i << " " << j << " " << c << endl;
				v[ int(c) ]++;
				if( v[ int(c) ]>max )
				{
					max = v[ int(c) ];
					maxi = i;
					maxj = j;
					//cout << max << " " << i << " " << j << endl;
				}
			}
		}
		fout << maxi+1 << " " << max << " " << f[maxj*m+maxi];
		if(N) fout << endl;
	}
	
	return 0;
}