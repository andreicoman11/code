// BEGIN CUT HERE
// PROBLEM STATEMENT
// John has a sequence of digits.
// He and Brus will now play with the sequence.
// 
// 
// First, John will repeat the following operation k times:
// He will choose two different positions in the sequence, 
// and swap the elements at those positions.
// (John makes each choice uniformly at random.
// That is, each time John chooses two positions, each pair 
// of different positions has the same probability of being 
// chosen.)
// 
// 
// Afterwards, Brus will randomly choose a non-empty 
// contiguous subsequence of John's sequence.
// He will compute the sum of all elements in the chosen 
// subsequence and he will write it down on a piece of paper.
// (Brus also makes his choice uniformly at random.
// That is, each possible contiguous subsequence has the same 
// probability of being chosen.)
// 
// 
// You are given a vector <string> sequence.
// Concatenate all elements of sequence to get the string s.
// For each i, the i-th character of s is a digit ('0'-'9') 
// representing the digit at index i in John's original 
// sequence.
// 
// 
// Return the expected value of the sum Brus writes down.
// 
// DEFINITION
// Class:TheSwapsDivOne
// Method:find
// Parameters:vector <string>, int
// Returns:double
// Method signature:double find(vector <string> sequence, int 
// k)
// 
// 
// NOTES
// -The returned value must be accurate to within a relative 
// or absolute value of 1E-9.
// 
// 
// CONSTRAINTS
// -sequence will contain between 2 and 47 elements, inclusive.
// -Each element of sequence will contain between 1 and 47 
// characters, inclusive.
// -Each element of sequence will consist of only decimal 
// digits ('0'-'9').
// -k will be between 1 and 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"4", "77"}
// 1
// 
// Returns: 10.0
// 
// There are three equally likely swaps John might make.
// If the first two elements are swapped, John will get the 
// sequence {7,4,7}.
// Then Brus chooses one of the six possible subsequences.
// Their sums are 7, 4, 7, 11, 11 and 18.
// Thus the expected value is (7 + 4 + 7 + 11 + 11 + 18)/6 = 
// 29/3.
// 
// If the first and the last elements are swapped, the 
// sequence becomes {7,7,4}, and the subsequence sums are 7, 
// 7, 4, 14, 11 and 18.
// The expected value in this case is (7 + 7 + 4 + 14 + 11 + 
// 18)/6 = 61/6.
// 
// When the last two elements are swapped, the sequence 
// doesn't change and the expected value is equal to 61/6 as 
// well.
// Finally, the overall expected value is equal to (29/3 + 
// 61/6 + 61/6)/3 = 10.
// 
// 
// 1)
// {"4", "77"}
// 47
// 
// Returns: 10.0
// 
// 
// 
// 2)
// {"1", "1", "1", "1", "1", "1", "1"}
// 1000000
// 
// Returns: 3.0
// 
// 
// 
// 3)
// {"572685085149095989026478064633266980348504469", 
// "19720257361", "9", "69"}
// 7
// 
// Returns: 98.3238536775161
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

class TheSwapsDivOne {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 10.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; double Arg2 = 10.0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1", "1", "1", "1", "1", "1", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; double Arg2 = 3.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 98.3238536775161; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

	public: 
	double find(vector <string> sequence, int k) {
		string s = "";
      for(int i=0; i<sequence.size(); i++)
         s+=sequence[i];

      int n = s.size();
      double pSame;
      if( n==2 ) {
         if( k%2 )   pSame = 0.0;
         else        pSame = 1.0;
      } else {
         pSame = 1.0;
         const double pAffected = 2 / double(n);
         const double pPutBack = 2 / double(n) / double(n-1);
         for(int i=0; i<k; i++)
            pSame = pSame * (1.0 - pAffected) + (1.0 - pSame) * pPutBack;
      }

      double sum = 0.0;
      const double pSelected = 1.0 / double(n-1);
      for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) {
         double prob;
         if( i==j )
            prob = pSame;
         else
            prob = (1.0 - pSame) * pSelected;

         const int cur = s[i] - '0';
         const int sums_with_jth_pos = (j+1) * (n-j);
         const double cur_sum = prob * sums_with_jth_pos * cur;
         sum += cur_sum;
      }
      const int posSums = n * (n+1) / 2;
      return sum / (double)posSums;
	}
	
};

// BEGIN CUT HERE 
#include <iomanip>
int main()
{
	TheSwapsDivOne ___test; 
   cerr << fixed << setprecision(10);
	___test.run_test(-1); 
} 
// END CUT HERE
