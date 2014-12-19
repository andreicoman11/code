// BEGIN CUT HERE
// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers.
// They fight against evil to protect the Earth.
// Cosmic enemies have just attacked the Earth, and the 
// Magical Girls are going to fight them.
// 
// You are given a vector <int> magicalGirlStrength that 
// describes the Magical Girls:
// for each i, magicalGirlStrength[i] is the strength of one 
// of the girls.
// You are also given a vector <int> enemyStrength and a 
// vector<long long> enemyCount that describe their enemies:
// for each i, there are enemyCount[i] enemies that each have 
// strength enemyStrength[i].
// 
// Each Magical Girl will always fight one enemy at a time.
// A Magical Girl will defeat her enemy if her strength is 
// greater than or equal to the strength of that enemy.
// 
// At the beginning of the fight the fatigue of each Magical 
// Girl is 0.
// Each time a Magical Girl defeats an enemy, her fatigue 
// increases by 1.
// 
// The Magical Girls want to defeat all the enemies.
// That is, each of the enemies must be defeated by one of 
// the Magical Girls.
// Additionally, the Magical Girls want to minimize the 
// maximum fatigue among them.
// 
// If it is impossible to defeat all of the enemies, return -1.
// Otherwise, return the smallest F with the following 
// property:
// the Magical Girls can defeat all enemies in such a way 
// that at the end the fatigue of each girl is at most F.
// 
// DEFINITION
// Class:SpaceWarDiv1
// Method:minimalFatigue
// Parameters:vector <int>, vector <int>, vector<long long>
// Returns:long long
// Method signature:long long minimalFatigue(vector <int> 
// magicalGirlStrength, vector <int> enemyStrength, 
// vector<long long> enemyCount)
// 
// 
// NOTES
// -The elements of enemyStrength are not necessarily 
// pairwise distinct.
// 
// 
// CONSTRAINTS
// -magicalGirlStrength will contain between 1 and 50 
// elements, inclusive.
// -Each element of magicalGirlStrength will be between 1 and 
// 10,000, inclusive.
// -enemyStrength and enemyCount will each contain between 1 
// and 50 elements, inclusive.
// -enemyStrength and enemyCount will contain the same number 
// of elements.
// -Each element of enemyStrength will be between 1 and 
// 10,000, inclusive.
// -Each element of enemyCount will be between 1 and 
// 100,000,000,000,000 (10^14), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2, 3, 5}
// {1, 3, 4}
// {2, 9, 4}
// 
// Returns: 7
// 
// There are 3 Magical Girls, their strength are 2, 3, and 5.
// There are 3 kinds of enemies: 2 enemies with strength 1 
// each, 9 enemies with strength 3 each, and 4 enemies with 
// strength 4 each.
// This is one of the ways how to minimize the maximal fatigue:
// 
// Magical girl 0 defeats 2 enemies with strength 1.
// Magical girl 1 defeats 7 enemies with strength 3.
// Magical girl 2 defeats 2 enemies with strength 3 and 4 
// enemies with strength 4.
// 
// 
// 1)
// {2, 3, 5}
// {1, 1, 2}
// {2, 9, 4}
// 
// Returns: 5
// 
// Each of the Magical Girls can defeat any of the enemies. 
// The optimal strategy is that each girl should defeat 5 of 
// the enemies.
// 
// 2)
// {14, 6, 22}
// {8, 33}
// {9, 1}
// 
// Returns: -1
// 
// None of the magical girls can defeat the enemy with 
// strength 33.
// 
// 3)
// {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 
// 308, 137, 665, 834, 955, 958, 613, 417}
// {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 
// 872, 127, 261, 103, 763, 864, 360, 618, 307}
// {20626770196420, 45538527263992, 52807114957507, 
// 17931716090785, 65032910980630, 88711853198687, 
// 26353250637092,
//  61272534748707, 89294362230771, 52058590967576, 
// 60568594469453, 23772707032338, 43019142889727, 
// 39566072849912,
//  78870845257173, 68135668032761, 36844201017584, 
// 10133804676521, 6275847412927, 37492167783296}
// 
// Returns: 75030497287405
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

class SpaceWarDiv1 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {14, 6, 22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 33}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {9, 1}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 75030497287405LL; verify_case(3, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
   bool can_win(long long x, vector <int> gs, vector <pair< int, long long> > e) {
      int pos = 0;
      for(int i=0; pos<(int)e.size() && i<(int)gs.size(); i++) {
         long long str = x;
         if( e[pos].first > gs[i] ) return 0;

         while( str && pos<(int)e.size() ) {
            if( e[pos].second > str ) {
               e[pos].second -= str;
               str = 0LL;
            }
            else if( e[pos].second == str ) {
               e[pos].second = 0LL;
               pos++;
               str = 0LL;
            }
            else {
               str -= e[pos].second;
               e[pos].second = 0LL;
               pos++;
            }
         }
      }
      return pos >= (int)e.size();
   }

	long long minimalFatigue(vector <int> gs, vector <int> es, vector<long long> ec) {
		long long a = 1, b = 10000000000000000LL;
      sort(gs.begin(), gs.end());
      reverse(gs.begin(), gs.end());
      vector<pair<int, long long> > e(es.size());

      for(int i=0; i<(int)e.size(); i++)
         e[i].first = es[i], e[i].second = ec[i];
      sort( e.begin(), e.end());
      reverse(e.begin(), e.end());

      if( !can_win(b, gs, e) ) return -1LL;
      while( a+1<b ) {
         long long mid = (a+b) / 2LL;
         if( can_win(mid, gs, e) ) b = mid;
         else a = mid;
      }
      if( can_win(a, gs, e) ) return a;
      return b;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	SpaceWarDiv1 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
