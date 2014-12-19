/*
ID: andreic4
PROG: buylow
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
#define INFILE "buylow.in" 
#define OUTFILE "buylow.out"
#define MOD 10

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n;
int v[5001];
int x[5001];
int cou[5001][128];
int siz[5001];

int main()
{
  memset(x, 1, sizeof(x));
  memset(cou, 1, sizeof(cou));
  memset(siz, 1, sizeof(siz));
  int sirmax = 0;
  fin >> n;
  REP(i, n)
  {
    fin >> v[i];
    int xmax = 0;
    int pos[1000] = {0};
    int sizp = 0;
    set<int> s;
    for(int j=i-1; j>=0; j--)
      if( v[j] > v[i] )
      {
        if( x[j]==xmax && s.find(v[j])==s.end() )
        {
          s.insert(v[j]);
          int t = 0, sizi = 0;
          //add(pos, cou[j]);
          while( t>0 || sizi<=max(sizp, siz[j]) )
          {
            int ad = (cou[j][sizi] + pos[sizi] + t) % MOD;
            t = (cou[j][sizi] + pos[sizi] + t) / MOD;
            pos[sizi] = ad;
            sizi++;
          }
          sizp = sizi-1;
        }
        else if( x[j]>xmax )
        {
          xmax = x[j];
          s.clear();
          s.insert(v[j]);
          memcpy(pos, cou[j], sizeof(pos));
          sizp = siz[j];
        }
      }
    x[i] = xmax + 1;
    memcpy(cou[i], pos, sizeof(pos));
    siz[i] = sizp;
    if( sizp==0 && pos[0]==0 )
    {
      cou[i][0] = 1;
      siz[i] = 0;
    }
    
    //cout << i << " " << v[i] << "\t" << x[i] << " " << cou[i] << "\n";
    if( x[i]>sirmax )
    {
      sirmax = x[i];
    }
    //cout << sirmax << " " << sirpos << endl;
  }
  int spsz = 0;
  int sirpos[1000] = {0};
  set<int> s;
  for(int i=n-1; i>=0; i--)
    if( x[i]==sirmax && s.find(v[i])==s.end() )
    {
      //sirpos += cou[i];
      int t = 0, sico = 0;
      while( t>0 || sico<=max(spsz, siz[i]) )
      {
            int ad = (cou[i][sico] + sirpos[sico] + t) % MOD;
            t = (cou[i][sico] + sirpos[sico] + t) / MOD;
            sirpos[sico] = ad;
            sico++;
      }
      spsz = sico-1;
      s.insert(v[i]);
    }
  fout << sirmax << " ";
  for(int i=spsz; i>=0; i--)
  {
    fout << sirpos[i];
  }
  fout << endl;


	return 0;
}
