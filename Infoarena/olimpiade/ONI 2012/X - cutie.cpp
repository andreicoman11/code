#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long
#define INFILE "cutie.in" 
#define OUTFILE "cutie.out"

int t, n, m, k;

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   cin >> t;
   while(t--)
   {
      cin >> n >> k >> m;
      vector<int> v(k+2);
      v[0] = 1;
      v[k+1] = n;
      for(int i=1; i<=k; i++)
         cin >> v[i];

      int imp=0, pi=0, bila;
      for(int i=0; i<m; i++)
      {
         cin >> bila;
         vector<int>::iterator it = lower_bound(v.begin(), v.end(), bila);
         it--;
         int dif1 = bila - (*it);
         it++;
         int dif2 = (*it) - bila;
         if( dif1%2 && dif2%2 ) imp++;
         else if( dif1%2 || dif2%2 ) pi++;
         //cout << bila << " " << dif1 << " " << dif2 << endl;
      }

      //cout << pi << " " << imp << " " << (pi + imp)%2 << endl;
      cout << ((pi%2) | (imp%2));
   }

   return 0;
}
