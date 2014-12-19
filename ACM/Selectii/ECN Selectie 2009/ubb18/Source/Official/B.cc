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

#define MAXRC 1001

char to[MAXRC][MAXRC];
short dis[MAXRC][MAXRC];
int dir[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};

pair<short,short> q[MAXRC*MAXRC];
int r,c,r1,c1,r2,c2,n,head,tail,tail1,r3,c3,d;

inline void add(int r1,int c1,int d1){
//if(d1<dis[r1][c1]) puts("FUBAR");
  if((r1>=0)&&(r1<r)&&(c1>=0)&&(c1<c)&&(dis[r1][c1]==-1)){
    dis[r1][c1]=d1;
    q[tail++]=MP(r1,c1);
  }
}

int main(){
  freopen("b.dat","r",stdin);
  scanf("%d%d",&r,&c);
  FOR(i,r){
    scanf("%s",to[i]);
    FOR(j,c) to[i][j]-='0';
  }
  scanf("%d",&n);
  while(n--){
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    tail=0;
    FOR(i,r) FOR(j,c) dis[i][j]=-1; 
    add(--r1,--c1,0);
    head=0;
    while(head<tail){
      FR(i,head,tail){
        r3=q[i].A;
        c3=q[i].B;
        d=to[r3][c3]; 
        add(r3+dir[d][0],c3+dir[d][1],dis[r3][c3]);
      }
      tail1=tail;
      while(head<tail1){
        FOR(j,8)
          add(q[head].A+dir[j][0],q[head].B+dir[j][1],dis[q[head].A][q[head].B]+1);
        head++;
      }
    }
//FOR(i,r){FOR(j,c) printf("%d",dis[i][j]); printf("\n");}
    printf("%d\n",dis[--r2][--c2]);
  } 
  return 0;
}

