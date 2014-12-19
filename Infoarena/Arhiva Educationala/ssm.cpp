#include <iostream>
#include <fstream>
using namespace std;

#define INFILE "ssm.in" 
#define OUTFILE "ssm.out"

int main()
{
  ifstream fin(INFILE);

  int n, msum, mst, mend, nr, sum, ist;
  fin >> n >> msum;
  mst = mend = 0;
  sum = (msum < 0 ? 0 : msum);
  ist = (sum==msum ? 0 : 1);

  for(int i=1; i<n; i++)
  {
    fin >> nr;
    sum += nr;
    if( sum>msum )
      mst = ist, mend = i, msum = sum;
    if( sum<0 )
      sum = 0, ist = i+1;
  }

  ofstream fout(OUTFILE);
  fout << msum << " " << mst+1 << " " << mend+1 << "\n";
	
	return 0;
}
