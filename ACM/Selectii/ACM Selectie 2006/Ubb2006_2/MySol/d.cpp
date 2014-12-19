//Sursa: 2003 ACM Southeastern Europe Problema F
//Metoda de rezolvare: Programare dinamica
//Timp: O(LEN(a)*LEN(b))
//Memorie: O(LEN(a)*LEN(b)), se poate ajunge cu usurinta la O(LEN(b))

//Problema era, ca nu a fost specificata lungimea maxima posibila a stringurilor. In asemenea cazuri 
//cel mai recomandat este cererea unui Clarification prin programul PC^2. Daca nu se raspunde la intrebare
//se poate incerca o implementare, cu arrayuri declarate la o marime cat mai mare (cat permite memoria, sau 
//o marime care ar cauza un TLE anyway). O alta abordare posibila este submitarea unui program de genul:
//if (n>1000) while (1) ; else fout<<"1"; din raspunsul careia se poate afla daca valoarea lui n depaseste
//1000 in testele comisiei, dar adauga 20 de minute la penalty. A doua metoda se recomanda daca se cunosc 
//doua solutii posibile la o problema, cea eficienta fiind mult mai greu de implementat, dar cateodata
//prima varianta poate fi mai buna si acest caz.

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int c[1001][1001];

void main()
{
	ifstream fin("d.dat");
	ofstream fout("d.out");
	string a,b;
	while (fin>>a>>b) 
	{
		int ans=0;
		for (int q=0;q<=a.size();++q) c[q][0]=0;
		for (int q=0;q<=b.size();++q) c[0][q]=0;
		for (int q=1;q<=a.size();++q) 
			for (int w=1;w<=b.size();++w)
			{
				if (a[q-1]==b[w-1]) c[q][w]=1+c[q-1][w-1];
				else c[q][w]=max(c[q-1][w],c[q][w-1]);
				ans=max(ans,c[q][w]);
			}
		fout<<ans<<endl;
	}
}