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
#define INFILE "C-large-practice.in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n;
    int v[1024];
    fin >> n;
    int sum = 0, xsum = 0, min = -1;
    REP(i, n)
    {
      fin >> v[i];
      sum += v[i];
      xsum ^= v[i];
      if( min==-1 || min>v[i] )
        min = v[i];
    }

    fout << "Case #" << r << ": ";
    if( xsum>0 )  fout << "NO\n";
    else          fout << sum-min << endl;
	
		
	}
	
	return 0;
}