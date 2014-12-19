// O(N^2)

#include <stdio.h>

#define NMAX 2066
#define NUM 29997

int P[2][NMAX], Sinf[2][NMAX], Ssup[2][NMAX];
int i, j, k, N, c, a, rez;
char s[NMAX];

int main()
{
	int test;

	freopen("perm.in", "r", stdin);

	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %s", &N, s + 1);

		P[c = 0][1] = 1 % NUM;

		for (j = 0; j <= 3; j++)
			Sinf[c][j] = Ssup[c][j] = 0;

		Sinf[c][1] = Ssup[c][1] = P[c][1];


		for (i = 2; i <= N; i++)
		{
			a = c;
			c = 1 - c;

			for (j = 1; j <= i; j++)
			{
				P[c][j] = 0;

				if (s[i - 1] == '<')
					P[c][j] = Sinf[a][j - 1];
				else
					P[c][j] = Ssup[a][j];
			}

			Sinf[c][0] = 0;
			for (j = 1; j <= i; j++)
				Sinf[c][j] = (Sinf[c][j - 1] + P[c][j]) % NUM;

			Ssup[c][i + 1] = 0;
			for (j = i; j >= 1; j--)
				Ssup[c][j] = (Ssup[c][j + 1] + P[c][j]) % NUM;
		}

		rez = 0;
		for (i = 1; i <= N; i++)
			rez = (rez + P[c][i]) % NUM;

		printf("%d\n", rez);
	}

	return 0;
}