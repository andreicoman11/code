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
#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "A-large-practice.in" 
#define OUTFILE ".out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int runs;
	fin >> runs;
	for(int run = 1; run<=runs; run++)
	{
    int x, r, s, t, n;
    fin >> x >> s >> r >> t >> n;
    map<int,int> speeds;
    speeds[0] = x;
    for(int i=0; i<n; i++)
    {
      int e, b, w;
      fin >> b >> e >> w;
      speeds[w] = speeds[w] + e - b;
      speeds[0] = speeds[0] - (e - b);
    }

    double tt = 0.0;
    double runt = (double) t;
    for(map<int,int>::iterator it = speeds.begin(); it!=speeds.end(); it++)
    {
      double dist = (double)it->second;
      double speed = (double)it->first;

      speed += r;
      double treq = dist / speed;
      if( treq <= runt )
      {
        dist = 0;
        runt -= treq;
        tt += treq;
      }
      else
      {
        dist -= runt * speed;
        tt += runt;
        runt = 0.0;
      }
      speed -= r;

      if( dist>0 )
      {
        speed += s;
        double treq = dist / speed;
        tt += treq;
      }
    }
	
		fout << "Case #" << run << ": ";
    fout << fixed << setprecision(6) << tt << endl;
	}
	
	return 0;
}