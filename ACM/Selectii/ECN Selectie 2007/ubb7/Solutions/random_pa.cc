/* Sample solution for NCPC'06: Random Walking  
 * Author: Per Austrin
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;
int main(void) {
  int k, n, e, ok;
  for (; scanf("%d%d%d",&k,&n,&e),ok=1,k; printf("%s\n", ok?"Yes":"No")) {
    double p[1024], np[1024], bp[10];
    vector<int> adj[1024];
    for (int i = 0, a, b; i < e; ++i) {
      scanf("%d%d", &a, &b), adj[a].push_back(b); 
      if (a != b) adj[b].push_back(a);
    }
    for (int i = 0; i < (1<<n); ++i) np[i] = 1.0/(1<<n);
    for (int i = 0; ok && i < k-1; ++i) {
      memcpy(p, np, sizeof(np)); memset(np, 0, sizeof(np));
      for (int v = 0; v < (1<<n); ++v) for (int j = 0; j < adj[v].size(); ++j)
	np[adj[v][j]] += p[v] / adj[v].size();
      for (int v = 0; v < (1<<n); ++v) for(int b = 0; b < n; ++b) 
	if (v & (1<<b)) bp[b] = np[v] + (v == (1<<b) ? 0 : bp[b]);
      for (int b = 0; ok && b < n; ++b) {
	assert(fabs(bp[b]-0.25) > 1e-9 && fabs(bp[b]-0.75) > 1e-9);
	ok &= fabs(4*bp[b]-2) < 1;
      }
    }
  }
  return 0;
}
