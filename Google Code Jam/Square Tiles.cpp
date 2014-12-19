#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "A-large-practice.in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

char c[50][50];

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
	  int n, m;
    fin >> n >> m;
    REP(i, n)
    REP(j, m)
      fin >> c[i][j];

    int pos = 1;
    REP(i, n)
    REP(j, m)
      if( c[i][j]=='#' )
      {
        if( i+1<n && j+1<m && 
            c[i+1][j]=='#' && c[i][j+1]=='#' && c[i+1][j+1]=='#')
        {
          c[i][j] = c[i+1][j+1] = '/';
          c[i+1][j] = c[i][j+1] = '\\';
        }
        else pos = 0;
      }

		fout << "Case #" << r << ":\n";
    if( pos )
    {
      REP(i, n)
      {
        REP(j, m)
          fout << c[i][j];
        fout << endl;
      }
    }
    else fout << "Impossible\n";

	}
	
	return 0;
}