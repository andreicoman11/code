/* Sample solution for NCPC'06: Traveling Salesman
 * Author: Per Austrin
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
struct P { int x,y,z;
  bool operator<(const P p)const { return x==p.x?y==p.y?z<p.z:y<p.y:x<p.x; }};
typedef pair<P,P> L;
int main(void) {
  for (int c, n, a, b, v, j, nd, dst[9999]; scanf("%d", &c) == 1 && c; ) {
    map<L,vi> C; P x, y, z; vi adj[9999], *r; vi::iterator it;
    for (int i = 1; scanf("%d", &n), i <= c; ++i)
      for (scanf("%d%d%d", &x.x, &x.y, &x.z), y=x; n--; r->push_back(i), y=z) {
	if (n) scanf("%d%d%d", &z.x, &z.y, &z.z);
	else z = x;
	for (r=&C[L(min(y,z),max(y,z))], it=r->begin(); it!=r->end(); ++it)
	  adj[i].push_back(*it), adj[*it].push_back(i);
      }
    for (queue<int> q; n-- && scanf("%d%d", &a,&b); printf("%d\n", dst[b]))
      for (memset(dst, 0x1f, sizeof(dst)), q.push(a), dst[v=a]=0; !q.empty(); )
	for (v=q.front(), q.pop(), it=adj[v].begin(); it != adj[v].end(); ++it)
	  if (dst[*it] > dst[v]+1) dst[*it] = dst[v]+1, q.push(*it);
  }
  return 0;
}
