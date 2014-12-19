#include <iostream>
using namespace std;

long long int aa[50000];
long long int kk[50000];

int main()
{
    FILE* fin = fopen("numar.in", "r");
    FILE* fout = fopen("numar.out", "w");

    long long N, k, a;
    fscanf(fin, "%lld", &N);
    
    int c = 0;

    for(k = 2;2*N > k*k-k;k++)
    {
		if( (2*N + k - k*k) % (2*k) == 0 )
		{
			a = (2*N + k - k*k) / (2*k);
			fprintf(fout, "%lld %lld\n", a, k);
			aa[c] = a*(-1)+1;
			kk[c++] = k + (a-1)*2 +1;
		}
    }
    while( c-- )
    {
		fprintf(fout, "%lld %lld\n", aa[c], kk[c]);
    }
    fprintf(fout, "%lld %lld\n", N*(-1)+1, 2*N);

    fclose(fin);
    fclose(fout);
    return 0;
}
