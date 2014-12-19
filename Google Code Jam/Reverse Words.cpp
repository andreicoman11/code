#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define PB push_back
#define SZ size()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
//#define INFILE ".in" 
//#define INFILE "B-small-practice.in" 
#define INFILE "B-large-practice.in" 
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

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int runs;
	fin >> runs;
  char buf[1024];
  fin.getline(buf, 1024);
	for(int r = 1; r<=runs; r++)
	{
    fout << "Case #" << r << ": ";
    fin.getline(buf, 1024);
    string word;
    //cout << buf << endl;
    for(int i=strlen(buf)-1; i>=0; i--)
    {
      word = "";
      while( i>=0 && isalpha(buf[i]) )
      {
        word += buf[i];
        i--;
      }
      REVERSE(word);
      fout << word << " ";
    }
    fout << "\n";
		
	}
	
	return 0;
}