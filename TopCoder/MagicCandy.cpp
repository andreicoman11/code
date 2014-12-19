// BEGIN CUT HERE
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world 
// celebrate this 
// holiday. The following story takes place in the land of 
// reindeer, where Santa Claus resides.
// 
// 
// 
// The reindeer love candies. They have n pieces of candy. 
// The pieces of candy are numbered 1 through n. Dasher is 
// one of the reindeer. He wants to eat one of the candies. 
// To pick the one he will eat, Dasher uses the following 
// method:
// 
// While there is more than one piece of candy:
// Discard all candies that are numbered by perfect squares 
// (i.e., candies 1, 4, 9, 16, 25, etc.).
// Relabel the remaining k candies 1 through k, keeping the 
// numbers in the same order.
// Once only one piece of candy remains, Dasher will eat it.
// 
// 
// 
// 
// You are given an int n. Your method must compute and 
// return the number initially assigned to the piece of candy 
// eaten by Dasher.
// 
// DEFINITION
// Class:MagicCandy
// Method:whichOne
// Parameters:int
// Returns:int
// Method signature:int whichOne(int n)
// 
// 
// NOTES
// -It can be proved that Dasher's method will always lead to 
// a situation in which only one piece of candy remains.
// 
// 
// CONSTRAINTS
// -n will be between 1 and 1,000,000,000 inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// 
// Returns: 5
// 
// We start with 5 candies. Let's call them A, B, C, D, and 
// E. Initially, they are numbered 1 through 5, in this order.
// 
// In the first round, we discard candies with numbers 1 
// (which is A) and 4 (which is D).
// This leaves us with candies B, C, and E.
// These candies now get new numbers: B becomes 1, C becomes 
// 2, and E becomes 3.
// In the second round, we discard candy number 1 (which is 
// now B).
// This leaves us with candies C and E.
// Again, the candies now get new numbers: C becomes 1 and E 
// becomes 2.
// In the third round, we discard candy number 1 (which is 
// now C).
// 
// The only remaining candy is E. Its number in the beginning 
// was 5, therefore our method should return 5.
// 
// 1)
// 9
// 
// Returns: 7
// 
// This time we start with 9 pieces of candy. If we label 
// them A through I, the process will look as follows:
// 
// start: ABCDEFGHI
// throw away candies 1, 4, 9 (A, D, I)
// after the first round: BCEFGH
// throw away candies 1, 4 (B, F)
// after the second round: CEGH
// throw away candies 1, 4 (C, H)
// after the third round: EG
// throw away candy 1 (E)
// at the end: G
// 
// 
// 2)
// 20
// 
// Returns: 17
// 
// 
// 
// 3)
// 5265
// 
// Returns: 5257
// 
// 
// 
// 4)
// 20111223
// 
// Returns: 20110741
// 
// 
// 
// 5)
// 1
// 
// Returns: 1
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
int v[65000] = {0};

class MagicCandy {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; verify_case(0, Arg1, whichOne(Arg0)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 7; verify_case(1, Arg1, whichOne(Arg0)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 17; verify_case(2, Arg1, whichOne(Arg0)); }
	void test_case_3() { int Arg0 = 5265; int Arg1 = 5257; verify_case(3, Arg1, whichOne(Arg0)); }
	void test_case_4() { int Arg0 = 20111223; int Arg1 = 20110741; verify_case(4, Arg1, whichOne(Arg0)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; verify_case(5, Arg1, whichOne(Arg0)); }

// END CUT HERE

	public: int whichOne(int n) {
		int l = 0;
      while(n>3)
      {
         v[l++] = n;
         n -= (int)sqrt((double)n);
      }

      int sqn;
      for(;l;l--)
      {
         sqn = sqrt((double)n);
         while( (int)sqrt(double(n+sqn)) > sqn )
            sqn = sqrt(double(n+sqn));
         n += sqn;
      }
      return n;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MagicCandy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
