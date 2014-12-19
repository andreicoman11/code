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

bool valid(VI a, VI b, VI c, int base)
{
  int i = 0, t = 0;
  while( i<a.sz || i<b.sz || t )
  {
    if( i>=c.sz ) return false;
    int r = t;
    if( i<a.sz ) r += a[i];
    if( i<b.sz ) r += b[i];
    c[i] -= r % base;    
    t = r / base;
    i++;
  }
  
  REP(i, c.sz )
    if( c[i]!=0 )
      return false;

  return true;
}

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    vector<int> a, b, c;
    int x, basestart = 0;
    char ch;
    cin >> x;
    while(x)
    {
      a.pb(x%10);
      if( x%10 > basestart ) basestart = x%10;
      x /= 10;
    }
    cin >> ch ;
    cin >> x;
    while(x)
    {
      b.pb(x%10);
      if( x%10 > basestart ) basestart = x%10;
      x /= 10;
    }
    cin >> ch;
    cin >> x;
    while(x)
    {
      c.pb(x%10);
      if( x%10 > basestart ) basestart = x%10;
      x /= 10;
    }
    
    bool found = 0;
    if( basestart==1 )
    {
      bool b1 = 1;
      REP(i, a.sz)
        if( a[i]!=1 ) b1=0;

      REP(i, b.sz)
        if( b[i]!=1 ) b1=0;

      REP(i, c.sz)
        if( c[i]!=1 ) b1=0;
      
      if( b1 )
      {
        if( a.sz+b.sz==c.sz )
        {
          cout << "1\n";
          found = 1;
        }
      }
    }
    if( basestart<2 ) basestart = 2;
    else basestart++;
	
    for(int i = basestart; i<20 && !found; i++)
      if( valid(a, b, c, i) )
      {
        cout << i << endl;
        found = 1;
      }

		if( !found ) cout << "0" << endl;
	}
	
	return 0;
}