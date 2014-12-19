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
#define INFILE "a.in" 
#define OUTFILE "a.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
  int n;
  while( fin >> n )
  {
    long long int a = 0;
    long long int b = 1;
    n -= 1;
    while( n )
    {
      long long int c = b;
      b += a;
      a = c;
      n--;
    }
    fout << b << endl;
  }
	
	return 0;
}