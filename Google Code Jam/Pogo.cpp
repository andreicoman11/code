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
#include <stack>
#include <queue>
using namespace std;

//ifstream fin (".in");
//ifstream fin ("B-small.in");
ifstream fin ("B-large.in");
ofstream fout (".out");

map<int,int> sums_idx;
vector<int> sums;

void solve() {
   int x, y;
   int iix, iiy;
   fin >> x >> y;
   iix = x, iiy = y;
   string res = "";

   char up[] = {'N', 'S'};
   char r[] = {'E', 'W'};

   if( x<0 ) {
      x = -x;
      swap(r[0], r[1]);
   }

   if( y<0 ) {
      y = -y;
      swap(up[0], up[1]);
   }

   if( y==0 ) {
      swap(up[0], r[0]);
      swap(up[1], r[1]);
      y = x;
      x = 0;
   }

   int sum = x + y;
   int pos = sums_idx[ *lower_bound(sums.begin(), sums.end(), sum) ];
   cout << sum << " " << pos << " " << pos*(pos+1)/2 << "\t";

   if( x==1 && pos*(pos+1)/2 - sum==2 ) {
      swap(up[0], r[0]);
      swap(up[1], r[1]);
      y = x;
      x = 0;
   }

   while( (pos*(pos+1)/2 - sum) % 2 == 1 ) pos++;

   int detour = (pos * (pos+1) / 2 - sum) / 2;
   cout << pos << " " << detour << endl;

   vector<int> cul(pos+1, 0);

   for(int i=min(pos,detour); i && detour; i--) {
         if( i>detour ) i = detour;
         if( cul[i]==0 ) {
            detour -= i;
            cul[i] = 2;
         }
   }

   for(int i=min(pos,x), x2 = x; i && x2; i--) {
         if( i>x2 ) i = x2;
         if( cul[i]==0 ) {
            x2 -= i;
            cul[i] = 1;
         }
   }

   for(int i=1; i<=pos; i++) {
      if( cul[i]==2 ) {
         res += up[1];
         y += i;
      }
      else if( i<=x && cul[i] ) {
         res += r[0];
         x -= i;
      } 
      else {
         res += up[0];
         y -= i;
      }
      //cout << x << " " << y << endl;
   }


   fout << res << endl;
   if( x || y) cout << "Problem with x,y: " << iix << " " << iiy << "\tleft " << x << " " << y << endl;
   x = y = 0;
   for(int i=0; i<res.size(); i++)
      if( res[i]=='N' ) y+=i+1;
      else if( res[i]=='S' ) y-=i+1;
      else if( res[i]=='E' ) x+=i+1;
      else if( res[i]=='W' ) x-=i+1;
   if( iix!=x || iiy!=y ) {
      cout << "Problem: " << iix << " " << iiy << "\tbut got" << x << " " << y << endl;
   }
}

int main() {
   for(int i=1; i<10000; i++) {
      sums.push_back(i * (i+1) / 2);
      sums_idx[i * (i+1) / 2] = i;
   }

   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}