//Sursa: 2002 ACM Southeastern Europe Problema F
//Metoda de rezolvare: Ad hoc sau daca va place mai mult Brute force :)
//Timp: O(numarul instructiunilor "r" * AVG(lungimea listei))
//Memorie: O(lungimea maxima a listei)

#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void main()
{
	ifstream fin("f.dat");
	ofstream fout("f.out");
	int max, n, a[100], policy;
	vector <int> output/*Toate rezultatele instructiunilor de tip "r"*/, b/*lista actuala*/;
	while (fin>>max>>n)
	{
		policy=1;
		output.clear(); //A nu se uita aceste instructiuni
		b.clear(); //In cazul problemelor cu fisiere de intrare multitest
		for (int q=0;q<n;++q)
		{
			fin>>a[q];
		}
		char command;
		while (1) //Pentru Pascalistii, carora e dor de repeat..until 
		{
			//Bah, I guess the rest is clear
			fin>>command;
			if (command=='e') break;
			if (command=='a')
			{
				int x;
				fin>>x;
				b.push_back(x);
			}
			if (command=='p')
			{
				fin>>policy;
			}
			if (command=='r')
			{
				if (policy==1)
				{
					output.push_back(*min_element(b.begin(),b.end()));
					b.erase(min_element(b.begin(),b.end()));
				}
				else
				{
					output.push_back(*max_element(b.begin(),b.end()));
					b.erase(max_element(b.begin(),b.end()));
				}
			}
		}
		for (int q=0;q<n;++q)
		{
			fout<<output[a[q]-1]<<endl;
		}
		fout<<endl;
	}
}