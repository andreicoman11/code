// BEGIN CUT HERE
// PROBLEM STATEMENT
// Farmer Bessie and Cow John are walking along a straight 
// road.
// They are cautious, because they have heard that there may 
// be some wolves on the road.
// 
// 
// The road consists of N sections.
// The sections are numbered 0 through N-1, in order.
// Each section of the road contains at most one wolf.
// 
// 
// You have M additional pieces of information about the 
// positions of the wolves.
// Each piece of information is an interval of the road that 
// contains at most two wolves.
// More precisely, for each i between 0 and M-1, inclusive, 
// you are given two integers left[i] and right[i] such that 
// the sections with numbers in the range from left[i] to 
// right[i], inclusive, contain at most two wolves in total.
// 
// 
// You are given two vector <string>s L and R.
// The concatenation of all elements of L will be a single 
// space separated list containing the integers left[0] 
// through left[M-1].
// R contains all the integers right[i] in the same format.
// 
// 
// Return the number of ways in which wolves can be 
// distributed in the sections of the road, modulo 
// 1,000,000,007. 
// 
// DEFINITION
// Class:WolfInZooDivOne
// Method:count
// Parameters:int, vector <string>, vector <string>
// Returns:int
// Method signature:int count(int N, vector <string> L, 
// vector <string> R)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 300, inclusive.
// -L and R will contain between 1 and 50 elements, inclusive.
// -Each element of L and R will contain between 1 and 50 
// characters, inclusive.
// -Each character in L and R will be a digit ('0'-'9') or a 
// space (' ').
// -M will be between 1 and 300, inclusive.
// -The concatenation of all elements of L will be a single 
// space separated list of M integers. The integers will be 
// between 0 and N-1, inclusive, and they will be given 
// without unnecessary leading zeroes.
// -The concatenation of all elements of R will be a single 
// space separated list of M integers. The integers will be 
// between 0 and N-1, inclusive, and they will be given 
// without unnecessary leading zeroes.
// -For each i, the i-th integer in L will be smaller than or 
// equal to the i-th integer in R.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// {"0"}
// {"4"}
// 
// Returns: 16
// 
// There are at most two wolves in the segments 0 through 4, 
// i.e., in the entire road.
// The following picture shows all possible ways how the 
// wolves can be distributed.
// Note that there can also be only one wolf, or no wolves at 
// all.
// 
// 
// 
// 
// 1)
// 5
// {"0 1"}
// {"2 4"}
// 
// Returns: 21
// 
// 
// 
// 2)
// 10
// {"0 4 2 7"}
// {"3 9 5 9"}
// 
// Returns: 225
// 
// 
// 
// 3)
// 100
// {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 
// 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}
// {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","
// 80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}
// 
// Returns: 6419882
// 
// You must first concatenate the elements of L and only then 
// split it into integers. The same holds for R.
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

const long long mod = 1000000007;
const int NMAX = 305;
long long dp[NMAX][NMAX];
int n, m;
vector<int> l, r;

class WolfInZooDivOne {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"0 4 2 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 9 5 9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 225; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; string Arr1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6419882; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
   long long DP(int last, int at) {
      if( at>n ) return 1;
      if( dp[last][at]!=-1 ) return dp[last][at];

      long long res = DP(last, at+1);

      int end = at+1;
      for(int i=0; i<m; i++) {
         if(   l[i]<=last && at<=r[i] )
               end = max(end, r[i]+1);
      }
      res = (res + DP(at, end)) % mod;
      dp[last][at] = res;
      return res;
   }

	int count(int N, vector <string> L, vector <string> R) {
		n = N;
      memset(dp, -1, sizeof(dp));
      l.clear();
      r.clear();

      string lstr, rstr;
      for(int i=0; i<(int)L.size(); i++)
         lstr += L[i];
      for(int i=0; i<(int)R.size(); i++)
         rstr += R[i];
      istringstream inl(lstr), inr(rstr);

      int left, right;
      while( inl >> left ) {
         inr >> right;
         l.push_back(1+left);
         r.push_back(1+right);
      }
      m = l.size();

      return (int)DP(0, 1);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	WolfInZooDivOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
