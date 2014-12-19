// BEGIN CUT HERE
// PROBLEM STATEMENT
// King Dengklek once planted N trees, conveniently numbered 
// 0 through N-1, along the main highway in the Kingdom of 
// Ducks. As time passed, the trees grew beautifully. Now, 
// the height of the i-th tree is heights[i] units.
// 
// King Dengklek now thinks that the highway would be even 
// more beautiful if the tree heights were in strictly 
// ascending order. More specifically, in the desired 
// configuration the height of tree i must be strictly 
// smaller than the height of tree i+1, for all possible i. 
// To accomplish this, King Dengklek will cast his magic 
// spell. If he casts magic spell of level X, he can increase 
// or decrease the height of each tree by at most X units. He 
// cannot decrease the height of a tree into below 1 unit. 
// Also, the new height of each tree in units must again be 
// an integer.
// 
// Of course, a magic spell of a high level consumes a lot of 
// energy. Return the smallest possible non-negative integer 
// X such that King Dengklek can achieve his goal by casting 
// his magic spell of level X.
// 
// DEFINITION
// Class:KingdomAndTrees
// Method:minLevel
// Parameters:vector <int>
// Returns:int
// Method signature:int minLevel(vector <int> heights)
// 
// 
// CONSTRAINTS
// -heights will contain between 2 and 50 elements, inclusive.
// -Each elements of heights will be between 1 and 
// 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {9, 5, 11}
// 
// Returns: 3
// 
// One possible solution that uses magic spell of level 3:
// 
// Decrease the height of the first tree by 2 units.
// Increase the height of the second tree by 3 units.
// 
// The resulting heights are {7, 8, 11}.
// 
// 1)
// {5, 8}
// 
// Returns: 0
// 
// These heights are already sorted in strictly ascending 
// order.
// 
// 2)
// {1, 1, 1, 1, 1}
// 
// Returns: 4
// 
// Since King Dengklek cannot decrease the heights of the 
// trees below 1, the only possible solution is to cast his 
// magic spell of level 4 to transform these heights into {1, 
// 2, 3, 4, 5}.
// 
// 3)
// {548, 47, 58, 250, 2012}
// 
// Returns: 251
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

class KingdomAndTrees {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9, 5, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minLevel(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minLevel(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minLevel(Arg0)); }
	void test_case_3() { int Arr0[] = {548, 47, 58, 250, 2012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 251; verify_case(3, Arg1, minLevel(Arg0)); }

// END CUT HERE

	public: 
   bool verify(vector<int> h, int x) {
      h[0] = max(1, h[0]-x);
      for(int i=1; i<h.size(); i++){
         if( h[i]+x < h[i-1] ) return 0;
         if( h[i]+x <= h[i-1] ) return 0;
         h[i] = max(h[i-1]+1, h[i]-x);
      }
      return 1;
   }

	int minLevel(vector <int> h) {
		int a = 1, b = 1000000000;
      if( verify(h, 0) ) return 0;
      do{
         int m = (a+b) / 2;
         if( verify(h, m) ) b = m;
         else a = m+1;

      } while( a+1<b );
      if( verify(h, a) ) return a;
      return b;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	KingdomAndTrees ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
