#include <stdio.h>
#include <string.h>
#include <assert.h>

int adj[1001][1001];
int e[1001][1001];
int d, dist[1001];
int a,b,i,j,k,m,n,ne[1001],qn,q[1000000];
double cnt[1001];

double combos(int x){
   int i,k;
   double c = 0;
   if (cnt[x] >= 0) return cnt[x];
   if (x == 1) return 1;
   for (i=0;i<ne[x];i++) {
      k = e[x][i];
      if (dist[k] <= dist[x]) continue;
      c += combos(k);
   }
   return cnt[x] = c;
}
      

main(){
   double Q;
   while (2 == scanf("%d%d",&n,&m)) {
      memset(adj,0,sizeof(adj));
      memset(ne,0,sizeof(ne));
      memset(cnt,0,sizeof(cnt));
      for (i=0;i<m;i++) {
         scanf("%d%d%d", &a,&b,&d);
         assert (!adj[a][b] && !adj[b][a]);
         assert (a!=b && a >= 1 && a <= n && b >= 1 && b <= n);
         adj[a][b] = adj[b][a] = d;
         e[a][ne[a]++] = b;
         e[b][ne[b]++] = a;
      }
      for (i=1;i<=n;i++) dist[i] = 2000000000;
      dist[2] = 0;
      q[qn=0] = 2;
      ++qn;
      for (i=0;i<qn;i++) {
         for (j=0;j<ne[q[i]];j++) {
            k = e[q[i]][j];
            if (dist[q[i]] + adj[q[i]][k] < dist[k]) {
               dist[k] = dist[q[i]] + adj[q[i]][k];
               q[qn++] = k;
            }
         }
      }
      //for (i=1;i<=n;i++) printf("%d: %lg\n",i,dist[i]);
      for (i=1;i<=n;i++) cnt[i] = -1;
      Q = combos(2);
      printf("%0.0lf\n",Q);
      assert(Q <= 2147483647);
   }
   if (n) printf("bad eof %d %d\n",n,m);
}
