#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

ifstream fin ("find_the_mintxt.txt");
ofstream fout (".out");
#define LL long long
#define KMAX 100005

LL n, k, a, b, c, r;
LL m[KMAX];
int cnt[KMAX];

LL solve() {

   fin >> n >> k >> a >> b >> c >> r;
   memset(m, 0, sizeof(m));
   memset(cnt, 0, sizeof(cnt));
   set<LL> rem;

   for(int i=0; i<=k; i++)
      rem.insert(i);
   
   m[0] = a;
   if( m[0]<=k ) {
      rem.erase(m[0]);
      cnt[m[0]]++;
   }

   for(int i=1; i<k; i++) {
      m[i] = ( b * m[i-1] + c ) % r;
      if( m[i]<=k ) {
         rem.erase(m[i]);
         cnt[m[i]]++;
      }
   }
   n-=k;
   
   for(int i=0; i<=k; i++) {
      LL val = *rem.begin();
      if( m[i]<=k ) {
         cnt[m[i]]--;
         if( cnt[m[i]]==0 ) rem.insert(m[i]);
      }
      m[i] = val;
      cnt[m[i]]++;
      rem.erase(val);
   }

   n--;
   n = n%(1+k);
   return m[n];
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": " << solve() << '\n';
   }

	return 0;
}