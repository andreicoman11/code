/*
ID: andreic4
PROG: nocows
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N,K;
long s[200][100];

void input(){
	freopen("nocows.in","r",stdin);
	scanf("%d%d",&N,&K);
}
long solve(){
	for(long k=1;k<=K;++k){
		s[1][k]=1;
		for(long n=2;n<=N;++n){
			s[n][k]=0;
			for(long l=1;l<=n-2;++l){
				s[n][k]+=s[l][k-1]*s[n-1-l][k-1];
				s[n][k]%=9901;
			}
		}
	}
}
void output(){
	freopen("nocows.out","w",stdout);
	printf("%d\n",(s[N][K]-s[N][K-1]+9901)%9901);
}
int main(){
	input();
	solve();
	output();
}
