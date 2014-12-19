// Problem   Homogeneous squares
// Runtime   O(n^2)
// Author    Adrian Kuegel
// Date      2006.05.03

#include <stdio.h>

#define MAXN 1024

int s[MAXN][MAXN]; // square of numbers

int main() {
	freopen("homogeneous.in","r",stdin);
	int n;
	while(scanf("%d",&n) == 1 && n) {
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) {
				scanf("%d",&s[i][j]);
				if (i > 0)
					s[i][j] -= s[0][j];
			}
		bool homogeneous = true;
		for (int i=1; homogeneous && i<n; ++i)
			for (int j=1; j<n; ++j)
				if (s[i][j] != s[i][0]) {
					homogeneous = false;
					break;
				}
		if (!homogeneous)
			printf("not ");
		puts("homogeneous");
	}
	return 0;
}
