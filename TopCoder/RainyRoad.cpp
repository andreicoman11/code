// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is going to take a path to meet her friends. The 
// path is tiled with 1x1 square tiles. It is N tiles long 
// and 2 tiles wide. If we imagine that the path is going 
// from the left to the right, we can view it as a rectangle 
// with 2 rows and N columns of tiles.
// The rows of the path are numbered 0 to 1 from top to 
// bottom, and the columns of the path are numbered 0 to N-1 
// from left to right. Ciel starts at the tile in row 0, 
// column 0. She has to reach the tile in row 0, column N-1.
// 
// In each step, Ciel can move to an adjacent tile. Two tiles 
// are adjacent if they share at least one point (a side or a 
// corner).
// 
// Because it rained yesterday, some tiles are covered by 
// puddles of water. Ciel will not step on these tiles. You 
// are given a vector <string> road. The j-th character of i-
// th element is 'W' if a tile at i-th row of j-th column is 
// covered by  water, and '.' otherwise.
// 
// Return the string "YES" if she can move to her destination 
// without entering a tile which is filled with water. 
// Otherwise, return "NO".
// 
// DEFINITION
// Class:RainyRoad
// Method:isReachable
// Parameters:vector <string>
// Returns:string
// Method signature:string isReachable(vector <string> road)
// 
// 
// NOTES
// -The constraints guarantee that the starting tile and the 
// destination tile are never covered by water.
// 
// 
// CONSTRAINTS
// -road will contain exactly 2 elements.
// -Each elements of road will contain between 2 and 50 
// characters, inclusive.
// -All elements of road will contain the same number of 
// characters.
// -Each character of road will be either '.' or 'W'.
// -The first character and the last character of 0-th 
// element of road will be '.'.
// 
// 
// EXAMPLES
// 
// 0)
// {".W.."
// ,"...."}
// 
// Returns: "YES"
// 
// One of the possible ways is as follows. Here, 'F' is the 
// tile occupied by Fox Ciel.
// 
// "FW.."
// "...." 
// 
// ".W.."
// "F..." 
// 
// ".W.."
// ".F.."
// 
// ".W.."
// "..F."
// 
// ".W.F"
// "...."
// 
// 
// 1)
// {".W.."
// ,"..W."}
// 
// Returns: "YES"
// 
// 
// 
// 2)
// {".W..W.."
// ,"...WWW."}
// 
// Returns: "NO"
// 
// 
// 
// 3)
// {".."
// ,"WW"}
// 
// Returns: "YES"
// 
// 
// 
// 4)
// {".WWWW."
// ,"WWWWWW"}
// 
// Returns: "NO"
// 
// 
// 
// 5)
// {".W.W.W."
// ,"W.W.W.W"}
// 
// Returns: "YES"
// 
// 
// 
// 6)
// {".............................................W."
// ,".............................................W."}
// 
// Returns: "NO"
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
class RainyRoad {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".W.."
,"...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isReachable(Arg0)); }
	void test_case_1() { string Arr0[] = {".W.."
,"..W."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isReachable(Arg0)); }
	void test_case_2() { string Arr0[] = {".W..W.."
,"...WWW."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, isReachable(Arg0)); }
	void test_case_3() { string Arr0[] = {".."
,"WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, isReachable(Arg0)); }
	void test_case_4() { string Arr0[] = {".WWWW."
,"WWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isReachable(Arg0)); }
	void test_case_5() { string Arr0[] = {".W.W.W."
,"W.W.W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(5, Arg1, isReachable(Arg0)); }
	void test_case_6() { string Arr0[] = {".............................................W."
,".............................................W."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(6, Arg1, isReachable(Arg0)); }

// END CUT HERE

	public: string isReachable(vector <string> road) {
		for(int i=0; i<road[0].sz; i++)
      if( road[0][i]=='W' && road[1][i]=='W' )
        return "NO";
    return "YES";
	}
	
};

// BEGIN CUT HERE 
int main()
{
	RainyRoad ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
