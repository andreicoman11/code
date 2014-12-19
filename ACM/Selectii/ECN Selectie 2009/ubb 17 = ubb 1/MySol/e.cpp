//Sursa: 2003 ACM Southeastern Europe Problema D
//Metoda de rezolvare: Greedy
//Timp: O(n*AVG(d_i))
//Memorie: O(n+MAX(d_i))

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct T
{
	int profit, time;
};

bool operator<(const T &a, const T &b)
{
	//Am lasat si prima mea intentie de greedy
	//return a.time<b.time || a.time==b.time && a.profit>b.profit;
	return a.profit>b.profit;
}

void main()
{
	ifstream fin("e.dat");
	ofstream fout("e.out");
	int n, a[10000]/*p_i din enunt*/, b[10000]/*d_i din enunt*/;
	vector <T> c;
	while (fin>>n)
	{
		if (!n) //Caz special n=0
		{
			fout<<0<<endl;
			continue;
		}
		c.clear();
		for(int q=0;q<n;++q) 
		{
			fin>>a[q]>>b[q];
			T aux;
			aux.profit=a[q];
			aux.time=b[q];
			c.push_back(aux);
		}
		sort(c.begin(),c.end()); //Il sortam folosind operator< de mai sus
		int sol=0;
		bool was[10001]; //was_i = true, daca in momentul i avem deja produs
		memset(was,false,sizeof(was));
		for(int q=0;q<c.size();++q)
		{
			//Vindem produsul actual cel mai tarziu posibil, pentru a lasa loc produselor cu deadline mai mic
			for(int w=c[q].time;w>=1;--w) 
				if (!was[w])
				{
					was[w]=true;
					sol+=c[q].profit;
					break;
				}
		}
		fout<<sol<<endl;
	}
}