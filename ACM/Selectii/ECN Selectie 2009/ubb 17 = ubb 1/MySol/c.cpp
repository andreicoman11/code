//Sursa: 2003 ACM Southeastern Europe Problema C
//Metoda de rezolvare: Programare dinamica
//Metode alternative: Formula (eventual gasita prin incercari de ex. C_n=C_{n-2}+n-2)
//Timp: O(n) preprocesare, O(1) pentru fiecare query
//Memorie: O(n)

#include <fstream>

using namespace std;

void main()
{
	int c[40000]/*Cerinta problemei*/, d[40000] /*Solutia pentru varianta liniara (adica ne-circulara)*/;
	d[0]=0;
	for (int q=1;q<40000;++q) d[q]=q-1+d[q-1]; //S-ar fi putut obtine si cu formula q*(q-1)/2
	c[0]=0;
	c[1]=0;
	c[2]=0;
	c[3]=1;
	for (int q=4;q<40000;++q)
	{
		c[q]=q/2-1; //Il mutam pe 1 la mijloc
		c[q]+=d[q/2-1]+d[q-q/2]; //Si rezolvam problema pentru jumatatile ramase
	}
	ifstream fin("c.dat");
	ofstream fout("c.out");
	int test;
	fin>>test;
	while (test)
	{
		--test;
		int n;
		fin>>n;
		fout<<c[n]<<endl;
	}
}