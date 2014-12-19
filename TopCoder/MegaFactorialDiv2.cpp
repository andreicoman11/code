// BEGIN CUT HERE
// PROBLEM STATEMENT
// The factorial of the k-th order of a number n is denoted n!
// k and defined by the following recurrences:
// 1) n!k = n!(k-1) * (n-1)!k for n > 0 and k > 0
// 2) n!k = 1 for n = 0
// 3) n!k = n for k = 0
// 
// For example, 7!1 = 7! (the traditional factorial), and 5!3 
// = 5!2 * 4!3 = (5!1 * 4!2) * 4!3.
// 
// You are given ints N and K. Compute the number of distinct 
// divisors of the number N!K. Return the computed number 
// modulo 1,000,000,009.
// 
// 
// DEFINITION
// Class:MegaFactorialDiv2
// Method:countDivisors
// Parameters:int, int
// Returns:int
// Method signature:int countDivisors(int N, int K)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 1000, inclusive.
// -K will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 1
// 
// Returns: 4
// 
// 3!1 = 3! = 6. The divisors of 6 are 1, 2, 3 and 6.
// 
// 1)
// 3
// 2
// 
// Returns: 6
// 
// 3!2 = 3!1 * 2!2 = 3! * 2!1 * 1!2 = 3! * 2! * 1!1 * 0!2 = 
// 3! * 2! * 1! * 1 = 12. The divisors of 12 are 1, 2, 3, 4, 
// 6 and 12.
// 
// 2)
// 4
// 2
// 
// Returns: 18
// 
// 4!2 is equal to 288.
// 
// 3)
// 6
// 3
// 
// Returns: 1392
// 
// 
// 
// 4)
// 100
// 2
// 
// Returns: 321266186
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

const long long MOD = 1000000009LL;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()

int prim[1000];
map<int,int> divs[105];

class MegaFactorialDiv2 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 18; verify_case(2, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1392; verify_case(3, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 321266186; verify_case(4, Arg2, countDivisors(Arg0, Arg1)); }

// END CUT HERE

	public: 
	int countDivisors(int n, int k) {
      prim[0] = 2;
      prim[1] = 3;
      int pos = 2;
      for(int i=5; i<1000; i++)
      {
         bool isprim = 1;
         for(int j=0; isprim && j<pos; j++)
            if( i%prim[j]==0 ) isprim = 0;
         if( isprim ) prim[pos++] = i;
      }

      //n = 1000, k = 100;
      //for(int j=0; j<=k; j++)
      //   divs[j].clear();

      //int t = 1;      
      for(int i=2; i<=n; i++)
      {
         //t = 1-t;
         divs[1] = divs[1];
         int n2 = i;
         for(int ii=0; prim[ii] * prim[ii] <= n2; ii++)
            if( n2%prim[ii]==0 )
            {
               int cnt = 1;
               n2 /= prim[ii];
               while( n2>1 && n2%prim[ii]==0 ) {
                  cnt++;
                  n2 /= prim[ii];
               }
               divs[1][prim[ii]] += cnt;
               if( divs[1][prim[ii]]>=MOD )
                  divs[1][prim[ii]] -= MOD;
            }
         if( n2>1 ) divs[1][n2] += 1;

         for(int j=2; j<=k; j++)
         {
            divs[j] = divs[j];
            for(map<int,int>::iterator it=divs[j-1].begin(); it!=divs[j-1].end(); it++) {
               divs[j][it->first] += it->second;
               if( divs[j][it->first]>=MOD )
                  divs[j][it->first] -= MOD;
            }
         }
      }

      long long res = 1;
      for(map<int,int>::iterator it=divs[k].begin(); it!=divs[k].end(); it++)
         res = (res * (it->second+1) ) % MOD;
      
      return (int)res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	MegaFactorialDiv2 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
