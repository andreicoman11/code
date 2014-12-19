// BEGIN CUT HERE
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not 
// display properly if viewed outside of the applet.
// 
// 
// Everybody loves geometry, so here is a geometry problem.
// You have a few marbles of possibly different sizes.
// You are given a vector <int> radius that describes the 
// marbles: each element of radius is the radius of one of 
// your marbles.
// 
// You want to place all marbles onto a straight line that is 
// drawn on the table.
// Clearly, this makes the problem two-dimensional: we can 
// just view the marbles as circles that will all be touching 
// the line from above.
// Of course, the marbles cannot overlap, so in our problem 
// no two circles are allowed to overlap.
// Note that you may place the marbles onto the line in any 
// order, you do not have to preserve the order in which they 
// are given in radius.
// 
// Additionally, you want to pack the bottoms of the marbles 
// as close together as possible.
// More precisely:
// For each marble consider the point where it touches the 
// line.
// Compute and return the smallest possible distance between 
// the farthest two of those points.
// (That is, if you imagine the line as going from the left 
// to the right, your task is to minimize the distance 
// between the leftmost and the rightmost of the points where 
// the circles touch the line.)
// 
// DEFINITION
// Class:MarblePositioning
// Method:totalWidth
// Parameters:vector <int>
// Returns:double
// Method signature:double totalWidth(vector <int> radius)
// 
// 
// NOTES
// -The returned values must have an absolute or relative 
// error less than 1e-9.
// 
// 
// CONSTRAINTS
// -radius will contain between 2 and 8 elements, inclusive.
// -Each element of radius will be between 1 and 1000000000 
// (10^9), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 2}
// 
// Returns: 2.8284271247461903
// 
// One of the best ways to place the marbles is the following 
// one:
// 
// 
// 
// 
// 1)
// {7,7,7}
// 
// Returns: 28.0
// 
// 
// 
// 2)
// {10, 20, 30}
// 
// Returns: 62.92528739883945
// 
// 
// 
// 
// 
// 3)
// {100, 100,11,11,25}
// 
// Returns: 200.0
// 
// 
// 
// 4)
// {1,999950884,1}
// 
// Returns: 63246.0
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

class MarblePositioning {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.8284271247461903; verify_case(0, Arg1, totalWidth(Arg0)); }
	void test_case_1() { int Arr0[] = {7,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 28.0; verify_case(1, Arg1, totalWidth(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 62.92528739883945; verify_case(2, Arg1, totalWidth(Arg0)); }
	void test_case_3() { int Arr0[] = {100, 100,11,11,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(3, Arg1, totalWidth(Arg0)); }
	void test_case_4() { int Arr0[] = {1,999950884,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 63246.0; verify_case(4, Arg1, totalWidth(Arg0)); }

// END CUT HERE

	public: 
   double getdist(int r1, int r2) {
      return 2.0 * sqrt( double(r1)*double(r2));
   }

	double totalWidth(vector <int> r) {
		double mindist = 8e+11;
      int n = r.size();
      sort(r.begin(), r.end());
      do{
         
         vector<double> pos(n);
         pos[0] = 0.0;
         for(int i=1; i<n; i++) {
            double maxdist = 0.0;
            for(int j=0; j<i; j++) {
               double dist = pos[j] + getdist(r[i], r[j]);
               maxdist = max(maxdist, dist);
            }
            pos[i] = maxdist;
         }
         mindist = min(mindist, pos[n-1] - pos[0]);

      }while( next_permutation(r.begin(), r.end()) );
      return mindist;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MarblePositioning ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
