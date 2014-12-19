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
#include <iomanip>
#include <list>
using namespace std;

#define PROBLEM "F"
#define NMAX 1000005
ifstream fin;
ofstream fout;

double v[NMAX][2],n;

double getDist(double x, double y, double a, double b) {
   return sqrt((a-x)*(a-x) + (b-y)*(b-y));
}

double comp(double x, double y) {
   double sdist = 0.0;
   for(int i=0; i<n; i++) {
      double dist = getDist(x,y,v[i][0], v[i][1]);
      sdist += dist;
   }
   return sdist;
}

void solve() {
   fin >> n;
   double xs = 0.0, ys = 0.0;
   for(int i=0; i<n; i++) {
      fin >> v[i][0] >> v[i][1];
   }

   double besta = 0.0, bestb = 0.0, bestdist = comp(0.0, 0.0);
   double add = 1.0, a, b, dist;
   bool changed;
   while( add > 0.00000001 ) {
      //std::cout << besta << " " << bestb << endl;
      changed = 0;
      a = besta + add;
      b = bestb;
      dist = comp(a, b);
      if( dist<bestdist ) {
         changed = 1;
         besta = a;
         bestb = b;
         bestdist = dist;
         continue;
      }
      
      a = besta - add;
      b = bestb;
      dist = comp(a, b);
      if( dist<bestdist ) {
         changed = 1;
         besta = a;
         bestb = b;
         bestdist = dist;
         continue;
      }

      a = besta;
      b = bestb + add;
      dist = comp(a, b);
      if( dist<bestdist ) {
         changed = 1;
         besta = a;
         bestb = b;
         bestdist = dist;
         continue;
      }

      a = besta;
      b = bestb - add;
      dist = comp(a, b);
      if( dist<bestdist ) {
         changed = 1;
         besta = a;
         bestb = b;
         bestdist = dist;
         continue;
      }

      if( !changed ) add /= 10.0;
   }
      
   fout << fixed << setprecision(7) << besta << " " << bestb << '\n';
}

int main() {
	for(int i=2; i<=10; i++) {
		ostringstream ins, outs;
		ins << i << ".in";
		outs << PROBLEM << i << ".out";		
		fin.open(ins.str());
		fout.open(outs.str());

		solve();

		fin.close();
		fout.close();
	}

	return 0;
}