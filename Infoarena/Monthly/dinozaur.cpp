#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "dinozaur.in" 
#define OUTFILE "dinozaur.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

char sir[100100];
bool v[128];

#define min(x,y) (x<y ? x : y)

int main()
{
	fin.getline(sir, 100100);
	memset(v, 0, sizeof(v));
	for(int i=0; i<min(27, strlen(sir)); i++)
		if( v[ int(sir[i]) ] ) {
			fout << 1;
			return 0;
		} else v[ int(sir[i]) ] = 1;
	fout << 0;
	return 0;
}