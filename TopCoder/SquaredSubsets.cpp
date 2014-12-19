// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Given a set of points in the XY plane and an integer n, a 
// subset P of those points is called n-squared if it is not 
// empty and there exists a square of side n in the XY plane 
// with its sides parallel to the axes such that a point from 
// the given set of points is in P if and only if it is 
// contained within the square. A point lying on a side or a 
// vertex of the square is considered to be contained in it.
// 
// You will be given n as explained in the input. You will 
// also be given two vector <int>s x and y such that the 
// coordinates of point i are (x[i],y[i]). Return the number 
// of n-squared subsets in the input set described by x and y.
// 
// 
// DEFINITION
// Class:SquaredSubsets
// Method:countSubsets
// Parameters:int, vector <int>, vector <int>
// Returns:long long
// Method signature:long long countSubsets(int n, vector 
// <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 100000000 (10^8), inclusive.
// -x and y will contain between 1 and 50 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element of x and y will be between -100000000 (-10
// ^8) and 100000000 (10^8), inclusive.
// -All described points will be different.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// {-5,0,5}
// {0,0,0}
// 
// Returns: 5
// 
// The following subsets are squared: {(-5,0)}, {(0,0)}, 
// {(5,0)}, {(-5,0),(0,0)}, {(0,0),(5,0)}.
// 
// 1)
// 10
// {-5,0,5}
// {0,0,0}
// 
// Returns: 5
// 
// The following subsets are squared: {(-5,0)}, {(5,0)}, 
// {(0,0),(5,0)}, {(-5,0),(0,0)}, {(-5,0),(0,0),(5,0)}.
// 
// 2)
// 100000000
// {-1,-1,-1,0,1,1,1}
// {-1,0,1,1,-1,0,1}
// 
// Returns: 21
// 
// 
// 
// 3)
// 5
// {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}
// {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}
// 
// Returns: 66
// 
// 
// 
// 4)
// 1
// {-1,0}
// {0,0}
// 
// Returns: 3
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
class SquaredSubsets {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100000000; int Arr1[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,0,1,1,-1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 21LL; verify_case(2, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 66LL; verify_case(3, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(4, Arg3, countSubsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

	bool isinrect(int vx, int vy, int x, int y, int n)
  {
    return  vx>=x && vx<=x+n &&
            vy>=y && vy<=y+n;
  }
  LL getsubset(int n, vector <int> vx, vector <int> vy, int x, int y)
  {
    LL res=0;
    for(int i=0; i<vx.sz; i++)
      res = (res<<1) + int(isinrect(vx[i], vy[i], x, y, n));
    return res;
  }
	public: long long countSubsets(int n, vector <int> x, vector <int> y) {
    n*=2;
		set<LL> ss;
    vector<int> xs, ys;
    for(int i=0; i<x.sz; i++)
    {
      x[i]*=2;  y[i]*=2;
      xs.pb(x[i]); xs.pb(x[i]-n-1);
      ys.pb(y[i]); ys.pb(y[i]-n-1);
    }
    sort(xs.begin(), xs.end()); unique(xs.begin(), xs.end());
    sort(ys.begin(), ys.end()); unique(ys.begin(), ys.end());
    
    for(int i=0; i<xs.sz; i++)
    for(int j=0; j<ys.sz; j++)
    {
      ss.insert( getsubset(n, x, y, xs[i], ys[j]) );
      ss.insert( getsubset(n, x, y, xs[i]-n, ys[j]) );
      ss.insert( getsubset(n, x, y, xs[i], ys[j]-n) );
      ss.insert( getsubset(n, x, y, xs[i]-n, ys[j]-n) );
    }
    ss.erase(0);
    return (LL)ss.sz;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	SquaredSubsets ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
