// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a vector <int> y of length N. 
// The values in y describe N points in the plane: 
// for each x = 0, 1, ..., N - 1 there is a point at 
// coordinates (x, y[x]). 
// 
// Krolik is going to perform the following operation: 
// 
// 	Choose two of the given points, say A and B, with 
// different y-coordinates. 
// 	Consider the rectangle with sides parallel to coordinate 
// axes and points A and B in two opposite corners. 
// 	Erase all points strictly inside the rectangle. 
// 
// Return the maximum possible number of points Krolik can 
// erase by a single operation. 
// 
// 
// DEFINITION
// Class:PointErasingTwo
// Method:getMaximum
// Parameters:vector <int>
// Returns:int
// Method signature:int getMaximum(vector <int> y)
// 
// 
// NOTES
// -A point is strictly inside a rectangle if it is inside 
// the rectangle and does not lie on the border of the 
// rectangle. 
// 
// 
// CONSTRAINTS
// -y will contain between 2 and 50 elements, inclusive. 
// -Each element of y will be between 0 and 50, inclusive. 
// -y will contain at least 2 distinct elements. 
// 
// 
// EXAMPLES
// 
// 0)
// { 1, 2, 1, 1, 0, 4, 3 }
// 
// Returns: 2
// 
// If Krolik chooses A = (1, 2) and B = (4, 0), Krolik can 
// erase two points: (2, 1) and (3, 1).
// 
// 
// 
// 
// 1)
// { 0, 1 }
// 
// Returns: 0
// 
// 2)
// { 0, 1, 2, 3, 4 }
// 
// Returns: 3
// 
// 3)
// { 10, 19, 10, 19 }
// 
// Returns: 0
// 
// 
// 
// 4)
// { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 }
// 
// Returns: 5
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
class PointErasingTwo {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 1, 1, 0, 4, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { int Arr0[] = { 0, 1, 2, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { int Arr0[] = { 10, 19, 10, 19 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { int Arr0[] = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE

	public: int getMaximum(vector <int> y) {
		int max = 0;
    for(int i=0; i<y.sz-1; i++)
    for(int j=i+1; j<y.sz; j++)
      if( y[i]<y[j] )
      {
        int ins = 0;
        for(int k=i+1; k<j; k++)
          if( y[i]<y[k] && y[k]<y[j] ) ins++;
        max = (max<ins ? ins : max);
      } else if( y[i]>y[j] )
      {
        int ins = 0;
        for(int k=i+1; k<j; k++)
          if( y[i]>y[k] && y[k]>y[j] ) ins++;
        max = (max<ins ? ins : max);
      }
    return max;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PointErasingTwo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
