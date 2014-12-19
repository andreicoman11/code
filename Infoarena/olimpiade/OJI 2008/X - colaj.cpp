#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INFILE "colaj.in" 
#define OUTFILE "colaj.out"
#define DMAX 128
#define NMAX 256

struct drept{
  int xm, ym, xM, yM;
};

struct arb{
  int vl, vr;
  arb *l, *r;
  arb(int a, int b) : vl(a), vr(b), l(NULL), r(NULL) {}
};

drept d[DMAX];
int n, m, dno;
bool map[NMAX][NMAX];

void printmap()
{
  for(int j=0; j<m; j++)
  {
    for(int i=0; i<n; i++)    
      cout << map[m-j-1][i] << " ";
    cout << "\n";
  }cout << "\n";
}

void verifarb(arb* t, int x)
{
  arb* aux = t;
  t = t->r;
  delete aux;
  if( x>142 )
  {
    x = x+1-1;
  }
  while( t!=NULL )
  {
    for(int i=t->vl; i<t->vr; i++)
      map[i][x] = 1;
    aux = t;
    t = t->r;
    delete aux;
  }
}

void deltree(arb* t, int a, int b)
{
  t = t->r;
  while( t!=NULL && b > t->vl )
  {
    if( a<=t->vl && t->vr<=b )
    {
      t = t->l;
      arb* aux = t->r;
      t->r = aux->r;
      if( aux->r!=NULL ) aux->r->l = t;
      delete aux;
    }
    else if( t->vl<a && b<t->vr )
    {
      arb* aux = new arb(b, t->vr);
      t->vr = a;
      aux->r = t->r;
      if( aux->r!=NULL ) aux->r->l = aux;
      aux->l = t;
      t->r = aux;
      t = aux;
    }
    else if( t->vl<a && a<t->vr )
    {
      t->vr = a;
    }
    else if( t->vl<=b && b<t->vr )
    {
      t->vl = b;
    }

    t = t->r;
  }
}

void arbint(int x)
{
  arb *root = new arb(0, 0);
  root->r = new arb(0, m);
  root->r->l = root;
  for(int i=0; i<dno; i++)
    if( d[i].xm<=x && x < d[i].xM )
    {
      deltree(root, d[i].ym, d[i].yM);
    }
  verifarb(root, x);
}

void readd()
{
  set<int> x, y;
  x.insert(0);
  x.insert(n);
  y.insert(0);
  y.insert(m);
  for(int i=0; i<dno; i++)
  {
    cin >> d[i].xm >> d[i].ym >> d[i].xM >> d[i].yM;
    x.insert(d[i].xm);
    x.insert(d[i].xM);
    y.insert(d[i].ym);
    y.insert(d[i].yM);
  }

  int xi = 0;
  for(set<int>::iterator it=x.begin(); it!=x.end(); it++, xi++)
  for(int i=0; i<dno; i++)
  {
    if( d[i].xm==(*it) ) d[i].xm = xi;
    if( d[i].xM==(*it) ) d[i].xM = xi;
  }

  int yi = 0;
  for(set<int>::iterator it=y.begin(); it!=y.end(); it++, yi++)
  for(int i=0; i<dno; i++)
  {
    if( d[i].ym==(*it) ) d[i].ym = yi;
    if( d[i].yM==(*it) ) d[i].yM = yi;
  }
  n = x.size()-1;
  m = y.size()-1;
}

void paint(int x, int y)
{
  queue<pair<int,int> > q;
  q.push(make_pair(x, y));
  map[x][y] = 0;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  while( !q.empty() )
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int k=0; k<4; k++)
      if( x+dx[k]>=0 && x+dx[k]<m && y+dy[k]>=0 && y+dy[k]<n && map[x+dx[k]][y+dy[k]]==1)
      {
        q.push( make_pair(x+dx[k], y+dy[k]));
        map[x+dx[k]][y+dy[k]] = 0;
      }
  }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  memset(map, 0, sizeof(map));

  cin >> dno >> n >> m;

  readd();
  for(int i=0; i<n; i++)
  {
    arbint(i);
  }

  //printmap();

  int cul = 0;
  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
    if( map[j][i] )
    {
      cul++;
      paint(j, i);
    }
  cout << cul << "\n";

	return 0;
}
