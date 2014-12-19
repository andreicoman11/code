#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "suma.in" 
#define OUTFILE "suma.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {
   long long n, p;
   fin >> n >> p;

   long long n1 = n-1;
   long long n2 = n+1;
   if( n%3LL==0 ) n /= 3LL;
   else if( n1%3LL==0 ) n1 /= 3LL;
   else if( n2%3LL==0 ) n2 /= 3LL;
   n %= p;
   n1 %= p;
   n2 %= p;
   long long s = n * n1 * n2;
   fout << s % p;


   return 0;
}
