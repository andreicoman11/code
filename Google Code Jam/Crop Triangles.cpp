#include <fstream>
using namespace std;
#define LL long long

long long getPosT(LL x, LL y, int n, LL a, LL b, LL c, LL d, LL m)
{
  LL typt[9] = {0}, res = 0;
  do{
    typt[ (x%3)*3 + y%3 ]++;
    x = (a*x + b)%m;
    y = (c*y + d)%m;
  }while(--n);

  for(int t1=0; t1<9; t1++)
    res += typt[t1] * (typt[t1]-1) * (typt[t1]-2) / 6;

  for(int t1=0; t1<9; t1++)
  for(int t2=t1+1; t2<9; t2++)
  for(int t3=t2+1; t3<9; t3++)
    if( (t1/3+t2/3+t3/3)%3==0 &&
        (t1%3+t2%3+t3%3)%3==0 )
    {
        res += typt[t1] * typt[t2] * typt[t3];
    }
  return res;
}

int main()
{
  ifstream fin("A-large-practice.in");
  ofstream fout(".out");
  int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
    int n;
    LL x, y, A,B, C, D, M;
    fin >> n >> A >> B >> C >> D >> x >> y >> M;
	
		fout << "Case #" << r << ": " << getPosT(x, y, n, A, B, C, D, M) << "\n";
	}
  return 0;
}