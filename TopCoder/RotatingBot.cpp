// BEGIN CUT HERE
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not 
// display properly if viewed outside of the applet.
// 
// We had a rectangular grid that consisted of W x H square 
// cells.
// We placed a robot on one of the cells.
// The robot then followed the rules given below.
// 
// 
// Initially, the robot is facing east.
// The robot moves in steps. In each step it moves to the 
// adjacent cell in the direction it currently faces.
// The robot may not leave the grid.
// The robot may not visit the same cell twice. (This also 
// means that it may not reenter the starting cell.)
// If a step forward does not cause the robot to break the 
// above rules, the robot takes the step.
// Otherwise, the robot rotates 90 degrees to the left 
// (counter-clockwise) and checks whether a step forward 
// still breaks the above rules.
//   If not, the robot takes the step and continues executing 
// this program (still rotated in the new direction).
// If the rotation left did not help, the robot terminates 
// the execution of this program.
// We can also terminate the execution of the program 
// manually, at any moment.
// 
// For example, the following seven images show a series of 
// moves made by the robot in a 12 x 11 board:
// 
// 
// We forgot the dimensions of the grid and the original (x,
// y) coordinates of the cell on which the robot was 
// originally placed, but we do remember its movement. You 
// are given a vector <int> moves. This sequence of positive 
// integers shall be interpreted as follows:
// The robot performed moves[0] steps eastwards, turned left, 
// performed moves[1] steps northwards, turned left, and so on.
// After performing the last sequence of steps, the robot 
// stopped. (Either it detected that it should terminate, or 
// we stopped it manually.) We are not sure if the sequence 
// of moves is valid. If the sequence of moves is impossible, 
// return -1. Else, return the minimum area of a grid in 
// which the sequence of moves is possible.
// (I.e., the return value is the smallest possible value of 
// the product of W and H.).
// 
// DEFINITION
// Class:RotatingBot
// Method:minArea
// Parameters:vector <int>
// Returns:int
// Method signature:int minArea(vector <int> moves)
// 
// 
// CONSTRAINTS
// -moves will contain between 1 and 50 elements, inclusive.
// -Each element of moves will be between 1 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {15}
// 
// Returns: 16
// 
// The smallest valid board is a 16x1 board, with the robot 
// starting on the west end of the board.
// 
// 1)
// {3,10}
// 
// Returns: 44
// 
// The smallest solution is to place the robot into the 
// southwest corner of a 4 x 11 board.
// 
// 2)
// {1,1,1,1}
// 
// Returns: -1
// 
// This sequence of moves is not possible because the robot 
// would return to its initial location which is forbidden.
// 
// 3)
// {9,5,11,10,11,4,10}
// 
// Returns: 132
// 
// These moves match the image from the problem statement.
// 
// 4)
// {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}

// 
// Returns: 420
// 
// 5)
// {8,6,6,1}
// 
// Returns: -1
// 
// 
// 
// 6)
// {8,6,6}
// 
// Returns: 63
// 
// 
// 
// 7)
// {5,4,5,3,3}
// 
// Returns: 30
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

class RotatingBot {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, minArea(Arg0)); }
	void test_case_1() { int Arr0[] = {3,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(1, Arg1, minArea(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9,5,11,10,11,4,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 132; verify_case(3, Arg1, minArea(Arg0)); }
	void test_case_4() { int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420; verify_case(4, Arg1, minArea(Arg0)); }
	void test_case_5() { int Arr0[] = {8,6,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minArea(Arg0)); }
	void test_case_6() { int Arr0[] = {8,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(6, Arg1, minArea(Arg0)); }
	void test_case_7() { int Arr0[] = {5,4,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(7, Arg1, minArea(Arg0)); }

// END CUT HERE

	public: 

	int minArea(vector <int> m) {
      int x = 128, y = 128;
      int dir = 0;
      bool e[256][256];
      memset(e, 0, sizeof(e));
      e[y][x] = 1;

      bool sminx=0, smaxx=0, sminy=0, smaxy=0;
      int minx=x, maxx=x, miny=y, maxy=y;
      for(int i=0; i<m.size(); i++) {
         int newx=x, newy=y;
         switch(dir) {
         case 0:
            newx += m[i];
            for(int j=x+1; j<=newx; j++)
               if( e[y][j] ) return -1;
               else e[y][j] = 1;

            if( !smaxx ) maxx = newx, smaxx=1;
            else if( i+1<m.size() && newx!=maxx && e[y][newx+1]==0 ) return -1;
            break;

         case 1:
            newy += m[i];
            for(int j=y+1; j<=newy; j++)
               if( e[j][x] ) return -1;
               else e[j][x] = 1;

            if( !smaxy ) maxy = newy, smaxy=1;
            else if( i+1<m.size() && newy!=maxy && e[newy+1][x]==0 ) return -1;
            break;

         case 2:
            newx -= m[i];
            for(int j=x-1; j>=newx; j--)
               if( e[y][j] ) return -1;
               else e[y][j] = 1;

            if( !sminx ) {
               if( i+1<m.size() && minx<newx ) return -1;
               minx = min(minx, newx), sminx = 1;
            }
            else if( i+1<m.size() && minx!=newx  && e[y][newx-1]==0 ) return -1;
            break;

         default:
            newy -= m[i];
            for(int j=y-1; j>=newy; j--)
               if( e[j][x] ) return -1;
               else e[j][x] = 1;

            if( !sminy ) {
               if( i+1<m.size() && (miny+1<newy || (miny<newy && x!=128)) ) return -1;
               miny = min(miny, newy), sminy=1;
            }
            else if( i+1<m.size() && miny!=newy && e[newy-1][x]==0  ) return -1;
            break;
         }
         dir = (dir+1)%4;

         x = newx, y = newy;
      }
      if( x<minx || x>maxx || y<miny || y>maxy ) return -1;
      
      return (maxx-minx+1) * (maxy-miny+1);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	RotatingBot ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
