#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)

int pows[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n, m, b;
    cin >> n >> m;
    VI l(m);
    map<int,int> s;
    bool pos[32768] = {0};

    REP(i, m)
    {
      int v = 0;
      REP(j, n)
      {
        cin >> b;
        v = v*2 + b;
      }

      l[i] = v;
    }
    
    SORT(l);
    REVERSE(l);

    REP(i, m)
    {
      FOR(j, 0, pows[n]-1)
      {
        if( pos[j]  )
        {
          int nexts = j^l[i];
          if(pos[ nexts ]==0 || s[ nexts ]>s[j]+1)
          {
            s[ nexts ] = s[j]+1;
            pos[ nexts ] = 1;
          }
        }
      }
      s[l[i]] = 1;
      pos[l[i]] = 1;
    }


		cout << "Case " << r << ": ";
    if( s[pows[n]-1]==0 ) cout << "IMPOSSIBLE\n";
    else cout << (int)s[pows[n]-1] << endl;
	}
	
	return 0;
}