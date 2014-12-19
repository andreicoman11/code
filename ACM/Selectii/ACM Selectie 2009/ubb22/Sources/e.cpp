//Code of JongMan

#include<iostream>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cassert>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<deque>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()

bool seen[1000010];


int findMax(int n, int k) 
{
queue<int> q;
q.push(n);
seen[n] = true;
char buf[1024];
REP(moves,k)
{
  int qs = q.size();
  CLEAR(seen,0);
  REP(qq,qs)
  {
    int here = q.front(); q.pop();
    sprintf(buf, "%d", here);
    int len = strlen(buf);
    REP(i,len) FOR(j,i+1,len)
    {
      if(i == 0 && buf[j] == '0') continue;
      swap(buf[i], buf[j]);
      int there = atoi(buf);
      if(!seen[there])
      {
        seen[there] = true;
        q.push(there);
      }
      swap(buf[i], buf[j]);
    }
  }
}
int ret = -1;
while(!q.empty()) 
{
  ret = max(ret, q.front());
  q.pop();
}
return ret;
}

void main()
{
	int test;
	//freopen("e.in", "r", stdin);
	//freopen("e.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		long long n, k;
		cin >> n >> k;
		cout << findMax(n, k) << endl;
	}
}