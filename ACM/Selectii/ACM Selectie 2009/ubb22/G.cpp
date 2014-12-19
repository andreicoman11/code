#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

string t;
unsigned int no;
int len;
//set<string> s;

void back(int i, int v[], int x[])
{
	if( i>=len )
	{
		/*bool ok = true;
		string nn = "";
		for(int j=0; j<len-1; j++)
		{
			nn += t[x[j]];
		}
		s.insert(nn);*/
		no++;
	}
	else for(int j=0; j<len; j++)
		if( v[j]==0 && (i==0 || ( t[x[i-1]]!=t[j] ) ) )
		{
			v[j] = 1;
			x[i] = j;
			back(i+1, v, x);
			v[j] = 0;
		}
}

int fact(int l)
{
	int rez = 1;
	while(l)
	{
		rez *= l;
		l--;
	}
	return rez;
}

int main()
{
	int N;
	cin >> N;
	while( N-- )
	{
		cin >> t;
		len = t.size();
		int v[16] = {0};
		int x[16] = {0};
		no = 0;
		//s.clear();
		back(0, v, x);
		int p = 1;
		for(int i=0; i<t.size()-1; i++)
		if( isalpha(t[i]) )
		{
			int pp = 1;
			for(int j=i+1; j<t.size(); j++)
				if( t[i]==t[j] ) {pp++;t[j]='#';}
			p *= fact(pp);
		}
		//cout << s.size() << endl;
		cout << no/p << endl;
	}

	return 0;
}
