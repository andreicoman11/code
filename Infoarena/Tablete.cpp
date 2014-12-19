#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin ("tablete.in");

int N, k;

int main()
{
	FILE* fout;
	fout = fopen( "tablete.out", "w");
	int n = 0;
	fin >> N >> k;
	//cout << N << " " << k << endl;
	if( N%2==0 )
	{
		if( k%2==0 )
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				fprintf(fout, "%d ", ++n);
			fprintf(fout, "\n");
		}
		else
		{
			n++;
			for(int i=0; i<N-2; i++)
			{
				for(int j=0; j<N; j++)
					fprintf(fout, "%d ", ++n);
				fprintf(fout, "\n");
			}
			for(int j=0; j<N-1; j++)
				fprintf(fout, "%d ", ++n);
			fprintf(fout, "%d\n", n+N-1);
			fprintf(fout, "1 ");
			for(int j=1; j<N-1; j++)
				fprintf(fout, "%d ", ++n);
			fprintf(fout, "%d\n", n+2);
		}
	} else {

		if( k%2==0 )
		{
			for(int i=0; i<N-1; i+=2)
			{
				for(int j=0; j<N-1; j++)
					fprintf(fout, "%d ", ++n);
				fprintf(fout, "%d\n", n+1+N);
				for(int j=0; j<N; j++)
					fprintf(fout, "%d ", ++n);
				fprintf(fout,"\n");
				++n;
			}
			for(int j=0; j<N; j++)
				fprintf(fout, "%d ", ++n);
		} else {
			for(int i=0; i<N-1; i+=2)
			{
				int lastn = ++n;
				for(int j=0; j<N; j++)
					fprintf(fout, "%d ", ++n);
				fprintf(fout, "\n%d ", lastn);
				for(int j=1; j<N-1; j++)
					fprintf(fout, "%d ", ++n);
				if( i<N-3 ) fprintf(fout, "%d ", ++n);
				else fprintf(fout, "%d ", n+1+N);
				fprintf(fout,"\n");
			}
			for(int j=0; j<N; j++)
				fprintf(fout, "%d ", ++n);
		}

	}

	fclose(fout);
	/*ifstream in("tablete.out");
	for(int i=0;i<N; i++)
	{
		int nr, aux;
		in >> nr;
		for(int j=1; j<N; j++)
		{
			in >> aux;
			if( j==k-1 && aux%2==1 ) cout << "nu este par\n";
			if( nr>=aux ) cout << "nu este mai mare\n";
			nr = aux;
		}
		
	}*/
		

return 0;
}


