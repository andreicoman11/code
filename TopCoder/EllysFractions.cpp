// BEGIN CUT HERE
// PROBLEM STATEMENT
// A positive common fraction is a fraction of the form A/B, 
// where A and B are positive integers.
// An irreducible fraction is a positive common fraction such 
// that A and B are relatively prime. (In other words, the 
// only positive integer that divides both A and B is 1.)
// Elly recently invented the factor fractions: A factor 
// fraction is an irreducible fraction such that the product 
// A*B is a factorial number (see Notes for definition). We 
// will only be interested in factor fractions that lie 
// strictly between 0 and 1. (That is, A must be strictly 
// smaller than B.)
// 
// Examples:
// 
// 2/3, 4/6, 4/7, 7/7, 6/1, 42/49 are six positive common 
// fractions
// Out of those six, the following three are irreducible: 
// 2/3, 4/7, 6/1.
// The fraction 2/3 is a factor fraction, because 2*3 = 6 and 
// that is a factorial number.
// The fraction 4/7 is not a factor fraction, because 4*7 = 
// 28 and that is not a factorial number.
// The fraction 6/1 is a factor fraction, because 6*1 = 6 and 
// that is a factorial number. However, as 6/1 does not lie 
// strictly between 0 and 1, we are not interested in this 
// fraction.
// Note that 4/6 is not a factor fraction. (We do have 
// 4*6=24, but a factor fraction has to be irreducible.)
// 
// 
// 
// You are given an int N.
// Compute and return the number of factor fractions A/B such 
// that 0 < A/B < 1 and A*B is one of the factorial numbers 
// from 1! to N! (inclusive).
// 
// DEFINITION
// Class:EllysFractions
// Method:getCount
// Parameters:int
// Returns:long long
// Method signature:long long getCount(int N)
// 
// 
// NOTES
// -The factorial of X, denoted X!, is the product of the 
// first X positive integers. For example, 6! is 1*2*3*4*5*6 
// = 720. The factorial numbers are the numbers of the form 
// X! for positive integer X. The smallest few: 1, 2, 6, 24, 
// 120, 720, ...
// -The answer will always fit in a 64-bit signed integer.
// 
// 
// CONSTRAINTS
// -N will be between 1 and 250, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: 0
// 
// We are interested in factor fractions such that A*B = 1. 
// The only positive common fraction with this property is 
// the fraction 1/1. However, this fraction is not strictly 
// between 0 and 1.
// 
// 1)
// 2
// 
// Returns: 1
// 
// Here the only valid factor fraction is 1/2.
// 
// 2)
// 3
// 
// Returns: 3
// 
// The three fractions are 1/2, 1/6, and 2/3. (We have 1*2 = 
// 2! and 1*6 = 2*3 = 3!.)
// 
// 3)
// 5
// 
// Returns: 9
// 
// 
// 
// 4)
// 100
// 
// Returns: 177431885
// 
// Plenty of fractions here.
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

class EllysFractions {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 1LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 3LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arg0 = 5; long long Arg1 = 9LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { int Arg0 = 100; long long Arg1 = 177431885LL; verify_case(4, Arg1, getCount(Arg0)); }

// END CUT HERE

	public: 
	long long getCount(int N) {
		long long res = 0;
      vector<int> p;
      p.push_back(2);
      for(int i=3; i<250; i+=2)
      {
         bool ok = 1;
         for(int j=0; j<p.size(); j++)
            if( i%p[j]==0 ) ok = 0;
         if(ok) p.push_back(i);
      }

      for(int i=2; i<=N; i++)
      {
         int q = 0;
         while( q<p.size() && p[q]<=i ) q++;
         q--;
         res += (1LL<<q);
      }
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EllysFractions ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
