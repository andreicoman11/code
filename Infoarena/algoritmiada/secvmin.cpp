#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

#define LL long long
#define INFILE "secvmin.in" 
#define OUTFILE "secvmin.out"
#define NMAX 100005

int na, nb, a[NMAX], b[NMAX];
map<int,int> m;

int main()
{
  freopen(INFILE, "r", stdin);
  ofstream fout(OUTFILE);

  cin >> na >> nb;
  for(int i=0; i<na; i++)
     cin >> a[i];

  for(int i=0; i<nb; i++) {
     cin >> b[i];
     m[b[i]] = i+1;
  }

  memset(b, 0, sizeof(b));

  int smin = na;
  for(int i=0; i<na; i++) {
     int pos = m[a[i]];
     if( pos==1 ) b[1] = i+1;
     else if( b[pos-1] ) b[pos] = b[pos-1];
     if( pos==nb && b[pos] && smin>i-b[pos]+2 ) smin = i-b[pos]+2;
  }

  if( b[nb]==0 )  fout << -1;
  else            fout << smin;
  fout << endl;
  fout.close();

	return 0;
}
