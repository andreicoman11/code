#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	ifstream fin("e.in");
	int test,n;
	fin>>test;
	while (test--)
	{
		fin>>n;
		vector <int> sol(n,0);
		int i=-1;
		for (int q=1;q<=n;++q)
		{
			for (int w=0;w<=q;++w)
				do
					i=(i+1)%n;
				while (sol[i]) ;
			sol[i]=q;
		}
		for (int q=0;q<n;++q) cout<<sol[q]<<" ";
		cout<<endl;
	}
}