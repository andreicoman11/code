// BEGIN CUT HERE
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world 
// celebrate this 
// holiday. The following story takes place in the land of 
// reindeer, where Santa Claus resides.
// 
// 
// 
// The reindeer have invented a new magic spell. To pick a 
// name for the spell, they decided to concatenate their own 
// names.
// 
// 
// 
// Of course, this can be done in multiple ways. For example, 
// if there are two reindeer called "bob" and "bobby", they 
// could call the spell either "bobbobby" or "bobbybob". To 
// resolve this ambiguity, the reindeer picked the 
// lexicographically smallest possibility. (In this case, 
// that would be "bobbobby".)
// 
// 
// 
// You are given a string magicName. This is the name of the 
// spell. You do not know how many reindeer invented the 
// spell and what their names were. Your method must compute 
// and return the largest possible number of reindeer that 
// could have invented the spell.
// 
// DEFINITION
// Class:MagicNaming
// Method:maxReindeers
// Parameters:string
// Returns:int
// Method signature:int maxReindeers(string magicName)
// 
// 
// NOTES
// -Given two distinct strings of equal length, the 
// lexicographically smaller one is the one with a smaller 
// character in the first position where they differ
// -The name of each reindeer is a nonempty string of 
// lowercase letters.
// -It is always possible that the spell was created by a 
// single reindeer, so the return value is always defined.
// -Note that multiple reindeer may share the same name. See 
// Example #5 for clarification.
// 
// 
// CONSTRAINTS
// -The length of magicName will be between 1 and 50, 
// inclusive.
// -Each character in magicName will be between 'a' and 'z', 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// "aba"
// 
// Returns: 2
// 
// The magic spell called "aba" could have been invented by 
// two reindeer called "a" and "ba".
// 
// Note that this spell could not have been invented by three 
// reindeer. Their names would have to be "a", "b", and "a". 
// However, reindeer with these names would choose the name 
// "aab" for their spell.
// 
// 1)
// "babbaba"
// 
// Returns: 2
// 
// In this case there might have been two reindeer called 
// "ba" and "bbaba". More than two reindeer would never pick 
// this name for their spell.
// 
// 2)
// "philosophersstone"
// 
// Returns: 5
// 
// 
// 
// 3)
// "knuthmorrispratt"
// 
// Returns: 7
// 
// 
// 
// 4)
// "acrushpetrtourist"
// 
// Returns: 7
// 
// 
// 
// 5)
// "zzzzz"
// 
// Returns: 5
// 
// Note that multiple reindeer may share the same name.
// 
// END CUT HERE
#include <iostream>
#include <iomanip>
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
class MagicNaming {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 2; verify_case(0, Arg1, maxReindeers(Arg0)); }
	void test_case_1() { string Arg0 = "babbaba"; int Arg1 = 2; verify_case(1, Arg1, maxReindeers(Arg0)); }
	void test_case_2() { string Arg0 = "philosophersstone"; int Arg1 = 5; verify_case(2, Arg1, maxReindeers(Arg0)); }
	void test_case_3() { string Arg0 = "knuthmorrispratt"; int Arg1 = 7; verify_case(3, Arg1, maxReindeers(Arg0)); }
	void test_case_4() { string Arg0 = "acrushpetrtourist"; int Arg1 = 7; verify_case(4, Arg1, maxReindeers(Arg0)); }
	void test_case_5() { string Arg0 = "zzzzz"; int Arg1 = 5; verify_case(5, Arg1, maxReindeers(Arg0)); }

// END CUT HERE

	public: int maxReindeers(string name) {
		int n = name.size();
      int d[64][64];
      for(int i=0; i<=n; i++)
      for(int j=0; j<=n; j++)
         d[i][j] = -1;
      
      for(int i=0; i<n; i++)
         d[0][i] = 1;

      for(int i=1; i<n; i++)
      for(int j=i; j<n; j++)
      {
         for(int k=0; k<i; k++)
            if( d[k][i-1]>0 && name.substr(k, j-k+1).compare( name.substr(i,j-i+1) + name.substr(k, i-k) )<=0 )
            {
               d[i][j] = max(d[i][j], 1+d[k][i-1] );
            }
      }

      int res = -1;
      for(int i=0; i<n; i++)
         res = max(res, d[i][n-1]);
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MagicNaming ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
