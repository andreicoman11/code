// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have a set of cards.
// There is one non-negative integer on each card.
// Different cards may contain the same integer.
// For each i, the number written on the i-th card (0-based 
// index) is number[i].
// Your friend wants to select a subset of those cards such 
// that the bitwise xor of the selected cards is less than or 
// equal to limit.
// 
// 
// 
// You are given the vector<long long> number and the long 
// long limit.
// Count the number of ways in which your friend can select 
// the subset of cards.
// Two subsets count as different if they differ as sets of 
// cards (even if the corresponding sets of numbers are the 
// same, see Example 4).
// 
// DEFINITION
// Class:XorCards
// Method:numberOfWays
// Parameters:vector<long long>, long long
// Returns:long long
// Method signature:long long numberOfWays(vector<long long> 
// number, long long limit)
// 
// 
// NOTES
// -XOR (exclusive or) is a binary operation, performed on 
// two numbers in binary notation. First, the shorter number 
// is prepended with leading zeroes until both numbers have 
// the same number of digits (in binary). Then, the result is 
// calculated as follows: for each bit where the numbers 
// differ the result has 1 in its binary representation. It 
// has 0 in all other positions.
// -For example 42 XOR 7 is performed as follows. First, the 
// numbers are converted to binary: 42 is 101010 and 7 is 
// 111. Then the shorter number is prepended with leading 
// zeros until both numbers have the same number of digits. 
// This means 7 becomes 000111. Then 101010 XOR 000111 = 
// 101101 (the result has ones only in the positions where 
// the two numbers differ). Then the result can be converted 
// back to decimal notation. In this case 101101 = 45, so 42 
// XOR 7 = 45.
// -If your friend decides to select zero cards, the bitwise 
// xor of numbers on selected cards is zero.
// -If your friend decides to select a single card, the 
// bitwise xor of numbers on selected cards is the number on 
// the selected card.
// 
// 
// CONSTRAINTS
// -number will contain between 1 and 50 elements, inclusive.
// -Each element in number will be between 0 and 
// 1,000,000,000,000,000 (10^15), inclusive.
// -limit will be between 0 and 1,000,000,000,000,000 
// (10^15), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,2}
// 2
// 
// Returns: 3
// 
// This set of cards has four possible subsets.
// Here they are, along with the corresponding bitwise xors:
// {} => 0, {1} => 1, {2} => 2, and {1,2} => 3.
// Note that limit=2.
// Out of these four subsets, for the first three the bitwise 
// xor of selected numbers is at most equal to limit.
// 
// 1)
// {5,5}
// 3
// 
// Returns: 2
// 
// The two good subsets are {} and {5,5}.
// 
// 2)
// {1,2,3,4,5,6,7}
// 5
// 
// Returns: 96
// 
// 
// 
// 3)
// {123, 456, 789, 147, 258, 369, 159, 357}
// 500
// 
// Returns: 125
// 
// 
// 
// 4)
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

// 1000000000000000
// 
// Returns: 4294967296
// 
// 
// 
// 5)
// {1000000000000000, 999999999999999}
// 65535
// 
// Returns: 2
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

class XorCards {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arr0[] = {1,2}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; long long Arg2 = 3LL; verify_case(0, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_1() { long long Arr0[] = {5,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; long long Arg2 = 2LL; verify_case(1, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_2() { long long Arr0[] = {1,2,3,4,5,6,7}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; long long Arg2 = 96LL; verify_case(2, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_3() { long long Arr0[] = {123, 456, 789, 147, 258, 369, 159, 357}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 500LL; long long Arg2 = 125LL; verify_case(3, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_4() { long long Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000000LL; long long Arg2 = 4294967296LL; verify_case(4, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_5() { long long Arr0[] = {1000000000000000LL, 999999999999999LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 65535LL; long long Arg2 = 2LL; verify_case(5, Arg2, numberOfWays(Arg0, Arg1)); }

// END CUT HERE
   int getd(long long a) {
      int d = 0;
      while (a) {
         d++;
         a >>= 1;
      }
      return d;
   }

   int rank(vector<vector<int> > a, vector<int> b, int N, int M, int mod) {
      /*for(int i=0; i<M; i++) {
         for(int j=0; j<N; j++)
            cout << a[i][j] << " ";
         cout << "= " << b[i] << endl;
      }*/

      int ans = 0;
      vector<bool> used(M);
      for (int j=0; j<N; j++) {
         for (int i=0; i<M; i++) {
            if (a[i][j] && !used[i]) {
               ans++; // found a row with a non-0 value
               used[i] = true; // do not use this column any longer
               for (int i2 = 0; i2<M; i2++) 
                  if (!used[i2]) {
                     // subtract row i from i2
                     int mul = 0;
                     // find value such that a[i2][j] - a[i][j]*mul = 0, modulo mod
                     while ((mul * a[i][j] + a[i2][j]) % mod != 0) mul++;
                     for (int j2 = 0; j2<N; j2++) {
                        a[i2][j2] = (a[i2][j2] + mul * a[i][j2]) % mod;
                     }
                     b[i2] = (b[i2] + mul * b[i]) % mod;
                  }
            }
         }
      }
      for (int i=0; i<M; i++)
         if (!used[i] && b[i] != 0)
            return -1;

      return ans;
   }

   long long numberOfFixWays(vector<long long> cards, long long x) {
      int bits = getd(x);
      for (int i=0; i<cards.size(); i++)
         bits = max(bits, getd(cards[i]));

      vector<vector<int> > a(bits);
      vector<int> b(bits);
      long long p = 1LL;
      for (int i=0; i<bits; i++){
         a[i] = vector<int>(cards.size());
         for(int j=0; j<cards.size(); j++)
            if ((cards[j] & p) != 0) a[i][j] = 1;
         if (x&p) b[i] = 1;
         p <<= 1;
      }
      int r = rank(a, b, cards.size(), bits, 2);
      return (r == -1 ? 0LL : 1LL << (cards.size() - r));
   }

	public: 
	long long numberOfWays(vector<long long> cards, long long x) {
      // the case where == x
      long long res = numberOfFixWays(cards, x);
      //cout << endl << "\t\t" << res << endl;

      // the case of < x
		while (x) {
         if ((x & 1) == 1 ) {
            res += numberOfFixWays(cards, x-1);
            //cout << endl << "\t\t" << x-1 << " " << numberOfFixWays(cards, x-1) << endl;
         }

         x >>= 1;
         for (int i=0; i<cards.size(); i++) {
            cards[i] >>= 1;
         }
      }

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	XorCards ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
