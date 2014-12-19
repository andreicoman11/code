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
//#define INFILE ".in" 
#define INFILE "A-large-practice.in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int moves;
    fin >> moves;
    int steps = 0, t = 0;
    int po = 1, pb = 1, ot = 0, bt = 0;
    REP(i, moves)
    {
      char c;
      int pos;
      fin >> c >> pos;
      if( c=='O' )
      {
        int step = abs(pos - po);
        int tdif = t - ot;
        step = (tdif > step ? 0 : step-tdif);
        step++;
        steps += step;
        t += step;
        po = pos;
        ot = t;
      }
      else
      {
        int step = abs(pos - pb);
        int tdif = t - bt;
        step = (tdif > step ? 0 : step-tdif);
        step++;
        steps += step;
        t += step;
        pb = pos;
        bt = t;
      }
    }
	
		fout << "Case #" << r << ": " << steps << endl;
	}
	
	return 0;
}