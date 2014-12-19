// BEGIN CUT HERE
// PROBLEM STATEMENT
// Ms. Ciel loves rabbits. She has a large special cage for 
// her rabbits. The special cage is protected by a secret 
// password consisting of exactly X characters. Each 
// character of her password is one of 'a'-'z'. Due to the 
// security policy of the cage, each of the letters 'a'-'z' 
// only occurs at most twice in the password.
// 
// Bored with her current password, Ms. Ciel wants to change 
// her password into a palindrome. (A string is called 
// palindrome if it reads the same forwards and backwards.) 
// To change the password, Ms. Ciel may perform this 
// operation (that consists of two steps) zero or more times:
// 
// 
// Choose two different integers A and B such that 0 &lt= A < 
// B < X.
// Swap the characters at (0-based) positions A and B of the 
// current password.
// 
// 
// You are given a string password consisting of X characters 
// which represents Ms. Ciel's initial password. Return the 
// minimum number of operations Ms. Ciel needs to change 
// password into a palindrome. If this is not possible, 
// return -1 instead.
// 
// DEFINITION
// Class:PasswordXPalindrome
// Method:minSwaps
// Parameters:string
// Returns:int
// Method signature:int minSwaps(string password)
// 
// 
// CONSTRAINTS
// -password will contain between 1 and 50 characters, 
// inclusive.
// -Each character of password will be one of 'a'-'z'.
// -Each of the letters 'a'-'z' will occur at most twice in 
// password.
// 
// 
// EXAMPLES
// 
// 0)
// "levle"
// 
// Returns: 1
// 
// One possible solution is to swap the last two characters 
// to change the password into "level".
// 
// 1)
// "racecar"
// 
// Returns: 0
// 
// The password is already a palindrome.
// 
// 2)
// "abcdadcb"
// 
// Returns: 3
// 
// One possible solution:
// 
// Swap the characters at positions 4 and 7. The password 
// becomes "abcdbdca".
// Swap the characters at positions 5 and 6. The password 
// becomes "abcdbcda".
// Swap the characters at positions 4 and 6. The password 
// becomes "abcddcba".
// 
// 
// 3)
// "msmscielciel"
// 
// Returns: 5
// 
// 
// 
// 4)
// "hicanyouguesstodaywriter"
// 
// Returns: -1
// 
// It is not possible to change this password into a 
// palindrome.
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

class PasswordXPalindrome {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "levle"; int Arg1 = 1; verify_case(0, Arg1, minSwaps(Arg0)); }
	void test_case_1() { string Arg0 = "racecar"; int Arg1 = 0; verify_case(1, Arg1, minSwaps(Arg0)); }
	void test_case_2() { string Arg0 = "abcdadcb"; int Arg1 = 3; verify_case(2, Arg1, minSwaps(Arg0)); }
	void test_case_3() { string Arg0 = "msmscielciel"; int Arg1 = 5; verify_case(3, Arg1, minSwaps(Arg0)); }
	void test_case_4() { string Arg0 = "hicanyouguesstodaywriter"; int Arg1 = -1; verify_case(4, Arg1, minSwaps(Arg0)); }

// END CUT HERE

	public: 
	int minSwaps(string a) {
      int steps = 0, mid = -1;
      for(char c='a'; c<='z'; c++)
      {
         int occ = 0, idx = -1;
         for(int i=0; i<a.size(); i++)
            if( a[i]==c ) occ++, idx = i;
         if( occ==1 )
         {
            if( mid!=-1 || a.size()%2==0 ) return -1;
            mid = 1;
            if( idx != (a.size()-1)/2 )
               steps++, a[idx] = a[ (a.size()-1)/2 ];
         }
      }

      int n = a.size()/2;
      string b = a.substr(n + a.size()%2, a.size());
      a = a.substr(0, n);
      reverse(b.begin(), b.end());

      for(int i=0; i<n; i++)
         if( a[i]!=b[i] )
         {
            bool found = 0;
            steps++;
            for(int j=i+1; !found && j<n; j++)
               if( a[j]==a[i] )
                  a[j] = b[i], found = 1;
               else if( b[j]==a[i] )
                  b[j] = b[i], found = 1;
         }

      return steps;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PasswordXPalindrome ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
