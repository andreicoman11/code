#include <stdio.h>
#include <math.h>

int y,Y,i,j,m;
double f,w;

main(){
   while (1 == scanf("%d",&y) && y){
      w = log(4);
      for (Y=1960; Y<=y; Y+=10){
         w *= 2;
      }
      i = 1;
      f = 0;
      while (f < w) {
         f += log((double)++i);
      }
      printf("%d\n",i-1);
   }
   if (y) printf("fishy ending %d\n",y);
}
