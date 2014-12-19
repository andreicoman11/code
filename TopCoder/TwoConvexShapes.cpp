// BEGIN CUT HERE
// PROBLEM STATEMENT
// A platypus has been given the mission to paint the cells 
// on a grid either black or white according to the following 
// two conditions:
// 
// For each color, all cells of that color must be connected.
// Formally, a pair of cells of color X is connected if there 
// is a path of adjacent cells of color X between them.
// (Two cells are adjacent if they share a common edge.)
// We require that for each color, each pair of cells of that 
// color must be connected.
// All the cells of each color must form a convex shape. 
// A group of cells of a given color is convex if in each row 
// and each column the cells of that color form a connected 
// segment (possibly taking the whole row or column).
// In other words, whenever two cells of the same color share 
// the same row or the same column, all cells between them 
// must also have that particular color.
// 
// The platypus is also allowed to paint the grid completely 
// white or black.
// 
// The platypus may have already painted some of the cells. 
// The current state of the grid is given as a vector 
// <string> grid. The i-th character of the j-th element of 
// grid that represents the cell at row j, column i is 'W' if 
// it has been painted white, 'B' if it has been painted 
// black, and '?' if it does not have a color yet. Let X be 
// the number of different ways how to color the rest of the 
// grid according to the above conditions. Return the value X 
// modulo 1000000007 (10^9 + 7). Two ways to color a grid are 
// different if the color of at least one cell differs.
// 
// 
// 
// DEFINITION
// Class:TwoConvexShapes
// Method:countWays
// Parameters:vector <string>
// Returns:int
// Method signature:int countWays(vector <string> grid)
// 
// 
// CONSTRAINTS
// -grid will contain between 1 and 50 elements, inclusive.
// -Element 0 of grid will contain between 1 and 50 
// characters, inclusive.
// -The remaining elements of grid will contain the same 
// number of characters as element 0.
// -Each character in each element of grid will be one of 
// 'B', 'W', and '?' (quotes for clarity).
// 
// 
// EXAMPLES
// 
// 0)
// {"??",
//  "??"}
// 
// Returns: 14
// 
// Of all the 16 different ways to color the grid, only the 
// following 2 are not valid.
// 
// BW WB
// WB BW
// 
// This is because cells of the same color are not connected.
// 
// 1)
// {"B?",
//  "??"}
// 
// Returns: 7
// 
// The following seven ways to color the grid are correct:
// 
// BB BW BB BW BB BB BW
// BB BW WW WW WB BW BB
// 
// 
// 2)
// {"WWB",
//  "WWW",
//  "WWW",
//  "WWW"}
// 
// Returns: 1
// 
// All colors have already been picked. The only possible 
// coloring is already valid.
// 
// 3)
// {"BBBBBB",
//  "WWBBBB",
//  "WBBBBB"}
// 
// Returns: 0
// 
// This coloring of the grid is not valid, the black cells do 
// not form a convex shape.
// 
// 4)
// {"?BB?",
//  "BBBB",
//  "?BB?"}
// 
// Returns: 5
// 
// 
// 
// 5)
// {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
//  "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
//  "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
//  "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
//  "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
//  "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
//  "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
//  "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
//  "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
//  "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
//  "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
//  "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
//  "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
//  "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
//  "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
//  "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
//  "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
//  "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
//  "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
//  "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
//  "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
//  "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
//  "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
//  "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
//  "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
//  "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
//  "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
//  "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
//  "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
//  "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}
// 
// Returns: 73741817
// 
// Each of the 2^30 ways to color the remaining cells in the 
// grid is valid.
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
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define LL long long
#define pb push_back
#define sz size()
#define MOD 1000000007

int t[64][64];

class TwoConvexShapes {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"WWB",
 "WWW",
 "WWW",
 "WWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBBBB",
 "WWBBBB",
 "WBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"?BB?",
 "BBBB",
 "?BB?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, countWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(5, Arg1, countWays(Arg0)); }

// END CUT HERE

	public: 
   int verifAll(VVI v)
   {
      bool ones=0, twos=0;
      for(int i=0; i<v.sz; i++)
      for(int j=0; j<v[i].sz; j++)
         if( v[i][j]==1 ) ones=1;
         else if (v[i][j]==2 ) twos++;
      
      return 2 - ones - twos;
   }

