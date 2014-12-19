#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE ".in" 
#define OUTFILE "submultimi.out"

int n;
bool v[32] = {0};

void back(int i, bool ok)
{
  if( i>=n )
  {
    if( ok )
    {
      for(int i=0; i<n; i++)
        if( v[i] ) printf("%d ", i+1);
      printf("\n");
    }
  }
  else
    for(int j=0; j<2; j++)
    {
      v[i] = j;
      back(i+1, ok || j);
    }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  cin >> n;
  back(0, 0);
	
	return 0;
}
