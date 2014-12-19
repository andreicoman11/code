/*
ID: andreic4
PROG: milk4
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
#define INFILE "milk4.in" 
#define OUTFILE "milk4.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);
#define ARRAYMAX 20001

int min(int x, int y)
{
  return x < y ? x : y;
}

int main()
{
  int d[ARRAYMAX], q, n, bestq;
  //v[][][] = index in nre of number inserted
  vector<set<set<char> > > v(ARRAYMAX);
  memset(d, 0, sizeof(d));
  fin >> q >> n;
  bestq = n+1;
  VI nre(n);
  REP(i, n)
  {
    fin >> nre[i];
    if( nre[i]==q )
    {
      fout << "1 " << q << endl;
      return 0;
    }
    if( nre[i]>q )
    {
      i--;
      n--;
      nre.resize(n);
    }
  }

  SORT(nre);

  REP(i, n)
  {
    if( q==15383  )
      fprintf(stderr, "%d ", i);
    int nr = nre[i];
    FOR(j, 1, q+1)
      if( j%nr==0 )
      {
        d[j] = 1;
        set<char> a;
        //a.insert(nr);
        a.insert(i);
        v[j].insert(a);
        if( j==q ) bestq = d[q] = 1;
      }
      else if( d[j]>0 && (j+nr==q || j+nr+nr<=q) && d[j]<=bestq )
      {
        if( d[j+nr]==0 ) d[j+nr] = d[j]+1;
        for(set<set<char> >::iterator it = v[j].begin(); it!=v[j].end(); it++)
          if( (int)it->sz<=bestq )
          {
            set<char> a = *it;
            //a.insert(nr);
            a.insert(i);
            d[j+nr] = min(d[j+nr], a.sz);
            v[j+nr].insert(a);
          }
          else
            v[j].erase(it);
        
        if( j+nr==q )
        {
          bestq = d[j+nr];
        }
      } else if( j+nr>q && j!=q )
        v[j].clear();
  }
  
  fout << bestq;
  for(set<set<char> >::iterator it=v[q].begin(); it!=v[q].end(); it++)
      if( (*it).sz==bestq )
      {
        for(set<char>::iterator it2=(*it).begin(); it2!=(*it).end(); it2++)
          fout << " " << nre[*it2];
        break;
      }

  fout << endl;

	return 0;
}
