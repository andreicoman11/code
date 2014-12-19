// BEGIN CUT HERE
// PROBLEM STATEMENT
// A kingdom has n citizens. Each one has some amount of 
// money, a number of dollars denoted by a non-negative 
// integer.
// 
// Citizens are numbered from 0 to n-1. Some citizens have 
// friends. Their friendship network is described by a vector 
// <string> called isFriend, such that if isFriend[i][j] == 
// 'Y', the citizens numbered i and j are friends, and if 
// isFriend[i][j] == 'N', these citizens are not friends.
// 
// The king decrees the following:
// 
// Each citizen's amount of money must be within d dollars of 
// the amount of money belonging to any of his friends. In 
// other words, a citizen with x dollars must not have any 
// friends with less than x-d dollars or more than x+d dollars.
// 
// Given the number of citizens and their friendship network, 
// what is the greatest possible money difference between any 
// two people (not necessarily friends) in this kingdom? If 
// there is a finite answer, return it. Otherwise, return -1.
// 
// DEFINITION
// Class:Egalitarianism
// Method:maxDifference
// Parameters:vector <string>, int
// Returns:int
// Method signature:int maxDifference(vector <string> 
// isFriend, int d)
// 
// 
// CONSTRAINTS
// -n will be between 2 and 50, inclusive.
// -d will be between 0 and 1,000, inclusive.
// -isFriend will contain exactly n elements.
// -Each element of isFriend will contain exactly n 
// characters, each of which is either 'Y' or 'N'.
// -For any i, isFriend[i][i] = 'N'.
// -For any i and j, isFriend[i][j] = isFriend[j][i].
// 
// 
// EXAMPLES
// 
// 0)
// {"NYN",
//  "YNY",
//  "NYN"}
// 10
// 
// Returns: 20
// 
// The kingdom has three citizens. Citizens 0 and 1 are 
// friends. Also, citizens 1 and 2 are friends. The greatest 
// possible money difference between any two citizens is $20, 
// as in the following configuration: citizen 0 has $100; 
// citizen 1 has $110; citizen 2 has $120.
// 
// 1)
// {"NN",
//  "NN"}
// 1
// 
// Returns: -1
// 
// Since citizens 0 and 1 are not friends, there are no 
// constraints between them.
// 
// 2)
// {"NNYNNN",
//  "NNYNNN",
//  "YYNYNN",
//  "NNYNYY",
//  "NNNYNN",
//  "NNNYNN"}
// 1000
// 
// Returns: 3000
// 
// 
// 
// 3)
// {"NNYN",
//  "NNNY",
//  "YNNN",
//  "NYNN"}
// 584
// 
// Returns: -1
// 
// 
// 
// 4)
// {"NYNYYYN",
//  "YNNYYYN",
//  "NNNNYNN",
//  "YYNNYYN",
//  "YYYYNNN",
//  "YYNYNNY",
//  "NNNNNYN"}
// 5
// 
// Returns: 20
// 
// 
// 
// 5)
// {"NYYNNNNYYYYNNNN",
//  "YNNNYNNNNNNYYNN",
//  "YNNYNYNNNNYNNNN",
//  "NNYNNYNNNNNNNNN",
//  "NYNNNNYNNYNNNNN",
//  "NNYYNNYNNYNNNYN",
//  "NNNNYYNNYNNNNNN",
//  "YNNNNNNNNNYNNNN",
//  "YNNNNNYNNNNNYNN",
//  "YNNNYYNNNNNNNNY",
//  "YNYNNNNYNNNNNNN",
//  "NYNNNNNNNNNNNNY",
//  "NYNNNNNNYNNNNYN",
//  "NNNNNYNNNNNNYNN",
//  "NNNNNNNNNYNYNNN"}
// 
// 747
// 
// Returns: 2988
// 
// 
// 
// 6)
// {"NY",
//  "YN"}
// 0
// 
// Returns: 0
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

class Egalitarianism {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 20; verify_case(0, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(1, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 3000; verify_case(2, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 584; int Arg2 = -1; verify_case(3, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 20; verify_case(4, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 747; int Arg2 = 2988; verify_case(5, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(6, Arg2, maxDifference(Arg0, Arg1)); }

// END CUT HERE

	public: 
   int verif(vector <string> &isf, int d, int n, int root) {
      int res = 0;
      vector<bool> vis(n);

      queue<pair<int,int> > q;
      q.push(make_pair(root, 0));
      vis[root] = 1;
      while( !q.empty() ) {
         int nod = q.front().first;
         int dist = q.front().second;
         res = max(res, dist);
         q.pop();
         for(int j=0; j<n; j++)
            if( !vis[j]  && isf[nod][j]=='Y' ) {
               vis[j] = 1;
               q.push(make_pair(j, dist+d));
            }
      }
      for(int i=0; i<n; i++)
         if( !vis[i] ) return -1;
      return res;
   }
	int maxDifference(vector <string> isf, int d) {
		int res = -2;
      int n = isf.size();
      for(int i=0; i<n; i++) {
         res = max(res, verif(isf, d, n, i));
         if( res==-1 ) return res;
      }

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	Egalitarianism ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
