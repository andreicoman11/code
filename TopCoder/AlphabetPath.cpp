// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a 2-dimensional matrix of characters 
// represented by the vector <string> letterMaze. The i-th 
// character of the j-th element of letterMaze  represents 
// the character at row i and column j. Each of the 26 
// letters from 'A' to 'Z' appears exactly once in 
// letterMaze, the remaining characters are periods ('.').
// 
// An alphabet path is a sequence of 26 elements of the 
// matrix such that:
// 
// The first element contains the letter 'A'.
// The first element and the second element are (horizontally 
// or vertically) adjacent.
// The second element contains the letter 'B'.
// The second element and the third element are (horizontally 
// or vertically) adjacent.
// ...
// The 25-th element and the 26-th element are (horizontally 
// or vertically) adjacent.
// The last, 26-th element contains the letter 'Z'.
// 
// Given letterMaze return string "YES" if the alphabet path 
// exists in the matrix and "NO" otherwise.
// 
// DEFINITION
// Class:AlphabetPath
// Method:doesItExist
// Parameters:vector <string>
// Returns:string
// Method signature:string doesItExist(vector <string> 
// letterMaze)
// 
// 
// NOTES
// -Formally, elements (x1,y1) and (x2,y2) are horizontally 
// or vertically adjacent if and only if abs(x1 - x2) + abs
// (y1 - y2) = 1. 
// 
// 
// CONSTRAINTS
// -letterMaze will contain between 1 and 50 elements, 
// inclusive.
// -Each element of letterMaze will contain between 1 and 50 
// characters, inclusive.
// -All the elements of letterMaze will contain the same 
// number of characters.
// -Each element of letterMaze will only contain uppercase 
// letters ('A'-'Z') and periods ('.').
// -Each uppercase letter from 'A' to 'Z' will appear exactly 
// once in letterMaze.
// 
// 
// EXAMPLES
// 
// 0)
// {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
// 
// Returns: "YES"
// 
// Simply go from left to right.
// 
// 1)
// {"ADEHI..Z",
//  "BCFGJK.Y",
//  ".PONML.X",
//  ".QRSTUVW"}
// 
// 
// Returns: "YES"
// 
// 
// 
// 2)
// {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}
// 
// Returns: "NO"
// 
// 
// 
// 3)
// {"ABC.......",
//  "...DEFGHIJ",
//  "TSRQPONMLK",
//  "UVWXYZ...."}
// 
// Returns: "NO"
// 
// The cells marked with C and D are not adjacent, it is 
// impossible to make an alphabet path in this case.
// 
// 4)
// {"..............",
//  "..............",
//  "..............",
//  "...DEFGHIJK...",
//  "...C......L...",
//  "...B......M...",
//  "...A......N...",
//  "..........O...",
//  "..ZY..TSRQP...",
//  "...XWVU.......",
//  ".............."}
// 
// Returns: "YES"
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
class AlphabetPath {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, doesItExist(Arg0)); }
	void test_case_1() { string Arr0[] = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, doesItExist(Arg0)); }
	void test_case_2() { string Arr0[] = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, doesItExist(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, doesItExist(Arg0)); }
	void test_case_4() { string Arr0[] = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, doesItExist(Arg0)); }

// END CUT HERE

	public: string doesItExist(vector <string> l) {
		int x=-1, y=-1;
    int n = l.sz, m=l[0].sz;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if( l[i][j]=='A' )
      {
        x = i;
        y = j;
        i = n; j = m;
      }

    char c = 'A';
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while( c<'Z' )
    {
      bool f = 0;
      for(int i=0; i<4; i++)
      {
        int a = x+dx[i];
        int b = y+dy[i];
        if( a>=0 && b>=0 && a<n && b<m && l[a][b]==c+1 )
        {
          x = a;
          y = b;
          f = 1;
        }
      }
      if( !f ) return "NO";
      c++;
    }

    return "YES";
	}
	
};

// BEGIN CUT HERE 
int main()
{
	AlphabetPath ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
