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
#include <queue>
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
#define INFILE "B-large-practice.in" 
//#define INFILE ".in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int c, d, n;

    fin >> c;
    map<string, string> comb;
    REP(i, c)
    {
      string combi;
      fin >> combi;
      comb[ combi.substr(0,2) ] = combi.substr(2);
    }

    fin >> d;
    VS opp(d);
    REP(i, d)
    {
      fin >> opp[i];
    }

    fin >> n;
    string elem;
    int has[128] = {0};
    REP(i, n)
    {
      char l;
      fin >> l;
      if( elem.sz==0 )
      {
        elem += l;
        has[l]++;
      }
      else
      {
        string s1 = "  ";
        string s2 = "  ";
        s1[0] = elem[ elem.sz-1 ];
        s1[1] = l;
        s2[0] = l;
        s2[1] = elem[ elem.sz-1 ];

        if( comb[s1].sz>0 || comb[s2].sz>0 )
        {
          has[elem[elem.sz-1]]--;
          char newc;
          if( comb[s1].sz>0 ) newc = comb[s1][0];
          else if( comb[s2].sz>0 ) newc = comb[s2][0];
          elem[ elem.sz-1 ] = newc;
          has[ newc ]++;
        }
        else
        {
          elem += l;
          has[l]++;
        }

        REP(i, d)
        {
          if( has[opp[i][0]] && has[opp[i][1]] )
          {
            elem = "";
            memset( has, 0, sizeof(has));
            break;
          }
        }
      }

    }
	
		fout << "Case #" << r << ": [";
    for(int i=0; i<elem.sz; i++)
    {
      if( i>0 ) fout << ", ";
      fout << elem[i];
    }
    fout << "]\n";
	}
	
	return 0;
}