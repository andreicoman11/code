#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
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

#define X real
#define Y imag
#define INF 1000000000000000
#define EPS 1E-9

typedef long double ld;
typedef complex<ld> P;

int n;
P loc[1234],v[1234];
ld ans,x,y,d,s,r,pi;

ld dot(P a,P b){return real(conj(a)*b);}

ld moo(P p,P v){
  if(abs(p)<r+EPS) return 0;
  if(abs(v)<EPS) return INF;
  ld t=dot(p*P(ld(-1),0),v)/norm(v);
  if(t<-EPS) return INF;
  P p1=p+v*P(t,0);
  if(abs(p1)>r) return INF;
  else return t-sqrt(r*r-norm(p1))/abs(v);
}

int main(){
  freopen("c.dat","r",stdin);
  int ct;
  pi=acos(0.0)*ld(2);
  scanf("%d",&ct);
  while(ct--){
    scanf("%d%Lf",&n,&r);
    FOR(i,n){
      scanf("%Lf%Lf%Lf%Lf",&x,&y,&d,&s);
      loc[i]=P(x,y);
      v[i]=P(s,0)*exp(P(0,(ld(90)-d)/ld(180)*pi));
    }
    ans=INF;
    FOR(i,n) FOR(j,i)
      ans=min(ans,moo(loc[i]-loc[j],v[i]-v[j]));
    if(ans==INF) puts("No collision.");
    else printf("%0.0Lf\n",ans);
  }
  return 0; 
}

