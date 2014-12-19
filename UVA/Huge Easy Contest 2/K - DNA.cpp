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

int comb[16][16];
int n, k;
int threes[] = {1,3,9,27,81,243};
char elem[] = {'A','C','G','T'};
char adn[16];
char v[16];

void precomp()
{
  REP(i, 11)
    comb[i][0] = comb[i][i] = 1;

  FOR(i, 1, 11)
  FOR(j, 1, i)
    comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
}

int dif(int n2)
{
  int diff = 0;
  REP(i, n2)
    if( adn[i]!=v[i] ) diff++;
  return diff;
}

void back(int i, char v[10])
{
  if( i>=k && dif(i)>k )
      return;
  
  if( i>=n )
  {
    // print sol
    REP(i, n)
      printf("%c", v[i]);
    printf("\n");
    return;
  }

  REP(j, 4)
  {
    v[i] = elem[j];
    back(i+1, v);
  }
}

int main()
{
  precomp();
	int runs;
	cin >> runs;
	for(int r = 1; r<=runs; r++)
	{
	  cin >> n >> k;
    REP(i, n)
    {
      cin >> adn[i];
    }
    adn[n] = '\0';

    long long pos = 1;
    FOR(i, 1, k+1)
      pos += (long long)comb[n][i] * (long long)threes[i];
    cout << pos << endl;

    v[k] = '\0';
    back(0, v);
  }

	return 0;
}