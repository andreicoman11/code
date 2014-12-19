#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

#define LL long long
#define INFILE "mergesort.in" 
#define OUTFILE "mergesort.out"
#define NMAX 1000010
#define NMAX2 500010
#define MOD (LL)1000003

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n;
int s[NMAX], c[NMAX][2];
int p[NMAX];

LL comb(int x, int t)
{
   if( c[x][t] ) return c[x][t];
   LL prod = 1;

   for(LL i=x-(x/2)+1; i<=x; i++)
      prod = (prod * i) % MOD;
   c[x][1] = prod;
   if( x%2 ) c[x][0] = (prod * (x-x/2))%MOD;
   else c[x][0] = c[x][1];
   return c[x][t];
}

LL score(int x) 
{
   if( s[x] ) return s[x];
   int x1 = x/2;
   int x2 = x - x1;

   //LL cx = comb(x);
   //LL px1 = p[x1], px2 = p[x2];
   //LL sc1 = score(x1), sc2 = score(x2);
   //s[x] = (cx * (( (px1*px2)%MOD + (sc1*px2)%MOD + (px1*sc2)%MOD )%MOD) - (LL)2 + MOD) % MOD;

   LL px = p[x];
   LL px1 = comb(x,0), px2 = comb(x,1);
   LL sc1 = score(x1), sc2 = score(x2);
   s[x] = (px + (px1*sc1)%MOD + (px2*sc2)%MOD - (LL)2 + MOD) % MOD;

   return s[x];
}

int main() {
   fin >> n;

   p[1] = 1;
   for(LL i=2; i<=n; i++)
      p[i] = (i * p[i-1]) % MOD;

   s[1] = 1;
   s[2] = 4;

   fout << score(n) << '\n';

   return 0;
}
