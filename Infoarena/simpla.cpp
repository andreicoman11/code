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
#define INFILE "simpla.in" 
#define OUTFILE "simpla.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

long long comp(long long a, int add)
{
  if( a<10 )
  {
    if( add==0 )
      return a/2 + 1;
    else
      return (a+1)/2;
  }

  long long m = 1, n, rez = 0;
  while( m*10<=a )
    m *= 10;
  n = m;
  rez += n/2;
  
  while( n+m<=a )
  {
    m += n;
    rez += n/2;
  }
  a -= m;
  while( m>=10 ) m /= 10;
  return rez + comp(a, (add + m%2)%2);
}

int main()
{
  long long a, b;
  fin >> a >> b;
  long long rez = comp(b,0);
  if( a>0 ) rez -= comp(a-1,0);
  fout << rez << endl;

	return 0;
}