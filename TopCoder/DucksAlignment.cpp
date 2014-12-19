// BEGIN CUT HERE
// PROBLEM STATEMENT
// Mr. Dengklek has a rectangular farm conveniently divided 
// into a grid of unit squares. At this moment, each unit 
// square contains at most one duck. Moreover, each row and 
// column of the farm also contains at most one duck. You are 
// given a vector <string> grid. The j-th character of the i-
// th element of grid will be 'o' if there is exactly one 
// duck in square (i, j), i.e., row i column j, or '.' if 
// there is no duck in that square. 
// 
// Today, Mr. Dengklek wants to align the ducks so that the 
// ducks form a contiguous line. More precisely, assume that 
// there are N ducks on the farm. After the alignment, the 
// ducks must either occupy N contiguous squares in some row 
// or N contiguous squares in some column. To accomplish 
// that, he will move the ducks one at a time. To move a duck 
// in square (a, b) to another empty square (c, d), he needs 
// |a-c| + |b-d| seconds, where |x| denotes the absolute 
// value of x. Mr. Dengklek can always move any duck to any 
// empty square he desires - the other ducks are not obstacles.
// 
// Return the minimum time in seconds Mr. Dengklek needs to 
// align the ducks. Note that restrictions imposed on the 
// initial placement of ducks guarantee that a proper 
// alignment is always possible.
// 
// DEFINITION
// Class:DucksAlignment
// Method:minimumTime
// Parameters:vector <string>
// Returns:int
// Method signature:int minimumTime(vector <string> grid)
// 
// 
// CONSTRAINTS
// -grid will contain between 1 and 50 elements, inclusive.
// -Each element of grid will contain between 1 and 50 
// characters, inclusive.
// -All elements of grid will contain the same number of 
// characters.
// -Each character of grid will be either 'o' or '.'.
// -Each row in grid will contain at most one character 'o'.
// -Each column in grid will contain at most one character 'o'.
// -grid will contain at least one character 'o'.
// 
// 
// EXAMPLES
// 
// 0)
// {".o",
//  "o."}
// 
// Returns: 1
// 
// Move either duck to an adjacent empty square.
// 
// 1)
// {".o...",
//  "..o..",
//  "....o"}
// 
// Returns: 3
// 
// One of the solutions is: move the the duck in the first 
// row one square to the right, and then move the duck in the 
// last row two squares to the left.
// 
// 2)
// {"o..........",
//  "..o........",
//  ".......o...",
//  "...........",
//  "...........",
//  "...........",
//  "........o..",
//  "..........."}
// 
// Returns: 16
// 
// Align all ducks in the second row.
// 
// 3)
// {".........",
//  "....o....",
//  "........."}
// 
// Returns: 0
// 
// 
// 
// 4)
// {"...o..........................",
//  "............................o.",
//  ".o............................",
//  "............o.................",
//  ".................o............",
//  "......................o.......",
//  "......o.......................",
//  "....o.........................",
//  "...............o..............",
//  ".......................o......",
//  "...........................o..",
//  ".......o......................"}
// 
// Returns: 99
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
class DucksAlignment {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o",
 "o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumTime(Arg0)); }
	void test_case_1() { string Arr0[] = {".o...",
 "..o..",
 "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimumTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, minimumTime(Arg0)); }
	void test_case_3() { string Arr0[] = {".........",
 "....o....",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(4, Arg1, minimumTime(Arg0)); }

// END CUT HERE

	public: 
    int getmin(int rows[], int os, int n)
    {
      int rowm = 1000;
      for(int i=0; i+os<=n; i++)
      {
        int rowst = 0, ls = 0;
        for(int j=0; j<i; j++)
          if( rows[j]!=-1 )
          {
            rowst += i-j;
            ls++;
          }

        for(int j=i; j<i+os; j++)
          if( rows[j]==-1 )
          {
            if( ls ) {rowst += j-i; ls--;}
            else rowst += i+os-1-j;
          }

        for(int j=i+os; j<n; j++)
          if( rows[j]!=-1 )
            rowst += j-i-os+1;

        rowm = min(rowm, rowst);
      }
      return rowm;
    }

    int minimumTime(vector <string> g) {
		int rows[64], cols[64];
    int n = g.sz, m = g[0].sz, os = 0;
    for(int i=0; i<n; i++)
    {
      rows[i] = -1;
      for(int j=0; j<m; j++)
        if(g[i][j]=='o' ) {os++; rows[i] = j;}
    }

    for(int j=0; j<m; j++)
    {
      cols[j] = -1;
      for(int i=0; i<n; i++)
        if(g[i][j]=='o' ) cols[j] = i;
    }

    int minst = 500000;
    int rowm = getmin(rows, os, n);
    int colm = getmin(cols, os, m);

    for(int i=0; i<n; i++)
    {
      int ossum = 0;
      for(int j=0; j<m; j++)
        if( cols[j]>=0 )
          ossum += abs(i - cols[j]);
      minst = min(minst, ossum+colm);
    }

    for( int j=0; j<m; j++)
    {
      int ossum = 0;
      for(int i=0; i<n; i++)
        if( rows[i]>=0 )
          ossum += abs(j - rows[i]);
      minst = min(minst, ossum+rowm);
    }
    
    return minst;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	DucksAlignment ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
