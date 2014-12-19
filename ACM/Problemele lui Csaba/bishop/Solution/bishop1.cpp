#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

int n,m,k;
long long sol;
vector <pair<int,int> > ss;

pair<int,int> next(pair<int,int> x)
{
	++x.second;
	if (x.second>m)
	{
		++x.first;
		x.second=1;
	}
	return x;
}

bool ok(int sp)
{
	for (int i=1;i<sp;++i)
		if (abs(ss[sp].first-ss[i].first)==abs(ss[sp].second-ss[i].second)) return false;
	return true;
}

void back(int sp)
{
	if (sp>k) ++sol;
	else
	{
		ss[sp]=ss[sp-1];
		while (1)
		{
			ss[sp]=next(ss[sp]);
			if (ss[sp].first>n) break;
			if (ok(sp)) back(sp+1);
		}
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
		ss.resize(k+1);
		ss[0].first=0;
		ss[0].second=m;
		sol=0;
		back(1);
		fout<<sol<<endl;
	} while (1);
	fout<<(clock()-start)/double(CLOCKS_PER_SEC);
	fin.close();
	fout.close();
}