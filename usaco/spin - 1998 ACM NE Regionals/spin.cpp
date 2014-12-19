/*
ID: andreic4
PROG: spin
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
#include <queue>
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
#define INFILE "spin.in" 
#define OUTFILE "spin.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
const int MOD = 360;
VVI v;
int start[5][5], move[5];

bool verif()
{
  int w[360];
  memset(w, 0, sizeof(w));
  for(int i=0; i<5; i++)
  for(int j=0; j<v[i].sz; j+=2 )
  {
    bool go = 0;
    for(int k=v[i][j]; !go; k++)
    {
      if( k==360 ) k=0;
      if( k==v[i][j+1] ) go = 1;
      w[k]++;
      if( w[k]==5 )
        return true;
    }
  }
  return false;
}

void gowheel()
{
  for(int i=0; i<5; i++)
  for(int j=0; j<v[i].sz; j++)
    v[i][j] = (v[i][j] + move[i])%MOD;
}

bool backtostart()
{
  for(int i=0; i<5; i++)
  for(int j=0; j<v[i].sz; j+=2)
    if( v[i][j*2]!=start[i][j] ) return false;
  return true;
}

int main()
{
  for(int i=0; i<5; i++)
  {
    VI aux;
    int k;
    fin >> move[i] >> k;
    REP(j, k)
    {
      int a, e;
      fin >> a >> e;
      e = (a+e) % MOD;
      aux.pb(a);
      aux.pb(e);
      start[i][j] = a;
    }
    v.pb(aux);
  }

  bool found = 0;
  int steps = 0;
  while( !found && steps<=360 )
  {
    found = verif();
    gowheel();
    steps++;
    if( backtostart() )
      break;
  }
  if( !found ) fout << "none\n";
  else        fout << steps-1 << endl;

	return 0;
}
