// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given ints n and m: the dimensions of a matrix.
// A matrix M with n rows and m columns is called a mountain 
// if it satisfies the following conditions:
// 
// All elements of M are positive integers.
// There are integers a and b with the following properties:
//   
//   0 <= a <= n-1 and 0 <= b <= m-1.
//   For each row i, M[i][0] < M[i][1] < ... < M[i][b-1] < M
// [i][b] > M[i][b+1] > ... > M[i][m-1].
//   For each column j, M[0][j] < M[1][j] < ... < M[a-1][j] < 
// M[a][j] > M[a+1][j] > ... > M[n-1][j].
//   
// 
// 
// 
// In addition to n and m, you are given some elements of M.
// More precisely, you are given the vector <int>s rowIndex, 
// columnIndex and element.
// For each valid k, M[rowIndex[k]][columnIndex[k]] has to be 
// element[k].
// 
// Your task is to fill in the missing values so that M 
// becomes a mountain.
// Find and return the smallest possible sum of all elements 
// in a mountain M that matches the given constraints.
// If there is no mountain that matches the given 
// constraints, return -1 instead.
// 
// DEFINITION
// Class:TheMountain
// Method:minSum
// Parameters:int, int, vector <int>, vector <int>, vector 
// <int>
// Returns:int
// Method signature:int minSum(int n, int m, vector <int> 
// rowIndex, vector <int> columnIndex, vector <int> element)
// 
// 
// CONSTRAINTS
// -n and m will each be between 1 and 200, inclusive.
// -rowIndex will contain between 1 and min(n*m, 50) 
// elements, inclusive.
// -columnIndex and element will contain the same number of 
// elements as rowIndex.
// -Each element of rowIndex will be between 0 and n-1, 
// inclusive.
// -Each element of columnIndex will be between 0 and m-1, 
// inclusive.
// -Each element of element will be between 1 and 1,000, 
// inclusive.
// -No two indices represented by rowIndex and columnIndex 
// will be the same.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 3
// {0, 0, 0, 1, 1, 1}
// {0, 1, 2, 0, 1, 2}
// {4, 6, 9, 1, 3, 6}
// 
// Returns: 29
// 
// We are already given all elements of this matrix.
// It looks as follows:
// 
// [4 6 9]
// [1 3 6]
// 
// We can easily verify that this is a mountain for a=0 and 
// b=2.
// The sum of all elements is 4+6+9+1+3+6=29.
// 
// 1)
// 2
// 3
// {1, 0, 1}
// {2, 2, 0}
// {5, 7, 6}
// 
// Returns: 40
// 
// The matrix looks as follows.
// 
// [? ? 7]
// [6 ? 5]
// 
// The optimal solution is as follows. The sum is 
// 7+8+7+6+7+5=40.
// 
// [7 8 7]
// [6 7 5]
// 
// 
// 2)
// 3
// 3
// {0, 0, 2, 2}
// {0, 2, 2, 0}
// {1, 1, 1, 1}
// 
// Returns: 15
// 
// The matrix looks as follows:
// 
// [1 ? 1]
// [? ? ?]
// [1 ? 1]
// 
// The optimal solution is as follows.
// 
// [1 2 1]
// [2 3 2]
// [1 2 1]
// 
// 
// 3)
// 2
// 2
// {0, 0, 1, 1}
// {0, 1, 1, 0}
// {5, 8, 5, 8}
// 
// Returns: -1
// 
// The given matrix is not a mountain.
// 
// [5 8]
// [8 5]
// 
// 
// 4)
// 1
// 3
// {0}
// {1}
// {1}
// 
// Returns: -1
// 
// This matrix looks as follows:
// 
// [? 1 ?]
// 
// It is not possible to make a mountain out of it, because 
// in a mountain all elements have to be positive.
// (Note that 0 is not positive.)
// 
// 5)
// 123
// 45
// {2, 3, 5, 7, 11}
// {13, 17, 19, 23, 29}
// {100, 200, 300, 400, 500}
// 
// Returns: 367047
// 
// 
// 
// 6)
// 200
// 200
// {5}
// {8}
// {666}
// 
// Returns: 5737554
// 
// 
// 
// 7)
// 10
// 10
// {0, 8, 7}
// {3, 1, 9}
// {5, 4, 7}
// 
// Returns: 593
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

const int INF = 0x3f3f3f3f;

