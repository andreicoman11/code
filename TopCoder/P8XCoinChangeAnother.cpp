// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Exponential kingdom has N types of coins. For each i 
// from 0 to N-1, inclusive, there is a coin type worth 2^i 
// (two to the power of i). For example, if N=3  then the 
// coin values would be 2^0, 2^1, and 2^2.
// 
// You are given the int N and two long longs coins_sum and 
// coins_count. Your task is to find a set of coins with two 
// properties: First, it must contain exactly coins_count 
// coins. Second, the sum of coins it contains must be 
// exactly equal to coins_sum. Your method must return the 
// solution as a vector<long long> containing exactly N 
// elements. The i-th element of the return value must be the 
// number of coins worth 2^i in your set. If there are 
// multiple solutions, return the lexicographically smallest 
// one. If there is no set that satisfies both properties, 
// return an empty vector<long long> instead.
// 
// DEFINITION
// Class:P8XCoinChangeAnother
// Method:solve
// Parameters:int, long long, long long
// Returns:vector<long long>
// Method signature:vector<long long> solve(int N, long long 
// coins_sum, long long coins_count)
// 
// 
// NOTES
// -Given two different vector<long long>s A and B of equal 
// length, let i be the smallest index such that A[i] and B
// [i] differ. If A[i] &lt B[i], we say that A is 
// lexicographically smaller than B, and vice versa.
// 
// 
// CONSTRAINTS
// -N will be between 1 and 60, inclusive.
// -coins_sum and coins_count will each be between 1 and 
// 10^18, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 4
// 3
// 
// Returns: {2, 1 }
// 
// We have N=2, which means that we can use coins worth 2^0 
// and coins worth 2^1. We are looking for a set of 3 coins 
// worth 4 in total. There is a unique solution: use 2 coins 
// worth 2^0 and 1 coin worth 2^1.
// 
// 1)
// 3
// 6
// 3
// 
// Returns: {0, 3, 0 }
// 
// We have N=3, which means that we can use coins worth 2^0, 
// 2^1, and 2^2. We are looking for a set of 3 coins worth 6 
// in total. There are two possible solutions: 2 coins of 
// type 0 and 1 coin of type 2, or 3 coins of type 1. Since 
// the latter is lexicographically smaller than the former, 
// your method should return the latter.
// 
// 2)
// 2
// 8
// 1
// 
// Returns: { }
// 
// 
// 
// 3)
// 1
// 10000000000
// 10000000000
// 
// Returns: {10000000000 }
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
class P8XCoinChangeAnother {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; long long Arg2 = 3LL; long Arr3[] = {2, 1 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 6LL; long long Arg2 = 3LL; long Arr3[] = {0, 3, 0 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; long long Arg1 = 8LL; long long Arg2 = 1LL; long Arr3[] = {0 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; long long Arg1 = 10000000000LL; long long Arg2 = 10000000000LL; long long Arr3[] = {10000000000 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: vector<long long> solve(int n, long long sum, long long cnt) {
		vector<long long> res;
      if( cnt>sum ) return res;

      long long p = 1;
      for(int i=0; i<n; i++)
      {
         long long c = 0;
         if( sum&p ) ++c, sum-=p, --cnt;
         if( cnt<0 )
         {
            res.clear();
            return res;
         }
         if( i+1==n && sum )
         {
            if( cnt<sum/p )
            {
               res.clear();
               return res;
            }
            c += cnt;
            sum -= cnt * p;
            cnt = 0;
         }
         if( cnt > (sum/p)/2 )
         {
            long long c2 = sum/p - cnt;
            c += cnt - c2;
            sum -= (cnt-c2) * p;
            cnt -= cnt - c2;
         }

         res.push_back(c);
         p = p<<1LL;
      }

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	P8XCoinChangeAnother ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
