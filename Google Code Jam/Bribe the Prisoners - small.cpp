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
#define MEM(v,x) memset(v, x, sizeof(v))
#define INFILE "C-small-practice.in" 
#define OUTFILE "C-small.out"

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
ofstream fout (OUTFILE);

int p, q, mm;

void back(int i, int c[], int s, VI v)
{
	if( i>=q )
	{
		if( s<mm ) mm = s;
	}
	else
	{
		REP(j, v.SZ)
			if( c[v[j]] )
			{
				c[v[j]] = 0;
				//cout << c[v[j]] << " " << c[v[j]+1] << " " << c[v[j]-1] << endl;
				int s2 = s;
				for(int k = v[j]+1; k<p && c[k]; k++)
					s2++;
				for(int k = v[j]-1;k>=0 && c[k]; k--)
					s2++;
				//cout << v[j] << " " << s2 << endl;
				back( i+1, c, s2, v);
				c[v[j]] = 1;
			}
	}
}

int main()
{
	int runs;
	fin >> runs;
	FOR( r, 1, runs+1)
	{
		fin >> p >> q;
		VI v(q);
		REP(i, q) 
		{
			fin >> v[i];
			v[i]--;
		}
		int c[10000];
		//MEM(c, 1);
		memset(c, -1, sizeof(c));
		mm = INT_MAX;
		back(0, c, 0, v);
		
		fout << "Case #" << r << ": ";
		fout << mm << endl;
	}
	
	return 0;
}