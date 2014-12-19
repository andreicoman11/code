// BEGIN CUT HERE
// PROBLEM STATEMENT
// The pony Applejack has an N by N hexagonal board. The 
// following picture shows the hexagonal board when N = 1, 2, 
// 3, and 4.
// 
// 
// 
// 
// 
// She wants to color some cells of the board. You are given 
// a vector <string> board. If the j-th character of the i-th 
// element of board is 'X', she wants to color the cell (i, 
// j). If she colors two cells that share an edge, she must 
// use different colors for those cells. Return the minimal 
// number of colors she needs.
// 
// DEFINITION
// Class:HexagonalBoard
// Method:minColors
// Parameters:vector <string>
// Returns:int
// Method signature:int minColors(vector <string> board)
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 50 elements, inclusive.
// -Each element of board will contain exactly N characters, 
// where N is the number of elements in board.
// -Each character in board will be either 'X' or '-'.
// 
// 
// EXAMPLES
// 
// 0)
// {"---",
//  "---",
//  "---"}
//  
// 
// Returns: 0
// 
// She won't color any cells, so she won't need any colors.
// 
// 1)
// {"-X--",
//  "---X",
//  "----",
//  "-X--"}
// 
// Returns: 1
// 
// She can color all cells with the same color.
// 
// 2)
// {"XXXX",
//  "---X",
//  "---X",
//  "---X"}
// 
// Returns: 2
// 
// For example, she can color cells in the following way:
// 
// Color cells (0, 0), (0, 2), (1, 3), and (3, 3) red.
// Color cells (0, 1), (0, 3), and (2, 3) blue.
// 
// 
// 
// 3)
// {"XX-XX--"
// ,"-XX-XXX"
// ,"X-XX--X"
// ,"X--X-X-"
// ,"XX-X-XX"
// ,"-X-XX-X"
// ,"-XX-XX-"}
// 
// Returns: 3
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

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0};
int c[64][64], maxc;

class HexagonalBoard {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"---",
 "---",
 "---"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

// END CUT HERE
   void dfs(vector<string> B, int n, int a, int b, int cul) {
      c[a][b] = cul;
      maxc = max(maxc, cul);
      if (maxc == 3) return;

      for (int k=0; k<6; k++) {
         int x = a + dx[k];
         int y = b + dy[k];
         if (x>=0 && y>=0 && x<n && y<n && B[x][y]=='X') {
            if (c[x][y] && c[x][y]==cul) {
               maxc = 3;
               return;
            }
            else if (!c[x][y]) {
               dfs(B, n, x, y, 3 - cul);
            }
         }
      }
   }

	public: 
		int minColors(vector <string> b) {
		memset(c, 0, sizeof(c));
      int n = b.size();
      maxc = 0;

      for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
         if (b[i][j]=='X' && !c[i][j]) dfs(b, n, i, j, 1);

      return maxc;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	HexagonalBoard ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE