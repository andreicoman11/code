#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

int n,m,k;
long long sol,ans;
vector < vector < pair<int ,int > > > diag;
vector <int> ss, ss2;
vector <bool> was;

void BuildDiagonals()
{
	diag.clear();
	diag.resize(n+m-1);
	for (int q=2;q<=min(n,m);++q)
	{
		for (int w=1;w<q;++w)
		{
			diag[q-2].push_back(make_pair(w,q-w));
		}
	}
	for (int q=min(n,m);q<=max(n,m);++q)
	{
		for (int w=1;w<=min(m,n);++w)
		{
			if (n>m) diag[q-1].push_back(make_pair(w+q-min(n,m),min(n,m)-w+1));
			else diag[q-1].push_back(make_pair(min(n,m)-w+1,w+q-min(n,m)));
		}
	}
	for (int q=2;q<=min(n,m);++q)
	{
		for (int w=1;w<q;++w)
		{
			diag[n+m-q].push_back(make_pair(n-w+1,m-(q-w)+1));
		}
	}
}

void back2(int sp2, int nDiag)//Brute force the bishops on the selected diagonals
{
	if (sp2==nDiag) ++sol;
	else 
		for (ss2[sp2]=0;ss2[sp2]<diag[ss[sp2+1]].size();++ss2[sp2]) 
		{
			pair <int ,int> aDiag=diag[ss[sp2+1]][ss2[sp2]];
			if (!was[aDiag.first-aDiag.second+m-1]) 
			{
				was[aDiag.first-aDiag.second+m-1]=true;
				back2(sp2+1, nDiag);
				was[aDiag.first-aDiag.second+m-1]=false;
			}
		}
}

void back(int sp, int nDiag)//Select nDiag diagonals
{
	if (sp>nDiag) 
	{
		was.clear();
		was.resize(n+m-1,false);
		back2(0, nDiag);
	}
	else
		for (ss[sp]=ss[sp-1]+2;ss[sp]<n+m-1-nDiag+sp;++++ss[sp]) back(sp+1, nDiag);
}

void solve()
{
	int even;
	for (int i=0;i<=k;++i)
	{
		ss.resize(i+1);
		ss2.resize(i);
		ss[0]=-2;
		sol=0;
		if (i) back(1,i);//Brute force placing of i bishops on white squares
		else sol=1;
		even=sol;
		ss.resize(k-i+1);
		ss2.resize(k-i);
		ss[0]=-1;
		sol=0;
		if (k-i) back(1,k-i);//Brute force placing of k-i bishops on black squares
		else sol=1;
		ans+=sol*even;
	}
}

void main()
{
	clock_t start=clock();
	ifstream fin("bishop.in");
	ofstream fout("bishop.out");
	do
	{
		fin>>n>>m>>k;
		if (n==-1) break;
		BuildDiagonals();
		ans=0;
		solve();
		fout<<ans<<endl;
	} while (1);
	fout<<(clock()-start)/double(CLOCKS_PER_SEC);
	fin.close();
	fout.close();
}