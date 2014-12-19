// BEGIN CUT HERE
// PROBLEM STATEMENT
// Bob is using a peculiar text editor to write a sequence of 
// lines of text.
// The editor consists of three parts: a results window, a 
// text buffer and an undo history.
// More details about the three parts follow.
// 
// The results window contains a sequence of strings: the 
// lines of text you already wrote. Initially, the results 
// window is empty.
// The text buffer contains a string: the line you are 
// writing at the moment. Initially, the string in the text 
// buffer is empty.
// The undo history contains a sequence of strings: all the 
// past states of the text buffer. Initially, the undo 
// history contains a single element: an empty string.
// 
// 
// You are given a vector <string> lines.
// Bob would like to print the contents of lines into the 
// results window.
// (At the end, the sequence of strings stored in the results 
// window must be precisely equal to lines. Order of elements 
// matters.)
// Additionally, Bob would like to do so as quickly as 
// possible.
// He is able to take the following actions:
// 
// 
// Bob may type a lowercase letter. The letter is appended to 
// the text buffer. The new text buffer is then added as a 
// new element of the undo history. (For example, if the text 
// buffer currently contains "do", then pressing 'g' changes 
// the text buffer to "dog" and then stores "dog" into the 
// undo history.)
// Bob may press Enter. When he does so, the current content 
// of the text buffer is printed to the results window as a 
// new line, after the lines that were printed earlier. The 
// text buffer remains unmodified. (For example, if the text 
// buffer contains "dog" and Bob presses Enter, "dog" will be 
// appended to the results window, and the results buffer 
// still contains "dog".)
// Bob may use two mouse clicks to restore any entry from the 
// undo history to the text buffer. This operation does not 
// modify the undo history.
// 
// 
// Return the minimum total number of button presses 
// (keyboard and mouse) that Bob needs to print all the given 
// lines into the results window.
// 
// DEFINITION
// Class:UndoHistory
// Method:minPresses
// Parameters:vector <string>
// Returns:int
// Method signature:int minPresses(vector <string> lines)
// 
// 
// CONSTRAINTS
// -lines will contain between 1 and 50 elements, inclusive.
// -Each element of lines will contain between 1 and 50 
// characters, inclusive.
// -Each element of lines will contain only lowercase letters 
// ('a'-'z').
// 
// 
// EXAMPLES
// 
// 0)
// {"tomorrow", "topcoder"}
// 
// Returns: 18
// 
// 
// Type 't'. The text buffer now contains "t", and the undo 
// history now contains "" and "t".
// Type 'o'. The text buffer now contains "to", and the undo 
// history now contains "", "t", and "to".
// Using six more keypresses, type the letters in "morrow". 
// The text buffer now contains "tomorrow" and the undo 
// history contains all prefixes of "tomorrow". The results 
// window is still empty.
// Press Enter. The results window now contains one string: 
// "tomorrow".
// Click the mouse twice to restore "to" from undo history.
// Using another six keypresses, type the letters in "pcoder".
// Press Enter. The results window now contains "tomorrow" 
// and "topcoder", in this order, and we are done.
// 
// The total number of button presses was 8 (typing 
// "tomorrow") + 1 (Enter) + 2 (mouse) + 6 (typing "pcoder") 
// + 1 (Enter) = 18.
// 
// 1)
// {"a","b"}
// 
// Returns: 6
// 
// After typing "a" and pressing enter, we need to restore 
// the empty string (which is always present at the top of 
// the undo buffer) before typing "b".
// 
// 2)
// {"a", "ab", "abac", "abacus" }
// 
// Returns: 10
// 
// There are times when it is not necessary to use the undo 
// history at all.
// 
// 3)
// {"pyramid", "sphinx", "sphere", "python", "serpent"}
// 
// Returns: 39
// 
// 
// 
// 4)
// {"ba","a","a","b","ba"}
// 
// 
// Returns: 13
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

class UndoHistory {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tomorrow", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, minPresses(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minPresses(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "ab", "abac", "abacus" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minPresses(Arg0)); }
	void test_case_3() { string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(3, Arg1, minPresses(Arg0)); }
	void test_case_4() { string Arr0[] = {"ba","a","a","b","ba"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minPresses(Arg0)); }

// END CUT HERE

	public: 
	int minPresses(vector <string> lines) {
		string buf = "";
      set<string> hist;
      hist.insert("");
      int res = 0;

      for(int i=0; i<lines.size(); i++) {
         int use_buf = lines[i].size() + 2;
         if( buf.size()<=lines[i].size() && buf==lines[i].substr(0, buf.size()) )
            use_buf = lines[i].size() - buf.size();

         int pos = 0;
         string best = "";
         while( pos<(int)lines[i].size() && hist.find(best + lines[i][pos])!=hist.end() ) {
            best += lines[i][pos];
            pos++;
         }
         res += 1 + min(use_buf, 2 + (int)lines[i].size() - (int)best.size() );

         for(int j=0; j<lines[i].size(); j++)
            hist.insert( lines[i].substr(0, j+1));
         buf = lines[i];
      }


      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	UndoHistory ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
