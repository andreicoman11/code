#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
#define INFILE "fabrica.in" 
#define OUTFILE "fabrica.out"
#define MAX 100000
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n;

vector<pair<unsigned int, unsigned int> > a;
unsigned int aend[MAX];


bool comp(pair<unsigned int,unsigned int> x, pair<unsigned int,unsigned int> y)
{
  return (x.first) > (y.first);
}

void flow(vector<pair<unsigned int,unsigned int> > v, unsigned int end[MAX])
{
  make_heap (v.begin(),v.end(),comp);
  for(int i=0; i<n; i++)
  {
    pair<unsigned int,unsigned int> aux = v[0];
    end[i] = aux.first;
    aux.first += aux.second;
    pop_heap(v.begin(), v.end(), comp);
    v[v.sz-1] = aux;
    push_heap(v.begin(), v.end(), comp);
  }
}

int main()
{
  int na, nb;
  fin >> n >> na >> nb;
  a.resize(na);
  unsigned int aux;
  REP(i, na)
  {
    fin >> aux;
    a[i] = pair<unsigned int,unsigned int>(aux,aux);
  }

  //flow(a, aend);
  unsigned int maxa = 0, maxb = 0;
  make_heap (a.begin(),a.end(),comp);
  for(int i=0; i<n; i++)
  {
    pair<unsigned int,unsigned int> aux = a[0];
    aend[i] = aux.first;
    maxa = max(maxa, aend[i]);
    aux.first += aux.second;
    pop_heap(a.begin(), a.end(), comp);
    a[a.sz-1] = aux;
    push_heap(a.begin(), a.end(), comp);
  }

  a.resize(nb);
  REP(i, nb)
  {
    fin >> aux;
    a[i] = pair<unsigned int,unsigned int>(aux,aux);
  }

  //flow(b, bend);
  make_heap (a.begin(),a.end(),comp);
  for(int i=0; i<n; i++)
  {
    pair<unsigned int,unsigned int> aux = a[0];
    maxb = max(maxb, aend[n-i-1] + aux.first);
    aux.first += aux.second;
    pop_heap(a.begin(), a.end(), comp);
    a[a.sz-1] = aux;
    push_heap(a.begin(), a.end(), comp);
  }

  fout << maxa << " " << maxb << endl;
	
	return 0;
}
