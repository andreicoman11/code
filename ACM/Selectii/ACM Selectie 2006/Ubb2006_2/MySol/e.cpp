//Sursa: 2002 ACM Southeastern Europe Problema G
//Metoda de rezolvare: Algoritmul lui Prim
//Timp: O(n^2)
//Memorie: O(n^2) pentru memorarea grafului; cu liste de vecini, sau liste de muchii se poate ajunge la O(m)
//De remarcat, ca algoritmul lui Prim necesita doar O(n) memorie

#include<fstream>

using namespace std;

int a[55][55], n, m;

int Prim()
{
	bool was[55];
	memset(was,false,sizeof(was));
	int d[55], ans=0;
	was[1]=true;
	for (int i=1;i<=n;++i) d[i]=a[1][i];
	for (int i=2;i<=n;++i)
	{
		int iMin=0;
		for (int j=1;j<=n;++j)
			if (!was[j] && (iMin==0 || d[iMin]>d[j])) iMin=j;
		was[iMin]=true;
		ans+=d[iMin];
		for (int j=1;j<=n;++j)
			if (!was[j] && d[j]>a[iMin][j]) d[j]=a[iMin][j];
	}
	return ans;
}

void main()
{
	ifstream fin("e.dat");
	ofstream fout("e.out");
	while (1) //Ugly but effective
	{
		fin>>n;
		if (!n) break; //Ugly but effective
		fin>>m;
		memset(a,101,sizeof(a)); 
		//Valorile matricei fiind pe 2 bytes vor avea alta valoare decat 101, dar important e sa fie mai mari decat 100
		for (int q=0; q<m; ++q)
		{
			int i,j,aux;
			fin>>i>>j>>aux;
			if (aux<a[i][j])
			{
				a[i][j]=aux;
				a[j][i]=aux; //Don't forget me
			}
		}
		fout<<Prim()<<endl;
	}
}