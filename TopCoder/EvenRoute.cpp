// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel has stumbled upon a new problem: In this problem 
// you will visit some points with integer coordinates in the 
// Cartesian plane. Initially, you are located at the point 
// (0,0). In each step, you can move from your current point 
// to one of the four directly adjacent points.
// I.e., if you are at (x,y), you can move to one of the 
// points (x,y+1), (x,y-1), (x+1,y), and (x-1,y).
// 
// You are given two vector <int>s x and y, each containing N 
// elements.
// Together, x and y describe N distinct points in the 
// Cartesian plane:
// for 0 <= i < N, point i has the coordinates (x[i],y[i]).
// 
// The goal is to find a sequence of steps that satisfies the 
// following criteria:
// The starting point is (0,0).
// The sequence visits each of the N given points at least 
// once.
// The sequence finishes in one of the given points.
// 
// 
// Mr. K claims to have solved this problem but Ciel does not 
// believe him. Ciel has prepared a method to verify Mr. K's 
// claims. Given an int wantedParity, the parity of the 
// number of steps in the sequence found by Mr. K, Ciel will 
// find if it is possible to find a sequence that follows the 
// previously mentioned conditions and a new one:
// 
// The parity of the total number of steps is wantedParity. 
// In other words, if wantedParity=0 then the total number of 
// steps must be even, and if wantedParity=1 then the total 
// number of steps must be odd.
// 
// 
// Return "CAN" (quotes for clarity) if at least one such 
// sequence of steps exists, and "CANNOT" otherwise.
// 
// DEFINITION
// Class:EvenRoute
// Method:isItPossible
// Parameters:vector <int>, vector <int>, int
// Returns:string
// Method signature:string isItPossible(vector <int> x, 
// vector <int> y, int wantedParity)
// 
// 
// CONSTRAINTS
// -wantedParity will be 0 or 1.
// -x will contain between 1 and 50 elements, inclusive.
// -y will contain the same number of elements as x.
// -Each element of x and y will be between -1000000 and 
// 1000000, inclusive.
// -No point in the input will be equal to (0,0).
// -No pair of points in the input will be equal.
// 
// 
// EXAMPLES
// 
// 0)
// {-1,-1,1,1}
// {-1,1,1,-1}
// 0
// 
// Returns: "CAN"
// 
// A possible sequence containing an even number of steps:
// 2 steps: (0,0) -> (-1,-1).
// 2 steps: (-1,-1) -> (-1,1).
// 2 steps: (-1,1) -> (1,1).
// 2 steps: (1,1) -> (1,-1).
// 
// 
// 1)
// {-5,-3,2}
// {2,0,3}
// 1
// 
// Returns: "CAN"
// 
// A possible sequence containing an odd number of steps:
// 
// 7 steps: (0,0) -> (-5,2).
// 4 steps: (-5,2) -> (-3,0).
// 8 steps: (-3,0) -> (2,3).
// 
// 
// 
// 2)
// {1001, -4000}
// {0,0}
// 1
// 
// Returns: "CAN"
// 
// The shortest sequence that visits all the given points is 
// the sequence that first goes to (1001,0) and then to 
// (-4000,0).
// Note that this sequence does not have an odd amount of 
// steps.
// However, there is a longer sequence with an odd number of 
// steps: (0,0) -> (-4000,0) -> (1001, 0).
// 
// 3)
// {11, 21, 0}
// {-20, 42, 7}
// 0
// 
// Returns: "CANNOT"
// 
// 
// 
// 4)
// {0, 6}
// {10, -20}
// 1
// 
// Returns: "CANNOT"
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

class EvenRoute {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,1,1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; string Arg3 = "CAN"; verify_case(0, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-5,-3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "CAN"; verify_case(1, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1001, -4000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "CAN"; verify_case(2, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {11, 21, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-20, 42, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; string Arg3 = "CANNOT"; verify_case(3, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, -20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "CANNOT"; verify_case(4, Arg3, isItPossible(Arg0, Arg1, Arg2)); }

// END CUT HERE
   public: 
	string isItPossible(vector <int> x, vector <int> y, int par) {
      bool i=0, p=0;
      for(int j=0; j<x.size(); j++)
         if( abs(x[j]+y[j]) %2==1 ) i=1;
         else p = 1;
      
      if( par==0 && p==0 ) return "CANNOT";
      if( par==1 && i==0 ) return "CANNOT";
      return "CAN";
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EvenRoute ___test; 
	___test.run_test(-1); 
   int a[] = {573168, -848684, 699789, -826237, 649131, -383443, 58647, -386236, 781603, -754143, -977572, -752562, 318572, 440256, -450242, -644763, 36812, -839786, 110128, -74869, 866327, 397421, -474463, 535111, 696818, -635512};
   int b[] = {-999357, 127343, 889616, 894792, -336726, -736954, -95930, 119968, -298338, 864104, -120527, 248194, 853669, 297041, -290623, 446904, 430768, 56630, -279631, -390020, -691700, -876047, -626545, -518345, 670420, 845927};
   vector<int> va(a, a+26);
   vector<int> vb(b, b+26);
   cout << ___test.isItPossible(va, vb, 1);

	
} 
// END CUT HERE
