#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

//ifstream fin ("B-small.in");
//ofstream fout ("B-small.out");
ifstream fin ("B-large.in");
ofstream fout ("B-large.out");
#define INF 1000000

bool used[128][128];
int h, n, m, c[128][128], f[128][128], t[128][128];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

// given water lvl at time s, what is the highest water lvl (<t)
// so that we can (move from x,y to) arrive in a,b
int gett(int x, int y, int a, int b, int s) {
   if( f[x][y]+50 > c[a][b] ) return INF;
   if( f[a][b]+50 > c[a][b] ) return INF;
   if( f[a][b]+50 > c[x][y] ) return INF;

   int t = h - s;
   if( h>=s && t > c[a][b]-50 )
      s += t - (c[a][b] - 50);
   t = min(t, c[a][b]-50);

   if( s==0 ) return 0;
   
   if( t-f[x][y]>=20 ) return s + 10;
   else return s + 100;
}

void solve() {
   fin >> h >> n >> m;
   for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
         fin >> c[i][j];

   for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
         fin >> f[i][j], t[i][j] = INF;

   t[0][0] = 0;
   set<pair<int, int> > v;

   /*for(int j=0; j<4; j++) {
         int xx = 0 + dx[j];
         int yy = 0 + dy[j];
         if( xx>=0 && yy>=0 && xx<n && yy<m && !used[xx][yy] ) {
            v.insert(make_pair(xx, yy));
            int ts = gett(0, 0, xx, yy, t[0][0]);
            if( ts>=0 && ts < t[xx][yy] )
               t[xx][yy] = ts;
         }
      }*/

   memset(used, 0, sizeof(used));
   used[0][0] = 1;

   v.insert(make_pair(0,0));

   while( !used[n-1][m-1] ) {
      int tmin = INF, nx, ny;
      for(set<pair<int, int> >::iterator it = v.begin(); it!=v.end(); it++) {
         int x = it->first, y = it->second;
         if( t[x][y]>=0 && t[x][y] < tmin ) {
            tmin = t[x][y];
            nx = x, ny = y;
         } 
      }

      v.erase(make_pair(nx, ny));
      used[nx][ny] = 1;

      for(int j=0; j<4; j++) {
         int xx = nx + dx[j];
         int yy = ny + dy[j];
         if( xx>=0 && yy>=0 && xx<n && yy<m && !used[xx][yy] ) {
            v.insert(make_pair(xx, yy));
            int ts = gett(nx, ny, xx, yy, t[nx][ny]);
            if( ts>=0 && ts < t[xx][yy] )
               t[xx][yy] = ts;
         }
      }
   }
   fout << fixed << setprecision(1) << double(t[n-1][m-1]) / 10.0 << "\n";
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}
