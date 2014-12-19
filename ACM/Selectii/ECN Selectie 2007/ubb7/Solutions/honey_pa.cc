/* Sample solution for NCPC'06: Honeycomb Walk
 * Author: Per Austrin
 * Comment: this handles inputs up to 26, where the answer still fits
 *          in a long long.
 */
#include <cstdio>
#include <cstring>
typedef long long ll;
ll paths[40][80][80];
ll Paths(int s, int x, int y) {
  if (s && paths[s][x][y] == -1) paths[s][x][y] = 
	Paths(s-1, x-1, y) + Paths(s-1, x-1, y-1) + Paths(s-1, x, y-1) +
	Paths(s-1, x+1, y) + Paths(s-1, x+1, y+1) + Paths(s-1, x, y+1);
  return s ? paths[s][x][y] : (x == 40 && y == 40);
}

int main(void) {
  memset(paths, -1, sizeof(paths));
  int t, n;
  for(scanf("%d", &t);scanf("%d", &n)&&t--;printf("%lld\n", Paths(n,40,40)));
  return 0;
}
