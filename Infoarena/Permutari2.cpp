#include <iostream>
#include <fstream>
#include <sstream>
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
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "perm2.in" 
#define OUTFILE "perm2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

VI v;
vector<bool> x;
int N;

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a%b);
}

int gcm(int a, int b)
{
  return a * b / gcd(a,b);
}

int main()
{
  // read perm
  fin >> N;
  v = vector<int>(N, 0);
  x = vector<bool>(N, false);
  REP(i, N)
  {
    fin >> v[i];
    v[i]--;
  }

  // nr minim de permutari pana la identic
  VI perm;
  REP(i, N)
    if( x[i]==0 )
    {
      int c = 0;
      int j = i;
      while( x[j]==0 )
      {
        x[j] = 1;
        j = v[j];
        c++;
      }
      //cout << c << endl;
      if( c>1 ) perm.pb(c);
    }

  // min no of perm = gcm of all numbers
  int res = 1;
  REP(i, perm.sz)
    res = gcm(res, perm[i]);

  fout << res;
  fout.close();
	
	return 0;
}
