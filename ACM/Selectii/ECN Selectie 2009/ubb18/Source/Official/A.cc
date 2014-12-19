#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define MP make_pair
#define A first
#define B second

#define PB push_back
#define FR(i, a, b) for(int i=(a); i<(b); i++)
#define FOR(i, n) FR(i, 0, n)
#define RF(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define ROF(i, n) RF(i, 0, n)
#define EACH(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it)

set<int> has;
int seq[1234567],ans,i1,n,tem;

int main(){
  freopen("a.dat","r",stdin);
  int ct,i1;
  scanf("%d",&ct);
  while(ct--){
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&seq[i]);
    has.clear();
    ans=0;
    i1=-1;
    FOR(i,n){
      while(has.find(seq[i])!=has.end())
        has.erase(seq[++i1]);
      has.insert(seq[i]);
      tem=i-i1;
      if(tem>ans) ans=tem;
    }
    printf("%d\n",ans);
  }
  return 0;
}

