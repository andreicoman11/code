#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000

bool was[MAX][MAX],found=false;
int solution[MAX*MAX][2];
int n,m,X0,Y0;
long nr_sol;
short dx[8]={-2,-2,-1,-1,1,1,2,2};
short dy[8]={-1,1,-2,2,-2,2,-1,1};

bool on_table(int x, int y)
{
	return (x>0) && (y>0) && (x<=n) && (y<=m);
}

int nr_moves(int x, int y)
{
	int ans=0;
	for(int q=0;q<8;++q)
	{
		if (on_table(x+dx[q],y+dy[q]) &&
				!was[x+dx[q]][y+dy[q]]) ++ans;
	}
	return ans;
}

int center(int var, int x, int y)
{
	switch (var)
	{
		case 1:return abs(x-n/2-1)+abs(y-m/2-1);
		case 2:return abs(x-n/2)+abs(y-m/2);
		case 3:return abs(x-n/2-1)+abs(y-m/2);
	}
}

void make_move(int var, int x, int y)
{
	for (;;)
	{
		solution[nr_sol][0]=x;
		solution[nr_sol][1]=y;
		if (nr_sol==n*m-1)
		{
			found=true;
			return;
		}
		int nr[8],c[8],q;
		for (q=0;q<8;++q)
		{
			if (on_table(x+dx[q],y+dy[q]) &&
					!was[x+dx[q]][y+dy[q]]) 
			{
				nr[q]=nr_moves(x+dx[q],y+dy[q]);
				c[q]=center(var,x+dx[q],y+dy[q]);
			}
			else nr[q]=9;
		}
		int best=0;
		for (q=1;q<8;++q)
		{
			if (nr[best]>nr[q] || 
				nr[best]==nr[q] && c[best]<c[q])
				best=q;
		}
		if (nr[best]<9)
		{
			++nr_sol;
			was[x+dx[best]][y+dy[best]]=true;
			x+=dx[best];
			y+=dy[best];
		}
		else return;
	}
}

void main()
{
	//Citire
	int test;
	FILE *fin=fopen("knight.in","r");
	fscanf(fin,"%d",&test);
	//freopen("knight.out","w",stdout);
	while (test--)
	{
		fscanf(fin,"%d",&n);

		//Initializare
		m=n;
		X0=Y0=1;
		memset(was,false,sizeof(was));
		was[X0][Y0]=true;
		found=false;
		nr_sol=0;

		//Cautare
		make_move(1,X0,Y0);

		if (!found)
		{
			memset(was,false,sizeof(was));
			was[X0][Y0]=true;
			nr_sol=0;
			make_move(2,X0,Y0);
		}

		if (!found)
		{
			memset(was,false,sizeof(was));
			was[X0][Y0]=true;
			nr_sol=0;
			make_move(3,X0,Y0);
		}

		//Afisare
		if (!found)
			printf("0\n");
		else
		{
			printf("1\n");
			for(int q=0;q<n*m;++q) printf("%d %d\n",solution[q][0],solution[q][1]);	
		}
	}
	fclose(fin);
	//fclose(stdout);
}