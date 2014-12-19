// BEGIN CUT HERE
// PROBLEM STATEMENT
// Your friend the farmer liked to use the following method 
// to count the number of beavers and ducks present on the 
// farm: He would first find three ints webbedFeet, duckBills 
// and beaverTails, representing  the number of webbed feet, 
// duck bills and beaver tails he could count and then he 
// used those numbers to find the number of ducks and beavers 
// on the farm. (A duck has one duck bill and two webbed 
// feet. A beaver has one beaver tail and four webbed feet.)
// 
// The method worked great until he received news that there 
// could be a platypus invasion on the farm. A platypus is a 
// marvellous creature that has 4 webbed feet, a duck bill 
// and a beaver tail. Our farmer is justifiably confused. 
// Help him find out that his method is still useful. You are 
// given ints webbedFeet, duckBills and beaverTails that 
// specify the number of webbed feet, duck bills and beaver 
// tails  the farmer has counted, respectively. Return the 
// total number of animals (ducks, beavers, and platypuses) 
// on the farm. The constraints guarantee that there will be 
// exactly one solution.
// 
// DEFINITION
// Class:PlatypusDuckAndBeaver
// Method:minimumAnimals
// Parameters:int, int, int
// Returns:int
// Method signature:int minimumAnimals(int webbedFeet, int 
// duckBills, int beaverTails)
// 
// 
// CONSTRAINTS
// -webbedFeet, duckBills and beaverTails will each be 
// between 0 and 1000, inclusive.
// -There will be exactly one way to assign the number of 
// ducks, beavers and platypuses such that the total number 
// of each specific kind of body part matches webbedFeet, 
// duckBills and beaverTails, respectively.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// 1
// 1
// 
// Returns: 1
// 
// If there is only one platypus, it will have 4 webbed feet, 
// 1 beaver tail and 1 duck bill. Matching the description.
// 
// 1)
// 0
// 0
// 0
// 
// Returns: 0
// 
// 
// 
// 2)
// 10
// 2
// 2
// 
// Returns: 3
// 
// One platypus, one duck and one beaver.
// 
// 3)
// 60
// 10
// 10
// 
// Returns: 20
// 
// 10 ducks and 10 beavers.
// 
// 4)
// 1000
// 200
// 200
// 
// Returns: 300
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

class PlatypusDuckAndBeaver {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 2; int Arg3 = 3; verify_case(2, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 60; int Arg1 = 10; int Arg2 = 10; int Arg3 = 20; verify_case(3, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 200; int Arg2 = 200; int Arg3 = 300; verify_case(4, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
	int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
		for(int i=0; i*4<=webbedFeet; i++) {
         int d = duckBills - i;
         int b = beaverTails - i;
         if( webbedFeet == i*4 + d*2 + b*4 )
            return i + d + b;
      }
      return 0;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PlatypusDuckAndBeaver ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
