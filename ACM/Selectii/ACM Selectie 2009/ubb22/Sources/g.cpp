//Source of JongMan

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
typedef long long ll;

int count(string s) 
{
int ret = 0;
sort(all(s));
do
{
  bool ok = true;
  REP(i,s.sz-1)
    if(s[i] == s[i+1])
    {
      ok = false; break;
    }
  if(ok) ++ret;
} while(next_permutation(all(s)));
return ret;
}

void main()
{
	int test;
	//freopen("g.in", "r", stdin);
	//freopen("g.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		string n;
		cin >> n;
		cout << count(n) << endl;
	}
}