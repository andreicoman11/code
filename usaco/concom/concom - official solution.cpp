/*
ID: andreic4
PROG: concom
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long N=100;
long own[N][N];//own[i][j]表示i控制j的百分比 
bool control[N][N];//control[i][j]表示是否控制j 

void add_controller(long i,long j){//i要控制j啦 
	if(control[i][j])return;
	control[i][j]=true;
	for(long k=0;k<N;++k){
		if(control[k][i])add_controller(k,j);
		own[i][k]+=own[j][k];
		if(own[i][k]>50)add_controller(i,k);
	}
}
void add_owner(long i,long j,long v){//现在i控制j的v%啦
	for(long k=0;k<N;++k){
		if(control[k][i])
			own[k][j]+=v;
		if(own[k][j]>50)add_controller(k,j);
	}
}
void init(){
	memset(own,0,sizeof(own));
	memset(control,0,sizeof(control));
	for(long k=0;k<N;++k)
		control[k][k]=true;
}
void input(){
	freopen("concom.in","r",stdin);
	long n;
	scanf("%d",&n);
	do{
		long i,j,v;
		scanf("%d%d%d",&i,&j,&v);
		add_owner(i-1,j-1,v);
	}while(--n);
}
void output(){
	freopen("concom.out","w",stdout);
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j)
			if(i!=j&&control[i][j])
				printf("%d %d\n",i+1,j+1);
}
int main(){
	init();
	input();
	output();
}
