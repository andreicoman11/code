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
#define MAX 128
ifstream fin (INFILE);
ofstream fout (OUTFILE);

char w[MAX][MAX];
int g[MAX][2];
double wp[MAX], owp[MAX], oowp[MAX];

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    memset(w, 0, sizeof(w));
    int n;
    fin >> n;
    REP(i, n)
    REP(j, n)
    {
      fin >> w[i][j];
    }

    REP(i, n)
    {
      int p = 0, won = 0;
      REP(j, n)
        if( w[i][j]=='0' ) p++;
        else if( w[i][j]=='1' ) {p++; won++;}
      g[i][0] = won;
      g[i][1] = p;
      wp[i] = (double)won / (double)p;
    }

    REP(i, n)
    {
      double ow = 0.0;
      REP(j, n)
        if( w[i][j]!='.' )
        {
          ow += (double)(g[j][0] - (w[j][i]=='1' ? 1 : 0) ) / (double)(g[j][1]-1);
        }
      ow /= (double)g[i][1];
      owp[i] = ow;
    }

    REP(i, n)
    {
      double oow = 0.0;
      REP(j, n)
        if( w[i][j]!='.' )
        {
          oow += owp[j];
        }
      oow /= (double)g[i][1];
      oowp[i] = oow;
    }

  	fout << "Case #" << r << ":\n";
    REP(i, n)
    {
      fout << 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i] << endl;
    }
	}
	
	return 0;
}