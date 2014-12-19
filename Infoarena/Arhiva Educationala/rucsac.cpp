#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "rucsac.in" 
#define OUTFILE "rucsac.out"
#define GMAX 10001
int p[GMAX], n, g;

void additem(int gi, int pi)
{
  for(int i = g-gi; i>=0; i--)
    if( p[i]>0 && p[i+gi]<p[i]+pi )
      p[i+gi] = p[i] + pi;
  p[gi] = max(p[gi], pi);
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n >> g;

  memset(p, 0, sizeof(p));
  for(int i=0; i<n; i++)
  {
    int gi, pi;
    cin >> gi >> pi;
    if( gi<=g ) additem(gi, pi);
  }

  int pbest = 0;
  for(int i=0; i<=g; i++)
    pbest = (pbest<p[i] ? p[i] : pbest);
  
  cout << pbest;

	return 0;
}
