/*
ID: andreic4
PROG: prime3
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "prime3.in" 
#define OUTFILE "prime3.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

bool prim[100001];
int sum, first;
int n = 100001;
int c[5][5];
VVI rez;

bool is_prim(int a1, int a2, int a3, int a4, int a5)
{
  if( a1+a2+a3+a4+a5!=sum
      || a1<0 || a2<0 || a3<0 || a4<0 || a5<0 
      || a1>9 || a2>9 || a3>9 || a4>9 || a5>9) return false;

  return prim[ (((a1*10 + a2)*10 + a3)*10 + a4)*10 + a5];
}

void printc()
{
  REP(i,5)
  {
    REP(j,5)
      fout << c[i][j];
    fout << endl;
  }
}

void addsol()
{
  VI r1(5);
  REP(i, 5)
  {
    int nr = 0;
    REP(j, 5)
      nr = nr*10 + c[i][j];
    r1[i] = nr;
  }
  rez.pb(r1);
}

void get_primes()
{
  memset(prim, 1, sizeof(prim));
  for(int i=3; i * i <=n; i+=2)
    if( prim[i] )
      for(int j=i*i; j<=n; j+=i+i )
        prim[j] = 0;
}

bool check_row(int i)
{
  return is_prim(c[i][0],c[i][1],c[i][2],c[i][3],c[i][4]);
}

bool check_col(int i)
{
  return is_prim(c[0][i],c[1][i],c[2][i],c[3][i],c[4][i]);
}

void check()
{
  REP(i1, 10)
    if( is_prim(c[4][0], i1, c[2][2], sum-c[4][0]-i1-c[2][2]-c[0][4], c[0][4]))
    {
      c[3][1] = i1;
      c[1][3] = sum-c[4][0]-i1-c[2][2]-c[0][4];

      c[2][1] = sum-c[0][1]-c[1][1]-c[3][1]-c[4][1];
      c[1][2] = sum-c[1][0]-c[1][1]-c[1][3]-c[1][4];
      c[2][3] = sum-c[0][3]-c[1][3]-c[3][3]-c[4][3];
      c[3][2] = sum-c[3][0]-c[3][1]-c[3][3]-c[3][4];

      bool ok = 1;
      FOR(kk,1,4)
        if( !check_row(kk) || !check_col(kk) )
          ok = 0;
      if( ok )     addsol();
    }
}

int main()
{
  get_primes();
  fin >> sum >> first;
  c[0][0] = first;
  int vn[] = {1,3,7,9};
  VVI fr, fr2;
  for(int i1=0; i1<10; i1++)
  for(int i2=0; i2<10; i2++)
  for(int i3=0; i3<10; i3++)
  for(int i4=0; i4<4; i4++)
    if( is_prim(first, i1, i2, i3, vn[i4]) )
  {
    VI aux(5);
    aux[0] = first;
    aux[1] = i1;
    aux[2] = i2;
    aux[3] = i3;
    aux[4] = vn[i4];
    fr2.pb(aux);
    if( i1 && i2 && i3) fr.pb(aux);
  }

  REP(j1, fr.sz) //l1
  REP(j2, fr.sz) //c1
  REP(j3, fr2.sz) //d1
  {
    int vni = fr2[j3][4];
    int sumr1 = sum - fr[j1][4] - vni;
    int sumr2 = sum - fr[j2][4] - vni;
    for(int i1=0; i1<4; i1++)
    for(int i2=0; i2<4; i2++)
      if( is_prim(fr[j1][4], vn[i1], vn[i2], sumr1-vn[i1]-vn[i2], vni) )
      for(int i4=0; i4<4; i4++)
      for(int i5=0; i5<4; i5++)
        if( is_prim(fr[j2][4], vn[i4], vn[i5], sumr2-vn[i4]-vn[i5], vni) )
        {
          int k = 4;
          while(k)
          {
            c[0][k] = fr[j1][k];
            c[k][0] = fr[j2][k];
            c[k][k] = fr2[j3][k];
            k--;
          }
          c[1][4] = vn[i1];
          c[2][4] = vn[i2];
          c[3][4] = sumr1-vn[i1]-vn[i2];

          c[4][1] = vn[i4];
          c[4][2] = vn[i5];
          c[4][3] = sumr2-vn[i4]-vn[i5];

          check();
        }
  }

  if( rez.sz==0 )
    fout << "NONE\n";
  else
  {
    SORT(rez);
    REP(i, rez.sz)
    {
      REP(j, 5)
        fout << rez[i][j] << endl;
      if(i+1!=rez.sz) fout << endl;
    }
  }

  /*int sums[100] = {0};
  for(int i = 10001; i<100000; i+=2 )
    if( prim[i] )
    {
      fout << i << endl;
      int aux = i;
      int s = 0;
      while(aux)
      {
        s += aux%10;
        aux/=10;
      }
      sums[s]++;
    }

  fout << "\n\n\n";
  REP(i, 100)
    if(sums[i])
      fout << i << " " << sums[i] << endl;*/


	return 0;
}
