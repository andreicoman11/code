#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define FORit(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define INFILE "deque.in" 
#define OUTFILE "deque.out"
#define NMAX 5000001

int n, k, v[NMAX], d[NMAX], front, back;

void read() {
   FILE* fin = fopen(INFILE, "r");
   fscanf(fin, "%d %d\n", &n, &k);
   
   for(int i=0; i<n; i++)
      fscanf(fin, "%d", &v[i]);
}

int main() {
   freopen(OUTFILE, "w", stdout);
   read();

   LL s = 0LL;
   front = back = 0;
   d[0] = 0;
   for(int i=1; i<n; i++) {
      while( front<=back && v[d[back]]>v[i] ) back--;
      while( front<=back && d[front]+k<=i ) front++;

      d[++back] = i;
      if( i+1>=k ) s += (v[d[front]]);
   }
   cout << s << endl;
   return 0;
}
