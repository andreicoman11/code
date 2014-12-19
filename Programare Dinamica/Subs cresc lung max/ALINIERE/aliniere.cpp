#include <fstream>
using namespace std;
#define INFINIT 1000000

const int DIM = 1001;

int l[DIM], r[DIM];  // left, right  l[i] - cmls cresc care se incepe din stanga si se "termina" pe poz i
                     //              r[]i - cmls descresc care incepe pe poz i spre dreapta
int t1[DIM], t2[DIM];
int n;
int a[DIM];
int maxim;   // nr maxim de soldati care raman in formatie
int imaxim, jmaxim;
int s[DIM];  //

void read();
void left();
void right();
void write();
void solve();


int main()
{
	read();
	left();
	right();
	solve();
	write();
}


void read()
{
	int i;
	double k;
	ifstream fin("aliniere.in");
	fin >> n;
	for ( i = 1; i <= n; i ++ )
	{
		fin >> k;
		a[i] = k * 100000;
	}
	fin.close();
}

void left()
{
	int i,j;
	for ( i = 1; i <= n; i++ )
	{
		l[i] = 1;
		t1[i] = 0;
		for ( j = 1; j < i; j++ )
			if ( l[j] + 1 > l[i] && a[j] < a[i] )
			{
				l[i] = l[j] + 1;
				t1[i] = j;
			}
	}
}


void right()
{
	int i, j;
	for ( i = n; i >= 1; i-- )
	{
		r[i] = 1;
		t2[i] = 0;
		for ( j = n; j > i; j--)
			if ( r[j] + 1 > r[i] && a[j] < a[i] )
			{
				r[i] = r[j] + 1;
				t2[i] = j;
			}
	}
}


void solve()
{
	int i, j;
	maxim = -INFINIT;
	for ( i = 1; i <= n; i++ )
		for ( j = i; j <= n; j++ )
			if ( l[i] + r[j] > maxim )
			{
				maxim = l[i] + r[j];
				imaxim = i;
				jmaxim = j;
				if( i == j ) maxim--;
			}

	for ( i = imaxim; i; i = t1[i] )
		s[i] = 1;
	for ( i = jmaxim; i; i = t2[i] )
		s[i] = 1;
}


void write()
{
	int i;
	ofstream fout("aliniere.out");
	fout << n - maxim << "\n";
	for ( i = 1; i <= n; i++ )
		if ( !s[i] ) fout << i << " ";
	fout.close();
}


