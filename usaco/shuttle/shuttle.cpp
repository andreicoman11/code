/*
ID: andreic4
PROG: shuttle
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
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "shuttle.in" 
#define OUTFILE "shuttle.out"
#define MAX 1024

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n;
int moves[MAX] = {0};
int b[32] = {0};

bool dfs(int hole, int i)
{
  if( hole==n )
  {
    // check if sol found
    bool ok = 1;
    for(int j=0; j<n && ok; j++)
      if( b[j]!=2 ) ok = 0;

    for(int j=n+1; j<=2*n && ok; j++)
      if( b[j]!=1 ) ok = 0;

    if( ok )
    {
      // first sol found
      REP(j, i)
      {
        fout << moves[j]+1;
        if( (j+1)%20==0 ) fout << endl;
        else if( j+1<i ) fout << " ";
      }
      if(i%20) fout << endl;
      return 1;
    }
  }

  if( hole>0 )
  {
    if( b[hole-1]==1 )
    { // move white to right
      b[hole-1] = 0;
      b[hole] = 1;
      moves[i] = hole-1;
      if( dfs(hole-1, i+1) ) return 1;
      b[hole-1] = 1;
      b[hole] = 0;
    }
    else if( hole>1 && b[hole-2]==1 )
    { // jump white over black
      b[hole-2] = 0;
      b[hole] = 1;
      moves[i] = hole-2;
      if( dfs(hole-2, i+1) ) return 1;
      b[hole-2] = 1;
      b[hole] = 0;
    }
  }

  if( hole<2*n )
  {
    if( b[hole+1]==2 )
    { // move black to right
      b[hole+1] = 0;
      b[hole] = 2;
      moves[i] = hole+1;
      if( dfs(hole+1, i+1) ) return 1;
      b[hole+1] = 2;
      b[hole] = 0;
    }
    else if( hole<2*n-1 && b[hole+2]==2 )
    { // jump black over white
      b[hole+2] = 0;
      b[hole] = 2;
      moves[i] = hole+2;
      if( dfs(hole+2, i+1) ) return 1;
      b[hole+2] = 2;
      b[hole] = 0;
    }
  }
  return 0;
}

int main()
{
  fin >> n;
  REP(i, n)
    b[i] = 1;
  FOR(i, n+1, 2*n+1)
    b[i] = 2;

  dfs(n, 0);

	return 0;
}
