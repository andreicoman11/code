/*
ID: andreic4
PROG: fc
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
#define INFILE "fc.in" 
#define OUTFILE "fc.out"
#define MAX 100032
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, initp = 0;
long double x[MAX], y[MAX];
int idx[MAX];

// sortare dupa unghi
bool compangle(int a, int b)
{
  return ((x[a]-x[initp])*(y[b]-y[initp])) < ((x[b]-x[initp])*(y[a]-y[initp]));
}

// i1-i2-i3 clockwise or counter-clockwise
long double ccw(int initp, int a, int b)
{
  return (x[a]-x[initp])*(y[b]-y[initp]) - (x[b]-x[initp])*(y[a]-y[initp]);
}

long double dist(int i, int j)
{
  return sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
}

int main()
{
  fin >> n;
  REP(i, n)
  {
    fin >> x[i] >> y[i];
    if( x[i]<x[initp] || (x[i]==x[initp] && y[i]<y[initp] ))
      initp = i;
  }
  
  idx[0] = 1;
  REP(i, n)
    if( i!=initp )
      idx[ idx[0]++ ] = i;

  sort(idx + 1, idx + idx[0] + 1, compangle);
  
  int st[MAX];
  int stsize = 1;
  st[0] = initp;
  FOR(i, 1, idx[0]+1)
    if( idx[i]==initp ) continue;
    else
    {
      while( stsize>1 && ccw(st[stsize-2], st[stsize-1], idx[i])>=0 ) stsize--;
      st[stsize] = idx[i];
      stsize++;
    }

    while( ccw(st[stsize-2], st[stsize-1], st[0])>=0 )
    stsize--;


  /*for(int i=stsize-1; i>=0; i--)
    cout << x[st[i]] << " " << y[st[i]] << "\n";
  cout << endl;*/

  long double len = 0.0;
  for(int i=stsize-1; i>0; i--)
    len += dist(st[i], st[i-1]);
  len += dist(st[0], st[stsize-1]);
  fout << fixed << setprecision(2) << len << endl;

	return 0;
}
