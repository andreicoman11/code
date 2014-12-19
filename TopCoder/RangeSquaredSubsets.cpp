// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Given a real number n, a set of points P in the XY plane 
// is called n-squared if it is not empty and there exists a 
// square of side n in the XY plane with its sides parallel 
// to the axes such that a point from the given set of points 
// is in P if and only if it is contained within the square. 
// A point lying on a side or a vertex of the square is 
// considered to be contained in it.
// 
// You will be given two ints nlow and nhigh. You will also 
// be given two vector <int>s x and y such that the 
// coordinates of point i are (x[i],y[i]). Return the number 
// of subsets of the input set described by x and y that are 
// n-squared for some n between nlow and nhigh, inclusive.
// 
// 
// DEFINITION
// Class:RangeSquaredSubsets
// Method:countSubsets
// Parameters:int, int, vector <int>, vector <int>
// Returns:long long
// Method signature:long long countSubsets(int nlow, int 
// nhigh, vector <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -nlow will be between 1 and 100000000 (10^8), inclusive.
// -nhigh will be between nlow and 100000000 (10^8), inclusive.
// -x and y will contain between 1 and 40 elements, inclusive.
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
// 5
// {-5,0,5}
// {0,0,0}
// 
// Returns: 5
// 
// The following subsets are 5-squared: {(-5,0)}, {(0,0)}, 
// {(5,0)}, {(-5,0),(0,0)}, {(0,0),(5,0)}.
// 
// 1)
// 10
// 10
// {-5,0,5}
// {0,0,0}
// 
// Returns: 5
// 
// The following subsets are 10-squared: {(-5,0)}, {(5,0)}, 
// {(0,0),(5,0)}, {(-5,0),(0,0)}, {(-5,0),(0,0),(5,0)}.
// 
// 2)
// 1
// 100
// {-5,0,5}
// {0,0,0}
// 
// Returns: 6
// 
// {(-5,0),(5,0)} is not x-squared for any x. From the 
// previous 2 examples you can infer that all other non-empty 
// subsets are 5-squared or 10-squared.
// 
// 3)
// 3
// 100000000
// {-1,-1,-1,0,1,1,1}
// {-1,0,1,1,-1,0,1}
// 
// Returns: 21
// 
// 
// 
// 4)
// 64
// 108
// {-56,-234,12,324,-12,53,0,234,1,12,72}
// {6,34,2,235,234,234,342,324,234,234,234}
// 
// Returns: 26
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
#define INF 1000000007
class RangeSquaredSubsets {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(0, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(1, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 100; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 6LL; verify_case(2, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 100000000; int Arr2[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-1,0,1,1,-1,0,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 21LL; verify_case(3, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 64; int Arg1 = 108; int Arr2[] = {-56,-234,12,324,-12,53,0,234,1,12,72}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,34,2,235,234,234,342,324,234,234,234}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 26LL; verify_case(4, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  bool isinrect(int x0, int y0, int x1, int y1, int px, int py)
  {
	  return (x0 <= px && px <= x1 && y0 <= py && py <= y1);
  }
  bool isNSquare(int nlow, int nhigh, int nxi, int nyi, int nxj, int nyj)
  {
	  int dim = max(nlow, max(nxi, nyi));
	  return dim <= nhigh && dim < nxj && dim < nyj;
  }
	public: long long countSubsets(int nlow, int nhigh, vector <int> px, vector <int> py) 
  {
		set<long long> ss;
	  set<int> sx(px.begin(), px.end()), sy(py.begin(), py.end());
	  sx.insert(INF); sx.insert(-INF);
	  sy.insert(INF); sy.insert(-INF);
	  vector<int> x(sx.begin(), sx.end()), y(sy.begin(), sy.end());
  	
	  for(int xi = 1; xi < x.size(); ++xi)
    for(int yi = 1; yi < y.size(); ++yi)
	  for(int xj = xi; xj < x.size()-1; ++xj)
    for(int yj = yi; yj < y.size()-1; ++yj)
    {
		  int x0 = x[xi], y0 = y[yi], x1 = x[xj], y1 = y[yj];
		  long long mask = 0;
  		
		  if(isNSquare(nlow, nhigh, x1-x0, y1-y0, x[xj+1] - x[xi-1], y[yj+1] - y[yi-1]))
      {
			  for(int k = 0; k<px.size(); ++k)
				  if(isinrect(x0, y0, x1, y1, px[k], py[k]))
					  mask |= (1LL<<k);
  			
			 ss.insert(mask);
		  }
	  }
	  ss.erase(0);
	  return ss.sz;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	RangeSquaredSubsets ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
