#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "dreptunghiuri2.in" 
#define OUTFILE "dreptunghiuri2.out"
#define LMAX 1010

bool a[LMAX][LMAX];
int s[LMAX][LMAX], n, m;

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  cin >> n >> m;

  memset(a, 0, sizeof(a));
  memset(s, 0, sizeof(s));
  int dmax = 1, nrd = 0, drept = 0;
  for(int i=1; i<=n; i++)
  for(int j=1; j<=m; j++)
    {
      scanf("%d", &a[i][j]);
      if( a[i][j] )
      {
        if( !a[i-1][j] && !a[i][j-1] ) s[i][j] += 1, drept++;
      }
      else
      {
        if( a[i-1][j-1] && !a[i][j-1] && !a[i-1][j] ) s[i][j] += 1;
        if( a[i-1][j] && !a[i-1][j-1] ) s[i][j] -= 1;
        if( a[i][j-1] && !a[i-1][j-1] ) s[i][j] -= 1;
      }
    }

  /*for(int i=1; i<=n+1; i++)
  {
    for(int j=1; j<=m+1; j++)
      cout << setw(3) << s[i][j] << " ";
    cout << "\n";
  }cout << "\n";*/

  for(int i=1; i<=n; i++)
  for(int j=1; j<=m; j++)
  {
    s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    if( s[i][j]>dmax ) {dmax = s[i][j]; nrd=1;}
    else if( s[i][j]==dmax && s[i-1][j]<s[i][j] && s[i][j-1]<s[i][j] ) nrd++;
  }

  /*for(int i=1; i<=n+1; i++)
  {
    for(int j=1; j<=m+1; j++)
      cout << setw(3) << s[i][j] << " ";
    cout << "\n";
  }*/

  cout << drept << " " << dmax << " " << nrd << "\n";

	return 0;
}
