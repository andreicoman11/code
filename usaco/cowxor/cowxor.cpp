/*
ID: andreic4
PROG: cowxor
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
#define INFILE "cowxor.in" 
#define OUTFILE "cowxor.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define BLEN 20

struct nod{
  int idx; // end of nr corresp 0->idx-1
  nod* l; // next val=0
  nod* r; // next val=1
  nod() : l(NULL), r(NULL), idx(-1) {}
};

nod* root;
const int blen = BLEN;
const int initpos = (1<<21);
int bestval, bestidx;

void init(int nr)
{
  int pos = initpos;
  nod* n = root;
  while( pos>0 )
  {
    int bit = nr&pos;
    if( bit==0 )
    {
      n->l = new nod();
      n = n->l;
    }
    else
    {
      n->r = new nod();
      n = n->r;
    }
    pos = pos>>1;
  }
  n->idx = 0;
}

void add(nod* n, int nr, int pos, int idx)
{
  if( pos==0 )
  {
    // reached the end of binary tree
    n->idx = idx;
  }
  else
  {
    int bit = nr&pos;
    if( bit==0 )
    {
      if( n->l==NULL )
        n->l = new nod();
      n = n->l;
    }
    else
    {
      if( n->r==NULL )
        n->r = new nod();
      n = n->r;
    }
    add(n, nr, pos>>1, idx);
  }
}

void findbestidx(nod* n, int nr, int pos, int val)
{
  if( pos==0 )
  {
    bestval = val;
    bestidx = n->idx;
  }
  else
  {
    int bit = nr&pos;
    if( (bit==0 && n->r!=NULL) || (n->l==NULL) )
    {
      // bit==0, go for next bit 1
      // going right is best or only option
      findbestidx(n->r, nr, pos>>1, (val<<1)+1);
    }
    else
    {
      findbestidx(n->l, nr, pos>>1, (val<<1)+0);
    }
  }
}

int main()
{
  int n;
  fin >> n;

  root = new nod();
  int i = 0, xors, nr;
  fin >> nr;
  xors = nr;
  init(nr);

  int tbestval = nr, tbests=0, tbeste=0;
  for(i=1; i<n; i++)
  {
    fin >> nr;
    xors ^= nr;

    // check for best candidate so far
    // == most equal to !xors
    findbestidx(root, xors, initpos, 0);

    //cout << i << " " << nr << "   " << xors << "   " << bestval << " " << bestidx << endl;
    bestval ^= xors;
    if( bestval>tbestval )
    {
      // needs better val because of higher rank
      tbestval = bestval;
      tbests = bestidx;
      tbeste = i;
    }

    // add it
    add(root, xors, initpos, i);
  }

  if( tbests==tbeste )  fout << tbestval << " " << tbests+1 << " " << tbeste+1 << endl;
  else                  fout << tbestval << " " << tbests+2 << " " << tbeste+1 << endl;

	return 0;
}
