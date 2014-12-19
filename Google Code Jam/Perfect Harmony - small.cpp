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
#define INFILE "C-small-practice.in" 
#define OUTFILE ".out-good"

ifstream fin (INFILE);
ofstream fout (OUTFILE);


int n, h, l;
int f[100];

bool verif(int x)
{
  REP(i, n)
    if( f[i]%x>0 && x%f[i]>0 )
      return 0;
  return 1;
}

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    fin >> n >> l >> h;
    REP(i, n)
      fin >> f[i];

    bool found = 0;
    while( !found && l<=h )
    {
      if( verif(l) )
        found = 1;
      else l++;
    }
	
		fout << "Case #" << r << ": ";
    if( found ) fout << l << endl;
    else        fout << "NO\n";
	}
	
	return 0;
}