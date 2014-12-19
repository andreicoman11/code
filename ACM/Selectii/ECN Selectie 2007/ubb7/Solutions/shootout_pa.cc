/* Sample solution for NCPC'06: Shootout
 * Author: Per Austrin
 */
#include <cstdio>
#include <vector>

using namespace std;

#define dprintf debug && printf
#define debug false

typedef vector<int> vi;

vi targets[1<<13][13];
double prob[1<<13][13][13];
double hitp[13];
int n;

double Prob(int S, int who, int i);

void CalcTargets(int S, int who) {
  if (targets[S][who].empty()) {
    double bestp = -1;
    for (int j = 0; j < n; ++j)
      if ((S & (1<<j)) && j != who) {
	double p = Prob(S & ~(1<<j), (who+1) % n, who);
	if (p > bestp + 1e-9) targets[S][who].clear();
	bestp >?= p;
	if (p > bestp - 1e-9) targets[S][who].push_back(j);
      }
  }
}

double Prob(int S, int who, int i) {
  double &r = prob[S][who][i], allmiss = 1;
  if (r == -1) {
    r = 0;
    for (int j = 0, k; k = (who+j) % n, j < n; ++j)
      if (S & (1<<k)) {
	CalcTargets(S, k);
	for (vi::iterator it = targets[S][k].begin();
	     it != targets[S][k].end(); ++it) {
	  r += allmiss * hitp[k] * 
	    Prob(S&~(1<< *it), (k+1) % n, i) / targets[S][k].size();
	}
	allmiss *= 1 - hitp[k];
      }
    r /= (1-allmiss);
  }
  return r;
}

int main(void) {
  int t;
  for (scanf("%d", &t); t-- && scanf("%d", &n); ) {
    for (int i = 0; i < n; ++i) scanf("%lf", hitp+i), hitp[i] /= 100.0;
    for (int S = 0; S < (1<<n); ++S)
      for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j)
	  if (!(S & (1<<j))) prob[S][i][j] = 0;
	  else prob[S][i][j] = -1;
	targets[S][i].clear();
      }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
      prob[1<<i][j][i] = 1;
    for (int i = 0; i < n; ++i) 
      printf("%.2lf%c", 100*Prob((1<<n)-1, 0, i), i==n-1 ? '\n' : ' ');
  }
}
