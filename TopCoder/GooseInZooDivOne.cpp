// BEGIN CUT HERE
// PROBLEM STATEMENT
// Crow Keith is looking at the goose cage in the zoo.
// The bottom of the cage is divided into a grid of square 
// cells.
// There are some birds sitting on those cells (with at most 
// one bird per cell).
// Some of them are geese and all the others are ducks.
// 
// Keith wants to know which birds are geese.
// He knows the following facts about them:
// 
// There is at least one goose in the cage.
// The number of geese is even.
// Each bird within Manhattan distance dist of any goose is 
// also a goose.
// 
//  
// You are given a vector <string> field and the int dist.
// The array field describes the bottom of the cage.
// Each character of each element of field describes one of 
// the cells.
// The meaning of individual characters follows.
// 
// The character 'v' represents a cell that contains a bird.
// The character '.' represents an empty cell.
// 
// 
// Return the number of possible sets of geese in the cage, 
// modulo 1,000,000,007.
// Note that for some of the test cases there can be no 
// possible sets of geese.
// 
// DEFINITION
// Class:GooseInZooDivOne
// Method:count
// Parameters:vector <string>, int
// Returns:int
// Method signature:int count(vector <string> field, int dist)
// 
// 
// NOTES
// -The Manhattan distance between cells (a,b) and (c,d) is 
// |a-c| + |b-d|, where || denotes absolute value. In words, 
// the Manhattan distance is the smallest number of steps 
// needed to get from one cell to the other, given that in 
// each step you can move to a cell that shares a side with 
// your current cell.
// 
// 
// CONSTRAINTS
// -field will contain between 1 and 50 elements, inclusive.
// -Each element of field will contain between 1 and 50 
// characters, inclusive.
// -Each element of field will contain the same number of 
// characters.
// -Each character of each element of field will be 'v' or '.'.
// -dist will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"vvv"}
// 0
// 
// Returns: 3
// 
// There are three possible sets of positions of geese: 
// "ggd", "gdg", or "dgg" ('g' are geese and 'd' are ducks).
// 
// 1)
// {"."}
// 100
// 
// Returns: 0
// 
// The number of geese must be positive, but there are no 
// birds in the cage.
// 
// 2)
// {"vvv"}
// 1
// 
// Returns: 0
// 
// 
// 
// 3)
// {"v.v..................v............................"
// ,".v......v..................v.....................v"
// ,"..v.....v....v.........v...............v......v..."
// ,".........vvv...vv.v.........v.v..................v"
// ,".....v..........v......v..v...v.......v..........."
// ,"...................vv...............v.v..v.v..v..."
// ,".v.vv.................v..............v............"
// ,"..vv.......v...vv.v............vv.....v.....v....."
// ,"....v..........v....v........v.......v.v.v........"
// ,".v.......v.............v.v..........vv......v....."
// ,"....v.v.......v........v.....v.................v.."
// ,"....v..v..v.v..............v.v.v....v..........v.."
// ,"..........v...v...................v..............v"
// ,"..v........v..........................v....v..v..."
// ,"....................v..v.........vv........v......"
// ,"..v......v...............................v.v......"
// ,"..v.v..............v........v...............vv.vv."
// ,"...vv......v...............v.v..............v....."
// ,"............................v..v.................v"
// ,".v.............v.......v.........................."
// ,"......v...v........................v.............."
// ,".........v.....v..............vv.................."
// ,"................v..v..v.........v....v.......v...."
// ,"........v.....v.............v......v.v............"
// ,"...........v....................v.v....v.v.v...v.."
// ,"...........v......................v...v..........."
// ,"..........vv...........v.v.....................v.."
// ,".....................v......v............v...v...."
// ,".....vv..........................vv.v.....v.v....."
// ,".vv.......v...............v.......v..v.....v......"
// ,"............v................v..........v....v...."
// ,"................vv...v............................"
// ,"................v...........v........v...v....v..."
// ,"..v...v...v.............v...v........v....v..v...."
// ,"......v..v.......v........v..v....vv.............."
// ,"...........v..........v........v.v................"
// ,"v.v......v................v....................v.."
// ,".v........v................................v......"
// ,"............................v...v.......v........."
// ,"........................vv.v..............v...vv.."
// ,".......................vv........v.............v.."
// ,"...v.............v.........................v......"
// ,"....v......vv...........................v........."
// ,"....vv....v................v...vv..............v.."
// ,".................................................."
// ,"vv........v...v..v.....v..v..................v...."
// ,".........v..............v.vv.v.............v......"
// ,".......v.....v......v...............v............."
// ,"..v..................v................v....v......"
// ,".....v.....v.....................v.v......v......."}
// 3
// 
// Returns: 898961330
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

class GooseInZooDivOne {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 898961330; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

	public: 
   bool within(int dist, int x, int y, int i, int j) {
      return abs(x-i) + abs(y-j) <= dist;
   }

	int count(vector <string> f, int dist) {
      const long long mod = 1000000007LL;

      bool check[2505];
      vector<pair<int, int> > v;
      memset(check, 0, sizeof(check));

      for(int i=0; i<f.size(); i++)
      for(int j=0; j<f[i].size(); j++)
         if( f[i][j]=='v' ) 
            v.push_back(make_pair(i, j));
      
      long long odd = 0, even = 0;
      for(int i=0; i<v.size(); i++) 
         if( !check[i] ) {
            int sno = 0;
            check[i] = 1;
            queue<pair<int, int> > q;
            q.push(make_pair(v[i].first, v[i].second));
            while( !q.empty() ) {
               int x = q.front().first;
               int y = q.front().second;
               sno++;
               q.pop();
               for(int j=i; j<v.size(); j++)
                  if( !check[j] && within(dist, x, y, v[j].first, v[j].second)) {
                     check[j] = 1;
                     q.push(make_pair(v[j].first, v[j].second));
                  }
            }
            if( sno%2 ) odd++;
            else even++;
         }
      
		long long res = 1LL;
      for(int i=0; i<(int)even; i++)
         res = (res + res) % mod;
      
      for(int i=1; i<(int)odd; i++)
         res = (res + res) % mod;
         

      return (int)((res + mod - 1) % mod);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	GooseInZooDivOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
