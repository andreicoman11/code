// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Order of the Hats has commissioned the creation of a 
// new hat rack. This new hat rack must meet certain 
// properties in order to be considered to hold headwear of 
// such importance.
// The hat rack is formed by taking several numbered knobs 
// that are connected by rods. One of the knobs is nailed to 
// the wall. The remaining knobs then hang below this top 
// knob. A sample hat rack is shown in the picture below.
// 
// 
// 
// The picture also shows that the hat rack can be divided 
// into levels of knobs. Formally, the level i is defined to 
// contain each knob X such that there are exactly i rods 
// between the top knob and knob X.
// 
// The order would like their hat rack to meet the following 
// three requirements:
// 
// Each knob X can have at most two knobs hanging directly 
// below it. If there is only one such knob, it hangs 
// directly below X; otherwise, one knob will hang slightly 
// to the right of X and the other slightly to the left.
// Except for the bottommost level, each level must be full. 
// That is, if level i is not the bottommost level, it must 
// contain exactly 2^i knobs.
// The bottommost level must have all its knobs as far on the 
// left as possible.
// 
// 
// The third requirement in more detail: Let b be the 
// bottommost level. If we traverse level b-1 from left to 
// right, there will first be some knobs with two rods going 
// to knobs in level b, then possibly a single knob with one 
// rod going to level b, and finally some knobs not connected 
// to any knob in level b.
// 
// You are given a configuration of knobs and rods. The knobs 
// are not fastened to the wall yet. The knobs are numbered 1 
// through N. There are precisely N-1 rods, and they are 
// connecting the knobs in such a way that the entire 
// structure holds together. (Thus, necessarily, the topology 
// of the hat rack is a tree.)
// 
// You are given two vector <int>s knob1 and knob2, each 
// containing N-1 elements. These two vector <int>s describe 
// the rods: For each i, there is a rod connecting the two 
// knobs knob1[i] and knob2[i]. Return the number of ways to 
// arrange the hat rack such that it meets the requirements 
// set by the Order of the Hats. Two arrangements are 
// considered different if the relative position of at least 
// one pair of knobs differs. If it is not possible to meet 
// the requirements, return 0.
// 
// DEFINITION
// Class:HatRack
// Method:countWays
// Parameters:vector <int>, vector <int>
// Returns:long long
// Method signature:long long countWays(vector <int> knob1, 
// vector <int> knob2)
// 
// 
// NOTES
// -The correct number of arrangements always fits in a 
// signed 64 bit integer.
// 
// 
// CONSTRAINTS
// -knob1 will contain between 1 and 50 elements, inclusive.
// -knob1 and knob2 will contain the same number of elements.
// -Each element of knob1 will be between 1 and N, inclusive, 
// where N is 1 + (the number of elements in knob1).
// -Each element of knob2 will be between 1 and N, inclusive, 
// where N is 1 + (the number of elements in knob2).
// -Each pair of knobs in the hat rack will be connected by 
// some sequence of rods and knobs.
// 
// 
// EXAMPLES
// 
// 0)
// {1}
// {2}
// 
// Returns: 2
// 
// 
// 
// 1)
// {1,1}
// {2,3}
// 
// Returns: 2
// 
// 
// 
// 2)
// {1,1,1,1}
// {2,3,4,5}
// 
// Returns: 0
// 
// 
// 
// 3)
// {6,6,6,4,1}
// {1,2,4,5,3}
// 
// Returns: 0
// 
// 
// 
// 4)
// {1,1,2,2,11,11,8,8,3,3,4,4,5}
// {2,3,11,8,12,13,9,10,4,5,7,6,14}
// 
// Returns: 16
// 
// 
// 
// 5)
// {1,2,3,4,5,6,7,8,9}
// {2,3,4,5,6,7,8,9,10}
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

int n;
vector<vector<int> > e, e2;
LL pow2[] = {1, 2, 4, 8, 16, 32, 64};

class HatRack {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,6,6,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,2,2,11,11,8,8,3,3,4,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,11,8,12,13,9,10,4,5,7,6,14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

	public: 
   LL count(int r, int& lvls, int& lastlvl)
   {
      for(int i=0; i<e[r].size(); i++)
      for(int j=0, x=e[r][i]; j<e[x].size(); j++)
         if( e[x][j]==r )
         {
            e[x][j] = e[x][ e[x].size()-1 ];
            e[x].resize( e[x].size()-1 );
            break;
         }

      if( e[r].size()==0 ) {
         lvls = 0;
         lastlvl = 1;
         return 1LL;

      } else if( e[r].size()==1 ) {
         if( e[ e[r][0] ].size()!=0 ) return 0LL;
         lvls = 1;
         lastlvl = 1;
         return 1LL;

      } else if( e[r].size()>2 ) {
         return 0LL;

      } else {
         int lvls2[2], lastlvl2[2];
         LL res1 = count( e[r][0], lvls2[0], lastlvl2[0]);
         LL res2 = count( e[r][1], lvls2[1], lastlvl2[1]);
         if( abs(lvls2[0]-lvls2[1])>1 ) return 0LL;
         if( res1==0LL || res2==0LL ) return 0LL;

         
         lvls = max(lvls2[0], lvls2[1]) + 1;
         lastlvl = lastlvl2[0] + lastlvl2[1];

         if( lvls2[0]==lvls2[1] )
         {
            if( lastlvl2[0]!=pow2[lvls2[0]] && lastlvl2[1]!=pow2[lvls2[0]] ) return 0LL;
            if( lastlvl2[0]==pow2[lvls2[0]] && lastlvl2[1]==pow2[lvls2[0]] ) return 2*res1*res2;
            return res1 * res2;
         }

         if( lvls2[0]<lvls2[1] )
         {
            swap(lvls2[0], lvls2[1]);
            swap(lastlvl2[0], lastlvl2[1]);
            swap(res1, res2);
         }

         if( lastlvl2[1]!=pow2[lvls2[1]] ) return 0LL;
         return res1 * res2;
      }
   }

	long long countWays(vector <int> k1, vector <int> k2) {
		LL res = 0;

      n = k1.size()+1;
      e.clear();
      e.resize(n);
      if( n==2 ) return 2LL;

      for(int i=0; i<k1.size(); i++)
      {
         e[k1[i]-1].push_back( k2[i]-1 );
         e[k2[i]-1].push_back( k1[i]-1 );
      }

      int lvls, lastlvl;
      for(int i=0; i<n; i++)
         if( e[i].size()==2 )
         {
            e2 = e;
            res += count(i, lvls, lastlvl);
            e = e2;
         }

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	HatRack ___test; 
   //int k1[] = {39, 22, 20, 14, 45, 23, 33, 30,  7, 45, 47, 36, 13, 22, 47, 10, 18, 38, 34, 24,  8, 31,  6, 1, 36, 33,  4, 27, 26,  9, 37, 19, 26, 27, 18, 47, 41, 22, 39, 45,  9, 46, 7, 43, 23, 11, 15,  9, 12, 12};
   //int k2[] = { 2,  3,  5, 16, 14, 17, 20, 21, 25, 28, 29, 30, 32, 13, 35, 40, 10, 42, 38, 34, 24,  8, 31, 6,  1, 36, 33,  4, 44, 48, 49, 37, 19, 26, 27, 18, 47, 41, 22, 39, 45, 50, 46, 7, 43, 23, 11, 15,  9, 51};
   //vector<int> v1(k1, k1+50);
   //vector<int> v2(k2, k2+50);
   //
   //cout << ___test.countWays(v1, v2);

	___test.run_test(-1); 
} 
// END CUT HERE
