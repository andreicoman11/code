// BEGIN CUT HERE
// PROBLEM STATEMENT
// In the Land of Winter lives the Toy King. The Toy King 
// owns many fields and in each field he has control over 
// different plots of land. The Toy King also has nine lords 
// under him. To each of his lords he has given control over 
// some of the plots in his kingdom. Now he wishes to use 
// some of those plots to make train tracks for a winter 
// celebration.
// 
// To build his train tracks the king can use three types of 
// track pieces. Each of these pieces resembles a puzzle 
// piece where each end can be positive or negative.
// 
// 
// 
// 
// A type A piece of track rotates by 90 degrees and has two 
// positive ends.
// A type B piece of track rotates by 90 degrees and has two 
// negative ends.
// A straight piece has both one positive and one negative end.
// 
// 
// Notice how the positive end fits snugly together with the 
// negative end. The ends of two pieces of track can connect 
// if and only if one end is positive and one end is 
// negative. This makes creating connected tracks very easy. 
// Simply place two pieces of track side by side and make 
// sure the positive and negative ends interlock.
// 
// Currently, some plots of land are empty and others contain 
// pieces of track of various types. Each plot of land can 
// contain at most one piece of track. While forming the new 
// tracks, the king allowed you to rotate the existing pieces 
// of track in increments of 90 degrees. Additionally, you 
// are allowed to add new straight pieces onto empty plots of 
// land. Each of these new pieces can have any of the four 
// possible orientations. You are not allowed to add new 
// pieces of types A and B.
// 
// You are given a vector <string> field that describes a 
// rectangular area of the country, divided into unit square 
// plots of land.
// 
// Each character of each element of field describes one plot 
// of land. The meanings of individual characters follow.
// 
// The character '.' represents an empty plot of land.
// The character 'A' represents a plot occupied by a type A 
// piece.
// The character 'B' represents a plot occupied by a type B 
// piece.
// The character 'S' represents a plot of land occupied by a 
// straight piece.
// If the character is a digit 'x' (where 'x' is from '1' to 
// '9'), it represents a plot of land owned by the lord 
// number x.
// 
// 
// The king would like to have a non-empty set of closed 
// track segments. More precisely, in the final configuration 
// there must be at least one track piece and each track 
// piece has to be connected to two other track pieces. Note 
// that in the final configuration there may be more than one 
// closed sequence of tracks. Sometimes it may happen that it 
// is impossible to build the tracks without using plots that 
// were assigned to some of the lords. If the king wishes to 
// use one or more plots that were assigned to lord i, he 
// will pay the lord exactly i gold coins. Paying the i coins 
// once allows the king to use all the plots that were 
// assigned to lord i. Adding new straight pieces does not 
// cost anything. The king would like to know the minimum 
// total amount of gold coins he would have to pay to make 
// the train tracks. Return this minimum amount. If it is not 
// possible to build the train tracks, return -1 instead.
// 
// DEFINITION
// Class:ToyTrain
// Method:getMinCost
// Parameters:vector <string>
// Returns:int
// Method signature:int getMinCost(vector <string> field)
// 
// 
// CONSTRAINTS
// -field will contain between 1 and 50 elements, inclusive.
// -Each element of field will contain between 1 and 50 
// characters, inclusive.
// -Each element of field will contain the same number of 
// characters.
// -Each character of each element of field will be 'A', 'B', 
// 'S', '.' or a digit between '1' and '9', inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"BA",
//  "SS",
//  "AB"}
// 
// Returns: 0
// 
// 
// 
// 1)
// {"."}
// 
// Returns: -1
// 
// It is not possible to build any closed train tracks.
// 
// 2)
// {"ABBA",
//  "BAAB"}
// 
// Returns: 0
// 
// The King can make two separate tracks for this field.
// 
// 3)
// {"AA",
//  "AA"}
// 
// 
// Returns: -1
// 
// 
// 
// 4)
// {"..AB",
//  "B..A",
//  "....",
//  "A.B."}
// 
// Returns: -1
// 
// 
// 
// 5)
// {"A1B8A2B",
//  "16A.B22",
//  "BAB.9.A",
//  "ABA.7.B",
//  "B12345A"}
// 
// Returns: 31
// 
// 
// 
// 6)
// {"..A.B",
//  ".1.2.",
//  "A.B..",
//  ".3.4.",
//  "B...A"}
// 
// Returns: 0
// 
// 
// 
// 7)
// {"ASBSBSA",
//  "S.S.S.S",
//  "BSASASB"}
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
#define INF 1024

