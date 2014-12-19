#include <iostream>
#include <iomanip>
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
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "drepte3.in" 
#define OUTFILE "drepte3.out"
#define MAX 100001

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int d[MAX][3];
double xmax, xmin, ymax, ymin;
bool ini = false;

void init(double x, double y)
{
  xmax = xmin = x;
  ymax = ymin = y;
  ini = true;
}

void adauga(double x, double y)
{
  xmax = x > xmax ? x : xmax;
  xmin = x < xmin ? x : xmin;
  ymax = y > ymax ? y : ymax;
  ymin = y < ymin ? y : ymin;
}

void search(int i, int j)
{
  double x, y;
  double a1 = (double)d[i][0];
  double a2 = (double)d[j][0];
  double b1 = (double)d[i][1];
  double b2 = (double)d[j][1];
  double c1 = (double)d[i][2];
  double c2 = (double)d[j][2];

  if( d[i][0]==0 )
  {
    y = (-1) * c1 / b1;
    x = (-1) * (b2 * y + c2) / a2;
  }
  else
  {
    y = (a1*c2 - a2*c1) / (a1*b2 - a2*b1);
    x = (-1) * (b1 * y - c1) / a1;
  }

  if( !ini ) init(x, y);
  else adauga(x, y);
}

int comp1(const void * x, const void * y)
{
  int* a = (int*)x;
  int* b = (int*)y;
  double a1, a2, b1, b2;
  a1 = (double)*(a);
  b1 = (double)*(a+1);
  a2 = (double)*(b);
  b2 = (double)*(b+1);
  if( b1==0.0 ) b1 = 0.00001;
  if( b2==0.0 ) b2 = 0.00001;
  if(a2 / b2 > a1 / b1 ) return 1;
  else if(a2 / b2 < a1 / b1 ) return -1;
  return 0;
}

int comp2(const void * x, const void * y)
{
  return comp1(x, y) *(-1);
}

int comp3(const void * x, const void * y)
{
  int* a = (int*)x;
  int* b = (int*)y;
  double a1, a2, b1, b2;
  a1 = (double)*(a);
  b1 = (double)*(a+1);
  a2 = (double)*(b);
  b2 = (double)*(b+1);
  if( a1==0.0 ) a1 = 0.00001;
  if( a2==0.0 ) a2 = 0.00001;
  
  if(b2 / a2 > b1 / a1 ) return 1;
  else if(b2 / a2 < b1 / a1 ) return -1;
  return 0;
}

int comp4(const void * x, const void * y)
{
  return comp3(x, y) * (-1);
}

void printd(int n)
{
  REP(i, n)
    cout << d[i][0] << " " << d[i][1] << " " << d[i][2] << endl;
  cout << endl;
}

int main()
{
  int N;
  fin >> N;
  REP(i, N)
    fin >> d[i][0] >> d[i][1] >> d[i][2];

  // x min
  qsort(d, N, 3*sizeof(int), comp1);//printd(N);
  search(0, N-1);
  REP(i, N-1)
    search(i, i+1);
  //cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;

  // x max - reverse of xmin sort
  /*qsort(d, N, 3*sizeof(int), comp2);//printd(N);
  search(0, N-1);
  REP(i, N-1)
    search(i, i+1);*/
  //cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;

  // y min
  qsort(d, N, 3*sizeof(int), comp3);//printd(N);
  search(0, N-1);
  REP(i, N-1)
    search(i, i+1);
  //cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;

  // y max - reverse of ymin sort
  /*qsort(d, N, 3*sizeof(int), comp4);//printd(N);
  search(0, N-1);
  REP(i, N-1)
    search(i, i+1);*/
	
  //cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
  fout << setprecision(6) << fixed << (xmax - xmin) * (ymax - ymin) << endl;

	return 0;
}
