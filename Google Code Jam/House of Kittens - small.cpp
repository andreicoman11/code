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
#define INFILE2 ".in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int w[8][2], r[10][10];
int rooms, n,m;
int rez[8];

bool check(int v[8], int minr)
{
  for(int i=0; i<=m; i++)
  for(int j=0; j<minr; j++)
  {
    int found = 0;
    for(int k = 1; k<=r[i][0]; k++)
      if( v[r[i][k]]==j ) found = 1;
    if( !found) return false;
  }
  return true;
}

bool back(int i, int v[8], int minr)
{
  if( i>=n )
  {
    if( check(v, minr) )
    {
      memcpy(rez, v, sizeof(rez));
      return true;
    }
  }
  else
  {
    for(int j=0; j<minr; j++)
    {
      v[i] = j;
      if( back(i+1, v, minr) ) return true;
    }
  }
  return false;
}

int main()
{
	int runs;
	fin >> runs;
	for(int R = 1; R<=runs; R++)
	{
    fin >> n >> m;

    REP(k, 2)
    REP(i, m)
    {
      fin >> w[i][k];
      w[i][k]--;
    }

    for(int i=1; i<=n; i++)
      r[0][i] = i-1;
    r[0][0] = n;
    rooms = 1;

    REP(i, m)
    {
      REP(j, rooms)
      {
        int found = 0;
        for(int k=1; k<=r[j][0]; k++)
          if( r[j][k]==w[i][0] || r[j][k]==w[i][1] )
            found++;
        if( found==2 )
        {
          // room j will be split in 2
          int r2[2][10] = {0};
          r2[0][0] = r2[1][0] = 2;
          r2[0][1] = r2[1][1] = w[i][0];
          r2[0][2] = r2[1][2] = w[i][1];

          for(int k=1; k<=r[j][0]; k++)
            if( r[j][k]>w[i][0] && r[j][k]<w[i][1] )
            {
              r2[0][ ++r2[0][0] ] = r[j][k];
            }
            else if( r[j][k]<w[i][0] || r[j][k]>w[i][1] )
            {
              r2[1][ ++r2[1][0] ] = r[j][k];
            }

          memcpy( r[j], r2[0], sizeof( r2[0]) );
          memcpy( r[rooms], r2[1], sizeof( r2[1]) );
          rooms++;
          j = rooms;
        }
      }

    }

    int mincol = 8;
    REP(i, rooms)
      mincol = min(mincol, r[i][0]);

    int v[8] = {0};
    while( back(0, v, mincol)==0 )
    {
      memset(v, 0, sizeof(v));
      mincol--;
    }
	
		fout << "Case #" << R << ": " << mincol << endl;
    REP(i, n)
    {
      if( i ) fout << " ";
      fout << rez[i]+1;
    }
    fout << endl;
	}
	
	return 0;
}