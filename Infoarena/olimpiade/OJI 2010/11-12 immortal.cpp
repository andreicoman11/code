#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "immortal.in" 
#define OUTFILE "immortal.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

const int NMAX = 16, MMAX = 25;
int n, m, x, pos[NMAX][2], map[MMAX][MMAX], res = 0, sol[NMAX][4];
bool vis[1<<NMAX];

void print_sol() {
   for(int i=0; i<x-1; i++)
      fout << sol[i][0] << " " << sol[i][1] << " " << sol[i][2] << " " << sol[i][3] << '\n';
}

bool can_move(int x1, int y1, int x2, int y2) {
   if( map[x1][y1]==0 ) return 0;
   if( map[x2][y2]==0 ) return 0;
   if( x1==x2 ) y2 = y1 + 2*(y2-y1);
   if( y1==y2 ) x2 = x1 + 2*(x2-x1);

   if( x2<0 || x2>=n || y2<0 || y2>=m ) return 0;
   if( map[x2][y2] ) return 0;
   return 1;
}

void move(int x1, int y1, int x2, int y2, int ipos, int poscnt) {
   if( x1==x2 ) y2 = y1 + 2*(y2-y1);
   if( y1==y2 ) x2 = x1 + 2*(x2-x1);

   pos[ipos][0] = x2;
   pos[ipos][1] = y2;
   map[x2][y2] = 1 - map[x2][y2];
   map[x1][y1] = 1 - map[x1][y1];
   map[(x1+x2)/2][(y1+y2)/2] = 1 - map[(x1+x2)/2][(y1+y2)/2];

   sol[poscnt][0] = x1 + 1;
   sol[poscnt][1] = y1 + 1;
   sol[poscnt][2] = x2 + 1;
   sol[poscnt][3] = y2 + 1;
}

void search(int rem, int cnt) {
   //cout << rem << " " << cnt << endl;
   //for(int i=0; i<n; i++) {
   //   for(int j=0; j<m; j++)
   //      cout << map[i][j] << " " ;
   //   cout << endl;
   //}
   if( vis[rem] || res ) return;
   vis[rem] = 1;
   if( cnt==1 ) {
      res = rem;
      print_sol();
      return ;
   }

   for(int i=0; !res && i<x; i++)
   for(int j=i+1; !res && j<x; j++)
      if(   (pos[i][0]==pos[j][0] && abs(pos[i][1]-pos[j][1])==1) ||
            (pos[i][1]==pos[j][1] && abs(pos[i][0]-pos[j][0])==1) ) {
         // jump i over j
         if( can_move(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) ) {
            move(pos[i][0], pos[i][1], pos[j][0], pos[j][1], i, x-cnt);
            search( rem ^ (1<<j), cnt-1);
            move(pos[i][0], pos[i][1], pos[j][0], pos[j][1], i, x-cnt);
         }

         // jump j over i
         if( can_move(pos[j][0], pos[j][1], pos[i][0], pos[i][1]) ) {
            move(pos[j][0], pos[j][1], pos[i][0], pos[i][1], j, x-cnt);
            search( rem ^ (1<<i), cnt-1);
            move(pos[j][0], pos[j][1], pos[i][0], pos[i][1], j, x-cnt);
         }

      }
}

int main() {
   fin >> n >> m >> x;

   for(int i=0; i<x; i++) {
      fin >> pos[i][0] >> pos[i][1];
      pos[i][0]--;
      pos[i][1]--;
      map[pos[i][0]][pos[i][1]] = 1;
   }

   search((1<<x) - 1, x);
   
   return 0;
}
