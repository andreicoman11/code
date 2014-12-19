#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
using namespace std;

#define LL long long
#define sortAll(x) sort(x.begin(), x.end())
#define INFILE "ismquery.in" 
#define OUTFILE "ismquery.out"
#define NMAX 400005

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, p=1, k=1, g, h;
int a[NMAX], v[NMAX][5], cnt[NMAX];

int main()
{
	fin >> n >> m;
	for(int i=1; i<=n; i++)
		fin >> a[i];
   fin >> g >> h;

   list<pair<int,int> > s;
   s.push_back(make_pair(a[1],1));
   for(int i=2; i<=n; i++)
   {
      list<pair<int,int> >::iterator it = s.end();
      it--;
      while( it->first < a[i] && it!=s.begin() ) {
         v[it->second][ cnt[it->second]++ ] = i;
         if( cnt[it->second]==5 ) {
            list<pair<int,int> >::iterator it2 = it;
            it--;
            s.erase(it2);
         }
         else
            it--;
      }
      if( it==s.begin() && it->first < a[i] ) {
         v[it->second][ cnt[it->second]++ ] = i;
         if( cnt[it->second]==5 ) {
            list<pair<int,int> >::iterator it2 = it;
            s.erase(it2);
         }
         s.push_front(make_pair(a[i], i));
      
      } else
         s.insert(++it, make_pair(a[i], i));
   }

	
	
	for(int i=1; i<=m; i++)
	{
		p = 1 + (i+p*g) % n;
		k = 1 + (i+k*h) % 5;
		fout << v[p][k-1] << '\n';
	}

	return 0;
}