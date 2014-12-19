#include <stdio.h>
#include <math.h>
#include <assert.h>

char a,b;
double A,B,temp,hum,dew;

double dohum(double tt,double dd){
   double e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(dd+273.16))));
   double h = (0.5555)*(e - 10.0);
   return tt + h;
}

double dotemp(){
   double e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(dew+273.16))));
   double h = (0.5555)*(e - 10.0);
   return hum - h;
}

double dodew(){
   double x = 0;
   double delta=100;
   for (delta=100;delta>.00001;delta *=.5) {
      if (dohum(temp,x) > hum) x -= delta;
      else x += delta;
   }
   return x;
}

main(){
   while (4 == scanf(" %c %lf %c %lf",&a,&A,&b,&B) && a != 'E'){
      temp = hum = dew = -99999;
      if (a == 'T') temp = A;
      if (a == 'H') hum = A;
      if (a == 'D') dew = A;
      if (b == 'T') temp = B;
      if (b == 'H') hum = B;
      if (b == 'D') dew = B;
      if (hum == -99999) hum = dohum(temp,dew);
      if (dew == -99999) dew = dodew();
      if (temp == -99999) temp = dotemp();
      printf("T %0.1lf D %0.1lf H %0.1lf\n",temp,dew,hum);
   }
   assert(a == 'E');
}
