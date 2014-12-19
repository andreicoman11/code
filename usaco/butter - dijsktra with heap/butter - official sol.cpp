/*
ID: andreic4
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
 
using namespace std;
 
ifstream fin("butter.in");
ofstream fout("butter.out");
 
const int INFINITE=99999999;
 
int Cows,N,M;
int map[801][801];
int CowPosi[801];
vector<int> edge[801];
 
int ans;
 
struct node{

	int value;
	int tar;
	bool operator<(const node & x) const
	{
		if (value>x.value) return true;
		return false;
	}
};
 
priority_queue< node ,vector<node> > q;

int dis[801];
bool used[801];
 
 
void init()
{
	int i,j,k,l;
	fin>>Cows>>N>>M;
 
	memset(CowPosi,false,sizeof(CowPosi));
	for (i=1;i<=Cows;++i) 
	{
		fin>>CowPosi[i];
	}
 
	for (i=0;i<M;++i)
	{
		fin>>j>>k>>l;
		map[j][k]=map[k][j]=l;
		edge[j].push_back(k);
		edge[k].push_back(j);
	}
}
 
void dijk(int start)
{
	int i,j,k;
	while (!q.empty()) q.pop();
 
	for (i=1;i<=800;++i) dis[i]=INFINITE;
	memset(used,false,sizeof(used));
 
	node temp,temp2;
	temp.value=0;
	temp.tar=start;
	q.push(temp);
 
	while (!q.empty())
	{
		while (!q.empty() && used[q.top().tar]) q.pop();
		if (q.empty()) break;
		temp=q.top();
		q.pop();
 
		used[temp.tar]=true;
		dis[temp.tar]=temp.value;
 
		for (k=0;k<edge[temp.tar].size();++k) 
		{
			j=edge[temp.tar][k];
			if (dis[temp.tar]+map[temp.tar][j]< dis[j] && !used[j])
			{
				dis[j]=dis[temp.tar]+map[temp.tar][j];
				temp2.tar=j;
				temp2.value=dis[j];
				q.push(temp2);
			}
		}
	}
 
	int total=0;
	for (i=1;i<=Cows;++i) total+=dis[CowPosi[i]];
	if (total<ans) ans=total;
}
 
 
 
void deal()
{
	int i;
	ans=INFINITE;
	for (i=1;i<=N;++i) dijk(i);
	fout<<ans<<endl;
}
 
 
int main()
{
	init();
	deal();
 
	//system("pause");
	return 0;
}
