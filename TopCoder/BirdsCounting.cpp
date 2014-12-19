// BEGIN CUT HERE
// PROBLEM STATEMENT
// In ecology, there are several ways of estimating the size 
// of a population in a given area.  We are interested in 
// estimating the size of a population of birds.  To do this, 
// we will use the following procedure.
// 
// First, there will be a data collection phase that lasts 
// exactly daysNumber days.  Initially, all the birds are 
// unmarked.  During each day of data collection, we will 
// catch exactly caughtPerDay birds.  At the end of each day, 
// we will examine each of the birds we have caught.  If a 
// bird is unmarked, we will mark it.  If a bird is already 
// marked, we will leave it alone (and it will remain 
// marked).  We will then release all of them back into the 
// wild before the next day begins.
// 
// After the data collection phase is complete, we can use 
// the number of unmarked birds caught each day to estimate 
// the size of the population.
// 
// To help our fellow ecologists in analyzing the collected 
// data, we must compute the probability that after 
// daysNumber days of data collection, there will be exactly 
// birdsMarked marked birds assuming that there are 
// birdsNumber birds in this area. Assume that the 
// probability of being caught is exactly the same for every 
// bird on every day.
// 
// DEFINITION
// Class:BirdsCounting
// Method:computeProbability
// Parameters:int, int, int, int
// Returns:double
// Method signature:double computeProbability(int 
// birdsNumber, int caughtPerDay, int daysNumber, int 
// birdsMarked)
// 
// 
// NOTES
// -The returned value must be accurate to within a relative 
// or absolute value of 1E-9.
// 
// 
// CONSTRAINTS
// -birdsNumber will be between 1 and 20, inclusive.
// -caughtPerDay will be between 1 and birdsNumber, inclusive.
// -daysNumber will be between 1 and 5, inclusive.
// -birdsMarked will be between 0 and birdsNumber, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 1
// 2
// 2
// 
// Returns: 0.6666666666666666
// 
// After the first day, there will be exactly one marked 
// bird.  During the second day, there is a 1/3 chance that 
// we will catch this marked bird (which means we will have 1 
// marked bird after 2 days), and a 2/3 chance that we will 
// catch an unmarked bird (in which case, we will mark it and 
// have 2 marked birds after 2 days).
// 
// 1)
// 3
// 1
// 5
// 1
// 
// Returns: 0.012345679012345678
// 
// 2)
// 8
// 3
// 3
// 7
// 
// Returns: 0.2582908163265306
// 
// 3)
// 5
// 3
// 2
// 4
// 
// Returns: 0.6
// 
// 4)
// 20
// 6
// 5
// 17
// 
// Returns: 0.30035494805367574
// 
// 
// 
// END CUT HERE
#include <iostream>
#include <iomanip>
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
class BirdsCounting {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; double Arg4 = 0.6666666666666666; verify_case(0, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 5; int Arg3 = 1; double Arg4 = 0.012345679012345678; verify_case(1, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 3; int Arg3 = 7; double Arg4 = 0.2582908163265306; verify_case(2, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; double Arg4 = 0.6; verify_case(3, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 6; int Arg2 = 5; int Arg3 = 17; double Arg4 = 0.30035494805367574; verify_case(4, Arg4, computeProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

	public: double computeProbability(int bt, int c, int days, int bm) {
      int comb[32][32];
      comb[0][0] = comb[1][0] = comb[1][1] = 1;
      for(int i=2; i<=21; i++)
      {
         comb[i][0] = comb[i][i] = 1;
         for(int j=1; j<i; j++)
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
      }

      bool setp[8][32];
      double p[8][32];
      memset(setp, 0, sizeof(setp));
      memset(p, 0, sizeof(p));
      p[1][c] = 1.0;
      setp[1][c] = 1;

      for(int i=2; i<=days; i++)
      for(int j=c; j<=bt; j++)
      {
         p[i][j] = 0.0;
         for(int k=0; k<=c; k++)
            if( setp[i-1][j-k] ) {
               p[i][j] += p[i-1][j-k] * comb[j-k][c-k] * comb[bt-j+k][k] / comb[bt][c];
               setp[i][j] = 1;
            }
      }
      
      /*for(int j=c; j<=bt; j++){
         for(int i=1; i<=days; i++)
            cout << setp[i][j] << " ";
         cout << "\n";
      }
      cout << "\n";

      for(int j=c; j<=bt; j++){
         for(int i=1; i<=days; i++)
            cout << fixed << setprecision(4) << p[i][j] << " ";
         cout << "\n";
      }*/

      return p[days][bm];
	}
	
};

// BEGIN CUT HERE 
int main()
{
	BirdsCounting ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
