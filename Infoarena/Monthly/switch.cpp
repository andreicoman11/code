#include <fstream>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "switch.in" 
#define OUTFILE "switch.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int main()
{
	int T;
	fin >> T;
	for(int i=0; i<T; i++)
	{
		int a = 0, b = 0, c;
		for(int j=0; j<4; j++) {
			fin >> c;
			a += c;
		}
		for(int j=0; j<4; j++) {
			fin >> c;
			b += c;
		}
		if( a%2==b%2 ) fout << "DA\n";
		else fout << "NU\n";
	}

	return 0;
}