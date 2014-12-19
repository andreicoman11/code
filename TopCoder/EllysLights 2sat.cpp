// BEGIN CUT HERE
// PROBLEM STATEMENT
// Elly's house has a number of light bulbs. Some of them are 
// turned on, some of them are not. She wants to switch all 
// of them off for the upcoming Earth Hour.
// 
// Unfortunately, her house has a strange system of light 
// switches. Each switch changes the state of some of the 
// bulbs (possibly none or all of them). This means that if 
// she uses the switch, all bulbs that are connected to it go 
// off if they were on, and go on if they were off. She also 
// knows that each bulb is connected to at most two switches. 
// Help Elly determine what is the minimal number of switches 
// she must use in order to turn off all the lights.
// 
// You are given a string initial and a vector <string> 
// switches. Each character in initial represents one light 
// bulb: if the i-th light bulb (0-based index) is initially 
// on, the i-th character of initial is 'Y', otherwise it is 
// 'N'. Each element of switches represents one switch: if 
// the i-th switch toggles the j-th light bulb, switches[i]
// [j] is 'Y', otherwise it is 'N'.
// 
// Find and return the smallest nonnegative integer X such 
// that there is a sequence of X switches such that if Elly 
// toggles those switches in the given order, all light bulbs 
// will be turned off at the end. If no such X exists, return 
// -1.
// 
// DEFINITION
// Class:EllysLights
// Method:getMinimum
// Parameters:string, vector <string>
// Returns:int
// Method signature:int getMinimum(string initial, vector 
// <string> switches)
// 
// 
// NOTES
// -It is possible that none or all of the bulbs are turned 
// on initially.
// -Elly is allowed to toggle the same switch more than once.
// 
// 
// CONSTRAINTS
// -initial will contain between 1 and 50 characters, 
// inclusive.
// -Each character of initial will be either 'Y' or 'N'.
// -switches will contain between 1 and 50 elements, inclusive.
// -Each element of switches will contain the same number of 
// characters as initial.
// -Each character of each element of switches will be either 
// 'Y' or 'N'.
// -For each index of initial there will be at most two 
// elements of switches that will have 'Y' at that index.
// 
// 
// EXAMPLES
// 
// 0)
// "YNYNNN"
// {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"}
// 
// Returns: 2
// 
// There are multiple ways how to turn off all the lights.
// For example, she can first use switch 0, then switch 4, 
// and finally switch 1.
// The shortest solutions only use two switches.
// For example, it is enough to flip the switch 2 followed by 
// the switch 3.
// 
// 1)
// "YNYNYN"
// {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"}
// 
// Returns: 4
// 
// Some of the switches might change the state of none or all 
// of the bulbs. Some of the bulbs might be influenced by 
// less than 2 switches.
// 
// 
// 2)
// "YYN"
// {"YNY", "NYN"}
// 
// Returns: -1
// 
// Sometimes there might be no way to switch off all the 
// bulbs. In this case return -1.
// 
// 
// 3)
// "NNYNYNYYYNNYYYYN"
// {"NYNYNYNYNYNYNYNY",
//  "YNYNYNYNYNYNYNYN",
//  "NNNNNNNNNNNNNNNN",
//  "YNNNNNNNNNNNNNNN",
//  "NYNNNNNNNNNNNNNN",
//  "NNYNNNNNNNNNNNNN",
//  "NNNYNNNNNNNNNNNN",
//  "NNNNYNNNNNNNNNNN",
//  "NNNNNYNNNNNNNNNN",
//  "NNNNNNYNNNNNNNNN",
//  "NNNNNNNYNNNNNNNN",
//  "NNNNNNNNYNNNNNNN",
//  "NNNNNNNNNYNNNNNN",
//  "NNNNNNNNNNYNNNNN",
//  "NNNNNNNNNNNYNNNN",
//  "NNNNNNNNNNNNYNNN",
//  "NNNNNNNNNNNNNYNN",
//  "NNNNNNNNNNNNNNYN",
//  "NNNNNNNNNNNNNNNY"}
// 
// Returns: 6
// 
// There are 9 lit bulbs initially. We can turn them off one 
// by one, but it will be faster to use one of the complex 
// switches and then to toggle the ones that are still lit.
// 
// 4)
// "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY"
// {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
//  "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
//  "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
//  "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
//  "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
//  "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
//  "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
//  "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
//  "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
//  "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
//  "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
//  "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
//  "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"}
// 
// Returns: 7
// 
// 
// 
// 5)
// "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN"
// {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
//  "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
//  "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
//  "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
//  "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
//  "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
//  "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
//  "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
//  "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
//  "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
//  "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
//  "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
//  "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
//  "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
//  "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
//  "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
//  "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
//  "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"}
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

