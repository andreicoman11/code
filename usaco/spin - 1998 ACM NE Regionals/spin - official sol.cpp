/*
ID: andreic4
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int N(5), T(360);
 
int S[N], W[N], A[N][N], E[N][N];
bool all[T], now[T];
 
FILE *fin(fopen("spin.in", "r")), *fout(fopen("spin.out", "w"));
 
int main()
{
	int i, j, k, p;
 
	for(i = 0; i < N; ++ i)
	{
		fscanf(fin, "%d%d", S+i, W+i);
		for(j = 0; j < W[i]; ++ j)
			fscanf(fin, "%d%d", A[i]+j, E[i]+j);
	}
 
	for(i = 0; i < T; ++ i)
	{
		memset(all, 1, sizeof all);
		for(j = 0; j < N; ++ j)
		{
			memset(now, 0, sizeof now);
			for(k = 0; k < W[j]; ++ k)
			{
				for(p = 0; p <= E[j][k]; ++ p)
					now[ (A[j][k]+p) % T ] = 1;
				A[j][k] = (A[j][k]+S[j]) % T;
			}
			for(k = 0; k < T; ++ k)
				all[k] &= now[k];
		}
		for(j = 0; j < T; ++ j)
			if(all[j]) break;
		if(j < T) break;
	}
 
	if(i < T)
		fprintf(fout, "%d\n", i);
	else
		fprintf(fout, "none\n");
 
	fclose(fin);
	fclose(fout);
	return 0;
}
