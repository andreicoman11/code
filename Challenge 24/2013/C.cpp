#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
using namespace std;

#define PROBLEM "C"
ifstream fin;
ofstream fout;

int n;
set<int> h, v, dp, ds;
vector<pair<int, int> > sol;
set<pair<int,int> > pct;

void solve() {
   fin >> n;
   int maxx = -10000000, minx = 10000000;
   for(int i=0; i<n; i++) {
      int a, b;
      fin >> b >> a;
      h.insert(b);
      pct.insert(make_pair(b, a));
      maxx = max(maxx, a);
      minx = min(minx, a);
   }

   int hx = *h.begin();
   int mm[2] = {minx, maxx};
   int t = 0;
   fout << hx << " " << minx << '\n';
   fout << hx << " " << maxx << '\n';

   for(int i=minx; i<=maxx; i++)
      pct.erase(make_pair(i, hx));

   auto it = h.begin();
   for(it++; it!=h.end(); it++) {
      t = 1-t;
      fout << *it << " " << mm[t] << '\n';
      fout << *it << " " << mm[1-t] << '\n';
      for(int i=minx; i<=maxx; i++)
         pct.erase(make_pair(i, *it));
   }

   for(auto it=pct.begin(); it!=pct.end(); it++)
      cout << it->first << " " << it->second << '\n';
}

int main() {
	for(int i=1, tests; i<=10; i++) {
		ostringstream ins, outs;
		ins << i << ".in";
		outs << PROBLEM << i << ".out";		
		fin.open(ins.str());
		fout.open(outs.str());

		solve();
      std::cout << i << endl;

		fin.close();
		fout.close();
	}

	return 0;
}