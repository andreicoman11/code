// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Jiro came to a flower shop to buy flowers.
// The flowers in the shop are arranged in some cells of a 
// rectangular grid.
// The layout of the grid is given as a vector <string> 
// flowers.
// If the j-th cell of the i-th row of the grid contains a 
// flower, then the j-th character of the i-th element of 
// flowers will be 'F'.
// (All indices in the previous sentence are 0-based.)
// If the particular cell is empty, the corresponding 
// character will be '.' (a period).
// 
// In order to buy flowers, Jiro has to draw a rectangle on 
// this grid and buy all the flowers which lie inside the 
// rectangle.
// Of course, the sides of the rectangle must be on cell 
// boundaries.
// (Therefore, the sides of the rectangle will necessarily be 
// parallel to the coordinate axes.)
// 
// Jiro wants to buy as many flowers as possible.
// Unfortunately, he cannot select the entire grid.
// Eel Saburo came to this shop before Jiro.
// Saburo has already drawn his rectangle.
// Saburo's rectangle contains just a single cell: the c-th 
// cell of the r-th row of the grid.
// (Again, both indices are 0-based.)
// Jiro's rectangle may not contain this cell.
// 
// You are given the vector <string> flowers and the ints r 
// and c.
// Return the maximum possible number of flowers Jiro can buy 
// in this situation.
// 
// DEFINITION
// Class:FoxAndFlowerShopDivTwo
// Method:theMaxFlowers
// Parameters:vector <string>, int, int
// Returns:int
// Method signature:int theMaxFlowers(vector <string> 
// flowers, int r, int c)
// 
// 
// CONSTRAINTS
// -flowers will contain R elements.
// -R will be between 2 and 10, inclusive.
// -Each element of flowers will contain C characters.
// -C will be between 1 and 10, inclusive.
// -Each character in flowers will be either 'F' or '.'.
// -r will be between 0 and R - 1, inclusive.
// -c will be between 0 and C - 1, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"F.F",
//  ".F.",
//  ".F."}
// 1
// 1
// 
// Returns: 2
// 
// The forbidden cell is the one in the middle. Jiro can buy 
// two flowers by drawing a rectangle that contains the 
// entire first row.
// 
// 1)
// {"F..",
//  "...",
//  "..."}
// 0
// 0
// 
// Returns: 0
// 
// There are no flowers Jiro can buy.
// 
// 2)
// {".FF.F.F",
//  "FF...F.",
//  "..FF.FF"}
// 1
// 2
// 
// Returns: 6
// 
// 
// 
// 3)
// {"F",
//  ".",
//  "F",
//  "F",
//  "F",
//  ".",
//  "F",
//  "F"}
// 4
// 0
// 
// Returns: 3
// 
// 
// 
// 4)
// {".FFF..F...",
//  "FFF...FF.F",
//  "..F.F.F.FF",
//  "FF..F.FFF.",
//  "..FFFFF...",
//  "F....FF...",
//  ".FF.FF..FF",
//  "..F.F.FFF.",
//  ".FF..F.F.F",
//  "F.FFF.FF.F"}
// 4
// 3
// 
// Returns: 32
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

class FoxAndFlowerShopDivTwo {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"F.F",
 ".F.",
 ".F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"F..",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {".FF.F.F",
 "FF...F.",
 "..FF.FF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 6; verify_case(2, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"F",
 ".",
 "F",
 "F",
 "F",
 ".",
 "F",
 "F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; int Arg3 = 3; verify_case(3, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {".FFF..F...",
 "FFF...FF.F",
 "..F.F.F.FF",
 "FF..F.FFF.",
 "..FFFFF...",
 "F....FF...",
 ".FF.FF..FF",
 "..F.F.FFF.",
 ".FF..F.F.F",
 "F.FFF.FF.F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 32; verify_case(4, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
	int theMaxFlowers(vector <string> f, int r, int c) {
      int sum = 0;
      for(int i=0; i<f.size(); i++)
      for(int j=0; j<f[i].size(); j++)
      for(int x=i; x<f.size(); x++)
      for(int y=j; y<f[i].size(); y++)
         if( (i>r || x<r) || (j>c || y<c) ) 
         {
            int sum2 = 0;
            for(int ii=i; ii<=x; ii++)
            for(int jj=j; jj<=y; jj++)
               if( f[ii][jj]=='F' ) sum2++;

            sum = max(sum, sum2);
         }
      return sum;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	FoxAndFlowerShopDivTwo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
