#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "triangles.in" 
#define OUTFILE "triangles.out"

int v[160000][2];

int comp(const void* a, const void* b)
{
   return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   int n, k;
   cin >> n >> k;
   n = min(n, 30 * k);

   for(int i=0; i<n; i++) {
      scanf("%d", &v[i][0]);
      v[i][1] = i+1;
   }

   qsort(v, n, 2*sizeof(int), comp);
   for(int i=0; i<n; i++)
      if( v[i][0]+v[i+1][0] >= v[i+k-1][0] )
      {
         for(int j=i; j<i+k; j++)
            printf("%d ", v[j][1]);
         break;
      }


   return 0;
}
