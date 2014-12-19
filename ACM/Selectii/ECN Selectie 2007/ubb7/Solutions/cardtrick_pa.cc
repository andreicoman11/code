/* Sample solution for NCPC'06: Cardtrick
 * Author: Per Austrin
 */
#include <cstdio>
#include <cstring>

int main(void) {
  int t, n;
  for (scanf("%d", &t); scanf("%d", &n) && t--; ) {
    int out[20], pos = 0;
    memset(out, 0, sizeof(out));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i; ++j) {
	++(pos %= n);
	while (out[pos]) ++(pos %= n);
      }
      out[pos] = i;
    }
    for(int i = 1; i <= n; ++i) printf("%d%c", out[i], i==n ? '\n' : ' ');
  }
  return 0;
}
