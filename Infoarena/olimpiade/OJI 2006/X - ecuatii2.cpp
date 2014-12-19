#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define INFILE "ecuatii2.in" 
#define OUTFILE "ecuatii2.out"
#define BUF_SIZE 512
ifstream fin (INFILE);
ofstream fout (OUTFILE);

char buf[BUF_SIZE];

int main()
{
	int N;
	fin >> N;
	fin.getline(buf, BUF_SIZE);
	while( N-- ) {
		fin.getline(buf, BUF_SIZE);
		int x[2], v[2];
		int semn = 1, n = strlen(buf), part = 0;
		x[0] = v[0] = x[1] = v[1] = 0;

		for(int i=0; i<n; i++)
			if( isdigit(buf[i]) ) 
			{
				int nr = 0;
				while( isdigit(buf[i]) ) {
					nr = nr*10 + buf[i] - int('0');
					i++;
				}
				nr *= semn;
				semn = 1;

				if( buf[i]=='x' ) x[part] += nr;
				else {
					v[part] += nr;
					i--;
				}
			} 
			else 
			{
				switch( buf[i] ) {
					case 'x':
						x[part] += semn;
						semn = 1;
						break;
					case '-':
						semn = -1;
						break;
					case '+':
						semn = 1;
						break;
					case '=':
						part = 1;
						break;
					default:
						printf("Error - illegal char");
						break;
				}
			}
		
		int final_x = x[0] - x[1];
		int final_v = v[1] - v[0];
		if( final_x==0 ) {
			if( final_v==0 ) fout << "infinit";
			else	fout << "imposibil";
		} else {
			if( final_x<0) final_x *= -1, final_v *= -1;

			fout << fixed;
			fout << setprecision(4) << double(final_v) / double(final_x);
		}
		fout << "\n";
	}

	return 0;
}