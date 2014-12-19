// BEGIN CUT HERE
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not 
// display properly if viewed outside of the applet.
// 
// Cat Taro has the following building blocks:
// 
// cubes[0] red unit cubes,
// cubes[1] yellow unit cubes,
// cubes[2] blue unit cubes,
// B black rectangular prisms with dimensions 2x1x1.
// 
// 
// Cat Taro is using the blocks to build w adjacent towers of 
// blocks (some possibly empty), as shown on the right side 
// of the picture below. Taro will always place the 
// rectangular prisms vertically. In other words, each prism 
// will look like two black unit cubes placed one on top of 
// the other. Taro is not required to use all of the blocks 
// when building the towers. (In fact, he may even decide not 
// to use any blocks at all.)
// 
//  
// 
// Rabbit Hanako is looking at Taro's towers from the left 
// side of the room. To him, the towers seem as a single 
// tower which we will call a view, as shown on the left side 
// of the picture above. More precisely, at each height i 
// Hanako sees the color of the block at height i in the 
// leftmost tower that has such a block. Hanako's view can be 
// described as a string of characters, giving the colors of 
// each 1x1 square seen by Hanako in the order from bottom to 
// top.
// Black squares will be denoted 'b', and colored squares 
// will be denoted '0', '1', and '2' (in the same order used 
// in cubes).
// 
// You are given the vector <int> cubes, the int B, the int 
// w, and a vector <string> views.
// Each element of views specifies one view Taro wants Hanako 
// to see, in the format specified above.
// Return a vector <string> with the same number of elements 
// as views.
// If Taro can build the towers in such a way that Hanako 
// will see the view views[i], the i-th element of the return 
// value should be "valid", otherwise it should be "invalid" 
// (quotes for clarity).
// 
// DEFINITION
// Class:SkewedPerspectives
// Method:areTheyPossible
// Parameters:vector <int>, int, int, vector <string>
// Returns:vector <string>
// Method signature:vector <string> areTheyPossible(vector 
// <int> cubes, int B, int w, vector <string> views)
// 
// 
// CONSTRAINTS
// -w will be between 1 and 50, inclusive.
// -cubes will contain exactly 3 elements.
// -Each element of cubes will be between 0 and 100, inclusive.
// -B will be between 0 and 100, inclusive.
// -views will contain between 1 and 50 elements, inclusive.
// -Each element of views will contain between 1 and 50 
// characters, inclusive.
// -Each character in each element of views will be one of 
// 'b', '0', '1', and '2'.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1,1}
// 1
// 2
// { "012", "012bb", "bb0", "21bb", "21b", "1bb20" }
// 
// Returns: {"valid", "valid", "valid", "valid", "valid", 
// "valid" }
// 
// The following picture shows a way to achieve each of the 
// given views.
// 
// 
// 1)
// {0,1,0}
// 3
// 2
// {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
//  "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
//  "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
//  "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
//  "bbb1","bbb1b","bbb1bb","bbb1bbb",
//  "bbbb1","bbbb1b","bbbb1bb",
//  "bbbbb1","bbbbb1b",
//  "bbbbbb1" }
// 
// Returns: {"invalid", "valid", "valid", "valid", "valid", 
// "valid", "valid", "valid", "valid", "valid", "valid", 
// "valid", "valid", "invalid", "invalid", "invalid", 
// "invalid", "invalid", "invalid", "valid", "valid", 
// "valid", "invalid", "valid", "invalid", "invalid", 
// "invalid", "invalid", "valid", "invalid", "valid", 
// "invalid", "invalid", "valid" }
// 
// 
// 
// 2)
// {100,0,0}
// 20
// 3
// {"00000000000000000000000000000000000000000000000000",
//  "00000000000000000000000000000000000b00000000000000",
//  "0000000000000000000000000000000000000000000000000b",
//  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}
// 
// Returns: {"valid", "valid", "valid", "valid" }
// 
// 
// 
// 3)
// {5,6,3}
// 0
// 1
// {"00000111111222", "0000111111222", "0000011111222", 
// "000001111111222", "0000011111122", "b"}
// 
// Returns: {"valid", "valid", "valid", "invalid", "valid", 
// "invalid" }
// 
// 
// 
// 4)
// {100,100,100}
// 100
// 50
// {"2",
//  "bb1b012012012012012012012",
//  "bb1b012012012012012012012b",
//  "bb1b012012012b012b012b012012b",
//  "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
//  "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
//  "bbb1b012012012012012012012"
// }
// 
// Returns: {"valid", "valid", "valid", "valid", "valid", 
// "invalid", "valid" }
// 
// 
// 
// 5)
// {0,0,0}
// 0
// 1
// {"0", "bb"}
// 
// Returns: {"invalid", "invalid" }
// 
// Taro has no cubes and no prisms, therefore he cannot 
// create any non-empty view.
// 
// 6)
// {3,0,0}
// 4
// 3
// {"00b0b", "bbbbbbbb", "000b"}
// 
// Returns: {"invalid", "valid", "valid" }
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

class SkewedPerspectives {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arr3[] = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; string Arr3[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 3; string Arr3[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5,6,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 50; string Arr3[] = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"0", "bb"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; string Arr3[] = {"00b0b", "bbbbbbbb", "000b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
	public: 
   bool isPossible(vector<int> c, int b, int w, string p) {
      if( p[0]=='b' && ( p.size()<2 || p[1]!='b') ) return 0;
      
      for(int i=0; i<p.size(); i++)
         if( isdigit(p[i]) )
            c[ int(p[i])-int('0') ]--;

      if( c[0]<0 || c[1]<0 || c[2] <0 ) return 0;
      c[0] += c[1] + c[2];
      vector<int> left;

      for(int i=0; i<p.size(); i++)
         if( p[i]=='b' )
         {
            int j = i+1;
            while( j<p.size() && p[j]=='b' ) j++;
            b -= (j-i+1)/2;
            if( (j-i)%2 )
            {
               w--;
               if( i>0 ) left.pb(i-1-((i-1)%2)), c[0]-=(i-1)%2;
               else      c[0]--;
            }
            i = j;
         }

      if( (w<1) || (b<0) || (c[0]<0) ) return 0;

      for(int i=0; i<left.size(); i++)
         if( b*2>=left[i] ) b -= left[i]/2;
         else {left[i] -= b*2; b=0; c[0] -= left[i]; }

      return (w>=1) && (b>=0) && (c[0]>=0);

   }
	vector <string> areTheyPossible(vector <int> cubes, int B, int W, vector <string> views) {
      vector<string> res;
      string ans[2] = {"invalid", "valid"};
		for(int i=0; i<views.size(); i++)
         res.pb( ans[isPossible(cubes, B, W, views[i])] );
      return res;
   }
	
};

// BEGIN CUT HERE 
int main()
{
	SkewedPerspectives ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
