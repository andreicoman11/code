#include <iostream>
#include <fstream>

#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "arbint.in" 
#define OUTFILE "arbint.out"
#define VMAX 400001

int v[VMAX];
int pos, nr, a, b, maxv;

int max(int a, int b)
{
  return a > b ? a : b;
}
void add(int idx, int st, int dr)
{
  if( st==dr )
  {
    v[idx] = nr;
    return;
  }
  
  int mij = (st+dr)/2;
  if( pos<=mij ) add( (idx+1)*2-1, st, mij);
  else           add( (idx+1)*2, mij+1, dr);
  v[idx] = max(v[(idx+1)*2-1], v[(idx+1)*2]);
}

void getmax(int idx, int st, int dr)
{
  if(a<=st && dr<=b )
  {
    maxv = max(maxv, v[idx]);
    return;
  }
  int mij = (st+dr)/2;
  if( a<=mij )      getmax( (idx+1)*2-1, st, mij);
  if( b>mij )  getmax( (idx+1)*2, mij+1, dr);
}

int main()
{
  memset(v, 0, sizeof(v));
  int ops, op, n;

  FILE* fin = fopen(INFILE, "r");
  FILE* fout = fopen(OUTFILE, "w");

  fscanf(fin, "%d %d\n", &n, &ops);
  REP(i, n)
  {
    fscanf(fin, "%d ", &nr);
    pos = i;
    add(0, 0, n-1);
  }

  REP(i, ops)
  {
    fscanf(fin, "%d %d %d\n", &op, &a, &b);
    switch(op) {
      case 0:
        a--;
        b--;
        maxv = -1;
        getmax(0, 0, n-1);
        fprintf(fout, "%d\n", maxv);
        break;
      default:
        pos = a-1;
        nr = b;
        add(0, 0, n-1);
    }
  }
	
	return 0;
}
