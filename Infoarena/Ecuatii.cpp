#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "eqs.in" 
#define OUTFILE "eqs.out"
#define MOD 666053
#define ADD 12500000
#define ADD2 25000000

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int a1, a2, a3, a4, a5;

struct nod{
  int val;
  int cnt;
  nod* next;
};

nod* table[MOD];
int pos;

int contains(int nr)
{
  nod* n = table[nr%MOD];
  while( n!=NULL && n->val!=nr )
    n = n->next;
  if( n==NULL )
    return 0;
  else 
    return n->cnt;//((n == NULL) ? 0 : n->cnt );
}

void add(int nr)
{
  int key = nr%MOD;
  nod* n = table[key];
  while( n!=NULL && n->val!=nr )
    n = n->next;
  if( n==NULL )
  {
    n = new nod();
    n->val = nr;
    n->cnt = 1;
    n->next = table[key];
    table[key] = n;
  }
  else
    n->cnt++;
}

void makeHash()
{
  int s1, s2;
  FOR(x4, 1, 51)
  FOR(x5, 1, 51)
  {
    s1 = a4*x4*x4*x4;
    s2 = a5*x5*x5*x5;
    add(ADD + s1 + s2 );
    add(ADD - s1 + s2 );
    add(ADD + s1 - s2 );
    add(ADD - s1 - s2 );
  }
}

void verifHash()
{
  int sum;
  int s1, s2, s3;
  pos = 0;
  FOR(x1,1,51)
  FOR(x2,1,51)
  FOR(x3,1,51)
  {
    s1 = a1*x1*x1*x1;
    s2 = a2*x2*x2*x2;
    s3 = a3*x3*x3*x3;
    sum = ADD + s1 + s2 + s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD + s1 + s2 - s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD + s1 - s2 + s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD + s1 - s2 - s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD - s1 + s2 + s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD - s1 + s2 - s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD - s1 - s2 + s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
    sum = ADD - s1 - s2 - s3;
    if( sum>=0 && sum <=ADD2 ) pos += contains((int)sum);
  }
}

int main()
{
  fin >> a1 >> a2 >> a3 >> a4 >> a5;
  
  makeHash();
  verifHash();

  fout << pos << endl;
	
	return 0;
}