#include<cstdio>
#include<cstring>
#define _max(a,b) ((a)<(b)? (b) : (a))
int t,n,i,j,a[30001],arb[100000],arb2[100000],l[30001];
int max(int p,int st,int dr,int x)
{
	if(x==n) return 0;
	if(st>x) return arb[p];
	int mij=(st+dr)>>1,p1=p<<1,m=0,m2;
	if(x<mij) m=max(p1,st,mij,x);
	m2=max(p1+1,mij+1,dr,x);
	if(m2>m) return m2;
	else return m;
}
int min(int p,int st,int dr,int x)
{
	if(x==1) return 0;
	if(dr<x) return arb2[p];
	int mij=(st+dr)>>1,p1=p<<1,m=0,m2;
	m2=min(p1,st,mij,x);
	if(x>mij+1) m=min(p1+1,mij+1,dr,x);
	if(m2>m) return m2;
	else return m;
}
void addmax(int p,int st,int dr,int x,int l)
{
	if(st==dr)
	{
		if(l>arb[p]) arb[p]=l;
		return;
	}
	int mij=(st+dr)>>1,p1=p<<1;
	if(x>mij) addmax(p1+1,mij+1,dr,x,l);
	else addmax(p1,st,mij,x,l);
	arb[p]=_max(arb[p1],arb[p1+1]);
}
void addmin(int p,int st,int dr,int x,int l)
{
	if(st==dr)
	{
		if(l>arb2[p]) arb2[p]=l;
		return;
	}
	int mij=(st+dr)>>1,p1=p<<1;
	if(x>mij) addmin(p1+1,mij+1,dr,x,l);
	else addmin(p1,st,mij,x,l);
	arb2[p]=_max(arb2[p1],arb2[p1+1]);
}
int main()
{
	freopen("f.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		memset(arb,0,sizeof(arb));
		memset(arb2,0,sizeof(arb2));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			j=max(1,1,n,a[i]);
			if(j==0) j=-1;
			j++;
			l[i]=j;
			if(j) addmin(1,1,n,a[i],j);
			j=min(1,1,n,a[i]);
			j++;
			if(j>l[i]) l[i]=j;
			addmax(1,1,n,a[i],j);
		}
		j=0;
		for(i=1;i<=n;i++)
			if(l[i]>j) j=l[i];
		printf("%d\n",j);
	}
	return 0;
}
