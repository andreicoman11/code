// BEGIN CUT HERE
// PROBLEM STATEMENT
// One day, Fox Ciel got surprised because there were many 
// mosquitoes in her garden.
// She decided to kill as many mosquitoes as possible by 
// detonating a single bomb at a suitable place and time.
// 
// 
// 
// Ciel's garden can be seen as an infinitely long straight 
// line. Mosquitoes are points, each moving with some 
// constant velocity.
// You are given vector <int>s xInit and v of equal length N. 
// For each i between 0 and N-1, inclusive, there is a 
// mosquito with current position xInit[i] and constant 
// velocity v[i].
// 
// 
// 
// The current positions all correspond to a moment at time 
// t=0. A mosquito that starts at the position X and has 
// velocity V will be at the position X+Vt at time t. For 
// example, a mosquito with velocity 0 stays at the same 
// position forever, and two mosquitoes with velocities -1 
// and 1 are flying in opposite directions.
// 
// 
// 
// You are also given an int R: the radius of Ciel's bomb.
// If a bomb is detonated at the position x at time t, it 
// kills all mosquitoes that are at positions between x-R and 
// x+R, inclusive, at that time.
// The position of the bomb and the time of detonation do not 
// have to be integers.
// Ciel can detonate the bomb at any nonnegative time t 
// (including t=0).
// Your method must return the maximum number of mosquitoes 
// she can kill by a single detonation.
// 
// DEFINITION
// Class:Mosquitoes
// Method:getMaximum
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int getMaximum(vector <int> xInit, vector 
// <int> v, int R)
// 
// 
// CONSTRAINTS
// -xInit will contain between 1 and 50 elements, inclusive.
// -xInit and v will contain the same number of elements.
// -Each element of xInit will be between -100 and 100, 
// inclusive.
// -Each element of v will be between -100 and 100, inclusive.
// -All elements in v will be pairwise distinct.
// -R will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, -1}
// {1, -1}
// 10
// 
// Returns: 2
// 
// There are many ways how to kill both mosquitoes. For 
// example, she can detonate the bomb at time t=0 at position 
// 0.
// 
// 1)
// {100, -100}
// {1, -1}
// 10
// 
// Returns: 1
// 
// In this case, Ciel can only kill one mosquito.
// Note that the two mosquitoes are flying away from each 
// other.
// 
// 2)
// {0, -1, 10, -11, 99, -99}
// {1, -1, -3, 3, 47, -47}
// 3
// 
// Returns: 4
// 
// In this case, an optimal solution is to detonate the bomb 
// at position -0.5 at the time t=2.5.
// Mosquitoes 0, 1, 2, and 3 will be killed by the bomb.
// 
// 3)
// {5}
// {2}
// 8
// 
// Returns: 1
// 
// 
// 
// 4)
// {12,34,56,78,90}
// {-1,2,-3,4,-5}
// 6
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

class Mosquitoes {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 2; verify_case(0, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, -100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 1; verify_case(1, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, -1, 10, -11, 99, -99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1, -3, 3, 47, -47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 1; verify_case(3, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {12,34,56,78,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,-3,4,-5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(4, Arg3, getMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: int getMaximum(vector <int> x, vector <int> v, int R) {
		int n = v.size();
      int maxk = 0;

      for(int k=0; k<n; k++)
      {
         int maxk2 = 0;
         for(int l=0; l<n; l++)
            if( x[k]<=x[l] && 2*R + x[k] >= x[l])
               maxk2++;
         maxk = max(maxk, maxk2);
      }
      
      for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
         if( i!=j )
         {
            int ta = x[i] - x[j];
            int tb = v[j] - v[i];
            if( ta*tb<0 ) continue;

            for(int k=0; k<n; k++)
            {
               int maxk2 = 0;
               for(int l=0; l<n; l++)
                  if( tb*2*R + tb*x[k] + ta*v[k] >= tb*x[l] + ta*v[l] &&
                     tb*x[k] + ta*v[k] <= x[l]*tb + v[l]*ta) 
                     maxk2++;
               maxk = max(maxk, maxk2);
            }
         }

      return maxk;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	Mosquitoes ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
