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
#define INFILE ".in" 
#define OUTFILE ".out"
#define MAX 65000
#define DAY_NO 366
#define DRIVER_NO 400
#define PAY_NO 1024

ifstream fin (INFILE);
ofstream fout (OUTFILE);
  
int N;
char buf[MAX];
int day[DRIVER_NO][DAY_NO];
int tim[DRIVER_NO][DAY_NO];
int pay[PAY_NO];
int pay_day[PAY_NO];
bool vis[PAY_NO];
int days=0, pays=0;
int drivers = 0;

bool back(int d, int driv, int v[4], int i, int sum)
{
  if( day[driv][d]==sum )
  {
    day[driv][d] = 0;
    REP(k, i)
      pay[ v[k] ]=0;
    return true;
  } 
  else if( i<4 )
  {
    FOR(k, 1, pays+1)
      if( pay[k] && !vis[k] && sum+pay[k]<=day[driv][d] && d<=pay_day[k] && d+tim[driv][d]>=pay_day[k] )
      {
        vis[k] = 1;
        v[i] = k;
        if( back(d, driv, v, i+1, sum+pay[k]) )
          return true;
        vis[k] = 0;
      }
  }
  return false;
}

int main()
{
  fin >> N;
  fin.getline(buf, MAX);
  while(N--)
  {
    memset(day, 0, sizeof(day));
    memset(pay, 0, sizeof(pay));
    fin.getline(buf, MAX);
    istringstream os(buf);
    char c;
    int d, p, driv;
    int j = 1;
    while( os >> c )
    {
      if( c=='F' )
      {
        os >> d >> driv;
        os >> tim[driv][d] >> p;
        day[driv][d] = p;
        days = max(days, d);
        drivers = max(drivers, driv);
      }
      if( c=='B' )
      {
        os >> d >> p;
        pay[j] = p;
        pay_day[j] = d;
        pays = max(pays, j);
        j++;
      }
    }

    int v[4];
    FOR(j, 1, days+1)
    FOR(k, 1, drivers+1)
      if( day[k][j] )
      {
        memset(vis, 0, sizeof(vis));
        if( !back(j, k, v, 0, 0) )
          fout << j << ":" << k << " ";
      }
    fout << endl;
  }
	
	return 0;
}