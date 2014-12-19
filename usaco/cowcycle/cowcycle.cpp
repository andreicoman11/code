/*
ID: andreic4
PROG: cowcycle
LANG: C++
*/
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
#define INFILE "cowcycle.in" 
#define OUTFILE "cowcycle.out"
#define MAX 100000.0

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int F, R;
int n;
double ratio[100][100] = {0};
double difs[64];
int f1, f2, r1, r2;
int frez[5], rrez[10];
double rezv = MAX;
int f[5], r[10];

void check()
{
  int p[5] = {0};
  int c = 0;
  double sum = 0.0, lastr = 0.0;
  // compute ratio difs in sorting order
  while( c<n )
  {
    int minp;
    double minr = MAX;
    REP(i, F)
      if( p[i]<R && minr>ratio[f[i]][r[R-1-p[i]]] )
      {
        minr = ratio[f[i]][r[R-1-p[i]]];
        minp = i;
      }
    if(c)
      difs[c] = minr - lastr;
    lastr = minr;
    sum += difs[c++];
    p[minp]++;
  }

  /*if( 0 && difs[0]+difs[0]+difs[0] > difs[n-1] )
  {
    cout << difs[0] << " " << difs[n-1] << endl;
    cout << f[0] << " " << r[R-1] << "\t" << f[F-1] << " " << r[0] << endl;
    cout << "err\n";
    system("pause");
  }*/
  double rez = 0.0;
  sum = (sum - difs[0]) / (double)(n-1);
  FOR(i, 1, n)
  {
    rez += (difs[i]-sum) * (difs[i]-sum);
  }

  rez /= (double)(n-1);
  if( rez < rezv )
  {
    rezv = rez;
    memcpy(frez, f, sizeof(frez));
    memcpy(rrez, r, sizeof(rrez));
  }
}

void back(int i, int j)
{
  //cout << i << " " << j << "\t";
  if( i>=F && j>=R )
  {
    if( 3*f[0]*r[0] <= f[F-1]*r[R-1] )
      check();
  }
  else if( i<F )
  {
    int k = i==0 ? f1 : (f[i-1]+1);
    for(;k<=f2; k++)
    {
      f[i] = k;
      back(i+1, j);
    }
  }
  else if( j<R )
  {
    int k = j==0 ? r1 : (r[j-1]+1);
    for(;k<=r2; k++)
    {
      r[j] = k;
      back(i, j+1);
    }
  }
}

int main()
{
  fin >> F >> R;
  n = F*R;
  fin >> f1 >> f2;
  fin >> r1 >> r2;

  FOR(i, f1, f2+1)
  FOR(j, r1, r2+1)
    ratio[i][j] = (double)i / (double)j;

  int f[5] = {0};
  int r[10] = {0};
  back(0, 0);

  fout << frez[0];
  FOR(i, 1, F)
    fout << " " << frez[i] ;
  fout << endl;
  fout << rrez[0];
  FOR(i, 1, R)
    fout << " " << rrez[i] ;
  fout << endl;

	return 0;
}
