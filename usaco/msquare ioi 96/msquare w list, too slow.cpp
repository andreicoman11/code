/*
ID: andreic4
PROG: msquare
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
#define INFILE "msquare.in" 
#define OUTFILE "msquare.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define HASHSZ 2097152 
const int MOD = HASHSZ;
const int hashinit = 5381;

bool h[HASHSZ];
int hnr[] = {99901, 99907, 99923, 99929, 99961, 99971, 99989, 99991};
int hnr2[] = {2, 3, 5, 7, 11, 13, 17, 19};
int target[8];

struct nod{
  int *v;
  string s;
};

int gethash(int *v)
{
  long long nr = 0;//hashinit;
  for(int i=0; i<8; i++)
    nr = ((nr<<3) + v[i]);
  return nr % MOD;
}

int* getM(int move, int v[8])
{
  int *x = new int[8];
  if( move==0 )
  {
    for(int i=0; i<8; i++)
      x[i] = v[7-i];
  }
  else if( move==1 )
  {
    x[0] = v[3], x[1] = v[0], x[2] = v[1], x[3] = v[2];
    x[4] = v[5], x[5] = v[6], x[6] = v[7], x[7] = v[4];
  }
  else if( move==2 )
  {
    x[0] = v[0], x[1] = v[6], x[2] = v[1], x[3] = v[3];
    x[4] = v[4], x[5] = v[2], x[6] = v[5], x[7] = v[7];
  }
  return x;
}

bool checktarget(int *x)
{
  for(int i=0; i<8; i++)
    if( x[i]!=target[i] ) 
      return false;
  return true;
}

int main()
{
  memset(h, 0, sizeof(h));
  string move = "ABC";
  for(int i=0; i<8; i++)
  {
    fin >> target[i];
    target[i]--;
  }

  nod n;
  n.v = new int[8];
  for(int i=0; i<8; i++)
    n.v[i] = i;
  n.s = "";

  list<nod> l;
  l.pb(n);
  h[gethash(n.v)] = 1;

  bool found = checktarget(n.v);
  string res;
  int *x;
  //int steps = 0;
  while( !found )
  {
    if( l.sz==0 ) break;
    n = l.front();
    l.pop_front();
    //steps++;

    for(int j=0; j<3; j++)
    {
      x = getM(j, n.v);
      if( h[gethash(x)]==0 )
      {
        h[gethash(x)] = 1;
        if( checktarget(x) )
        {
          found = 1;
          res = n.s + move[j];
        }
        nod m;
        m.v = x;
        m.s = n.s + move[j];
        l.pb(m);
      }
    }
  }

  //cout << steps << endl;
  //cout << found << endl;
  fout << res.sz << endl << res << endl;

	return 0;
}
