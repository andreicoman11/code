#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "bemo.in" 
#define OUTFILE "bemo.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);
const static int NMAX = 1501;
int m[NMAX][NMAX], pos[NMAX*NMAX][2];

int main() {
   int r, c;
   fin >> r >> c;
   for(int i=0; i<r; i++)
   for(int j=0; j<c; j++) {
      fin >> m[i][j];
      pos[m[i][j]][0] = i;
      pos[m[i][j]][1] = j;
   }

   for(int p=1; p<=r*c; p++)
      if( pos[p][0]!=-1 ) {
         int x = pos[p][0];
         int y = pos[p][1];
         for(int i=x+1; i<r; i++) {
            if( m[i][y-1]==0 ) break;
            for(int j=y-1; m[i][j] && j>=0; j--) {
               pos[m[i][j]][0] = pos[m[i][j]][1] = -1;
               m[i][j] = 0;
            }
         }

         for(int i=x-1; i>=0; i--) {
            if( m[i][y+1]==0 ) break;
            for(int j=y+1; m[i][j] && j<c; j++) {
               pos[m[i][j]][0] = pos[m[i][j]][1] = -1;
               m[i][j] = 0;
            }
         }
      }

   fout << m[0][0];
   for(int i=0, j=0; i<r-1 || j<c-1; ) {
      if( m[i+1][j] ) i++;
      else           j++;
      fout << " " << m[i][j];
   }

   return 0;
}
