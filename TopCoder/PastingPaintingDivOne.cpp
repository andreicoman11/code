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

char map[128][128];

class PastingPaintingDivOne {
	

	public: 
   int getval(char c)
   {
      if( c=='.' || c==0 ) return 0;
      if( c=='R' ) return 1;
      if( c=='G' ) return 2;
      return 3;
   }
	vector<long long> countColors(vector <string> c, int t) {
		vector<long long> res(4);
      memset(map, 0, sizeof(map));

      for(int i=0; i< min(t, 50); i++)
      {
         for(int j=0; j<c.size(); j++)
         for(int k=0; k<c[j].size(); k++)
            if( c[j][k]!='.' ) {
               res[ getval(map[i+j][i+k]) ]--;
               res[ getval(c[j][k]) ]++;
               map[i+j][i+k] = c[j][k];
            }
         //cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;
      }

      if( t<=50 ) {
         res[0] = res[1];
         res[1] = res[2];
         res[2] = res[3];
         res.resize(3);
         return res;
      }
      
      long long T = (long long)t - (long long)50;
      vector<long long> res2 = res;

      for(int j=0; j<c.size(); j++)
      for(int k=0; k<c[j].size(); k++)
         if( c[j][k]!='.' ) {
            res[ getval(map[50+j][50+k]) ]--;
            res[ getval(c[j][k]) ]++;
            map[50+j][50+k] = c[j][k];
         }
         
      for(int i=1; i<4; i++) {
         res[i] = (res[i] - res2[i]);
         res[i] *= T;
         res[i] += res2[i];
      }
      
      res[0] = res[1];
      res[1] = res[2];
      res[2] = res[3];
      res.resize(3);
      return res;
	}
	
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
