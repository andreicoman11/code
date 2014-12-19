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
#include <queue>
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

double stars[1024][2];

double dist(int i, int j)
{
  return (stars[i][0]-stars[j][0])*(stars[i][0]-stars[j][0]) + 
           (stars[i][1]-stars[j][1])*(stars[i][1]-stars[j][1]);
}

int main()
{
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n;
    double d;
    cin >> n >> d;
    REP(i, n)
      cin >> stars[i][0] >> stars[i][1];

    int cons = 0;
    d = d*d;
    bool vis[1024] = {0};
    REP(i, n)
      if( vis[i]==0 )
      {
        cons++;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while( !q.empty() )
        {
          int star = q.front();
          q.pop();
          REP(j, n)
            if( !vis[j] && d>=dist(star,j) )
            {
              q.push(j);
              vis[j] = 1;
            }
        }
      }
	
		cout << "Case " << r << ": " << cons << endl;
	}
	
	return 0;
}