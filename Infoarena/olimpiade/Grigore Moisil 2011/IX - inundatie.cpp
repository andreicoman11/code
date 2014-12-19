#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long
#define INFILE "inundatie.in" 
#define OUTFILE "inundatie.out"

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);
   int n, m;
   cin >> n >> m;
   n *= m;
   vector<int> v(n);
   for(int i=0; i<n; i++)
      scanf("%d", &v[i]);

   sort(v.begin(), v.end());
   vector<int> a(n);
   a[0] = v[0];
   for(int i=1; i<n; i++)
      a[i] = a[i-1] + v[i];

   int q, x;
   cin >> q;
   for(int i=0; i<q; i++)
   {
      scanf("%d", &x);
      x--;
      if( x<1 ) {printf("0\n"); continue;}
      int l = 0, r = n-1, mid;
      bool go = 1;
      while( go )
      {
         mid = (l+r) >> 1;
         if( v[mid]==x ) go = 0;
         else if( v[mid]>x ) r = mid;
         else if( v[mid]<x ) l = mid;
         if( l+1>=r ) go = 0;
      }
      //cout << x << " " << l << " " << v[l] << " - " << r << " "<< v[r] << endl;
      if( v[mid]==x )      printf("%d\n", a[mid] + (n-mid-1) * x);
      else if( l==0 && v[l]>x ) printf("%d\n", n*x);
      else if( v[r]<x )    printf("%d\n", a[r]);
      else                 printf("%d\n", a[l] + (n-l-1) * x);
   }

   return 0;
}
