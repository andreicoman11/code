// BEGIN CUT HERE
// PROBLEM STATEMENT
// A binary matrix is a matrix in which each element is 
// either 0 or 1. There is a secret binary matrix with R rows 
// and C columns. Your task is to determine its elements from 
// two partial descriptions.
// 
// The first description is given as a vector <string> rows 
// with R elements. Each element of rows will be a string of 
// C characters. Element i of rows describes the i-th row of 
// the secret matrix. Each character in each element of rows 
// is either '0', '1', or '?'. The meaning of '?' is that the 
// corresponding element of the matrix may be either 0 or 1.
// 
// The second description is given as a vector <string> 
// columns with C elements. Each element of columns will be a 
// string of R characters. Each element of columns describes 
// one column of the secret matrix. Different elements of 
// columns represent different columns, but not necessarily 
// in the correct order. Again, each character in each 
// element of columns is either '0', '1', or '?'.
// 
// You may assume that there is at least one binary matrix 
// that corresponds to both descriptions: its rows match the 
// elements of rows (in the same order) and its columns match 
// the elements of columns (after a suitable permutation is 
// applied on columns). Your method must find the 
// lexicographically smallest of all such matrices. Return 
// that matrix formatted as a vector <string>.
// 
// DEFINITION
// Class:P8XMatrixRecovery
// Method:solve
// Parameters:vector <string>, vector <string>
// Returns:vector <string>
// Method signature:vector <string> solve(vector <string> 
// rows, vector <string> columns)
// 
// 
// NOTES
// -Given two different matrices A and B, let i be the first 
// row on which they differ, and let j be the first element 
// in that row on which they differ. If A[i,j] &lt B[i,j], we 
// say that A is lexicographically smaller than B, and vice 
// versa.
// 
// 
// CONSTRAINTS
// -rows will contain between 1 and 30 elements, inclusive.
// -Each element of rows will contain between 1 and 30 
// characters, inclusive.
// -All the elements of rows will contain the same number of 
// character.
// -Each character in each element of rows will be either 
// '0', '1', or '?'.
// -columns will contain exactly C elements, where C is the 
// number of elements in rows[0].
// -Each element of columns will contain exactly R 
// characters, where R is the number of elements in rows.
// -Each character in each element of columns will be '0', 
// '1', or '?'.
// -There will be at least one binary matrix that corresponds 
// to both rows and columns in the way described in the 
// problem statement.
// 
// 
// EXAMPLES
// 
// 0)
// {"10?"
// ,"?11"}
// {"01"
// ,"10"
// ,"1?"}
// 
// 
// Returns: {"101", "011" }
// 
// Note that columns[0] describes column 1 of the secret 
// matrix, columns[1] describes column 0 and columns[2] 
// describes column 2.
// 
// 1)
// {"0"
// ,"?"
// ,"1"}
// {"0?1"}
// 
// Returns: {"0", "0", "1" }
// 
// There are two matrices that match both descriptions. We 
// return the lexicographically smaller one.
// 
// 2)
// {"10"
// ,"01"}
// {"10"
// ,"01"}
// 
// Returns: {"10", "01" }
// 
// 
// 
// 3)
// {"??0"
// ,"11?"
// ,"?01"
// ,"1?1"}
// {"1???"
// ,"?111"
// ,"0?1?"}
// 
// Returns: {"010", "110", "101", "101" }
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

int n, m;
bool e[64][64] = {0};
vector<string> r, c;

class P8XMatrixRecovery {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"10?"
,"?11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01"
,"10"
,"1?"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"101", "011" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0"
,"?"
,"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0?1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0", "0", "1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10"
,"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10"
,"01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10", "01" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"??0"
,"11?"
,"?01"
,"1?1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1???"
,"?111"
,"0?1?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"010", "110", "101", "101" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE
   void graph()
   {
      memset(e, 0, sizeof(e));
      for(int j=0; j<m; j++)
      {
         for(int k=0; k<m; k++)
         {
            bool ok = 1;
            for(int i=0; ok && i<n; i++)
               if( r[i][j]!=c[k][i] && r[i][j]!='?' && c[k][i]!='?' )
                  ok = 0;
            
            if( ok )
            {
               e[j][m+k] = 1;
            }
         }
      }
   }

   int flow()
   {
      graph();
      for(int i=0; i<m; i++) {
         e[2*m][i] = 1;
         e[m+i][2*m+1] = 1;
      }
      
      int t[64] = {0};
      bool vis[64] = {0};
      int flow = 0, found;
      do{
         memset(t, 0, sizeof(t));
         memset(vis, 0, sizeof(vis));
         found = 0;
         queue<int> q;
         q.push(2*m);
         t[2*m] = -1;
         vis[2*m] = 1;
         while( !q.empty() && !found )
         {
            int qn = q.front();
            q.pop();
            for(int i=0; i<2*m+2; i++)
               if( e[qn][i] && !vis[i] )
               {
                  q.push(i);
                  t[i] = qn;
                  vis[i] = 1;
                  if( i==2*m+1 ) found = 1;
               }
         }

         if( found ) flow++;
         else break;

         int qn = 2*m+1;
         while( t[qn]!=-1 )
         {
            e[t[qn]][qn] = 0;
            e[qn][t[qn]] = 1;
            qn = t[qn];
         }

      } while(found);
      return flow;
   }

	public: vector <string> solve(vector <string> r2, vector <string> c2) {
      r = r2;
      c = c2;
		vector<int> eout(c.size()), ein(c.size());
      n = r.size(), m = r[0].size();
      
      for(int x=0;x<n; x++)
      for(int y=0;y<m; y++)
      if( r[x][y]=='?' )
      {
         r[x][y] = '0';
         if( flow()<m ) r[x][y] = '1';
      }
      
      return r;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	P8XMatrixRecovery ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
