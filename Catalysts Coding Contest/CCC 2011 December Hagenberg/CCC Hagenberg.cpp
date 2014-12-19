#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define LL long long
#define pb push_back
#define sz size()

#define INFILE ".in" 
#define OUTFILE ".out"

char dir;
int map[512][512];
int map2[512][512];
int mapid[512][512];
int n, m;
int pairs;
int bright[128] = {0};
int idof[128] = {0};
int allcr[128][2], crno;

struct cr{
  int x1, y1;
  int x2, y2;
};

cr moon[128];

void findrect(int cul, bool printit)
{
  int x = n, y = m, dx=0, dy=0;
  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
    if( map[i][j]==cul )
    {
      x = min(x, i-1);
      y = min(y, j-1);
      dx = max(dx, i+1);
      dy = max(dy, j+1);
    }
  moon[cul].x1 = x;
  moon[cul].y1 = y;
  moon[cul].x2 = dx;
  moon[cul].y2 = dy;
  if(printit)
  {
    if( dir=='l' )
    {
      y = m-1-y;
      dy = m-1-dy;
      if( y>dy )
      {
        int aux = y;
        y = dy;
        dy = aux;
      }
    }
    if( dir=='t' )
    {
      //cout << x << " " << y << " " << dx << " " << dy << "\n";
      y = m-1-y;
      dy = m-1-dy;
      int aux = x;
      x = y;
      y = aux;
      aux = dx;
      dx = dy;
      dy = aux;
      if( y>dy )
      {
        int aux = y;
        y = dy;
        dy = aux;
      }
      if( x>dx )
      {
        int aux = x;
        x = dx;
        dx = aux;
      }
      //cout << x << " " << y << " " << dx << " " << dy << "\n";
    }
    if( dir=='b' )
    {
      x = n-1-y;
      dx = n-1-dy;
      int aux = x;
      x = y;
      y = aux;
      aux = dx;
      dx = dy;
      dy = aux;
      if( x>dx )
      {
        int aux = x;
        x = dx;
        dx = aux;
      }
    }
   cout << " " << y << " " << x << " " << dy-y << " " << dx-x;
  }
}

void elimcr()
{
  //cout << n << " " << m;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      bool found = 0;
      for(int k=0; k<crno; k++)
        if( map[i][j]==allcr[k][0] || map[i][j]==allcr[k][1] )
        {
          map[i][j] = k+1;/*cout << " 1";*/
          found = 1;
        }
      if( !found ) map[i][j] = 0;/*cout << " 0";*/
    }
    //cout << "\n";
  }
}

void findsame(set<int> ids)
{
  vector<int> vid(ids.begin(), ids.end());
  for(int i=0; i<vid.sz; i++)
    findrect(vid[i], 0);

  crno = 0;
  for(int ii=0; ii<vid.sz; ii++)
  for(int jj=ii+1; jj<vid.sz; jj++)
  {
    int i = vid[ii], j = vid[jj];
    if( moon[i].x1==moon[j].x1 && moon[i].x2==moon[j].x2 && 
        (bright[i]-bright[j]) * (moon[i].y1 - moon[j].y1)<0 /*&&
        (abs(moon[i].y2 - moon[j].y1)<4 || abs(moon[i].y1 - moon[j].y2)<4 )*/
        )
    {
      allcr[crno][0] = i;
      allcr[crno][1] = j;
      crno++;
    }
  }

  elimcr();
}

void read2()
{
  cin >> n >> m;
  set<int> ids;
  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
  {
    cin >> map[i][j];
    if( map[i][j]>0 ) ids.insert(map[i][j]);
  }

  cin >> pairs;
  for(int i=0; i<pairs; i++)
  {
    int ID;   
    cin >> ID;
    cin >> bright[ID];
  }

  findsame(ids);
}

void print3(int allids)
{
  cout << n << " " << m;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cout << " " << mapid[i][j];
    }
    //cout << "\n";
  }
  cout << " " << allids-1;
  for(int i=1; i<allids; i++)
    cout << " " << i << " " << bright[i];
}

void printmap()
{
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cout << " " << map[i][j];
    }
    cout << "\n";
  }
}

void gocol(int x, int y, int mapcol, int lastid)
{
  mapid[x][y] = lastid;
  queue<int> xx, yy;
  xx.push(x);
  yy.push(y);
  while( !xx.empty() )
  {
    x = xx.front(); xx.pop();
    y = yy.front(); yy.pop();
    for(int i=-1; i<2; i++)
    for(int j=-1; j<2; j++)
      if( i*j==0 && i+x>=0 && j+y>=0 && x+i<n && y+j<m && mapid[x+i][y+j]==0 && map[x+i][y+j]==mapcol )
      {
        xx.push(x+i);
        yy.push(y+j);
        mapid[x+i][y+j] = lastid;
      }
  }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  memset(map, 0, sizeof(map));
  memset(map2, 0, sizeof(map2));
  memset(mapid, 0, sizeof(mapid));
  
  cin >> n >> m;
  int lastid = 1;
  memset(bright, 0, sizeof(bright));
  memset(idof, 0, sizeof(idof));

  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
  {
    cin >> map[i][j];
  }

  cin >> dir;//cout << dir << "\n";
  //printmap();
  if( dir=='l' )
  {
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      map2[i][j] = map[i][m-1-j];
    memcpy(map,map2, sizeof(map));
  }
  else if( dir=='t' )
  {
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      map2[j][n-1-i] = map[i][j];

    memcpy(map,map2, sizeof(map));
    int aux = n;
    n = m;
    m = aux;
  }
  else if( dir=='b' )
  {
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      map2[m-1-j][i] = map[i][j];

    memcpy(map,map2, sizeof(map));
    int aux = n;
    n = m;
    m = aux;
  }
  //cout <<"\n";printmap();cout <<"\n";

  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
    if( map[i][j]>0 && mapid[i][j]==0 )
    {
      bright[lastid] = map[i][j];
      gocol(i, j, map[i][j], lastid);
      lastid++;
    }

  memcpy(map, mapid, sizeof(map));
  //print3(lastid);
  //printmap();
  set<int> ids;
  for(int i=1; i<lastid; i++)
    ids.insert(i);
  findsame(ids);
  printmap();
  cout << crno;
  for(int i=0; i<crno; i++)
  {
    findrect(i+1, 1);
  }

	return 0;
}
