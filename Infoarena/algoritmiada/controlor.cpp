#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#define LL long long
#define INFILE "controlor.in" 
#define OUTFILE "controlor.out"
#define NMAX 1002
int n, u[NMAX], c[NMAX];
vector<vector<int> > t;


void printc() {
   cout << "\n";
   for(int i=0; i<n; i++)
      cout << c[i] << " ";
   cout << "\n";
}
int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   cin >> n;
   t.resize(n-1);
   for(int i=0; i<n-1; i++)  {
      t[i].resize(n-i-1);
      for(int j=0; j<n-i-1; j++) {
         scanf("%d",  &t[i][j]);
         u[i] += t[i][j];
         c[i+j] += t[i][j];
      }
   }

   for(int i=0; i<n-1; i++) {
      int in = u[i];
      printf("%d", u[i]);
      for(int j=1; j<n-i-1; j++) {
         in += u[i+j] - c[i+j-1];
         printf(" %d", in);
      }
      for(int j=0; j<n-i-1; j++)
         c[i+j] -= t[i][j];
      printf("\n");
      //printc();
   }

   return 0;
}
