/*
ID: andreic4
PROG: fence3
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
#define INFILE "fence3.in" 
#define OUTFILE "fence3.out"
#define FENCEMAX 151

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int fx[FENCEMAX][2], fy[FENCEMAX][2];
int f;

double dist(int xc, int yc, int xa, int ya, int xb, int yb)
{
  int xdiff = 0, ydiff = 0;

  if( xc<xa ) xdiff = xa - xc;
  else if( xc>xb ) xdiff = xc - xb;

  if( yc<ya ) ydiff = ya - yc;
  else if( yc>ya ) ydiff = yc - yb;

  if( ya==yb && yb==yc )
    return (double) xdiff;

  if( xa==xb && xb==xc )
    return (double) ydiff;

  return sqrt( double(xdiff*xdiff + ydiff*ydiff));
}

double alldist(int x, int y)
{
  double tdist = 0.0;
  for(int k=0; k<f; k++)
    tdist += dist(x, y, fx[k][0], fy[k][0], fx[k][1], fy[k][1]);
  return tdist;
}

double 
totaldist (double x, double y)
{
  int a;
  double  answer = 0, xdiff, ydiff;
  for (a = 0; a < f; a++) 
  {
    if (fx[a][0] > x)
      xdiff = fx[a][0] - x;
    else if (fx[a][1] < x)
      xdiff = x - fx[a][1];
    else
      xdiff = 0;
    if (fy[a][0] > y)
      ydiff = fy[a][0] - y;
    else if (fy[a][1] < y)
      ydiff = y - fy[a][1];
    else
      ydiff = 0;
    answer += sqrt ((xdiff * xdiff) + (ydiff * ydiff));
  }
  return answer;
}


int main()
{
  fin >> f;
  REP(i, f)
  {
    fin >> fx[i][0] >> fy[i][0] >> fx[i][1] >> fy[i][1];
    if( fx[i][0] > fx[i][1] ) swap(fx[i][0], fx[i][1]);
    if( fy[i][0] > fy[i][1] ) swap(fy[i][0], fy[i][1]);
  }

  double dist[FENCEMAX][FENCEMAX];

  // get distances to all lattice points
  for(int i=0; i<=100; i++)
  for(int j=0; j<=100; j++)
    //dist[i][j] = alldist( i, j);
    dist[i][j] = totaldist( double(i), double(j));
  
  int  minx = 0, miny = 0;
  double mindist = 0.0;
  bool setm = 0;
  double dist2[FENCEMAX][FENCEMAX];
  // find best 2X2 square
  for(int i=1; i<100; i++)
  for(int j=1; j<100; j++)
  {
    dist2[i][j] = dist[i][j] + dist[i-1][j] + dist[i][j-1] + dist[i+1][j] + dist[i][j+1];
    if( dist2[i][j]<mindist || !setm )
    {
      setm = 1;
      mindist = dist2[i][j];
      minx = i;
      miny = j;
    }
  }

  //cout << minx << " " << miny << endl;

  REP(i, f)
  {
    fx[i][0] *= 10;
    fx[i][1] *= 10;
    fy[i][0] *= 10;
    fy[i][1] *= 10;
  }

  int bestx, besty;
  double best = 0.0;
  setm = 0;
  // mupltiply area by 10, and research in best square
  for(int i = (minx-1)*10; i <= (minx+1)*10; i++)
  for(int j = (miny-1)*10; j <= (miny+1)*10; j++)
    {
      //double newd = alldist(i, j);
      double newd = totaldist( double(i), double(j));
      //cout << i << " " << j << newd << endl;
      if( newd<best || !setm )
      {
        setm = 1;
        best = newd;
        bestx = i;
        besty = j;
      }
    }
  double bx = (double)bestx * 0.1;
  double by = (double)besty * 0.1;
  best = best * 0.1;


  fout << fixed << setprecision(1) << bx << " " << by << " " << best << endl;

	return 0;
}
