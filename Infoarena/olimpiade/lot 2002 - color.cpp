#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

#define INFILE "color.in" 
#define OUTFILE "color.out"

const int NMAX = 4002;
int rosii[NMAX];
char buf[5500001];

int main() {
   int n, m;
   FILE* fin = fopen(INFILE, "r");
   fscanf(fin, "%d %d", &n, &m);

   fread(buf, 1, m * 11, fin);
   int len = strlen(buf), a = 0;
   for(int i=0; i<len; i++) 
      if( isdigit(buf[i]) ) 
         a = a*10 + int(buf[i]) - int('0');
      else if(a) {
         rosii[a-1]++;
         a = 0;
      }
   if(a)
      rosii[a-1]++;

   long long res = 0LL;
   long long N = n;
   for(int i=0; i<n; i++)
      res += (long long)(rosii[i] * (n - 1 - rosii[i]));
   
   FILE* fout = fopen(OUTFILE, "w");
   fprintf(fout, "%lld", N * (N-1LL) * (N-2LL) / 6LL - res / 2LL);

   return 0;
}
