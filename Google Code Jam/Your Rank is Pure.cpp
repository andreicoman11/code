#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define pb push_back
#define sz size()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE ".in" 
#define INFILE1 "C-small-practice.in" 
#define INFILE2 "C-large-practice.in" 
#define OUTFILE ".out"

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

ifstream fin (INFILE2);
ofstream fout (OUTFILE);

#define MOD 100003

long long comb[501][501] = {0};
long long d[501][501] = {0};

void getComb()
{
  REP(i, 501)
    comb[i][0] = comb[i][i] = 1;
  REP(i, 501)
    FOR(j, 1, i)
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
}

void memo()
{
  FOR(i, 2, 501)
    d[i][1] = 1;

  //compute d[i][j];
  FOR(n, 2, 501)
  {
    long long tsum = 1;
    FOR(k, 2, n)
    {
      long long sum = 0;
      // d[i][j] = sum d[i][1] ... d[i][j-1]
      FOR(i, max(1, 2*k-n), k)
      {
        sum = (sum + d[k][i] * comb[n-k-1][k-i-1]) % MOD;
      }
      d[n][k] = sum;
      tsum = (tsum + sum) %MOD;
    }
    d[n][n] = tsum;
  }

  /*FOR(n, 2, 501)
  {
    fout << n << ": ";
    FOR(k, 1, n+1)
      fout << d[n][k] << " ";
    fout << endl;
  }
  fout << endl;*/
}

int main()
{
  getComb();
  memo();
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
	  int n;
    fin >> n;
		fout << "Case #" << r << ": " << d[n][n] << endl;
	}
	
	return 0;
}