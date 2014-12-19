#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> comp(string T, string P)
{
	vector<int> pi(T.size() + P.size(), 0);
	
	int k = 0;
	for(int i=1; i<P.size(); i++)
	{
		while( k>0 && P[k]!=P[i] )
			k = pi[k-1];
		if( P[k]==P[i] ) k++;
		pi[i] = k;
	}
	
	k = 0;
	for(int i=0; i<T.size(); i++)
	{
		while( k>0 && P[k]!=T[i] )
			k = pi[k-1];
		if( P[k]==T[i] ) k++;
		pi[i+P.size()] = k;
	}
	
	return pi;
	// return pi[pi.size()-1];
}

int main()
{
	string a, b;
	while( cin >> a >> b)
	{
		vector<int> pi = comp(a,b);
		for(int i=0; i<b.size(); i++)
			cout << pi[i] << " ";
		cout << endl;
		for(int i=a.size(); i<a.size()+b.size(); i++)
			cout << pi[i] << " ";
		cout << endl;
	}
	return 0;
}