   VVI checkv(VVI v, int cul)
   {
      int n = v.sz, m = v[0].sz;
      VVI a(n);
      int cul2 = 3 - cul;
      for(int i=0; i<n; i++)
      {
         a[i].resize(2);
         a[i][0] = m-1; // last element eq to cul
         a[i][1] = 0; // first elem eq to cul2
         int j = 0;
         while( j<m && v[i][j]!=cul2 )
            j++;
         a[i][1] = j;
         j = m-1;
         while( j>=0 && v[i][j]!=cul )
            j--;
         a[i][0] = j;
      }
      return a;
   }
   
   VVI checkv2(VVI v, int cul)
   {  // check column wise
      int n = v.sz, m = v[0].sz;
      VVI a(m);
      int cul2 = 3 - cul;
      for(int i=0; i<m; i++)
      {
         a[i].resize(2);
         a[i][0] = n-1; // last element eq to cul
         a[i][1] = 0; // first elem eq to cul2
         int j = 0;
         while( j<n && v[j][i]!=cul2 )
            j++;
         a[i][1] = j;
         j = n-1;
         while( j>=0 && v[j][i]!=cul )
            j--;
         a[i][0] = j;
      }
      return a;
   } 

   int common(VVI v)
   {
      VVI a = checkv(v, 1);
      if( a[0][1]<v[0].sz || a[a.sz-1][0]>=0 ) return 0;

      int res = 0;
      int i = 0;
      while( i<v.size()-1 && a[i][1]==v[i].sz ) {
         i++;
         res++;
         if( a[i][0]>=0 ) res = 0;
      }
      if( i==v.size()-1 ) return res;

      while( i<v.size()-1 )
      {
         if( a[i][0]>=0 ) return 0;
         i++;
      }
      return res;
   }

   int corner1(VVI v, int cul)
   {  // 1 max corner, color = 2
      memset(t, 0, sizeof(t));
      int n = v.sz, m = v[0].sz;

      VVI a(n);
      int cul2 = 3 - cul;
      for(int i=0; i<n; i++)
      {
         a[i].resize(2);
         a[i][0] = 0; // last element eq to cul
         a[i][1] = m+1; // first elem eq to cul2
         for(int j=m; j; j--)
            if( v[i][j-1]==cul2 )
               a[i][1] = j;
         
         int j = m;
         while( j>=1 && v[i][j-1]!=cul )
            j--;
         a[i][0] = j;
      }
      
      for(int i=1; i<n; i++)
         if( a[i][1]<a[i][0] )
            return 0;

      if( a[n-1][0]>=1 ) return 0;
      for(int i=min(m-1, a[0][1]-1), x=1; i>=max(1,a[0][0]); i--) {
         t[0][i] = 1;
      }
      
      for(int i=1; i<n; i++) 
      {
         for(int j=a[i][0]; j<a[i][1]; j++)
         {
            for(int k=j; k<a[i-1][1]; k++)
               t[i][j] = (t[i][j] + t[i-1][k]) % MOD;
         }
      }
      /*for(int i=0; i<n; i++){
      for(int j=0; j<=m; j++)
         cout << t[i][j] << " ";
      cout << endl;
      }*/

      return t[n-1][0];
   }

