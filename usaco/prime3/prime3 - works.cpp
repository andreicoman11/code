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
bool found = 0;
set<VI> rez;

bool is_prim(int a1, int a2, int a3, int a4, int a5)
{
  if( a1+a2+a3+a4+a5!=sum
      || a1<0 || a2<0 || a3<0 || a4<0 || a5<0 
      || a1>9 || a2>9 || a3>9 || a4>9 || a5>9) return false;

  return prim[ (((a1*10 + a2)*10 + a3)*10 + a4)*10 + a5];
}

void printc()
{
  VI r1(5), r2(5);
  REP(i, 5)
  {
    int nr = 0, nr2 = 0;
    REP(j, 5)
    {
      nr = nr*10 + c[i][j];
      nr2 = nr2*10 + c[j][i];
    }
    r1[i] = nr;
    r2[i] = nr2;
  }
  if( is_prim(c[4][0],c[3][1],c[2][2],c[1][3],c[0][4]) )  rez.insert(r1);
  if( is_prim(c[0][4],c[1][3],c[2][2],c[3][1],c[4][0]) )  rez.insert(r2);
}

void get_primes()
{
  memset(prim, 1, sizeof(prim));
  for(int i=3; i * i <=n; i+=2)
    if( prim[i] )
      for(int j=i*i; j<=n; j+=i+i )
        prim[j] = 0;
}

void check()
{
  REP(i1, 10)
  REP(i2, 10)
    if( is_prim(c[0][1], i1, i2, sum-c[0][1]-i1-i2-c[4][1], c[4][1]) )
      for(int j=0; j<10; j++)
        if( is_prim(c[3][0], sum-c[0][1]-i1-i2-c[4][1], j, c[0][1]+i1+i2+c[4][1]-c[3][0]-j-c[3][4], c[3][4]) )
        {
          c[1][1] = i1;
          c[2][1] = i2;
          c[3][1] = sum-c[0][1]-i1-i2-c[4][1];
          c[3][2] = j;
          c[3][3] = c[0][1]+i1+i2+c[4][1]-c[3][0]-j-c[3][4];
          if( is_prim(c[0][0], c[1][1], sum-c[0][0]-c[1][1]-c[3][3]-c[4][4], c[3][3], c[4][4]) )
            {
              c[2][2] = sum-c[0][0]-c[1][1]-c[3][3]-c[4][4];
              if( is_prim( c[0][2], sum-c[0][2]-c[2][2]-c[3][2]-c[4][2], c[2][2], c[3][2], c[4][2]) )
                {
                  c[1][2] = sum-c[0][2]-c[2][2]-c[3][2]-c[4][2];
                  if( is_prim(c[1][0], c[1][1], c[1][2], sum-c[1][0]-c[1][1]-c[1][2]-c[1][4], c[1][4]) )//&&
                      //is_prim(c[4][0], c[3][1], c[2][2], sum-c[1][0]-c[1][1]-c[1][2]-c[1][4], c[0][4]) )
                    {
                      c[1][3] = sum-c[1][0]-c[1][1]-c[1][2]-c[1][4];
                      if( is_prim(c[2][0], c[2][1], c[2][2], sum-c[2][0]-c[2][1]-c[2][2]-c[2][4], c[2][4]) &&
                          is_prim(c[0][3], c[1][3], sum-c[2][0]-c[2][1]-c[2][2]-c[2][4], c[3][3], c[4][3]) )
                        {
                          c[2][3] = sum-c[2][0]-c[2][1]-c[2][2]-c[2][4];
                          printc();
                          found = 1;
                        }
                    }
                }
            }
        }
}

int main()
{
  get_primes();
  fin >> sum >> first;
  c[0][0] = first;
  int vn[] = {1,3,7,9};
  VI fr;
  //VI lr;
  for(int i1=1; i1<10; i1++)
  for(int i2=1; i2<10; i2++)
  for(int i3=1; i3<10; i3++)
  for(int i4=0; i4<4; i4++)
  {
    int vnsum = first + i1 + i2 + i3 + vn[i4];
    int nr = (((first*10 + i1)*10 + i2)*10 + i3)*10 + vn[i4];
    if( vnsum==sum && prim[nr] )
    {
      //cout << nr << endl;
      //fout << nr << endl;
      fr.pb(nr);
    }
  }

  /*for(int i1=0; i1<4; i1++)
  for(int i2=0; i2<4; i2++)
  for(int i3=0; i3<4; i3++)
  for(int i4=0; i4<4; i4++)
  for(int i5=0; i5<4; i5++)
  {
    int vnsum = vn[i1] + vn[i2] + vn[i3] + vn[i4] + vn[i5];
    int nr = (((vn[i1]*10 + vn[i2])*10 + vn[i3])*10 + vn[i4])*10 + vn[i5];
    if( vnsum==sum && prim[nr] )
    {
      //cout << nr << endl;
      //fout << nr << endl;
      lr.pb(nr);
    }
  }*/

  REP(j1, fr.sz)
  FOR(j2, j1, fr.sz)
  for(int i=0; i<4; i++)
  {
    int sumr1 = sum - fr[j1]%10 - vn[i];
    int sumr2 = sum - fr[j2]%10 - vn[i];
    for(int i1=0; i1<4; i1++)
    for(int i2=0; i2<4; i2++)
      if( is_prim(fr[j1]%10, vn[i1], vn[i2], sumr1-vn[i1]-vn[i2], vn[i]) )
        //vn[i1]+vn[i2]+vn[i3]==sumr1 && prim[ ((((fr[j1]%10)*10 + vn[i1])*10 + vn[i2])*10 + vn[i3])*10 + vn[i] ] )
      for(int i4=0; i4<4; i4++)
      for(int i5=0; i5<4; i5++)
      if( is_prim(fr[j2]%10, vn[i4], vn[i5], sumr2-vn[i4]-vn[i5], vn[i]) )
        //vn[i4]+vn[i5]+vn[i6]==sumr2 && prim[ ((((fr[j2]%10)*10 + vn[i4])*10 + vn[i5])*10 + vn[i6])*10 + vn[i] ] )
      {
        int a = fr[j1];
        int b = fr[j2];
        int k = 4;
        while(k)
        {
          c[0][k] = a%10;
          c[k][0] = b%10;
          a/=10;
          b/=10;
          k--;
        }
        c[1][4] = vn[i1];
        c[2][4] = vn[i2];
        c[3][4] = sumr1-vn[i1]-vn[i2];
        c[4][4] = vn[i];
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
    for(set<VI>::iterator it=rez.begin(); it!=rez.end();it++)
    {
      if( it!=rez.begin() ) fout << endl;
      REP(j,5)
        fout << (*it)[j] << endl;
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
