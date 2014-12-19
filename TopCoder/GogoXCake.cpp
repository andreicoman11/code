// BEGIN CUT HERE
// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to cut and 
// eat cake. He used a rectangular baking dish to make a 
// cake. The dish is divided into a grid of unit square 
// cells. Initially, all the cells contained the cake.
// 
// Gogo's friend John wanted to eat the cake. Gogo gave John 
// a rectangular cake cutter with the following properties:
// 
// The cake cutter is divided into a grid of cells. The cells 
// are of the same size as the cells of the dish.
// The cake cutter contains cells of two types: used cells 
// and ignored cells.
// Each of the first row, the last row, the first column, and 
// the last column of the cutter contains at least one used 
// cell.
// 
// When used, the cake cutter must be placed on the dish 
// according to the following rules:
// 
// Each cell of the cutter must contain a single cell of the 
// dish.
// It is not allowed to flip or rotate the cutter. Rows and 
// columns of the cutter must correspond to some consecutive 
// rows and some consecutive columns of the dish in the given 
// orientation. (See the last two examples.)
// Each used cell of the cutter must be placed onto a cell 
// that still contains cake. The ignored cells may be placed 
// onto any cells.
// 
// 
// When the cake cutter is used in the way described above, 
// it removes the cake from all the used cells. John may have 
// used the cake cutter multiple times, one after another.
// 
// After John went home, Gogo examined the cake that remained 
// in the dish. He now wants to check whether John really cut 
// the cake according to the above rules. You are given 
// vector <string>s cake and cutter. The remaining cake is 
// described by cake. More precisely, cake[i][j] is 'X' if 
// the cell in the i-th row and j-th column of the dish still 
// contains cake; otherwise cake[i][j] is '.' (a period). The 
// cake cutter is described by cutter. More precisely, cutter
// [i][j] is '.' (a period) if the cell in the i-th row and j-
// th column of the cutter is used, and 'X' if the cell is 
// ignored.
// 
// Return "YES" (quotes for clarity) if it is possible that 
// John only ate the cake by using the cutter in the way 
// described above. Return "NO" otherwise.
// 
// DEFINITION
// Class:GogoXCake
// Method:solve
// Parameters:vector <string>, vector <string>
// Returns:string
// Method signature:string solve(vector <string> cake, vector 
// <string> cutter)
// 
// 
// NOTES
// -The used cells in the cutter do not have to be contiguous.
// 
// 
// CONSTRAINTS
// -cake will contain between 1 and 50 elements, inclusive.
// -Each element of cake will contain between 1 and 50 
// characters, inclusive.
// -All elements of cake will contain the same number of 
// characters.
// -Each character in each element of cake will be either '.' 
// or 'X'.
// -There will be at least one '.' in cake
// -cutter will contain between 1 and R elements, inclusive, 
// where R is the number of elements in cake.
// -Each element of cutter will contain between 1 and C 
// characters, inclusive, where C is the number of characters 
// in each element of cake.
// -All elements of cutter will contain the same number of 
// characters.
// -Each character in each element of cutter will be either 
// '.' or 'X'.
// -Each of the first row, the first column, the last row, 
// and the last column of the cutter will contain at least 
// one '.'.
// 
// 
// EXAMPLES
// 
// 0)
// {"X.X"
// ,"..."
// ,"..."
// ,"X.X"}
// {".X"
// ,".."
// ,"X."}
// 
// Returns: "YES"
// 
// 
// 
// 1)
// {"..XX"
// ,"...X"
// ,"X..."
// ,"XX.."}
// {".."
// ,".."}
// 
// Returns: "NO"
// 
// 
// 
// 2)
// {"...X..."}
// {"..."}
// 
// Returns: "YES"
// 
// 
// 
// 3)
// {".X."
// ,"X.X"
// ,".X."}
// {"."}
// 
// Returns: "YES"
// 
// 
// 
// 4)
// {"XXXXXXX"
// ,"X.....X"
// ,"X.....X"
// ,"X.....X"
// ,"XXXXXXX"}
// {".X."
// ,"XXX"
// ,".X."}
// 
// Returns: "NO"
// 
// 
// 
// 5)
// {".."
// ,"X."
// ,".X"}
// {".."
// ,".X"
// ,"X."}
// 
// Returns: "NO"
// 
// You may not flip the cutter.
// 
// 6)
// {"X.."
// ,".XX"
// ,".XX"}
// {".XX"
// ,".XX"
// ,"X.."}
// 
// Returns: "NO"
// 
// You may not rotate the cutter.
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

vector <string> cake, cut;

class GogoXCake {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X"
,"..."
,"..."
,"X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X"
,".."
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..XX"
,"...X"
,"X..."
,"XX.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".X."
,"X.X"
,".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X."
,"XXX"
,".X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".."
,"X."
,".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".X"
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(5, Arg2, solve(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"X.."
,".XX"
,".XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".XX"
,".XX"
,"X.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(6, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE
   bool add(int i, int j)
   {
      for(int x=0; x<cut.size(); x++)
      for(int y=0; y<cut[x].size(); y++)
         if( i+x>=cake.size() || j+y>=cake[0].size() || (cut[x][y]=='.' && cake[i+x][j+y]=='X') ) return false;
         else if( cake[i+x][j+y]==cut[x][y] ) cake[i+x][j+y] = 'X';
      return true;
   }

	public: string solve(vector <string> cake2, vector <string> cut2) {
		cake = cake2;
      cut = cut2;
      int x = 0;
      for(int i=0; i<cut[0].size(); i++)
         if( cut[0][i]=='.' ) {x = i; break;}

      for(int i=0; i<cake.size(); i++)
      for(int j=0; j<cake[i].size(); j++)
         if( cake[i][j]=='.' )
            if( x>j || !add(i, j-x) )
               return "NO";
      return "YES";
	}
	
};

// BEGIN CUT HERE 
int main()
{
	GogoXCake ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
