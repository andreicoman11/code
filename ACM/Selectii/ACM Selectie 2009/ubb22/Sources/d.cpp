//Code of RAVEman

#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue> 
#include <iostream>
#include <iterator>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <sstream>

#pragma comment(linker, "/STACK:60777216")

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for (int  i=(a); i < (b); i++) 
#define FD(i,a,b) for (int i=(a); i >= (b); i--) 
#define REP(i,n) FOR(i,0,n) 
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int inf = 1011111111;


ll res=-1;
vi v;
int a[111];

bool go(int pos,int left_diff,int mask=0,bool bigger=false){
    if(left_diff>v.size()-pos) return false;
    if(left_diff<0) return false;
    if(pos==v.size()){
        if(left_diff) return false;
        ll c=0;
        REP(i,pos) c=10*c+a[i];
        if(res==-1 || res>c) res=c;
        return true;
    }
    if(bigger){
        FOR(dig,0,10){
            a[pos]=dig;
            if(go(pos+1,left_diff+(mask&(1<<dig)?0:-1),mask|(1<<dig),true)) return true;
        }
    }else{
        FOR(dig,v[pos],10){
            a[pos]=dig;
            if(go(pos+1,left_diff+(mask&(1<<dig)?0:-1),mask|(1<<dig),dig!=v[pos])) return true;
        }
    }
    return false;
}

long long find(long long n, int k) {
    v.clear();
    while(n) v.pb(n%10),n/=10;
    reverse(v.begin(),v.end());
    for(;;){
        res=-1;
        go(0,k);
        if(res!=-1) return res;
        v.insert(v.begin(),0);
        REP(i,v.size()) v[i]=0;
        v[0]=1;
    }
    return -1;
}



void main()
{
	int test;
	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		long long n, k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	}
}