#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("A.dat");

int main()
{
	int N;
	fin >> N;
	vector<int> x;
	set<int> v;
	while(N--)
	{
		x.clear();
		v.clear();
		int n;
		fin >> n;
		if(n) 
		{
			int max = 1;
			int count = 1;
			int aux;
			fin >> aux;
			x.push_back(aux);
			v.insert(x[0]);
			//cout << n;
			for(int i=1; i<n; i++)
			{
				//cout << i;
				fin >> aux;
				x.push_back(aux);
				if( v.find(aux)==v.end() ) // not yet
				{
					v.insert(aux);
					count++;
				}
				else
				{
					if( count>max )
						max = count;
					v.clear();
					v.insert(x[i]);
					count = 1;
					for(int j=i-1; x[j]!=x[i]; j--)
					{
						v.insert(x[j]);
						count ++;
					}
				}
			}
			if( count>max )
				max = count;
			cout << max << endl;
		}
		else
			cout << "0\n";
	}
	return 0;
}