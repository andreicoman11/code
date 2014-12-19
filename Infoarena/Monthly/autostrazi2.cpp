#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "autostrazi2.in" 
#define OUTFILE "autostrazi2.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);
static const int NMAX = 1004;
bool e[NMAX][NMAX];
int n, m;

int main() {
   fin >> n >> m;
   for(int i=0; i<m; i++) {
      int a, b;
      fin >> a >> b;
      e[a-1][b-1] = e[b-1][a-1] = 1;
   }

   vector<int> v(n);
   for(int i=0; i<n; i++)
      v[i] = i;

   for(int i=0; i<n-1; i++)
      if( e[v[i]][v[i+1]]==0 ) {
         
         for(int j=0; j<n-1; j++)
            if( e[v[i]][v[j]] && e[v[i+1]][v[j+1]] ) {
               int k = min(i,j) + 1;
               int l = max(i,j);
               while(k<l) {
                  int aux = v[k];
                  v[k] = v[l];
                  v[l] = aux;
                  k++;
                  l--;
               }

               break;
            }

         
      }
      
   for(int i=0; i<n; i+=2)
      fout << v[i]+1 << " " << v[i+1]+1 << '\n';

   return 0;
}
