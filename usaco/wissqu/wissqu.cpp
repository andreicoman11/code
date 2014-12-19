/*
ID: andreic4
PROG: wissqu
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
#define INFILE "wissqu.in" 
#define OUTFILE "wissqu.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define n 5
#define A 'A'
#define B 'B'
#define C 'C'
#define D 'D'
#define E 'E'

char p[6][6];
bool can_p[6][6];
int ways = 0;
int to_place[] = {3,3,3,3,3};
int path[16][3] = {0};
int herds[] = {A,B,C,D,E};

bool can_place(int i, int j, char h)
{
  FOR(x, i-1, i+2)
  FOR(y, j-1, j+2)
    if( p[x][y]==h ) return false;
  return true;
}

void search(int left)
{
  if( left==0 )
  {
    ways++;
    if( ways==1 )
    {
      REP(i, 16)
        fout << char(path[i][0]) << " " << path[i][1] << " " << path[i][2] << endl;
    }
  }
  else
  {
    REP(k, 5)
      if( to_place[k] )
      FOR(i, 1, n)
      FOR(j, 1 ,n)
        if( can_p[i][j] && can_place(i, j, herds[k]) )
        {
          char cell = p[i][j];
          p[i][j] = herds[k];
          to_place[k]--;
          
          path[16-left][0] = herds[k];
          path[16-left][1] = i;
          path[16-left][2] = j;
          can_p[i][j] = 0;

          search(left-1);
          p[i][j] = cell;
          to_place[k]++;
          can_p[i][j] = 1;
        }
  }
}

int main()
{
  memset(p, 0, sizeof(p));
  memset(can_p, true, sizeof(can_p));
  FOR(i, 1, n)
  FOR(j, 1, n)
    fin >> p[i][j];

  FOR(i, 1, n)
  FOR(j, 1, n)
    if( can_place(i,j,D) )
    {
      char cell = p[i][j];
      p[i][j] = D;
      path[0][0] = D;
      path[0][1] = i;
      path[0][2] = j;
      can_p[i][j] = 0;

      search(15);
      p[i][j] = cell;
      can_p[i][j] = 1;
    }

  fout << ways << endl;

	return 0;
}
