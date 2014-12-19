#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

#define LL long long
#define INFILE "traseu2.in" 
#define OUTFILE "traseu2.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);
#define MAXV 1000000000;
#define NMAX 72

int n, m, v[NMAX][NMAX], drum[NMAX*NMAX][2];

int main() {
   fin >> n >> m;
   int mini, minj, minv = MAXV;
   int found = 0;
   string buf;
   getline(fin, buf);
   for(int i=0; i<n; i++) {
      getline(fin, buf);
      for(int k=0; k<buf.size(); k++)
         if( buf[k]=='#' ) {
            buf[k] = '0';
            found++;
         }

      istringstream in(buf);
      for(int j=0; j<m; j++) {
         in >> v[i][j];
         if( v[i][j]<minv && v[i][j]!=0 ) {
            minv = v[i][j];
            mini = i;
            minj = j;
         }
      }
   }

   bool go = 1;
   int d = 0;
   while(go) {
      drum[d][0] = mini;
      drum[d][1] = minj;
      int x = mini, y = minj;
      minv = MAXV;
      go = 0;
      d++;
      for(int i=max(0,x-1); i<=min(n-1,x+1); i++)
      for(int j=max(0,y-1); j<=min(m-1,y+1); j++)
         if( v[i][j]>v[x][y] && v[i][j]<minv ) {
            mini = i;
            minj = j;
            minv = v[i][j];
            go = 1;
         }
   }

   if( d+found==n*m ) {
      fout << "Exista solutie!\n";
      fout << d << "\n";
      for(int i=0; i<d; i++)
         fout << drum[i][0]+1 << " " << drum[i][1]+1 << " " << v[drum[i][0]][drum[i][1]] << "\n";
   } else
      fout << "Nu exista solutie!";

   return 0;
}
