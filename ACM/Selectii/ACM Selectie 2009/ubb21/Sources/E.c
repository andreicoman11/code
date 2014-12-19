#include <stdio.h>
#include <string.h>
#include <assert.h>

char take[10000];
char done[10000];

int i,j,k,m,n,r,c,yes;

main(){
   while (2 == scanf("%d%d",&k,&m) && k) {
      memset(take,0,sizeof(take));
      yes = 1;
      for (i=0;i<k;i++) {
         scanf("%d",&j);
         assert(!take[j]);
         take[j] = 1;
      }
      for (i=0;i<m;i++) {
         memset(done,0,sizeof(done));
         scanf("%d%d",&c,&r);
         for (j=0;j<c;j++) {
            scanf("%d",&n);
            assert(!done[n]);
            done[n] = 1;
            r -= take[n];
         }
         yes &= (r <= 0);
      }
      if (yes) printf("yes\n"); else printf("no\n");
   }
   if (k) printf("fishy end of file %d\n",k);
}
