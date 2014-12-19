#include <iostream>
#include <fstream>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "cpal.in" 
#define OUTFILE "cpal.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	for(int N=0; N<10; N++) {
		int s = 0, imp = 0, nr;
		for(int i=0; i<9; i++) {
			fin >> nr;
			s += nr;
			if( nr%2 ) imp++;
		}
		fout << ((s>0) && (imp<2)) << endl;
	}
	return 0;
}