#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "hotel.in" 
#define OUTFILE "hotel.out"
FILE *fin, *fout;
#define VMAX 400001

int v[VMAX][3], a, b;

int max(int x, int y)
{
  return x > y ? x : y;
}

void init(int idx, int st, int dr)
{
  v[idx][1] = dr-st+1;
}

void add(int idx, int st, int dr)
{
  int mij = (st+dr)>>1, l = ((idx+1)<<1)-1, r = (idx+1)<<1;

  if( a<=st && dr<=b )
  {
    // fill everything
    v[idx][0] = v[idx][1] = v[idx][2] = 0;
    return;
  }

  // verify if subtree has been recently updated
  if( v[idx][1]==dr-st+1 )
  {
    v[l][0] = v[l][1] = v[l][2] = mij-st+1;
    v[r][0] = v[r][1] = v[r][2] = dr-mij;
  }

  if( v[idx][1]==0 )
    v[l][0] = v[l][1] = v[l][2] = v[r][0] = v[r][1] = v[r][2] = 0;

  if( a<=mij ) add( l, st, mij);
  if( b>mij ) add( r, mij+1, dr);  
  
  // recompute local maximum
  v[idx][0] = v[l][0];
  v[idx][2] = v[r][2];

  if( v[l][0]==mij-st+1 || v[r][2]==dr-mij )
  {
    v[idx][1] = v[l][2] + v[r][0];
    if( v[l][0]==mij-st+1 ) v[idx][0] += v[r][0];
    if( v[r][2]==dr-mij ) v[idx][2] += v[l][2];
  }
  else 
    v[idx][1] = max(v[l][2] + v[r][0], max(v[l][1], v[r][1]));
}

void rem(int idx, int st, int dr)
{
  int mij = (st+dr)>>1, l = ((idx+1)<<1)-1, r = (idx+1)<<1;
  if( a<=st && dr<=b )
  {
    // remove everything
    v[idx][0] = v[idx][1] = v[idx][2] = dr-st+1;
    return;
  }

  // verify if subtree has been recently updated
  if( v[idx][1]==dr-st+1 )
  {
    v[l][0] = v[l][1] = v[l][2] = mij-st+1;
    v[r][0] = v[r][1] = v[r][2] = dr-mij;
  }

  if( v[idx][1]==0 )
    v[l][0] = v[l][1] = v[l][2] = v[r][0] = v[r][1] = v[r][2] = 0;
  
  if( a<=mij ) rem( l, st, mij);
  if( b>mij ) rem( r, mij+1, dr);

  // recompute local maximum
  v[idx][0] = v[l][0];
  v[idx][2] = v[r][2];
  
  if( v[l][0]==mij-st+1 || v[r][2]==dr-mij )
  {
    v[idx][1] = v[l][2] + v[r][0];
    if( v[l][0]==mij-st+1 ) v[idx][0] += v[r][0];
    if( v[r][2]==dr-mij ) v[idx][2] += v[l][2];
  }
  else
    v[idx][1] = max(v[l][2] + v[r][0], max(v[l][1], v[r][1]));
}

int main()
{
  fin  = fopen(INFILE, "r");
  fout = fopen(OUTFILE, "w");
  memset(v, 0, sizeof(v));
  int n, ops, op;

  fscanf(fin, "%d %d\n", &n, &ops);
  init(0, 0, n-1);

  REP(i, ops)
  {
    fscanf(fin, "%d", &op);
    switch(op) {
      case 1:
        fscanf(fin, "%d %d\n", &a, &b);
        b = a+b-2;
        a--;
        add(0, 0, n-1);
        break;
      case 2:
        fscanf(fin, "%d %d\n", &a, &b);
        b = a+b-2;
        a--;
        rem(0, 0, n-1);
        break;
      default:
        fprintf(fout, "%d\n", v[0][1]);
    }
  }
	
	return 0;
}
