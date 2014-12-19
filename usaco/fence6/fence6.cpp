/*
ID: andreic4
PROG: fence6
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
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
#define REVERSE(X) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "fence6.in" 
#define OUTFILE "fence6.out"
#define MAXP 26000

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int N;
int minp = MAXP;

struct seg{
  int len;
  int n[2][9];// 0i - left, 1i - right
              // i0 - number of neigh on side i
};

// all segments
seg v[128];
// i,j = connection type (-1, 0->3)
int map[128][128];
// find connection between i,j as:
// k,i,j, k: l,l -> l,r -> r,l, r->r
int get_seg[4][128][128];



void dfs(int seg_to_go, int i, int tlen, int segm_puse[128][2], bool x[128])
{
  int a, b, end;
  if( seg_to_go==1 )
  {
    // check for connecting segment
    a = segm_puse[0][0];
    int end1 = segm_puse[0][1];
    b = segm_puse[i-1][0];
    int end2 = 1 - segm_puse[i-1][1];

    int lastseg = get_seg[ 2*end1 + end2 ][a][b];
    if( lastseg>=0 && tlen + v[lastseg].len<minp )
      minp = tlen + v[lastseg].len;

    /*REP(j,i)
      cout << segm_puse[j][0] << " ";
    cout << " " << lastseg << "\t\t" << tlen << "\n";*/

  }
  else
  {
    a = segm_puse[i-1][0];
    end = 1 - segm_puse[i-1][1];
    // traverse neighbours on other segment end
    FOR(j, 1, v[a].n[end][0]+1)
    {
      b = v[a].n[end][j];
      if( x[b]==false && minp > tlen + v[b].len )
      {
        segm_puse[i][0] = b;
        segm_puse[i][1] = map[a][b]%2;
        x[b] = true;
        dfs(seg_to_go-1, i+1, tlen + v[b].len, segm_puse, x);
        x[b] = false;
      }
    }
  }
}  

int main()
{
  fin >> N;
  memset( map, -1, sizeof(map));
  int id, a, b;
  REP(i, N)
  {    
    fin >> id;
    fin >> v[id].len >> v[id].n[0][0] >> v[id].n[1][0];
    REP(j, v[id].n[0][0] )
    {
      fin >> v[id].n[0][j+1];
      a = id;
      b = v[id].n[0][j+1];
      if( map[a][b]==-1 )
      { // set initial settings
        map[a][b] = 0;
        map[b][a] = 0;
      }
      else
      {
        // nothing, since we would have to add 0 for l
      }
    }
    REP(j, v[id].n[1][0] )
    {
      fin >> v[id].n[1][j+1];
      a = id;
      b = v[id].n[1][j+1];
      if( map[a][b]==-1 )
      {
        map[a][b] = 2;
        map[b][a] = 1;
      }
      else
      {
        map[a][b] += 2;
        map[b][a] += 1;
      }
    }
  }

  // set segments to corresp values
  memset(get_seg, -1, sizeof(get_seg));
  FOR(i, 1, N+1)
  FOR(j, 1, N+1)
  FOR(k, 1, N+1)
    if( i!=k && j!=k && map[i][k] > -1 && map[k][j] > -1)
    {
      int end1 = map[i][k]/2;
      int end2 = map[k][j]%2;
      int kend = map[i][k]%2;
      bool ok = true;
      FOR(ii, 1, v[k].n[kend][0]+1)
        if( v[k].n[kend][ii]==j ) ok = false;

      if( ok )
        get_seg[ 2*end1 + end2 ][i][j] = k;
    }

  /*FOR(k, 0, 4)
  {
    cout << k << "\n";
    REP(i, N+1)
    {
      REP(j, N+1)
        if( get_seg[k][i][j]>-1 )
          cout << i << " " << j << " " << get_seg[k][i][j] << endl;
    }
    cout << "\n\n";
  }*/


  int segm_puse[128][2] = {0};
  bool x[128] = {false};
  // start looking for perimeters of size at least 3
  FOR(i, 3, N+1)
  {
    FOR(j, 1, N+1)
    {
      segm_puse[0][0] = j;
      x[j] = true;

      segm_puse[0][1] = 0;
      dfs(i-1, 1, v[j].len, segm_puse, x);
      //cout << "\n\n";

      segm_puse[0][1] = 1;
      dfs(i-1, 1, v[j].len, segm_puse, x);
      //cout << "\n\n";

      x[j] = false;
    }
    //cout << i << " " << minp << endl;
  }

  fout << minp << endl;


	return 0;
}
