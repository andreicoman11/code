// BEGIN CUT HERE
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming 
// contest called SRM (Special Round Match)!
// 
// The coding phase is over, and you are now in the 
// intermission phase of the contest. There were 3 problems 
// in the contest. The i-th problem is worth between 1 and 
// points[i] points, inclusive, depending on when a solution 
// to the problem was submitted. The total score of a coder 
// is the total points of all problems whose solutions were 
// submitted by the coder.
// 
// The contest has a room summary containing a scoreboard of 
// all coders in the contest. The coders in the scoreboard 
// are sorted in decreasing order of their total score. For 
// each coder, the scoreboard shows the points of each 
// problem, or 0 if the coder didn't submit a solution to the 
// problem.
// 
// Unfortunately, you lose your internet connection in this 
// intermission phase. So, you ask your friend how the 
// scoreboard is currently like. However, your friend only 
// tells you the solutions submitted by each coder. This is 
// given in description. The j-th character of the i-th 
// element of description will be 'Y' if the i-th coder 
// submitted a solution to the j-th problem, or 'N' 
// otherwise. description describes the scoreboard from top 
// to bottom, i.e., description[0] describes the coder with 
// the highest score, description[1] (if any) describes the 
// coder with the second highest score, and so on. Moreover, 
// your friend also tells you that all coders have different 
// total scores.
// 
// Return the number of different possible scoreboards that 
// match your friend's description, modulo 1,000,000,007. 
// Your friend's description may be inaccurate, so, if no 
// scoreboards match it, return 0.
// 
// DEFINITION
// Class:SRMIntermissionPhase
// Method:countWays
// Parameters:vector <int>, vector <string>
// Returns:int
// Method signature:int countWays(vector <int> points, vector 
// <string> description)
// 
// 
// CONSTRAINTS
// -points will contain exactly 3 elements.
// -points[0] will be between 25000 and 30000, inclusive.
// -points[1] will be between 45000 and 60000, inclusive.
// -points[2] will be between 90000 and 110000, inclusive.
// -description will contain between 1 and 20 elements, 
// inclusive.
// -Each element of description will contain exactly 3 
// characters.
// -Each character in description will be 'Y' or 'N'.
// 
// 
// EXAMPLES
// 
// 0)
// {25000, 50000, 100000}
// {"YNN",
//  "NNN"}
// 
// Returns: 25000
// 
// The first coder's total score can be between 1 and 25000, 
// inclusive (25000 ways). The second coder's total score 
// must be 0 (1 way). So, in total there are 25000 x 1 = 
// 25000 different possible scoreboards.
// 
// 1)
// {30000, 60000, 90000}
// {"NYN",
//  "NYN"}
// 
// Returns: 799969993
// 
// If the first coder's total score is 2, then the second 
// coder's total score must be 1. If the first coder's total 
// score is 3, then the second coder's total score can be 1 
// or 2. If the first coder's total score is 4, then the 
// second coder's total score can be 1, 2, or 3, and so on. 
// So, there are (1 + 2 + 3 + ... + 59999) mod 1000000007 = 
// 799969993 different possible scoreboards.
// 
// 2)
// {25000, 45000, 110000}
// {"NNN",
//  "YYY"}
// 
// Returns: 0
// 
// The first coder didn't submit anything, but ranked above 
// the second coder who submitted all three problems. It is 
// impossible.
// 
// 3)
// {25600, 51200, 102400}
// {"NYY",
//  "YNY",
//  "YYY",
//  "YNN",
//  "YYN",
//  "NNY",
//  "NYN",
//  "NNN"}
// 
// Returns: 867560805
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
const int MOD = 1000000007;
const int VMAX = 200000;
int v[2][VMAX+12];
int w[4][VMAX+12];
class SRMIntermissionPhase {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25000, 50000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25000; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {30000, 60000, 90000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 799969993; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {25000, 45000, 110000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25600, 51200, 102400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 867560805; verify_case(3, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE
  int getY(string s)
  {
    return ((s[0]=='Y') + (s[1]=='Y') + (s[2]=='Y'));
  }
  int getP(vector<int> p, string s)
  {
    return ((s[0]=='Y')*p[0] + (s[1]=='Y')*p[1] + (s[2]=='Y')*p[2]);
  }
	public: int countWays(vector <int> p, vector <string> desc) {
    int n = desc.sz;
		vector<int> minp(n), maxp(n);
    minp[n-1] = getY(desc[n-1]);
    for(int i=n-2; i>=0; i--)
    {
      minp[i] = getY(desc[i]);
      if( minp[i]==0 && minp[i+1]>0 ) return 0;
      minp[i] = max(minp[i], minp[i+1] + 1);
    }

    maxp[0] = getP(p, desc[0]);
    for(int i=1; i<n; i++)
    {
      maxp[i] = getP(p, desc[i]);
      maxp[i] = min(maxp[i], maxp[i-1]-1);
      if( minp[i]>maxp[i] ) return 0;
    }

    int ii = n-1, t = 0;
    while( ii>=0 && maxp[ii]==0 ) ii--;
    if( ii<0 ) return 1;

    memset(w, 0, sizeof(w));
    for(int j=1; j<=VMAX; j++)
      w[0][j] = 1;

    for(int j=1; j<=3; j++)
    {
      int m=0, M=0;
      if( desc[ii][j-1]=='Y' ) m=1, M=p[j-1];
      for(int k=m; k<=VMAX; k++)
      {
        w[j][k+1] = (w[j][k] + w[j-1][k-m+1]) % MOD;
        w[j][k+1] = (w[j][k+1] - w[j-1][max(0,k-M-1+1)] + MOD) % MOD;
      }
    }

    memset(v, 0, sizeof(v));
    for(int j=minp[ii]; j<=maxp[ii]; j++)
      v[t][j] = (v[t][j-1] + (w[3][j+1] - w[3][j-1+1] + MOD) % MOD) % MOD;
    for(int j=maxp[ii]+1; j<=VMAX; j++)
      v[t][j] = v[t][j-1];

    for(int i = ii-1; i>=0; i--)
    {
      t = 1 - t;

      memset(w, 0, sizeof(w));
      for(int j=1; j<=VMAX; j++)
        w[0][j] = 1;

      for(int j=1; j<=3; j++)
      {
        int m=0, M=0;
        if( desc[i][j-1]=='Y' ) m=1, M=p[j-1];
        for(int k=m; k<=VMAX; k++)
        {
          w[j][k+1] = (w[j][k] + w[j-1][k-m+1]) % MOD;
          w[j][k+1] = (w[j][k+1] - w[j-1][max(0,k-M-1+1)] + MOD) % MOD;
        }
      }

      for(int j=0; j<minp[i]; j++)
        v[t][j] = 0;
      for(int j=minp[i]; j<=maxp[i]; j++)
      {
        LL add = (w[3][j+1] - w[3][j-1+1] + MOD);
        add = (add * (LL)v[1-t][j-1]) % MOD;
        v[t][j] = (v[t][j-1] + add) % MOD;
      }

      if( i )
      for(int j=maxp[i]+1; j<=maxp[i-1]; j++)
        v[t][j] = v[t][j-1];
    }
    return v[t][maxp[0]];
	}
};

// BEGIN CUT HERE 
int main()
{
	SRMIntermissionPhase ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
