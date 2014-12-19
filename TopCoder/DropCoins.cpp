// BEGIN CUT HERE
// PROBLEM STATEMENT
// There is a rectangle divided into 1x1 cells. Each cell is 
// either empty or it contains a single coin. 
// 
// You can apply the following operation repeatedly.
// 
// First, choose one of the directions: up, down, left, or 
// right. 
// Then, move all coins in the chosen direction by exactly 1 
// cell. If this would cause a coin to move out of the 
// rectangle, the coin drops out from the rectangle and 
// disappears. 
// 
// Your objective in this problem is to apply the operations 
// so that the number of coins remaining on the rectangle 
// becomes exactly K.
// 
// You are given the int K and a vector <string> board that 
// describes the initial state of the rectangle. More 
// precisely, character j of element i of board is 'o' if i-
// th row of j-th column of the rectangle contains a coin, 
// and it is '.' otherwise.
// 
// Return the minimum number of operations you have to 
// perform. If the objective is impossible, return -1.
// 
// DEFINITION
// Class:DropCoins
// Method:getMinimum
// Parameters:vector <string>, int
// Returns:int
// Method signature:int getMinimum(vector <string> board, int 
// K)
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 30 elements, inclusive.
// -Each element of board will contain between 1 and 30 
// characters, inclusive.
// -All elements of board will contain the same number of 
// characters.
// -Each character in each element of board will be either 
// '.' or 'o'.
// -K will be between 1 and 900, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {".o.."
// ,"oooo"
// ,"..o."}
// 
// 3
// 
// Returns: 2
// 
// One of the optimal solutions is to move coins to the right 
// twice.
// 
// 1)
// {".....o"
// ,"......"
// ,"oooooo"
// ,"oooooo"
// ,"......"
// ,"o....."}
// 
// 12
// 
// Returns: 3
// 
// One of the optimal solutions:
// 
// move coins up (1 coin drops, 13 remain) 
// move coins down 
// move coins down again (1 coin drops, 12 remain) 
// 
// 
// 2)
// {"...."
// ,".oo."
// ,".oo."
// ,"...."}
// 
// 3
// 
// Returns: -1
// 
// It is impossible to make the number of remaining coins 
// exactly 3.
// 
// 3)
// {"......."
// ,"..ooo.."
// ,"ooooooo"
// ,".oo.oo."
// ,"oo...oo"}
// 
// 12
// 
// Returns: 4
// 
// 
// 
// 4)
// {"................."
// ,".ooooooo...oooo.."
// ,".ooooooo..oooooo."
// ,".oo.......oo..oo."
// ,".oo.......oo..oo."
// ,".ooooo.....oooo.."
// ,".ooooooo...oooo.."
// ,".....ooo..oo..oo."
// ,"......oo..oo..oo."
// ,".ooooooo..oooooo."
// ,".oooooo....oooo.."
// ,"................."}
// 
// 58
// 
// Returns: 6
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
class DropCoins {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o.."
,"oooo"
,"..o."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 3; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...."
,".oo."
,".oo."
,"...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 4; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 6; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

	public: int getMinimum(vector <string> board, int K) {
		int b[32][32];
    memset(b, 0, sizeof(b));
    int n = board.sz, m = board[0].sz;
    b[0][0] = (board[0][0]=='o');

    for(int i=1; i<n; i++)
      b[i][0] = b[i-1][0] + (board[i][0]=='o');

    for(int i=1; i<m; i++)
      b[0][i] = b[0][i-1] + (board[0][i]=='o');

    for(int i=1; i<n; i++)
    for(int j=1; j<m; j++)
      b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + (board[i][j]=='o');

    int minst = 1001;
    for(int i1=0; i1<n; i1++)
    for(int i2=0; i1+i2<n; i2++)
    for(int j1=0; j1<m; j1++)
    for(int j2=0; j1+j2<m; j2++)
    {
      int st = i1 + i2 + min(i1, i2);
      st += j1 + j2 + min(j1, j2);
      if( st<minst )
      {
        int coins = b[n-i2-1][m-j2-1];
        if( j1 ) coins -= b[n-i2-1][j1-1];
        if( i1 ) coins -= b[i1-1][m-j2-1];
        if( i1 && j1 ) coins += b[i1-1][j1-1];

        if( coins==K ) minst = min(minst, st);
      }
    }

    if( minst==1001 ) minst = -1;
    return minst;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	DropCoins ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
