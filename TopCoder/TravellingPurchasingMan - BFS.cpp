// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are interested in purchasing items from a number of 
// stores in a local market. The market is composed of N 
// stores numbered from 0 to N-1. The stores with numbers 
// from 0 to M-1 are interesting to you and all the other 
// stores are not interesting. Some pairs of stores are 
// connected by roads.
// 
// You are given a vector <string> interestingStores which 
// contains M elements and describes the interesting stores. 
// The i-th element corresponds to store i and is formatted 
// "OPEN CLOSE DURATION" (quotes for clarity), where OPEN is 
// the opening time (in seconds), CLOSE is the closing time 
// (in seconds) and DURATION is the time (in seconds) 
// required to make a purchase in this store. You can 
// initiate a purchase from a store at any time T between 
// OPEN and CLOSE, inclusive. In order to do so, you need to 
// arrive to the store at time T (or earlier). The purchase 
// will be finalized at time T + DURATION and you need to 
// stay at the store for the entire duration of your 
// purchase. Note that it is possible for a purchase to end 
// when the store is already closed. You cannot make multiple 
// purchases in the same store.
// 
// The roads are given by the vector <string> roads. Each 
// element of roads describes a single bidirectional road and 
// is formatted "A B LENGTH" (quotes for clarity). Here A and 
// B are the numbers of stores connected by the road and 
// LENGTH is the time (in seconds) required to move from A to 
// B (or from B to A) using this road.
// 
// Your start at time 0 at the location of store N-1. Return 
// the maximum number of purchases in interesting stores that 
// you can make.
// 
// DEFINITION
// Class:TravellingPurchasingMan
// Method:maxStores
// Parameters:int, vector <string>, vector <string>
// Returns:int
// Method signature:int maxStores(int N, vector <string> 
// interestingStores, vector <string> roads)
// 
// 
// NOTES
// -You are allowed to wait for any amount of time at any 
// location.
// 
// 
// CONSTRAINTS
// -N will be between 1 and 50, inclusive.
// -roads will contain between 1 and 50 elements, inclusive.
// -Each element of roads will be formatted "A B LENGTH" 
// (quotes for clarity), where A, B and LENGTH are integers 
// with no unnecessary leading zeros.
// -In each road, A and B will each be between 0 and N-1, 
// inclusive.
// -In each road, A and B will be distinct.
// -In each road, LENGTH will be between 1 and 604,800, 
// inclusive.
// -There will exist at most one road between each pair of 
// stores.
// -interestingStores will contain between 1 and min{16, N} 
// elements, inclusive,
// -Each element of interestingStores will be formatted "OPEN 
// CLOSE DURATION" (quotes for clarity), where OPEN, CLOSE 
// and DURATION are integers with no unnecessary leading zeros.
// -In each store, OPEN will be between 0 and 604,800, 
// inclusive.
// -In each store, CLOSE will be between OPEN+1 and 604,800, 
// inclusive.
// -In each store, DURATION will be between 1 and 604,800, 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {"1 10 10" , "1 55 31", "10 50 100" }
// {"1 2 10"}
// 
// Returns: 1
// 
// It is not possible to make more than one purchase:
// If you decide to make the purchase at store 2: You need to 
// wait 10 seconds until it opens. Then wait until time = 110 
// seconds for the purchase to finish. At 110 seconds, all 
// the other stores will be closed.
// If you instead decide to make the purchase at store 1: You 
// first need travel through the road and arrive store 1 at 
// time = 10. The purchase finishes at time = 41. After you 
// travel back to store 2, the time will be 51 seconds and 
// store 2 will be closed.
// There is no way to reach store 0 when store 2 is the 
// starting point.
// 
// 
// 1)
// 3
// {"1 10 10" , "1 55 30", "10 50 100" }
// {"1 2 10"}
// 
// Returns: 2
// 
// This time we can travel to store 1, make the purchase and 
// return to store 2 exactly at time = 50 to make two 
// purchases in total.
// 
// 
// 2)
// 5
// {"0 1000 17"}
// {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}
// 
// Returns: 0
// 
// It is not possible to reach store 0 before it closes.
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

const int INF = 0x3f3f3f3f;
int m, n, e[64][64], maxvis;
int stores[64][3];
int vis[1<<16][16];

class TravellingPurchasingMan {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 30; string Arr1[] = {"44017 51380 10445", "43326 45781 10826", "1858 7620 55820", "59671 69374 49335", "43469 91557 19846", "56665 62962 9195", "23925 83744 36638", "24987 36482 16873", "49497 91643 8310", "37946 80751 6922", "40836 87754 48723", "22729 38381 19605", "24733 66899 58724"}; 
   vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 58347", "0 3 12218", "3 5 36887", "5 6 28245", "3 4 41830", "3 9 23633", "9 2 16042", "2 7 28163", "9 16 51186", "16 10 59664", "7 15 5895", "7 14 11381", "2 21 25986", "9 23 38346", "21 12 58189", "9 27 52827", "0 18 12855", "10 26 21285", "15 25 1589", "25 13 30677", "5 19 18386", "12 28 26422", "11 26 10195", "15 5 20557", "22 28 28994", "1 23 49421", "29 16 15007", "12 23 25646", "28 13 51562", "24 19 4146", "15 18 58771", "1 27 31312", "24 20 46064", "1 16 42453", "15 1 29331", "3 6 38801", "20 2 46850", "22 3 31069", "16 21 35728", "1 10 46523", "26 29 54648", "6 21 31583"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }

// END CUT HERE

	public: 
   int ones(int x) {
      int res = 0;
      while(x) {
         res += x%2;
         x /= 2;
      }
      return res;
   }

	int maxStores(int N, vector <string> ist, vector <string> roads) {
		memset(e, 0, sizeof(e));
      n = N;

      for(int i=0; i<(int)roads.size(); i++) {
         istringstream in(roads[i]);
         int a, b, len;
         in >> a >> b >> len;
         e[a][b] = e[b][a] = len;
      }
      
      for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
         if( i!=j && e[i][k] && e[k][j] &&
            (e[i][j]==0 || e[i][j]>e[i][k]+e[k][j] ) )
            e[i][j] = e[i][k] + e[k][j];

      m = ist.size();
      for(int i=0; i<m; i++) {
         istringstream in(ist[i]);
         in >> stores[i][0] >> stores[i][1] >> stores[i][2];
      }
      
      maxvis = 0;
      memset(vis, INF, sizeof(vis));
      for(int i=0; i<m; i++) {
         int t = e[n-1][i];
         if( t || i==n-1 ) {
            if( stores[i][1]<t ) continue;
            t = max(t, stores[i][0]);
            t += stores[i][2];
            vis[1<<i][i] = t;
         }
      }

      for(int i=1; i<(1<<m); i++) {
         int one = ones(i);
         for(int j=0; j<m; j++)
            if( (i & (1<<j)) && vis[i][j]!=INF ) {
               maxvis = max(maxvis, one);
               for(int k=0; k<m; k++)
                  if( (i & (1<<k))==0 && e[j][k]) {
                     int t = vis[i][j] + e[j][k];
                     if( t>stores[k][1] ) continue;
                     t = max(t, stores[k][0]) + stores[k][2];
                     vis[i | (1<<k)][k] = min(vis[i | (1<<k)][k], t);
               }
            }
      }

      return maxvis;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TravellingPurchasingMan ___test; 
	___test.run_test(2); 
} 
// END CUT HERE
