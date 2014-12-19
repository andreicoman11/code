#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <deque>
using namespace std;

#define LL long long
#define FORit(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define INFILE "secventa.in" 
#define OUTFILE "secventa.out"
#define NMAX 500001

int v[NMAX], n, k;
deque<int> s, u;

char buf[3500000];

void read() {
   FILE* fin = fopen(INFILE, "r");
   fscanf(fin, "%d %d\n", &n, &k);
   fgets(buf, 3500000, fin);
   fclose(fin);
   int len = strlen(buf), j=0, sign=1, nr=0, i=0;
   while( i<len ) {
      if( buf[i]==' ' ) {
         v[j] = nr * sign;
         j++;
         sign = 1;
         nr = 0;
      } else if( buf[i]=='-' ) {
         sign = -1;
      } else {
         nr = nr*10 + (buf[i] - '0');
      }
      i++;
   }
   v[j] = nr * sign;
}

void ins(int i) {
   while( !s.empty() && s.back() >= v[i] )  {
      s.pop_back();
      u.pop_back();
   }
   
   s.push_back( v[i] );
   u.push_back( i );
}

int main() {
   freopen(OUTFILE, "w", stdout);

   read();
   for(int i=0; i<k; i++)
      ins(i);

   int minv = s.front(), is = 0, ie = k-1;
   for(int i=k; i<n; i++) {
      ins(i);
      
      while( u.front() <= i-k ) {
         u.pop_front();
         s.pop_front();
      }

      if( s.front() > minv ) {
         minv = s.front();
         is = i - k + 1;
         ie = i;
      }
   }

   cout << is+1 << " " << ie+1 << " " << minv << "\n";

   return 0;
}
