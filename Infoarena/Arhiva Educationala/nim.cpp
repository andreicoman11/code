#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
#define INFILE "nim.in" 
#define OUTFILE "nim.out"


int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  int t, n, nxor, ni;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d %d", &n, &nxor);
    for(int i=1; i<n; i++)
    {
      scanf("%d", &ni);
      nxor = nxor ^ ni;
    }

    if( nxor ) cout << "DA\n";
    else cout << "NU\n";
  }
	
	return 0;
}
