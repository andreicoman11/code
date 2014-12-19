// BEGIN CUT HERE
// PROBLEM STATEMENT
// Mr. Dengklek once told you that 4 and 7 are lucky numbers. 
// He also defined the luckiness of a positive integer as the 
// absolute difference between the number of 7s in its 
// decimal representation and the number of 4s in its decimal 
// representation. For example, for each of the numbers 23, 
// 47 and 47714 the luckiness is 0, and for each of the 
// numbers 4474 and 7070 the luckiness is 2.
// 
// You are given two ints A and B. Return the sum of 
// luckiness of all integers between A and B, inclusive.
// 
// 
// DEFINITION
// Class:SumOfLuckiness
// Method:theSum
// Parameters:int, int
// Returns:long long
// Method signature:long long theSum(int A, int B)
// 
// 
// CONSTRAINTS
// -A will be between 1 and 2,000,000,000, inclusive.
// -B will be between A and 2,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 10
// 
// Returns: 2
// 
// The luckiness of 4 is 1. The luckiness of 7 is 1. The 
// luckiness of the other numbers is 0. So, the sum of 
// luckiness is 2.
// 
// 1)
// 40
// 47
// 
// Returns: 8
// 
// The luckiness of 40, 41, 42, 43, 45, and 46 is 1. The 
// luckiness of 44 is 2. The luckiness of 47 is 0.
// 
// 2)
// 58
// 526
// 
// Returns: 231
// 
// 
// 
// 3)
// 4444
// 7777
// 
// Returns: 2338
// 
// 
// 
// 4)
// 585858585
// 858585858
// 
// Returns: 287481025
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

int comb[11][11], opt[11];

class SumOfLuckiness {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; long long Arg2 = 2LL; verify_case(0, Arg2, theSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 40; int Arg1 = 47; long long Arg2 = 8LL; verify_case(1, Arg2, theSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 58; int Arg1 = 526; long long Arg2 = 231LL; verify_case(2, Arg2, theSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4444; int Arg1 = 7777; long long Arg2 = 2338LL; verify_case(3, Arg2, theSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 585858585; int Arg1 = 858585858; long long Arg2 = 287481025LL; verify_case(4, Arg2, theSum(Arg0, Arg1)); }

// END CUT HERE
  void getcomb()
  {
    memset(comb, 0, sizeof(comb));
    for(int i=0; i<11; i++)
      comb[i][0] = comb[i][i] = 1;
    for(int i=1; i<11; i++)
    for(int j=1; j<i; j++)
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    opt[0] = 1;
    for(int i=1; i<10; i++)
      opt[i] = opt[i-1] * 8;
  }
  long long lSum(int x)
  {
    vector<int> vx;
    while(x)
    {
      vx.pb(x%10);
      x/=10;
    }

    int yet4 = 0, yet7 = 0;
    LL lsum = 0;
    for(int i=vx.sz-1; i>=0; i--)
    {
      int fd = vx[i];
      int d = i;
      int fdpos = fd - (fd>4) - (fd>7);
      for(int n4=0; n4<=d+1; n4++)
      for(int n7=0; n4+n7<=d+1; n7++)
        if( n4+yet4 != n7+yet7 )
        {
          LL pos = 0;
          if( n4+n7<=d )
          {
            pos += comb[d][n4] * comb[d-n4][n7] * opt[d - n4 - n7] * fdpos;
          }
          if( fd>4 && n4>=1 ) pos += comb[d][n4-1] * comb[d-n4+1][n7] * opt[d-n4-n7+1];
          if( fd>7 && n7>=1 ) pos += comb[d][n7-1] * comb[d-n7+1][n4] * opt[d-n4-n7+1];
          lsum += pos * (LL)abs(n4+yet4-n7-yet7);
        }
      if( fd==4 ) yet4++;
      if( fd==7 ) yet7++;
    }
    return lsum;
  }
	public: long long theSum(int A, int B) {
    getcomb();
    //cout << lSum(A) << " " << lSum(B+1) << endl;
		return lSum(B+1) - lSum(A);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	SumOfLuckiness ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
