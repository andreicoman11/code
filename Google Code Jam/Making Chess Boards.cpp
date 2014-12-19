#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
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

bool a[512][512];
bool v[512][512];
int d[512][512];

int n, m;

void printa();
void printb();
void printc();

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    memset(a, 0, sizeof(a));
    memset(v, 0, sizeof(v));
    fin >> m >> n;
    REP(i, m)
    {
      string s;
      fin >> s;
      REP(j, n/4)
      {
        stringstream in;
        in << std::hex << s[j];
        int x;
        in >> x;
        REP(k, 4)
        {
          a[i][j*4 + 3-k] = x&1;
          x = x>>1;
        }
      }
    }

    int cells = n*m;
    int smax = 512;
    list<pair<int, int> > ans;
    //printa();
    while( smax>1 )
    {
      smax = 1;
      list<pair<int,int> > sij;
      memset(d, 0, sizeof(d));
      d[0][0] = 1;
      FOR(i, 1, m)
        //if( a[i-1][0]!=a[i][0] )
          d[i][0] = 1;
      FOR(i, 1, n)
        //if( a[0][i-1]!=a[0][i] )
          d[0][i] = 1;

      FOR(i,1,m)
      FOR(j,1,n)
        if( v[i][j]==0 && v[i][j-1]==0 && v[i-1][j]==0 && v[i-1][j-1]==0 && 
            a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j-1] && a[i][j]==a[i-1][j-1] )
        {
          d[i][j] = 1 + min(d[i-1][j-1], min(d[i][j-1], d[i-1][j]));
          if( d[i][j]>smax )
          {
            smax = d[i][j];
            sij.clear();
            sij.pb( pair<int,int>(i,j) );
          }
          else if(d[i][j]==smax)
            sij.pb( pair<int,int>(i,j) );
        }
        else d[i][j] = 1;

      //printb();

      if( smax>1 )
      {
        int nr = 0;
        for(list<pair<int,int> >::iterator it=sij.begin(); it!=sij.end(); it++)
        {
          bool ok = 1;
          for(int i = it->first-smax+1; ok && i<it->first+1; i++)
          for(int j = it->second-smax+1; ok && j<it->second+1; j++)
            if( v[i][j]==1 )
              ok = 0;
          if( ok )
          {
            nr++;
            FOR(i, it->first-smax+1,it->first+1)
            FOR(j, it->second-smax+1, it->second+1)
              v[i][j]=1;
          }
        }
        ans.pb(pair<int,int>(smax, nr));
        cells -= smax * smax * nr;
      }
      else if( cells>0 )
        ans.pb(pair<int,int>(1, cells));
      
      //printc();
      //system("pause");
    }
		fout << "Case #" << r << ": " << ans.sz << endl;
    for(list<pair<int,int> >::iterator it=ans.begin(); it!=ans.end(); it++)
      fout << it->first << " " << it->second << endl;
  
	}
	
	return 0;
}

void printa()
{
  REP(i, m)
  {
    REP(j, n)
      cout << a[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void printb()
{
  REP(i, m)
  {
    REP(j, n)
      cout << setw(1) << d[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void printc()
{
  REP(i, m)
  {
    REP(j, n)
      cout << v[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}