class TheMountain {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {0, 0, 0, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 2, 0, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 6, 9, 1, 3, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 29; verify_case(0, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 7, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 40; verify_case(1, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0, 0, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 15; verify_case(2, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 0, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 8, 5, 8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(3, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(4, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 45; int Arr2[] = {2, 3, 5, 7, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {13, 17, 19, 23, 29}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 200, 300, 400, 500}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 367047; verify_case(5, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 200; int Arg1 = 200; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {666}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5737554; verify_case(6, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {0, 8, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 1, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 4, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 593; verify_case(7, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

	public: 
   void printmat(vector<vector<int> > x) {
      return ;
      for(int i=0; i<(int)x.size(); i++) {
         for(int j=0; j<(int)x[i].size(); j++)
            if( x[i][j]!=INF ) cout << x[i][j] << " ";
            else              cout << "INF ";
         cout << endl;
      }
      cout << endl;
   }

	int minSum(int n, int m, vector <int> r, vector <int> c, vector <int> e) {
      vector<vector<int> > x(n, vector<int> (m, 0));
      vector<vector<bool> > is_set(n, vector<bool> (m, false));
		vector<vector<int> > x1(n, vector<int> (m, 0));
      vector<vector<int> > x2(n, vector<int> (m, 0));
      vector<vector<int> > x3(n, vector<int> (m, 0));
      vector<vector<int> > x4(n, vector<int> (m, 0));

      vector<vector<int> > s1(n, vector<int> (m, 0));
      vector<vector<int> > s2(n, vector<int> (m, 0));
      vector<vector<int> > s3(n, vector<int> (m, 0));
      vector<vector<int> > s4(n, vector<int> (m, 0));

      for(int i=0; i<(int)r.size(); i++) {
         x[r[i]][c[i]] = e[i];
         is_set[r[i]][c[i]] = 1;
         x1[r[i]][c[i]] = e[i];
         x2[r[i]][c[i]] = e[i];
         x3[r[i]][c[i]] = e[i];
         x4[r[i]][c[i]] = e[i];
      }

      for(int i=0; i<n; i++)
         for(int j=0; j<m; j++) {
            int val = 0;
            if( i ) val = max(val, x1[i-1][j]);
            if( j ) val = max(val, x1[i][j-1]);
            if( val!=INF ) val++;

            if( x1[i][j]==0 ) x1[i][j] = val;
            else if( x1[i][j]<val ) x1[i][j] = INF;

            if( x1[i][j]!=INF ) {
               int a=0, b=0, c=0;
               if( i ) a = s1[i-1][j];
               if( j ) b = s1[i][j-1];
               if( i && j ) c = s1[i-1][j-1];
               if( a==INF || b==INF || c==INF ) s1[i][j] = INF;
               else s1[i][j] = a + b - c + x1[i][j];

            } else
               s1[i][j] = INF;
         }
      printmat(x1);
      printmat(s1);

      for(int i=n-1; i>=0; i--)
         for(int j=0; j<m; j++) {
            int val = 0;
            if( i<n-1 ) val = max(val, x2[i+1][j]);
            if( j ) val = max(val, x2[i][j-1]);
            if( val!=INF ) val++;

            if( x2[i][j]==0 ) x2[i][j] = val;
            else if( x2[i][j]<val ) x2[i][j] = INF;

            if( x2[i][j]!=INF ) {
               int a=0, b=0, c=0;
               if( i<n-1 ) a = s2[i+1][j];
               if( j ) b = s2[i][j-1];
               if( i<n-1 && j ) c = s2[i+1][j-1];
               if( a==INF || b==INF || c==INF ) s2[i][j] = INF;
               else s2[i][j] = a + b - c + x2[i][j];

            } else
               s2[i][j] = INF;
         }
      printmat(x2);
      printmat(s2);

      for(int i=n-1; i>=0; i--)
         for(int j=m-1; j>=0; j--) {
            int val = 0;
            if( i<n-1 ) val = max(val, x3[i+1][j]);
            if( j<m-1 ) val = max(val, x3[i][j+1]);
            if( val!=INF ) val++;

            if( x3[i][j]==0 ) x3[i][j] = val;
            else if( x3[i][j]<val ) x3[i][j] = INF;

            if( x3[i][j]!=INF ) {
               int a=0, b=0, c=0;
               if( i<n-1 ) a = s3[i+1][j];
               if( j<m-1 ) b = s3[i][j+1];
               if( i<n-1 && j<m-1 ) c = s3[i+1][j+1];
               if( a==INF || b==INF || c==INF ) s3[i][j] = INF;
               else s3[i][j] = a + b - c + x3[i][j];

            } else
               s3[i][j] = INF;
         }
      printmat(x3);
      printmat(s3);

      for(int i=0; i<n; i++)
         for(int j=m-1; j>=0; j--) {
            int val = 0;
            if( i ) val = max(val, x4[i-1][j]);
            if( j<m-1 ) val = max(val, x4[i][j+1]);
            if( val!=INF ) val++;

            if( x4[i][j]==0 ) x4[i][j] = val;
            else if( x4[i][j]<val ) x4[i][j] = INF;

            if( x4[i][j]!=INF ) {
               int a=0, b=0, c=0;
               if( i ) a = s4[i-1][j];
               if( j<m-1 ) b = s4[i][j+1];
               if( i && j<m-1 ) c = s4[i-1][j+1];
               if( a==INF || b==INF || c==INF ) s4[i][j] = INF;
               else s4[i][j] = a + b - c + x4[i][j];

            } else
               s4[i][j] = INF;
         }
      printmat(x4);
      printmat(s4);

      int res = INF;
      for(int a=0; a<n; a++)
      for(int b=0; b<m; b++) {
         int s = 0;
         if( a && b ) s += s1[a-1][b-1];
         if( s>=INF ) continue;
         if( a<n-1 && b ) s+= s2[a+1][b-1];
         if( s>=INF ) continue;
         if( a<n-1 && b<m-1 ) s += s3[a+1][b+1];
         if( s>=INF ) continue;
         if( a && b<m-1 ) s += s4[a-1][b+1];
         if( s>=INF ) continue;

         int val = 1;
         bool exists = 1;
         for(int i=0; s<res && exists && i<a; i++)
            if( is_set[i][b] ) {
               val = x[i][b];
               if( b && x[i][b]<=x1[i][b-1] )       exists = 0;
               if( b<m-1 && x[i][b]<=x4[i][b+1] )   exists = 0;
               if( i && x[i][b]<=x[i-1][b] )       exists = 0;
               s += x[i][b];
            }
            else {
               if( b )     val = max(val, x1[i][b-1]+1);
               if( b<m-1 ) val = max(val, x4[i][b+1]+1);
               if( i )     val = max(val, x [i-1][b]+1);
               if( val>=INF ) exists = 0;
               x[i][b] = val;
               val++;
               s += x[i][b];
            }
         
         val = 1;
         for(int i=n-1; s<res && exists && i>a; i--)
            if( is_set[i][b] ) {
               val = x[i][b];
               if( b && x[i][b]<=x2[i][b-1] )       exists = 0;
               if( b<m-1 && x[i][b]<=x3[i][b+1] )   exists = 0;
               if( i<n-1 && x[i][b]<=x[i+1][b] )    exists = 0;
               s += x[i][b];
            }
            else {
               if( b )     val = max(val, x2[i][b-1]+1);
               if( b<m-1 ) val = max(val, x3[i][b+1]+1);
               if( i<n-1 ) val = max(val, x [i+1][b]+1);
               if( val>=INF ) exists = 0;
               x[i][b] = val;
               val++;
               s += x[i][b];
            }

         val = 1;
         for(int j=0; s<res && exists && j<b; j++) {
            if( a )     val = max(val, x1[a-1][j]+1);
            if( a<n-1 ) val = max(val, x2[a+1][j]+1);
            if( j )     val = max(val, x [a][j-1]+1);
            if( val>=INF ) exists = 0;

            if( is_set[a][j] )
               exists &= (x[a][j]>=val);
            else
               x[a][j] = val;
            val++;
            s += x[a][j];
         }

         val = 1;
         for(int j=m-1; s<res && exists && j>b; j--) {
            if( a )     val = max(val, x4[a-1][j]+1);
            if( a<n-1 ) val = max(val, x3[a+1][j]+1);
            if( j<m-1 ) val = max(val, x [a][j+1]+1);
            if( val>=INF ) exists = 0;

            if( is_set[a][j] )
               exists &= (x[a][j]>=val);
            else
               x[a][j] = val;
            val++;
            s += x[a][j];
         }

         val = 1;
         if( a )     val = max(val, x[a-1][b]+1);
         if( a<n-1 ) val = max(val, x[a+1][b]+1);
         if( b )     val = max(val, x[a][b-1]+1);
         if( b<m-1 ) val = max(val, x[a][b+1]+1);
         if( is_set[a][b] ) 
            exists &= (x[a][b]>=val);
         else
            x[a][b] = val;
         s += x[a][b];

         if( exists && s<res ) res = s;
      }

      return (res==INF ? -1 : res);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TheMountain ___test; 
   int n = 1, m = 1;
   vector <int> r, c, e;
   r.push_back(0);
   c.push_back(0);
   e.push_back(1);
   cout << ___test.minSum(n, m, r, c, e) << endl;
	___test.run_test(-1); 
} 
// END CUT HERE
