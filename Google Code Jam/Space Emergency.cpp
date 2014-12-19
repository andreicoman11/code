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
#define INFILE2 ".in" 
#define OUTFILE ".out"
#define MAX 1024
ifstream fin (INFILE);
ofstream fout (OUTFILE);

long long C[MAX], st[MAX];
bool sb[MAX];

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    long long t, t_t=0, t_c=0, L, N, c;
    fin >> L >> t >> N >> c;
    memset(st, 0, sizeof(st));
    memset(sb, 0, sizeof(sb));

    REP(i, c)
    {
      fin >> C[i];
      t_c += C[i];
      if( i<N%c ) 
      {
        t_t += 2*C[i];
        st[i]++;
      }
    }
    t_t += 2 * t_c * (N/c);

    long long stt = N/c - t/(2*t_c);
    t = t%(2*t_c);
    long long save = 0;

    long long t_st = 0;
    REP(i, c)
    {
      st[i] += stt;
      if( t>0 && t<2*C[i] )
      {// station finishes while on way
        save = (2*C[i]-t)/2;
        st[i]--;
        t = 0;
      }
      else if( t>0 )
      {// station cannot be sb this time
        t -= 2*C[i];
        st[i]--;
      }
      t_st += st[i];
    }
    if( save ) t_st++;

    // build as many stations as possible
    while( L && t_st )
    {
      // search for max to be sb
      long long cmax = 0, imax = -1;
      REP(i, c)
        if( sb[i]==0 && C[i]>cmax )
        {
          imax = i;
          cmax = C[i];
        }

      if( cmax>save )
      {
        sb[imax] = 1;
        long long tsb = min(st[imax], L);
        t_t -= tsb * cmax;
        L -= tsb;
        t_st -= tsb;
      }
      else
      {
        t_t -= save;
        t_st--;
        L--;
        save = 0;
      }
    }

    
		fout << "Case #" << r << ": " << t_t << endl;
	}
	
	return 0;
}