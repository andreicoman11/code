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

int main()
{
  int sq[256];
  for(int i=0; i<250; i++)
  {
    sq[i] = i*i;
  }
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int N;
    cin >> N;
    bool done = 0;
    for(int a=0; 3*sq[a]<=N && !done; a++)
    for(int b=0; sq[a]+2*sq[b]<=N && !done; b++)
    {
      int c = (int)sqrt((double)(N-sq[a]-sq[b]));
      if( c*c == N-sq[a]-sq[b] )
      {
        cout << a << " " << b << " " << c << endl;
        done = 1;
      }
    }
	  if( !done ) cout << "-1\n";
	}
	
	return 0;
}