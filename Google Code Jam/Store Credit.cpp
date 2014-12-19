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
#define INFILE "A-large-practice.in" 
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

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
	  int c, i;
    fin >> c >> i;
    int aux;
    int v[2048] = {0};
    int a, b;
    REP(j, i)
    {
      fin >> aux;
      if( aux<c && v[c - aux]>0 )
      {
        a = v[c-aux];
        b = j + 1;
        while( (j+1)<i )
        {
          fin >> aux;
          j++;
        }
      }
      v[aux] = j + 1;
    }


		fout << "Case #" << r << ": ";
    fout << a << " " << b << endl;
	}
	
	return 0;
}