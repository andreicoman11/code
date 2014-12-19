// BEGIN CUT HERE
// PROBLEM STATEMENT
// Elly's memories of last night's sleepover with her friends 
// are rather blurry. She recalls that they played a game 
// involving drinking orange and apple juice. In the 
// beginning there were two identical bottles. One contained 
// a gallon of orange juice, the other a gallon of apple 
// juice. The game was played in turns, starting with turn 
// zero. In even-numbered turns (turn 0, 2, 4, ...) the 
// current player drank half of the remaining orange juice. 
// In odd-numbered turns (turn 1, 3, 5, ...) the current 
// player drank half of the remaining apple juice. The winner 
// of the game is the player who drank the greatest total 
// amount of liquid during the game. If multiple players are 
// tied for the greatest amount, there is no winner.
// 
// For example, consider a game consisting of five turns. 
// Suppose that the players to drink were, in order, Elly, 
// Kriss, Stancho, Elly, and Stancho. (That is, Elly and 
// Stancho both drank twice: Elly in turns 0 and 3, Stancho 
// in turns 2 and 4.) In this game, Elly drank 0.75 gallons 
// of liquid (0.5 gallons of orange juice and 0.25 of apple 
// juice), Kriss drank 0.5 gallons of apple juice, and 
// Stancho drank 0.375 gallons of orange juice (0.25 gallons 
// in turn 2 and another 0.125 gallons in turn 4). In this 
// game Elly would be the winner.
// 
// Elly knows all the people who played the game yesterday, 
// and for each of them the number of times they drank. 
// However, she remembers nothing about the order in which 
// the players drank.
// 
// You are given a vector <string> players, containing the 
// names of all players. If a player's name is contained X 
// times in players that means that he or she drank exactly X 
// times during the game. Determine all people who could have 
// possibly won the game (for some particular order of 
// turns). Return their names as a lexicographically sorted 
// vector <string>. The return value should only contain each 
// of the names once.
// 
// DEFINITION
// Class:EllysJuice
// Method:getWinners
// Parameters:vector <string>
// Returns:vector <string>
// Method signature:vector <string> getWinners(vector 
// <string> players)
// 
// 
// NOTES
// -A sequence of distinct strings is sorted if each element 
// is lexicographically smaller than all the ones following it.
// -string A is lexicographically smaller than string B if A 
// contains smaller character at the first index where they 
// differ. If there is no index where they differ, the 
// shorter one is lexicographically smaller. For example 
// "ariadne" is smaller than "elly", "abc" is smaller than 
// "abd", "aaa" is smaller than "aaaaa", and "czzzzzzz" is 
// smaller than "kaaaaaaa".
// 
// 
// CONSTRAINTS
// -players will contain between 1 and 8 elements, inclusive.
// -Each element of players will contain between 1 and 20 
// characters, inclusive.
// -Each element of players will consist only of lowercase 
// English letters ('a'-'z').
// 
// 
// EXAMPLES
// 
// 0)
// { "elly", "kriss", "stancho", "elly", "stancho" }
// 
// Returns: {"elly", "stancho" }
// 
// Elly would win for the order given in the problem 
// statement. If Stancho and Elly swapped all their turns, 
// Stancho would win the game. Kriss cannot win.
// 
// 1)
// {"torb", "elly", "stancho", "kriss"}
// 
// Returns: { }
// 
// In any valid game two of the four players would be tied 
// for the lead (with half a gallon each).
// 
// 2)
// {"elly", "elly", "elly", "elly", "elly"}
// 
// Returns: {"elly" }
// 
// Since she was the only player, apparently she won.
// 
// 3)
// { "ariadne", "elly", "ariadne", "stancho", "stancho", 
// "kriss", "stancho", "elly" }
// 
// Returns: {"ariadne", "elly", "stancho" }
// 
// Although Stancho has drunk three times, there are 
// orderings in which someone else wins.
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

class EllysJuice {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "elly", "kriss", "stancho", "elly", "stancho" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"elly", "stancho" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getWinners(Arg0)); }
	void test_case_1() { string Arr0[] = {"torb", "elly", "stancho", "kriss"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getWinners(Arg0)); }
	void test_case_2() { string Arr0[] = {"elly", "elly", "elly", "elly", "elly"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"elly" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getWinners(Arg0)); }
	void test_case_3() { string Arr0[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ariadne", "elly", "stancho" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinners(Arg0)); }

// END CUT HERE

	public: 
	vector <string> getWinners(vector <string> p) {
      set<string> res;
      int n = p.size();

      vector<int> perm(n);
      for(int i=0; i<n; i++)
         perm[i] = i;

      do
      {
         vector<string> s(n);
         for(int i=0; i<n; i++)
            s[i] = p[perm[i]];

         double juice[2] = {1.0, 1.0};
         map<string, double> d;
         double maxj = 0.0;
         vector<string> rres;
         for(int i=0; i<n; i++)
         {
            d[s[i]] = d[s[i]] + juice[i%2];
            juice[i%2] *= 0.5;
            if( d[s[i]]>maxj )
            {
               maxj = d[s[i]];
               rres.clear();
               rres.push_back(s[i]);
            }
            else if( d[s[i]]==maxj )
               rres.push_back(s[i]);
         }

         if( rres.size()==1 )
            res.insert( rres[0] );


      }while( next_permutation(perm.begin(), perm.end()) );

      vector<string> finalres(res.begin(), res.end());
      return finalres;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EllysJuice ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
