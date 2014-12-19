#include <iostream>
#include <fstream>
using namespace std;

#define INFILE "rj.in" 
#define OUTFILE "rj.out"

int map[101][101], n, m, r[2][2][900][2];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  char str[128];
  cin >> n >> m;
  cin.getline(str, 128, '\n');
  r[0][1][0][0] = r[1][1][0][0] = 1;

  for(int i=0; i<n; i++)
  {
    cin.getline(str, 128, '\n');
    for(int j=0; j<m; j++)
    {
      switch(str[j]) {
        case 'X':
          map[i][j] = -1;
          break;
        case 'R':
          map[i][j] = -1;
          r[0][1][1][0] = i;
          r[0][1][1][1] = j;
          break;
        case 'J':
          map[i][j] = -1;
          r[1][1][1][0] = i;
          r[1][1][1][1] = j;
          break;
        default:
          map[i][j] = 0;
      };
    }
  }

  bool found = 0;
  int tmin = 2, xmin = 128, ymin = 128;
  for(; !found; tmin++)
  {
    r[0][tmin%2][0][0] = r[1][tmin%2][0][0] = 0;
    for(int k=0; k<2; k++)
    for(int i=1; i<=r[k][(tmin+1)%2][0][0]; i++)
    {
      int x = r[k][(tmin+1)%2][i][0];
      int y = r[k][(tmin+1)%2][i][1];
      map[x][y] = 2;
      for(int xx = -1; xx<2; xx++)
      for(int yy = -1; yy<2; yy++)
        if( (xx || yy) && (x+xx>=0 && x+xx<n && y+yy>=0 && y+yy<m)  )
        {
          if( map[x+xx][y+yy]==0 )
          {
            map[x+xx][y+yy] = k+1;
            r[k][tmin%2][ ++r[k][tmin%2][0][0] ][0] = x+xx;
            r[k][tmin%2][ r[k][tmin%2][0][0] ][1] = y+yy;
          }
          else if ( map[x+xx][y+yy]==1 && 1==k )
          {
            found = 1;
            if( x+xx<xmin || (x+xx==xmin && y+yy<ymin ) )
            {
              xmin = x+xx;
              ymin = y+yy;
            }
          }
        }
    }
  }

  cout << tmin-1 << " " << xmin+1 << " " << ymin+1 << "\n";

  return 0;
}
