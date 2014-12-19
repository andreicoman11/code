#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long
#define INFILE "algsort.in" 
#define OUTFILE "algsort.out"
#define NMAX 500000

int n, v[NMAX];

int comp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void quick_sort()
{
  qsort (v, n, sizeof(int), comp);
  for(int i=0; i<n; i++)
    printf("%d ",  v[i]);
}

void heap_sort()
{
  vector<int> v2(v,v+n);
  make_heap(v2.begin(), v2.end());
  sort_heap(v2.begin(), v2.end());
  for(int i=0; i<n; i++)
    printf("%d ",  v2[i]);
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", &v[i]);

  quick_sort();
  //heap_sort();

	return 0;
}
