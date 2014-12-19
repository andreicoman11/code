#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MP make_pair
#define A first
#define B second

#define FR(i, a, b) for(int i=(a); i<(b); i++)
#define FOR(i, n) FR(i, 0, n)

#define MAXRC 210

int gri[MAXRC][MAXRC],hp[MAXRC][MAXRC];
int ngri[MAXRC][MAXRC],nhp[MAXRC][MAXRC];
int dis[MAXRC][MAXRC];
int q[MAXRC*MAXRC][2],tail;
int attack[3],n,turn,a1,d1,a2,d2;
char from[MAXRC][MAXRC][8],ft[MAXRC][MAXRC];
char s[MAXRC];
char move[MAXRC][MAXRC];

int dir[9][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1,0,0};
int dir1[4][2]={-1,0,0,1,1,0,0,-1};

char key[4]=".12";
void show(){
  FR(i,1,n+1){
    FR(j,1,n+1) printf("%c",key[gri[i][j]],hp[i][j]); 
    printf("\n");
  }
}

void add(int r1,int c1,int d1){
  if((r1>0)&&(r1<=n)&&(c1>0)&&(c1<=n)&&(dis[r1][c1]==10000)){
    dis[r1][c1]=d1;
    q[tail][0]=r1;
    q[tail++][1]=c1;
  }
}

void stop(int r1,int c1){
  move[r1][c1]=8;
  FOR(i,8) if((r1>=0)&&(c1>=0)&&(r1<=n+1)&&(c1<=n+1)&&
      (from[r1][c1][i])&&(move[r1+dir[i][0]][c1+dir[i][1]]!=8))
    stop(r1+dir[i][0],c1+dir[i][1]);
}

int main(){
  freopen("d.dat","r",stdin);
  scanf("%d",&n);
  while(n){
    memset(gri,0,sizeof(gri));
    scanf("%d%d%d%d",&a1,&d1,&a2,&d2);
    attack[1]=a1-d2+5;
    attack[2]=a2-d1+5;
    FR(i,1,n+1){
      scanf("%s",s);
      FOR(j,n) if(s[j]!='.'){
        gri[i][j+1]=s[j]-'0';
        hp[i][j+1]=35;
      }
    }
    scanf("%d",&turn);
    while(turn--){
//pick directions of attacks
      memset(from,0,sizeof(from));
      memset(ft,0,sizeof(ft));
      FR(side,1,3){
        tail=0;
        FOR(i,n+2) FOR(j,n+2) dis[i][j]=10000;
        FR(i,1,n+1) FR(j,1,n+1) if(gri[i][j]+side==3)
          add(i,j,0);
        if(tail==0) goto done;
        FOR(i,tail) FOR(j,4)
          add(q[i][0]+dir1[j][0],q[i][1]+dir1[j][1],
            dis[q[i][0]][q[i][1]]+1);
        FR(i,1,n+1) FR(j,1,n+1) if(gri[i][j]==side){
           int d=0;
           FR(k,1,8) if(dis[i+dir[k][0]][j+dir[k][1]]<
                         dis[i+dir[d][0]][j+dir[d][1]])
             d=k;
           if(dis[i+dir[d][0]][j+dir[d][1]]==0){
             move[i][j]=8;
             hp[i+dir[d][0]][j+dir[d][1]]-=attack[side];
           }
           else{
             move[i][j]=d;
             from[i+dir[d][0]][j+dir[d][1]][(d+4)%8]=1;
             ft[i+dir[d][0]][j+dir[d][1]]++;
           }
        }
     }
//remove dead ones
      FR(i,1,n+1) FR(j,1,n+1) if(hp[i][j]<=0)
        gri[i][j]=hp[i][j]=0; 
//resolve collisions
      FR(i,1,n+1) FR(j,1,n+1) if((gri[i][j])&&(move[i][j]==8))
        stop(i,j);
      else if(ft[i][j]>1){
        int d1=-1;
        FOR(k,8) if((from[i][j][k])&&((d1==-1)||
          (MP(i+dir[k][0],j+dir[k][1]))<MP(i+dir[d1][0],j+dir[d1][1])))
            d1=k;
        FOR(k,8) if((from[i][j][k])&&(d1!=k))   
          stop(i+dir[k][0],j+dir[k][1]);
      }
//make moves
      memset(ngri,0,sizeof(ngri));
      memset(nhp,0,sizeof(nhp));
      FR(i,1,n+1) FR(j,1,n+1) if(gri[i][j]){
        int i1=i+dir[move[i][j]][0];
        int j1=j+dir[move[i][j]][1];
        ngri[i1][j1]=gri[i][j];
        nhp[i1][j1]=hp[i][j]+(hp[i][j]<35);
      }
//copy things over
      FR(i,1,n+1) FR(j,1,n+1){
        gri[i][j]=ngri[i][j];
        hp[i][j]=nhp[i][j];
      }
    }
done:
    show();
    scanf("%d",&n);
    if(n) printf("\n");
  }
}
