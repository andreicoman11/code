#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "poligon5.in" 
#define OUTFILE "poligon5.out"
#define NMAX 210

int n, p[NMAX][2], step[NMAX][2], stepm, stepi, xfin, yfin;
LL len[NMAX], laux[NMAX], pmin;

void readp()
{
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> p[i][0] >> p[i][1];
}

int gcd(int a, int b)
{
  return (b==0 ? a : gcd(b, a%b));
}

void findstep()
{
  stepm = 200001;
  stepi = -1;
  for(int i=0, j=0; i<n; i++)
  {
    j = (i==n-1 ? 0 : i+1);
    int x = p[j][0] - p[i][0];
    int y = p[j][1] - p[i][1];
    int xygcd = gcd( abs(x), abs(y));
    x /= xygcd;
    y /= xygcd;
    step[i][0] = x;
    step[i][1] = y;
    if( xygcd<stepm ) stepm = xygcd, stepi = i;
    //cout << i << " " << x << " " << y << " " << xygcd << "\t\t" << stepm << "\n";
  }
}

LL dist(LL x, LL y, LL x2, LL y2)
{
  LL res = (x-x2)*(x-x2);
  res += (y-y2)*(y-y2);
  return res;
}

void findlen(int lasti)
{
  int dx[NMAX], dy[NMAX], dx2[NMAX], dy2[NMAX], pos = 1;
  dx[0] = xfin, dy[0] = yfin;
  len[0] = 0;

  for(int i = (lasti==n-1 ? 0 : lasti+1); i!=lasti; i=(i==n-1 ? 0 : i+1))
  {
    int j=0;
    do
    {
      dx2[j] = p[i][0] + (j+1)*step[i][0];
      dy2[j] = p[i][1] + (j+1)*step[i][1];
      j++;
    }while( dx2[j-1]+step[i][0]!=p[(i+1)%n][0] || dy2[j-1]+step[i][1]!=p[(i+1)%n][1] );
    //cout << i << ":\t";
    for(int k=0; k<j; k++)
    {
      laux[k] = dist(dx2[k], dy2[k], dx[0], dy[0]) + len[0];
      for(int u=1; u<pos; u++)
      {
        LL aux = dist(dx2[k], dy2[k], dx[u], dy[u]) + len[u];
        laux[k] = (laux[k] > aux ? aux : laux[k]);
      }
      //cout << dx2[k] << " "<< dy2[k] << " " << laux[k] << "\t\t";
    }
    //cout << "\n";
    memcpy(len, laux, sizeof(laux));
    memcpy(dx, dx2, sizeof(dx2));
    memcpy(dy, dy2, sizeof(dy2));
    pos = j;
  }

  for(int j=0; j<pos; j++)
    if( pmin==-1 || ( pmin > len[j] + dist(dx[j], dy[j], xfin, yfin)) )
        pmin = len[j] + dist(dx[j], dy[j], xfin, yfin);
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  int teste;
  cin >> teste;
  while( teste-- )
  {
    readp();
    findstep();
    pmin = -1;
    for(int i=1; i<stepm; i++)
    {
      xfin = p[stepi][0] + step[stepi][0]*i;
      yfin = p[stepi][1] + step[stepi][1]*i;
      //cout << stepi << " " << xfin << " " << yfin << "\n";
      findlen(stepi);
      //cout << pmin << "\n";
    }
    cout << pmin; if(teste) cout << "\n";
  }

	return 0;
}
