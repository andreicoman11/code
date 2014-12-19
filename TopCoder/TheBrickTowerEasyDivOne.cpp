// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// John and Brus are building towers using toy bricks.
// They have two types of bricks: red and blue ones.
// The number of red bricks they have is redCount and each of 
// them has a height of redHeight.
// The number of blue bricks they have is blueCount and each 
// of them has a height of blueHeight.
// 
// 
// 
// A tower is built by placing bricks one atop another.
// A brick can be placed either on the ground, or on a brick 
// of a different color.
// (I.e., you are not allowed to put two bricks of the same 
// color immediately on one another.)
// A tower has to consist of at least one brick.
// The height of a tower is the sum of all heights of bricks 
// that form the tower.
// Two towers are considered to be different if they have 
// different heights.
// (Two towers of the same height are considered the same, 
// even if they differ in the number and colors of bricks 
// that form them.)
// 
// 
// 
// You are given the ints redCount, redHeight, blueCount and 
// blueHeight.
// Return the number of different towers that John and Brus 
// can build.
// 
// 
// 
// DEFINITION
// Class:TheBrickTowerEasyDivOne
// Method:find
// Parameters:int, int, int, int
// Returns:int
// Method signature:int find(int redCount, int redHeight, int 
// blueCount, int blueHeight)
// 
// 
// CONSTRAINTS
// -redCount will be between 1 and 474,747,474, inclusive.
// -redHeight will be between 1 and 474,747,474, inclusive.
// -blueCount will be between 1 and 474,747,474, inclusive.
// -blueHeight will be between 1 and 474,747,474, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 2
// 3
// 4
// 
// Returns: 4
// 
// John and Brus have 1 red brick of height 2 and 3 blue 
// bricks of height 4. Using these bricks, it's possible to 
// build 4 towers:
// red (height 2);
// blue (height 4);
// red, blue (height 6);
// blue, red, blue (height 10).
// 
// 1)
// 4
// 4
// 4
// 7
// 
// Returns: 12
// 
// 2)
// 7
// 7
// 4
// 4
// 
// Returns: 13
// 
// 3)
// 47
// 47
// 47
// 47
// 
// Returns: 94
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

class TheBrickTowerEasyDivOne {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = 4; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 4; int Arg3 = 7; int Arg4 = 12; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 4; int Arg3 = 4; int Arg4 = 13; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 47; int Arg2 = 47; int Arg3 = 47; int Arg4 = 94; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	public: 
	int find(int r, int rh, int b, int bh) {
      int res = 0;
      if( rh!=bh )
      {
         res = (min(b,r)-1) * 3;
         if( b==r ) res += 3;
         else        res += 4;
      }
      else
      {
         res = min(b,r) * 2;
         if( b!=r ) res++;
      }
		return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TheBrickTowerEasyDivOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
