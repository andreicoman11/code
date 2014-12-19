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
#include <queue>
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
#define INFILE "B-large-practice.in" 
#define OUTFILE ".out"
#define MAX 256
ifstream fin (INFILE);
ofstream fout (OUTFILE);

const long long bmax = 2000000000000;
long long p[MAX], v[MAX], d;
int c;

bool verif(long long t)
{
  long long next = 0 - bmax;
  REP(i, c)
  {
    long long l = p[i] - t;
    long long r = p[i] + t;
    l = max(l, next);
    long long last = l + (v[i]-1) * d;
    if( last>r ) return false;
    next = last + d;
  }
  return true;
}

long long bs(long long a, long long b)
{
  if( b-a==1 ) return b;
  long long mid = (a+b)/2;
  
  if( verif(mid) )    return bs(a, mid);
  else                return bs(mid, b);
}

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    fin >> c >> d;
    d *= 2;
    REP(i, c)
    {
      fin >> p[i] >> v[i];
      p[i] *= 2;
    }

    /*for(long long i = 0; i<10; i++)
      cout << verif(i) << " ";
    cout << endl;*/

    long long secs = bs(0, bmax);
    if( verif(0) ) secs = 0;
	

		fout << "Case #" << r << ": " << secs/2 << ".";
    if( secs%2==0 ) fout << "0\n";
    else            fout << "5\n";
	}
	
	return 0;
}