#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "carti2.in" 
#define OUTFILE "carti2.out"
#define CMAX 4100
#define NMAX 16

int hmin[CMAX], n, h, l, g, a[NMAX], b[NMAX];
int bmax, cval;

void back(int i, int hmax, int l2, int hcval, int hval, int books)
{
  if( i>=n )
  {
    //cout << hval << " " << hcval << "\n";
    if( hmax==0 ) return;
    if( l2<=l ) 
    {
      hmin[hval] = min( hmin[hval], hmin[hcval] + g + hmax);
    
      if( hmin[hval] <= h && (books>bmax || (books==bmax && hval>cval)) )
      {
        bmax = books;
        cval = hval;
        //cout << "\nbmax : " << hval << " " << hmax << " " << l2 << " " << hcval << " " << books << " " << hmin[hval] << " " << hmin[hcval] << "\n";
      }
    }
  }
  else
  {
    hcval<<=1, hval<<=1;
    back(i+1, hmax, l2, hcval, hval, books);
    back(i+1, max(hmax, a[i]), l2+b[i], hcval, hval | 1, books+1);
    back(i+1, hmax, l2, hcval | 1, hval | 1, books+1);
  }
}
void printb(int val, int i)
{
  if( val ) printb(val>>1, i-1);
  if( val & 1 ) cout << i+1 << " ";

}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  int teste;
  cin >> teste;
  while( teste-- )
  {
    cin >> n >> h >> l >> g;
    for(int i=0; i<n; i++)
      cin >> a[i] >> b[i];

    hmin[0] = 0;
    for(int j=1; j<CMAX; j++)
      hmin[j] = h + 1;
    
    bmax = 0, cval = 0;
    back(0, 0, 0, 0, 0, 0);
    cout << bmax << "\n";
    printb(cval, n-1);
    cout << "\n";
  }

	return 0;
}
