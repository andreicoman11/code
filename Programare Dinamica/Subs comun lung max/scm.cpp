//Det subsirlui comun de lungime maxima
#include <fstream.h>
#include <iomanip.h>

int a[100][100];  //a[i][j] - lung maxima a subs. comun format cu primele i elem din x si primele j din y
int x[100], y[100], i, j, m, n;

ifstream fin("subsirmax.in");
ofstream fout("scm.out");

void Citeste();
void Dinamic();
void Afiseaza(int i, int j);
void Write();

int main()
{
	Citeste();
	Dinamic();
	fout << "Lungimea subsirlui comun maximal este : " << a[m][n] << '\n';
	Write();
	Afiseaza(m, n);
    fout.close();

	return 0;
}


void Citeste()
{
	fin >> m >> n;
	for (  i = 1; i <= m; i++ ) fin >> x[i];
	for (  i = 1; i <= n; i++ ) fin >> y[i];
	fin.close();
}


void Afiseaza(int i, int j)
{
	if ( i == 0  ||  j == 0 ) return;
	if ( x[i] == y[j] )
	{
		Afiseaza( i - 1, j - 1 );
		fout << x[i] << " ";
	}
	else
		if ( a[i-1][j] >= a[i][j-1] ) Afiseaza( i - 1, j );
		else                         Afiseaza( i, j - 1 );
}

int Max(int a, int b )
{
	return (a > b) ? a : b;
}

void Dinamic()
{
	for (i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
			if ( x[i] == y[j] ) a[i][j] = a[i-1][j-1] + 1;
			else                a[i][j] = Max(a[i-1][j], a[i][j-1] );
        
    }    
}

void Write()
{
    int i, j;
    fout << "\n";
    for (i = 0; i <= n; i++ )
        fout << setw(3) << y[i];
    fout << "\n";    
    for ( i = 1; i <= m; i++ )
    {
        fout << setw(3) << x[i];
        for (j = 1; j <= n; j++ )
            fout << setw(3) << a[i][j];
        fout << "\n";
    }
}        
