#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "kfib.in" 
#define OUTFILE "kfib.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int MOD = 666013;
int z[2][2], zk[2][2], aux[2][2];

void mul(int a[2][2], int b[2][2], int c[2][2]) {
   for(int i=0; i<2; i++)
   for(int j=0; j<2; j++) {
      c[i][j] = 0;
      for(int k=0; k<2; k++)
         c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
   }
}

int main() {
   int k;
   fin >> k;
   if( k<=1 ) {
      fout << k;
      return 0;
   }

   k--;
   z[0][0] = 0;
   z[0][1] = z[1][0] = z[1][1] = 1;
   zk[0][0] = zk[1][1] = 1;
   zk[0][1] = zk[1][0] = 0;
   for(int i=0; (1<<i)<=k; i++) {
      if( k & (1<<i) ) {
         mul(zk, z, aux);
         zk[0][0] = aux[0][0];
         zk[0][1] = aux[0][1];
         zk[1][0] = aux[1][0];
         zk[1][1] = aux[1][1];
      }
      mul(z, z, aux);
      z[0][0] = aux[0][0];
      z[0][1] = aux[0][1];
      z[1][0] = aux[1][0];
      z[1][1] = aux[1][1];
   }
   fout << zk[1][1];

   return 0;
}
