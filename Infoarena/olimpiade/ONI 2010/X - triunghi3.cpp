#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "triunghi3.in" 
#define OUTFILE "triunghi3.out"
#define NMAX 1001

int v[NMAX][NMAX], n;
LL s[NMAX], c[NMAX][NMAX], d[NMAX][NMAX];

void readvcd()
{
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  cin >> n;
  for(int i=0; i<n; i++)
  for(int j=0; j<=i; j++)
  {
    scanf("%d", &v[i][j]);
    if( i==n-1 ) s[j] = c[n-1][j] = d[n-1][j] = v[n-1][j];
  }
}

void prints()
{
  for(int i=0; i<n; i++)
    cout << s[i] << " ";
  cout << "\n";
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  readvcd();

  /*for(int i=0; i<n; i++)
  {
    for(int j=0; j<=i; j++)
      cout << setw(4) << v[i][j] << " ";
    cout << "\n";
  }cout << "\n";

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<=i; j++)
      cout << setw(4) << c[i][j] << " ";
    cout << "\n";
  }cout << "\n";

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<=i; j++)
      cout << setw(4) << d[i][j] << " ";
    cout << "\n";
  }cout << "\n";*/

  //prints();
  for(int i=n-2; i>=0; i--)
  for(int j=0; j<=i; j++)
  {
    c[i][j] = v[i][j] + c[i+1][j];
    d[i][j] = v[i][j] + d[i+1][j+1];
    s[j] = min( (2*c[i][j] - v[i][j] - v[n-1][j]) + 
                (c[i][j] - v[n-1][j] + c[i+1][j+1])*(n-1-i) + 
                (i<n-2 ? s[j+1] : 0), 
                (2*d[i][j] - v[i][j] - v[n-1][j+n-1-i]) + 
                (d[i][j] - v[n-1][j+n-1-i] + d[i+1][j])*(n-1-i) + 
                (i<n-2 ? s[j] : 0));
  }

  cout << s[0] << "\n";

	return 0;
}
