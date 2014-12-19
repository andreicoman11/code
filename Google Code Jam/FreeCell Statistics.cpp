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
#define INFILE "A-large-practice.in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

long long gcd(long long x, long long y)
{
  return (y==0 ? x : gcd(y, x%y));  
}

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    long long int pd, pg, n;
    fin >> n >> pd >> pg;
    string yok = "Possible";
    string nok = "Broken";
    bool ok = 1;

    if( pd<100 && pg==100 ) ok = 0;
    else if( pd>0 && pg==0 ) ok = 0;
    {
      long long int d = 100 / gcd(100, pd);
      if( d>n ) ok = 0;
    }
	
		fout << "Case #" << r << ": ";
    if( ok ) fout << yok << endl;
    else  fout << nok << endl;
	}
	
	return 0;
}