#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "expozitie.in" 
#define OUTFILE "expozitie.out"
#define NMAX 512

int n, d, k;

#define min(x,y) (x>y ? y : x)
typedef int BIGINT[310];

BIGINT m[2][1024];

void sum(BIGINT a, BIGINT b, BIGINT& c)
{
  int aux = 0, i = 1;
  for(; i<=min(a[0], b[0]); i++)
  {
    aux += a[i] + b[i];
    c[i] = aux%10;
    aux /= 10;
  }
  for(; i<=max(a[0], b[0]) || aux; i++)
  {
    aux += ( i > a[0] ? b[i] : a[i]);
    c[i] = aux%10;
    aux /= 10;
  }
  c[0] = i-1;  
}

void printBIGINT(BIGINT a)
{
  for(int i=a[0]; i; i--)
    cout << a[i];
  cout << "\n";
}

void din()
{
  for(int i=0; i<=d; i++)
  {
    int aux = i;
    m[0][i][0] = 0;
    while(aux)
    {
      m[0][i][ ++m[0][i][0] ] = aux%10;
      aux /= 10;
    }
  }
  
  int t = 1;
  for(int i=2; i<=n; i++, t=1-t)
  {
    m[t][1][0] = m[t][1][1] = 1;
    for(int j=2; j<=d; j++)
      sum(m[t][j-1], m[1-t][j], m[t][j]);
  }
  printBIGINT(m[1-t][d]);
}

void comb()
{
  m[0][0][0] = m[0][0][1] = 1;
  m[0][1][0] = m[0][1][1] = 1;
  int t = 1;
  for(int i=2; i<=n+d-1; i++, t=1-t)
  {
    m[t][0][0] = m[t][0][1] = 1;
    m[t][i][0] = m[t][i][1] = 1;
    for(int j=1; j<i; j++)
      sum( m[1-t][j-1], m[1-t][j], m[t][j]);
  }

  printBIGINT(m[1-t][n]);
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n >> d >> k;

  n -= d*k;

  if( n<2 )
  {
    if( n<0 )       cout << "0\n";
    else if( n==0 ) cout << "1\n";
    else            cout << d << "\n";
    return 0;
  }
  //din();
  comb();
  
	return 0;
}
