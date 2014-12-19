#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "livada.in" 
#define OUTFILE "livada.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int v[500000];
unsigned int n, m, p;
int r = 0;
int consec = 1, newcons;
int val, newv, oldv;

int main()
{
  fin >> m >> n >> p;
  REP(i, m)
  {
    memset(v, 0, sizeof(v));
    fin >> val;
    v[250000]++;
    oldv = val;
    newcons = 1;
    bool isr = false;
    FOR(j, 1, n)
    {
      fin >> newv;
      v[250000 + newv - val]++;
      if( v[250000 + newv - val] >= (int)(n/2)+1 )
        isr = true;
      if( oldv==newv ) 
        newcons++;
      else
      {
        consec = consec > newcons ? consec : newcons;
        newcons = 1;
      }
      oldv = newv;
    }
    if( isr ) r++;
  }

  fout << r << endl << consec << endl;
	
	return 0;
}