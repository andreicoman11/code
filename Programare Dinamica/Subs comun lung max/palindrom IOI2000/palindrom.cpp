#include <fstream.h>
#include <string.h>

#define DIM 101
#define Max(x, y) ( (x > y) ? (x) : (y) )

ifstream fin("palin.in");
ofstream fout("palin.out");
char s[DIM], rev[DIM]; // sirul si inversul lui
int a[DIM][DIM];    // matr dinamica
int i, j, n;

void Dinamic();

int main()
{
	fin >> n;
	for ( i = 1; i <= n; i++ )
		fin >> s[i];
	for ( i = 1; i <= n; i++ )
		rev[i] = s[n-i+1];
	fin.close();

	Dinamic();
	fout << n - a[n][n];
	fout.close();
	return 0;
}


void Dinamic()
{

	for (int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			if ( s[i] == rev[j] ) a[i][j] = a[i-1][j-1] + 1;
			else                a[i][j] = Max(a[i-1][j], a[i][j-1] );
}



