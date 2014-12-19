/*
ID: andreic4
PROG: cryptcow
LANG: C++
*/
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
#define REVERSE(X) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "cryptcow.in" 
#define OUTFILE "cryptcow.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int total[16] = {0};

bool verif(string *s, string *target)
{
  int i = (*s).find('C');
  if( i>0 && (*s).substr(0,i)!=(*target).substr(0,i) )
  {
    return false;
  }
  int k = (*s).find_last_of('W');
  int j = (*target).sz - (*s).sz + k;
  if( k>=0 && j>=0 && (*s).substr(k+1)!=(*target).substr(j+1) )
  { 
    return false;
  }
  (*s) = (*s).substr(i,k+1-i);
  (*target) = (*target).substr(i,j+1-i);

  // verify that already computed parts in s actually exist in target
  i = 0;
  while( i<(*s).sz )
  {
    j = i;
    k = 0;
    while( i<(*s).sz && (*s)[i]!='W' && (*s)[i]!='C' && (*s)[i]!='O')
    {
      k++;
      i++;
    }
    if( k )
    {
      if( (*target).find((*s).substr(j,k))==-1 )
        return false;
    }
    else i++;
  }
  return true;
}

bool dfs(int rem, string s, string target)
{
  total[rem]++;
  if( rem==0 )
  {
    if( s==target ) return true;
    return false;
  }
  else
  {
    if( !verif(&s, &target) )
      return false;
    //fout << rem << " " << s << " " << target << "\n";

    int ii = 0;
    if( s[ii]!='C' ) return false;

    FOR(i, ii, s.sz-2)
      if( s[i]=='C' )
      FOR(j, i+1,s.sz-1)
        if( s[j]=='O' )
        FOR(k, j+1, s.sz)
          if( s[k]=='W' )
          {
            if( dfs( rem-1, s.substr(0,i) + s.substr(j+1,k-j-1) + s.substr(i+1,j-i-1) + s.substr(k+1), target) )
              return true;
          }
  }
  return false;
}

int main()
{
  char str[128];
  fin.getline( str, 128);
  string s = str;

  int c, o, w;
  c = o = w = 0;
  string aux = "";
  
  string target = "Begin the Escape execution at the Break of Dawn";

  REP(i, s.sz)
    if( s[i]=='C' ) c++;
    else if( s[i]=='O' ) o++;
    else if( s[i]=='W' ) w++;
    else aux += s[i];

  SORT(aux);
  string t = target;
  SORT(t);
  if( c!=o || o!=w || w!=c || t!=aux )
  {
    fout << "0 0\n";
    return 0;
  }

  bool found = dfs(c, s, target);
  if( found )
    fout << "1 " << c << endl;
  else
    fout << "0 0\n";

  REP(i, c)
    cout << total[i] << endl;

	return 0;
}
