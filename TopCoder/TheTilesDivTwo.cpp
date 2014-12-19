// BEGIN CUT HERE
// PROBLEM STATEMENT
// John and Brus have a rectangular chessboard with black and 
// white tiles.
// Rows and columns of the chessboard are numbered starting 
// from 0.
// The cell at row i, column j is black if i+j is even and it 
// is white if i+j is odd.
// 
// 
// Some of the cells of the chessboard are occupied by chess 
// pieces.
// You are given a vector <string> board.
// For each i and j, the j-th character of the i-th element 
// (0-based indices) of board is 'X' if the cell in row i, 
// column j of the chessboard contains a chess piece.
// Otherwise, the j-th character of the i-th element of board 
// is '.'.
// 
// 
// John and Brus also have an infinite supply of L-shaped 
// tiles.
// Each tile consists of three squares which are of the same 
// size as the cells of the chessboard.
// I.e., each tile looks as follows:
// 
// OO
// O
// 
// 
// John and Brus want to place some of the tiles onto their 
// chessboard, according to the following rules:
// 
// Each tile may be rotated by any multiple of 90 degrees.
// Each tile must cover exactly three cells of the chessboard.
// Tiles are not allowed to overlap.
// Tiles are not allowed to cover the cells that are already 
// occupied by the chess pieces.
// The corner cell of each tile must cover a black cell of 
// the chessboard.
// 
// 
// 
// Return the maximum number of tiles John and Brus can place 
// on the board according to the above rules.
// 
// 
// DEFINITION
// Class:TheTilesDivTwo
// Method:find
// Parameters:vector <string>
// Returns:int
// Method signature:int find(vector <string> board)
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 4 elements, inclusive.
// -Each element of board will contain between 1 and 47 
// characters, inclusive.
// -All elements of board will contain the same number of 
// characters.
// -Each element of board will consist of only characters 'X' 
// and '.'.
// 
// 
// EXAMPLES
// 
// 0)
// {"X.X",
//  "...",
//  "X.X"}
// 
// Returns: 1
// 
// Since only one black cell is available, just one tile can 
// be placed on the board.
// 
// 1)
// {"...",
//  "...",
//  "..."}
// 
// Returns: 2
// 
// 
// 
// 2)
// {"......X.X.XXX.X.XX."}
// 
// Returns: 0
// 
// 
// 
// 3)
// {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
//  ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
//  "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
//  "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."}
// 
// Returns: 13
// 
// 
// 
// END CUT HERE
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define LL long long
#define pb push_back
#define sz size()
static const int MAXN = 512;

vector<int> e[MAXN];
bool vis[MAXN];
int t[MAXN], f[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class TheTilesDivTwo {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X",
 "...",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"......X.X.XXX.X.XX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

	public: 
   int getflow(int s, int d) {
      memset(vis, 0, sizeof(vis));
      memset(t, 0x3f3f3f3f, sizeof(t));
      t[s] = -1;
      vis[s] = 1;
      queue<int> q;
      q.push(s);
      while( !vis[d] && !q.empty() ) {
         int nod = q.front();
         q.pop();
         for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
            if( f[nod][*it]==1 && !vis[*it] ) {
               t[*it] = nod;
               vis[*it] = 1;
               q.push(*it);
            }
      }

      if( !vis[d] ) return 0;

      while( t[d]!=-1 ) {
         f[t[d]][d] = 0;
         f[d][t[d]] = 1;
         d = t[d];
      }
      return 1;
   }

   inline int IN(int x) {return x*2;};
   inline int OUT(int x) {return x*2+1;};

   void add_edge(int a, int b) {
      e[a].push_back(b);
      e[b].push_back(a);
      f[a][b] = 1;
      f[b][a] = 0;
   }

	int find(vector <string> b) {
		int r = b.size(), c = b[0].size();
      int n = r*c, s = IN(n), d = OUT(n);

      for(int i=0; i<n; i++)
         add_edge(IN(i), OUT(i));

      for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
         if( (i+j)%2 && b[i][j]=='.' ) {
            if(i%2)
               add_edge(s, IN(i*c + j));
            else
               add_edge(OUT(i*c + j), d);

            for(int k=0; k<4; k++) {
               int x = i + dx[k];
               int y = j + dy[k];
               if(x>=0 && y>=0 && x<r && y<c && b[x][y]=='.' ) {
                  if( i%2 )
                     add_edge(OUT(i*c+j), IN(x*c+y));
                  else
                     add_edge(OUT(x*c+y), IN(i*c+j));
               }
            }

         }

      int flow = 0;
      while( getflow(s, d) ) {
         flow++;
      }

      return flow;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TheTilesDivTwo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
