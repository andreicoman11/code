// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Let X be a nonnegative integer.
// The Kleofas tail of X is an infinite sequence of 
// nonnegative integers, defined as follows:
// 
// 
// The first element is X.
// After an even element Y, the next element of the sequence 
// is Y/2.
// After an odd element Z, the next element of the sequence 
// is Z-1.
// 
// 
// For example, the Kleofas tail of 60 starts as follows: 60, 
// 30, 15, 14, 7, 6, ...
// 
// 
// You are given long longs K, A, and B.
// Return the number of integers X between A and B, 
// inclusive, such that the Kleofas tail of X contains at 
// least one occurrence of K.
// 
// 
// DEFINITION
// Class:KleofasTail
// Method:countGoodSequences
// Parameters:long long, long long, long long
// Returns:long long
// Method signature:long long countGoodSequences(long long K, 
// long long A, long long B)
// 
// 
// NOTES
// -Zero is an even number.
// 
// 
// CONSTRAINTS
// -K will be between 0 and 10^18, inclusive.
// -A will be between 0 and 10^18, inclusive.
// -B will be between 0 and 10^18, inclusive.
// -A will be less than or equal to B.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 4
// 8
// 
// Returns: 2
// 
// The value 3 occurs in the Kleofas tail of 6 and also in 
// the Kleofas tail of 7.
// 
// 1)
// 1
// 23457
// 123456
// 
// Returns: 100000
// 
// For each X between 23457 and 123456, inclusive, the 
// Kleofas tail of X contains the value 1.
// 
// 2)
// 1234567890123456
// 10
// 1000000
// 
// Returns: 0
// 
// Each Kleofas tail is a nonincreasing sequence.
// 
// 3)
// 0
// 0
// 2
// 
// Returns: 3
// 
// 
// 
// 4)
// 2
// 3
// 3
// 
// Returns: 1
// 
// The Kleofas tail of 3 is 3, 2, 1, 0, 0, 0, ...
// 
// 5)
// 13
// 12345
// 67890123
// 
// Returns: 8387584
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

class KleofasTail {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 8LL; long long Arg3 = 2LL; verify_case(0, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 23457LL; long long Arg2 = 123456LL; long long Arg3 = 100000LL; verify_case(1, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1234567890123456LL; long long Arg1 = 10LL; long long Arg2 = 1000000LL; long long Arg3 = 0LL; verify_case(2, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 2LL; long long Arg3 = 3LL; verify_case(3, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 3LL; long long Arg3 = 1LL; verify_case(4, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 13LL; long long Arg1 = 12345LL; long long Arg2 = 67890123LL; long long Arg3 = 8387584LL; verify_case(5, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
	long long countGoodSequences(long long K, long long A, long long B) {
		long long res = 0LL, size = (K%2==0 ? 2LL  : 1LL);
      if( K==0LL ) return B - A + 1;
      while( K<=B ) {
         if( K+size>A ) {
            if( K+size<=B ) {
               if( K>=A ) res += size;
               else res += K + size - A;
            } else {
               if( K>=A ) res += B - K + 1;
               else res += B - A + 1;
            }
         }
         K *= 2LL;
         size *= 2LL;
      }
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	KleofasTail ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
