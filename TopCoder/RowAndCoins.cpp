// BEGIN CUT HERE
// PROBLEM STATEMENT
// Alice and Bob play the following game. 
// The game board consists of some cells in a row. 
// Each cell is marked either 'A' or 'B'. 
// At the beginning, there are no coins placed on the board – 
// all the cells are empty. 
// Alice and Bob take alternating turns. 
// Alice plays first. 
// In each turn, the current player chooses some contiguous 
// empty cells and places a coin onto each of the chosen 
// cells. 
// The player must always choose at least one cell. 
// The player must never choose all empty cells. 
// In other words, after each turn there must be at least one 
// empty cell. 
// 
// The following picture shows two examples of placing coins: 
// 
// 
// 
// The game ends when there is only one cell left without a 
// coin. 
// If that cell is marked 'A', Alice wins. 
// Otherwise, Bob wins. 
// You are given a string cells representing the row of cells. 
// Assuming that both players aim to win and play optimally, 
// return a string containing the name of the winner. 
// 
// 
// DEFINITION
// Class:RowAndCoins
// Method:getWinner
// Parameters:string
// Returns:string
// Method signature:string getWinner(string cells)
// 
// 
// CONSTRAINTS
// -cells will contain between 2 and 14 characters, inclusive. 
// -Each character in cells will be either 'A' or 'B'. 
// 
// 
// EXAMPLES
// 
// 0)
// "ABBB"
// 
// Returns: "Alice"
// 
// Alice can win by placing coins on three cells marked 'B' 
// in her first turn. 
// 
// 
// 1)
// "BBBB"
// 
// Returns: "Bob"
// 
// 2)
// "BA"
// 
// Returns: "Alice"
// 
// 
// 
// 3)
// "BABBABBB"
// 
// Returns: "Bob"
// 
// 4)
// "ABABBBABAABBAA"
// 
// Returns: "Alice"
// 
// 
// 
// 5)
// "BBBAAABBAAABBB"
// 
// Returns: "Bob"
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
class RowAndCoins {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBB"; string Arg1 = "Alice"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "BBBB"; string Arg1 = "Bob"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = "BA"; string Arg1 = "Alice"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "BABBABBB"; string Arg1 = "Bob"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = "ABABBBABAABBAA"; string Arg1 = "Alice"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { string Arg0 = "BBBAAABBAAABBB"; string Arg1 = "Bob"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

	public: string getWinner(string cells) {
		int a=0, b=0;
    for(int i=0; i<cells.sz; i++) 
    {
      if( cells[i]=='A' ) a++;
      else  b++;
      int j = i+1;
      while( j<cells.sz && cells[i] == cells[j] ) j++;
      i = j-1;
    }
    if( a>=b ) return "Alice";
    else return "Bob";
	}
	
};

// BEGIN CUT HERE 
int main()
{
	RowAndCoins ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
