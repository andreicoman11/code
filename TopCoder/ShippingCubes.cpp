// BEGIN CUT HERE
// PROBLEM STATEMENT
// You want to ship N cubes abroad. The size of each cube is 
// 1 x 1 x 1.
// You can only ship the cubes by filling them into a single 
// cuboid box.
// The cost of shipping a cuboid box with dimensions a x b x 
// c is equal to (a+b+c).
// 
// 
// 
// You can't leave any empty space in the box, because the 
// cubes would shift and get damaged during the transfer.
// 
// 
// You are given an int N.
// Return the minimal cost of shipping N cubes.
// 
// 
// DEFINITION
// Class:ShippingCubes
// Method:minimalCost
// Parameters:int
// Returns:int
// Method signature:int minimalCost(int N)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 200, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: 3
// 
// The only way is to use a box with dimensions 1 x 1 x 1.
// 
// 1)
// 6
// 
// Returns: 6
// 
// This time one optimal solution is to send a box with 
// dimensions 1 x 2 x 3. The cost of sending this box is 
// 1+2+3 = 6. Any other option is at least as expensive as 
// this one. For example, sending a box with dimensions 6 x 1 
// x 1 has the cost 6+1+1 = 8.
// 
// 2)
// 7
// 
// Returns: 9
// 
// 
// 
// 3)
// 200
// 
// Returns: 18
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
class ShippingCubes {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; verify_case(0, Arg1, minimalCost(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, minimalCost(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 9; verify_case(2, Arg1, minimalCost(Arg0)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 18; verify_case(3, Arg1, minimalCost(Arg0)); }

// END CUT HERE

	public: int minimalCost(int N) {
		int minc = 1000;

    for(int i=1; i<=N; i++)
      if( N%i==0 )
    for(int j=i; j<=N; j++)
      if( N%(i*j)==0 )
      {
        int k = (N / i) / j;
        minc = min(minc, i+j+k);
      }

    return minc;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	ShippingCubes ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
