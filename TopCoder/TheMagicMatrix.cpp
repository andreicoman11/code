// BEGIN CUT HERE
// PROBLEM STATEMENT
// A magic matrix is a square matrix filled with digits (0 to 
// 9) such that its row sums and column sums all have the 
// same last digit.
// John has n by n matrix.
// Its rows and columns are numbered from 0 to n-1.
// Some cells of the matrix already contain digits and some 
// are empty.
// John wants to assign a value to each empty cell to get a 
// magic matrix.
// 
// 
// You are given an int n and vector <int>s rows, columns, 
// values.
// The number values[i] is the digit in John's matrix at row 
// rows[i] and at column columns[i].
// Return the number of different matrices John can get 
// modulo 1,234,567,891.
// 
// 
// DEFINITION
// Class:TheMagicMatrix
// Method:find
// Parameters:int, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int find(int n, vector <int> rows, vector 
// <int> columns, vector <int> values)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 1000, inclusive.
// -rows will contain between 1 and 10 elements, inclusive.
// -rows, columns and values will all contains the same 
// number of elements.
// -Each element of rows will be between 0 and n-1, inclusive.
// -Each element of columns will be between 0 and n-1, 
// inclusive.
// -Each element of values will be between 0 and 9, inclusive.
// -All pairs (rows[i], columns[i]) will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// {0, 1}
// {1, 0}
// {4, 4}
// 
// Returns: 10
// 
// John will get a magic matrix only if he assigns equal 
// values to both empty cells. 
// 
// 
// 1)
// 2
// {0, 1}
// {1, 0}
// {4, 7}
// 
// Returns: 0
// 
// 
// 
// 2)
// 4
// {0, 0, 0, 1, 2, 2, 2, 3, 3, 3}
// {0, 1, 2, 3, 0, 1, 2, 0, 1, 2}
// {3, 5, 1, 9, 5, 1, 8, 6, 7, 1}
// 
// Returns: 2
// 
// 
// 
// 3)
// 474
// {44, 77}
// {47, 74}
// {4, 7}
// 
// Returns: 83494518
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

long long MOD = 1234567891LL;
int b[16][16];
vector <int> r;
vector <int> c;
vector <int> v;

class TheMagicMatrix {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 0, 1, 2, 0, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 5, 1, 9, 5, 1, 8, 6, 7, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 474; int Arr1[] = {44, 77}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {47, 74}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 83494518; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
   long long pown(long long a, long long b) {
      long long res = 1LL;
      while (b) {
         if ((b & 1) == 1) {
            res = (res * a) % MOD;
         }
         a = (a * a) % MOD;
         b >>= 1;
      }
      return res;
   }

   int rank(vector<vector<int> > a, vector<int> b, int N, int M, int mod) {
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

   long long solve(int n, int mod) {
      // N variables, M equations
      int N = n * n;
      int M = 2 * n - 1 + v.size();
      
      vector<vector<int> > a(M);
      vector<int> b(M);
      M = 0;

      // create the equations of the type aij = v, by creating 
      // 0 * a11 + ... + 1 * aij + .. + 0 * ann = v;
      for (int i=0; i<v.size(); i++) {
         a[M] = vector<int>(N, 0);
         a[M][r[i] * n + c[i]] = 1;
         b[M] = v[i] % mod;
         M++;
      }

      // create the equations for equalities between rows, by subtracting:
      // a11 + .. + a1n - ai1 - ai2 - .. ain = 0
      for(int i=1; i<n; i++) {
         a[M] = vector<int>(N, 0);
         for(int j=0; j<n; j++) {
            a[M][j] = 1;
            a[M][i*n + j] = mod - 1; // -1 * k = (p-1) * k, where p is prime, in mod p
         }
         M++;
      }

      // create the equations for equalities between row0 and all cols, by subtracting:
      // a11 + .. + a1n - a1i - a2i - .. - ani = 0
      for(int i=0; i<n; i++) {
         a[M] = vector<int>(n*n, 0);
         // we will have intersections between row/col, so split them up
         for(int j=0; j<n; j++) {
            a[M][j] = 1;
         }
         for(int j=0; j<n; j++) {
            a[M][j*n + i] = (a[M][j*n + i] + mod - 1) % mod; // -1 * k = (p-1) * k, where p is prime, in mod p
         }
         M++;
      }

      int r = rank(a, b, N, M, mod);
      return (r == -1 ? 0L : pown(mod, N - r));
   }

	public: 
	int find(int n, vector <int> r_, vector <int> c_, vector <int> v_) {
      r = r_;
      c = c_;
      v = v_;
		if (n >= 11) {
         return (int)(pown(10, (n-1)*(n-1) - v.size() + 1));
      }

      memset(b, -1, sizeof(b));
      for (int i=0; i<v.size(); i++) {
         b[r[i]][c[i]] = v[i] % 2;
      }
      long long res2 = solve(n, 2);

      memset(b, -1, sizeof(b));
      for (int i=0; i<v.size(); i++) {
         b[r[i]][c[i]] = v[i] % 5;
      }
      long long res5 = solve(n, 5);
      return (int) ((res2 * res5) % MOD);
	}
};

// BEGIN CUT HERE 
int main()
{
	TheMagicMatrix ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
