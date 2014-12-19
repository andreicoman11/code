#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
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
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "elemente.in" 
#define OUTFILE "elemente.out"
#define MAX 100001
#define MOD 1000003
//ifstream fin (INFILE);
ofstream fout (OUTFILE);

int nr[MAX], p[MAX];
int n, k;

int compare(const void* a, const void* b)
{
  return ((*(int*)a) - (*(int*)b));
}

void make_p()
{
  p[0] = 1;
  FOR(i, 1, n)
    p[i] = (p[i-1]*2)%MOD;
}

int main()
{
  FILE* fin = fopen(INFILE, "r");

  fscanf(fin, "%d %d", &n, &k);

	REP(i, n)
    fscanf(fin, "%d", &nr[i]);

  /* Create powers of 2 needed */
  make_p();
  /* Sort array to identify subarrays*/
  qsort(nr, n, sizeof(int), compare);

  /* [i,j] arrays found with given propery */
  int i=0, j=0, tsum=0;
  while( j<n )
  {
    while( nr[j] > nr[i]+k )
    {
      i++;
    }
    tsum = (tsum + p[j-i]) % MOD;
    j++;
  }

  fout << tsum << endl;

	return 0;
}
