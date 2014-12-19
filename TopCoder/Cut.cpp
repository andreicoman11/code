// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel wants to eat eels as a celebration of this year's 
// end.
// 
// Initially, Ciel has some eels of various lengths. She only 
// likes to eat eels of length exactly 10, no more, no less.
// Before she eats, she may cut the eels to prepare pieces of 
// desired length. However, she only has the time to make at 
// most maxCuts cuts. A single cut looks as follows:
// 
// Fox Ciel chooses one of the eels. Let its length be x. She 
// can only choose an eel of length greater than 1.
// She chooses an integer y such that 0 < y < x.
// She cuts the eel into two pieces so that one of them 
// measures exactly y.
// In other words, instead of one eel of length x she now has 
// two eels of lengths y and (x-y), respectively.
// 
// 
// You are given a vector <int> eelLengths. Each element of 
// eelLengths is the length of one of the eels Ciel has at 
// the beginning.
// You are also given the int maxCuts.
// Return the maximum number of eels of length exactly 10 she 
// can produce.
// 
// DEFINITION
// Class:Cut
// Method:getMaximum
// Parameters:vector <int>, int
// Returns:int
// Method signature:int getMaximum(vector <int> eelLengths, 
// int maxCuts)
// 
// 
// CONSTRAINTS
// -eelLengths will contain between 1 and 50 elements, 
// inclusive.
// -Each element of eelLengths will be between 1 and 1,000, 
// inclusive.
// -maxCuts will be between 1 and 1,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {13, 20, 13}
// 2
// 
// Returns: 3
// 
// One optimal solution looks as follows:
// 
// First, cut eel 0 into two pieces of lengths 10 and 3. 
// Next, cut eel 1 into two equal parts of length 10 each. 
// This produces a total of 3 eels whose length is 10.
// 
// 
// 
// 1)
// {5, 5, 5, 5}
// 2
// 
// Returns: 0
// 
// There are four eels whose length is 5.
// As you cannot combine eels, it is impossible to make an 
// eel of length 10.
// 
// 2)
// {34, 10, 48}
// 4
// 
// Returns: 5
// 
// She already has one eel of length 10. By cutting the other 
// two eels she can produce four more eels of the desired 
// length.
// 
// 3)
// {30, 50, 30, 50}
// 350
// 
// Returns: 16
// 
// She may cut eels at most 350 times, but in this case she 
// doesn't have to cut them so many times.
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
class Cut {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {13, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {34, 10, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {30, 50, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 350; int Arg2 = 16; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

	public: int getMaximum(vector <int> eels, int cuts) {
		multiset<int> e1, e2;
      for(int i=0; i<eels.size(); i++)
         if( eels[i]%10==0 ) e1.insert(eels[i]);
         else if( eels[i]>10 ) e2.insert(eels[i]);

      int eres = 0;
      for(multiset<int>::iterator it=e1.begin(); cuts && it!=e1.end(); it++)
         if( (*it)/10-1 <= cuts )
         {
            eres += (*it)/10;
            cuts -= (*it)/10 - 1;
         } else {
            eres += cuts;
            cuts = 0;
         }

      for(multiset<int>::iterator it=e2.begin(); cuts && it!=e2.end(); it++)
         if( (*it)/10 <= cuts )
         {
            eres += (*it)/10;
            cuts -= (*it)/10;
         }
         else
         {
            eres += cuts;
            cuts = 0;
         }
      return eres;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	Cut ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
