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
#define INFILE "dictree.in" 
#define OUTFILE "dictree.out"
ofstream fout (OUTFILE);

unsigned long long int nods;

int main()
{
  FILE* fin = fopen(INFILE, "r");
  int n;
  fscanf(fin, "%d\n", &n);
  if( n==0 )
  {
    fout << 0 << endl;
    return 0;
  }
  char word[128];

  vector<string> vs(n);
  REP(i, n)
  {
    fscanf(fin, "%s\n", word);
    vs[i] = word;
  }

  SORT(vs);
  nods = 1 + vs[0].sz;

  FOR(i, 1, n)
  {
    int j = 0; // number of indexes that are the same
    while( j<(int)vs[i].sz && j<(int)vs[i-1].sz && vs[i][j]==vs[i-1][j] )
      j++;
    nods += vs[i].sz-j;
  }

  fout << nods << endl;
	
	return 0;
}
