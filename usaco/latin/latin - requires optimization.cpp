/*
ID: andreic4
PROG: latin
LANG: C++
*/
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
#define INFILE "latin.in" 
#define OUTFILE "latin.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int fact[8], n;
bool col[8][8];
bool row[8][8];
long long pos;

void getpos(int r, int c)
{
  if( r>=n-1 ) pos++;
  else
  {
    for(int j=0; j<n; j++)
      if( col[c][j]==1 && row[r][j]==1 )
      {
        col[c][j] = 0;
        row[r][j] = 0;
        if( c==n-1 )  getpos(r+1, 1);
        else          getpos(r, c+1);
        col[c][j] = 1;
        row[r][j] = 1;
        
      }
  }
}

long long solve()
{
  memset(col, 1, sizeof(col));
  memset(row, 1, sizeof(row));
  REP(j, n)
  {
    col[j][j] = 0;
    row[j][j] = 0;
  }

  pos = 0;
  row[1][2] = col[1][2] = 0;
  getpos(1,2);
  long long totalpos = pos * (n-2);

  pos = 0;
  row[1][2] = col[1][2] = 1;
  row[1][0] = col[1][0] = 0;
  getpos(1,2);
  
  return (totalpos + pos) * fact[n-1];
}

int main()
{
  fact[1] = 1;
  for(int i=2; i<7; i++)
    fact[i] = i*fact[i-1];

  fin >> n;
  long long tpos = solve();
  fout << tpos << endl;

	return 0;
}
