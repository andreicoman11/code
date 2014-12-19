#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "petrecere.in" 
#define OUTFILE "petrecere.out"
#define CMAX 3010

int l[2], n, t;
char c[2][CMAX];

void printc(int p)
{
  for(int j=l[p]-1; j>=0; j--)
    printf("%d", c[p][j]);
  printf("\n");
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n;
  l[0] = l[1] = 1;
  c[0][0] = 1;
  c[1][0] = 2;
  t = 0;

  if( n==1 ) printc(0);
  else if(n==2) printc(1);
  else for(int i=3; i<=n; i++, t=1-t)
  {
    int L = 0, aux = 0;
    while( L<max(l[0], l[1]) || aux )
    {
      aux = c[1-t][L] + (i-1)*c[t][L] + aux;
      c[t][L++] = aux%10;
      aux /= 10;
    }
    l[t] = L;
  }
  printc(1-t);
  

	return 0;
}
