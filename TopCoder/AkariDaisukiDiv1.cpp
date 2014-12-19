// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Consider the following function:
// f(X) = Waai + X + Akari + X + Daisuki
// Here, X is a string and + denotes string concatenation.
// Waai, Akari and Daisuki are constant non-empty strings.
// 
// 
// 
// You are given 5 strings Waai, Akari, Daisuki, S and F, and 
// a  int k. 
// Compute how many times F occurs in f^k(S) as its 
// substring. (The notation f^k(S) means that f is applied to 
// S exactly k times in a row. See Notes for a formal 
// definition.) Since the number can be quite large, compute 
// the number modulo 1,000,000,007.
// 
// 
// DEFINITION
// Class:AkariDaisukiDiv1
// Method:countF
// Parameters:string, string, string, string, string, int
// Returns:int
// Method signature:int countF(string Waai, string Akari, 
// string Daisuki, string S, string F, int k)
// 
// 
// NOTES
// -Formally, we have f^1(X)=f(X) and for k greater than one 
// we have f^k(X)=f(f^(k-1)(X)).
// -String A is substring of B if A can be obtained by 
// erasing some (possibly zero) characters from the beginning 
// of B and some (possibly zero) characters from the end of B.
// 
// 
// CONSTRAINTS
// -Waai, Akari, Daisuki, S, and F will contain between 1 and 
// 50 characters, inclusive.
// -Each character of Waai, Akari, Daisuki, S, and F will be 
// a lowercase letter ('a'-'z').
// -k will be between 1 and 10,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// "a"
// "b"
// "c"
// "x"
// "axb"
// 2
// 
// Returns: 2
// 
// S = "x",
// f(S) = "axbxc",
// f^2(S) = f("axbxc") = "aaxbxcbaxbxcc".
// This string contains the substring "axb" twice.
// 
// 1)
// "a"
// "b"
// "c"
// "x"
// "abcdefghij"
// 1
// 
// Returns: 0
// 
// The answer can be zero.
// 
// 2)
// "a"
// "a"
// "a"
// "b"
// "aba"
// 2
// 
// Returns: 4
// 
// S = "b",
// f(S) = "ababa",
// f^2(S) = f("ababa") = "aababaaababaa".
// This string contains the substring "aba" four times. You 
// must count overlapping substrings.
// 
// 3)
// "a"
// "b"
// "c"
// "d"
// "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"
// 58
// 
// Returns: 191690599
// 
// 
// 
// 4)
// "a"
// "x"
// "y"
// "b"
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// 49
// 
// Returns: 1
// 
// 
// 
// 5)
// "waai"
// "akari"
// "daisuki"
// "usushio"
// "id"
// 10000000
// 
// Returns: 127859200
// 
// 
// 
// 6)
// "vfsebgjfyfgerkqlr"
// "ezbiwls"
// "kjerx"
// "jbmjvaawoxycfndukrjfg"
// "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"
// 1575724
// 
// Returns: 483599313
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
#define MOD 1000000007LL

class AkariDaisukiDiv1 {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "axb"; int Arg5 = 2; int Arg6 = 2; verify_case(0, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "abcdefghij"; int Arg5 = 1; int Arg6 = 0; verify_case(1, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arg0 = "a"; string Arg1 = "a"; string Arg2 = "a"; string Arg3 = "b"; string Arg4 = "aba"; int Arg5 = 2; int Arg6 = 4; verify_case(2, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "d"; string Arg4 = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"; int Arg5 = 58; int Arg6 = 191690599; verify_case(3, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arg0 = "a"; string Arg1 = "x"; string Arg2 = "y"; string Arg3 = "b"; string Arg4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; int Arg5 = 49; int Arg6 = 1; verify_case(4, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { string Arg0 = "waai"; string Arg1 = "akari"; string Arg2 = "daisuki"; string Arg3 = "usushio"; string Arg4 = "id"; int Arg5 = 10000000; int Arg6 = 127859200; verify_case(5, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { string Arg0 = "vfsebgjfyfgerkqlr"; string Arg1 = "ezbiwls"; string Arg2 = "kjerx"; string Arg3 = "jbmjvaawoxycfndukrjfg"; string Arg4 = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"; int Arg5 = 1575724; int Arg6 = 483599313; verify_case(6, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

	public: 
   int count(string s, string x)
   {
      if( x.size()>s.size() ) return 0;
      int res = 0;

      for(int i=0; i<s.size()-x.size()+1; i++)
      {
         bool ok = 1;
         for(int j=0; ok && j<x.size(); j++)
            if( s[i+j] != x[j] ) ok = 0;
         if(ok) res++;
      }

      return res;
   }

	int countF(string a, string b, string c, string S, string x, int k) {
		LL res = 0;

      string r = a + S + b + S + c;
      for(int k2=2; k2<=min(4, k); k2++)
         r = a + r + b + r + c;

      LL ri = count(r, x);
      //cout << r << " " << ri << endl;
      if( k<=4 ) return (int)ri;

      string rleft = r.substr(0, x.size()-1);
      string rright = r.substr( r.size()-(x.size()-1) );
      for(int k2=5; k2<=min(52, k); k2++)
      {
         ri = (2*ri + count(a+rleft, x) + count(rright+b+rleft, x) + count(rright+c, x)) % MOD;
         rleft = a + rleft;
         rleft = rleft.substr(0, x.size()-1);
         rright = rright + c;
         rright = rright.substr( rright.size()-(x.size()-1));
         //cout << ri << " " << rleft << " " << rright << endl;
      }

      if( k<=52 ) return (int)ri;
      k -= 52;

      LL ridiff = count(a+rleft, x) + count(rright+b+rleft, x) + count(rright+c, x);
      //cout << ri << " " << ridiff << " " << k << endl;
      LL pow2 = 1;
      while(k)
      {
         pow2 = pow2*2;
         if( pow2 >= MOD ) pow2 -= MOD;
         k--;
      }

      res = ((ri*pow2) % MOD + (ridiff *(pow2-1)) % MOD) % MOD;

      return (int)res;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	AkariDaisukiDiv1 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
