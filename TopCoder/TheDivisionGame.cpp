// BEGIN CUT HERE
// PROBLEM STATEMENT
// Manao likes to play the Division Game with his friends. 
// This two-player game is played with some collection of 
// natural numbers S. Manao plays first and the players 
// alternate in making a move. A move is choosing some number 
// X from S and a natural number Y &gt 1 such that Y divides 
// X. Then, X is replaced by X / Y in the collection. Note 
// that at any moment the collection may contain multiple 
// copies of the same number. The game proceeds until no more 
// moves can be made. The player who managed to make the last 
// move is declared the winner.
// 
// Since hot debates arise on what numbers should be in S, 
// the friends decided to regularize their choice. They 
// always choose a contiguous interval of numbers [A, B] to 
// be the initial collection S. That is, at the beginning of 
// the game, the collection S contains each of the integers A 
// through B, inclusive, exactly once. Manao knows that A and 
// B will satisfy the condition L &le A &le B &le R. You are 
// given the ints L and R. Count the number of such intervals 
// for which Manao will win the Division Game given that both 
// players play optimally.
// 
// DEFINITION
// Class:TheDivisionGame
// Method:countWinningIntervals
// Parameters:int, int
// Returns:long long
// Method signature:long long countWinningIntervals(int L, 
// int R)
// 
// 
// NOTES
// -Only one number from the collection changes in each move. 
// For example, if the collection contains three copies of 
// the number 8, and the player chooses X=8 and Y=4, only one 
// of the 8s in the collection will change to a 2.
// 
// 
// CONSTRAINTS
// -L will be between 2 and 1,000,000,000, inclusive.
// -R will be between L and L + 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 9
// 10
// 
// Returns: 2
// 
// If the chosen interval is [9,9] or [10,10], the collection 
// S contains only one number. In these two situations Manao 
// can win the game in a single move. On the other hand, if 
// the chosen interval is [9,10], Manao will lose to an 
// optimally playing opponent.
// 
// 
// 1)
// 2
// 5
// 
// Returns: 9
// 
// The only case where Manao loses is if the game starts with 
// the interval [2,3]. Note that if the starting interval is 
// [2,5], Manao can choose X=4 and Y=2 in his first move. 
// After that move, the collection will contain the values 2, 
// 2, 3, and 5.
// 
// 2)
// 2
// 6
// 
// Returns: 13
// 
// Manao will also lose the game if the starting interval is 
// [3,6].
// 
// 3)
// 2
// 100
// 
// Returns: 4345
// 
// 
// 
// 4)
// 12566125
// 12567777
// 
// Returns: 1313432
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
#define DMAX 50010
#define LRMAX 1000020
#define PRIMENR 3500
#define MAXPRIME 31650

int primes[PRIMENR], primenr;
bool isprime[MAXPRIME];

int last[DMAX];
int consec[LRMAX];
int divs[LRMAX];
int val[LRMAX];

class TheDivisionGame {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 10; long long Arg2 = 2LL; verify_case(0, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; long long Arg2 = 9LL; verify_case(1, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; long long Arg2 = 13LL; verify_case(2, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 100; long long Arg2 = 4345LL; verify_case(3, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12566125; int Arg1 = 12567777; long long Arg2 = 1313432LL; verify_case(4, Arg2, countWinningIntervals(Arg0, Arg1)); }

// END CUT HERE

	public: 
	void getprimes()
   {
      for(int i=3; i<MAXPRIME; i++)
         isprime[i] = 1;

      primenr = 1;
      primes[0] = 2;
      for(int i=3; i<MAXPRIME; i+=2)
         if( isprime[i] )
         {
            primes[primenr++] = i;
            for(int j = i+i; j<MAXPRIME; j+=i)
               isprime[j] = 0;
         }
   }

   int getdivs(int x)
   {
      int res = 0;
      int primesi = 2;
      for(int i=0; primesi*primesi<=x && i<primenr; i++, primesi = primes[i])
         if( x%primesi==0 )
         {
            //primesi = primes[i];
            int divs = 1;
            x /= primesi;
            while( x%primesi==0 ) {
               divs++;
               x /= primesi;
            }
            res += divs;
         }
      if( x>1 ) res++;
      return res;
   }

	long long countWinningIntervals(int L, int R) {
      getprimes();
      int nre = R-L;

      for(int i=0; i<=nre; i++)
         val[i] = i+L;

      for(int i=0; i<primenr; i++)
      for(int j= (primes[i] - (L%primes[i])) % primes[i]; j<=nre; j+=primes[i])
         if( val[j]%primes[i]==0 )
         {
            val[j] /= primes[i];
            divs[j]++;
            while( val[j]%primes[i]==0 )
            {
               val[j] /= primes[i];
               divs[j]++;
            }
         }

      for(int i=0; i<=nre; i++)
         if( val[i]>1 ) divs[i]++;

		long long res = 0LL;
      int xo = 0;
      last[0] = 1;
      consec[0] = 0;

      for(int i = L; i<=R; i++)
      {
         xo ^= divs[i-L];
         //std::cout << i << " " ;
         if(last[xo] ) {
            consec[i-L+2] = consec[last[xo]] + 1;
            res += consec[last[xo]] * (consec[last[xo]]+1) / 2;
            res -= consec[i-L+2] * (consec[i-L+2]+1) / 2;
            last[xo] = i-L+2;
         }
         else {
            last[xo] = i-L+2;
            consec[i-L+2] = 0;
         }
      }
		res += (long long)(R-L+1) * (R-L+2) / 2LL;

      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TheDivisionGame ___test; 
	___test.run_test(4); 
} 
// END CUT HERE
