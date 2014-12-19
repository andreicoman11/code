#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define LL long long
#define INFILE "scmax.in" 
#define OUTFILE "scmax.out"
//#define AMAX 2000000000
#define NMAX 100001

int N;
int mina[NMAX], a[NMAX], prev[NMAX];
bool viz[NMAX];
int best = -1;

void add(int lv, int rv, int val)
{
  while( lv != rv )
  {
    int mid = (lv + rv) >> 1;
    if( viz[mid]==1 && a[val] > a[mina[mid]] )
      lv = mid+1;
    else rv = mid;
  }

  if( lv>0 ) prev[val] = mina[lv-1];
  if( viz[lv]==0 || a[mina[lv]]>a[val] )
  {
    mina[lv] = val;
    viz[lv] = 1;
    if( lv>best ) best = lv;
  }
}

void printarray(int val, int i)
{
  if( i>=0 )
  {
    printarray(prev[val], i-1);
    printf("%d", a[val]);
    if( i<best ) printf(" ");
  }
}

int main()
{
  memset(viz, 0, sizeof(viz));
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  scanf("%d", &N);
  for(int i=0; i<N; i++)
  {
    scanf("%d", &a[i]);
    add(0, N, i);
  }

  printf("%d\n", best+1);
  printarray(mina[best], best);
	
	return 0;
}
