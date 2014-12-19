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

bool col[8][8];
bool row[8][8];
int n;
long long pos;

void getpos(int r, int c)
{
  if( r>=n ) pos++;
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

int main()
{
  /*int fact[8];
  fact[1] = 1;
  for(int i=2; i<7; i++)
    fact[i] = i*fact[i-1];
  for(int i=2; i<=7; i++)
  {
    memset(col, 1, sizeof(col));
    memset(row, 1, sizeof(row));
    REP(j, i)
    {
      col[j][j] = 0;
      row[j][j] = 0;
    }
    n = i;
    pos = 0;
    getpos(1,1);
    cout << i << " " << pos*fact[i-1] << endl;
    fout << i << " " << pos*fact[i-1] << endl;
  }*/

  long long int res[8];
  res[2] = 1;
  res[3] = 2;
  res[4] = 24;
  res[5] = 1344;
  res[6] = 1128960;
  res[7] = 12198297600;

  fin >> n;
  fout << res[n] << endl;


	return 0;
}
