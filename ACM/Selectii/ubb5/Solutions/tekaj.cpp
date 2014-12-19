#include <stdio.h>
#include <string.h>

#define MAX 200000

long a[MAX];

void main()
{
	FILE *fin=fopen("tekaj.in","r");
	int test;
	fscanf(fin,"%d",&test);
	//freopen("tekaj.out","w",stdout);
	while (test--)
	{
		bool found=false;
		long n;
		
		fscanf(fin,"%ld",&n);
		for (long q=0;q<n;++q) fscanf(fin,"%ld",&a[q]);

		long was[MAX];
		memset(was,0,sizeof(was));
		long aux;
		int q;
		for(q=0;q<n;++q)
		{
			if (!a[q])
			{
				printf("1\n%ld\n1\n%ld\n",q+1,(!q)?2:1);
				found=true;
				break;
			}
			aux=a[q];
			while (!(aux&1)) aux>>=1;
			if (!was[aux]) was[aux]=q+1;
			else break;
		}

		if (found) continue;
		if (a[q]>a[was[aux]-1])	printf("1\n%ld\n1\n%ld\n",q+1,was[aux]);
		else printf("1\n%ld\n1\n%ld\n",was[aux],q+1);
	}
	fclose(fin);
	//fclose(stdout);
}