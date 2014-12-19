// BEGIN CUT HERE
// PROBLEM STATEMENT
// Hieroglyphs were widely used for writing in ancient times 
// and they are used in some languages even now. In this 
// problem, we will consider a simplified model of hieroglyphs.
// Let's call a hieroglyph a two-dimensional figure that 
// consists of several segments, each of which has a positive 
// length and is either horizontal or vertical. The segments 
// in the same hieroglyph can touch or intersect each other, 
// but no two segments may overlap. That is, there are no two 
// segments such that the length of their intersection is 
// positive. The segments are considered to be infinitely thin.
// You will be given two hieroglyphs in vector <string> hier1 
// and hier2. Both of them are drawn on the same plane with a 
// Cartesian coordinate system. Each element of hier1 will be 
// a comma-separated list of segments. Each segment is 
// formatted "x1 y1 x2 y2" (quotes for clarity), where (x1, 
// y1) and (x2, y2) are the coordinates of its two endpoints 
// (x1 ? x2, y1 ? y2). The set of all segments of the first 
// hieroglyph is the union of all segments presented in 
// elements of hier1. The set of all segments of the second 
// hieroglyph is given in the same format in elements of 
// hier2. It is guaranteed that both hier1 and hier2 describe 
// valid hieroglyphs as defined in the previous paragraph.
// You are allowed to move each of the hieroglyphs to an 
// arbitrary place on the plane via translation (See notes). 
// No other operations like applying rotation or symmetry are 
// allowed.
// Once the positions for each hieroglyph are chosen, their 
// union is defined as a set of points on the plane that 
// belong to at least one of them. It's easy to see that 
// union of two hieroglyphs can be represented as a set of 
// non-overlapping segments. You are to minimize the total 
// length of these segments.
// Return this minimum possible total length.
// 
// DEFINITION
// Class:Hieroglyphs
// Method:minimumVisible
// Parameters:vector <string>, vector <string>
// Returns:int
// Method signature:int minimumVisible(vector <string> hier1, 
// vector <string> hier2)
// 
// 
// NOTES
// -Translation is an operation that moves every point a 
// constant distance in a specified direction. More exactly, 
// an arbitrary vector (dx, dy) is first chosen, and then 
// translation works as moving each point (x, y) to (x + dx, 
// y + dy).
// 
// 
// CONSTRAINTS
// -hier1 and hier2 will each contain between 1 and 50 
// elements, inclusive.
// -Each element of hier1 and hier2 will contain between 1 
// and 50 characters, inclusive.
// -Each element of hier1 and hier2 will be a single comma 
// separated list of between 1 and 4 segment descriptions, 
// inclusive, without leading and trailing commas.
// -Each segment description will be formatted "x1 y1 x2 y2" 
// (quotes for clarity), where x1, y1, x2 and y2 are integers 
// between 0 and 80, inclusive, with no extra leading zeros.
// -In each segment description, x1 will be less than or 
// equal to x2 and y1 will be less than or equal to y2.
// -Each segment will be either horizontal or vertical and 
// will have a positive length.
// -No two segments of the same hieroglyph will overlap (as 
// defined in the statement).
// 
// 
// EXAMPLES
// 
// 0)
// {"0 0 10 0,10 0 10 3"}
// {"0 1 10 1","5 1 5 4"}
// 
// Returns: 16
// 
// 
// 
// 
// Here it's better to combine the horizontal line segments 
// than the vertical ones.
// 
// 1)
// {"1 1 1 5"}
// {"3 2 5 2"}
// 
// Returns: 6
// 
// 
// 
// There is no way to combine the hieroglyphs in such a way 
// that segments overlap.
// 
// 2)
// {"0 2 6 2"}
// {"5 1 6 1,8 1 9 1"}
// 
// Returns: 6
// 
// 
// 
// 
// 3)
// {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"}
// {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}
// 
// 
// Returns: 65
// 
// 
// 
// 4)
// {"10 10 10 20,10 30 10 40","10 10 20 10"}
// {"10 0 10 20,10 27 10 35","10 0 20 0"}
// 
// Returns: 45
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

struct hier{
  int x1, x2, y1, y2;
};

int h1no[2], h2no[2];
hier h1[2][512];
hier h2[2][512];


