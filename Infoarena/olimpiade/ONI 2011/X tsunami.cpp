#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

#define LL long long
#define INFILE "tsunami.in" 
#define OUTFILE "tsunami.out"

int n, m, h;
int map[1024][1024];
bool vis[1024][1024];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  memset(vis, 0, 1024*1024*sizeof(bool));

  cin >> n >> m >> h;
  queue<pair<int,int> > q;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
      cin >> map[i][j];
      if( map[i][j]==0 ) {
        q.push(make_pair(i, j));
        vis[i][j] = 1;
      }
    }

  int res = 0, x, y, x2, y2;
  while( !q.empty() )
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int k=0; k<4; k++) {
      x2 = x + dx[k];
      y2 = y + dy[k];
      if( x2>=0 && y2>=0 && x2<n && y2<m && vis[x2][y2]==0 && map[x2][y2]>0 && map[x2][y2]<h ) {
        vis[x2][y2] = 1;
        res++;
        q.push(make_pair(x2,y2));
      }
    }
  }

  cout << res << "\n";

	return 0;
}
