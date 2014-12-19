// BEGIN CUT HERE
// PROBLEM STATEMENT
// Elly has a set of unique positive integers, given in the 
// vector <int> numbers. She wants to add several (possibly 
// none) new positive integers to this set, such that when 
// the set is sorted no two consecutive numbers will share a 
// positive divisor greater than 1. Return the smallest 
// possible count of new numbers, with which she can achieve 
// that.
// 
// DEFINITION
// Class:EllysCoprimesDiv2
// Method:getCount
// Parameters:vector <int>
// Returns:int
// Method signature:int getCount(vector <int> numbers)
// 
// 
// CONSTRAINTS
// -numbers will contain between 1 and 50 elements, inclusive.
// -Each element of numbers will be between 1 and 100,000, 
// inclusive.
// -All elements of numbers will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {2200, 42, 2184, 17}
// 
// Returns: 3
// 
// Here one possible set of additional numbers is {43, 2195, 
// 2199}.
// The sorted sequence is (17, 42, 43, 2184, 2195, 2199, 
// 2200), and as you may see, no two consecutive numbers 
// share a divisor greater than one.
// 
// 1)
// {13, 1, 6, 20, 33}
// 
// Returns: 0
// 
// For some sets, such as this one, no additional numbers are 
// needed. When sorted, no pair of consecutive numbers shares 
// a common divisor greater than 1.
// 
// 2)
// {7, 42}
// 
// Returns: 1
// 
// Note that prime numbers are not coprime with all other 
// numbers.
// 
// 3)
// {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 
// 24124, 91858, 7856,
//  12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 
// 8421, 97984, 34586,
//  893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 
// 80845, 67079, 14829,
//  25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 
// 64263, 1337, 42666}
// 
// Returns: 15
// 
// Large random set of numbers.
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

class EllysCoprimesDiv2 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2200, 42, 2184, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arr0[] = {13, 1, 6, 20, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arr0[] = {7, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arr0[] = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, getCount(Arg0)); }

// END CUT HERE

	public: 
   int gcd(int x, int y) {
      return (y==0 ? x : gcd(y, x%y));
   }
	int getCount(vector <int> v) {
      sort(v.begin(), v.end());
      int x[100010];
      memset(x, 0, sizeof(x));
      int res = 0;
		for(int i=0; i+1<v.size(); i++) {
         int a = v[i], b = v[i+1], cul = 1, t = 0;
         x[a] = 0;
         vector<int> q[2];
         q[0].push_back(a);
         while( x[b]==0 ) {
            t = 1 - t;
            for(int j=a+1; j<=b; j++) {
               bool found = 0;
               for(int k=0; !found && k<q[1-t].size(); k++)
                  if( gcd(j, q[1-t][k])==1 ) {
                     q[t].push_back(j);
                     x[j] = cul;
                     found = 1;
                  }
            }
            cul++;
         }
         res += x[b] - 1;
      }

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EllysCoprimesDiv2 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
