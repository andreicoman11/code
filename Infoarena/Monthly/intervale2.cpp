#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define LL long long
#define INFILE "intervale2.in" 
#define OUTFILE "intervale2.out"
#define NMAX 100010

ifstream fin(INFILE);
ofstream fout(OUTFILE);

struct arb{
   int pi;
   int i;
   int x;
};

int n, rez[NMAX], v[NMAX];
arb c[NMAX];

int comp(const void* a, const void* b) {
   return ((arb*)a)->x <= ((arb*)b)->x;
}

int get_sum(int pos) {
   int sum = 0;
   while( pos>0 ) {
      sum += v[pos];
      pos -= (pos & -pos);
   }
   return sum;
}

void bit_add(int pos, int val) {
   while( pos<=n ) {
      v[pos] += val;
      pos += (pos & -pos);
   }
}

int main() {
   memset(v, 0, sizeof(v));
   fin >> n;
   for(int i=1; i<=n; i++)
      fin >> c[i].x;

   for(int i=1; i<=n; i++) {
      fin >> c[i].pi;
      c[i].i = i;
   }

   qsort(&c[1], n, sizeof(arb), comp);

   for(int i=1; i<=n; i++) {
      rez[ c[i].i ] = get_sum(c[i].i) - get_sum(c[i].pi - 1);
      bit_add( c[i].i ,1 );
   }

   for(int i=1; i<=n; i++)
      fout << rez[i] << " ";

   return 0;
}
