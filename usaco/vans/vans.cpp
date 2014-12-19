/*
ID: andreic4
PROG: vans
LANG: C++
*/
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
#include <queue>
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
#define INFILE "vans.in" 
#define OUTFILE "vans.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);

//                1, 2, 3, 4, 5, 6, 7, 8
bool tr[8][8] = {{0, 0, 1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 1, 0, 0, 0},
                 {1, 0, 0, 1, 0, 1, 0, 1}, 
                 {0, 0, 1, 0, 0, 0, 0, 0}, 
                 {0, 1, 0, 0, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0, 1, 0},
                 {0, 0, 1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 0, 1, 0, 1}};

class num{
  int v[1000];
  int len;
public:
  num() : len(0)
  {
    memset(v, 0, sizeof(v));
  }
  void init()
  {
    v[0] = 1;
  }
  void add(const num& nr)
  {
    int i = 0, t = 0;
    while( i<=this->len || i<=nr.len || t )
    {
      this->v[i] = this->v[i] + nr.v[i] + t;
      t = this->v[i] / 10;
      this->v[i] = this->v[i] % 10;
      i++;
    }
    this->len = max(this->len, i-1);
  }
  void afis()
  {
    for(int i = len; i>=0; i--)
      fout << v[i];
    fout << endl;
  }
  num operator=(const num& nr)
  {
    this->len = nr.len;
    memcpy(this->v, nr.v, sizeof(v));
    return *this;
  }
};

num d[8];
int n;

int main()
{
  fin >> n;
  d[2].init();
  d[6].init();
  for(int i=1; i<n-1; i++)
  {
    num a[8];
    for(int j=0; j<8; j++)
        for(int k=0; k<8; k++)
          if( tr[j][k] )
            a[k].add(d[j]);

    for(int j=0; j<8; j++)
      d[j] = a[j];
  }
  
  if( n==1 ) fout << "0\n";
  else
  {
    num ans;
    ans.add(d[2]);
    ans.add(d[2]);
    ans.add(d[7]);
    ans.add(d[7]);
    ans.afis();
  }

	return 0;
}
