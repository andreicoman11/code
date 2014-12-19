/*
ID: andreic4
PROG: hidden
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
#include <queue>
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
#define INFILE "hidden.in" 
#define OUTFILE "hidden.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int s[100000];
int d[100000];
int p[100000];
int p2[100000];
int L, plen;

void printd()
{
  REP(i, plen)
    cout << p[i] << " ";
  cout << endl;
}

/*bool findperm(int lvl)
{
  for(int i=0; i<plen-1; i++)
    if( p[i]+lvl==p[i+1] ) return 1;
  return (p[plen-1]+lvl)%L==p[0];
}*/


// leave in p only the starts to the longest permutations
void bestperm(int lvl)
{
  int i = 0;
  while( i<plen-1 && p[i]+lvl==p[i+1] )
  {
    i++;
  }
  
  if( i==plen-1 )
  {
    // has searched all array, 2 options: 
    // rotational permutation OR permutation ends at the end
    // either way, this is the one and only longest perm, starting at p[0]
    plen = 1;
    return;
  }

  p2[0] = p[0];
  int plen2 = 1;
  int permmax = i+1;
  int perms0 = (p[0]==0 ? i+1 : 0);
  
  while( i<plen-1 )
  {
    int permsz = 0;
    i++;
    int j = i;
    while( i<plen-1 && p[i]+lvl==p[i+1] )
    {
      i++;
    }
    permsz = i-j+1;
    // check if permutation continues at start
    if( i==plen-1 && p[0]==(p[i]+lvl)%L )
      permsz += perms0;

    if( permsz > permmax )
    {
      permmax = permsz;
      p2[0] = p[j];
      plen2 = 1;
    }
    else if( permsz==permmax )
    {
      p2[plen2] = p[j];
      plen2++;
    }
  }
  memcpy(p, p2, sizeof(p));
  plen = plen2;
}

int main()
{
  char buf[128];
  FILE* fin = fopen(INFILE, "r");
  fscanf(fin, "%d", &L);
  int i=0, minv=128;
  plen = 0;
  while( i<L )
  {
    fscanf(fin, "%s", buf);
    int chars = strlen(buf);
    REP(j, chars)
    {
      s[i+j] = int(buf[j]) - int('a');
      if( s[i+j]<minv )
      {
        minv = s[i+j];
        plen = 1;
        p[0] = i+j;
      }
      else if( s[i+j]==minv )
      {
        p[plen] = i+j;
        plen++;
      }
    }
    i += chars;
  }

  memcpy(d, s, sizeof(d));
  int lvl = 1;
  //cout << "LEVEL: " << lvl-1 << " "  << minv << " " << plen << endl;
  //printd();
  int plen2;
  bestperm(1);
  while( plen>1 && lvl<L )
  {
    minv = 128;
    plen2 = 0;
    for(int j=0; j<plen; j++)
    {
      i = p[j];
      d[i] += s[ ((i+lvl)>=L ? (i+lvl-L) : (i+lvl)) ];
      if( d[i]<minv )
      {
        minv = d[i];
        plen2 = 1;
        p2[0] = i;
      }
      else if( d[i]==minv )
      {
        p2[plen2] = i;
        plen2++;
      }
    }
    lvl++;
    plen = plen2;
    memcpy(p, p2, sizeof(p));
    //cout << "LEVEL: " << lvl-1 << " "  << minv << " " << plen2 << endl;
    //printd();
    bestperm(lvl);
    //cout << "After perm: " << lvl-1 << " "  << minv << " " << plen2 << endl;
    //printd();
  }
  
  fout << p[0] << endl;

	return 0;
}
