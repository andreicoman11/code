// BEGIN CUT HERE
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming 
// contest called SRM (Special Round Match)!
// 
// You are now in the system test phase of the contest. There 
// were N coders in the contest. There were 3 problems in the 
// contest. The system has tested all submitted solutions in 
// the contest. For each submitted solution, there are 3 
// possible outcomes: 'passed', 'failed', and 'challenged'.
// 
// The contest has a division summary containing a scoreboard 
// of all coders in the contest. For each coder, the 
// scoreboard shows the outcome of the submitted solution of 
// each problem, or an 'X' if the coder didn't submit a 
// solution to the problem. The coders in the scoreboard are 
// sorted in descending order of the number of passed 
// solutions. If there is a tie, then they are sorted in 
// ascending order of the number of challenged solutions. If 
// there is still a tie, the scoreboard may show them in 
// arbitrary order.
// 
// Unfortunately, you lose your internet connection in this 
// system test phase. So, you ask your friend how the 
// scoreboard is currently like. However, your friend only 
// tells you the solutions submitted by each coder. This is 
// given in description. The j-th character of the i-th 
// element of description will be 'Y' if the i-th coder 
// submitted a solution to the j-th problem, or 'N' 
// otherwise. description describes the scoreboard from top 
// to bottom, i.e., description[0] describes the coder in the 
// first position, description[1] (if any) describes the 
// coder in the second position, and so on.
// 
// Return the number of different possible scoreboards that 
// match your friend's description, modulo 1,000,000,007.
// 
// DEFINITION
// Class:SRMSystemTestPhase
// Method:countWays
// Parameters:vector <string>
// Returns:int
// Method signature:int countWays(vector <string> description)
// 
// 
// CONSTRAINTS
// -description will contain between 1 and 50 elements, 
// inclusive.
// -Each element of description will contain exactly 3 
// characters.
// -Each character in description will be 'Y' or 'N'.
// 
// 
// EXAMPLES
// 
// 0)
// {"YYY"}
// 
// Returns: 27
// 
// There are 3 possible outcomes for each solution, so there 
// are 3^3 = 27 different possible scoreboards.
// 
// 1)
// {"YNN",
//  "NYN"}
// 
// Returns: 6
// 
// Here are the 6 different scoreboards:
// 
// 
// +----------------------------------
// +----------------------------------+
// | passed     X          X          | passed     X          
// X          |
// | X          passed     X          | X          failed     
// X          |
// +----------------------------------
// +----------------------------------+
// | passed     X          X          | failed     X          
// X          |
// | X          challenged X          | X          failed     
// X          |
// +----------------------------------
// +----------------------------------+
// | failed     X          X          | challenged X          
// X          |
// | X          challenged X          | X          challenged 
// X          |
// +----------------------------------
// +----------------------------------+
// 
// 
// 2)
// {"YNN",
//  "NNN",
//  "NNY"}
// 
// Returns: 4
// 
// Here are the 4 different scoreboards:
// 
// 
// +----------------------------------
// +----------------------------------+
// | passed     X          X          | passed     X          
// X          |
// | X          X          X          | X          X          
// X          |
// | X          X          failed     | X          X          
// challenged |
// +----------------------------------
// +----------------------------------+
// | failed     X          X          | failed     X          
// X          |
// | X          X          X          | X          X          
// X          |
// | X          X          failed     | X          X          
// challenged |
// +----------------------------------
// +----------------------------------+
// 
// 
// 3)
// {"NNN",
//  "NNN"}
// 
// Returns: 1
// 
// 
// 
// 4)
// {"YYY",
//  "YNY",
//  "NYY",
//  "YYN",
//  "YYY",
//  "YNN"}
// 
// Returns: 15176
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

const LL MOD = 1000000007;

class SRMSystemTestPhase {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNN",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"YNN",
 "NNN",
 "NNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYY",
 "YNY",
 "NYY",
 "YYN",
 "YYY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15176; verify_case(4, Arg1, countWays(Arg0)); }

// END CUT HERE
  void printd(LL d[])
  {
    LL tpos = 0;
    for(int i=0; i<64; i++)
      tpos = (tpos+d[i])%MOD;
    cout << tpos << "\n";
  }
	public: int countWays(vector <string> desc) {
    LL d[2][64];
    memset(d, 0, sizeof(d));
    int t = 0;
    for(int i=0; i<64; i++)
    {
      int r[4] = {(i>>4)&3, (i>>2)&3, i&3};
      if( ((desc[0][0]=='N' && r[0]==0) || (desc[0][0]=='Y' && r[0])) &&
          ((desc[0][1]=='N' && r[1]==0) || (desc[0][1]=='Y' && r[1])) &&
          ((desc[0][2]=='N' && r[2]==0) || (desc[0][2]=='Y' && r[2])))
            d[t][i] = 1LL;
    }

    t = 1-t;
    int wins, chal, wins2, chal2;
    LL pos;
    for(int i=1; i<desc.sz; i++)
    {
      //printd(d[1-t]);
      for(int j=0; j<64; j++)
      {
        d[t][j] = 0;
        int r[4] = {(j>>4)&3, (j>>2)&3, j&3};
        if( ((desc[i][0]=='N' && r[0]==0) || (desc[i][0]=='Y' && r[0])) &&
            ((desc[i][1]=='N' && r[1]==0) || (desc[i][1]=='Y' && r[1])) &&
            ((desc[i][2]=='N' && r[2]==0) || (desc[i][2]=='Y' && r[2])))
          {
            pos = 0;
            wins = (r[0]==3) + (r[1]==3) + (r[2]==3);
            chal = (r[0]==2) + (r[1]==2) + (r[2]==2);
            for(int k=0; k<64; k++)
              if( d[1-t][k] )
              {
                int r2[4] = {(k>>4)&3, (k>>2)&3, k&3};
                wins2 = (r2[0]==3) + (r2[1]==3) + (r2[2]==3);
                chal2 = (r2[0]==2) + (r2[1]==2) + (r2[2]==2);
                if( wins<wins2 || (wins==wins2 && chal>=chal2) )
                  pos = (pos + d[1-t][k]) % MOD;
              }
            d[t][j] = (d[t][j] + pos)%MOD;
          }
      }
      t = 1-t;
    }

    LL tpos = 0;
    for(int i=0; i<64; i++)
      tpos = (tpos + d[1-t][i])%MOD;
    return tpos;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	SRMSystemTestPhase ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
