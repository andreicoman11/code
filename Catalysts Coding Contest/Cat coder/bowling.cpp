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
#define INFILE ".in" 
#define OUTFILE ".out"

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

FILE* fin = fopen(INFILE, "r");
FILE* fout = fopen(OUTFILE, "w");

int main()
{
	int r, score;
	int p[1024] = {0};
	char c;
	char buf[1024];
	while( fscanf(fin, "%d", &r)>0 )
	{
		score = 0;
		fscanf(fin, "%c", &c);
		//cout << r << c << endl;
		for(int i=0; c!='\n'; i++ )
		{
			fscanf( fin, "%d%c", &p[i], &c);
			//cout << p[i] << c << endl;
		}
		
		int j = 0;
		FOR(i,0,r)
		{
			if( p[j]!= 10 )
			{
				score += p[j] + p[j+1];
				if( p[j]+p[j+1]==10 ) score += p[j+2];
				j+=2;
			}
			else 
			{
				score += p[j] + p[j+1] + p[j+2];
				j++;
			}
			fprintf(fout, "%d", score);
			if( i+1<r) fprintf(fout, ",");
		}
		fprintf(fout, "\n");
	}
	
	return 0;
}