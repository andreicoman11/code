//Sursa: 2004 ACM Southeastern Europe Problema I
//Metoda de rezolvare: Brute force
//Timp: O(n) se poate si in O(1), daca e necesar
//Memorie: O(1)

#include <fstream>

using namespace std;

void main()
{
	ifstream fin("f.dat");
	ofstream fout("f.out");
	int n;
	//Metoda taranului - no comment
	while (fin>>n)
	{
		int i=1, j=1;
		for (int q=1;q<n;++q)
		{
			if ((i+j)&1)
				if (j==1)
				{
					++i;
				}
				else
				{
					++i;
					--j;
				}
			else
				if (i==1)
				{
					++j;
				}
				else
				{
					--i;
					++j;
				}
		}
		fout<<"TERM "<<n<<" IS "<<i<<"/"<<j<<endl;
	}
}