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
#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "magic.in" 
#define OUTFILE "magic.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int x, n, n2, maxn;
map<int,pair<int,int> > m;
int pow2[] = {1,2,4,8,16,32};
int mat[5][5];
int md[5][5];
int cnt = 0;
char afis[] = {'1', '9'};
bool go = 1;

void printm()
{
  /*REP(i, n)
  {
    REP(j, n)
      fout << mat[i][j] << " ";
    fout << endl;
  }fout << endl;*/

  for(int i=1; i<=2*n; i++)
  {
    int r = m[i].first;
    int o = m[i].second;
    for(int j=0; j<n; j++)
      if( r==0 ) fout << afis[mat[o][j]];// << " ";
      else        fout << afis[mat[j][o]];// << " ";
    //fout << endl;
  }
  fout << endl;
}

bool check(int rc, int x, int v, int cul)
{
  if( rc==0 )
  {
    for(int i=n-1; i>=0; i--)
    {
      if( md[x][i]<cul && mat[x][i]!=(v&1) )
        return false;
      if( md[x][i]==cul )
        mat[x][i] = (v&1);
      v = v>>1;
    }
  } 
  else 
  {
    for(int i=n-1; i>=0; i--)
    {
      if( md[i][x]<cul && mat[i][x]!=(v&1) )
        return false;
      if( md[i][x]==cul )
        mat[i][x] = (v&1);
      v = v>>1;
    }
  }
  return 1;
}

void afism()
{
  REP(i, n)
  {
    REP(j, n)
      cout << mat[i][j] << " ";
    cout << endl;
  }system("pause");
}

void back(int i, int lastv)
{
  //afism();
  if( !go ) return;
  if( i>2*n )
  {
    cnt++; 
    if( x==2 )
    {
      go = 0;
      printm();
    }
  }
  else
  {
    int r = m[i].first;
    int o = m[i].second;
    for(int j = lastv+1; j<maxn; j++)
    {
      if( check(r, o, j, i) )
        back(i+1, j);
    }
  }

}

int main()
{
  memset(mat, 0, sizeof(mat));
  memset(md, 0, sizeof(md));
  fin >> x >> n;
  for(int i=0; i<n; i++)
  {
    int r;
    fin >> r;
    m[r] = pair<int,int>(0, i);
  }
  for(int i=0; i<n; i++)
  {
    int c;
    fin >> c;
    m[c] = pair<int,int>(1,i);
  }
  maxn = pow2[n];

  for(int i=1; i<=2*n; i++)
  {
    int r = m[i].first;
    int o = m[i].second;
    if( r==0 )
    {
      for(int j=0; j<n; j++)
        if( md[o][j]==0 )
          md[o][j] = i;
    }
    else
    {
      for(int j=0; j<n; j++)
        if( md[j][o]==0 )
          md[j][o] = i;
    }

  }

  back(1,-1);

  if( x==1 ) fout << cnt << endl;
	
	return 0;
}