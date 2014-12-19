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
  //char com[100099]; 
	int runs;
	cin >> runs;
  char ch = cin.get();
	for(int r = 1; r<=runs; r++)
	{
    unsigned char c[100] = {0};
    //scanf("%s", com);
    int p = 0;
    //int n = strlen(com);
    ch = cin.get();
    //REP(i, n)
    while( ch!='\n' )
    {
      switch(ch/*com[i]*/) {
        case '>':
          p = ( p==99 ? 0 : p+1);
          break;
        case '<':
          p = ( p==0 ? 99 : p-1);
          break;
        case '-':
          c[p]--;
          break;
        case '+':
          c[p]++;
          break;
        default:
          break;
      }
      ch = cin.get();
    }

    cout << "Case " << r << ": ";
    REP(i, 100 )
    {
      if( c[i]<16  ) cout << "0";
      else
      {
        if( c[i]/16<10 ) cout << (int)c[i]/16;
        else        cout << char(int('A') + c[i]/16 - 10);
      }
      c[i] = c[i]%16;
      if( c[i]<10 ) cout << (int)c[i];
       else      cout << char(int('A') + c[i] - 10);
      if( i<99 ) cout << " ";
    }
    cout << endl;
	}
	
	return 0;
}