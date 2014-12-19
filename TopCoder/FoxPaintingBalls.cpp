// BEGIN CUT HERE
// PROBLEM STATEMENT
// A Ball Triangle is a set of identical balls placed in a 
// triangular shape. A Ball Triangle has N rows, numbered 1 
// to N from top to bottom. For all i, 1 <= i <= N, the i-th 
// row contains i balls. For example, the following image 
// shows a Ball Triangle with N=3.
// 
// 
// 
// 
// Fox Jiro has infinitely many Ball Triangles. He can paint 
// a Ball Triangle according to the following conditions:
// 
// Each of the balls has to be painted either red, green, or 
// blue.
// No two adjacent balls may share the same color.
// 
// The following image shows one valid coloring of a Ball 
// Triangle for N=3.
// 
// 
// 
// 
// Jiro wants to paint as many Ball Triangles as he can.
// As long as he follows the rules above, he may color the 
// Ball Triangles in any way he likes.
// Some of the colored Ball Triangles may look exactly the 
// same, but they don't have to.
// The only other constraint is the total amount of paint 
// available to Jiro:
// In all the triangles together, he can paint at most R 
// balls red, G balls green, and B balls blue.
// 
// You are given the long longs R, G, and B.
// You are also given the int N.
// Return the maximum possible number of Ball Triangles Jiro 
// can paint.
// 
// DEFINITION
// Class:FoxPaintingBalls
// Method:theMax
// Parameters:long long, long long, long long, int
// Returns:long long
// Method signature:long long theMax(long long R, long long 
// G, long long B, int N)
// 
// 
// CONSTRAINTS
// -R, G and B will each be between 0 and 
// 1,000,000,000,000,000,000 (10^18), inclusive.
// -N will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 2
// 2
// 3
// 
// Returns: 1
// 
// Jiro can paint one Ball Triangle in the same way as in the 
// image in the statement.
// 
// 1)
// 1
// 2
// 3
// 3
// 
// Returns: 0
// 
// This time Jiro can paint no Ball Triangles.
// 
// 2)
// 8
// 6
// 6
// 4
// 
// Returns: 2
// 
// 
// 
// 3)
// 7
// 6
// 7
// 4
// 
// Returns: 2
// 
// 
// 
// 4)
// 100
// 100
// 100
// 4
// 
// Returns: 30
// 
// 
// 
// 5)
// 19330428391852493
// 48815737582834113
// 11451481019198930
// 3456
// 
// Returns: 5750952686
// 
// 
// 
// 6)
// 1
// 1
// 1
// 1
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

class FoxPaintingBalls {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 2LL; int Arg3 = 3; long long Arg4 = 1LL; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; int Arg3 = 3; long long Arg4 = 0LL; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 8LL; long long Arg1 = 6LL; long long Arg2 = 6LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 7LL; long long Arg1 = 6LL; long long Arg2 = 7LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; int Arg3 = 4; long long Arg4 = 30LL; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { long long Arg0 = 19330428391852493LL; long long Arg1 = 48815737582834113LL; long long Arg2 = 11451481019198930LL; int Arg3 = 3456; long long Arg4 = 5750952686LL; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; int Arg3 = 1; long long Arg4 = 3LL; verify_case(6, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	public: 
	long long theMax(long long R, long long G, long long B, int N) {
      if( N==1 ) return R + G + B;
      LL m = N/3;
      LL p = m*(m+1) / 2 * 3 - m;
      //LL p = (LL)N*(N+1) / 2 / 3;
      LL pmin = min(R, min(G, B));

      if( N%3==2 ) p += 2*m + 1;
      if( N%3==1 ) {
         p += m;
         LL l = 0, r = R + G + B;
         LL res = 0;
         while( l<=r ) {
            LL mid = (l+r) / 2;
            if( pmin/p>=mid && R + G + B - 3 * mid * p >= mid ) {
               res = mid;
               l = mid+1;
            }
            else r = mid-1;

         }
         return res;
      }
      
      return pmin / p;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	FoxPaintingBalls ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
