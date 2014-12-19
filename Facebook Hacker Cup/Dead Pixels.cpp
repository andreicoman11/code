#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
using namespace std;
#define HMAX 40005

ifstream fin ("dead_pixels.txt");
//ifstream fin (".in");
ofstream fout (".out");

int W, H, P, Q, N, X, Y, a, b, c, d;
int drept[1000000][4];

bool comp(int a, int b) {
   return drept[a][0] < drept[b][0];
}

void solve() {
   fin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;

   vector<vector<int> > st(HMAX), en(HMAX);   

   for(int i=0; i<N; i++){
      //map[Y][X] = 1;
      drept[i][0] = max(0, Y-Q+1);
      drept[i][1] = max(0, X-P+1);
      drept[i][2] = Y;
      drept[i][3] = X;
      //drept[2*i][0] = max(0, Y-Q+1);
      //drept[2*i][1] = max(0, X-P+1);
      //drept[2*i][2] = Y;
      //drept[2*i][3] = X;
      //drept[2*i+1][0] = Y;
      //drept[2*i+1][1] = X;
      //drept[2*i+1][2] = min(H-1, Y+Q-1);
      //drept[2*i+1][3] = min(W-1, X+P-1);

      st[ drept[i][0] ].push_back(i);
      en[ drept[i][2]+1].push_back(i);
      //st[ drept[2*i][0] ].push_back(2*i);
      //en[ drept[2*i][2]+1].push_back(2*i);
      //st[ drept[2*i+1][0] ].push_back(2*i+1);
      //en[ drept[2*i+1][2]+1].push_back(2*i+1);

      int X2 = (X * a + Y * b + 1) % W;
      int Y2 = (X * c + Y * d + 1) % H;
      X = X2;
      Y = Y2;
   }

   int sum = 0, good = W-P+1;
   multiset<pair<int,int> > s;
   for(int i=0; i<H-Q+1; i++)
   {
      bool ch = 0;

      for(int j=0; j<st[i].size(); j++)
      {
         s.insert(make_pair(drept[st[i][j]][1], drept[st[i][j]][3]));
         ch = 1;
      }

      for(int j=0; j<en[i].size(); j++)
      {
         s.erase(s.find(make_pair(drept[en[i][j]][1], drept[en[i][j]][3])));
         ch = 1;
      }

      int wmax = W-P+1;
      if( ch ){
         good = 0;
         int j = 0;
         for(auto it=s.begin(); j<wmax && it!=s.end(); it++){
            if( it->first>j ) good += min(wmax, it->first) - j;
            j = max(j, it->second+1);
         }
         if( j<wmax ) good += wmax - j;
      }
      sum += good;
   }

   fout << sum << '\n';
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