/*
ID: andreic4
PROG: theme
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "theme.in" 
#define OUTFILE "theme.out"
#define MAX 5001
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int x[MAX], d[MAX] = {0};

int main()
{
  int n;
  fin >> n;

  REP(i, n)
    fin >> x[i];
  
  int maxs = 4;

  REP(i, n)
  {
    int length = 1;
    for (int j = n - i - 2; j >= 0; j--)
    {
      if (x[j] - x[j + 1] == x[j + i] - x[j + i + 1])
      {
        length++;
        length = min(length, i);
        maxs = max(maxs, length);
      }
      else
        length = 1;
    }
  }

  fout << (maxs==4 ? 0 : maxs) << endl;

	return 0;
}
