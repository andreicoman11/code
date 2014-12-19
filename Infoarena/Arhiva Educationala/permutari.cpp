#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define INFILE "permutari.in" 
#define OUTFILE "permutari.out"

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);
   int n; cin >> n;
   vector<int> v(n);

   for(int i=0; i<n; i++)
      v[i] = i+1;

   do{
      for(int i=0; i<n; i++)
         printf("%d ", v[i]);
      printf("\n");
   }while(next_permutation(v.begin(), v.end()));

   return 0;
}
