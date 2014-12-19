#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

//ifstream fin (".in");
//ifstream fin ("A-small.in");
ifstream fin ("A-large.in");
ofstream fout (".out");

string res[] = {"X won", "O won", "Draw", "Game has not completed"};

void solve() {
   bool x=0, o=0, all=1;

   char m[4][4], aux;
   for(int i=0; i<4; i++)
   for(int j=0; j<4; j++) {
      fin >> m[i][j];
      if( m[i][j]=='.' ) all = 0;
   }

   for(int i=0; i<4; i++) {
      int cnto=0, cntx=0;
      for(int j=0; j<4; j++)
         if( m[i][j]=='T' ) cntx++, cnto++;
         else if( m[i][j]=='X' ) cntx++;
         else if( m[i][j]=='O' ) cnto++;

      if( cntx==4 ) {
         x = 1;
         break;
      }
      if( cnto==4 ) {
         o = 1;
         break;
      }

      cnto=0, cntx=0;
      for(int j=0; j<4; j++)
         if( m[j][i]=='T' ) cntx++, cnto++;
         else if( m[j][i]=='X' ) cntx++;
         else if( m[j][i]=='O' ) cnto++;

      if( cntx==4 ) {
         x = 1;
         break;
      }
      if( cnto==4 ) {
         o = 1;
         break;
      }
   }

   if( !x && !o ) {
      int cnto = 0, cntx = 0;
      for(int i=0; i<4; i++)
         if( m[i][i]=='T' ) cntx++, cnto++;
         else if( m[i][i]=='X' ) cntx++;
         else if( m[i][i]=='O' ) cnto++;

      if( cntx==4 )
         x = 1;
      if( cnto==4 )
         o = 1;
      
      cnto = 0, cntx = 0;
      for(int i=0; i<4; i++)
         if( m[i][3-i]=='T' ) cntx++, cnto++;
         else if( m[i][3-i]=='X' ) cntx++;
         else if( m[i][3-i]=='O' ) cnto++;

      if( cntx==4 )
         x = 1;
      if( cnto==4 )
         o = 1;
   }
   
   if(x)          fout << res[0] << endl;
   else if(o)     fout << res[1] << endl;
   else if(all)   fout << res[2] << endl;
   else           fout << res[3] << endl;
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}