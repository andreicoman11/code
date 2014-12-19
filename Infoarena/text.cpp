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
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "text.in" 
#define OUTFILE "text.out"

//ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
  long long int c = 0, l = 0;
  char a, b;
  FILE* in = fopen(INFILE, "r");
  fscanf(in, "%c", &a);
  if( isalpha(a) ) {l++;c++;}

  while( !feof(in) )
  {
    fscanf(in, "%c", &b);
    if( isalpha(b) )
    {
      l++;
      if( !isalpha(a) )
        c++;
    }
    a = b;
  }
  //cout << c << " "<< l <<endl;
  fout << l / c << endl;
	
	return 0;
}