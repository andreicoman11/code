#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define LL long long
#define INFILE "inv.in" 
#define OUTFILE "inv.out"
#define MOD 9917
#define NMAX 100010

int sinv = 0, n, v[NMAX], aux[NMAX];

void merge_sort(int l, int r)
{
  if( l>=r ) return;
  int mid = (l+r) >> 1;
  if(l<mid) merge_sort(l, mid);
  if(mid+1<r) merge_sort(mid+1, r);

  memcpy(aux + l, v + l, sizeof(int)*(r-l+1));
  int a = l, b = mid + 1, left = mid - l + 1;
  for(int i=l; i<=r; i++)
    if( b>r || (a<=mid && aux[a]<=aux[b]) ) 
    {
      v[i] = aux[a++];
      left--;
    }
    else
    {
      v[i] = aux[b++];
      sinv = (sinv+left) % MOD;
    }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &v[i]);

  merge_sort(0, n-1);  
  cout << sinv << "\n";

	return 0;
}
