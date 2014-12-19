#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

#define INFILE "stup.in" 
#define OUTFILE "stup.out"
#define NMAX 100002

int v[NMAX][6], nr[NMAX], t[NMAX], n;
bool isv[NMAX], isd[NMAX];
int q[NMAX], qend;

void addv(int i, int vv)
{
  v[i][ nr[i]++ ] = vv;
}

void addtoq(int x)
{
  isd[x] = 1;
  for(int i=x; i>=1 && t[i]==t[x]; i--)
    if( isv[i]==0 )
      q[qend++] = i, isv[i]=1;

  for(int i=x+1; i<=n && t[i]==t[x]; i++)
    if( isv[i]==0 )
      q[qend++] = i, isv[i]=1;
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  
  int m, x, y, lastt, trib=1, last=3;
  cin >> n >> m >> x >> y;

  cin >> lastt;
  for(int i=1; i<=n; i++)
  {
    if( i+1<=n ) addv(i, i+1), addv(i+1, i);

    while( nr[i]<6 && last<=n )
    {
      addv(i, last);
      addv(last, i);
      last++;
    }
    if( nr[i]==6 ) last--;

    t[i] = trib;
    if( i==lastt && lastt<n )
    {
      cin >> lastt;
      trib++;
    }
  }

  memset(isv, 0, sizeof(isv));
  memset(isd, 0, sizeof(isd));
  qend = 0;
  addtoq(x);
  int lvl = 1, qs = 0, qendlvl;

  while(isv[y]==0)
  {
    lvl++;
    qendlvl = qend;

    for(; qs<qendlvl && !isv[y]; qs++)
      for(int i=0; i<nr[q[qs]]; i++)
        if( isv[ v[q[qs]][i] ]==0 )
          addtoq(v[q[qs]][i]);
  }
  cout << lvl << "\n";

	return 0;
}
