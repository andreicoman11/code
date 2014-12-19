#include <iostream>
#include <fstream>
#include <sstream>
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
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "jku.in" 
#define OUTFILE "jku.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

vector<int> perm, ans;
map<int, int> p;

struct inv{
  VI ans;
  map<int, int> p;
};

VI InversionPairWithIndex(int xi, int i, int xj, int j)
{
  VI aux = perm;
  unsigned int s = i, e = j-1;
  if( xi+xj==-1 ) {s = i+1;e=j;}
  FOR(k, s, e+1)
  {
    //cout << aux[k] << " " << perm[e-k+s] << endl;
    aux[k] = (-1) * perm[e-k+s];
  }
  return aux;
}

bool verif(int a, int b)
{
  if( a<0 && b>=0 ) return true;
  if( a>=0 && b<0 ) return true;
  return false;
}

inv* getInversions(VI v)
{
  ans.clear();
  p.clear();
  REP(i, v.sz-1)
    FOR(j,i+1,v.sz)
    if( verif(v[i],v[j]) && abs( abs(v[i])-abs(v[j]))==1 )
    {
      ans.pb(i);
      p[i] = j;

    }
  /*cout << ans.sz;
  //SORT(ans);
  REP(i, ans.sz)
    cout << " " << ans[i] << " " << p[ans[i]];cout << endl;*/
  inv *a = new inv();
  a->ans = ans;
  a->p = p;
  return a;
}

void printV(VI v)
{
  REP(i, v.sz)
    cout << v[i] << " ";cout << endl;
}

int main()
{
  int n;
  while( fin >> n )
  {
    perm.resize(n);
    REP(i, perm.sz)
      fin >> perm[i];
    printV(perm);cout << endl;
    getInversions(perm);
    VI base = ans;
    map<int, int> p_base = p;
    int counter = 0;
    while( base.sz>0 )
    {
      //VI scores(ans.sz);
      int maxscore = -1;
      VI perm2;
      REP(k, ans.sz)
      {
        int xi,xj,i,j;
        i = base[k];
        j = p_base[i];
        xi = perm[i];
        xj = perm[j];
        //cout << "do perm " << xi << " " << i << " " << xj << " " << j << endl;
        VI rez = InversionPairWithIndex(xi,i,xj,j);
        //cout << "rez = ";printV(rez);
        
        getInversions(rez);
        //cout << ans.sz << endl;
        if( (int)ans.sz>maxscore )
        {
          //cout << "new max score: " << maxscore << "\n";
          maxscore = ans.sz;
          perm2 = rez;
        }
        //cout << "-----------------------------------\n";
      }
      //cout << "found perm with maximum score of invertions\n";
      cout << "next : "; printV(perm2);
      counter++;
      perm = perm2;
      getInversions(perm);
      base = ans;
      p_base = p;
    }
    fout << counter << endl;
  }
  return 0;
}