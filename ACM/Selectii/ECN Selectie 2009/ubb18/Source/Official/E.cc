#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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

char s1[12345],s2[12345];
int n,k,ans,ma,ct;

int same(int p1,int p2,int l){
  FOR(i,l) if(s1[p1+i]!=s2[p2+i]) return 0;
  return 1;
}

int main(){
  freopen("e.dat","r",stdin);
  scanf("%d",&ct);
  while(ct--){
    scanf("%d%d",&k,&n);
    ans=k;
    scanf("%s",s1);
    while(--n){
      scanf("%s",s2);
      ma=0;
      FOR(i,k) if(same(i,0,k-i)){ ma=k-i; break;}
      ans+=k-ma;
      FOR(i,k) s1[i]=s2[i];
    }
    printf("%d\n",ans);
  }
  return 0;
}

