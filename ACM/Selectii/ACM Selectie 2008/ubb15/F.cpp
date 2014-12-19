#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

ifstream fin ("F.in");
//ofstream fout ("F.out");

int N;

int main()
{
	fin >> N;
	while(N--)
	{
		int n;
		fin >> n;
		int last;
		fin >> last;
		int len = 1;
		bool bigger = true;
		for(int i=1; i<n; i++)
		{
			int aux;
			fin >> aux;
			if( aux<last && bigger )
			{
				bigger = !bigger;
				len++;
			}
			if( aux>last && !bigger )
			{
				bigger = !bigger;
				len++;
			}
			last = aux;
		}
		cout << len << "\n";
	}

	return 0;
}