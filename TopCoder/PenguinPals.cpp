// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Penguin Pals is a match making service that matches 
// penguins to new friends, using the following procedure:
// 
// Each penguin is asked a single question: "Do you prefer 
// the color blue, or the color red?"
// All penguins are arranged so that they stand on a circle, 
// equally spaced. 
// The organizers draw some straight lines, connecting some 
// pairs of penguins. Each penguin may only be connected to 
// at most one other penguin. Two penguins cannot be 
// connected if they prefer a different color.
// Each penguin who is connected to some other penguin 
// follows the line to find their match.
// 
// 
// 
// 
// The only problem with the above system was that it allowed 
// penguins to collide if two lines crossed each other.
// Therefore, a new additional rule was adopted: no two lines 
// may cross.
// Penguin Pals now has some penguins arranged on a circle 
// (after step 2 of the above procedure).
// They need to know the maximum number of pairs of penguins 
// they can create.
// 
// 
// 
// You are given a string colors whose i-th character 
// represents the prefered color of the i-th penguin (0-based 
// index) in the circular arrangement. The i-th character is 
// 'R' if the i-th penguin prefers red and 'B' if the i-th 
// penguin prefers blue. Return the maximum number of matched 
// pairs that can be formed.
// 
// 
// DEFINITION
// Class:PenguinPals
// Method:findMaximumMatching
// Parameters:string
// Returns:int
// Method signature:int findMaximumMatching(string colors)
// 
// 
// CONSTRAINTS
// -colors will contain between 1 and 50 characters, inclusive.
// -Each character of colors will be either 'R' or 'B'.
// 
// 
// EXAMPLES
// 
// 0)
// "RRBRBRBB"
// 
// Returns: 3
// 
// In this picture the penguins have been colored in their 
// preferred color. 
// 
// 
// 
// 1)
// "RRRR"
// 
// Returns: 2
// 
// 
// 
// 2)
// "BBBBB"
// 
// Returns: 2
// 
// 
// 
// 3)
// "RBRBRBRBR"
// 
// Returns: 4
// 
// 
// 
// 4)
// "RRRBRBRBRBRB"
// 
// Returns: 5
// 
// 
// 
// 5)
// "R"
// 
// Returns: 0
// 
// 
// 
// 6)
// "RBRRBBRB"
// 
// Returns: 3
// 
// 
// 
// 7)
// "RBRBBRBRB"
// 
// Returns: 4
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

class PenguinPals {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRBRBRBB"; int Arg1 = 3; verify_case(0, Arg1, findMaximumMatching(Arg0)); }
	void test_case_1() { string Arg0 = "RRRR"; int Arg1 = 2; verify_case(1, Arg1, findMaximumMatching(Arg0)); }
	void test_case_2() { string Arg0 = "BBBBB"; int Arg1 = 2; verify_case(2, Arg1, findMaximumMatching(Arg0)); }
	void test_case_3() { string Arg0 = "RBRBRBRBR"; int Arg1 = 4; verify_case(3, Arg1, findMaximumMatching(Arg0)); }
	void test_case_4() { string Arg0 = "RRRBRBRBRBRB"; int Arg1 = 5; verify_case(4, Arg1, findMaximumMatching(Arg0)); }
	void test_case_5() { string Arg0 = "R"; int Arg1 = 0; verify_case(5, Arg1, findMaximumMatching(Arg0)); }
	void test_case_6() { string Arg0 = "RBRRBBRB"; int Arg1 = 3; verify_case(6, Arg1, findMaximumMatching(Arg0)); }
	void test_case_7() { string Arg0 = "RBRBBRBRB"; int Arg1 = 4; verify_case(7, Arg1, findMaximumMatching(Arg0)); }

// END CUT HERE

	public: 
	int findMaximumMatching(string c) {
		int maxp = 0;

      bool found = 1;
      while( found && c.size()>1 )
      {
         found = 0;
         for(int i=0; i<c.size()-1; i++)
            if( c[i]==c[i+1] ) {
               found = 1;
               maxp++;
               c = c.substr(0, i) + c.substr(i+2);
               i = i-2;
            }

         if( !found && c.size()>1 && c[0]==c[c.size()-1] ) {
            found = 1;
            maxp++;
            c = c.substr(1, c.size()-2);
         }
      }

      if( c.size()!=1 && c.size()>=4 )
         maxp += c.size()/2 - 1;

      return maxp;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PenguinPals ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
