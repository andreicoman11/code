// BEGIN CUT HERE
// PROBLEM STATEMENT
// Manao has a matrix X with 10,000 rows and W columns. He 
// likes to fill it with characters; he even has developed an 
// algorithm for this task. First, he chooses a string S 
// consisting of at most W lowercase letters. The string S is 
// called the generator. Then, he applies the algorithm 
// described by the following pseudocode:
// 
// cur := 0
// for i := 0 to 9999
//   for j := 0 to W - 1
//     X[i][j] := S.charAt(cur)
//     cur := (cur + 1) mod length(S)
// 
// 
// Manao has recently found a matrix X in his notepad.
// He wonders whether it was generated using the above 
// algorithm.
// You are given:
// 
// a vector <string> fragment that contains a rectangular 
// submatrix of X,
// the int W: the width of X,
// and two ints i0 and j0: the coordinates of the upper left 
// corner of your submatrix within X.
// 
// In other words, for all valid i, j we have fragment[i][j] 
// = X[i + i0][j + j0].
// Count how many different generators Manao could have used 
// to create a matrix X that contains the fragment you were 
// given.
// Return this number modulo 1,000,000,009.
// 
// DEFINITION
// Class:CharacterBoard2
// Method:countGenerators
// Parameters:vector <string>, int, int, int
// Returns:int
// Method signature:int countGenerators(vector <string> 
// fragment, int W, int i0, int j0)
// 
// 
// CONSTRAINTS
// -fragment will contain N elements, where N is between 1 
// and 10, inclusive.
// -Each element of fragment will be M characters long, where 
// M is between 1 and 10, inclusive.
// -Each element of fragment will consist of lowercase 
// letters ('a'-'z') only.
// -W will be between M and 10,000, inclusive.
// -i0 will be between 0 and 10,000 - N, inclusive.
// -j0 will be between 0 and W - M, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"dea",
//  "abc"}
// 7
// 1
// 1
// 
// Returns: 1
// 
// Manao has a matrix with 10000 rows and 7 columns. We know 
// that it looks as follows:
// 
// 
// ???????
// ?dea???
// ?abc???
// ???????
// ...
// 
// 
// The only string of length at most 7 which could generate 
// such matrix is "abcde".
// 
// 1)
// {"xyxxy"}
// 6
// 1
// 0
// 
// Returns: 28
// 
// The given information is:
// 
// ??????
// xyxxy?
// ??????
// ...
// 
// 
// The corresponding generator could be "xyx", "yxyxx", or a 
// string of form "xyxxy?", where '?' stands for any 
// lowercase letter.
// 
// 2)
// {"gogogo",
//  "jijiji",
//  "rarara"}
// 6
// 0
// 0
// 
// Returns: 0
// 
// No generator could create this matrix using the given 
// algorithm.
// 
// 3)
// {"abababacac",
//  "aaacacacbb",
//  "ccabababab"}
// 882
// 10
// 62
// 
// Returns: 361706985
// 
// 
// 
// 4)
// {"asjkffqw",
//  "basjkffq",
//  "qbasjkff",
//  "qqbasjkf"}
// 9031
// 9024
// 1959
// 
// Returns: 173947456
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

static const long long mod = 1000000009;

class CharacterBoard2 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"dea",
 "abc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(0, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"xyxxy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 1; int Arg3 = 0; int Arg4 = 28; verify_case(1, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"gogogo",
 "jijiji",
 "rarara"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; verify_case(2, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"abababacac",
 "aaacacacbb",
 "ccabababab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 882; int Arg2 = 10; int Arg3 = 62; int Arg4 = 361706985; verify_case(3, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9031; int Arg2 = 9024; int Arg3 = 1959; int Arg4 = 173947456; verify_case(4, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	public: 
	int countGenerators(vector <string> f, int w, int i0, int j0) {
      long long res = 0LL;
      for(int len = 1; len<=w; len++) {
         long long sum = 1LL;
         
		   string gen(len, '?');

         for(int i=0; sum && i<f.size(); i++)
         for(int j=0; sum && j<f[0].size(); j++) {
            int pos = (i0+i) * w + j + j0;
            pos = pos % len;

            if( gen[pos]=='?' ) gen[pos] = f[i][j];
            else if( gen[pos]!=f[i][j] ) sum = 0LL;
         }
                  
         for(int i=0; i<len; i++)
            if( gen[i]=='?' )
               sum = (sum * 26) % mod;
         res = (res + sum) % mod;
      }
      return (int)res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	CharacterBoard2 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
