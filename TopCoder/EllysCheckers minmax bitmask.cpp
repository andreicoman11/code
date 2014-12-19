// BEGIN CUT HERE
// PROBLEM STATEMENT
// Elly and Kriss play a game. The game is played on a single 
// row that consists of N cells; we will call it the board. 
// The cells of the board are numbered 0 through N-1, from 
// the left to the right. Each cell of the board is either 
// empty or occupied by a single checker. The girls take 
// alternating turns, until one of them cannot make a move. 
// The girl who is unable to make a move loses the game.
// 
// In each move the current player selects a cell containing 
// a checker and performs one of the following two types of 
// moves:
// 
// A step, in which the checker is moved one cell to the 
// right. The step can only be made if the target cell is 
// empty.
// A jump, in which the checker jumps three cells to the 
// right. The jump can only be made if the target cell is 
// empty and the cells it jumped over contain two other 
// checkers.
// 
// Once a checker reaches the rightmost cell, it disappears 
// immediately and no longer plays any role in the game.
// 
// The initial layout of the board will be given as a string 
// board. The i-th character of board will be '.' (a period) 
// if the i-th cell is empty at the
// beginning, and it will be 'o' (lowercase letter o) if the 
// i-th cell initially contains a checker. Assume that both 
// girls play optimally. Return "YES" (quotes for clarity) if 
// the first player wins the game and "NO" otherwise.
// 
// DEFINITION
// Class:EllysCheckers
// Method:getWinner
// Parameters:string
// Returns:string
// Method signature:string getWinner(string board)
// 
// 
// NOTES
// -If there is a checker on the rightmost cell in the 
// beginning of the game, it disappears instantly (before the 
// first move is made), as if it were never there.
// -The rules of the game ensure that each cell contains at 
// most one checker at any time, and that no checker can jump 
// beyond the last cell.
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 20 characters, inclusive.
// -Each character of board will be either '.' or 'o'.
// 
// 
// EXAMPLES
// 
// 0)
// ".o..."
// 
// Returns: "YES"
// 
// With only one checker it is pretty obvious who will win.
// 
// 1)
// "..o..o"
// 
// Returns: "YES"
// 
// Don't forget to ignore checkers on the rightmost cell.
// 
// 2)
// ".o...ooo..oo.."
// 
// Returns: "NO"
// 
// Here one can jump the checker from cell 5 to cell 8.
// 
// 3)
// "......o.ooo.o......"
// 
// Returns: "YES"
// 
// 4)
// ".o..o...o....o.....o"
// 
// Returns: "NO"
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
map<int, bool> win;
map<int, int> comp;
int n;
class EllysCheckers {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

	public: 
   int getNo(vector<int> v)
   {
      int nr = 0;
      for(int i=0; i<n-1; i++)
         nr = (nr<<1) + v[i];
      return nr;
   }

   bool isWinBoard(vector<int> v)
   {
      v[n-1] = 0;
      int nr = getNo(v);
      if( comp[nr]==1 )
         return win[nr];

      bool canWin = 0;
      for(int i=0; !canWin && i<n-1; i++)
         if( v[i]==1 )
         {
            if( i+1<n && v[i+1]==0 )
            {
               v[i] = 0; v[i+1] = 1;
               if( !isWinBoard(v) ) canWin = 1;
               v[i+1] = 0; v[i] = 1;
            }
            else if( i+3<n && v[i+1]==1 && v[i+2]==1 && v[i+3]==0)
            {
               v[i] = 0; v[i+3] = 1;
               if( !isWinBoard(v) ) canWin = 1;
               v[i+3] = 0; v[i] = 1;
            }
         }

      comp[nr] = 1;
      win[nr] = canWin;
      return canWin;
   }
	string getWinner(string board) {
      n = board.sz;
      vector<int> v(board.size());
      for(int i=0; i<board.sz; i++)
         v[i] = (board[i]=='.' ? 0 : 1);

      comp[0] = 1;
      win[0] = 0;
      bool res = isWinBoard(v);
      return (res==1 ? "YES" : "NO");
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EllysCheckers ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
