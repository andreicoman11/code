#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long
#define INFILE "arbore3.in" 
#define OUTFILE "arbore3.out"
#define NMAX 1000010
#define HASHSIZE 8388608

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int nod[NMAX], res, S;
vector<list<int> > t;

LL ones = (1LL<<23) - 1LL;

int v[HASHSIZE], countv[HASHSIZE];

LL gethash(LL x)
{
   return (x*8388609LL) & ones;
}

void addhash(int aux)
{
   aux++;
   LL haux = gethash(aux);
   while( haux<HASHSIZE && v[haux] && v[haux]!=aux ) haux++;
   if( haux==HASHSIZE ) haux = 0;
   while( haux<HASHSIZE && v[haux] && v[haux]!=aux ) haux++;

   if( v[haux]==aux )   countv[haux]++;
   else {
      v[haux] = aux;
      countv[haux] = 1;
   }
}

void removehash(int f)
{
   f++;
   LL haux = gethash(f);
   while( haux<HASHSIZE && v[haux]!=f && v[haux] ) haux++;
   if( haux==HASHSIZE ) haux = 0;
   while( haux<HASHSIZE && v[haux]!=f && v[haux] ) haux++;

   if( v[haux]==f )     countv[haux]--;
}

int find(int f)
{
   f++;
   LL haux = gethash(f);
   while( haux<HASHSIZE && v[haux]!=f && v[haux] ) haux++;
   if( haux==HASHSIZE ) haux = 0;
   while( haux<HASHSIZE && v[haux]!=f && v[haux] ) haux++;

   if( v[haux]==f )     return countv[haux];
   return 0;
}


void dfs(int root, int s)
{
	s += nod[root];
	addhash(s);

	res += find(s-S);
	for(list<int>::iterator it=t[root].begin(); it!=t[root].end(); it++)
		dfs(*it, s);

	removehash(s);
}

int main()
{
	int n, taux;
	fin >> n >> S;
	t.resize(n+1);
	for(int i=1; i<=n; i++) {
		fin >> taux >> nod[i];
		t[taux].push_back(i);
	}

	addhash(0);
	res = 0;
	dfs(1, 0);
	fout << res;

	return 0;
}