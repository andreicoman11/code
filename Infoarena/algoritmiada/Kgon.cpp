#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define INFILE "kgon.in" 
#define OUTFILE "kgon.out"
#define M_PI 3.14159265358979323846
const double prec = 0.00001;

ifstream fin(INFILE);
ofstream fout(OUTFILE);

bool mmic(double a, double b) {
   return a + prec < b;
}

bool eq(double a, double b) {
   return abs(a-b) <= prec;
}

int main() {
   int n, k, kgon = 0;
   double r;
   fin >> n >> k >> r;
   
   vector<double> v(n);
   for(int i=0; i<n; i++)
      fin >> v[i];

   double dist = 2.0 * r * M_PI / double(k);

   sort(v.begin(), v.end());
   queue<pair<double,int> > q;
   for(int i=0; i<n; i++) {
      while( !q.empty() && mmic(q.front().first, v[i]-dist ) )
         q.pop();
      if( !q.empty() && eq( q.front().first, v[i]-dist) ) {
         if( q.front().second+1 == k )
            kgon++;
         else 
            q.push(make_pair(v[i], q.front().second+1));
         q.pop();
      } else
         q.push(make_pair(v[i], 1));
   }

   fout << kgon;

   return 0;
}
