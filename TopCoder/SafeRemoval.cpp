// BEGIN CUT HERE
// PROBLEM STATEMENT
// Did you know that platypuses can be very superstitious? A 
// certain platypus was on a mission to remove exactly k 
// numbers from a sequence in such a way that the sum of the 
// remaining numbers is as large as possible. This task would 
// have been very simple, were it not the case that our 
// platypus wants to avoid some unlucky situations.
// 
// More precisely, our platypus thinks that the number 4 is 
// unlucky, and so are all its multiples.
// Fortunately, the sum of the original sequence of numbers 
// is not a multiple of 4. The platypus wants to keep it that 
// way. It will only consider removing a number from the 
// sequence if after the removal the sum of the remaining 
// elements is not a multiple of 4. We will call such a 
// removal safe.
// 
// You are given vector <int> seq and int k. If it is 
// possible to perform exactly k safe removals (one element 
// at a time), return the maximum possible sum of the 
// elements remaining after the k removals. In case it is not 
// possible to perform k safe removals, return -1.
// 
// DEFINITION
// Class:SafeRemoval
// Method:removeThem
// Parameters:vector <int>, int
// Returns:int
// Method signature:int removeThem(vector <int> seq, int k)
// 
// 
// CONSTRAINTS
// -seq will contain between 2 and 50 elements, inclusive.
// -Each element of seq will be between 1 and 1000, inclusive.
// -k will be at least 1. 
// -k will be less than the number of elements in seq.
// -The sum of all elements of seq will not be a multiple of 4.
// 
// 
// EXAMPLES
// 
// 0)
// {3, 8, 4}
// 1
// 
// Returns: 11
// 
// The best move for the platypus is to remove 4.
// The platypus cannot remove 3, because the remaining 
// elements would add up to 4+8 = 12, a multiple of 4.
// Removing 8 is safe, but the total sum of the remaining 
// elements, 3+4=7 is smaller than 11.
// 
// 1)
// {1,1,1,1,1,1}
// 3
// 
// Returns: -1
// 
// The initial sum is 6. After removing any of the elements, 
// the sum becomes 5. At that point it becomes impossible to 
// remove any of the remaining elements without making the 
// sum a multiple of 4.
// 
// 2)
// {1,6,1,10,1,2,7,11}
// 6
// 
// Returns: 21
// 
// 
// 
// 3)
// {1,1,1,1,1,1,1,1,7}
// 3
// 
// Returns: 6
// 
// One of the three removed elements has to be the 7. The 
// platypus has to remove the elements either in the order 
// 1,7,1, or in the order 1,1,7.
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

int f[50][50][50][50];

class SafeRemoval {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 11; verify_case(0, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(1, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,6,1,10,1,2,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 21; verify_case(2, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(3, Arg2, removeThem(Arg0, Arg1)); }

// END CUT HERE

	public: 
	int removeThem(vector <int> seq, int k) {
		vector<vector<int> > v(4);
      int sum = 0;
      for(int i=0; i<seq.size(); i++) {
         sum += seq[i];
         v[seq[i]%4].push_back(seq[i]);
      }

      for(int i=0; i<4; i++)
         sort(v[i].begin(), v[i].end());

      int res = -1;
      
      memset(f, 0, sizeof(f));
      f[0][0][0][0] = sum;
      for(int i0=0; i0<=v[0].size(); i0++)
      for(int i1=0; i1<=v[1].size(); i1++)
      for(int i2=0; i2<=v[2].size(); i2++)
      for(int i3=0; i3<=v[3].size(); i3++)
         if( f[i0][i1][i2][i3] && i0+i1+i2+i3<k ) {
            if( i0+1<=v[0].size() && (f[i0][i1][i2][i3] - v[0][i0])%4 )   f[i0+1][i1][i2][i3] = f[i0][i1][i2][i3] - v[0][i0];
            if( i1+1<=v[1].size() && (f[i0][i1][i2][i3] - v[1][i1])%4 )   f[i0][i1+1][i2][i3] = f[i0][i1][i2][i3] - v[1][i1];
            if( i2+1<=v[2].size() && (f[i0][i1][i2][i3] - v[2][i2])%4 )   f[i0][i1][i2+1][i3] = f[i0][i1][i2][i3] - v[2][i2];
            if( i3+1<=v[3].size() && (f[i0][i1][i2][i3] - v[3][i3])%4 )   f[i0][i1][i2][i3+1] = f[i0][i1][i2][i3] - v[3][i3];
         }
         else if( f[i0][i1][i2][i3] && i0+i1+i2+i3==k ) {
            res = max(res, f[i0][i1][i2][i3]);
         }
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	SafeRemoval ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
