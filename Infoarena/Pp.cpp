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
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "pp.in" 
#define OUTFILE "pp.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
  int n, k;
  fin >> n >> k;

  if(n==0)
  {
    fout << 0 << endl;
    return 0;
  }

  long long l = 1, r = k-1;
  bool win = 1;
  while( n > r )
  {
    l = ++r;
    if( win )
      r = r*2-1;
    else 
      r = r*k-1;
    win = !win;
    //cout << l << " " << r << " " << win << endl;
  }
  fout << win << endl;

	return 0;
}
