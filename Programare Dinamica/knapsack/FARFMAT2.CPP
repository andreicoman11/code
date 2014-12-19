/*
    O(N * T) time complexity
    O(2 * T) memory complexity
    foloseste matrice cu 2 linii in loc de doua siruri
*/
#include <fstream.h>
#define IN "t9"
#define OUT "farfurii.out"

int a[2][10000];    // a[0] linia precedenta (i-1)  a[1] - linia curenta (i)
                    // a[l2][j] nr max de farf dintre primele i, spalate in timpul j 
                    // a[l1][j] nr max de farf dintre primele i-1, spalate in timpul j 
                    // farf i nu trebuie spalata obligatoriu
int t[100], tmin, max, T, n;

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
	int i, j, l1 = 0, l2 = 1;
	max = 0;
	tmin = 0;     // cate secunde pana la maxim
	for ( i = 1; i <= T; i++ ) a[0][i] = -1;
	a[0][1] = 0;  // intr-o secunda nu pot spala o farfurie, ci numai s-o sparg (nr farfurii spalate intr-o secunda)
	a[0][t[1]] = 1;  //iau prima farfurie separat

	max = a[0][t[1]]; tmin = t[1];

	for ( i = 2; i <= n; i++, l1 = l1^1, l2 = l2^1 )  // pt fiec farfurie incepand cu a 2
	{
		for ( j = 1; j <= T; j++ )	a[l2][j] = -1;
		for ( j = 1; j <= T; j++ )  // pt fiecare secunda
			if ( a[l1][j] != -1 ) // daca in timpul j s-a spalat sau spart cel putin o farfurie
			{
				 if  ( a[l2][j+1] < a[l1][j] ) a[l2][j+1] = a[l1][j];  // daca as sparge farf i
				 if  ( a[l2][j+t[i]] < a[l1][j] + 1 )   // daca as spala-o
					a[l2][j+t[i]] = a[l1][j] + 1;
			} 
		for ( j = 1; j <= T; j++ )
			if ( a[l2][j] > max || ( a[l2][j] == max &&  j < tmin ) )
			{
				tmin = j; max = a[l2][j];
			}
	}
}

void Afisare()
{
	ofstream g(OUT);
	g << max << " " << tmin;
	g.close();
}

