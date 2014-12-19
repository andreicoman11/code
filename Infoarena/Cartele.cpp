#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

#define INFILE "cartele.in" 
#define OUTFILE "cartele.out"
#define NMAX 51

FILE* fin = fopen(INFILE, "r");
FILE* fout = fopen(OUTFILE, "w");

bool sablon[NMAX][NMAX];
bool cartela[NMAX][NMAX];
int n,c;

bool verif()
{
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    if( sablon[i][j]!=cartela[i][j] )
      return 0;
  return 1;
}

void rotate()
{
  bool aux[NMAX][NMAX];
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    aux[j][n-i-1] = cartela[i][j];
  memcpy(cartela, aux, sizeof(cartela));
}

void turn()
{
  bool aux[NMAX][NMAX];
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    aux[i][n-j-1] = cartela[i][j];
  memcpy(cartela, aux, sizeof(cartela));
}

int main()
{
  fscanf(fin, "%d %d", &n, &c);

  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
    fscanf(fin, "%d", &sablon[i][j]);

  while( c-- )
  {
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      fscanf(fin, "%d", &cartela[i][j]);

    bool res = 0;
    for(int i=0; i<2 && !res; i++)
    {
      int j = 4;
      while( (j--) && !res )
      {
        res = verif();
        rotate();
      }
      turn();
    }
    fprintf(fout, "%d\n", res);
  }
	
	return 0;
}
