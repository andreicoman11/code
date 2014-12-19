// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Marvin plays a simple game. The game is played with an 
// infinite supply of marbles and five bags, labeled "bag 0" 
// through "bag 4".
// 
// 
// 
// At the beginning, Marvin takes N marbles (where N is a 
// nonnegative integer) and places them into bag 0. The 
// remaining four bags are left empty.
// Marvin then follows this simple algorithm:
// 
// 
// 
//     Add a marble into bag 1.
//     Repeat forever:
//         Add a marble into bag 1.
//         Empty bag 4.
//         While there are marbles in bag 0:
//             While there are marbles both in bag 0 and in 
// bag 1:
//                 Remove a marble from bag 0.
//                 Remove a marble from bag 1.
//                 Add a marble into bag 2.
//                 Add a marble into bag 3.
//             End While
//             Add a marble into bag 4.
//             If bags 0 and 1 are both empty:
//                 Move all marbles from bag 3 to bag 4.
//                 TERMINATE THE GAME
//             End If
//             Move all marbles from bag 3 to bag 1.
//         End While
//         Move all marbles from bag 2 to bag 0.
//     End Repeat
// 
// 
// 
// You are given a long long N. Return a long long containing 
// the number of marbles that will be in bag 4 at the end of 
// Marvin's game. If Marvin's game does not terminate for the 
// given N, return -1 instead.
// 
// 
// DEFINITION
// Class:MinskyMysteryDiv2
// Method:computeAnswer
// Parameters:long long
// Returns:long long
// Method signature:long long computeAnswer(long long N)
// 
// 
// NOTES
// -You may assume that the answer always fits into a long 
// long.
// -Note that N is allowed to be zero.
// 
// 
// CONSTRAINTS
// -N will be between 0 and 10^12, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 
// Returns: 3
// 
// 
// 
// 1)
// 3
// 
// Returns: 4
// 
// 
// 
// 2)
// 4
// 
// Returns: 4
// 
// 
// 
// 3)
// 15
// 
// Returns: 8
// 
// 
// 
// 4)
// 24
// 
// Returns: 14
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
class MinskyMysteryDiv2 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 3LL; verify_case(0, Arg1, computeAnswer(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; verify_case(1, Arg1, computeAnswer(Arg0)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 4LL; verify_case(2, Arg1, computeAnswer(Arg0)); }
	void test_case_3() { long long Arg0 = 15LL; long long Arg1 = 8LL; verify_case(3, Arg1, computeAnswer(Arg0)); }
	void test_case_4() { long long Arg0 = 24LL; long long Arg1 = 14LL; verify_case(4, Arg1, computeAnswer(Arg0)); }

// END CUT HERE

	public: long long computeAnswer(long long N) {
      if( N<2 ) return -1;
      if( N%2==0 ) return N/2 + 2;
      for(long long i=3; i*i <= N; i+=2)
         if( N%i==0 )
         {
            return N/i + i;
         }
      return N + 1;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MinskyMysteryDiv2 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