class ToyTrain {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BA",
 "SS",
 "AB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getMinCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, getMinCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABBA",
 "BAAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMinCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"AA",
 "AA"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, getMinCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"..AB",
 "B..A",
 "....",
 "A.B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, getMinCost(Arg0)); }
	void test_case_5() { string Arr0[] = {"A1B8A2B",
 "16A.B22",
 "BAB.9.A",
 "ABA.7.B",
 "B12345A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(5, Arg1, getMinCost(Arg0)); }
	void test_case_6() { string Arr0[] = {"..A.B",
 ".1.2.",
 "A.B..",
 ".3.4.",
 "B...A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, getMinCost(Arg0)); }
	void test_case_7() { string Arr0[] = {"ASBSBSA",
 "S.S.S.S",
 "BSASASB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(7, Arg1, getMinCost(Arg0)); }

// END CUT HERE

	public: 
   bool verif(vector<string> f, vector<bool> use )
   {
      bool foundTrack = 0, founda = 0;
      char last;
      for(int i=0; i<f.size(); i++)
      {
         for(int j=0; j<f[i].size(); j++)
            if( founda && f[i][j]=='#' ) return 0;
            else if( founda && isdigit(f[i][j]) && use[int(f[i][j])-int('1')]==0 ) return 0;
            else if( founda && isalpha(f[i][j]) )
            {
               if( f[i][j]=='S' ) f[i][j]='#';
               else
               {
                  if( f[i][j]==last ) return 0;
                  founda = 0;
               }
            }
            else if( founda )
            {
               f[i][j] = '#';
            }
            else if( isalpha(f[i][j]) )
            {
               if( f[i][j]=='S' ) continue;
               last = f[i][j];
               founda = 1;
               foundTrack = 1;
            }

         if( founda ) return 0;
      }

      founda = 0;
      for(int j=0; j<f[0].size(); j++)
      {
         for(int i=0; i<f.size(); i++)
            if( founda && f[i][j]=='#' ) return 0;
            else if( founda && isdigit(f[i][j]) && use[int(f[i][j])-int('1')]==0 ) return 0;
            else if( founda && isalpha(f[i][j]) )
            {
               if( f[i][j]=='S' ) f[i][j]='#';
               else
               {
                  if( f[i][j]==last ) return 0;
                  founda = 0;
               }
            }
            else if( isalpha(f[i][j]) )
            {
               if( f[i][j]=='S' ) continue;
               last = f[i][j];
               founda = 1;
               foundTrack = 1;
            }

         if( founda ) return 0;
      }
      
      for(int i=0; i<f.size(); i++)
      for(int j=0; j<f[i].size(); j++)
         if( f[i][j]=='S' ) return 0;

      return foundTrack;
   }

	int getMinCost(vector <string> f) {
      vector<string> f2( f[0].size() );
      
      int mincost = INF;
	   vector<bool> use(9);
      for(int i=0; i<512; i++)
      {
         int cost = 0;
         for(int j = 0; j<9; j++)
            if( i&(1<<j) ) use[j] = 1, cost += j+1;
            else use[j] = 0;

         if( verif(f, use) ) mincost = min(mincost, cost);
      }
      return (mincost==INF ? -1 : mincost);
	}
	
};

// BEGIN CUT HERE 
int main()
{
	ToyTrain ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
