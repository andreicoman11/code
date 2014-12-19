/* Sample solution for NCPC'06: Tour Guide
 * Author: Per Austrin
 */
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(void) {
  int n, p[10], i;
  double v, x, y, t, arr, x0[10], y0[10], dx[10], dy[10], pv[10], mint;
  double pdx, pdy, px, py, a, b;
  for ( ; scanf("%d%lf", &n, &v) && n; printf("%.0lf\n", mint)) {
    for (mint = 1e30, i = 0; i < n; ++i)
      scanf("%lf%lf%lf%lf", x0+i,y0+i, pv+i, dx+i), 
	dy[i] = pv[i]*sin(dx[i]), dx[i] = pv[i]*cos(dx[i]), p[i] = i;
    do for (x=y=t=arr=i=0; i < n; arr >?= t + sqrt(x*x+y*y) / pv[p[i++]])
      pdx = dx[p[i]], pdy = dy[p[i]],
	px = x0[p[i]] + t*pdx - x, py = y0[p[i]] + t*dy[p[i]] - y,
	a = v*v - pv[p[i]]*pv[p[i]], b = px*pdx + py*pdy,
	t += (b + sqrt(b*b + a*(px*px+py*py))) / a,
	x = x0[p[i]] + t*pdx, y = y0[p[i]] + t*pdy;
    while (mint <?= arr, next_permutation(p, p+n));
  }
  return 0;
}
