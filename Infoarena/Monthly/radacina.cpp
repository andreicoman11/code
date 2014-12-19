#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "radacina.in" 
#define OUTFILE "radacina.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int g;
double p[10];

double get_val(double x) {
   double rez = p[0];
   for(int i=1; i<=g; i++) {
      rez = (rez * x + p[i]);
   }
   return rez;
}

int main() {
   fin >> g;
   for(int i=g; i>=0; i--)
      fin >> p[i];

   double a = -20.0, reza = get_val(-20.0);
   double b = 20.0, rezb = get_val(20.0);
   
   while( a+0.00001<=b ) {
      double m = (a+b) / 2.0;
      double rezm = get_val(m);
      if( rezm==0 ) {
         fout << m;
         return 0;
      }
      if( (rezm>0 && reza<0) || (rezm<0 && reza>0) ) b = m, rezb = rezm;
      else a = m, reza = rezm;

      //cout << a << " " << b << endl;
   }
   //cout << get_val(a) << " " << reza;
   fout << a << endl;

   return 0;
}
