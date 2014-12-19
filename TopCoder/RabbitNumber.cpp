// BEGIN CUT HERE
// PROBLEM STATEMENT
// When cat Taro and rabbit Hanako were practicing hard for 
// SRM 484, they noticed an interesting property of 484. They 
// called it Rabbit Number.
// 
// 
// Let S(n) be the sum of the digits of n. For example, S
// (484) = 4+8+4 = 16 and S(22) = 2+2 = 4.
// A positive integer x is called a Rabbit Number if S(x*x) = 
// S(x)*S(x). For example, 22 is a Rabbit Number because S
// (484) = S(22)*S(22).
// 
// 
// Return the number of Rabbit Numbers between low and high, 
// inclusive.
// 
// DEFINITION
// Class:RabbitNumber
// Method:theCount
// Parameters:int, int
// Returns:int
// Method signature:int theCount(int low, int high)
// 
// 
// CONSTRAINTS
// -low will be between 1 and 1,000,000,000, inclusive.
// -high will be between low and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 22
// 22
// 
// Returns: 1
// 
// 22 is a Rabbit Number because
// 
// S(22*22) = S(484) = 16
// 
// S(22) * S(22) = 4 * 4 = 16
// 
// 1)
// 484
// 484
// 
// Returns: 0
// 
// 484 is not a Rabbit Number because
// 
// S(484*484) = S(234256) = 22
// 
// S(484) * S(484) = 16 * 16 = 256
// 
// 2)
// 1
// 58
// 
// Returns: 12
// 
// 
// 
// 3)
// 58
// 484
// 
// Returns: 24
// 
// 
// 
// 4)
// 1000000000
// 1000000000
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
class RabbitNumber {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 22; int Arg1 = 22; int Arg2 = 1; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 484; int Arg1 = 484; int Arg2 = 0; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 12; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; int Arg1 = 484; int Arg2 = 24; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

	public: int theCount(int low, int high) {
    int cnt = 0;
		for(long long i = (LL)low; i<=(LL)high; i++)
    {
      int div = 0;
      while( S(i)>=13 )
      {
        i /= 10;
        i++;
        div++;
      }
      while( div-- )
      {
        i *= 10;
      }
      if( i<=(LL)high && S(i)*S(i) == S(i*i) ) cnt++;
    }
    return cnt;
	}

  int S(LL x)
  {
    int s = 0;
    while(x)
    {
      s += x%10;
      x /= 10;
    }
    return s;
  }
	
};

// BEGIN CUT HERE 
int main()
{
	RabbitNumber ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
