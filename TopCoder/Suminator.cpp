// BEGIN CUT HERE
// PROBLEM STATEMENT
// Suminator is a very limited programming language.
// A program in this language is simply a sequence of 
// nonnegative integers.
// The program is evaluated using a stack of nonnegative 
// integers.
// Initially, the stack is empty.
// Trying to pop an element from an empty stack returns a zero.
// (Alternately, you can imagine that the stack already 
// contains a sufficient number of zeros in the beginning.)
// 
// A Suminator program is evaluated using the following 
// algorithm:
// 
// for i = 0 to length(program) - 1 {
//     if ( program[i] is 0) {
//          Pop the top two elements from the stack, add them 
// together
//          and push the result to the top of the stack.
//     } else {
//          Push program[i] to the top of the stack.
//     }
// }
// Pop the top element of the stack and print it.
// 
// For example, when executing the program {1}, we first push 
// the 1 to the stack, and then we print it. 
// When executing the program {5,0,1,2,0}, we take the 
// following steps:
// 
// We push the 5 to the top of the stack.
// We pop the top two elements (5 and 0), add them together 
// and push the result (5).
// We push the 1 to the top of the stack.
// We push the 2 to the top of the stack. At this moment, the 
// stack contains the values 5, 1, and 2 (from bottom to top).
// We pop the top two elements (2 and 1), add them together 
// and push the result (3).
// We print the top element of the stack: the number 3. Note 
// that the stack also contains the value 5, which is ignored.
// 
// 
// You are given a vector <int> program containing a 
// Suminator program (a sequence of nonnegative integers), in 
// which one of the elements of the sequence was changed to -1.
// You are also given a int wantedResult.
// Your task is to change the -1 back to a nonnegative 
// integer X in such a way that the resulting program prints 
// the number wantedResult.
// Return X.
// If there are multiple possible values of X, return the 
// smallest one.
// If there is no way to make the program print wantedResult, 
// return -1 instead.
// 
// DEFINITION
// Class:Suminator
// Method:findMissing
// Parameters:vector <int>, int
// Returns:int
// Method signature:int findMissing(vector <int> program, int 
// wantedResult)
// 
// 
// NOTES
// -The return value always fits into an int. This follows 
// from the constraints and the nature of the problem.
// 
// 
// CONSTRAINTS
// -program will contain between 1 and 50 elements, inclusive.
// -Each element of program will be between -1 and 1000000000 
// (10^9), inclusive.
// -program will contain -1 exactly once.
// -wantedResult will be between 1 and 1000000000 (10^9), 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {7,-1,0}
// 10
// 
// Returns: 3
// 
// 
// 
// 1)
// {100, 200, 300, 0, 100, -1}
// 600
// 
// Returns: 0
// 
// 
// 
// 2)
// {-1, 7, 3, 0, 1, 2, 0, 0}
// 13
// 
// Returns: 0
// 
// We can replace the first element with many other values, 
// but 0 is the smallest that achieves the wanted result.
// 
// 3)
// {-1, 8, 4, 0, 1, 2, 0, 0}
// 16
// 
// Returns: -1
// 
// It does not matter what value we use in the first element 
// of the array, the result will always be 15.
// 
// 4)
// {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 
// 0, 0, 0}
// 1000000000
// 
// Returns: -1
// 
// It does not matter what we replace the -1 with, the result 
// will be larger than 1000000000.
// 
// 5)
// {7, -1, 3, 0}
// 3
// 
// Returns: -1
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

int pos;
vector<LL> p;

LL getnr() {
   if(pos<0) return 0;
   if( p[pos]!=0 ) return p[pos];

   pos--;
   LL nr1 = getnr();
   pos--;
   LL nr2 = getnr();
   return nr1 + nr2;
}

class Suminator {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE

	public: 
	int findMissing(vector <int> _p, int w) {
      p.resize(_p.size());
      for(int i=0; i<_p.size(); i++)
         p[i] = _p[i];

		pos = p.size()-1;
      int pos1;
      for(int i=0; i<p.size(); i++)
         if( p[i]==-1 ) pos1 = i, p[i] = 0;

      LL rez = getnr();
      if( rez==w ) return 0;

      p[pos1] = 1;
      pos = p.size() - 1;
      rez = getnr();

      if( rez<=w && pos<=pos1 ) return w-rez+1;
      if( rez==w ) return 1;
      return -1;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	Suminator ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
