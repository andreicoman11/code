// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Jiro is interested in sequences of intetegers. Today 
// he considers the sequence given to you as the vector <int> 
// first. Let K be the number of elements of first. Jiro 
// chooses some permutation of first. Let's call this 
// permutation F. An infinite sequence of integers A is 
// defined as follows:
// 
// for all i, 0 <= i < K, A[i] = F[i].
// Otherwise, A[i] = A[i-K] - A[i-K+1] + ... + (-1)^(K-1) * A
// [i-1].
// 
// In addition to first, Jiro has a int N.
// His goal is to maximize the value of A[N].
// Return a vector <int> containing the best choice of F.
// If there are multiple permutations of first maximizing the 
// value of A[N], return the lexicographically smallest one.
// 
// DEFINITION
// Class:FoxPlusMinus
// Method:maximize
// Parameters:vector <int>, int
// Returns:vector <int>
// Method signature:vector <int> maximize(vector <int> first, 
// int N)
// 
// 
// NOTES
// -A vector <int> A is lexicographically smaller than a 
// vector <int> B if A contains a smaller number at the first 
// index where they differ.
// 
// 
// CONSTRAINTS
// -first will contain between 1 and 50 elements, inclusive.
// -Each element of first will be between -1,000,000,000 and 
// 1,000,000,000, inclusive.
// -N will be between 0 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 2}
// 2
// 
// Returns: {2, 1 }
// 
// A[2] will be 1 if F = {2, 1}, and it will be -1 if F = {1, 
// 2}.
// 
// 1)
// {1, 2, 3}
// 3
// 
// Returns: {2, 1, 3 }
// 
// {3, 1, 2} also maximizes A[3] but {2, 1, 3} is 
// lexicographically smaller.
// 
// 2)
// {-3, 1, -4, 1, -5, 9, -2}
// 10
// 
// Returns: {-5, -4, 9, -3, -2, 1, 1 }
// 
// 
// 
// 3)
// {2, 7, -1, 8, -2, -8}
// 10
// 
// Returns: {2, -1, 7, -2, 8, -8 }
// 
// 
// 
// 4)
// {-10, -20, -30}
// 1
// 
// Returns: {-30, -10, -20 }
// 
// 
// 
// 5)
// {1, 2, 4, 9, 7, 3}
// 13
// 
// Returns: {3, 4, 2, 7, 1, 9 }
// 
// 
// 
// 6)
// {-4112039, 51143992, 941422315, -153492958, 499218832, 
// 543599293, 132059490, -434243951,
//  -95819234, 1552938, -857192847, 481950390, 401099286, 
// 71482395, -711450593, 8101919}
// 884142312
// 
// Returns: {51143992, 8101919, 71482395, 1552938, 132059490, 
// -4112039, 401099286, -95819234, 481950390, -153492958, 
// 499218832, -434243951, 543599293, -711450593, 941422315, 
// -857192847 }
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

class FoxPlusMinus {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, maximize(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {2, 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, maximize(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-3, 1, -4, 1, -5, 9, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {-5, -4, 9, -3, -2, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, maximize(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 7, -1, 8, -2, -8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {2, -1, 7, -2, 8, -8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, maximize(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-10, -20, -30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {-30, -10, -20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, maximize(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1, 2, 4, 9, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arr2[] = {3, 4, 2, 7, 1, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, maximize(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {-4112039, 51143992, 941422315, -153492958, 499218832, 543599293, 132059490, -434243951,
 -95819234, 1552938, -857192847, 481950390, 401099286, 71482395, -711450593, 8101919}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 884142312; int Arr2[] = {51143992, 8101919, 71482395, 1552938, 132059490, -4112039, 401099286, -95819234, 481950390, -153492958, 499218832, -434243951, 543599293, -711450593, 941422315, -857192847 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, maximize(Arg0, Arg1)); }

// END CUT HERE

	public: 
	vector <int> maximize(vector <int> f, int N) {
		int k = f.size();
      if( k==1 ) return f;
      sort(f.begin(), f.end());

      if( N<k ) {
         int fmax = f[k-1];
         for(int i=k-1; i>N; i--)
            f[i] = f[i-1];
         f[N] = fmax;
         return f;
      }

      if( k%2==1 ) 
      {
         N = N % (k+1);
         if( N<k ) 
         {
            int fmax = f[k-1];
            for(int i=k-1; i>N; i--)
               f[i] = f[i-1];
            f[N] = fmax;
            return f;
         } else {
            vector<int> res(k);
            for(int i=0; i<k/2; i++)
               res[i*2+1] = f[i];
            for(int i=0; i<k/2+1; i++)
               res[i*2] = f[i+k/2];
            return res;
         }
      }

      vector<int> res(k);
      vector<int> c(k);

      if( N < 2*k )
      {
         for(int i=0; i<k; i++)
            c[i] = (i%2==0 ? 1 : -1);
         for(int i=k+1; i<=N; i++)
         {
            for(int j=0; j<k; j++)
               c[j] *= -2;
            c[i-k-1]++;
         }
      }
      else
      {
         for(int i=0; i<k; i++)
            c[i] = ((i%2==N%2) ? (i+1) : (-i-1));
      }

      for(int i=0; i<k; i++)
      {
         int pos = -1;
         for(int j=0; j<k; j++)
            if( (pos==-1 && c[j]!=0 ) || (pos>=0 && c[j]!=0 && c[j]<c[pos] ) )
               pos = j;
         res[pos] = f[i];
         c[pos] = 0;
      }

      return res;
	}
	
};


// BEGIN CUT HERE 
int main()
{
	FoxPlusMinus ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE