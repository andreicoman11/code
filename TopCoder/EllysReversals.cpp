// BEGIN CUT HERE
// PROBLEM STATEMENT
// Elly has a list of several distinct strings given in the 
// vector <string> words. She can apply the following 
// operation as many times as she wants (including zero times):
// 
// Choose one of the words and call it S.
// Choose an even number k between 2 and |S|, inclusive, 
// where |S| is the length of S (thus, chose a prefix with 
// even length).
// Reverse the order of the first k characters of S (thus, 
// reverse the chosen prefix without the rest of the word).
// 
// For example, if she has the word "topcoder", she can 
// reverse its first 2, 4, 6, or all 8 characters. If she 
// chooses to reverse its first 4 characters, the change will 
// be: "topcoder" -> "cpotoder". If at a later time she 
// decides to chose the same string and reverse all of its 
// characters (which is also a valid prefix with even 
// length), she would get "cpotoder"->"redotopc".
// 
// After performing some operations two strings might become 
// equal. If that happens, Elly crosses them out and 
// continues playing her game with the remaining strings 
// only, i.e. they "disappear" from the list. The girl 
// wonders what is the minimal number of strings she can end 
// up with.
// 
// For example, suppose she has the strings {"esprit", "god", 
// "redotopc", "odcpoter", "dog"}. The word "redotopc" can be 
// converted to "topcoder" by first reversing all 8 
// characters and then reversing the first 4. The word 
// "odcpoter" can also be converted to "topcoder" by 
// performing "odcpoter" -> "docpoter" -> "topcoder". At that 
// point the words become equal and disappear, leaving Elly 
// only with {"esprit", "god", "dog"}. This is where she gets 
// stuck: The words "god" and "dog" cannot become equal, 
// because she can only reverse prefixes with even length. 
// Thus, the minimal number of words she can get is 3.
// 
// Given her initial strings in vector <string> words, return 
// an int indicating the minimal number of strings she can be 
// left with.
// 
// DEFINITION
// Class:EllysReversals
// Method:getMin
// Parameters:vector <string>
// Returns:int
// Method signature:int getMin(vector <string> words)
// 
// 
// CONSTRAINTS
// -words will contain between 1 and 50 elements, inclusive.
// -Each element of words will contain between 1 and 50 
// characters, inclusive.
// -Each element of words will consist only of lowercase 
// letters of the English alphabet ('a'-'z').
// -All elements of words will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {"esprit", "god", "redotopc", "odcpoter", "dog"}
// 
// Returns: 3
// 
// The example from the problem statement.
// 
// 1)
// {"no", "zaphod", "just", "very", "improbable"}
// 
// Returns: 5
// 
// It is possible that she cannot get rid of any of the words.
// 
// 2)
// {"rats", "live", "stressed", "to", "act", "as", "star", 
// "desserts", "of", "evil", "cat", "sa", "fo", "ot"}
// 
// Returns: 0
// 
// It is possible that she ends up with zero words.
// 
// 3)
// {"topcoder", "redocpot", "doretopc", "cpotdoer", 
// "harlemshake"}
// 
// Returns: 1
// 
// Sometimes it is possible to match different words when 
// using a different sequence of operations.
// 
// 4)
// {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", 
// "nqlwgmcyvdikt",
//  "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", 
// "bwhykzupcux",
//  "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", 
// "dkbktqdtgfujcut",
//  "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", 
// "pqhbsiujwda",
//  "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", 
// "yovinyguyudmv"}
// 
// Returns: 16
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

class EllysReversals {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"esprit", "god", "redotopc", "odcpoter", "dog"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arr0[] = {"no", "zaphod", "just", "very", "improbable"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arr0[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arr0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arr0[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(4, Arg1, getMin(Arg0)); }

// END CUT HERE

	public: 
	int getMin(vector <string> w) {
		int n = w.size(); 
      vector<bool> hasm(n);

      for(int i=0; i<w.size(); i++)
         if( hasm[i]==0 )
         for(int j=i+1; j<w.size(); j++)
            if( hasm[j]==0 ) {

               if( w[i].size()!=w[j].size() ) continue;
               if( w[i].size()%2 && w[i][w[i].size()-1]!=w[j][w[j].size()-1] ) continue;

               map<string, int> m;
               for(int k=0; k<w[i].size()-1; k+=2) {
                  string aux = w[i].substr(k, 2);
                  sort(aux.begin(), aux.end());
                  m[ aux ]++;
               }
               
               for(int k=0; k<w[i].size()-1; k+=2) {
                  string aux = w[j].substr(k, 2);
                  sort(aux.begin(), aux.end());
                  m[ aux ]--;
               }

               bool ok = 1;
               for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++)
                  if( it->second!=0 ) ok = 0;
               if( ok ) {
                  hasm[i] = hasm[j] = 1;
                  break;
               }
            }

      int res = 0;
      for(int i=0; i<n; i++)
         res += (hasm[i]==0);
      return res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	EllysReversals ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
