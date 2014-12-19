#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("maxunice.in");

int main()
{
  FILE* fout = fopen("maxunice.out", "w");

  long long n;
  fin >> n;
  long double nsq = 2*(long double)n + 9.0 / 4.0;
  nsq = sqrt(nsq);
  nsq -= 1.5;
  long long r1 = (long long)nsq;
 
  while( r1*(r1+1)/2 < n )
    r1++;

  if( r1*(r1+1)/2==n )
  {
    fprintf(fout, "%d\n", (unsigned int) r1);
    unsigned int i = 1;
    for(; i+3<=r1; i+=4)
      fprintf(fout, "%d\n%d\n%d\n%d\n", i, i+1, i+2, i+3);
    while( i<=r1 )
    {
      fprintf(fout, "%d\n", i);
      i++;
    }
    return 0;
  }

  r1--;
  fprintf(fout, "%d\n", (unsigned int)r1);

  unsigned int i=1;
  for(; i+3<r1; i+=4)
    fprintf(fout, "%d\n%d\n%d\n%d\n", i, i+1, i+2, i+3);
  while( i<r1 )
  {
    fprintf(fout, "%d\n", i);
    i++;
  }
  fprintf(fout, "%d\n", (unsigned int)(n - r1*(r1-1)/2));

  return 0;
}
