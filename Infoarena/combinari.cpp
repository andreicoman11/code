#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "combinari.in" 
#define OUTFILE "combinari.out"

int v[32] = {0}, n, k;

void back(int i, int val)
{
  if( i>=k )
  {
    for(int l=0; l<k; l++)
      printf("%d ", v[l]);
    printf("\n");
  }
  else
  {
    for(int l=val+1; l+(k-i-1)<=n; l++)
    {
      v[i] = l;
      back(i+1, l);
    }
  }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n >> k;
  back(0, 0);
	
	return 0;
}
