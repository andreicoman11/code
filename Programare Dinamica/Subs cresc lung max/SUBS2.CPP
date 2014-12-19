//subsir crescator maximal
//PD liniar   metoda inapoi
#include <iostream.h>

int l[50], t[50], a[50], n;
//l[i] cel mai lung subsir care se termina cu a[i]
// t[i] = j   in stanga elem a[i] se afla elem a[j] (in subsirul crescator)
int Din();
void Afis(int);
void Cit();

int main()
{
	Cit();
	int k = Din();
	for (int i = 1; i <= n; i++ )
		cout << l[i] << " ";
	cout << endl;
	cout << k << endl;

	Afis( k );

	return 0;
}

int Din()
{
	for (int i = 1; i <= n; i++ )
	{
		l[i] = 1, t[i] = 0; //n-are vecin in stanga
		for ( int j = 1; j < i; j++)
			if ( a[j] < a[i] && l[j] + 1 > l[i])
			{
				l[i] = l[j] + 1;
				t[i] = j; // j este vecinul din stanga
			}
	}

	int max = 0, k;
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
	Afis( t[i] );
	cout << a[i] << ' ';
}

void Cit()
{
	cout << "n = "; cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

}


