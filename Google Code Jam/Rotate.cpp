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
//#define INFILE ".in" 
#define INFILE1 "A-small-practice.in" 
#define INFILE2 "A-large-practice.in" 
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

int n, k;
string aux = "..................................................";

bool hask(VS m, int k, int i, int j, char c)
{
  bool ok = 0;
  // right straight
  if( j<=n-k )
  {
    ok = 1;
    REP(l, k)
      if( m[i][j+l]!=c ) ok = 0;
    if( ok ) return true;
  }

  // down
  if( i<=n-k )
  {
    ok = 1;
    REP(l, k)
      if( m[i+l][j]!=c ) ok = 0;
    if( ok ) return true;
  }
  
  // diag right
  if( j<=n-k && i<=n-k)
  {
    ok = 1;
    REP(l, k)
      if( m[i+l][j+l]!=c ) ok = 0;
    if( ok ) return true;
  }

  // diag left
  if( j>=k-1 && i<=n-k)
  {
    ok = 1;
    REP(l, k)
      if( m[i+l][j-l]!=c ) ok = 0;
    if( ok ) return true;
  }
  return false;
}

/*void trym()
{
  n = 3;
  VS m1(3, "...");
  m1[0][0] = m1[0][1] = m1[0][2] = 'R';
  cout << hask( m1, 3, 0, 0, 'R') << "\n";
  m1[0][0] = m1[0][1] = m1[0][2] = '.';

  m1[0][0] = m1[1][0] = m1[2][0] = 'R';
  cout << hask( m1, 3, 0, 0, 'R') << "\n";
  m1[0][0] = m1[1][0] = m1[2][0] = '.';

  m1[0][0] = m1[1][1] = m1[2][2] = 'R';
  cout << hask( m1, 3, 0, 0, 'R') << "\n";
  m1[0][0] = m1[1][1] = m1[2][2] = '.';

  m1[2][0] = m1[1][1] = m1[0][2] = 'R';
  cout << hask( m1, 3, 0, 2, 'R') << "\n";
  m1[2][0] = m1[1][1] = m1[0][2] = '.';
}*/

int main()
{
	int runs;
	fin >> runs;
  char c;
	for(int r = 1; r<=runs; r++)
	{
	  fin >> n >> k;
    VS m(n, aux);
    REP(i, n)
    {
      string line = "";
      REP(j, n)
      {
        fin >> c;
        if( c!='.' )
          line += c;
      }
      for(int j=0; j<line.sz; j++)
        m[j+n-line.sz][n-i-1] = line[j];
    }

    /*REP(i,n)
    {
      REP(j, n)
        cout << m[i][j];
      cout << endl;
    }cout << endl;*/

    int red=0, blue=0;
    REP(i, n)
    REP(j, n)
      if(m[i][j]=='R' && red==0)
      {
        if( hask(m, k, i, j, m[i][j]) )
          red = 1;
      }
      else if(m[i][j]=='B' && blue==0)
      {
        if( hask(m, k, i, j, m[i][j]) )
          blue = 1;
      }

		fout << "Case #" << r << ": ";
    //cout << red << " " << blue << endl;
    red = red*2 + blue;
    switch(red)
    {
      case 0: fout << "Neither";
        break;
      case 1: fout << "Blue";
        break;
      case 2: fout << "Red";
        break;
      default: fout << "Both";
    }
    fout << endl;
	}
	
	return 0;
}