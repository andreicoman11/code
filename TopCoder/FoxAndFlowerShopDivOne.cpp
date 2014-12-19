// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Jiro came to a flower shop to buy flowers.
// The flowers in the shop are arranged in some cells of a 
// rectangular grid.
// The layout of the grid is given as a vector <string> 
// flowers.
// There are two types of flowers in the shop: lilies and 
// petunias.
// If the j-th cell of the i-th row of the grid contains a 
// flower, then the j-th character of the i-th element of 
// flowers will be 'L' if it is a lily, and 'P' if it is a 
// petunia.
// (All indices in the previous sentence are 0-based.)
// If the particular cell is empty, the corresponding 
// character will be '.' (a period).
// 
// In order to buy flowers, Jiro has to draw two disjoint 
// rectangles on this grid and buy all the flowers which lie 
// inside the rectangles.
// Of course, the sides of the rectangles must be on cell 
// boundaries.
// (Therefore, the sides of the rectangles will necessarily 
// be parallel to the coordinate axes.)
// The rectangles are allowed to touch, but they may not 
// intersect.
// In other words, the rectangles may share a common 
// boundary, but no cell may belong to both rectangles.
// Each of the two rectangles must contain at least one cell.
// 
// Jiro wants to buy approximately the same number of lilies 
// and petunias.
// More precisely, the positive difference between the number 
// of lilies and petunias must be at most maxDiff, inclusive.
// Given that constraint, Jiro wants to buy as many flowers 
// as possible.
// 
// You are given the vector <string> flowers and the int 
// maxDiff.
// Return the maximum possible number of flowers Jiro can buy 
// in this situation.
// If there is no valid way to buy flowers, return -1 instead.
// 
// DEFINITION
// Class:FoxAndFlowerShopDivOne
// Method:theMaxFlowers
// Parameters:vector <string>, int
// Returns:int
// Method signature:int theMaxFlowers(vector <string> 
// flowers, int maxDiff)
// 
// 
// CONSTRAINTS
// -flowers will contain between 2 and 30 elements, inclusive.
// -Each element of flowers will contain the same number of 
// characters.
// -Each element of flowers will contain between 1 and 30 
// characters, inclusive.
// -Each character in flowers will be either 'L', 'P', or '.'.
// -maxDiff will be between 0 and 900, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"LLL",
//  "PPP",
//  "LLL"}
// 1
// 
// Returns: 7
// 
// Jiro cannot buy all the flowers, because the difference 
// between the number of lilies and the number of petunias 
// would be too large.
// The best he can do is to buy 7 flowers: 4 lilies and 3 
// petunias.
// One way of doing so is to draw two rectangles: (0,0)-(1,2) 
// and (2,0)-(2,0).
// Note that (r1,c1)-(r2,c2) denotes a rectangle with cell 
// (r1,c1) in the top left corner and cell (r2,c2) in the 
// bottom right corner.
// (All indices are 0-based.)
// 
// 1)
// {"LLL",
//  "PPP",
//  "LLL"}
// 0
// 
// Returns: 6
// 
// This time Jiro is required to buy the same number of 
// lilies and petunias.
// Therefore the best he can do is to buy three of each kind.
// 
// 2)
// {"...",
//  "...",
//  "..."}
// 3
// 
// Returns: 0
// 
// There are no flowers.
// 
// 3)
// {"LLPL.LPP",
//  "PLPPPPLL",
//  "L.P.PLLL",
//  "LPL.PP.L",
//  ".LLL.P.L",
//  "PPLP..PL"}
// 2
// 
// Returns: 38
// 
// 
// 
// 4)
// {"LLLLLLLLLL",
//  "LLLLLLLLLL",
//  "LLLLLLLLLL",
//  "LLLLLLLLLL",
//  "LLLLLLLLLL"}
// 0
// 
// Returns: -1
// 
// Here it is impossible to draw the two rectangles. 
// Regardless of how Jiro draws them, he will surely buy more 
// lilies than petunias, and that is not allowed.
// 
// 5)
// {"LLLP..LLP.PLL.LL..LP",
//  "L.PL.L.LLLL.LPLLPLP.",
//  "PLL.LL.LLL..PL...L..",
//  ".LPPP.PPPLLLLPLP..PP",
//  "LP.P.PPL.L...P.L.LLL",
//  "L..LPLPP.PP...PPPL..",
//  "PP.PLLL.LL...LP..LP.",
//  "PL...P.PPPL..PLP.L..",
//  "P.PPPLPLP.LL.L.LLLPL",
//  "PLLPLLP.LLL.P..P.LPL",
//  "..LLLPLPPPLP.P.LP.LL",
//  "..LP..L..LLPPP.LL.LP",
//  "LPLL.PLLPPLP...LL..P",
//  "LL.....PLL.PLL.P....",
//  "LLL...LPPPPL.PL...PP",
//  ".PLPLLLLP.LPP...L...",
//  "LL...L.LL.LLLPLPPPP.",
//  "PLPLLLL..LP.LLPLLLL.",
//  "PP.PLL..L..LLLPPL..P",
//  ".LLPL.P.PP.P.L.PLPLL"}
// 9
// 
// Returns: 208
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

