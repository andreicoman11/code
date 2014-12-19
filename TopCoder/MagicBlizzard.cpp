// BEGIN CUT HERE
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world 
// celebrate this 
// holiday. The following story takes place in the land of 
// reindeer, where Santa Claus resides.
// 
// 
// 
// For Christmas, the land should be covered by snow, but 
// there was no snowfall yet. Luckily, the reindeer know a 
// spell called Magic Blizzard that can make it snow.
// 
// 
// 
// The land can be imagined as an infinite grid of unit 
// squares with integer coordinates. When a reindeer casts 
// Magic Blizzard, the effect depends on two parameters: the 
// range of the spell R and the amount A. The spell will 
// generate A snowballs. Each snowball will fall on some 
// square with coordinates (x,y) such that -R <= x, y <= R. 
// For each snowball, the target square is chosen uniformly 
// at random. Targets for snowballs are chosen independently 
// of each other. (Hence it is possible that multiple 
// snowballs will hit the same square.)
// 
// 
// 
// N reindeer are going to cast Magic Blizzard, one after 
// another. You are given two vector <int>s range and amount 
// of length N. The spell by reindeer i will have range equal 
// to range[i] and the amount of snowballs it produces will 
// be amount[i].
// 
// 
// 
// The beauty of the landscape can be computed as the total 
// beauty of all squares. The beauty of a square that was hit 
// by x snowballs is x^2.
// 
// 
// 
// Your method must compute and return the expected value of 
// the beauty of the landscape.
// 
// DEFINITION
// Class:MagicBlizzard
// Method:expectation
// Parameters:vector <int>, vector <int>
// Returns:double
// Method signature:double expectation(vector <int> range, 
// vector <int> amount)
// 
// 
// NOTES
// -The returned value must be accurate to within a relative 
// or absolute error of 1e-9.
// 
// 
// CONSTRAINTS
// -range will contain between 1 and 50 elements, inclusive.
// -amount will contain between 1 and 50 elements, inclusive.
// -range and amount will contain the same number of elements.
// -Each element in range will be between 0 and 10,000, 
// inclusive.
// -Each element in amount will be between 1 and 10,000, 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,0}
// {1,1}
// 
// Returns: 2.2222222222222223
// 
// The second snowball will surely fall on the square (0,0). 
// The first snowball will fall on the same square with 
// probability 1/9. If that happens, the beauty of the 
// landscape will be 2^2 = 4. Otherwise, we will have two 
// squares containing one snowball each, for a total beauty 
// of 1^2 + 1^2 = 2. So the expected beauty is (1/9) * 4 + 
// (8/9) * 2 = 20/9.
// 
// 1)
// {1,0}
// {2,1}
// 
// Returns: 3.666666666666667
// 
// 
// 
// 2)
// {5,2,6,5}
// {1,2,2,3}
// 
// Returns: 8.46525111252384
// 
// 
// 
// 3)
// {7,11,2,13,3,19,5,17}
// {16,8,4,15,12,9,10,6}
// 
// Returns: 98.55659436211914
// 
// 
// 
// 4)
// {0,0,0,0,0,0,0,0,0,0}
// {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}

// 
// Returns: 1.0E10
// 
// Note that the answer can be very large.
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
class MagicBlizzard {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.2222222222222223; verify_case(0, Arg2, expectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.666666666666667; verify_case(1, Arg2, expectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,2,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.46525111252384; verify_case(2, Arg2, expectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7,11,2,13,3,19,5,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16,8,4,15,12,9,10,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 98.55659436211914; verify_case(3, Arg2, expectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0E10; verify_case(4, Arg2, expectation(Arg0, Arg1)); }

// END CUT HERE

	public: 
   double expectation(vector <int> range, vector <int> amount) {
      double res = 0.0;
      LL snow = 0;
      for(int i=0; i<range.size(); i++)
      {
         for(int j=i; j<range.size(); j++)
            if( range[i]>range[j] )
            {
               swap(range[i], range[j]);
               swap(amount[i], amount[j]);
            }

         for(int k=0; k<amount[i]; k++)
            res += 1.0 + 2.0 * double(snow++) / double((2*range[i]+1)*(2*range[i]+1));
      }
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MagicBlizzard ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
