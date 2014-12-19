#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define pb push_back
#define sz size()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "B-large-practice.in" 
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

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int x[50] = {0};
int v[50] = {0};

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n, k, b, t;
    int moves = 0;
    fin >> n >> k >> b >> t;
    REP(i, n)
      fin >> x[i];
    REP(i, n)
      fin >> v[i];

    int skiped = 0;

    for(int i = n-1; k>0 && i>=0; i--)
    {
      if( x[i] + v[i]*t >= b )
      { // reaches destination
        k--;
        // do we need to skip any chicks?
        moves += skiped;
      }
      else
      {// chick needs to pe skiped
        skiped++;
      }
    }

		fout << "Case #" << r << ": ";
    if( k>0 ) fout << "IMPOSSIBLE\n";
    else fout << moves << endl;
	}
	
	return 0;
}