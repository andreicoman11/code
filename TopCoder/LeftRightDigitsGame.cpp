// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are playing a solitaire game called Left-Right Digits 
// Game. This game uses a deck of N cards. Each card has a 
// single digit written on it. These digits are given as 
// characters in the string digits. More precisely, the i-th 
// character of digits is the digit written on the i-th card 
// from the top of the deck (both indices are 0-based).
// 
// The game is played as follows. First, you place the 
// topmost card (whose digit is the 0-th character of digits) 
// on the table. Then, you pick the cards one-by-one from the 
// top of the deck. For each card, you have to place it 
// either to the left or to the right of all cards that are 
// already on the table.
// 
// After all of the cards have been placed on the table, they 
// now form an N-digit number. This number must not have 
// leading zeros; i.e., the leftmost card on the table must 
// not be a '0'. The goal of the game is to make this N-digit 
// number as small as possible.
// 
// Return the smallest possible resulting number you can 
// achieve in this game as a string.
// 
// DEFINITION
// Class:LeftRightDigitsGame
// Method:minNumber
// Parameters:string
// Returns:string
// Method signature:string minNumber(string digits)
// 
// 
// CONSTRAINTS
// -digits will contain between 1 and 50 characters, inclusive.
// -Each character of digits will be between '0' and '9', 
// inclusive.
// -digits will contain at least one character that is not '0'.
// 
// 
// EXAMPLES
// 
// 0)
// "565"
// 
// Returns: "556"
// 
// The solution is as follows.
// 
// Place the first card on the table.
// Place the second card to the right of all cards on the 
// table.
// Place the last card to the left of all cards on the table.
// 
// 
// 1)
// "9876543210"
// 
// Returns: "1234567890"
// 
// The resulting number cannot have leading zeros.
// 
// 2)
// "8016352"
// 
// Returns: "1086352"
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

class LeftRightDigitsGame {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "565"; string Arg1 = "556"; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "9876543210"; string Arg1 = "1234567890"; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "8016352"; string Arg1 = "1086352"; verify_case(2, Arg1, minNumber(Arg0)); }

// END CUT HERE

	public: 
   string get(string d, bool one) {
      char dmin = '9' + 1;
      int idx = -1;
      for(int i=0; i<d.size(); i++)
         if( dmin > d[i] && (!one || d[i]!='0')) {
            dmin = d[i];
            idx = i;
         } else if( dmin==d[i] ) {
            idx = i;
         }

      string res = d.substr(idx, 1);
      if( idx ) res += get( d.substr(0, idx), 0);
      res += d.substr(idx+1);
      return res;
   }
	string minNumber(string d) {
		return get(d, 1);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	LeftRightDigitsGame ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
