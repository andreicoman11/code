//Sursa: 2002 ACM Southeastern Europe Problema A
//Metoda de rezolvare: Programare dinamica / Knapsack
//Timp: O(cash*SUM(n_i))
//Memorie: O(cash)

#include<fstream>  //Va recomand calduros in loc de fopen/fscanf/fprintf
#include<iostream>
#include<time.h>

using namespace std; //Shit, de cate ori uit linia asta...

void main()
{
	ifstream fin("a.dat");
	ofstream fout("a.out");
	clock_t start=clock();
	int cash, n, a[10]/*n_i din enunt*/,b[10]/*D_i din enunt*/;
	bool c[100001]/*C_i = true daca putem obtine suma i*/;
	while (fin>>cash>>n) //Cu aceasta metoda nu vom avea probleme cu functia feof
	{
		for (int q=0;q<n;++q)
		{
			fin>>a[q]>>b[q];
		}
		memset(c,false,sizeof(c)); //Mai scurt si mai rapit decat un for
		c[0]=true; //0 se poate plati intotdeauna
		for (int q=0;q<n;++q) //Pentru toate tipurile de bancnote
		{
			for (int w=0;w<a[q];++w) //Pentru numarul de bucati al bancnotei actuale
			{
				for (int e=cash-b[q];e>=0;--e) //Marcam toate sumele ce se pot obtine
				{
					if (c[e]) c[e+b[q]]=true;
				}
			}
		}
		int sol=cash; 
		while (!c[sol]) --sol; //Avem nevoie de cea mai mare suma mai mica decat cash
		fout<<sol<<endl;
	}
	cout<<(clock()-start)/CLOCKS_PER_SEC; //Asa se poate masura timpul de executie al programului
}