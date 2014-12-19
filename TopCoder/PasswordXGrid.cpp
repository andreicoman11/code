// BEGIN CUT HERE
// PROBLEM STATEMENT
// Ms. Ciel loves rabbits. She has a large special cage for 
// her rabbits. The cage is protected by a special lock: a 
// board containing a grid.
// 
// 
// 
// The board contains an N times M grid.
// We can assign integer coordinates to the vertices of the 
// grid.
// (Vertices are the points where horizontal and vertical 
// grid lines intersect.)
// The top left corner of the grid will get the coordinates 
// (0,0) and the bottom right corner coordinates (N,M).
// Each line segment between two adjacent vertices is labeled 
// by an integer from 0 to 9, inclusive.
// You are given two vector <string>s horizontal and vertical 
// containing these labels in the format defined below.
// 
// For all i, j such that 0 <= i <= N and 0 <= j <= M-1, 
// there is a line segment between the points (i,j) and (i,
// j+1).
// This line segment has the label horizontal[i][j].
// For all i, j such that 0 <= i <= N-1 and 0 <= j <= M, 
// there is a line segment between the points (i,j) and (i,
// j+1).
// This line segment has the label vertical[i][j].
// 
// 
// 
// 
// To unlock this board, you must put your finger on the 
// point (0, 0), and move to the point (N, M).
// In each step you can only go down or right.
// I.e., if you are currently at the point (i,j), your next 
// step may take you either to (i,j+1), or to (i+1,j).
// By moving your finger you picked one of the paths from the 
// top left to the bottom right corner.
// The path consists of N+M line segments, and each of those 
// line segments has an integer label.
// The cost of a path is the sum of those labels.
// Let S be the smallest value among the costs of all valid 
// paths from the top left to the bottom right corner.
// Inside the board there is a counter that computes the sum 
// of all numbers that are on the line segments you used in 
// your path.
// The lock will open if and only if you picked a path with 
// cost exactly S, i.e., a path with the smallest possible 
// cost.
// 
// 
// 
// Finding the way to unlock a given board is a shortest path 
// problem.
// You could surely solve it, but Ciel is just a young fox.
// She does not know any complicated algorithms such as 
// Dijkstra, Bellman-Ford, or Floyd-Warshall.
// Thus unlocking the board is too hard for her.
// She wants you to modify her board to a state in which it 
// can be unlocked by any path from the top left to the 
// bottom right corner.
// In other words, on the resulting board all valid paths 
// must have exactly the same cost T. 
// The only allowed operation is to increase some of the 
// labels.
// (The new labels must again be integers, but they are 
// allowed to exceed 9.)
// Compute and return the smallest possible value of T.
// 
// DEFINITION
// Class:PasswordXGrid
// Method:minSum
// Parameters:vector <string>, vector <string>
// Returns:int
// Method signature:int minSum(vector <string> horizontal, 
// vector <string> vertical)
// 
// 
// NOTES
// -Note that Ciel can always achieve her goal: for example, 
// she can increase every number to X, where X is the maximal 
// number over all numbers on the board.
// 
// 
// CONSTRAINTS
// -N and M will be between 1 and 40, inclusive.
// -horizontal will contain N+1 elements.
// -Each element of horizontal will contain M characters.
// -vertical will contain N elements.
// -Each element of vertical will contain M+1 characters.
// -Each character in each element of horizontal and vertical 
// will be a digit: '0'-'9'.
// 
// 
// EXAMPLES
// 
// 0)
// {"1","4"}
// {"32"}
// 
// Returns: 7
// 
// We have two possible paths.
// One of them has the cost 1+2 = 3, the other one 3+4 = 7.
// As the costs are not equal, we have to modify some of the 
// labels.
// One possible solution is to increase the label 1 to 6.
// Then both paths have the same cost: 7.
// 
// 1)
// {"47", "59"}
// {"361"}
// 
// Returns: 19
// 
// This is how the grid looks like:
// 
// +--4--+--7--+
// |     |     |
// 3     6     1
// |     |     |
// +--5--+--9--+
// 
// One possible solution is to increase 3 to 5 and 7 to 14.
// 
// 2)
// {"36", "23", "49"}
// {"890", "176"}
// 
// Returns: 28
// 
// 
// 
// 3)
// {"8888585","5888585"}
// {"58585858"}
// 
// Returns: 58
// 
// 
// 
// 4)
// {"7777777","7777777","7777777","7777777"}
// {"44444444","44444444","44444444"}
// 
// Returns: 61
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
int g[128][128], n, m;

int val(char c)
{
   return int(c) - int('0');
}

class PasswordXGrid {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"32"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(0, Arg2, minSum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"47", "59"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"361"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 19; verify_case(1, Arg2, minSum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"36", "23", "49"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"890", "176"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(2, Arg2, minSum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"8888585","5888585"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"58585858"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; verify_case(3, Arg2, minSum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"7777777","7777777","7777777","7777777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"44444444","44444444","44444444"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 61; verify_case(4, Arg2, minSum(Arg0, Arg1)); }

// END CUT HERE

	public: 
	int minSum(vector <string> h, vector <string> v) {
      n = h.size() + v.size();
      m = h[0].size() + v[0].size();
		memset(g, 0, sizeof(g));
      for(int i=0; i<n; i++)
         if( i%2==0 )
            for(int j=1; j<m; j+=2)
               g[i][j] = val(h[i/2][j/2]);
         else
            for(int j=0; j<m; j+=2)
               g[i][j] = val(v[i/2][j/2]);
      
      for(int j=2; j<m; j++)
         g[0][j] += g[0][j-1];

      for(int i=2; i<n; i++)
         g[i][0] += g[i-1][0];

      for(int i=2; i<n; i+=2)
      for(int j=2; j<m; j+=2)
         g[i][j] += max(g[i-1][j]+g[i-2][j], g[i][j-1]+g[i][j-2]);

      /*cout << n << " " << m << endl;
      for(int i=0; i<n; i++)
      {
         for(int j=0; j<m; j++)
            cout << g[i][j] << " ";
         cout << "\n";
      }*/

      return g[n-1][m-1];
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PasswordXGrid ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
