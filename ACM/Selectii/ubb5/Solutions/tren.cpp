#include <stdio.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>

#define MAX 20000

long nr_dist,n;
int was[MAX],length,ss[1500];
bool ans[MAX],found;

void write_data()
{
	printf("%d\n",n);
	for (int q=1;q<=length;++q)
	{
		if (ans[q]) printf("%d ",q);
	}
	printf("\n");
	found=true;
}

bool valid_station(int sp, int next_station)
{
	for (int q=1;q<sp;++q)
	{
		if (!was[abs(next_station-ss[q])]) return false;
	}
	return true;
}

void add_station(int sp, int next_station)
{
	ss[sp]=next_station;
	ans[next_station]=true;
	for (int q=1;q<sp;++q)
	{
		--was[abs(next_station-ss[q])];
	}
}

void remove_station(int sp, int next_station)
{
	ans[next_station]=false;
	for (int q=1;q<sp;++q)
	{
		++was[abs(next_station-ss[q])];
	}
}

void back(int sp, int next_station)
{
	if (sp>n) write_data();
	while (!was[next_station]) --next_station;
	if (valid_station(sp, next_station))
	{
		add_station(sp, next_station);
		back(sp+1,next_station);
		if (found) return;
		remove_station(sp, next_station);
	}
	if (valid_station(sp, length-next_station))
	{
		add_station(sp, length-next_station);
		back(sp+1,next_station);
		remove_station(sp, length-next_station);
	}
}

void main()
{
	int test;
	FILE *fin=fopen("tren.in","r");
	fscanf(fin,"%d",&test);
	//freopen("tren.out","w",stdout);
	while (test--)
	{
		found=false;
		memset(was,0,sizeof(was));
		fscanf(fin,"%d",&nr_dist);
		n=(sqrt(double(8*nr_dist+1))+1)/2;
		for (int q=0;q<nr_dist;++q)
		{
			int aux;
			fscanf(fin,"%d",&aux);
			++was[aux];
		}
		
		length=MAX;
		while (!was[length]) --length;
	  
		memset(ans,false,sizeof(ans));
		ans[0]=true;
		ans[length]=true;
		ss[1]=0;
		ss[2]=length;
		--was[length];
		back(3,length);
	}
	fclose(fin);
	//fclose(stdout);
}