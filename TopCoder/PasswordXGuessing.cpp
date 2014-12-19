// BEGIN CUT HERE
// PROBLEM STATEMENT
// Ms. Ciel loves rabbits. She has a large special cage for 
// her rabbits. The special cage is protected by a secret 
// password consisting of exactly X digits. Each digit of her 
// password is one of '0'-'9'. (It is possible that the 
// password starts with a '0'.)
// 
// There are N friends who want to guess the password. Each 
// friend make a guess consisting of exactly X digits. This 
// is given in vector <string> guesses that contains N 
// elements, where guesses[i] is the guess of the i-th 
// friend. The friends are so lucky that after they make 
// their guesses, Ms. Ciel tells them that each person 
// guessed the password correctly, except for exactly one 
// digit.
// 
// You are given the vector <string> guesses. Return the 
// number of different passwords that have the above property 
// (i.e., differ from each element of guesses in exactly one 
// digit). Note that it is possible that no such password 
// exists. In such case, return 0.
// 
// DEFINITION
// Class:PasswordXGuessing
// Method:howMany
// Parameters:vector <string>
// Returns:long long
// Method signature:long long howMany(vector <string> guesses)
// 
// 
// NOTES
// -The result is guaranteed to fit in a 64-bit signed 
// integer data type.
// 
// 
// CONSTRAINTS
// -guesses will contain between 1 and 50 elements, inclusive.
// -Each element of guesses will contain between 1 and 50 
// characters, inclusive.
// -All elements of guesses will contain the same number of 
// characters.
// -Each character of each element of guesses will be one of 
// '0'-'9'.
// 
// 
// EXAMPLES
// 
// 0)
// {"58", "47"}
// 
// Returns: 2
// 
// The two possible passwords are "57" and "48".
// 
// 1)
// {"539", "540", "541"}
// 
// Returns: 1
// 
// The only possible password is "549".
// 
// 2)
// {"12", "34", "56", "78"}
// 
// Returns: 0
// 
// There is no possible password. Ms. Ciel must have 
// forgotten her own password.
// 
// 3)
// {"2", "3", "5"}
// 
// Returns: 7
// 
// 
// 
// 4)
// {"4747", "4747", "4747", "4747"}
// 
// Returns: 36
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

class PasswordXGuessing {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"58", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"539", "540", "541"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"12", "34", "56", "78"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"2", "3", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"4747", "4747", "4747", "4747"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 36LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

	public: 
	long long howMany(vector <string> g) {
		int res = 0;

      for(int i=0; i<g[0].size(); i++)
      {
         char ci = g[0][i];
         for(char c='0'; c<='9'; c++)
            if( c!=ci )
            {
               g[0][i] = c;
               bool ok = 1;
               for(int j=1; j<g.size(); j++)
               {
                  int dif = 0;
                  for(int k=0; k<g[j].size(); k++)
                     if( g[j][k]!=g[0][k] ) dif++;
                  if( dif!=1 ) ok = 0;
               }
               if( ok ) res++;
            }
         g[0][i] = ci;
      }

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PasswordXGuessing ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
