/*
ID: andreic4
PROG: window
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
#define INFILE "window.in" 
#define OUTFILE "window.out"
ofstream fout (OUTFILE);
#define MAXW 64

struct win{
  int x1, x2, y1, y2, pos;
  win() : x1(0), x2(0), y1(0), y2(0) {}
  win(int _x1, int _y1, int _x2, int _y2) : 
  x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

bool isw[MAXW];
win w[MAXW];
int wnr = 0;

int getint(char c)
{
  if( isdigit(c) )
    return int(c) - int('0');
  if( c<='Z' )
    return 10 + int(c) - int('A');
  return 36 + int(c) - int('a');
}

void create(int, int, int, int, int);
void top(int);
void bottom(int);
void destroy(int);
long double  getarea(int);
list<win> comp(win a, win b);
bool intersectpoint(win a, int x, int y);
int intersectline(win, int, int, int, int);
bool contains(win, win);

int main()
{
  memset(isw, 0, sizeof(isw));
  FILE* fin = fopen(INFILE, "r");
  char op, window;
  int X1,X2,Y1,Y2;
  while( !feof(fin) )
  {
    fscanf(fin, "%c", &op);
    if( op=='w' )
    {
      fscanf(fin, "(%c,%d,%d,%d,%d)\n", &window, &X1, &Y1, &X2, &Y2);
      create(getint(window), X1, Y1, X2, Y2);
    }
    else
    {
      fscanf(fin, "(%c)\n", &window);
      switch(op) {
        case 't':
          top( getint(window) );
          break;
        case 'b':
          bottom( getint(window) );
          break;
        case 'd':
          destroy( getint(window) );
          break;
        default:
          // s
          fout << fixed << setprecision(3) << getarea( getint(window) ) << endl;
      }
    }
  }


	return 0;
}

void create(int neww, int X1, int Y1, int X2, int Y2)
{
  if( X1>X2 ) swap(X1, X2);
  if( Y1>Y2 ) swap(Y1, Y2);
  
  isw[neww] = 1;
  w[neww].x1 = X1;
  w[neww].x2 = X2;
  w[neww].y1 = Y1;
  w[neww].y2 = Y2;
  w[neww].pos = wnr;
  wnr++;
  top(neww);
}

void destroy(int window)
{
  bottom(window);
  isw[window] = 0;
  wnr--;
}

void top(int window)
{
  REP(i, 62)
    if( isw[i] && w[i].pos < w[window].pos )
      w[i].pos++;
  w[window].pos = 0;
}

void bottom(int window)
{
  REP(i, 62)
    if( isw[i] && w[i].pos > w[window].pos )
      w[i].pos--;
  w[window].pos = wnr-1;
}

// compute area visible for selected window
long double getarea(int sw)
{
  long long int area = (w[sw].x2 - w[sw].x1) * (w[sw].y2 - w[sw].y1);

  list<win> wl;
  wl.pb(w[sw]);
  
  REP(i, 62)
    // window i exists and is in front of sw
    if( isw[i] && w[sw].pos > w[i].pos )
    {
      list<win> newl;
      for(list<win>::iterator it = wl.begin(); it!=wl.end(); it++)
      {
        // put window i on top of every window remaining from sw
        //newl.insert(newl.begin(), comp( w[i], *it));
        list<win> nnewl = comp( w[i], *it);
        newl.insert(newl.begin(), nnewl.begin(), nnewl.end());
      }
      wl = newl;
    }

  long long int newarea = 0;
  for(list<win>::iterator it = wl.begin(); it!=wl.end(); it++)
    newarea += (it->x2 - it->x1) * (it->y2 - it->y1);
  return 100.0 * (long double)newarea / (long double)area;
}

bool intersectpoint(win a, int x, int y)
{
  return (a.x1<x && x<a.x2 && a.y1<y && y<a.y2);
}

#define NONE 0
#define CORNER 1
#define LINEIN 2
#define LINEOUT 3

int intersectline(win a, int x1, int y1, int x2, int y2)
{
  if( intersectpoint(a,x1,y1) && intersectpoint(a,x2,y2) )
    return LINEIN;

  if( intersectpoint(a,x1,y1) || intersectpoint(a,x2,y2) )
    return CORNER;

  if( x1==x2 )
  {
    if( y1<a.y1 && y2>a.y2 && a.x1<x1 && x1<a.x2 )
      return LINEOUT;
    return NONE;
  }
  else
  {
    if( x1<a.x1 && x2>a.x2 && a.y1<y1 && y1<a.y2 )
      return LINEOUT;
    return NONE;
  }
  return NONE;
}

bool contains(win a, win b)
{
  return (a.x1<=b.x1 && b.x2<=a.x2 && a.y1<=b.y1 && b.y2<=a.y2);
}

list<win> comp(win a, win b)
{
  list<win> lw;
  bool points[4] = {intersectpoint(b, a.x1, a.y1),
                    intersectpoint(b, a.x1, a.y2),
                    intersectpoint(b, a.x2, a.y1),
                    intersectpoint(b, a.x2, a.y2)};
  int lines[4] = {intersectline(b, a.x1, a.y1, a.x1, a.y2),
                  intersectline(b, a.x2, a.y1, a.x2, a.y2),
                  intersectline(b, a.x1, a.y1, a.x2, a.y1),
                  intersectline(b, a.x1, a.y2, a.x2, a.y2)};

  int ans = max(max(lines[0], lines[1]), max(lines[2], lines[3]));

  if( ans==CORNER )
  {
    // split window into 4, check which out of the 4 is inside window a
    int x = a.x1, y = a.y1;
    if( points[1] ) y = a.y2;
    else if(points[2] ) x = a.x2;
    else if(points[3] ) {x = a.x2; y = a.y2;}

    win b1(b.x1, b.y1, x, y);
    win b2(b.x1, y, x, b.y2);
    win b3(x, b.y1, b.x2, y);
    win b4(x, y, b.x2, b.y2);

    if( !contains(a,b1) ) lw.pb(b1);
    if( !contains(a,b2) ) lw.pb(b2);
    if( !contains(a,b3) ) lw.pb(b3);
    if( !contains(a,b4) ) lw.pb(b4);
  }
  else if( ans==LINEIN )
  {
    if( lines[0]==LINEIN || lines[1]==LINEIN )
    {
      win b1(b.x1, b.y1, b.x2, a.y1);
      win b2(b.x1, a.y2, b.x2, b.y2);
      lw.pb(b1);
      lw.pb(b2);
      if( lines[0] )
      {
        win b3(b.x1, a.y1, a.x1, a.y2);
        lw.pb(b3);
      }
      if( lines[1] )
      {
        win b3(a.x2, a.y1, b.x2, a.y2);
        lw.pb(b3);
      }
    }
    else 
    if( lines[2]==LINEIN || lines[3]==LINEIN )
    {
      win b1(b.x1, b.y1, a.x1, b.y2);
      win b2(a.x2, b.y1, b.x2, b.y2);
      lw.pb(b1);
      lw.pb(b2);
      if( lines[2] )
      {
        win b3(a.x1, b.y1, a.x2, a.y1);
        lw.pb(b3);
      }
      if( lines[3] )
      {
        win b3(a.x1, a.y2, a.x2, b.y2);
        lw.pb(b3);
      }
    }
  }
  else if( ans==LINEOUT )
  {
    // split window into 2
    if( lines[0]==LINEOUT )
    {
      win b1(b.x1, b.y1, a.x1, b.y2);
      lw.pb(b1);
    }
    if( lines[1]==LINEOUT )
    {
      win b1(a.x2, b.y1, b.x2, b.y2);
      lw.pb(b1);
    }
    if( lines[2]==LINEOUT )
    {
      win b1(b.x1, b.y1, b.x2, a.y1);
      lw.pb(b1);
    }
    if( lines[3]==LINEOUT )
    {
      win b1(b.x1, a.y2, b.x2, b.y2);
      lw.pb(b1);
    }
  }
  else
  {
    // ans==0, we can have either no intersections, or b is inside a
    if( !contains(a, b) )
      lw.pb(b);
  }

  return lw;
}