class FoxAndFlowerShopDivOne {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; verify_case(0, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 6; verify_case(1, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 38; verify_case(3, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(4, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 208; verify_case(5, Arg2, theMaxFlowers(Arg0, Arg1)); }

// END CUT HERE

	public: 
   int theMaxFlowersImpl(vector <string> f, int maxDiff) {
		int l[32][32];
      int p[32][32];
      int n = f.size(), m = f[0].size();
      memset(l, 0, sizeof(l));
      memset(p, 0, sizeof(p));

      for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
      {
         l[i][j] = (f[i-1][j-1]=='L' ? 1 : 0) + l[i-1][j] + l[i][j-1] - l[i-1][j-1];
         p[i][j] = (f[i-1][j-1]=='P' ? 1 : 0) + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
      }

      int rez = -1;
      for(int d=1; d<n; d++)
      {
         map<int,int> up, low;
         for(int i=1; i<=d; i++)
         for(int j=1; j<=m; j++)
         for(int x=i; x<=d; x++)
         for(int y=j; y<=m; y++)
         {
            int ln = l[x][y] - l[x][j-1] - l[i-1][y] + l[i-1][j-1];
            int pn = p[x][y] - p[x][j-1] - p[i-1][y] + p[i-1][j-1];
            if( up[ln-pn] < ln+pn )
               up[ln-pn] = ln + pn;
         }

         for(int i=d+1; i<=n; i++)
         for(int j=1; j<=m; j++)
         for(int x=i; x<=n; x++)
         for(int y=j; y<=m; y++)
         {
            int ln = l[x][y] - l[x][j-1] - l[i-1][y] + l[i-1][j-1];
            int pn = p[x][y] - p[x][j-1] - p[i-1][y] + p[i-1][j-1];
            if( low[ln-pn] < ln+pn )
               low[ln-pn] = ln + pn;
         }


         for(map<int,int>::iterator it1=up.begin(); it1!=up.end(); it1++)
         for(map<int,int>::iterator it2=low.begin(); it2!=low.end(); it2++)
            if( (abs(it1->first + it2->first) <=maxDiff) && (it1->second+it2->second>rez) )
               rez = it1->second + it2->second;
      }

      return rez;
	}
		
   int theMaxFlowers(vector <string> f, int maxDiff) {
      vector<string> f2;

      for(int i=0; i<f[0].size(); i++)
      {
         string f2row;
         for(int j=0; j<f.size(); j++)
            f2row += f[j][i];
         f2.push_back(f2row);
      }
      
      return max( theMaxFlowersImpl(f, maxDiff), theMaxFlowersImpl(f2, maxDiff));
   }
};

// BEGIN CUT HERE 
int main()
{
	FoxAndFlowerShopDivOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
