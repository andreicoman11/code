#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

#define LL long long
#define INFILE "planificare.in" 
#define OUTFILE "planificare.out"
#define NMAX 100010

int n, k, v[NMAX][2];

int comp(const void * a, const void * b) {
   if(  ((int*)a)[1] == ((int*)b)[1] ) 
      return  (((int*)a)[0] - ((int*)b)[0]);
  return ( ((int*)a)[1] - ((int*)b)[1] );
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; ++i)
  {
     scanf("%d %d", &v[i][0], &v[i][1]);
  }
  /*n = 100000;
  k = 3;
  for(int i=0; i<n; i++)
     v[i][0] = i + 1, v[i][1] = i + 110;*/
  if( k>=n )
  {
     cout << n << endl;
     return 0;
  }

  qsort (v, n, 2*sizeof(int), comp);

  multiset<int> sh;
  for(int i=0; i<k; ++i)
  {
     sh.insert(0);
     //sh.insert(v[i][1]);
  }

  int res = n;
  for(int i=0; i<n; ++i) 
  {
     multiset<int>::iterator it = sh.upper_bound(v[i][0]);
     if( it==sh.begin() ) 
     {
        --res;
     }
     else 
     {
         --it;
         sh.erase(it);
         sh.insert(v[i][1]);
     }
  }

  cout << res << endl;

	return 0;
}
