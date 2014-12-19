#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n,m,k,nNodes;
double c[1024],new_c[1024];

vector <vector <int> > a;

bool good()
{
	double p[10];
	memset(p,0,sizeof(p));
	for (int q=0;q<nNodes;++q) 
		for (int w=0;w<n;++w)
			if (q&(1<<w)) p[w]+=c[q];
	for (int q=0;q<n;++q)
		if (p[q]<=0.25 || p[q]>=0.75) return false;
	return true;
}

void main()
{
	ifstream fin("h.in");
	while (1)
	{
		bool ok=true;
		fin>>k>>n>>m;
		if (!k) break;
		nNodes=1<<n;
		a.clear();
		a.resize(nNodes);
		int x,y;
		for (int q=0;q<m;++q)
		{
			fin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for (int q=0;q<nNodes;++q) c[q]=1.0/nNodes;
		if (!good())
		{
			cout<<"No"<<endl;
			continue;
		}
		for (int q=2;q<=k;++q)
		{
			memset(new_c,0,sizeof(new_c));
			for (int node=0;node<nNodes;++node)
				for (int i=0;i<a[node].size();++i) new_c[a[node][i]]+=c[node]*1.0/a[node].size();
			memcpy(c,new_c,sizeof(c));
			if (!good())
			{
				cout<<"No"<<endl;
				ok=false;
				break;
			}
		}
		if (ok) cout<<"Yes"<<endl;
	}
}