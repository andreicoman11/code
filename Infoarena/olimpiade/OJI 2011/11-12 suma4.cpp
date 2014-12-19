#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "suma4.in" 
#define OUTFILE "suma4.out"

const static int NMAX = 64000;
const static int INF = 0x3f3f3f3f;

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int C[NMAX], cmin[NMAX], t[NMAX];

void printt(int v) {
   if( v!=1 ) printt(t[v]);
   fout << v << " ";
}

int main() {
   int n;
   fin >> n;
   for(int i=1; i<=n; i++) {
      fin >> C[i];
      cmin[i] = INF;
   }

   cmin[1] = C[1];
   int l=1, s=0;
   for(int i=1, r=1, c=1; i+l*l<=n; i++) {

      int val = s + l*l + (l+1)*(r-1) + c;
      if( cmin[val] > cmin[i] + C[val] )           {cmin[val] = cmin[i] + C[val]; t[val] = i; }
      if( cmin[val+1] > cmin[i] + C[val+1] )       {cmin[val+1] = cmin[i] + C[val+1]; t[val+1] = i; }
      if( cmin[val+l+1] > cmin[i] + C[val+l+1] )   {cmin[val+l+1] = cmin[i] + C[val+l+1]; t[val+l+1] = i; }
      if( cmin[val+l+2] > cmin[i] + C[val+l+2] )   {cmin[val+l+2] = cmin[i] + C[val+l+2]; t[val+l+2] = i; }
      //cout << i << " " << l << " " << s << " " << r << " " << c << "\t" << val << " " << val+1 << " " << val+l+1 << " " << val+l+2 << endl;

      c++;
      if( c>l ) c=1, r++;
      if( r>l ) s+=l*l, l++, r=1, c=1;
   }
   //cout << l << " " << s << endl;

   int smin = INF, scmin = -1;
   for(int i = s+1; i<=n; i++) {
      if( cmin[i] < smin ) {
         smin = cmin[i];
         scmin = i;
      }
   }
   //cout << scmin << "\n";
   //for(int i=1; i<=n; i++)
   //   cout << C[i] << " " << cmin[i] << "\n";

   fout << l << " " << smin << '\n';
   printt(scmin);

   return 0;
}
