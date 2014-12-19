// BEGIN CUT HERE
// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to "read" 
// virtual novels. In particular, he's currently "reading" a 
// novel titled Touhou, with Reimu Hakurai as its main 
// protagonist. There are N stages in Touhou, numbered 0 
// through N-1. A playthrough of the novel always starts at 
// the stage 0. The playthrough then may visit some other 
// stages, based on the player's choices. The sequence of 
// visited stages is always strictly ascending. A playthrough 
// is successful if it terminates by reaching the stage N-1.
// 
// In each stage, Gogo can either finish the playthrough or 
// choose one of the available options that advance Reimu to 
// other stages. You are given a vector <string> choices. If 
// there is a choice that advances Reimu from stage i to 
// stage j, choices[i][j] will be 'Y', otherwise it will be 
// 'N'. For each pair of stages i, j such that i < j the game 
// contains at most one such choice.
// 
// Gogo wants to make as many successful playthroughs as 
// possible, one after another. However, there is an 
// additional constraint: Each playthrough must contain at 
// least one choice Gogo never made in any of the previous 
// playthroughs.
// 
// Return the maximum number of successful playthroughs that 
// Gogo can play. If there are no such playthrough, return 0.
// 
// DEFINITION
// Class:GogoXReimuHakurai
// Method:solve
// Parameters:vector <string>
// Returns:int
// Method signature:int solve(vector <string> choices)
// 
// 
// CONSTRAINTS
// -choices will contain between 2 and 50 elements, inclusive.
// -Each element of choices will contain N characters, where 
// N is the number of elements in choices.
// -Each character in choices will be either 'Y', or 'N'.
// -If i >= j then choices[i][j] will be 'N'.
// 
// 
// EXAMPLES
// 
// 0)
// {
// "NYY",
// "NNY",
// "NNN"}
// 
// Returns: 2
// 
// The two possible successful playthroughs:
// 0 -> 1 -> 2
// 0 -> 2
// Gogo may play them both, in any order.
// 
// 1)
// {
// "NYNY",
// "NNYY",
// "NNNY",
// "NNNN"}
// 
// Returns: 3
// 
// 
// 
// 2)
// {"NNY"
// ,"NNY"
// ,"NNN"}
// 
// Returns: 1
// 
// 
// 
// 3)
// {"NN"
// ,"NN"}
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
#include <list>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define LL long long
#define pb push_back
#define sz size()

vector<string> c;
bool vis[64], ok[64] = {0}, r[64] = {0};
int n, m=0;

class GogoXReimuHakurai {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"NYY",
"NNY",
"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {
"NYNY",
"NNYY",
"NNNY",
"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNY"
,"NNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE
   void check(int j)
   {
	   memset(vis, 0, sizeof(vis));
	   queue<int> q;
	   q.push(j);
	   vis[j] = 1;
	   while( !q.empty() )
	   {
		   int nod = q.front();
		   q.pop();
		   for(int i=nod+1; i<n; i++)
			   if( c[nod][i]=='Y' && vis[i]==0 )
			   {
				   q.push(i);
				   vis[i] = 1;
			   }
	   }
	   ok[j] = vis[n-1];
   }

   int solve(vector <string> c2) {
	   c = c2;
	   n = c.size();
      m = 0;
	   check(0);
	   memcpy(r, vis, sizeof(r));
	   for(int i=1; i<n-1; i++)
		   check(i);
		
	   if( ok[0]==0 ) return 0;
	   ok[n-1] = 1;
	
	   for(int i=0; i<n; i++)
	   for(int j=0; j<n; j++)
		   if( c[i][j]=='Y' && r[i]==1 && ok[j]==1 ) m++;	
	
	   for(int i=1; i<c.size()-1; i++)
		   if( ok[i]==0 || r[i]==0 ) n--;
	
	   for(int i=0; i<c.size(); i++)
		   cout << r[i] << " " << ok[i] << endl;
		
	   cout << m << " " << n << endl;
	
       return m - n + 2;
   }
	
};

// BEGIN CUT HERE 
int main()
{
	GogoXReimuHakurai ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
