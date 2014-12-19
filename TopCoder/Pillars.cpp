// BEGIN CUT HERE
// PROBLEM STATEMENT
// On a horizontal line, there are two vertical pillars.
// The distance between their bottoms is w.
// The height of the first pillar is an integer, chosen 
// uniformly at random in the range 1 through x, inclusive.
// The height of the second pillar is an integer, chosen 
// uniformly at random in the range 1 through y, inclusive.
// The tops of both pillars will be connected by a straight 
// piece of rope.
// 
// You are given the ints w, x, and y.
// Compute and return the expected length of the rope.
// 
// DEFINITION
// Class:Pillars
// Method:getExpectedLength
// Parameters:int, int, int
// Returns:double
// Method signature:double getExpectedLength(int w, int x, 
// int y)
// 
// 
// NOTES
// -Your return value must have a relative or an absolute 
// error of less than 1e-9.
// -In this task, the expected rope length can be computed as 
// the average rope length over all possible cases.
// 
// 
// CONSTRAINTS
// -w will be between 1 and 1000, inclusive.
// -x will be between 1 and 100,000, inclusive.
// -y will be between 1 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 1
// 1
// 
// Returns: 1.0
// 
// The rope always has a length of 1.
// 
// 1)
// 1
// 5
// 1
// 
// Returns: 2.387132965131785
// 
// There are 5 possible (equiprobable) cases in which the 
// length of the rope is 1, sqrt(2), sqrt(5), sqrt(10) and 
// sqrt(17). The correct answer is the arithmetic average of 
// these 5 numbers.
// 
// 2)
// 2
// 3
// 15
// 
// Returns: 6.737191281760445
// 
// 
// 
// 3)
// 10
// 15
// 23
// 
// Returns: 12.988608956320535
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

#define pb push_back
#define sz size()

class Pillars {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; double Arg3 = 2.387132965131785; verify_case(1, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; double Arg3 = 6.737191281760445; verify_case(2, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 23; double Arg3 = 12.988608956320535; verify_case(3, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
	double getExpectedLength(int _w, int _x, int _y) {
      long long x = _x, y = _y, w = _w;
      long long w2 = w*w, count = 0LL;
		double sum = 0.0;
      if( x>y ) swap(x, y);

      sum += x * w;
      count += x;

      for(long long diff=1LL; diff <= y-1; diff++) {
         long long count_diff = min(x, y-diff);
         count += count_diff;
         sum += ((double)count_diff * sqrt(double(w2 + diff*diff)));
      }

      for(long long diff=1LL; diff <= x-1; diff++) {
         long long count_diff = x-diff;
         count += count_diff;
         sum += ((double)count_diff * sqrt(double(w2 + diff*diff)));
      }

      return sum / (double)count;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	Pillars ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
