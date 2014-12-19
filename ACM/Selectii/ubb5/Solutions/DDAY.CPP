#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

long dom[MAX],c[MAX][MAX][MAX];
int ppl[MAX],money[MAX],father[MAX][MAX][MAX];


void main()
{
	//Citire
	int test;
	FILE *fin=fopen("dday.in","r");
	//freopen("dday.out","w",stdout);
	fscanf(fin,"%d",&test);
	while (test--)
	{
		int n,m,k;
		fscanf(fin,"%d%d%d",&n,&m,&k);
		for(int q=0;q<n;++q) fscanf(fin,"%ld%d%d",&dom[q],&money[q],&ppl[q]);

		//Initializare
		int i,j;
		for(i=0;i<=m;++i)
		{
			for(j=0;j<=k;++j) c[0][i][j]=-1;
		}
		c[0][0][0]=0;

		//Dinamica
		for(int q=0;q<n;++q)
		{
			for(int i=0;i<=m;++i)
			{
				for(int j=0;j<=k;++j)
				{
					c[q+1][i][j]=c[q][i][j];
					father[q+1][i][j]=father[q][i][j];
				}
			}
			for(i=0;i<=m-money[q];++i)
			{
				for(j=0;j<=k-ppl[q];++j)
				{
					if (c[q][i][j]!=-1 && c[q+1][i+money[q]][j+ppl[q]]<c[q][i][j]+dom[q])
					{
						c[q+1][i+money[q]][j+ppl[q]]=c[q][i][j]+dom[q];
						father[q+1][i+money[q]][j+ppl[q]]=q;
					}
				}
			}
		}

		//Cautarea solutiei
		int besti=0,bestj=0;
		for(i=1;i<=m;++i)
		{
			for(j=1;j<=k;++j)
			{
				if (c[n][besti][bestj]<c[n][i][j])
				{
					besti=i;
					bestj=j;
				}
			}
		}

		//Construirea solutiei
		vector <int> ans;

		ans.clear();

		i=besti;
		j=bestj;
		int q=n;
		while (i>0)
		{
			int aux=father[q][i][j];
			ans.push_back(aux+1);
			i-=money[aux];
			j-=ppl[aux];
			q=aux;
		}

		sort(ans.begin(),ans.end());

		//Afisarea
		printf("%d %ld %d %d\n",ans.size(),c[n][besti][bestj],besti,bestj);
		for(q=0;q<ans.size();++q) printf("%d ",ans[q]);
		printf("\n");
	}
	//fclose(stdout);
	fclose(fin);
}