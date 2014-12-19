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


int perm[7][4] = {0,0,0,0,
                  3,4,5,6,
                  6,5,4,3,
                  2,4,1,6,
                  3,2,5,1,
                  1,4,2,6,
                  3,1,5,2};

int per[7] = {0,2,1,5,6,3,4};


int getnr(int a1, int a2, int a3, int a4)
{
  return ((a1*10 + a2)*10 + a3)*10 + a4;
}

bool check_rot(int a[7], int b[7], int perm[4])
{
  int nr = getnr(a[3],a[4],a[5],a[6]);
  REP(i, 4)
  {
    int nr2 = getnr(b[ perm[(0+i) & 3] ],
                    b[ perm[(1+i) & 3] ],
                    b[ perm[(2+i) & 3] ],
                    b[ perm[(3+i) & 3] ]);
    if( nr==nr2 ) return true;
  }

  return false;
}

bool check_rot2(int a[4], int b[4])
{
  int nr = getnr(a[0],a[1],a[2],a[3]);
  REP(i, 4)
  {
    int nr2 = getnr(b[ (0+i) & 3 ],
                    b[ (1+i) & 3 ],
                    b[ (2+i) & 3 ],
                    b[ (3+i) & 3 ]);
    if( nr==nr2 ) return true;
  }

  return false;
}

int main()
{
  //perm[0][] = {3,4,5,6};
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int a[7], b[7];
    char c;
    FOR(i,1, 7)
    {
      cin >> c;
      a[i] = c - int('0');
    }

    FOR(i, 1, 7)
    {
      cin >> c;
      b[i] = c - int('0');
    }

    bool eq = 0;
    FOR(i, 1, 7)
      // b[i] is on top, select proper pair and case
      if( a[1]==b[i] && a[2]==b[per[i]] && 
        check_rot(a, b, perm[i]) )
      {
        eq = 1;
        break;
      }
      /*if( a[1]==b[i] && a[2]==b[per[i]] )
      {
        b[i] = b[i] + b[1];
        b[1] = b[i] - b[1];
        b[i] = b[i] - b[1];
        b[per[i]] = b[per[i]] + b[2];
        b[2] = b[per[i]] - b[2];
        b[per[i]] = b[per[i]] - b[2];
        if( check_rot2(a+2, b+2) )
          eq = 1;
        break;
      }*/
        
    if( eq ) cout << "Equal\n";
    else   cout << "Not Equal\n";
  }
	
	return 0;
}