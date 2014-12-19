#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

#define LL long long
#define INFILE "xp.in" 
#define OUTFILE "xp.out"
#define nMax 2010

unsigned int P, Q, a, b, prod[nMax], prodaux[nMax], v[nMax], v2[nMax];
int N, n, m;
#define max(x,y) (x>=y ? x : y)

unsigned int compval(unsigned int i)
{
   unsigned int val;
   i %= P;//while( i>=P ) i -= P;

   val = (a+1) & (b+1);
   val %= P;//while( val>=P ) val -= P;
   i = i^val;
   i %= P;//while( i>=P ) i -= P;
   return max(1, i);
}

void comp()
{
   unsigned int aa, bb;
   aa = a + P - 1;
   bb = b + 1;
   a = (aa ^ bb);
   b = (aa | bb);
   while( a>=P ) a -= P;
   while( b>=P ) b -= P;
}

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   cin >> N >> a >> b >> P >> Q;
   unsigned int A = a, B = b;
   for(n=0; n*n<=N; n++)
      prod[n] = 1;
   m = (N/n) + (N%n==0 ? 0 : 1);

   LL val, prod2 = 1, rez2, rez = 0;
   for(int i=0, pos=-1; i<N; i++)
   {
      if(i) comp();
      if( i%n==0 )
      {
         if(pos>=0 ) prodaux[pos] = (unsigned int)prod2;
         if(pos>=0 ) prod2 = (prod2 * prod[pos]) % Q;
         pos++;
      }
      
      val = compval(i+1);
      prod[pos] = (unsigned int)((val * prod[pos]) % Q);
   }
   prodaux[m-1] = (unsigned int)prod2;
   
   prod2 = 1;
   for(int i=m-1; i>=0; i--)
   {
      prodaux[i] = (prod2 * prodaux[i]) % Q;
      prod2 = (prod2 * prod[i]) % Q;
   }

   a = A, b = B;
   val = 1;
   for(int i=0, pos=0, j=0; i<=N; i++, j++)
   {
      if(i) comp();
      if( j==n || i==N)
      {
         val = 1;
         for(int k=j-1; k>=0; k--)
         {
            if( k+1<j ) val = (val * v[k+1]) % Q;
            rez2 = val;
            if( k ) rez2 = (rez2 * v2[k-1]) % Q;
            rez2 = (rez2 * prodaux[pos]) % Q;
            rez = rez ^ rez2;
         }
         pos++;
         j = 0;
         val = 1;
         if( i==N ) break;
      }
      v[j] = compval(i+1);
      val = (val * v[j]) % Q;
      v2[j] = (unsigned int)val;
   }

   cout << rez << endl;

   return 0;
}
