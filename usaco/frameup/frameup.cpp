/*
ID: andreic4
PROG: frameup
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
#define INFILE "frameup.in" 
#define OUTFILE "frameup.out"
#define MAX 100
#define MIN -1
ifstream fin (INFILE);
ofstream fout (OUTFILE);

struct rect{
  int minx, miny;
  int maxx, maxy;
  rect() {
    minx = MAX;
    miny = MAX;
    maxx = MIN;
    maxy = MIN;
  }
};

char f[32][32] = {0};
vector<rect> corners(128);
int h, w;
int v[128] = {0};
vector<string> results;

set<char> readframe()
{
  fin >> h >> w;
  set<char> frames;
  REP(i, h)
  REP(j, w)
  {
    fin >> f[i][j];
    if( isalpha( f[i][j]) )
    {
      frames.insert( f[i][j] );
      corners[ f[i][j] ].minx = min( i, corners[ f[i][j] ].minx);
      corners[ f[i][j] ].miny = min( j, corners[ f[i][j] ].miny);
      corners[ f[i][j] ].maxx = max( i, corners[ f[i][j] ].maxx);
      corners[ f[i][j] ].maxy = max( j, corners[ f[i][j] ].maxy);
    }
  }
  return frames;
}

void printframe()
{
  REP(i, h)
  {
    REP(j, w)
      cout << f[i][j];
    cout << endl;
  }
  cout << endl;
}

void elim_rectangle(int i, int j, int x, int y)
{
  for(int col=j; col<=y; col++)
  {
    f[i][col] = '*';
    f[x][col] = '*';
  }

  for(int row=i; row<=x; row++)
  {
    f[row][j] = '*';
    f[row][y] = '*';
  }
}

bool find_rectangle(char c, int i, int j, int x, int y)
{
  for(int col=j; col<=y; col++)
    if( (f[i][col]!=c && f[i][col]!='*') ||
        (f[x][col]!=c && f[x][col]!='*') )
        return false;

  for(int row=i; row<=x; row++)
    if( (f[row][j]!=c && f[row][j]!='*') ||
        (f[row][y]!=c && f[row][y]!='*') )
        return false;

  return true;
}

void get_top(int i, string frames, string res)
{
  if( i>=(int)frames.sz )
  {
    //fout << res << endl;
    results.pb(res);
  }
  for(int j=0; j<(int)frames.sz; j++)
    if( v[frames[j]]==0 && 
      find_rectangle(frames[j], corners[frames[j]].minx, corners[frames[j]].miny,
                                corners[frames[j]].maxx, corners[frames[j]].maxy) )
    {
      char f2[32][32];
      memcpy(f2, f, sizeof(f));
      v[frames[j]] = 1;
      elim_rectangle(corners[frames[j]].minx, corners[frames[j]].miny, 
                      corners[frames[j]].maxx, corners[frames[j]].maxy);
      
      //cout << "found " << frames[j] << endl;
      //printframe();
      get_top(i+1, frames, (frames[j])+res);
      memcpy(f, f2, sizeof(f));
      v[frames[j]] = 0;
    }
}

int main()
{
  set<char> frame = readframe();
  string frames = "";
  for(set<char>::iterator it=frame.begin(); it!=frame.end(); it++)
    frames += (*it);

  get_top(0, frames, "");

  SORT(results);
  REP(i, results.sz)
    fout << results[i] << endl;

	return 0;
}
