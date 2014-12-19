//subsir crescator maximal
#include <fstream.h>
#include <iostream.h>

int l[50], t[50], a[50], n;
//l[i] cel mai lung subsir care incepe (de la stanga spre dreapta) la pozitia i
int Din();
void Afis(int);
void Cit();

int main()
{
	Cit();
	int k = Din();

	Afis( k ); //afis subs cresc maximal
	system("pause");
	return 0;
}

int Din()
{
    int i, j;
	for ( i = n; i >= 1; i-- )
	{
		l[i] = 1, t[i] = 0;
		for ( j = i + 1; j <= n; j++)
			if ( a[j] > a[i] && l[i] < l[j] + 1)
			{
				l[i] = l[j] + 1;
				t[i] = j;
			}
	}

	int max = l[1], k;
	for ( i = 1; i <= n; i++)
		if ( l[i] > max )
		{
			max = l[i];
			k = i;
		}
	return k;
}

void Afis(int i)
{
	if ( i == 0 ) return;
	cout << a[i] << ' ';
	Afis( t[i] );
}

/*
void Afis(int i)
{
	while ( i )
	{
		cout << a[i] << " ";
		i = t[i];
	}
}
*/

void Cit()
{
	ifstream f("cresc.in");
	f >> n;
	for ( int i = 1; i <= n; i++ )
	{

		f >> a[i];
	}
	f.close();

}


