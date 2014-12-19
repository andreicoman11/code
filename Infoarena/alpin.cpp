#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdlib>
#define INFILE "alpin.in" 
#define OUTFILE "alpin.out"
using namespace std;
#define NMAX 1025
#define BUFMAX 256

int n, map[NMAX][NMAX], tmax[NMAX][NMAX];

char dir[NMAX][NMAX];
bool viz[NMAX][NMAX];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, Tmax = 0, Ti=0, Tj=0;

void parsed_read()
{
  char buf[BUFMAX];
  scanf("%d", &n);
  fgets(buf, BUFMAX, stdin);
  for(int i=0; i<n; i++)
  {
    unsigned int j=0, val = 0, k = 0;
    fgets(buf, BUFMAX, stdin);
    do
    {
      for(k = 0; k<strlen(buf); k++)
        if( !isdigit(buf[k]) )
        {
          map[i][j++] = val;
          val = 0;
        }
        else
          val = val*10 + int(buf[k]) - int('0');
      if( buf[k-1]=='\n' ) break;
    }
    while( fgets(buf, BUFMAX, stdin)!=NULL );
    map[i][j] = val;
  }
}

void print_trace(int i, int j)
{
  if( tmax[i][j]>0 )
    print_trace( i+dx[(int)dir[i][j]], j+dy[(int)dir[i][j]] );
  printf("\n%d %d", i+1, j+1);
}

void check(int i, int j)
{
  for(int k=0; k<4; k++)
  {
    int x=i+dx[k], y=j+dy[k];
    if( x>=0 && x<n && y>=0 && y<n && map[i][j] > map[x][y] )
    {
      if( !viz[x][y] )
        check(x, y);

      if( tmax[i][j] < tmax[x][y] + 1)
      {
        tmax[i][j] = tmax[x][y] + 1;
        dir[i][j] = k;
      }
    }
  }

  if( tmax[i][j] > Tmax )
  {
    Tmax = tmax[i][j];
    Ti = i;
    Tj = j;
  }
  viz[i][j] = 1;

}

int main()
{
  memset(viz, 0, sizeof(viz));
  memset(tmax, 0, sizeof(tmax));

  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  parsed_read();

  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    if( !viz[i][j] )
    {
      check(i,j);
    }
  
  printf("%d", Tmax+1);
  print_trace(Ti, Tj);
  
	return 0;
}
