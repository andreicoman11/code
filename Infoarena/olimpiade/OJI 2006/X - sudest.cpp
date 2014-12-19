#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
using namespace std;

#define INFILE "sudest.in" 
#define OUTFILE "sudest.out"
#define NMAX 102

int n, c[NMAX][NMAX], d[NMAX][NMAX], s[NMAX*2];
bool dir[NMAX][NMAX];

void print_path(int i, int j, int step)
{
  if( i || j )
  {
    if( dir[i][j]==0 ) print_path(i-s[step], j, step-1);
    else               print_path(i, j-s[step], step-1);
  }
  cout << i+1 << " " << j+1 << "\n";
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n;
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    cin >> c[i][j];

  memset(d, 0, sizeof(d));
  d[0][0] = c[0][0];

  set<pair<int,int> > q;
  q.insert(make_pair(0,0));
  int k, step, x, y;
  cin >> k;
  for(int i=0; i<k; i++)
  {
    cin >> step;
    s[i] = step;
    set<pair<int,int> > q2;
    for(set<pair<int,int> >::iterator it=q.begin(); it!=q.end(); it++)
    {
      x = it->first;
      y = it->second;
      if( x+step<n )
      {
        if( d[x+step][y] < d[x][y] + c[x+step][y] )
        {
          d[x+step][y] = d[x][y] + c[x+step][y];
          dir[x+step][y] = 0;
        }
        q2.insert(make_pair(x+step, y));
      }
      if( y+step<n )
      {
        if( d[x][y+step] < d[x][y] + c[x][y+step] )
        {
          d[x][y+step] = d[x][y] + c[x][y+step];
          dir[x][y+step] = 1;
        };
        q2.insert(make_pair(x, y+step));
      }
    }
    q = q2;
  }

  cout << d[n-1][n-1] << "\n";
  print_path(n-1, n-1, k-1);

	return 0;
}
