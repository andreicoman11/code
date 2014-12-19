// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is going to walk along an unpaved road to her 
// friend's house.
// For our purposes, the road can be considered a one-
// dimensional polyline consisting of N segments.
// The segments are numbered 0 through N-1 along the road.
// At the beginning, Ciel stands on the segment number 0.
// Her friend's house is on the segment number N-1.
// 
// Unfortunately, yesterday it rained, so some segments of 
// the road are now muddy.
// Ciel has new shoes, so she must only use the other, dry 
// segments.
// She knows that segments 0 and N-1 are dry.
// The friend just called her and gave her two additional 
// pieces of information:
// 
// Out of the remaining N-2 segments, exactly muddyCount are 
// muddy.
// There is an even number of ways how Ciel can get to the 
// friend's house without stepping into the mud, while making 
// steps of length at most 2.
// 
// 
// We will now explain the second information in more detail.
// When Ciel walks along the road, each of her steps has 
// either length 1 or 2.
// A step of length 1 takes her from segment i to segment i+1.
// A step of length 2 takes her from segment i to segment 
// i+2, skipping the (possibly, but not necessarily muddy) 
// segment i+1.
// 
// Fox Ciel would like to use the information she has to 
// determine how the road looks like.
// Of course, there may be multiple configurations that match 
// the information.
// It is also possible that her friend was mistaken and there 
// is no sequence of dry and muddy segments that matches what 
// she told Ciel.
// 
// You are given the ints N and muddyCount.
// Count all the ways the road can look like, and return that 
// count modulo 555,555,555.
// 
// DEFINITION
// Class:MuddyRoad2
// Method:theCount
// Parameters:int, int
// Returns:int
// Method signature:int theCount(int N, int muddyCount)
// 
// 
// NOTES
// -Zero (0) is also an even number. Hence, if Ciel cannot 
// reach her friend's house without stepping into the mud, 
// there is an even number of ways to reach the house.
// -Two configurations of the road are different if some road 
// segment is dry in one of them and muddy in the other.
// 
// 
// CONSTRAINTS
// -N will be between 2 and 555, inclusive.
// -muddyCount will be between 0 and N-2, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// 1
// 
// Returns: 2
// 
// There are two possible configurations of the road: 
// .#...
// and
// ...#. (where '#' denotes a muddy segment and '.' a dry one).
// 
// 1)
// 5
// 2
// 
// Returns: 2
// 
// Possible configurations:
// .##..
// and
// ..##.
// Note that in these configurations, there are no ways to go 
// from part 0 to part 4 without stepping onto any muddy 
// parts. You have to count this kind of configurations too, 
// since 0 is an even number.
// 
// 2)
// 10
// 4
// 
// Returns: 65
// 
// 
// 
// 3)
// 314
// 78
// 
// Returns: 498142902
// 
// 
// 
// 4)
// 555
// 222
// 
// Returns: 541606281
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
#define MOD 555555555

int t[600][600][3];
int c[600][600];

class MuddyRoad2 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 65; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 314; int Arg1 = 78; int Arg2 = 498142902; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 555; int Arg1 = 222; int Arg2 = 541606281; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

	public: 
	int theCount(int n, int mud) {
      if(n==2) return 0;
      // compute all possible combinations
		memset(c, 0, sizeof(c));
      for(int i=1; i<n; i++)
      {
         c[i][0] = c[i][i] = 1;
         for(int j=1; j<i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
      }

      // split the n-mud+1 road into mud+1 numbers
      memset(t, 0, sizeof(t));
      for(int i=1; i<=n; i++) {
         t[i][1][i%3] = 1;
         for(int a=2; a<=i; a++)
         for(int p=1; p<=2; p++){
            t[i][a][p] = (t[i-p][a-1][1] + t[i-p][a-1][2]) % MOD;
            if( i>2 )
               t[i][a][p] = (t[i][a][p] + t[i-3][a][p]) % MOD;
         }
      }
      int rez = (c[n-2][mud] - t[n-mud][mud+1][1] - t[n-mud][mud+1][2]) % MOD;
      return (rez + MOD) % MOD;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MuddyRoad2 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
