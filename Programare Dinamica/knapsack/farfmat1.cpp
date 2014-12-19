// Punctaj maxim
// O(N * T) time complexity
// O(N * T) memory complexity
#include <fstream.h>
#define IN "t6"
#define OUT "farfurii.out"

int a[76][1001];  // a[i][j] NR MAX DE FARF. SPALATE DINTRE PRIMELE i IN TIMPUL j
                  // farf i poate fi sparta sau spalata (poate fi aleasa sau nu)
int t[100];       // timpii de spalare a farfuriilor
int max;          // nr maxim de farf spalate in timpul T (raspunsul)
int tmin, T, n;    // timpul minim in care se spala max farfurii (tmin <= T)

void Citire();
void Dinamic();
void Afisare();

int main()
{
	Citire();
	Dinamic();
	Afisare();
	return 0;
}

void Citire()
{
	ifstream f(IN);
	f >> n >> T; //  nr farfurii, timpul total
	for ( int i = 1; i <= n; i++ )
		f >> t[i];
	f.close();
}

void Dinamic()
{
	int i, j;
	max = 0;
	tmin = 0;     // cate secunde pana la maxim
	for ( i = 1; i <= T; i++ ) a[1][i] = -1;
	a[1][1] = 0;  // intr-o secunda nu pot spala o farfurie, ci numai s-o sparg (nr farfurii spalate intr-o secunda)
	a[1][t[1]] = 1;  //iau prima farfurie separat

	max = a[1][t[1]]; tmin = t[1];

	for ( i = 2; i <= n; i++ )  // pt fiec farfurie incepand cu a 2
	{
		for ( j = 1; j <= T; j++ )	a[i][j] = -1;  
		for ( j = 1; j <= T; j++ )  // pt fiecare secunda
			if ( a[i-1][j] != -1 ) // daca in timpul j s-a spalat sau spart cel putin o farfurie
			{
				 if  ( a[i][j+1] < a[i-1][j] ) a[i][j+1] = a[i-1][j];  // daca as sparge farf i
				 if  ( a[i][j+t[i]] < a[i-1][j] + 1 )   // daca as spala-o
					a[i][j+t[i]] = a[i-1][j] + 1;
			}  
		for ( j = 1; j <= T; j++ )
			if ( a[i][j] > max || ( a[i][j] == max &&  j < tmin ) )
			{
				tmin = j; max = a[i][j];
			}
	}
}

void Afisare()
{
	ofstream g(OUT);
	g << max << " " << tmin;
	g.close();
}

