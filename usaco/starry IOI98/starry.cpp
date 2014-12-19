/*
ID: andreic4
PROG: starry
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
#include <queue>
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
#define INFILE "starry.in" 
#define OUTFILE "starry.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int sky[101][101], n, m;
int clsize[512] = {0};
int clhw[512][2] = {0};
int clpos[512][4] = {0};
int clxy[512][2] = {0};
int clno = 0;
int rec[101][101] = {0};

bool color(int i, int j, int change, int cul, bool add_cl);

void rever(int nn, int mm)
{
  int rec2[101][101] = {0};
  for(int i=nn; i>=0; i--)
  for(int j=mm; j>=0; j--)
    rec2[i][mm-j] = rec[i][j];

  memcpy(rec, rec2, sizeof(rec));
}

void rotate(int nn, int mm)
{
  int rec2[101][101] = {0};
  for(int i=nn; i>=0; i--)
  for(int j=mm; j>=0; j--)
    rec2[j][nn-i] = rec[i][j];

  memcpy(rec, rec2, sizeof(rec));
}

int check_clusters(int ext[4], int cul1, int pos[4], int cul2)
{
  int nn = ext[2] - ext[0];
  int mm = ext[3] - ext[1];
  REP(i, nn+1)
    memcpy( rec[i], sky[ext[0]+i] + ext[1], (ext[3]-ext[1]+1)*sizeof(int));

  int rot = 0, rev = 0, ok;
  while( rot<4 || rev<1 )
  {
    if( nn!=pos[2]-pos[0] || mm!=pos[3]-pos[1] )
    {
      rotate(nn, mm);
      rot++;
      swap(nn,mm);
    }

    if( rot>=4 )
    {
      rev++;
      rot = 0;
      rever(nn, mm);
    }

    ok = 1;
    for(int i=0; i<=nn && ok; i++)
    for(int j=0; j<=mm && ok; j++)
      if( (rec[i][j]==cul1 && sky[pos[0]+i][pos[1]+j]!=cul2) )//|| (rec[i][j]!=cul1 && sky[pos[0]+i][pos[1]+j]==cul2))
            ok = 0;
    if( ok ) return true;
    
    rotate(nn, mm);
    swap(nn,mm);
    rot++;
  }

  return false;
}

bool add_cluster(int x, int y, int clsz, int minx, int miny, int maxx, int maxy)
{
  int h = max(maxx - minx, maxy - miny);
  int w = min(maxx - minx, maxy - miny);
  int ext[4] = {minx, miny, maxx, maxy};
  bool found = 0;
  REP(i, clno)
    if( clsz==clsize[i] && h==clhw[i][0] && w==clhw[i][1] )
    {
      if( check_clusters( ext, sky[x][y], clpos[i] ,sky[clxy[i][0]][clxy[i][1]]) )
      {
        color(x, y, sky[x][y], sky[clxy[i][0]][clxy[i][1]], 0);
        found = 1;
        break;
      }
    }
  if( !found )
  {
    clsize[clno] = clsz;
    clhw[clno][0] = h;
    clhw[clno][1] = w;
    clpos[clno][0] = ext[0];
    clpos[clno][1] = ext[1];
    clpos[clno][2] = ext[2];
    clpos[clno][3] = ext[3];
    clxy[clno][0] = x;
    clxy[clno][1] = y;
    clno++;
    return true;
  }
  return false;
}

bool color(int i, int j, int change, int cul, bool add_cl)
{
  sky[i][j] = cul;
  queue<pair<int,int> > q;
  q.push(pair<int,int>(i,j));
  int maxx[2] = {i,j};
  int minn[2] = {i,j};
  int clsz = 1;
  while( !q.empty() )
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    maxx[0] = max(maxx[0], x);
    minn[0] = min(minn[0], x);
    maxx[1] = max(maxx[1], y);
    minn[1] = min(minn[1], y);
    
    FOR(a, x-1, x+2)
    FOR(b, y-1, y+2)
    if( a>=0 && b>=0 && a<n && b<m && sky[a][b]==change )
    {
      sky[a][b] = cul;
      q.push(pair<int,int>(a,b));
      clsz++;
    }
  }

  // add cluster
  if( add_cl )
    if( add_cluster( i, j, clsz, minn[0], minn[1], maxx[0], maxx[1] ) )
      return true;
  return false;
}

void printsky()
{
  REP(i,n)
  {
    REP(j,m)
      if( sky[i][j]==0 ) fout << 0;
      else fout << char(int('a')+sky[i][j]-1);

    fout << endl;
  }
}

void printsky2()
{
  REP(i,n)
  {
    REP(j,m)
      if( sky[i][j]==0 ) cout << 0;
      else if( sky[i][j]==-1 ) cout << '.';
      else cout << char(int('a')+sky[i][j]-1);
    cout << endl;
  }
  cout << endl << endl;
}

int main()
{
  fin >> m >> n;
  char c;
  REP(i,n)
  REP(j,m)
  {
    fin >> c;
    sky[i][j] = c=='0' ? 0 : -1;
  }

  int cul = 1;
  REP(i,n)
  REP(j,m)
    if( sky[i][j]==-1 )
    {
      if( color(i,j,-1, cul,1) )
        cul++;

      //printsky2();
      //system("pause");
    }

  printsky();

	return 0;
}
