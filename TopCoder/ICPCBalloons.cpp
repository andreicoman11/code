// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are organizing a subregional ACM ICPC contest. The 
// problemset at the contest will consist of M problems. 
// According to an ACM ICPC tradition, when a team solves a 
// problem, it gets awarded a balloon. To account for this, 
// you've bought balloons of N different colors (conveniently 
// numbered from 0 to N-1). The number of balloons of color i 
// that you've bought is given by balloonCount[i]. Balloons 
// come in two sizes: medium and large. All balloons of the 
// same color have the same size. If the i-th character of 
// balloonSize is 'M', then all balloons of color i have 
// medium size, and if this character is 'L', then all 
// balloons of color i have large size.
// 
// Today you've been at the meeting with the scientific 
// committee of the contest. There, you learned that there 
// are additional restrictions of which you were not aware. 
// Here are those restrictions:
// 
// All balloons that get awarded for a particular problem 
// must have the same color and size.
// For any two problems, the colors of balloons awarded for 
// solving them must be different. In other words, the color 
// of balloons awarded for each problem must be unique.
// 
// These are definitely bad news, since you ordered balloons 
// pretty much arbitrarily and it's possible that you won't 
// be able to satisfy the restrictions with the balloons you 
// currently have. However, the good news is that scientific 
// committee members were able to evaluate the difficulty of 
// each problem. More exactly, they told you that the maximum 
// number of teams that can potentially solve the i-th 
// problem is maxAccepted[i]. The scientific committee 
// members are very clever and experienced, so their 
// prediction is guaranteed to come true.
// 
// Your budget is limited and balloons are expensive, so 
// buying more of them is not an option. Fortunately, there 
// is a very cheap balloon repaint service at your city, so 
// you are going to use it. The service offers repainting a 
// given balloon into any other color. This can be one of the 
// N colors you have, as well as any color that you don't 
// have yet. However, it is not possible to change the size 
// of a balloon.
// 
// You are given the vector <int>s balloonCount, maxAccepted 
// and the string balloonSize. Return the minimum number of 
// balloons that have to be repainted in order to guarantee 
// that you will be able to award balloons to the teams 
// properly. If it is impossible to achieve the goal using 
// any number of balloon repaintings, return -1.
// 
// DEFINITION
// Class:ICPCBalloons
// Method:minRepaintings
// Parameters:vector <int>, string, vector <int>
// Returns:int
// Method signature:int minRepaintings(vector <int> 
// balloonCount, string balloonSize, vector <int> maxAccepted)
// 
// 
// CONSTRAINTS
// -balloonCount will contain between 1 and 50 elements, 
// inclusive.
// -Each element of balloonCount will be between 1 and 100, 
// inclusive.
// -balloonSize will contain the same number of characters as 
// the number of elements in balloonCount.
// -Each character of balloonSize will be 'M' or 'L'.
// -maxAccepted will contain between 1 and 15 elements, 
// inclusive.
// -Each element of maxAccepted will be between 1 and 100, 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {100}
// "L"
// {1,2,3,4,5}
// 
// Returns: 10
// 
// You have 100 large balloons of the same color. 5 of them 
// can be used for problem 4 and 1+2+3+4=10 balloons need to 
// be repainted in order to be used for remaining problems.
// 
// 1)
// {100}
// "M"
// {10,20,30,40,50}
// 
// Returns: -1
// 
// We don't have enough balloons. Repainting is not going to 
// help.
// 
// 2)
// {5,6,1,5,6,1,5,6,1}
// "MLMMLMMLM"
// {7,7,4,4,7,7}
// 
// Returns: 6
// 
// (Note that all of the indices in this annotation are 0-
// based.)
// 
// Repaint one balloon of color 7 into color 1. Repaint one 
// balloon of color 7 into color 4. Now large balloons can be 
// awarded for problems 0, 1, and 2.
// 
// Repaint two balloons of colors 2 and 5 into color 0. 
// Repaint two balloons of colors 6 and 8 into color 3. Now 
// medium balloons of colors 0, 3, and 6 can be awarded for 
// problems 3, 4, and 5.
// 
// 3)
// {100,100}
// "ML"
// {50,51,51}
// 
// Returns: -1
// 
// Even though we have 200 balloons overall and only at most 
// 152 accepted solutions, there is still no way of dividing 
// and repainting the balloons that works.
// 
// 4)
// {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}
// "MMMLLLMMLLMLMLM"
// {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}
// 
// Returns: 5
// 
// 
// 
// 5)
// {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}

// "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"
// {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}
// 
// Returns: 210
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
#include <bitset>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define LL long long
#define pb push_back
#define sz size()
#define INF 1000000000

class ICPCBalloons {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L"; int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M"; int Arr2[] = {10,20,30,40,50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,6,1,5,6,1,5,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MLMMLMMLM"; int Arr2[] = {7,7,4,4,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(2, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ML"; int Arr2[] = {50,51,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MMMLLLMMLLMLMLM"; int Arr2[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"; int Arr2[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 210; verify_case(5, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
   int getmin(vector<int> a, vector<int> b)
   {
      int have=0, need=0;
      for(int i=0; i<max( a.size(), b.size()); i++)
      {
         int diff = 0;
         if( i<a.size() ) diff += a[i];
         if( i<b.size() ) diff -= b[i];
         if( diff<0 ) need -= diff;
         if( diff>0 ) have += diff;
      }
      if( have>=need ) return need;
      return INF;
   }

	int minRepaintings(vector <int> bc, string bs, vector <int> acc) {
		vector<int> m, l;
      for(int i=0; i<bc.size(); i++)
         if( bs[i]=='L' ) l.push_back(bc[i]);
         else m.push_back(bc[i]);

      sort( m.rbegin(), m.rend());
      sort( l.rbegin(), l.rend());
      sort( acc.rbegin(), acc.rend());

      int pos = (1<<acc.size());

      int res = INF;
      for(int i=0; i<pos; i++)
      {
         vector<int> M, L;
         for(int j=0; j<acc.size(); j++)
            if( i & (1<<j) )
               M.push_back(acc[j]);
            else 
               L.push_back(acc[j]);

         res = min( getmin(m, M) + getmin(l, L), res);
      }      
      return (res==INF ? -1 : res);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	ICPCBalloons ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
