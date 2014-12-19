#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i,n) for (int i=0;i<n;i++)

struct maxthing {
 int val[222222];
 int buc[22222];
 int buc2[999];
 int buc3[66];
 maxthing() {
  memset(val,-2,sizeof(val));
  memset(buc,-2,sizeof(buc));
  memset(buc2,-2,sizeof(buc2));
  memset(buc3,-2,sizeof(buc3));
 }
 int get(int a, int b) {
  int ans = -77777777;
  while (a%16&&a<b) ans = max(ans,val[a++]);
  while (b%16&&a<b) ans = max(ans,val[--b]);
  a/=16; b/=16;
  while (a%16&&a<b) ans = max(ans,buc[a++]);
  while (b%16&&a<b) ans = max(ans,buc[--b]);
  a/=16; b/=16;
  while (a%16&&a<b) ans = max(ans,buc2[a++]);
  while (b%16&&a<b) ans = max(ans,buc2[--b]);
  a/=16; b/=16;
  while (a<b) ans = max(ans,buc3[a++]);
  return ans;
 }
 void inc(int i, int v) {
  val[i]=v;
  buc[i/16]=max(buc[i/16],v);
  buc2[i/256]=max(buc2[i/256],v);
  buc3[i/4096]=max(buc3[i/4096],v);
 }
};

int foo[222222];
int pos[222222];
int n;
maxthing mins, maxs;

int doit2(int,int);

int tiod2(int a, int b) {
 if (b-a<2) return b-a;
 int c = pos[-mins.get(a,b)];
 return tiod2(a,c)/2*2 + doit2(c+1,b) + 1;
}

int doit2(int a, int b) {
 if (b-a<2) return b-a;
 int c = pos[maxs.get(a,b)];
 return doit2(a,c)/2*2 + tiod2(c+1,b) + 1;
}

int read_int() {
 cout<<"start read_int"<<endl;
 char c = getc(stdin);
 if (!isdigit(c)) printf("expected int but none was forthcoming\n");
 ungetc(c,stdin);
 int k;
 if (1 != scanf("%i", &k)) printf("unexpected eof\n");
 cout<<"end read_int"<<endl;
 return k;
}

void read_space() {
 char c = getc(stdin);
 if (c-' ') printf("expected space but none was forthcoming\n");
}

void read_lf() {
 char c = getc(stdin);
 if (c-'\n') printf("expected newline but none was forthcoming\n");
}


void doit() {
 cout<<"start doit"<<endl;
 cout<<"n=="<<n<<endl;
 n = read_int();
 cout<<n<<endl;
 memset(pos,-1,sizeof(pos));
 mins = maxthing(); maxs = maxthing();
 FOR(i,n) {
  read_space(); foo[i] = read_int();
  mins.inc(i,-foo[i]);
  maxs.inc(i,foo[i]);
  if (pos[foo[i]]+1) printf("duplicate sequence element\n");
  if (foo[i] < 1 || foo[i] > n) printf("element out of range\n");
  pos[foo[i]]=i;
 }
 read_lf();
 printf("%i\n", doit2(0,n));
}

int main() {
 freopen("f.in","r",stdin);
 int n = read_int(); read_lf();
 cout<<"n="<<n<<endl;
// while(n--)doit();
 doit();
}
