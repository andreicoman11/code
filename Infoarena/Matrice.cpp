#include <iostream>
#include <fstream>
using namespace std;

#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "matrice.in" 
#define OUTFILE "matrice.out"
#define MAX 30005
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, a, max0=0, tocc0=0;
bool R[MAX], C[MAX];
int ZR[MAX], OR[MAX], ZC[MAX], OC[MAX];
int cnr[MAX], rnr[MAX];

void check(int x, int y)
{
  x--; y--;
  int hasc[MAX] = {0}, hasr[MAX] = {0};
  int cc = 0, rc = 0, zeros;

  for(int i=1; i+x<=n; i++)
  {
    zeros = ZR[i+x] - ZR[i-1];
    if( !hasr[zeros] )
    {
      hasr[zeros] = 1;
      rnr[rc++] = zeros;
    }
    else hasr[zeros]++;
  }

  for(int j=1; j+y<=m; j++)
  {
    zeros = ZC[j+y] - ZC[j-1];
    if( !hasc[zeros] )
    {
      hasc[zeros] = 1;
      cnr[cc++] = zeros;
    }
    else hasc[zeros]++;
  }

  for(int i=0; i<rc; i++)
  for(int j=0; j<cc; j++)
  {
    int count = rnr[i]*cnr[j] + (x+1-rnr[i])*(y+1-cnr[j]);
    if( count>max0 )
    {
      max0 = count;
      tocc0 = hasr[rnr[i]]*hasc[cnr[j]];
    }
    else if( count==max0 ) tocc0+=hasr[rnr[i]]*hasc[cnr[j]];
  }
}

void oldcheck(int x, int y)
{
  x--; y--;
  for(int i=1; i+x<=n; i++)
  for(int j=1; j+y<=m; j++)
  {
    int count = (ZR[i+x]-ZR[i-1])*(ZC[j+y]-ZC[j-1]) + 
                (OR[i+x]-OR[i-1])*(OC[j+y]-OC[j-1]);

    if( count>max0 )
    {
      max0 = count;
      tocc0 = 1;
    }
    else if(count==max0 )
      tocc0++;
  }
}

int main()
{
  fin >> n >> m >> a;
  //ZR[0] = OR[0] = ZC[0] = OC[0] = 0;
  ZR[0] = ZC[0] = 0;
  REP(i, n)
  {
    fin >> R[i+1];
    //OR[i+1] = (i > 0 ? OR[i] : 0);
    ZR[i+1] = (i > 0 ? ZR[i] : 0);
    if( !R[i+1] )  ZR[i+1]++;
    //else          OR[i+1]++;
  }

  REP(i, m)
  {
    fin >> C[i+1];
    //OC[i+1] = (i > 0 ? OC[i] : 0);
    ZC[i+1] = (i > 0 ? ZC[i] : 0);
    if( !C[i+1] )   ZC[i+1]++;
    //else          OC[i+1]++;
  }

  for(int i=1; i*i<=a; i++)
    if( a%i==0 )
    {
      if( i<=n && a/i<=m )    check(i, a/i);
      if( i*i<a && i<=m && a/i<=n )    check(a/i, i);
    }

  fout << max0 << " " << tocc0 << endl;
	
	return 0;
}
