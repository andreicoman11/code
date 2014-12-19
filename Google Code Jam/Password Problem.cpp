#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

//ifstream fin ("A-small.in");
//ofstream fout ("A-small.out");
ifstream fin ("A-large.in");
ofstream fout ("A-large.out");

void solve(int caseNo) {
   int a, b;
   fin >> a >> b;
   double L = b+1, p, A = a, P = 1.0, best = L + 1;

   for(int i=0; i<a; i++) {
      fin >> p;
      P *= p;
      double val = A - double(i+1) * 2.0 + L * (2.0 - P);
      best = min(best, val);
   }
   fout << fixed << setprecision(6) << best << endl;
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2 << ": ";
      solve(N2++);
   }

	return 0;
}