class EllysLights {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYNNN"; string Arr1[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "YNYNYN"; string Arr1[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "YYN"; string Arr1[] = {"YNY", "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "NNYNYNYYYNNYYYYN"; string Arr1[] = {"NYNYNYNYNYNYNYNY",
 "YNYNYNYNYNYNYNYN",
 "NNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNN",
 "NNNNYNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNN",
 "NNNNNNYNNNNNNNNN",
 "NNNNNNNYNNNNNNNN",
 "NNNNNNNNYNNNNNNN",
 "NNNNNNNNNYNNNNNN",
 "NNNNNNNNNNYNNNNN",
 "NNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNYN",
 "NNNNNNNNNNNNNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
 "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
 "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
 "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
 "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
 "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
 "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
 "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

	public: 
	int getMinimum(string init, vector <string> sw) {
		int n = sw.size() * 2;
      bool use[128];      
      bool e[128][128];
      memset(use, 0, sizeof(use));
      memset(e, 0, sizeof(e));

      for(int i=0; i<init.size(); i++)
      {
         int swi[2], swn = 0;
         for(int j=0; j<sw.size(); j++)
            if( sw[j][i]=='Y' ) {
               swi[swn++] = j*2;
            }
         switch(swn) {
         case 0:
            if( init[i]=='Y' ) return -1;
            break;
         case 1:
            // use only if light is on
            use[ (init[i]=='Y') ? swi[0] : swi[0]+1 ] = 1;
            break;
         case 2:
            if( init[i]=='Y' ) {
               // use one light
               e[swi[0]+1][swi[1]] = e[swi[1]][swi[0]+1] = 1;
               e[swi[1]+1][swi[0]] = e[swi[0]][swi[1]+1] = 1;
            } else {
               e[swi[0]][swi[1]] = e[swi[1]][swi[0]] = 1;
               e[swi[0]+1][swi[1]+1] = e[swi[1]+1][swi[0]+1] = 1;
            }
            break;
         default:
            break;
            // error
         }
      }

      // get all possible paths
      for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
         if( e[i][k] && e[k][j] ) e[i][j] = 1;

      // check for switch, non-switch in same component
      for(int i=0; i<n; i+=2 )
         if( e[i][i+1] && e[i+1][i] ) return -1;

      // find all switches that have to be used
      for(int i=0; i<n; i++)
         if( use[i] )
            for(int j=0; j<n; j++)
               if( e[i][j] ) use[j] = 1;

      // find if switch, non-switch have to be used
      for(int i=0; i<n; i+=2 )
         if( use[i] && use[i+1] ) return -1;

      for(int i=0; i<n; i+=2)
         if( !use[i] && !use[i+1] ) {
            int cnt1=0, cnt2=0;
            for(int j=0; j<n; j++) {
               if( e[i][j] ) cnt1 += 1 - (j&1);
               if( e[i+1][j] ) cnt2 += 1 - (j&1);
            }

            for(int j=0; j<n; j++) {
               if( cnt1<cnt2 && e[i][j] ) use[j] = 1;
               if( cnt2<=cnt1 && e[i+1][j] ) use[j] = 1;
            }
         }

      int res = 0;
      for(int i=0; i<n; i+=2 )
         if( use[i] ) res++;
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EllysLights ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
