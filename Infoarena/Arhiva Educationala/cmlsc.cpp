#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

#define NMAX 1025
#define INFILE "cmlsc.in" 
#define OUTFILE "cmlsc.out"

#define max(a,b) ((a)>(b)?(a):(b))

int a[NMAX], b[NMAX];
int sub[NMAX][NMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  int n, m;
  cin >> n >> m;

  for(int i=0; i<n; i++)
    cin >> a[i];

  for(int i=0; i<m; i++)
    cin >> b[i];

  memset(sub, 0, sizeof(sub));
  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
  {
    sub[i+1][j+1] = max(sub[i][j+1], sub[i+1][j]);
    if( a[i]==b[j] )
      sub[i+1][j+1] = max(sub[i][j]+1, sub[i+1][j+1]);
  }

	cout << (int)sub[n][m] << endl;

  int rez[NMAX];
  int val = sub[n][m];
  int i = n;
  int j = m;
  while( val && i && j )
  {
    while( sub[i][j]==val )
      i--;
    while( sub[i+1][j]==val )
      j--;
    rez[--val] = a[i];
  }  

  for(i=0; i<sub[n][m]; i++)
  {
    cout << rez[i];
    if( i+1<sub[n][m] ) cout << " " ;
  }

	return 0;
}
