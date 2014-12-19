#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define INFILE "transport2.in" 
#define OUTFILE "transport2.out"
#define NMAX 100010
#define MMAX 200010
#define WMAX 10010

typedef struct nod{
  int end, wm;
  nod* next;
};

nod* v[NMAX];
int n, q[NMAX];
bool isv[NMAX];//, isw[WMAX];

bool check(int w)
{
  memset(isv, 0, sizeof(isv));
  isv[0] = 1;
  q[0] = 0;
  int qs = 0, qe = 1;
  while( qs<qe && isv[n-1]==0 )
  {
    for(nod* nv = v[q[qs++]]; nv!=NULL && isv[n-1]==0; nv = nv->next)
      if( nv->wm>=w && isv[nv->end]==0 )
      {
        q[qe++] = nv->end;
        isv[nv->end] = 1;
      }
  }
  return isv[n-1];
}

int bin_search(int l, int r)
{
  if( l+1>=r )
  {
    if( r>l && check(r) ) return r;
    return l;
  }

  int mid = (l + r) >> 1;
  if( check(mid) )
  {
    //while( !isw[mid] ) mid++;
    l = mid;
  }
  else
  {
    //while( !isw[mid-1] ) mid--;
    r = mid - 1;
  }

  return bin_search(l, r);
}

void addv(int x, nod* nnew)
{
  //if( v[x]==NULL || v[x]->wm <= nnew->wm )
  //{
    nnew->next = v[x];
    v[x] = nnew;
  /*}
  else
  {
    nod* nx = v[x];
    while( nx->next!=NULL && nx->next->wm > nnew->wm )
      nx = nx->next;
    nnew->next = nx->next;
    nx->next = nnew;
  }*/
}

nod na[MMAX], nb[MMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);
  int m, w1 = 0, w2 = 0;
  scanf("%d %d", &n, &m);
  memset(v, NULL, sizeof(v));
  //memset(isw, NULL, sizeof(isw));
  int a, b, wab;
  for(int i=0; i<m; i++)
  {
    scanf("%d %d %d", &a, &b, &wab);
    a--; b--; //isw[wab] = 1;
    if( a==0 || b==0 ) w1 = max(w1, wab);
    if( a==n-1 || b==n-1 ) w2 = max(w2, wab);
    na[i].end = b, na[i].wm = wab; addv(a, &na[i]);
    nb[i].end = a, nb[i].wm = wab; addv(b, &nb[i]);
  }
  printf("%d\n", bin_search(1, min(w1, w2)));

	return 0;
}
