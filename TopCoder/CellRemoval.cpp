// BEGIN CUT HERE
// PROBLEM STATEMENT
// In biology, organisms have the following property: 
// Starting from the first cell (the zygote), each cell 
// during an organism's development process either divides 
// into 2 other cells or does not divide at all.  An organism 
// is mature when all of its cells will not divide any further.
// 
// Let's assign a unique number to each cell in an organism's 
// development process.  For example, consider a species in 
// which each organism starts with cell 0, which divides into 
// cells 1 and 2.  Cell 1 divides into cells 3 and 4.  Cells 
// 2, 3 and 4 do not divide.  Every mature organism of this 
// species will consist of exactly 3 cells - 2, 3 and 4.
// 
// 
// During the development process, if we kill a cell, it will 
// be absent in the mature form of the organism.  If that 
// cell happens to be a cell that divides, then the mature 
// organism will be missing all of the cell's descendants as 
// well because the cell is killed before it has a chance to 
// divide.  For example, in the organism described above, if 
// we kill cell 1 during the development process, the mature 
// organism will contain only cell 2.
// 
// 
// 
// You are given a vector <int> parentCell describing the 
// development process of an organism.  The i-th element of 
// parentCell is the parent cell of cell i (where i is a 0-
// based index).  The zygote's parent is -1.  Return the 
// number of cells the mature form of this organism would 
// have if you killed cell deletedCell during the development 
// process.
// 
// DEFINITION
// Class:CellRemoval
// Method:cellsLeft
// Parameters:vector <int>, int
// Returns:int
// Method signature:int cellsLeft(vector <int> parent, int 
// deletedCell)
// 
// 
// CONSTRAINTS
// -parentCell will contain exactly N elements, where N is an 
// odd integer between 1 and 50, inclusive.
// -There will be exactly one "-1" element in parentCell.
// -Every element of parentCell will be between -1 and N-1, 
// inclusive.
// -parentCell will form a binary tree.
// -deletedCell will be between 0 and N-1, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {-1,0,0,1,1}
// 2
// 
// Returns: 2
// 
// This is the example organism from the problem statement.  
// If we kill cell 2, there will still be two cells left (3 
// and 4).
// 
// 1)
// {-1,0,0,1,1}
// 1
// 
// Returns: 1
// 
// This is the example organism from the problem statement.  
// If we kill cell 1, the only cell left will be cell 2.  
// Cells 3 and 4 will not exist because cell 1 is their 
// ancestor.
// 
// 2)
// {-1,0,0,1,1}
// 0
// 
// Returns: 0
// 
// If we kill the zygote, there is nothing left.
// 
// 3)
// {-1,0,0,2,2,4,4,6,6}
// 4
// 
// Returns: 2
// 
// 
// 
// 4)
// {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,

//  35,18,7,36,10,16,5,38,35,4,13,
// -1,16,26,1,12,2,5,18,40,1,17,38,44,14}
// 24
// 
// Returns: 14
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
class CellRemoval {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, cellsLeft(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, cellsLeft(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, cellsLeft(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1,0,0,2,2,4,4,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(3, Arg2, cellsLeft(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 14; verify_case(4, Arg2, cellsLeft(Arg0, Arg1)); }

// END CUT HERE

	public: int cellsLeft(vector <int> p, int dc) {
      bool m[64] = {0};
      m[dc] = 1;
      queue<int> q;
      for(int i=0; i<p.size(); i++)
         if( p[i]==-1 && i!=dc ) q.push(i);
      int res = 0;
      while( !q.empty() )
      {
         int n = q.front();
         q.pop();
         //cout << n << "\t";
         bool hask = 0;
         for(int i=0; i<p.size(); i++)
            if( p[i]==n && i!=dc )
            {
               q.push(i);
               hask = 1;
            }
         if( !hask ) res++;

      }
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	CellRemoval ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