   int corner2(VVI v)
   {  // 1 max 2 corners, color = 1
      memset(t, 0, sizeof(t));
      int n = v.sz, m = v[0].sz;
      // check first row for other color, last row for color to be made
      for(int i=0; i<m; i++)
         if( v[0][i]==2 || v[n-1][i]==1 ) return 0;

      VVI a = checkv2(v, 1);
      
      for(int j=1; j<m; j++)
         if( a[j][1]<a[j][0] )
            return 0;

      for(int i=min(n-2, a[0][1]-1), x=1; i>=a[0][0]; i--){
         t[i][0] = 1;
      }
      
      for(int j=1; j<m; j++)
      {
         for(int i=min(n-2,a[j][1]-1); i>=max(0,a[j][0]); i--)
         {
            for(int k=i; k<=min(n-2,a[j-1][1]-1); k++)
               t[i][j] = (t[i][j] + t[k][j-1]) % MOD;
         }
      }

      /*for(int i=0; i<n; i++){
      for(int j=0; j<=m; j++)
         cout << t[i][j] << " ";
      cout << endl;
      }*/
      LL res = 0;
      for(int i=0; i<=n-2; i++)
         res = (res + t[i][m-1]) % MOD;
      //return t[0][m-1];
      return res;
   }
   VVI rotate(VVI v)
   {
      int n = v.sz, m = v[0].sz;
      VVI v2(m);
      for(int j=0; j<m; j++)
      {
         v2[j].resize(n);
         for(int i=0; i<n; i++)
            v2[j][n-i-1] = v[i][j];
      }
      return v2;
   }
   VVI transl(VVI v)
   {
      int n = v.sz, m = v[0].sz;
      VVI v2(n);
      for(int i=0; i<n; i++)
      {
         v2[i].resize(m);
         for(int j=0; j<m; j++)
            v2[i][j] = v[i][m-j-1];
      }
      return v2;
   }
	int countWays(vector <string> grid) {
      VVI v;
      v.resize(grid.sz);
      for(int i=0; i<grid.sz; i++)
      {
         v[i].resize(grid[i].sz);
         for(int j=0; j<grid[i].sz; j++)
            if( grid[i][j]=='B' ) v[i][j] = 1;
            else if (grid[i][j]=='W' ) v[i][j] = 2;
      }
     
      LL rez = verifAll(v);

      if( v[0].sz==1 ) v = rotate(v);
      if( v.sz==1 )
      {
         if( v[0].sz==1 ) return rez;
         VVI x(2);
         bool add = 1;
         for(int i=0; i<v[0].sz; i++)
         {
            x[0].pb(1);
            x[1].pb(v[0][i]);
            if( v[0][i]!=0 ) add=0;
         }
         v = x;
         if (add ) rez--;
      }


      //cout << "verifALL " << rez << endl;

      // check for 1 corner for both colors (==checks for 3 corners)
      for(int c=1; c<=2; c++)
      for(int i=0; i<4; i++)
      {
         rez = (rez + corner1(v, c)) % MOD;
         cout << "corner1 " << rez << /*"\t" << count_1(v, c) << */endl;
         v = rotate(v);
      }

      // check for 2 corners for one color (==checking for 2 corners)
      for(int i=0; i<4; i++)
      {
         rez = (rez + corner2(v)) % MOD;
         cout << "corner2 " << rez << endl;
         rez = (rez + corner2(transl(v))) % MOD;
         cout << "corner 2 transl " << rez << endl;
         rez = (rez - common(v) + MOD) % MOD;
         cout << "common " << rez << /*"\t" << count_2(v, 1) << */endl;
         v = rotate(v);
      }

     
      return rez;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	TwoConvexShapes ___test;
   //vector<string> vstr;
   char aux[45][3]= { "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "B?",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "B?",
	                   "??",
	                   "B?",
	                   "??",
	                   "?B",
	                   "??",
	                   "?B",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "??",
	                   "B?",
	                   "?B",
	                   "??",
	                   "??",
	                   "??",
	                   "??"};

                     /*{  "?????????", 
                        "???????W?", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "??????W??",
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????", 
                        "?????????"};*/
   vector<string> vstr(45);
   for(int i=0; i<45; i++)
   for(int j=0; j<2; j++)
      vstr[i].push_back(aux[i][j]);
   //vstr[0] = "?WW";//"?B??";
   //vstr[1] = "B?W";//"??W?";
   //vstr[2] = "BB?";//"???B";
   //vstr[3] = "????";//"?WWW";
   //vstr.push_back("???????W????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????W???????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("???W????????????????");
   //vstr.push_back("??????????????????W?");
   //vstr.push_back("????????????????????");
   //vstr.push_back("???????W????????????");
   //vstr.push_back("??????????B?????????");
   //vstr.push_back("??????W?????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   //vstr.push_back("???????????????????W");
   //vstr.push_back("????????????????????");
   //vstr.push_back("????????????????????");
   ////vstr.push_back("????????????????????");
   //vector<string> vstr(1);
   //vstr[0] = "?";
   cout << ___test.countWays(vstr);
	___test.run_test(-1); 
} 
// END CUT HERE
