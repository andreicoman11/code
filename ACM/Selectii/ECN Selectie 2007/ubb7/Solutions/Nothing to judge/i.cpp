#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dx[6]={-1,-1,0,0,1,1};
int dy[6]={0,1,-1,1,-1,0};

void main()
{
	ifstream fin("i.in");
	int test,n;
	fin>>test;
	long long a[100][100],new_a[100][100];
	while (test--)
	{
		fin>>n;
		memset(a,0,sizeof(a));
		a[50][50]=1;
		queue <pair<int,int>> que;
		set <pair<int,int>> was;
		que.push(make_pair(50,50));
		for (int q=1;q<=n;++q)
		{
			was.clear();
			memset(new_a,0,sizeof(new_a));
			while (!que.empty())
			{
				pair<int,int> aux=que.front();
				if (a[aux.first][aux.second]==0) break;
				for (int w=0;w<6;++w)
				{
					pair <int,int> mp=make_pair(aux.first+dx[w],aux.second+dy[w]);
					if (!was.count(mp))
					{
						que.push(mp);
						was.insert(mp);
					}
					new_a[aux.first+dx[w]][aux.second+dy[w]]+=a[aux.first][aux.second];
				}
				que.pop();
			}
			memcpy(a,new_a,sizeof(a));
		}
		cout<<a[50][50]<<endl;
	}
}