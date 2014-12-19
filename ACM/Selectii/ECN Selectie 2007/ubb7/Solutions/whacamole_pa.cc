/* Sample solution for NCPC'06: Whac-a-Mole
 * Author: Per Austrin
 */
#include <cstdio>
#include <cstring>
int gcd(int a, int b) { return b ? gcd(b, a % b) : (a >? 1); }
int main(void) {
  int B[20][60][60], M[20][60][60], ans, ct, dv, n, d, m, x, y, t;
  for (; scanf("%d%d%d", &n, &d, &m) == 3 && (n += 2*d); printf("%d\n", ans)) {
    memset(M, 0, sizeof(M)); memset(B, 0, sizeof(B)); ans = 0;
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &x, &y, &t), M[t][x+d][y+d]=1;
    for (t = 11; --t; )
      for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ans >?= B[t][i][j], ++j)
	  for (int ni = 0 >? i-d, di; di = ni-i, ni < n <? i+d+1; ++ni)
	    for (int nj = 0 >? j-d, dj, s; dj = nj-j, nj < n <? j+d+1; ++nj)
	      if (di*di + dj*dj <= d*d)
		for (ct=0, dv=gcd(di>?-di, dj>?-dj), s=!di&&!dj; s <= dv; ++s)
		  B[t][i][j]>?=(ct+=M[t][i+s*di/dv][j+s*dj/dv])+B[t+1][ni][nj];
  }
  return 0;
}
