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
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "subsir1000.in" 
#define OUTFILE "subsir1000.out"
#define MAX 100000

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int a[MAX], n, d[MAX], ndiv[MAX];

int main()
{
  memset(d, 0, sizeof(d));
  fin >> n;
  int tmax = 0;
  
  REP(i, n)
  {
    fin >> a[i];
    int imax = 0, c = 0;

    ndiv[c++] = a[i];
    imax = d[a[i]];

    for(int j=2; j*j<=a[i]; j++)
      if( a[i]%j==0 )
      {
        ndiv[c++] = j;
        ndiv[c++] = a[i]/j;
        imax = max(imax, d[j]);
        imax = max(imax, d[a[i]/j]);
      }
    imax++;
    for(int j=0; j<c; j++)
      d[ ndiv[j] ] = imax;
    tmax = max(imax, tmax);
  }

  fout << tmax << endl;
	
	return 0;
}
