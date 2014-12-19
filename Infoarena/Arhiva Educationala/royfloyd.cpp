#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "royfloyd.in" 
#define OUTFILE "royfloyd.out"
#define NMAX 128
int m[NMAX][NMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    scanf("%d", &m[i][j]);
	
  for(int k=0; k<n; k++)
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    if( m[i][k] && m[k][j] && 
        (m[i][j] > m[i][k] + m[k][j] || m[i][j]==0)
        && i!=j)
      m[i][j] = m[i][k] + m[k][j];

  for(int i=0; i<n; i++)
  {
    if( i ) printf("\n");
    printf("%d", m[i][0]);
    for(int j=1; j<n; j++)
      printf(" %d", m[i][j]);
  }

	return 0;
}
