// BEGIN CUT HERE
// PROBLEM STATEMENT
// This problem statement contains superscripts and/or 
// subscripts. These may not display properly outside the 
// applet.
// 
// Gobble City has a tree topology: There are N 
// intersections, numbered 0 through N-1. The intersections 
// are connected by N-1 bidirectional roads in such a way 
// that it is possible to travel between any two 
// intersections. More precisely, for each pair of 
// intersections there is a unique path (a sequence of roads; 
// see Notes for a formal definition) that connects them. You 
// are given a vector <int> roads that describes the roads: 
// for each i (0 <= i <= N-2), we have 0 <= roads[i] <= i and 
// there is a road between intersections numbered roads[i] 
// and i+1.
// 
// On each road there is a single lamp. The lamps are 
// numbered 0 through N-2. For each i, lamp i is on the road 
// that connects roads[i] and i+1. You are given a string 
// initState that describes the initial states of all lamps: 
// initState[i]='1' means that lamp i is initially on, and 
// initState[i]='0' means that it is off.
// 
// Now you are at the Control Center for these lamps. The 
// only way in which you can operate the lamps looks as 
// follows: You enter the numbers of two intersections (X and 
// Y) into the Control Center computer, and the computer 
// toggles the state of all lamps on the path between X and 
// Y. (Toggling the state of a lamp means that if the lamp 
// was off it is now on, and vice versa.) You can perform 
// arbitrarily many such operations, one after another.
// 
// Some of the lamps are important to you. You are given this 
// information in the string isImportant: isImportant[i]='1' 
// means that lamp i is important, and isImportant[i]='0' 
// means that it is not.
// 
// Your goal is to turn on all important lamps at the same 
// time. (We do not care about the state of the remaining 
// lamps.) Return the minimum number of operations needed to 
// achieve the goal.
// 
// DEFINITION
// Class:TurnOnLamps
// Method:minimize
// Parameters:vector <int>, string, string
// Returns:int
// Method signature:int minimize(vector <int> roads, string 
// initState, string isImportant)
// 
// 
// NOTES
// -In your solution some lamps may be toggled multiple times.
// -A path between two intersection a and b is a sequence of 
// intersections (v0=a, v1, v2, ..., vk=b) such that all v0, 
// v1, ..., vk are pairwise distinct and for each i=0..k-1, 
// there exists a road between vi and vi+1.
// 
// 
// CONSTRAINTS
// -roads will contain N-1 elements, where N is between 2 and 
// 50, inclusive.
// -For each i, the i-th (0-based index) element of roads 
// will be between 0 and i, inclusive.
// -initState will be N-1 characters long.
// -initState will only contain the characters '0' and '1'.
// -isImportant will be N-1 characters long.
// -isImportant will only contain the characters '0' and '1'.
// 
// 
// EXAMPLES
// 
// 0)
// {0,0,1,1}
// "0001"
// "0111"
// 
// Returns: 1
// 
// The figure below illustrates this test case and its 
// optimal solution.
// 
// Red roads are the important ones. The optimal solution 
// chooses the intersections 2 and 3. The path that 
// corresponds to this choice is enclosed by the dashed line. 
// All lamps on this path are toggled from 0 to 1.
// 
// 1)
// {0,0,1,1}
// "0000"
// "0111"
// 
// Returns: 2
// 
// This is almost the same test case as Example 0, but now 
// the initial state of the lamp 3 (i.e., the lamp on the 
// road that connects intersections 1 and 4) is now 0. As 
// this is an important lamp, we now need two operations in 
// order to turn all important lamps to 1.
// 
// 
// 2)
// {0,0,1,1,4,4}
// "000100"
// "111111"
// 
// Returns: 2
// 
// 
// Note that lamp on the road between intersections 1 and 4 
// was toggled twice: first from 1 to 0, and then from 0 back 
// to 1.
// 
// 3)
// {0,0,1,1,4,4}
// "100100"
// "011101"
// 
// Returns: 2
// 
// 
// 
// 4)
// {0,0,2,2,3,1,6,3,1}
// "010001110"
// "000110100"
// 
// Returns: 1
// 
// 
// 
// 5)
// {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}

// "0000000000010000000000000010000010100000000000000"
// "1010111111111011011111000110111111111111111110111"
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

class TurnOnLamps {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0001"; string Arg2 = "0111"; int Arg3 = 1; verify_case(0, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000"; string Arg2 = "0111"; int Arg3 = 2; verify_case(1, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "000100"; string Arg2 = "111111"; int Arg3 = 2; verify_case(2, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "100100"; string Arg2 = "011101"; int Arg3 = 2; verify_case(3, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,2,2,3,1,6,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010001110"; string Arg2 = "000110100"; int Arg3 = 1; verify_case(4, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000000000010000000000000010000010100000000000000"; string Arg2 = "1010111111111011011111000110111111111111111110111"; int Arg3 = 14; verify_case(5, Arg3, minimize(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
	int minimize(vector <int> roads, string init, string imp) {
      int n = (int)roads.size() + 1;
		vector<pair<int,int> > lvl(n);
      int res = 0;
      lvl[0] = make_pair(0,0);
      for(int i=0; i<n-1; i++)
         lvl[1+i] = make_pair(lvl[roads[i]].first + 1, i+1);
      sort(lvl.begin(), lvl.end());
      vector<int> vis(n);
      init = "0" + init;
      imp = "0" + imp;

      for(int i=n-1; i>=0; i--) {
         int j = lvl[i].second;

         if( vis[j]>=2 ) {
            res+=vis[j]/2;
            vis[j] -= (vis[j] / 2) * 2;
         }

         if( vis[j]==1 && j==0 ) res++, vis[j] = 0;
         
         if( vis[j]==1 && imp[j]=='1' && init[j]=='1' ) {
            res++;
            vis[j] = 0;
         } 
         
         if( vis[j]==1 || ( imp[j]=='1' && init[j]=='0' ))
            vis[roads[j-1]]++;
      }

      return res;

	}
	
};

// BEGIN CUT HERE 
int main()
{
	TurnOnLamps ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
