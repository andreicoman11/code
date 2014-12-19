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

long long comb[50][50];

int main()
{
  for(int i=0; i<=50; i++)
    comb[i][0] = comb[i][i] = 1;
  for(int i=1; i<=50; i++)
  for(int j=1; j<i; j++)
    comb[i][j] = comb[i-1][j-1] + comb[i-1][j];

	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    string a="", b="";
    char c;
    cin >> c;//read (
    cin >> c;// read a
    while( isalpha(c) )
    {
      a+=c;
      cin >> c;
    }
    // just read +
    cin >> c; // read b
    while( isalpha(c) )
    {
      b+=c;
      cin >> c;
    }// just read(
    cin >> c;
    int k;
    cin >> k;
    //cout << a << " " << b << " " << k << endl;

    cout << "Case " << r << ": ";
    for(int i=0; i<=k; i++)
    {
      if( comb[k][i]>1 ) cout << comb[k][i] << "*";
      int p1 = k-i;
      int p2 = i;
      if( p1 ) cout << a;
      if( p1>1 ) cout << "^" << p1;

      if( p1 && p2 ) cout << "*";
      if(p2)  cout << b;
      if( p2>1 ) cout << "^" << p2;
      if( i<k ) cout << "+";
    }     
	  cout << endl;		
	}
	
	return 0;
}