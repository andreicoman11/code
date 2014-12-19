/*
ID: andreic4
PROG: snail
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
#define INFILE "snail.in" 
#define OUTFILE "snail.out"

#define U 0
#define L 1
#define D 2
#define R 3

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m[128][128], maxlen = 0;

void printmap()
{
  REP(i, n)
  {
    REP(j, n)
      if( m[i][j]>=0 ) cout << m[i][j] << " ";
      else cout << ". ";
    cout << endl;
  }
}

void search(int x, int y, int dir, int len);

int main()
{
  int b, d;
  char c;
  fin >> n >> b;
  memset(m, 0, sizeof(m));
  REP(i, b)
  {
    fin >> c;
    fin >> d;
    m[d-1][ int(c)-int('A')] = -1;
  }
  //printmap();

  m[0][0] = 1;
  search(0,0,D,1);
  search(0,0,R,1);

  fout << maxlen << endl;

	return 0;
}

void search(int x, int y, int dir, int len)
{
  //cout << "\n\n\n" << x << " " << y << " "<< dir << "    " << len << "\n\n";
  //printmap();system("pause");
  if( len>maxlen ) maxlen = len;
  if( dir==U )
  {
    if( x>0 && m[x-1][y]==0 )
    {
      // go snail
      int x2 = x-1;
      while( x2>=0 && m[x2][y]==0 )
      {
        m[x2][y] = 1;
        x2--;
        len++;
      }
      x2++;

      if( x2==0 || m[x2-1][y]==-1 )
      { // found edge or block
        search(x2, y, R, len);
        search(x2, y, L, len);
      }
      else // found own trail. stop
        maxlen = max(len, maxlen);

      // retreat snail
      while( x2<x )
      {
        m[x2][y] = 0;
        x2++;
      }
    }
  }
  else if( dir==D )
  {
    if( x<n-1 && m[x+1][y]==0 )
    {
      // go snail
      int x2 = x+1;
      while( x2<n && m[x2][y]==0 )
      {
        m[x2][y] = 1;
        x2++;
        len++;
      }
      x2--;

      if( x2==n-1 || m[x2+1][y]==-1 )
      { // found edge or block
        search(x2, y, R, len);
        search(x2, y, L, len);
      }
      else // found own trail. stop
        maxlen = max(len, maxlen);

      // retreat snail
      while( x2>x )
      {
        m[x2][y] = 0;
        x2--;
      }
    }
  }
  else if( dir==L )
  {
    if( y>0 && m[x][y-1]==0 )
    {
      // go snail
      int y2 = y-1;
      while( y2>=0 && m[x][y2]==0 )
      {
        m[x][y2] = 1;
        y2--;
        len++;
      }
      y2++;

      if( y2==0 || m[x][y2-1]==-1 )
      { // found edge or block
        search(x, y2, U, len);
        search(x, y2, D, len);
      }
      else // found own trail. stop
        maxlen = max(len, maxlen);

      // retreat snail
      while( y2<y )
      {
        m[x][y2] = 0;
        y2++;
      }
    }
  }
  else if( dir==R )
  {
    if( y<n-1 && m[x][y+1]==0 )
    {
      // go snail
      int y2 = y+1;
      while( y2<n && m[x][y2]==0 )
      {
        m[x][y2] = 1;
        y2++;
        len++;
      }
      y2--;

      if( y2==n-1 || m[x][y2+1]==-1 )
      { // found edge or block
        search(x, y2, U, len);
        search(x, y2, D, len);
      }
      else // found own trail. stop
        maxlen = max(len, maxlen);

      // retreat snail
      while( y2>y )
      {
        m[x][y2] = 0;
        y2--;
      }
    }
  }
}