/*
ID: andreic4
PROG: fence8
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "fence8.in" 
#define OUTFILE "fence8.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int N, R;
int r[1024];
int n[64];
int sums[1024] = {0};
int minindex[1024];

bool vr[1024];
bool vn[64];

int maxr = 0;
int bsum = 0;

void gogreedy(int n[64]);

bool dfsid(int i, int waste, int minj)
{
  //fout << i << "." << endl;
  if( i<0 )
    return true;
  else
  {
    /*if( vr[i]==1 )
    {
      if( dfsid(i-1, waste, 0) )
        return true;
      return false;
    }*/
    int oldwaste = waste, newj;
    // try to cut this rail from each given board
    FOR(j, max(minj, minindex[i]), N)
      if( r[i]<=n[j] /*&& vn[j]==0 && (j==0 || (n[j]!=n[j-1] && vn[j-1]==0))*/ )
      {
        n[j] -= r[i];
        // can I still use this board to cut another rail?
        if( i>0 && n[j]<r[0] )
        {
          // no, it's wasted
          if( waste >= n[j] )
            waste -= n[j];
          else
          {
            n[j] += r[i];
            continue;
          }
        }

        newj = 0;
        if( i>0 && r[i-1]==r[i] ) newj = j;

        //fout << i << "-" << j << "\n";
        if( dfsid(i-1, waste, newj) )
          return true;
        waste = oldwaste;
        n[j] += r[i];
      }
  }
  return false;
}

int main()
{
  fin >> N;
  int maxn = 0, j, aux;
  REP(i, N)
  {
    fin >> n[i];
    bsum += n[i];
    maxn = maxn < n[i] ? n[i] : maxn;
    // keep array sorted
    j = i;
    while( j>0 && n[j]<n[j-1] )
    {
      aux = n[j];
      n[j] = n[j-1];
      n[j-1] = aux;
      j--;
    }
  }

  VI r2(1024);
  fin >> R;
  REP(i, R)
  {
    fin >> r2[i];
    if( r2[i]>maxn )
    {
      i--;
      R--;
    }
  }

  // resize and sort rails
  r2.resize(R);
  SORT(r2);
  // compute sums of rails up to given index
  sums[0] = r2[0];
  FOR(i, 1, r2.sz)
    sums[i] = sums[i-1] + r2[i];

  REP(i, r2.sz)
  {
    r[i] = r2[i];
    int j = 0;
    while( r2[i]>n[j] )
      j++;
    minindex[i] = j;
  }

  // get out reasonable first guess
  gogreedy(n);

  // dfs with iterative deepening
  // use first k rails to see if we can obtain them
  // from the given boards
  int rez = maxr;
  int n2[64];

  // search for perfect matches
  /*memset(vr, 0, sizeof(vr));
  memset(vn, 0, sizeof(vn));
  REP(i, maxr)
  REP(j, N)
    if( vn[j]==0 && vr[i]==0 && r[i]==n[j] )
    {
      vr[i] = 1;
      vn[j] = 1;
    }*/

  memcpy( n2, n, 64*sizeof(int));
  FOR(k, maxr+1, R+1)
  {
    memcpy( n, n2, 64*sizeof(int));
    /*REP(j, N)
    if( vn[j]==0 && r[k]==n[j] )
    {
      vr[k] = 1;
      vn[j] = 1;
      break;
    }*/
    if( bsum < sums[k-1] )
      break;
    if( dfsid(k-1, bsum - sums[k-1], 0) )
    {
      rez = k;
      cout << rez << endl;
    }
    else break;
  }
  fout << rez << endl;

	return 0;
}

void gogreedy(int n[64])
{
  int n2[64];
  memcpy(n2, n, 64*sizeof(int));
  int i=0, j=0;

  while( i<N && j<R )
  {
    while( j<R && r[j]<=n2[i] ) 
    {
      n2[i] -= r[j];
      j++;
      maxr++;
    }
    i++;
  }
}
