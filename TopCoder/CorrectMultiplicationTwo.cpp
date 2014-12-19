// BEGIN CUT HERE
// PROBLEM STATEMENT
// Krolik found a sheet of paper with an equation containing 
// three positive integers: 
// "a * b = c". 
// This equation might be wrong, 
// so Krolik is trying to make it correct by adjusting the 
// numbers a, b, and c. 
// 
// You are given three ints a, b, and c. 
// Return a int containing the minimum value of |A - a| + |B 
// - b| + |C - c|, 
// where A, B, and C are positive integers satisfying A * B = 
// C. 
// 
// 
// DEFINITION
// Class:CorrectMultiplicationTwo
// Method:getMinimum
// Parameters:int, int, int
// Returns:int
// Method signature:int getMinimum(int a, int b, int c)
// 
// 
// NOTES
// -|x| is the absolute value of x (which is x for non-
// negative x and (-x) for negative x). 
// 
// 
// CONSTRAINTS
// -a, b, and c will each be between 1 and 1,000,000, 
// inclusive. 
// 
// 
// EXAMPLES
// 
// 0)
// 19
// 28
// 522
// 
// Returns: 2
// 
// By assigning A = 18, B = 29, and C = 522 the value of |A - 
// a| + |B - b| + |C - c| is minimized. 
// 
// 
// 1)
// 10
// 30
// 500
// 
// Returns: 11
// 
// 2)
// 111
// 111
// 12321
// 
// Returns: 0
// 
// 3)
// 1000
// 100
// 10
// 
// Returns: 1089
// 
// Note that A, B, and C must be positive integers. 
// 
// 
// 4)
// 399
// 522
// 199999
// 
// Returns: 24
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
class CorrectMultiplicationTwo {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 19; int Arg1 = 28; int Arg2 = 522; int Arg3 = 2; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 30; int Arg2 = 500; int Arg3 = 11; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 111; int Arg1 = 111; int Arg2 = 12321; int Arg3 = 0; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 10; int Arg3 = 1089; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 399; int Arg1 = 522; int Arg2 = 199999; int Arg3 = 24; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: int getMinimum(int a, int b, int c) {
		int rez = abs(c-a*b), B, C, rez2;
    for(int A=a; A; A--)
    {
      B = c/A;
      if( B==0 ) B = 1;
      C = A*B;
      rez2 = abs(a-A) + abs(b-B) + abs(c-C);
      rez = min(rez, rez2);
      B++;
      C = A*B;
      rez2 = abs(a-A) + abs(b-B) + abs(c-C);
      rez = min(rez, rez2);
    }
    for(int A=a+1; A<=1000000; A++)
    {
      B = c/A;
      if( B==0 ) B = 1;
      C = A*B;
      rez2 = abs(a-A) + abs(b-B) + abs(c-C);
      rez = min(rez, rez2);
      B++;
      C = A*B;
      rez2 = abs(a-A) + abs(b-B) + abs(c-C);
      rez = min(rez, rez2);
    }
    return rez;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	CorrectMultiplicationTwo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
