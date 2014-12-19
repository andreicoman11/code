#include <fstream.h>
#include <string.h>

#define DIM 101
#define Max(x, y) ( (x > y) ? (x) : (y) )

char *s, *rev; // sirul si inversul lui
int (*a)[DIM];    // matr dinamica
int lc, lp;  // linia curenta, linia precedenta
int i, j, n;

void Alloc();
void Dealloc();
void Dinamic();
void Read();
void Write();

int main()
{
    Read();
    Dinamic();
	Write();
	
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

void Alloc()
{
    s = new char [n + 1];
    rev = new char [n + 1];

    a = new int [2][DIM];  // matrice 2 x (n+1)
    memset(a, 0, sizeof(a[0][0])*2 * DIM);
    memset( s, 0, sizeof(char)*(n+1) );
    memset(rev, 0, sizeof(char)*(n+1) );
}

void Dealloc()
{
    delete [] s;
    delete [] rev;
    delete [] a;    // eliberez matricea
}    


void Read()
{
    ifstream fin("palin.in");
   	fin >> n;
    Alloc();
	for ( i = 1; i <= n; i++ )
		fin >> s[i];
	for ( i = 1; i <= n; i++ )
		rev[i] = s[n-i+1];
	fin.close();
}

void Write()
{
    ofstream fout("palin.out");
	fout << n - a[lc][n];
	Dealloc();
	fout.close();
}
