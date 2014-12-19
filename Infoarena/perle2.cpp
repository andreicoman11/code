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
#define INFILE "perle2.in" 
#define OUTFILE "perle2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
  int n, k;
  fin >> n >> k;
  int bests = 0;
  int s = 0;
  REP(i, n)
  {
    int a;
    fin >> a;
    a -= k;
    s += a;
    if( s>bests ) bests = s;
    if( s<0 ) s = 0;
  }

  fout << bests << endl;
	
	return 0;
}