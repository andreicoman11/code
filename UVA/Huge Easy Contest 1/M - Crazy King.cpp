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
#include <queue>
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

char g[100][100];
int d[100][100];
int n, m;

int hx[] = {-2, -2, -1, -1, 1,  1, 2, 2};
int hy[] = {-1,  1, -2,  2, -2, 2, -1, 1};
int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void horsy(int x, int y)
{
  REP(k, 8)
  {
    int x2 = x+hx[k];
    int y2 = y+hy[k];
    if( x2>=0 && y2>=0 && x2<n && y2<m && g[x2][y2]=='.' )
      g[x2][y2] = 'H';
  }
}

void printstuff()
{
  REP(i, n)
  {
    REP(j, m)
      cout << g[i][j];
    cout << endl;
  }
  cout << endl;
  REP(i, n)
  {
    REP(j, m)
      cout << d[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  //system("pause");
}

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
	  cin >> n >> m;
    REP(i, n)
      scanf("%s", g[i]);

    int kx, ky, bx, by;
    REP(i,n)
    REP(j,m)
      if( g[i][j]=='Z' )
        horsy(i, j);
      else if( g[i][j]=='A' )
      {
        kx = i;
        ky = j;
      }
      else if( g[i][j]=='B' )
      {
        bx = i;
        by = j;
      }

   memset(d, 0, sizeof(d));
   queue<pair<int,int> > q;
   q.push( pair<int,int>(kx, ky) );
   d[kx][ky] = 1;
   bool b = 0;
   while( !q.empty() && !b )
   {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int k=0; k<8; k++)
      {
        int x2 = x + dx[k];
        int y2 = y + dy[k];
        if( x2>=0 && y2>=0 && x2<n && y2<m && g[x2][y2]!='Z' && g[x2][y2]!='H' && d[x2][y2]==0 )
        {
          d[x2][y2] = d[x][y] + 1;
          q.push( pair<int,int>(x2,y2) );
          if( x2==bx && y2==by ) b = 1;
        }
      }
   }

   //printstuff();
   if( b ) cout << "Minimal possible length of a trip is " << d[bx][by]-1 << endl;
   else cout << "King Peter, you can't go now!\n";

	}
	
	return 0;
}