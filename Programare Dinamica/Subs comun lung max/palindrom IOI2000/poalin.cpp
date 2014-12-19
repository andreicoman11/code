#include <fstream.h>
#include <string.h>

#define DIM 101
#define Max(x, y) ( (x > y) ? (x) : (y) )

ifstream fin("palin.in");
ofstream fout("palin.out");
char s[DIM], rev[DIM]; // sirul si inversul lui
int a[2][DIM];    // matr dinamica
int lc, lp;  // linia curenta, linia precedenta
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
	fout << n - a[lc][n];
	fout.close();
	return 0;
}


void Dinamic()
{
	lp = 0; lc = 1; // linia precedenta, curenta
	for (int i = 1; i <= n; i++, lc = !lc, lp = !lp  )
		for ( int j = 1; j <= n; j++ )
			if ( s[i] == rev[j] ) a[lc][j] = a[lp][j-1] + 1;
			else                a[lc][j] = Max(a[lp][j], a[lc][j-1] );
}



