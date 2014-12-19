// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Order of All Things Pointy and Magical has 
// commissioned the creation of some new wizard hats. A 
// wizard hat is created by taking two cones: a decorative 
// top cone, and a warm and fluffy bottom cone. To assemble 
// the hat, both cones are first placed onto a table, so that 
// their bases are horizontal and their apexes point upwards. 
// The top cone is then lifted and placed onto the bottom 
// cone. The base of the top cone has to remain horizontal, 
// and the apex of the top cone must be strictly above the 
// apex of the bottom cone. 
// 
// Not every pair of cones can be used to create a wizard 
// hat. A wizard hat is only produced if the following two 
// criteria are both met:
// 
// The apex of the top cone must be strictly above the apex 
// of the bottom cone. I.e., when the top cone is placed on 
// top of the bottom cone and released, their apexes must not 
// touch.
// Some part of the bottom cone must remain visible to form 
// the brim of the hat. (Otherwise, the hat would look like a 
// simple cone, not like a wizard hat!)
// 
// 
// You have several top cones and several bottom cones of 
// various sizes. Each cone can be described by its height 
// (the distance between the apex and the base) and by the 
// radius of its base. The top cones you have are described 
// by topHeight and topRadius: for each valid i, you have one 
// top cone with height topHeight[i] and radius topRadius[i]. 
// The bottom cones you have are described by bottomHeight 
// and bottomRadius in the same way. 
// 
// Your task is to determine the maximum number of wizard 
// hats you can make using each of the available top and 
// bottom cones at most once.
// 
// DEFINITION
// Class:PointyWizardHats
// Method:getNumHats
// Parameters:vector <int>, vector <int>, vector <int>, 
// vector <int>
// Returns:int
// Method signature:int getNumHats(vector <int> topHeight, 
// vector <int> topRadius, vector <int> bottomHeight, vector 
// <int> bottomRadius)
// 
// 
// CONSTRAINTS
// -topHeight and topRadius will contain the same number of 
// elements.
// -bottomHeight and bottomRadius will contain the same 
// number of elements.
// -topHeight will contain between 1 and 50 elements, 
// inclusive.
// -topRadius will contain between 1 and 50 elements, 
// inclusive.
// -bottomHeight will contain between 1 and 50 elements, 
// inclusive.
// -bottomRadius will contain between 1 and 50 elements, 
// inclusive.
// -Each element of topHeight, topRadius, bottomHeight, and 
// bottomRadius will be between 1 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {30}
// {3}
// {3}
// {30}
// 
// Returns: 1
// 
// The top and bottom cone can be used together to make a 
// wizard hat.
// 
// 1)
// {4,4}
// {4,3}
// {5,12}
// {5,4}
// 
// Returns: 1
// 
// The only way to produce a wizard hat is to use the top 
// cone 1 (height 4, radius 3) and the bottom cone 0 (height 
// 5, radius 5).
// 
// 2)
// {3}
// {3}
// {1,1}
// {2,4}
// 
// Returns: 1
// 
// 
// 
// 3)
// {10,10}
// {2,5}
// {2,9}
// {3,6}
// 
// Returns: 2
// 
// 
// 
// 4)
// {3,4,5}
// {5,4,3}
// {3,4,5}
// {3,8,5}
// 
// Returns: 2
// 
// 
// 
// 5)
// {1,2,3,4,5}
// {2,3,4,5,6}
// {2,3,4,5,6}
// {1,2,3,4,5}
// 
// Returns: 0
// 
// 
// 
// 6)
// {123,214,232,323,342,343}
// {123,123,232,123,323,434}
// {545,322,123,545,777,999}
// {323,443,123,656,767,888}
// 
// Returns: 5
// 
// 
// 
// 7)
// {999,999,999,10000,10000,10000}
// {10000,10000,10000,1,2,3}
// {2324,2323,234,5454,323,232}
// {1,2,3222,434,5454,23}
// 
// Returns: 3
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

#define pb push_back
#define sz size()

int e[128][128];

class PointyWizardHats {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {30}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(2, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(3, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,8,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(4, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(5, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {123,214,232,323,342,343}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {123,123,232,123,323,434}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {545,322,123,545,777,999}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {323,443,123,656,767,888}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(6, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {999,999,999,10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,10000,10000,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2324,2323,234,5454,323,232}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3222,434,5454,23}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(7, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	public: 
   int flow(int src, int sink) {
      queue<int> q;
      q.push(src);
      vector<bool> v(128);
      vector<int> t(128);
      v[src] = 1;
      t[src] = -1;
      while( !q.empty() && v[sink]==0 )
      {
         int nod = q.front();
         q.pop();

         for(int i=0; i<=sink; i++)
            if( e[nod][i] && v[i]==0 ) {
               v[i] = 1;
               t[i] = nod;
               q.push(i);
            }
      }
      
      if( v[sink]==0 ) return 0;

      int nod = sink;
      while( t[nod]!=-1 )
      {
         e[t[nod]][nod] = 0;
         e[nod][t[nod]] = 1;
         nod = t[nod];
      }
      return 1;
   }

	int getNumHats(vector <int> th, vector <int> tr, vector <int> bh, vector <int> br) {
		memset(e, 0, sizeof(e));
      int n = th.size(), m = bh.size();

      for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
         if( tr[i]<br[j] && th[i]>(bh[j]*tr[i])/br[j] )
            e[i][n+j] = 1;

      int src = n+m, sink = n+m+1;
      for(int i=0; i<n; i++)
         e[src][i] = 1;
      for(int i=0; i<m; i++)
         e[n+i][sink] = 1;

      int res = 0;
      while( flow(src, sink) ) res++;
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	PointyWizardHats ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
