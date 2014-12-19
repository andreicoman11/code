#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

#define LL long long
#define pb push_back
#define INFILE "xspe.in" 
#define OUTFILE "xspe.out"
#define NMAX 1000005
int n, m[NMAX], v[NMAX], vn;

void add(int pos, int val)
{
   int i = vn-1;
   for(; i>=0 && val<m[v[i]]; i--)
      m[v[i]] += val;
   vn = i+2;
   v[i+1] = pos;
}

int main()
{
   FILE* fin = fopen(INFILE, "r");
   ofstream fout(OUTFILE);
   vn = 0;

   fscanf(fin, "%d", &n);
   for(int i=0; i<n; i++)
   {
      fscanf(fin, "%d", &m[i]);
      add(i, m[i]);
   }

   for(int i=0; i<n; i++)
      fout << m[i] << " ";
   fout << endl;
   fout.close();

   return 0;
}
