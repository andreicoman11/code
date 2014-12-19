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
#define INFILE ".in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);
const double PI = 3.141592;
double gx, gy, galpha, wbase;

double getPIangle(double angle)
{
  return angle * PI / (double)180.00;
}

double getTurnR(double wbase, double steer)
{
  double turn = wbase;
  steer = getPIangle(steer);
  turn = turn / sin(steer);
  return turn;
}

double getTotalDist(double turn)
{
  return (double)2.00 * PI * turn;
}

void updatePos(double dist, double steer)
{
  cout << dist << " " << steer << "\t";
  int cadran = 0;
  bool left = 0;
  if( int(100.00*steer)<0 )
  {
    steer = 0.00 - steer;
    left = 1;
  }

  double r = getTurnR(wbase, steer);
  double totalD = getTotalDist(r);
  while( dist > totalD )
    dist -= totalD;
  if( int(100.00*dist)<0 )
  {
    dist = totalD + dist;
  }

  double alpha = (double)360.00 * dist / totalD;
  double alpha2 = alpha;
  
  if( alpha>90.00 && alpha<180.00 )
  {
    alpha = 180.00 - alpha;
    cadran = 1;
  }
  else if( alpha>180.00 && alpha<270.00 )
  {
    alpha = alpha - 180.00;
    cadran = 2;
  }
  else if( alpha>270.00 )
  {
    alpha = 360.00 - alpha;
    cadran = 3;
  }
  
  double x = 0.00, y = 0.00;
  y = sin( getPIangle(alpha) ) * r;
  if( cadran==0 || cadran==3 )        x = r - cos( getPIangle(alpha) ) * r;
  else if( cadran==1 || cadran==2 )   x = r + cos( getPIangle(alpha) ) * r;


  if( (int)(100.00*steer)==0 )
  {
    x = 0.00;
    y = dist;
    alpha2 = steer;
  }
  else
  {
    if( left )      x = (-1.00) * x;
    if( cadran>1 )  y = 0.00 - y;
    if( left )      alpha2 = 360.00 - alpha2;
  }

  cout << x << " " << y << "\t";
  double x2 = cos( getPIangle(galpha) )*x + sin( getPIangle(galpha) )*y;
  double y2 = cos( getPIangle(galpha) )*y - sin( getPIangle(galpha) )*x;
  x = x2; y = y2;

  galpha += alpha2;
  while( galpha<0 ) galpha += 360.00;
  while( galpha>=360.00 ) galpha -= 360.00;

  gx += x;
  gy += y;
  cout << x << " " << y << " " << alpha2 << endl;
  cout << "\t\t\tGpos" << gx << " " << gy << " " << galpha << endl;
}

#include <>

int main()
{
  cout << 2.00 * 14.00 * PI << endl;
  double steer, dist;
  int n;
  if( fin >> wbase >> n )
  {
    galpha = gx = gy = 0.00;
    while( n-- )
    {
      fin >> dist >> steer;
      updatePos(dist, steer);
    }
    fout << fixed << setprecision(2) << gx << " " << gy << " " << galpha << endl;
  }

  socket sock;
	
	return 0;
}