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
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "permlcs.in" 
#define OUTFILE "permlcs.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int c[1000], /*x[9][1000],*/ v[9][1000], d[1000];
int n, m;

int main()
{
  fin >> n >> m;
  int aux;
  REP(i, n)
  {// permutare inspre permutarea identica
    fin >> aux;
    c[aux-1] = i;
  }
  m--;
  REP(i,m)
  REP(j,n)
  {// permuta & memoreaza pozitia fiecarui element
    fin >> aux;
    //x[i][j] = c[aux-1];
    v[i][ c[aux-1] ] = j;
  }

  /*REP(i, n)
    cout << i << "=" << c[i] << endl;cout <<"\n\n";
  REP(i, m)
  {
    REP(j, n)
      cout << x[i][j] << " ";
    cout << endl;
  }cout << "\n\n";
  REP(i, m)
  {
    REP(j, n)
      cout << v[i][j] << " ";
    cout << endl;
  }*/

  d[0] = 1;
  int tmax = 0;
  FOR(i, 1, n)
  {
    int smax = 1;
    FOR(j, 0, i)
    {
      int ok = 1;
      FOR(k, 0, m)
        if( v[k][j] > v[k][i] )
          ok = 0;
      if( ok )
        smax = max(smax, d[j]+1);
    }
    d[i] = smax;
    tmax = max(tmax, smax);
    //cout << d[i] << " ";
  }

  fout << tmax << endl;
	
	return 0;
}