class Hieroglyphs {
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0 10 0,10 0 10 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 10 1","5 1 5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(0, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 1 1 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 2 5 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 2 6 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 1 6 1,8 1 9 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 65; verify_case(3, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"10 10 10 20,10 30 10 40","10 10 20 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 0 10 20,10 27 10 35","10 0 20 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 45; verify_case(4, Arg2, minimumVisible(Arg0, Arg1)); }

// END CUT HERE
  void gosort(hier hh[512], int hor, int n)
  {
    bool go = 1;
    while(go)
    {
      go = 0;
      for(int i=0; i<n-1; i++)
        if( (hor==0 && ( (hh[i].x1 > hh[i+1].x1) || (hh[i].x1==hh[i+1].x1 && hh[i].y1 > hh[i+1].y1) )) ||
            (hor==1 && ( (hh[i].y1 > hh[i+1].y1) || (hh[i].y1==hh[i+1].y1 && hh[i].x1 > hh[i+1].x1) )) )
          {
            hier aux;
            memcpy(&aux, &hh[i], sizeof(aux));
            memcpy(&hh[i], &hh[i+1], sizeof(aux));
            memcpy(&hh[i+1], &aux, sizeof(aux));
            go = 1;
          }
    }
  }
  int getdif(int a, int b, int c, int d)
  {
    if( c<=a && b<=d ) return b-a;
    else if( a<=c && d<=b ) return d-c;
    else if( c<=b && b<=d ) return b-c;
    else if( c<=a && a<=d ) return d-a;
    return 0;
  }
	public: int minimumVisible(vector <string> hier1, vector <string> hier2) {
    int tlen=0;
    int a, b, c, d, e;
    memset(h1no, 0, sizeof(h1no));
    memset(h2no, 0, sizeof(h2no));

		for(int i=0; i<hier1.sz; i++)
      while( hier1[i].sz>0 )
      {
        string str = hier1[i].substr(0, hier1[i].find(","));
        if( hier1[i].find(",") !=-1 ) hier1[i] = hier1[i].substr(hier1[i].find(",")+1);
        else hier1[i] = "";
        istringstream in(str);
        in >> a >> b >> c >> d;
        if( a==c )  e = 0;
        else        e = 1;
        h1[e][h1no[e]].x1 = a;
        h1[e][h1no[e]].y1 = b;
        h1[e][h1no[e]].x2 = c;
        h1[e][h1no[e]].y2 = d;
        tlen += c+d-a-b;
        h1no[e]++;
      }

    for(int i=0; i<hier2.sz; i++)
      while( hier2[i].sz>0 )
      {
        string str = hier2[i].substr(0, hier2[i].find(","));
        if( hier2[i].find(",") !=-1 ) hier2[i] = hier2[i].substr(hier2[i].find(",")+1);
        else hier2[i] = "";
        istringstream in(str);
        in >> a >> b >> c >> d;
        if( a==c )  e = 0;
        else        e = 1;
        h2[e][h2no[e]].x1 = a;
        h2[e][h2no[e]].y1 = b;
        h2[e][h2no[e]].x2 = c;
        h2[e][h2no[e]].y2 = d;
        tlen += c+d-a-b;
        h2no[e]++;
      }

    for(int k=0; k<2; k++)
    { gosort(h1[k], k, h1no[k]); gosort(h2[k], k, h2no[k]); }


    int mlen = tlen;

    for(int x=-80; x<80; x++)
    for(int y=-80; y<80; y++)
    {
      int len = 0;
      for(e = 0; e<2; e++)
      {
        int i = 0, j = 0;
        while ( i<h1no[e] && j<h2no[e] )
        {
          if( e==0 )
          {
            if( h1[e][i].x1+x == h2[e][j].x1 )
            {
              len += getdif( h1[e][i].y1+y, h1[e][i].y2+y, h2[e][j].y1, h2[e][j].y2);
            }

            if( h1[e][i].x1+x < h2[e][j].x1 || 
                (h1[e][i].x1+x == h2[e][j].x1 && (h1[e][i].y2+y < h2[e][j].y2) ) )
                i++;
            else j++;
          }
          else
          {
            if( h1[e][i].y1+y == h2[e][j].y1 )
            {
              len += getdif( h1[e][i].x1+x, h1[e][i].x2+x, h2[e][j].x1, h2[e][j].x2);
            }

            if( h1[e][i].y1+y < h2[e][j].y1 || 
                (h1[e][i].y1+y == h2[e][j].y1 && (h1[e][i].x2+x < h2[e][j].x2) ) )
                i++;
            else j++;
          }
        }

      }
      mlen = min(mlen, tlen-len);
    }

    return mlen;
	}
	
};

// BEGIN CUT HERE 
int main()
{
	Hieroglyphs ___test; 
  vector<string> vstr1, vstr2;
  vstr1.pb("17 7 18 7,6 0 12 0,21 7 30 7");
  vstr2.pb("14 13 19 13,1 25 27 25,0 5 23 5");
  cout << ___test.minimumVisible( vstr1, vstr2) << "\n";
	___test.run_test(-1); 
} 
// END CUT HERE
