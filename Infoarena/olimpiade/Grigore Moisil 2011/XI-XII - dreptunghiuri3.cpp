#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define INFILE "dreptunghiuri3.in" 
#define OUTFILE "dreptunghiuri3.out"
#define KMAX 1001
#define LMAX 3010

struct drept{
  int x, y, X, Y, v;
};

drept d[KMAX];
int a[LMAX][LMAX];
int n, m, k;
vector<int> vl, vc;
map<int, int> lmap, cmap;

void printa()
{
  cout << "x: ";
  for(int i=0; i<(int)vl.size(); i++)
    cout << vl[i] << " ";
  cout << "\ny: ";
  for(int i=0; i<(int)vc.size(); i++)
    cout << vc[i] << " ";
  cout << "\n\n";

  for(int i=(int)vc.size()-1; i>=0; i--)
  {
    for(int j=0; j<(int)vl.size(); j++)
      cout << setw(3) << a[i][j] << " ";
    cout << "\n";
  }cout << "\n";
}

LL getnr(int i, int j)
{
  //LL res = (i+1==vc.size() ? (m+1-vc[i]) : (vc[i+1]-vc[i]));
  //res *= (LL)(j+1==vl.size() ? (n+1-vl[j]) : (vl[j+1]-vl[j]));
  //return res;
  return (LL)(vl[i+1]-vl[i]) * (LL)(vc[j+1]-vc[j]);
}

void check(int i, int j, int& vmax, LL& nr)
{
  if( a[i][j]>vmax )
  {
    vmax = a[i][j];
    nr = getnr(i,j);
  }
  else if( a[i][j]==vmax ) 
    nr += getnr(i,j);
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  memset(a, 0, sizeof(a));

  set<int> l, c;
  cin >> n >> m >> k;
  for(int i=0; i<k; i++)
  {
    cin >> d[i].x >> d[i].y >> d[i].X >> d[i].Y >> d[i].v;
    l.insert(d[i].x);
    l.insert(d[i].X);
    l.insert(d[i].X+1);
    c.insert(d[i].y);
    c.insert(d[i].Y);
    c.insert(d[i].Y+1);
  }

  int cnt = 0;
  for(set<int>::iterator it=l.begin(); it!=l.end(); it++)
    lmap[*it] = cnt++;
  cnt = 0;
  for(set<int>::iterator it=c.begin(); it!=c.end(); it++)
    cmap[*it] = cnt++;

  vl = vector<int>(l.begin(), l.end());
  vc = vector<int>(c.begin(), c.end());

  int x1, x2, y1, y2;
  for(int i=0; i<k; i++)
  {
    x1 = lmap[d[i].x], x2 = lmap[d[i].X+1];
    y1 = cmap[d[i].y], y2 = cmap[d[i].Y+1];
    a[x1][y1] += d[i].v;
    a[x2][y2] += d[i].v;
    a[x1][y2] -= d[i].v;
    a[x2][y1] -= d[i].v;
  }

  //printa();
  int vmax = a[0][0];
  LL nr = getnr(0,0);
  for(int j=1; j<(int)c.size()-1; j++)
  {
    a[0][j] += a[0][j-1];
    check(0, j, vmax, nr);
  }

  for(int i=1; i<(int)l.size()-1; i++)
  {
    a[i][0] += a[i-1][0];
    check(i, 0, vmax, nr);
    for(int j=1; j<(int)c.size()-1; j++)
    {
      a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
      check(i, j, vmax, nr);
    }
  }
  //printa();

  cout << vmax << " " << nr << "\n";

	return 0;
}
