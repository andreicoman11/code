// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel and Fox Jiro both went to spend an evening in the 
// dancing room.
// Together, there are N foxes in the room.
// The foxes are numbered 0 through N-1.
// In particular, Ciel is fox 0 and Jiro is fox 1.
// 
// 
// 
// You are given a vector <string> friendship that describes 
// the initial friendship between the foxes in the room.
// More precisely, friendship contains N elements with N 
// characters each.
// Character j of element i of friendship is 'Y' if foxes i 
// and j are friends at the beginning of the evening, and 'N' 
// otherwise.
// Note that friendship is symmetric: whenever X is a friend 
// of Y, Y is a friend of X.
// 
// 
// 
// During the evening, multiple songs will be played in 
// succession.
// During each song, some pairs of foxes will be dancing 
// together.
// Foxes are not allowed to change partners during the dance.
// Thus in each dance each fox either dances with a single 
// partner, or sits the dance out.
// 
// 
// 
// Foxes are not allowed to form the pairs for a dance 
// arbitrarily.
// It is only allowed for two foxes to dance together if they 
// are friends, or if they have a common friend who can 
// introduce them.
// That is, if foxes A and B are not friends at the moment, 
// they can only dance together if there is a fox C such that 
// A and B are both friends with C.
// After two foxes dance together, they become friends.
// 
// 
// 
// Fox Ciel wants to become friends with Fox Jiro.
// Return the smallest number of dances in which this can be 
// achieved (assuming that all other foxes cooperate and form 
// pairs for the dances optimally).
// If it's impossible to make Ciel and Jiro friends, return 
// -1 instead.
// 
// DEFINITION
// Class:DancingFoxes
// Method:minimalDays
// Parameters:vector <string>
// Returns:int
// Method signature:int minimalDays(vector <string> friendship)
// 
// 
// NOTES
// -Gender does not matter for the foxes when choosing their 
// dance partners.
// 
// 
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -friendship will contain exactly N elements.
// -Each element of friendship will contain exactly N 
// characters.
// -Each character in friendship will be 'Y' or 'N'.
// -For each i, friendship[i][i] = 'N'.
// -For each i and j, friendship[i][j] = friendship[j][i].
// 
// 
// EXAMPLES
// 
// 0)
// {"NNY",
//  "NNY",
//  "YYN"}
// 
// Returns: 1
// 
// There are 3 foxes. Ciel and Jiro are not friends, but they 
// are both friends with fox 2. Thus, they may dance together 
// in the first dance and become friends.
// 
// 1)
// {"NNNNN",
//  "NNYYY",
//  "NYNYY",
//  "NYYNY",
//  "NYYYN"}
// 
// Returns: -1
// 
// Ciel does not know any other fox at the dance, so she 
// cannot dance with anybody.
// 
// 2)
// {"NNYYNN",
//  "NNNNYY",
//  "YNNNYN",
//  "YNNNNY",
//  "NYYNNN",
//  "NYNYNN"}
// 
// Returns: 2
// 
// 
// 
// 3)
// {"NNYNNNNYN",
//  "NNNNYNYNN",
//  "YNNYNYNNN",
//  "NNYNYNYYN",
//  "NYNYNNNNY",
//  "NNYNNNYNN",
//  "NYNYNYNNN",
//  "YNNYNNNNY",
//  "NNNNYNNYN"}
// 
// Returns: 3
// 
// 
// 
// 4)
// {"NY",
//  "YN"}
// 
// Returns: 0
// 
// Ciel and Jiro are already friends in the beginning, no 
// dances are needed. In such a case, the correct return 
// value is 0.
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

class DancingFoxes {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNY",
 "NNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalDays(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minimalDays(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimalDays(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minimalDays(Arg0)); }
	void test_case_4() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, minimalDays(Arg0)); }

// END CUT HERE

	public: 
	int minimalDays(vector <string> f) {
      vector<bool> vis(f.size(), 0);
		queue<pair<int, int> > q;
      q.push(make_pair(0, 0));
      vis[0] = 1;
      int dist = -1;
      while( !q.empty() && !vis[1] ) {
         int nod = q.front().first;
         int lvl = q.front().second;
         q.pop();

         for(int i=0; i<(int)f[nod].size(); i++)
            if( f[nod][i]=='Y' && !vis[i] ) {
               vis[i] = 1;
               q.push(make_pair(i, lvl+1));
               if( i==1 ) 
                  dist = lvl+1;
            }
      }
      if( !vis[1] ) return -1;
      if( dist==1 ) return 0;
      
      int res = 1;
      vector<int> d(dist+1);
      for(int i=0; i<d.size(); i++)
         d[i] = i;
      while( d.size() > 3) {
         vector<int> d2;
         for(int i=0; i<d.size(); i+=3) {
            if( i+2<d.size() ) {
               d2.push_back(i);
               d2.push_back(i+2);
            } else {
               while( i<d.size() ) {
                  d2.push_back(i++);
               }
            }
         }
         d = d2;
         res++;
      }
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	DancingFoxes ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
