/* Sample solution for NCPC'06: Nasty Hacks
 * Author: Per Austrin
 */
#include <cstdio>

int main(void) {
  int n, r, e, c;
  for (scanf("%d", &n); scanf("%d%d%d", &r, &e, &c) && n--; )
    printf("%s\n", e-c <= r ? e-c < r ? 
	   "do not advertise" : "does not matter" : "advertise");
  return 0;
}
