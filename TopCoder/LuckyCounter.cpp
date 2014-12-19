// BEGIN CUT HERE
// PROBLEM STATEMENT
// Suppose that we're given a moment of time written as HH:
// MM, where HH is the hour and MM is the minutes. Let's say 
// that this moment is lucky if it is formatted AB:AB, AA:BB 
// or AB:BA, where both occurrences of A stand for the same 
// digit and both occurrences of B also stand for the same 
// digit. It is allowed for the digits represented by A and B 
// to be the same as well.
// You are given a vector <string> moments, where each 
// element represents a single moment of time. Return how 
// many of these time moments are lucky.
// 
// 
// DEFINITION
// Class:LuckyCounter
// Method:countLuckyMoments
// Parameters:vector <string>
// Returns:int
// Method signature:int countLuckyMoments(vector <string> 
// moments)
// 
// 
// CONSTRAINTS
// -moments will contain between 1 and 50 elements, 
// inclusive.                                                              

// -Each element of moments will be formatted "HH:MM" (quotes 
// for clarity), where HH is between 00 and 23, inclusive, 
// and MM is between 00 and 59, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"12:21", "11:10"}
// 
// Returns: 1
// 
// 12:21 is lucky, while 11:10 is not.
// 
// 1)
// {"00:00", "00:59", "23:00"}
// 
// Returns: 1
// 
// Only 00:00 is lucky here (note that it is formatted AB:AB, 
// AA:BB and AB:BA at the same time).
// 
// 2)
// {"12:34"}
// 
// Returns: 0
// 
// 
// 
// 3)
// {"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"}
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
class LuckyCounter {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12:21", "11:10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countLuckyMoments(Arg0)); }
	void test_case_1() { string Arr0[] = {"00:00", "00:59", "23:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countLuckyMoments(Arg0)); }
	void test_case_2() { string Arr0[] = {"12:34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countLuckyMoments(Arg0)); }
	void test_case_3() { string Arr0[] = {"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, countLuckyMoments(Arg0)); }

// END CUT HERE

	public: int countLuckyMoments(vector <string> mom) {
		int res = 0;
    for(int i=0; i<mom.sz; i++)
      if( (mom[i][0]==mom[i][1] && mom[i][3]==mom[i][4])  ||
          (mom[i][0]==mom[i][3] && mom[i][1]==mom[i][4])  ||
          (mom[i][0]==mom[i][4] && mom[i][3]==mom[i][1])) res++;
    return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	LuckyCounter ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
