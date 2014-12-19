#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "egipt.in" 
#define OUTFILE "egipt.out"
#define NMAX 10010

int n, nr1=0, nr3=0;
int a[NMAX];


int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> a[i];
    if( a[i]==1 ) nr1++;
    else if(a[i]==3) nr3++;
  }

  int loc[4][4] = {0};
  for(int i=0; i<n; i++)
    if( i<nr1 ) loc[1][a[i]]++;
    else if( i>=n-nr3 ) loc[3][a[i]]++;
    else loc[2][a[i]]++;

  int inv = 0, m, d[6] = {1, 2, 1, 3, 2, 3}, inv2 = 0;
  for(int i=0; i<6; i+=2)
  {
    m = min(loc[d[i]][d[i+1]], loc[d[i+1]][d[i]]);
    loc[d[i]][d[i+1]] -= m, loc[d[i+1]][d[i]] -= m;
    inv += m;
    inv2 += loc[d[i]][d[i+1]] + loc[d[i+1]][d[i]];
  }
  inv += inv2 / 3 * 2;
  cout << inv << "\n";

  for(int i=0, l=nr1, r=n-1; i<nr1; i++)
    if( a[i]!=1 )
    {
      if( a[i]==3 )
      {
        while( a[r]!=1 ) r--;
        cout << i+1 << " " << r+1 << "\n";
        a[r] = a[i];
      }
      else
      {
        while( a[l]!=1 ) l++;
        cout << i+1 << " " << l+1 << "\n";
        a[l] = a[i];
      }
    }
  for(int i=nr1, r=n-1; i<n-nr3; i++)
    if( a[i]==3 )
    {
      while( a[r]!=2 ) r--;
      cout << i+1 << " " << r+1 << "\n";
      a[r] = 3;
    }

	return 0;
}
