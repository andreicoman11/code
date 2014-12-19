// BEGIN CUT HERE
// PROBLEM STATEMENT
// John and Brus are bored.
// They have n+m common friends.
// The first n of them are bored and other m are not.
// John chooses the j-th (1-based) friend for a talk.
// If the friend is not bored, he becomes bored after the talk.
// Brus does the same with the b-th (1-based) friend.
// Note that John and Brus can't choose the same friend.
// 
// You have to find the number of bored friends after the 
// talks.
// 
// 
// DEFINITION
// Class:TheBoredomDivTwo
// Method:find
// Parameters:int, int, int, int
// Returns:int
// Method signature:int find(int n, int m, int j, int b)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 47, inclusive.
// -m will be between 1 and 47, inclusive.
// -j will be between 1 and n+m, inclusive.
// -b will be between 1 and n+m, inclusive.
// -j and b will be different.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 1
// 1
// 2
// 
// Returns: 2
// 
// The first friend is already bored and the second friend 
// becomes bored after the talk with Brus.
// 
// 1)
// 2
// 1
// 1
// 2
// 
// Returns: 2
// 
// Here John and Brus choose two friends that are already 
// bored.
// 
// 2)
// 1
// 2
// 3
// 2
// 
// Returns: 3
// 
// All the friends become bored.
// 
// 3)
// 4
// 7
// 7
// 4
// 
// Returns: 5
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
class TheBoredomDivTwo {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 2; int Arg4 = 3; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 7; int Arg3 = 4; int Arg4 = 5; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	public: int find(int n, int m, int j, int b) {
    int res = n;
		if( j>n ) res++;
    if( b>n && b!=j ) res++;
    return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TheBoredomDivTwo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
