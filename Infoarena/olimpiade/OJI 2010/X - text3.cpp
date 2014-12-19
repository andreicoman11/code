#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

#define INFILE "text3.in" 
#define OUTFILE "text3.out"
#define WMAX 20010
#define LMAX 21

int t[WMAX], len[WMAX], occ[32];
char words[WMAX][LMAX];
list<int> v;

int main()
{
  FILE* fin = fopen(INFILE, "r");
  freopen(OUTFILE, "w", stdout);

 for(int i=0; i<32; i++)
   occ[i] = -1;
  memset(len, 0, sizeof(len));

  int w = -1, maxlen = 0, maxi = -1;
  while( !feof(fin) )
  {
    fscanf(fin, "%s", words[++w]);
    if( strlen(words[w])==0 ) {w--; continue;}
    int fc = (int)words[w][0] - int('a');
    int lc = (int)words[w][strlen(words[w])-1] - int('a');
    if( occ[lc]==-1 || (len[fc] + 1 > len[lc]) )
    {
      len[lc] = len[fc] + 1;
      t[w] = occ[fc];
      occ[lc] = w;
      if( len[lc]>maxlen )
      {
        maxlen = len[lc];
        maxi = w;
      }
    }
  }

  cout << w+1 << "\n" << w+1-maxlen;
  memset(len, 0, sizeof(len));
  while( maxi>=0 )
  {
    len[maxi] = 1;
    maxi = t[maxi];
  }

  for(int i=0; i<=w; i++)
    if( len[i] ) 
      cout << "\n" << words[i];

	return 0;
}
