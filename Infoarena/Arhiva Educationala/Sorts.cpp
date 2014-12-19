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
#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)

int* mergeSort(int v[], int a, int b)
{
  int *ans = new int[b-a+1];
  if( b-a==0 )
  {
    ans[0] = v[a];
    return ans;
  }
  int m = (a+b)/2;
  int* l = mergeSort(v, a, m);
  int* r = mergeSort(v, m+1, b);

  int i=0, j=0, k=0;
  while(k<b-a+1)
  {
    if( i<=m-a && (l[i]<r[j] || j>=b-m) )
    {
      ans[k] = l[i];
      i++;
    } else {
      ans[k] = r[j];
      j++;
    }
    k++;
  }
  return ans;
}

VI quickSort(VI v)
{
  if( v.sz<=1 ) return v;
  int m = v.sz / 2;
  VI l, r;
  REP(i, v.sz)
    if( v[i]<v[m] )
      l.pb(v[i]);
    else if( i!=m )
      r.pb(v[i]);

  VI rez = quickSort(l);
  rez.pb(v[m]);
  v = quickSort(r);
  rez.insert(rez.end(), v.begin(), v.end());
  return rez;
}

int main()
{
  int v[] = {18,  6,  9,  1,  4, 15, 12,  5,  6,  7, 11};
  
  int *x = mergeSort(v, 0, 10);
  REP(i, 11)
    cout << x[i] << " ";
  cout << endl;

  VI qx;
  qx.insert(qx.begin(), v, v+11);

  qx = quickSort(qx);
  REP(i, qx.sz ) 
    cout << qx[i] << " ";
  cout << endl;
	
	return 0;
}
