// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Jiro has a rectangular grid with H rows and W columns 
// (i.e., the grid has H*W cells in total). Initially, each 
// cell in the grid contained the character '0'.
// 
// A row flip is an operation in which Jiro picks a row of 
// the grid, and in that row he changes all '0's to '1's and 
// vice versa.
// Similarly, a column flip is an operation in which Jiro 
// does the same to a column of the grid.
// Jiro took the grid that contained '0's everywhere.
// He performed a row flip Rcount times, and then a column 
// flip Ccount times.
// (It is possible that Jiro flipped the same row or column 
// multiple times.)
// At the end, Jiro noticed that there are exactly S '1's in 
// the grid.
// 
// You are given the ints H, W, Rcount, Ccount, and S.
// We are interested in the number of different ways in which 
// Jiro could have flipped the rows and columns of the grid.
// Two ways of flipping are considered different if there is 
// a row or a column that was flipped a different number of 
// times.
// (That is, the order in which the rows and columns are 
// flipped does not matter.)
// Return the number of different ways of flipping that match 
// the given situation, modulo 555,555,555.
// 
// 
// DEFINITION
// Class:XorBoard
// Method:count
// Parameters:int, int, int, int, int
// Returns:int
// Method signature:int count(int H, int W, int Rcount, int 
// Ccount, int S)
// 
// 
// CONSTRAINTS
// -H will be between 1 and 1,555, inclusive.
// -W will be between 1 and 1,555, inclusive.
// -Rcount will be between 0 and 1,555, inclusive.
// -Ccount will be between 0 and 1,555, inclusive.
// -S will be between 0 and H*W, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 2
// 2
// 2
// 4
// 
// Returns: 4
// 
// In two of the four ways, Jiro flips each row once, and 
// then the same column twice.
// In the other two ways he first flips the same row twice, 
// and then each column once.
// 
// 1)
// 2
// 2
// 0
// 0
// 1
// 
// Returns: 0
// 
// Without any flips, all cells still contain '0's, so S=1 is 
// impossible.
// 
// 2)
// 10
// 20
// 50
// 40
// 200
// 
// Returns: 333759825
// 
// Rcount and Ccount may be greater than H and W.
// 
// 3)
// 1200
// 1000
// 800
// 600
// 4000
// 
// Returns: 96859710
// 
// 
// 
// 4)
// 555
// 555
// 555
// 555
// 5550
// 
// Returns: 549361755
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
#define MOD 555555555
int comb[1600][1600], hs[1600][1600], WS[1600][1600];

class XorBoard {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 4; verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 50; int Arg3 = 40; int Arg4 = 200; int Arg5 = 333759825; verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1200; int Arg1 = 1000; int Arg2 = 800; int Arg3 = 600; int Arg4 = 4000; int Arg5 = 96859710; verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 555; int Arg1 = 555; int Arg2 = 555; int Arg3 = 555; int Arg4 = 5550; int Arg5 = 549361755; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

	public: 
	int count(int H, int W, int rf, int cf, int S) {
      memset(comb, 0, sizeof(comb));
	  for(int i=0; i<1600; i++)
      {
         comb[i][0] = comb[i][i] = 1;
         for(int j=1; j<i; j++)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	   }
      
		memset(WS, 0, sizeof(WS));
		memset(hs, 0, sizeof(hs));
      
	  for(int j=0; j<=W; j++)
		  WS[0][j] = 1;
      for(int i=1; i<1600; i++) {
	  for(int j=W; j>=0;j--)
         WS[i][j] = (WS[i][j+1] + WS[i-1][j]) % MOD;
      }
      
	  for(int j=0; j<=H; j++)
		  hs[0][j] = 1;
      for(int i=1; i<1600; i++) {
	  for(int j=H; j>=0;j--)
         hs[i][j] = (hs[i][j+1] + hs[i-1][j]) % MOD;
      }

      int rez = 0;
      int rmax = min(rf, H);
      if( rmax<rf && (rf-rmax)%2==1 ) rmax--;
	  // r*W + c*H - 2*r*c == S
	  // c*(H - 2*r) == S - r*W
      for(int r = rmax; r>=0; r-=2)
         if( H==2*r && r )
         {
            if( r*W!=S ) continue;
            LL crez = ((LL)comb[H][r] * hs[(rf-r)/2][1]) % MOD;

			//LL pow = 1;
			//for(int i=0; i<=cf; i++) {
			//	 pow = (pow * W) % MOD;
			//}

            //crez = (crez * WS[cf]) % MOD;
			//crez = (crez * pow) % MOD;
			crez = (crez * WS[cf][1]) % MOD;
            rez = (rez + crez) % MOD;
         }
         else 
         {
            if( S==r*W && cf%2==0 ) {
               LL crez = ((LL) comb[H][r] * hs[(rf-r)/2][1]) % MOD;
               crez = (crez * WS[cf/2][1]) % MOD; //WS[cf/2] // comb[W][cf/2]
               rez = (rez + crez) % MOD;
               continue;
            }
            if( (S - r*W) % (H-2*r) || S==r*W ) continue;
			
            int c = (S - r*W) / (H-2*r);
            if( c>=0 && c<=cf && (cf-c)%2==0 )
            {
               LL crez = ((LL)comb[H][r] * hs[(rf-r)/2][1]) % MOD;
               crez = (crez * comb[W][c]) % MOD;
               crez = (crez * WS[(cf-c)/2][1]) % MOD;
               rez = (rez + (crez%MOD)) % MOD;
            }
         } 

      return rez;
   }
};

// BEGIN CUT HERE 
int main()
{
	XorBoard ___test; 
	cout << ___test.count(1554,1554,1555,1555,1207458);
	___test.run_test(-1); 
} 
// END CUT HERE