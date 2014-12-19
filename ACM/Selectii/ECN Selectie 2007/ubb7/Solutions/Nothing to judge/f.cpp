#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define xyz pair<int, pair <int,int> >

int n,nPoints,nEdges;
map <  xyz , int > points;
vector <vector <int> > poly, polyedges;
map <pair<int,int>, int > edges;
vector < vector <int> > in_poly;
vector < vector <int> > a;

int bf(int source, int dest)
{
	vector <int> d(n,-1);
	vector <bool> was(n,false);
	queue <int> que;
	d[source]=0;
	was[source]=true;
	que.push(source);
	while (!que.empty() && d[dest]==-1)
	{
		int node=que.front();
		for (int i=0;i<a[node].size();++i)
			if (!was[a[node][i]])
			{
				was[a[node][i]]=true;
				d[a[node][i]]=d[node]+1;
				que.push(a[node][i]);
			}
		que.pop();
	}
	return d[dest];
}

void main()
{
	ifstream fin("f.in");
	while (1)
	{
		fin>>n;
		nPoints=0;
		points.clear();
		poly.clear();
		poly.resize(n);
		polyedges.clear();
		polyedges.resize(n);
		if (!n) break;
		for (int q=0;q<n;++q)
		{
			int aux;
			fin>>aux;
			for (int w=0;w<aux;++w)
			{
				xyz aux2;
				fin>>aux2.first>>aux2.second.first>>aux2.second.second;
				if (!points.count(aux2)) 
				{
					++nPoints;
					points[aux2]=nPoints;
				}
				poly[q].push_back(points[aux2]);
			}
			for (int w=1;w<aux;++w)
			{
				if (!edges.count(make_pair(poly[q][w],poly[q][w-1])))
				{
					++nEdges;
					edges[make_pair(poly[q][w],poly[q][w-1])]=nEdges;
					edges[make_pair(poly[q][w-1],poly[q][w])]=nEdges;
				}
				polyedges[q].push_back(edges[make_pair(poly[q][w-1],poly[q][w])]);
			}
			if (!edges.count(make_pair(poly[q][0],poly[q][aux-1])))
			{
				++nEdges;
				edges[make_pair(poly[q][0],poly[q][aux-1])]=nEdges;
				edges[make_pair(poly[q][aux-1],poly[q][0])]=nEdges;
			}
			polyedges[q].push_back(edges[make_pair(poly[q][0],poly[q][aux-1])]);
		}
		in_poly.clear();
		in_poly.resize(nEdges+1);
		for (int q=0;q<n;++q)
			for (int w=0;w<polyedges[q].size();++w) in_poly[polyedges[q][w]].push_back(q);
		a.clear();
		a.resize(n);
		for (int q=1;q<=nEdges;++q)
			if (in_poly[q].size()>1)
				for (int i=0;i<in_poly[q].size()-1;++i)
					for (int j=i+1;j<in_poly[q].size();++j)
					{
						a[in_poly[q][i]].push_back(in_poly[q][j]);
						a[in_poly[q][j]].push_back(in_poly[q][i]);
					}
		int test;
		fin>>test;
		while (test--)
		{
			int x,y;
			fin>>x>>y;
			cout<<bf(x-1,y-1)<<endl;
		}
	}
}